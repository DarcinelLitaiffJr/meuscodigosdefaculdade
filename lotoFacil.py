import requests
import datetime
from pymongo import MongoClient
from collections import Counter

# Configuração do MongoDB
MONGO_URI = "mongodb://localhost:27017"  # Substitua pela URI do seu MongoDB se necessário
DB_NAME = "loterias"
COLLECTION_NAME = "lotofacil"

# URL da API da Lotofácil
URL_API_LOTOFACIL = "https://servicebus2.caixa.gov.br/portaldeloterias/api/lotofacil"

# Função para buscar o último sorteio
def buscar_ultimo_sorteio():
    try:
        response = requests.get(URL_API_LOTOFACIL)
        response.raise_for_status()
        dados = response.json()
        
        # Extrair informações relevantes
        sorteio = {
            "data": datetime.datetime.strptime(dados["dataApuracao"], "%d/%m/%Y"),
            "numeros": [int(num) for num in dados["listaDezenas"]]
        }
        return sorteio
    except requests.exceptions.RequestException as e:
        print(f"Erro ao acessar a API da Lotofácil: {e}")
        return None

# Função para salvar o sorteio no MongoDB
def salvar_sorteio_no_mongodb(sorteio):
    try:
        client = MongoClient(MONGO_URI)
        db = client[DB_NAME]
        collection = db[COLLECTION_NAME]
        
        # Inserir o sorteio se ainda não existir
        if not collection.find_one({"data": sorteio["data"]}):
            collection.insert_one(sorteio)
            print(f"Sorteio do dia {sorteio['data']} salvo com sucesso.")
        else:
            print(f"Sorteio do dia {sorteio['data']} já está salvo.")
        
        # Garantir que a coleção armazene no máximo 12 meses
        data_limite = datetime.datetime.now() - datetime.timedelta(days=12 * 30)
        collection.delete_many({"data": {"$lt": data_limite}})
    except Exception as e:
        print(f"Erro ao salvar sorteio no MongoDB: {e}")

# Função para calcular os números mais frequentes dos últimos 6 meses
def calcular_numeros_mais_frequentes():
    try:
        client = MongoClient(MONGO_URI)
        db = client[DB_NAME]
        collection = db[COLLECTION_NAME]
        
        # Data de 6 meses atrás
        data_inicio = datetime.datetime.now() - datetime.timedelta(days=6 * 30)
        
        # Buscar resultados dos últimos 6 meses
        resultados = collection.find({"data": {"$gte": data_inicio}})
        
        # Coletar todos os números sorteados
        todos_numeros = []
        for resultado in resultados:
            todos_numeros.extend(resultado["numeros"])
        
        # Contar frequência dos números
        frequencia = Counter(todos_numeros)
        
        # Ordenar os números por frequência
        numeros_mais_frequentes = frequencia.most_common()
        
        print("Números que mais se repetiram nos últimos 6 meses:")
        for numero, freq in numeros_mais_frequentes:
            print(f"Número: {numero}, Frequência: {freq}")
    
    except Exception as e:
        print(f"Erro ao calcular frequência: {e}")

# Função principal
def main():
    # Buscar o último sorteio
    ultimo_sorteio = buscar_ultimo_sorteio()
    if ultimo_sorteio:
        # Salvar o sorteio no MongoDB
        salvar_sorteio_no_mongodb(ultimo_sorteio)
        # Calcular os números mais frequentes
        calcular_numeros_mais_frequentes()
    else:
        print("Não foi possível obter o último sorteio.")

# Executar
if __name__ == "__main__":
    main()
