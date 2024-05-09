#include <stdio.h>
#include <stdlib.h>

int main (){
	
	int op;
	float vt, troco, vdinheiro, vparcela,parc;
	
	printf("\n****** Sistema de Pagamento ******\n");
	printf(" \n Escolha forma de pagamento\n");
	printf(" 1- Cartao de Debito\n");
	printf(" 2- Cartao de Credito\n");
	printf(" 3- Pagamento em Dinheiro\n");
	scanf("\n\n%d",&op);
	system ("cls");
	switch (op){
		case 1 :
			printf("\nInsira o Cartao...\n");
			printf("\nDigite o Valor da Compra:\n\n");
			scanf("\n%f",&vt);
			system ("cls");	
			printf("\n***** Resumo da compra *****\n");	
			printf("\nValor total da compra: %.2f",vt);	
			printf("\n\nPagamento Efetuado com Sucesso...\n\n");
		break;
		
		case 2 :
			printf("\nInsira o Cartao...\n");
			printf("\nDigite o Valor da Compra:\n\n");
			scanf("\n%f",&vt);
			printf("\nQuantidade de parcelas:\n");
			fflush(stdin);
			scanf("%f",&parc);
			vparcela=vt/parc;
			system("cls");
			printf("\n***** Resumo da compra *****\n");	
			printf("\nValor total da compra: %.2f",vt);
			printf("\nNumero de parcelas:%.0f",parc);
			printf("\nValor das parcelas:%.2f",vparcela);	
			printf("\n\nPagamento Efetuado com Sucesso...\n\n");
		break;
	
		case 3 :
			printf("\nDigite o valor do Dinheiro:\n\n");
			scanf("%f",&vdinheiro);
			printf("\nDigite o Valor da Compra:\n\n");
			scanf("\n%f",&vt);
			troco=vdinheiro-vt;
			system("cls");
				printf("\n***** Resumo da compra *****\n");	
			printf("\nValor dinheiro:%.2f\n",vdinheiro);
			printf("\nValor total da compra: %.2f\n",vt);
			printf("\nValor do troco %.2f\n",troco);
			printf("\n\nPagamento Efetuado com Sucesso...\n\n");
		break;
	}
	
	return 0;
}
