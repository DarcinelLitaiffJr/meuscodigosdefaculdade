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
			printf("Acima de tr�s parcelas � adicionado 5%c do valor em cada parcela pela bandeira do seu cart�o.\n",37);
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
	printf("\n\t\t[01]-Arroz    \t[11]-Requeij�o\t\t[21]-Carne Su�na\n");
	printf("\t\t[02]-Feij�o   \t[12]-Detergente\t\t[22]-Frango\n");
	printf("\t\t[03]-Macarr�o \t[13]-Ketchup\t\t[23]-Salame\n");
	printf("\t\t[04]-Farinha  \t[14]-Sab�o em P�\t[24]-Queijo\n");
	printf("\t\t[05]-Caf�     \t[15]-�gua Sanit�ria\t[25]-Presunto\n");
	printf("\t\t[06]-Sal      \t[16]-Ovo\t\t[26]-Frango Empanado\n");
	printf("\t\t[07]-LeiteP�   \t[17]-Salsicha\t\t[27]-Lingui�a de Frango\n");
	printf("\t\t[08]-A�ucar   \t[18]-Sardinha\t\t[28]-Lingui�a de Su�na\n");
	printf("\t\t[09]-Bolacha  \t[19]-Charque\t\t[29]-Lingui�a Toscana\n");
	printf("\t\t[10]-Guaran�  \t[20]-Carne Bovina\t[30]-Peixe\n");
	printf("\t\tPara finalizar o servi�o digite 0\n");
	printf("\t\tInsira o n�mero do Produto desejado:");
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
			printf("\nPre�o:2,59");
			break;
		case 2:
			printf("\n[02]-Feij�o 			Data de Vencimento 29/12/2019");
			valor=valor+4.50;
			printf("\nPre�o:4,50");
			break;
		case 3:
			printf("\n[03]-Macarr�o 			Data de Vencimento 29/12/2019");
			valor=valor+1.90;
			printf("\nPre�o:1,90");
			break;
		case 4:
			printf("\n[04]-Farinha 			Data de Vencimento 29/12/2019");
			valor=valor+6.00;
			printf("\nPre�o:6,00");
			break;
		case 5:
			printf("\n[05]-Caf� 			Data de Vencimento 29/12/2019");
			valor=valor+4.50;
			printf("\nPre�o:4,50");
			break;
		case 6:
			printf("\n[06]-Sal 			Data de Vencimento 29/12/2019");
			valor=valor+1.19;
			printf("\nPre�o:1,19");
			break;
		case 7:
			printf("\n[07]-LeiteP� 			Data de Vencimento 29/12/2019");
			valor=valor+7.90;
			printf("\nDe Pre�o:10,90 Por 7.90");
			break;
		case 8:
			printf("\n[08]-A�ucar 			Data de Vencimento 29/12/2019");
			valor=valor+1.99;
			printf("\nPre�o:1,99");
			break;
		case 9:
			printf("\n[09]-Bolacha 			Data de Vencimento 29/12/2019");
			valor=valor+3.30;
			printf("\nPre�o3,30:");
			break;
		case 10:
			printf("\n[10]-Guaran� 			Data de Vencimento 29/12/2019");
			valor=valor+5.00;
			printf("\nPre�o:5.00");
			break;
		case 11:
			printf("\n[11]-Requeij�o 			Data de Vencimento 29/12/2019");
			valor=valor+6.50;
			printf("\nPre�o:");
			break;
		case 12:
			printf("\n[12]-Detergente 			Data de Vencimento 29/12/2019");
			valor=valor+1.25;
			printf("\nPre�o:1,25");
			break;
		case 13:
			printf("\n[13]-Ketchup 			Data de Vencimento 29/12/2019");
			valor=valor+3.99;
			printf("\nPre�o:3,99");
			break;
		case 14:
			printf("\n[14]-Sab�o em P� 			Data de Vencimento 29/12/2019");
			valor=valor+4.00;
			printf("\nPre�o:4,00");
			break;
		case 15:
			printf("\n[15]-�gua Sanit�ria 			Data de Vencimento 29/12/2019");
			valor=valor+1.70;
			printf("\nPre�o:1,70");
			break;
		case 16:
			printf("\n[16]-Ovo 			Data de Vencimento 29/12/2019");
			valor=valor+0.40;
			printf("\nPre�o:0,40");
			break;
		case 17:
			printf("\n[17]-Salsicha 			Data de Vencimento 29/12/2019");
			valor=valor+5.00;
			printf("\nPre�o:5,00");
			break;
		case 18:
			printf("\n[18]-Sardinha 			Data de Vencimento 29/12/2019");
			valor=valor+2.75;
			printf("\nPre�o:2,75");
			break;
		case 19:
			printf("\n[19]-Charque 			Data de Vencimento 29/12/2019");
			valor=valor+26.00;
			printf("\nPre�o:26,00");
			break;
		case 20:
			printf("\n[20]-Carne Bovina 			Data de Vencimento 29/12/2019");
			valor=valor+35.00;
			printf("\nPre�o:35,00");
			break;
		case 21:
			printf("\n[21]-Carne Su�na 			Data de Vencimento 29/12/2019");
			valor=valor+15.00;
			printf("\nPre�o:15,00");
			break;
		case 22:
			printf("\n[22]-Frango 			Data de Vencimento 29/12/2019");
			valor=valor+4.99;
			printf("\nPre�o:4,99");
			break;
		case 23:
			printf("\n[23]-Salame 			Data de Vencimento 29/12/2019");
			valor=valor+35.99;
			printf("\nPre�o:35,99");
			break;
		case 24:
			printf("\n[24]-Queijo 			Data de Vencimento 29/12/2019");
			valor=valor+21.99;
			printf("\nPre�o:21,99");
			break;
		case 25:
			printf("\n[25]-Presunto 			Data de Vencimento 29/12/2019");
			valor=valor+13.00;
			printf("\nPre�o:13,00");
			break;
		case 26:
			printf("\n[26]-Frango Empanado 			Data de Vencimento 29/12/2019");
			valor=valor+1.25;
			printf("\nPre�o:1,25");
			break;
		case 27:
			printf("\n[27]-Lingui�a de Frango 			Data de Vencimento 29/12/2019");
			valor=valor+9.90;
			printf("\nPre�o:9,90");
			break;
		case 28:
			printf("\n[28]-Lingui�a de Su�na 			Data de Vencimento 29/12/2019");
			valor=valor+25.00;
			printf("\nPre�o:25,00");
			break;
		case 29:
			printf("\n[29]-Lingui�a Toscana 			Data de Vencimento 29/12/2019");
			valor=valor+12.99;
			printf("\nPre�o:12,99");
			break;
		case 30:
			printf("\n[30]-Peixe 			Data de Vencimento 29/12/2019");
			valor=valor+9.89;
			printf("\nPre�o:9,89");
			break;
		case 31:
			printf("\n\t\t*******************Equipe*********************");
			printf("\n\t\tAntonio Lucas Campos Rodrigues");
			printf("\n\t\tDarcinel Barbosa Litaiff J�nior");
			printf("\n\t\tJos� Carlos Freitas Felipe");
			printf("\n\t\tMiri� Ferreira da Costa Maciel");
			printf("\n\t\tRangel Tom� Gaia Barbosa");
			break;																				
		default:
			printf("Produto n�o cadastrado!!!\n Por favor Insira um dos n�meros de produto valido!");
			break;										
	}
}
	return 0;
}
