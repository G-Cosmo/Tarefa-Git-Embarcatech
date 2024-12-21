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
/*         Fontana <gui.fontana0701@gmail.com>                                */
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
        printf("2. Potência \n");
        printf("3. Temperatura \n");
        printf("4. Volume \n");
        printf("5. Tempo \n");

        printf("0. Sair \n");
        printf("Opcao: ");
        scanf("%d", &opc);
        
        switch (opc)
        {
            case 1:
                ConversorDeComprimento();
                break;
            case 2:
                ConversorDePotencia();
                break;
            case 3:
                ConversorDeTemperatura();
                break;
            case 4:
                ConversorDeVolume();
                break; 
            case 5:
                ConversorDeTempo();
            default:
                break;
        }

    } while (opc != 0);
}

void ConversorDeComprimento(void){

    double valor, valorSI = 0;
    int opc, unidade = 0;
    char prefixo = 'a';

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
                break;
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
        printf(" %.6lf %cm ----> %.6lf Km\n", valor, prefixo, valorSI*pow(10,-3));
        printf(" %.6lf %cm ----> %.6lf cm\n", valor, prefixo, valorSI*pow(10,2));
        printf(" %.6lf %cm ----> %.6lf mm\n", valor, prefixo, valorSI*pow(10,3));
        printf(" %.6lf %cm ----> %.6lf um\n", valor, prefixo, valorSI*pow(10,6));
        printf("\n\nDigite 1 para realizar uma nova conversao de comprimento ou outro valor para retornar ao menu: ");
        scanf("%d", &opc);

    } while(opc == 1);
}

void ConversorDePotencia(void){
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

double VolConverterParaSI(double valor, int unidade) {
    switch (unidade) {
        case 1:
            return valor;                  // m³
        case 2:
            return valor / 1000;          // L -> m³
        case 3:
            return valor / 1000000;       // ml -> m³
        default:
            return 0;
    }

}

void ConversorDeVolume(void) {
    double entrada = 0.0;
    int unidade = -1;
    double valor_si = 0.0;

    system("cls");
    printf("Insira o valor que deseja converter: ");
    scanf("%lf", &entrada);

    while (unidade < 0 || unidade > 3) {
        system("cls");
        printf("Qual a unidade de medida do valor informado? \n");
        printf("0. Retornar ao menu \n");
        printf("1. Metro Cúbico (m³) \n");
        printf("2. Litro (L) \n");
        printf("3. Mililitro (ml) \n");
        printf("Selecione a opção: ");
        scanf("%d", &unidade);
    }

    if (unidade == 0) {
        return;
    }

    valor_si = VolConverterParaSI(entrada, unidade);

    system("cls");
    printf(" Valor em Metros Cúbicos (SI): %.6lf m³\n", valor_si);
    printf(" Valor em Litros: %.6lf L\n", valor_si * 1000.0);
    printf(" Valor em Mililitros: %.6lf ml\n", valor_si * 1000000.0);
    printf("\nPressione qualquer tecla para retornar ao menu.\n");

    getchar();
    getchar();
    return;
}



void celsiusParaOutros(double celsius, double *fahrenheit, double *kelvin) {
    *fahrenheit = (celsius * 9 / 5) + 32;
    *kelvin = celsius + 273.15;
}

void fahrenheitParaOutros(double fahrenheit, double *celsius, double *kelvin) {
    *celsius = (fahrenheit - 32) * 5 / 9;
    *kelvin = (*celsius) + 273.15;
}

void kelvinParaOutros(double kelvin, double *celsius, double *fahrenheit) {
    *celsius = kelvin - 273.15;
    *fahrenheit = (*celsius * 9 / 5) + 32;
}

void ConversorDeTemperatura() {
    double temperatura, celsius, fahrenheit, kelvin;
    int opcao;
    system("cls");
    printf("\nEscolha a escala de entrada:\n");
    printf("1 - Celsius\n2 - Fahrenheit\n3 - Kelvin\n");
    printf("Opcao: ");
    scanf("%d", &opcao);

    printf("Digite o valor da temperatura: ");
    scanf("%lf", &temperatura);

    if (opcao == 1) {
        celsiusParaOutros(temperatura, &fahrenheit, &kelvin);
        printf("\nCelsius: %.2f\nFahrenheit: %.2f\nKelvin: %.2f\n\n", temperatura, fahrenheit, kelvin);
    } else if (opcao == 2) {
        fahrenheitParaOutros(temperatura, &celsius, &kelvin);
        printf("\nFahrenheit: %.2f\nCelsius: %.2f\nKelvin: %.2f\n\n", temperatura, celsius, kelvin);
    } else if (opcao == 3) {
        kelvinParaOutros(temperatura, &celsius, &fahrenheit);
        printf("\nKelvin: %.2f\nCelsius: %.2f\nFahrenheit: %.2f\n\n", temperatura, celsius, fahrenheit);
    } else {
        printf("Opção inválida.\n");
    }
    
    printf("\nPressione qualquer tecla para retornar ao menu.\n");

    getchar();
    getchar();
}


void segundosParaOutros(float seg, float *min, float *hora) {
    *min = seg / 60;
    *hora = seg / 3600;
}

void minutosParaOutros(float min, float *seg, float *hora) {
    *seg = min * 60;
    *hora = min / 60;
}

void horasParaOutros(float hora, float *seg, float *min) {
    *seg = hora * 3600;
    *min = hora * 60;
}

void ConversorDeTempo() {
    float tempo, seg, min, hora;
    int opcao;

    system("cls");
    printf("Escolha a escala de entrada: \n");
    printf("1 - Segundos\n2 - Minutos\n3 - Horas\n");
    printf("Opcao: ");
    scanf("%d", &opcao);

    printf("\nTempo: ");
    scanf("%f", &tempo);

    if (opcao == 1) {
        segundosParaOutros(tempo, &min, &hora);
        printf("\nSegundos: %.0f\nMinutos: %.2f\nHoras: %.1f\n\n", tempo, min, hora);
    
    }else if(opcao == 2){
        minutosParaOutros(tempo, &seg, &hora);
        printf("\nSegundos: %.0f\nMinutos: %.2f\nHoras: %.1f\n\n", seg, tempo, hora);

    }else if(opcao == 3){
        horasParaOutros(tempo, &seg, &min);
        printf("\nSegundos: %.0f\nMinutos: %.2f\nHoras: %.1f\n\n", seg, min, tempo);

    }else{
        printf("Opcao invalida.\n");
    }

    printf("\nPressione qualquer tecla para retornar ao menu.\n");

    getchar();
    getchar();
}