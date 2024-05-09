#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct produto {
	int codigo;
	char nome [30];
	int quantidade;
	float preco;
	int validade;
	int catp;
}pdt;	

int main (){
	int i;
	pdt vet[2];
	for(i=0;i<2;i++){
		vet[i].codigo=i;
		printf("Informe o nome do produto:\n");
		fflush(stdin);
		gets(vet[i].nome);
		printf("Informe a quantidade:\n");
		scanf("%d",&vet[i].quantidade);
		printf("Informe o preco:\n");
		scanf("%f",&vet[i].preco);
		printf("Informe a validade:\n");
		scanf("%d",&vet[i].validade);
		printf("Informe a Categoria:\n");
		scanf("%d",&vet[i].catp);
		printf("\nProduto cadrastrado!!!\n");
	}
	system("cls");
	for(i=0;i<2;i++){ 
		printf("\tLista de Produtos\nCodigo:%d\nNome:%s\nQuantidade:%d\nPreco:%.2f\nValidade:%d\nCategoria:%d",vet[i].codigo,vet[i].nome,vet[i].quantidade,vet[i].preco,vet[i].validade,vet[i].catp);
	}
	return 0;
}


