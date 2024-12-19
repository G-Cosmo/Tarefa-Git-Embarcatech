//Embarcatech
//Tarefa: Depuração e Versionamento
//Subgrupo: 6                     


#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include <string.h>

int converterComprimento();
//void cabeçalhoDeFunçãoDeConversão();

void converterPotencia();

int main(){
    int opc;

    do
    {

    
        system("cls");
        printf("Escolha a opcao de conversao desejada: \n");
        printf("1. Comprimento \n");
        printf("2. Potência \n");
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
            case 2:
                converterPotencia();
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

void converterPotencia(){
    double valor, valorSI;
    int unidade, opc;
    char cUnidade[20];

    while(1){
        system("cls");
        printf("Insira o valor que deseja converter: ");
        scanf("%lf", &valor);
        system("cls");

        printf("Qual a unidade de medida do valor informado? \n");
        printf("1. Watt(W)\n");
        printf("2. Quilowatt(kW)\n");
        printf("3. MegaWatt (MW)\n");
        printf("4. Cavalo-vapor(cv) \n");
        printf("5. Cavalo-força(hp) \n");
        printf("6. British Thermal Unit per hour (BTU/h)\n");
        printf("Para sair pressione qualquer tecla não listada\n");
        printf("Sua escolha: ");
        scanf("%d", &unidade);

        switch (unidade)
        {
        case 1: valorSI = valor; strcpy(cUnidade, "W"); break;
        case 2: valorSI = valor * 1e3; strcpy(cUnidade, "kW"); break;
        case 3: valorSI = valor * 1e6; strcpy(cUnidade, "MW"); break;
        case 4: valorSI = valor * 735.5; strcpy(cUnidade, "cv"); break;
        case 5: valorSI = valor * 745.7; strcpy(cUnidade, "hp"); break;
        case 6: valorSI = valor * 0.293; strcpy(cUnidade, "BTU/h"); break;
        default: printf("Saindo...\n"); return;
        }

        printf("\nO valor em SI é %lf W\n", valorSI);
        printf(" %lf %s ----> %lf kW\n", valor,cUnidade, valorSI * 1e-3);
        printf(" %lf %s ----> %lf MW\n", valor,cUnidade, valorSI * 1e-6);
        printf(" %lf %s ----> %lf cv\n", valor,cUnidade, valorSI / 735.5);
        printf(" %lf %s ----> %lf hp\n", valor,cUnidade, valorSI / 745.7);
        printf(" %lf %s ----> %lf BTU/h\n", valor,cUnidade, valorSI / 0.293);
        printf("\n\nDigite 1 para realizar uma nova conversao de potência ou outro valor para retornar ao menu: \n");
        scanf("%d", &opc);
        if (opc != 1){ break;}
    }
}

//Km
//m
//cm
//mm
//um