import requests
import datetime
from pymongo import MongoClient
from collections import Counter

# Configuração do MongoDB
MONGO_URI = "mongodb://localhost:27017"  # Substitua pela URI do seu MongoDB, se necessário
DB_NAME = "loterias"
COLLECTION_NAME = "lotofacil"

# URL da API da Lotofácil
URL_API_LOTOFACIL = "https://servicebus2.caixa.gov.br/portaldeloterias/api/lotofacil"

# Função para buscar resultados de sorteios no intervalo dos últimos 6 meses
def buscar_resultados_6_meses():
    resultados = []
    try:
        # Data de 6 meses atrás
        data_inicio = datetime.datetime.now() - datetime.timedelta(days=12 * 30)
        
        # Buscar o sorteio mais recente
        url = URL_API_LOTOFACIL
        while True:
            response = requests.get(url)
            response.raise_for_status()
            dados = response.json()

            # Extrair informações do sorteio
            data_sorteio = datetime.datetime.strptime(dados["dataApuracao"], "%d/%m/%Y")
            
            # Parar se a data do sorteio estiver antes do intervalo de 6 meses
            if data_sorteio < data_inicio:
                break

            # Adicionar sorteio à lista de resultados
            resultados.append({
                "data": data_sorteio,
                "numeros": [int(num) for num in dados["listaDezenas"]],
                "numero": dados["numero"],
            })

            # Atualizar URL para buscar o concurso anterior
            if not dados.get("numeroConcursoAnterior"):
                break
            url = f"{URL_API_LOTOFACIL}/{dados['numeroConcursoAnterior']}"

        return resultados

    except requests.exceptions.RequestException as e:
        print(f"Erro ao acessar a API da Lotofácil: {e}")
        return resultados

# Função para salvar resultados no MongoDB
def salvar_resultados_no_mongodb(resultados):
    try:
        client = MongoClient(MONGO_URI)
        db = client[DB_NAME]
        collection = db[COLLECTION_NAME]
        
        # Inserir resultados no MongoDB
        for resultado in resultados:
            if not collection.find_one({"numero": resultado["numero"]}):
                collection.insert_one(resultado)
        
        # Garantir que a coleção armazene no máximo 24 meses
        data_limite = datetime.datetime.now() - datetime.timedelta(days=24 * 30)
        collection.delete_many({"data": {"$lt": data_limite}})
        
        print(f"Salvou {len(resultados)} sorteios e garantiu limite de 24 meses.")
    except Exception as e:
        print(f"Erro ao salvar sorteios no MongoDB: {e}")

# Função para calcular os números mais frequentes dos últimos 6 meses
def calcular_numeros_mais_frequentes():
    try:
        client = MongoClient(MONGO_URI)
        db = client[DB_NAME]
        collection = db[COLLECTION_NAME]
        
        # Data de 6 meses atrás
        data_inicio = datetime.datetime.now() - datetime.timedelta(days=12 * 30)
        
        # Buscar resultados dos últimos 6 meses no MongoDB
        resultados = collection.find({"data": {"$gte": data_inicio}})
        
        # Coletar todos os números sorteados
        todos_numeros = []
        for resultado in resultados:
            todos_numeros.extend(resultado["numeros"])
        
        # Contar frequência dos números
        frequencia = Counter(todos_numeros)
        
        # Ordenar os números por frequência
        numeros_mais_frequentes = frequencia.most_common()
        
        print("Números que mais se repetiram nos últimos 12 meses:")
        for numero, freq in numeros_mais_frequentes:
            print(f"Número: {numero}, Frequência: {freq}")
    
    except Exception as e:
        print(f"Erro ao calcular frequência: {e}")

# Função principal
def main():
    # Buscar os resultados dos últimos 6 meses
    resultados = buscar_resultados_6_meses()
    if resultados:
        # Salvar os resultados no MongoDB
        salvar_resultados_no_mongodb(resultados)
        # Calcular os números mais frequentes
        calcular_numeros_mais_frequentes()
    else:
        print("Nenhum resultado encontrado no intervalo de 24 meses.")

# Executar
if __name__ == "__main__":
    main()
