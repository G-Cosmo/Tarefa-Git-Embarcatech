//Embarcatech
//Tarefa: Depuração e Versionamento
//Subgrupo: 6                     


#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int converterComprimento();
//void cabeçalhoDeFunçãoDeConversão();

int main(){
    int opc;

    do
    {

    
        system("cls");
        printf("Escolha a opcao de conversao desejada: \n");
        printf("1. Comprimento \n");
        //printf("outras conversões");
        printf("0. Sair \n");
        printf("Opcao: ");
        scanf("%d", &opc);
        //printf("Opcao escolhida: %d", opc);


        switch (opc)
        {
            case 1:
                converterComprimento();
                break;
            default:
                break;
                
        }

    } while (opc != 0);
       
}

int converterComprimento(){

    double valor, valorSI;
    int opc, unidade;
    char prefixo;

    do
    { 
        do
        {
            system("cls");

            printf("Insira o valor que deseja converter: ");
            scanf("%lf", &valor);

            system("cls");

            printf("Qual a unidade de medida do valor informado? \n");
            printf("1. Metro(m) \n");
            printf("2. Quilometro(Km) \n");
            printf("3. Centimetro(cm) \n");
            printf("4. Milimetro(mm) \n");
            printf("5. Micrometro(um) \n");
            printf("0. Retornar ao menu \n");
            printf("Opcao: ");
            scanf("%d", &unidade);

        } while (unidade < 0 || unidade > 5);

        system("cls");

        switch(unidade)
        {
            case 0:
                return 0;
            case 1:
                valorSI = valor;
                prefixo = ' ';
                break;
            case 2:
                valorSI = valor * pow(10,3);
                prefixo = 'K';
                break;
            case 3:
                valorSI = valor * pow(10,-2);
                prefixo = 'c';
                break;
            case 4:
                valorSI = valor * pow(10, -3);
                prefixo = 'm';
                break;
            case 5:
                valorSI = valor * pow(10, -6);
                prefixo = 'u';
                break;

        }
           

        printf("Valor no sistema internacional de unidades: %lf m\n", valorSI);
        printf(" %lf %cm ----> %lf Km\n", valor, prefixo, valorSI*pow(10,-3));
        printf(" %lf %cm ----> %lf cm\n", valor, prefixo, valorSI*pow(10,2));
        printf(" %lf %cm ----> %lf mm\n", valor, prefixo, valorSI*pow(10,3));
        printf(" %lf %cm ----> %lf um\n", valor, prefixo, valorSI*pow(10,6));
        printf("\n\nDigite 1 para realizar uma nova conversao de comprimento ou outro valor para retornar ao menu: ");
        scanf("%d", &opc);

    }while(opc == 1);


}


//Km
//m
//cm
//mm
//um