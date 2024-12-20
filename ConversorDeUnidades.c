/* ************************************************************************** */
/*                                                                            */
/*   Embarcatech - Subgrupo 6                                                 */
/*   Depuração e Versionamento                                                */
/*                                                                            */
/*   ConversorDeUnidades.c                                                    */
/*                                                  ___         ___    __ __  */
/*                                                 | __|  ___  |_  )  / // /  */
/*                                                 | _|  |___|  / /  / // _ \ */
/*                                                 |___|       /___|/_/ \___/ */
/*   By: Gcosmo <bielxx94@gmail.com>                                          */
/*       EderRenato <eder.casar@outlook.com>                                  */
/*       Silva-Alisson <als987654@gmail.com>                                  */
/*       sarahmss <smodesto@student.42sp.org.br>                              */
/*                                                                            */
/* ************************************************************************** */
                     
#include "ConversorDeUnidades.h"

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


double VolConverterParaSI(double valor, int unidade) {
    switch (unidade) {
        case 1: return valor;                  // m³
        case 2: return valor / 1000;          // L -> m³
        case 3: return valor / 1000000;       // ml -> m³
        default: return -1;                   // Unidade inválida
    }
}

double VolConverterDeSI(double valorSI, int unidade_destino) {
    switch (unidade_destino) {
        case 1: return valorSI;               // m³
        case 2: return valorSI * 1000;        // m³ -> L
        case 3: return valorSI * 1000000;     // m³ -> ml
        default: return -1;                   // Unidade inválida
    }
}

void ConversorDeVolume(void) {
    t_ConversorDeUnidades data;

    system("cls");

    printf("Insira o valor que deseja converter: ");
    scanf("%lf", &data.entrada);

    system("cls");

    printf("Qual a unidade de medida do valor informado? \n");
    printf("1. Metro Cúbico (m³) \n");
    printf("2. Litro (L) \n");
    printf("3. Mililitro (ml) \n");
    printf("Selecione a unidade: ");
    scanf("%d", &data.unidade);

    system("cls");

    printf("Para qual unidade deseja converter? \n");
    printf("1. Metro Cúbico (m³) \n");
    printf("2. Litro (L) \n");
    printf("3. Mililitro (ml) \n");
    printf("Selecione a unidade: ");
    scanf("%d", &data.unidade_destino);

    data.valor_si = VolConverterParaSI(data.entrada, data.unidade);
    data.resultado = VolConverterDeSI(data.valor_si, data.unidade_destino);

    system("cls");
    printf("O valor convertido é: %.6lf\n", data.resultado);
}

//Km
//m
//cm
//mm
//um