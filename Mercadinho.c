#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<locale.h>
void pagamento(float valor){
	int op,s=0;
	float vt, troco, vdinheiro, vparcela,parc;
	vt=valor;
	printf("\n****** Sistema de Pagamento ******\n");
	printf(" \n Escolha forma de pagamento\n");
	printf(" 1- Cartao de Debito\n");
	printf(" 2- Cartao de Credito\n");
	printf(" 3- Pagamento em Dinheiro\n");
	scanf("\n\n%d",&op);
	//system ("cls");
	printf("Valor total:%.2f",vt);
	switch (op){
		case 1 :
			printf("\nInsira o Cartao...\n");
			//printf("\nDigite o Valor da Compra:\n\n");
			//scanf("\n%f",&vt);
			//system ("cls");	
			printf("\n***** Resumo da compra *****\n");	
			printf("\nValor total da compra: %.2f",vt);	
			printf("\n\nPagamento Efetuado com Sucesso...\n\n");
		break;
		
		case 2 :
			printf("\nInsira o Cartao...\n");
			//printf("\nDigite o Valor da Compra:\n\n");
			//scanf("\n%f",&vt);
			printf("\nQuantidade de parcelas:\n");
			fflush(stdin);
			scanf("%f",&parc);
			printf("Acima de três parcelas é adicionado 5%c do valor em cada parcela pela bandeira do seu cartão.\n",37);
			vparcela=vt/parc;
			if(parc>=3){
				vparcela=vparcela+(vparcela*0.05);
			}
			//system("cls");
			printf("\n***** Resumo da compra *****\n");	
			printf("\nValor total da compra: %.2f",vt);
			printf("\nNumero de parcelas:%.0f",parc);
			printf("\nValor das parcelas:%.2f",vparcela);	
			printf("\n\nPagamento Efetuado com Sucesso...\n\n");
		break;
	
		case 3 :
			printf("\nDigite o valor do Dinheiro:\n\n");
			scanf("%f",&vdinheiro);
			printf("\nCompras pagas em dinheiro tem 10%c de desconto:\n\n",37);
			vt=vt-(vt*0.1);
			//scanf("\n%f",&vt);
			troco=vdinheiro-vt;
			//system("cls");
				printf("\n***** Resumo da compra *****\n");	
			printf("\nValor dinheiro:%.2f\n",vdinheiro);
			printf("\nValor total da compra: %.2f\n",vt);
			printf("\nValor do troco %.2f\n",troco);
			printf("\n\nPagamento Efetuado com Sucesso...\n\n");
		break;
	}
	printf("Se desejar conitunar no Sistema digite [1] ou qualquer tecla para sair:");
	scanf("%d",&s);
	if(s==1){
		system("cls");
		main();
	}else{
		exit(0);
	}
}
int main(){
	int op;
	float valor;
	setlocale(LC_ALL,"Portuguese");
	printf("\t\t******************Menu de Produtos********************");
	printf("\n\t\t[01]-Arroz    \t[11]-Requeijão\t\t[21]-Carne Suína\n");
	printf("\t\t[02]-Feijão   \t[12]-Detergente\t\t[22]-Frango\n");
	printf("\t\t[03]-Macarrão \t[13]-Ketchup\t\t[23]-Salame\n");
	printf("\t\t[04]-Farinha  \t[14]-Sabão em Pó\t[24]-Queijo\n");
	printf("\t\t[05]-Café     \t[15]-Água Sanitária\t[25]-Presunto\n");
	printf("\t\t[06]-Sal      \t[16]-Ovo\t\t[26]-Frango Empanado\n");
	printf("\t\t[07]-LeitePó   \t[17]-Salsicha\t\t[27]-Linguiça de Frango\n");
	printf("\t\t[08]-Açucar   \t[18]-Sardinha\t\t[28]-Linguiça de Suína\n");
	printf("\t\t[09]-Bolacha  \t[19]-Charque\t\t[29]-Linguiça Toscana\n");
	printf("\t\t[10]-Guaraná  \t[20]-Carne Bovina\t[30]-Peixe\n");
	printf("\t\tPara finalizar o serviço digite 0\n");
	printf("\t\tInsira o número do Produto desejado:");
	for(;;){
	puts(" ");	
	scanf("%d",&op);
	
	switch(op){
		case 0:
			printf("\nCompra finalizada!!");
			pagamento(valor);
			exit(0);
			break;
		case 1:
			printf("\n[01]-Arroz 			Data de Vencimento 29/12/2019");
			valor=valor+2.59;
			printf("\nPreço:2,59");
			break;
		case 2:
			printf("\n[02]-Feijão 			Data de Vencimento 29/12/2019");
			valor=valor+4.50;
			printf("\nPreço:4,50");
			break;
		case 3:
			printf("\n[03]-Macarrão 			Data de Vencimento 29/12/2019");
			valor=valor+1.90;
			printf("\nPreço:1,90");
			break;
		case 4:
			printf("\n[04]-Farinha 			Data de Vencimento 29/12/2019");
			valor=valor+6.00;
			printf("\nPreço:6,00");
			break;
		case 5:
			printf("\n[05]-Café 			Data de Vencimento 29/12/2019");
			valor=valor+4.50;
			printf("\nPreço:4,50");
			break;
		case 6:
			printf("\n[06]-Sal 			Data de Vencimento 29/12/2019");
			valor=valor+1.19;
			printf("\nPreço:1,19");
			break;
		case 7:
			printf("\n[07]-LeitePó 			Data de Vencimento 29/12/2019");
			valor=valor+7.90;
			printf("\nDe Preço:10,90 Por 7.90");
			break;
		case 8:
			printf("\n[08]-Açucar 			Data de Vencimento 29/12/2019");
			valor=valor+1.99;
			printf("\nPreço:1,99");
			break;
		case 9:
			printf("\n[09]-Bolacha 			Data de Vencimento 29/12/2019");
			valor=valor+3.30;
			printf("\nPreço3,30:");
			break;
		case 10:
			printf("\n[10]-Guaraná 			Data de Vencimento 29/12/2019");
			valor=valor+5.00;
			printf("\nPreço:5.00");
			break;
		case 11:
			printf("\n[11]-Requeijão 			Data de Vencimento 29/12/2019");
			valor=valor+6.50;
			printf("\nPreço:");
			break;
		case 12:
			printf("\n[12]-Detergente 			Data de Vencimento 29/12/2019");
			valor=valor+1.25;
			printf("\nPreço:1,25");
			break;
		case 13:
			printf("\n[13]-Ketchup 			Data de Vencimento 29/12/2019");
			valor=valor+3.99;
			printf("\nPreço:3,99");
			break;
		case 14:
			printf("\n[14]-Sabão em Pó 			Data de Vencimento 29/12/2019");
			valor=valor+4.00;
			printf("\nPreço:4,00");
			break;
		case 15:
			printf("\n[15]-Água Sanitária 			Data de Vencimento 29/12/2019");
			valor=valor+1.70;
			printf("\nPreço:1,70");
			break;
		case 16:
			printf("\n[16]-Ovo 			Data de Vencimento 29/12/2019");
			valor=valor+0.40;
			printf("\nPreço:0,40");
			break;
		case 17:
			printf("\n[17]-Salsicha 			Data de Vencimento 29/12/2019");
			valor=valor+5.00;
			printf("\nPreço:5,00");
			break;
		case 18:
			printf("\n[18]-Sardinha 			Data de Vencimento 29/12/2019");
			valor=valor+2.75;
			printf("\nPreço:2,75");
			break;
		case 19:
			printf("\n[19]-Charque 			Data de Vencimento 29/12/2019");
			valor=valor+26.00;
			printf("\nPreço:26,00");
			break;
		case 20:
			printf("\n[20]-Carne Bovina 			Data de Vencimento 29/12/2019");
			valor=valor+35.00;
			printf("\nPreço:35,00");
			break;
		case 21:
			printf("\n[21]-Carne Suína 			Data de Vencimento 29/12/2019");
			valor=valor+15.00;
			printf("\nPreço:15,00");
			break;
		case 22:
			printf("\n[22]-Frango 			Data de Vencimento 29/12/2019");
			valor=valor+4.99;
			printf("\nPreço:4,99");
			break;
		case 23:
			printf("\n[23]-Salame 			Data de Vencimento 29/12/2019");
			valor=valor+35.99;
			printf("\nPreço:35,99");
			break;
		case 24:
			printf("\n[24]-Queijo 			Data de Vencimento 29/12/2019");
			valor=valor+21.99;
			printf("\nPreço:21,99");
			break;
		case 25:
			printf("\n[25]-Presunto 			Data de Vencimento 29/12/2019");
			valor=valor+13.00;
			printf("\nPreço:13,00");
			break;
		case 26:
			printf("\n[26]-Frango Empanado 			Data de Vencimento 29/12/2019");
			valor=valor+1.25;
			printf("\nPreço:1,25");
			break;
		case 27:
			printf("\n[27]-Linguiça de Frango 			Data de Vencimento 29/12/2019");
			valor=valor+9.90;
			printf("\nPreço:9,90");
			break;
		case 28:
			printf("\n[28]-Linguiça de Suína 			Data de Vencimento 29/12/2019");
			valor=valor+25.00;
			printf("\nPreço:25,00");
			break;
		case 29:
			printf("\n[29]-Linguiça Toscana 			Data de Vencimento 29/12/2019");
			valor=valor+12.99;
			printf("\nPreço:12,99");
			break;
		case 30:
			printf("\n[30]-Peixe 			Data de Vencimento 29/12/2019");
			valor=valor+9.89;
			printf("\nPreço:9,89");
			break;
		case 31:
			printf("\n\t\t*******************Equipe*********************");
			printf("\n\t\tAntonio Lucas Campos Rodrigues");
			printf("\n\t\tDarcinel Barbosa Litaiff Júnior");
			printf("\n\t\tJosé Carlos Freitas Felipe");
			printf("\n\t\tMiriã Ferreira da Costa Maciel");
			printf("\n\t\tRangel Tomé Gaia Barbosa");
			break;																				
		default:
			printf("Produto não cadastrado!!!\n Por favor Insira um dos números de produto valido!");
			break;										
	}
}
	return 0;
}
