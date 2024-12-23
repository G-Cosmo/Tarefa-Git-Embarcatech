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
/*       MelkBraga <melksb@hotmail.com>                                       */
/*                                                                            */
/* ************************************************************************** */



#include "ConversorDeUnidades.h"
#include <stdio.h>



int main(){
    int opc;

    do
    {
        system("cls");
        printf("Escolha a opcao de conversao desejada: \n");
        printf("1. Comprimento \n");
        printf("2. Potencia \n");
        printf("3. Temperatura \n");
        printf("4. Volume \n");
        printf("5. Dados \n");
        printf("6. Velocidade\n");

        printf("0. Sair \n");
        printf("Opcao: ");
        scanf("%d", &opc);
        
        switch (opc) {
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
                ConversorDeDados();
                break;
            case 6:
                ConversorDeVelocidade();
                break; 
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
                return;
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



void converterBitsParaBytes(double valor) {
    printf("%.2f Bits = %.2f Bytes\n", valor, valor / 8);
}

void converterBytesParaBits(double valor) {
    printf("%.2f Bytes = %.2f Bits\n", valor, valor * 8);
}

void converterBytesParaKB(double valor) {
    printf("%.2f Bytes = %.2f KB\n", valor, valor / 1024);
}

void converterBytesParaMB(double valor) {
    printf("%.2f Bytes = %.2f MB\n", valor, valor / (1024 * 1024));
}

void converterBytesParaGB(double valor) {
    printf("%.2f Bytes = %.2f GB\n", valor, valor / (1024 * 1024 * 1024));
}

void converterBytesParaTB(double valor) {
    printf("%.2f Bytes = %.2f TB\n", valor, valor / (1024.0 * 1024 * 1024 * 1024));
}

void converterKBParaBytes(double valor) {
    printf("%.2f KB = %.2f Bytes\n", valor, valor * 1024);
}

void converterKBParaMB(double valor) {
    printf("%.2f KB = %.2f MB\n", valor, valor / 1024);
}

void converterKBParaGB(double valor) {
    printf("%.2f KB = %.2f GB\n", valor, valor / (1024 * 1024));
}

void converterKBParaTB(double valor) {
    printf("%.2f KB = %.2f TB\n", valor, valor / (1024.0 * 1024 * 1024));
}

void converterMBParaKB(double valor) {
    printf("%.2f MB = %.2f KB\n", valor, valor * 1024);
}

void converterMBParaBytes(double valor) {
    printf("%.2f MB = %.2f Bytes\n", valor, valor * 1024 * 1024);
}

void converterMBParaGB(double valor) {
    printf("%.2f MB = %.2f GB\n", valor, valor / 1024);
}

void converterMBParaTB(double valor) {
    printf("%.2f MB = %.2f TB\n", valor, valor / (1024 * 1024));
}

void converterGBParaMB(double valor) {
    printf("%.2f GB = %.2f MB\n", valor, valor * 1024);
}

void converterGBParaKB(double valor) {
    printf("%.2f GB = %.2f KB\n", valor, valor * 1024 * 1024);
}

void converterGBParaBytes(double valor) {
    printf("%.2f GB = %.2f Bytes\n", valor, valor * 1024 * 1024 * 1024);
}

void converterGBParaTB(double valor) {
    printf("%.2f GB = %.2f TB\n", valor, valor / 1024);
}

void converterTBParaGB(double valor) {
    printf("%.2f TB = %.2f GB\n", valor, valor * 1024);
}

void converterTBParaMB(double valor) {
    printf("%.2f TB = %.2f MB\n", valor, valor * 1024 * 1024);
}

void converterTBParaKB(double valor) {
    printf("%.2f TB = %.2f KB\n", valor, valor * 1024 * 1024 * 1024);
}

void converterTBParaBytes(double valor) {
    printf("%.2f TB = %.2f Bytes\n", valor, valor * 1024.0 * 1024 * 1024 * 1024);
}

void converterBitsParaKB(double valor) {
    printf("%.2f Bits = %.2f KB\n", valor, valor / (8 * 1024));
}

void converterKBParaBits(double valor) {
    printf("%.2f KB = %.2f Bits\n", valor, valor * 8 * 1024);
}

void converterBitsParaMB(double valor) {
    printf("%.2f Bits = %.2f MB\n", valor, valor / (8 * 1024 * 1024));
}

void converterMBParaBits(double valor) {
    printf("%.2f MB = %.2f Bits\n", valor, valor * 8 * 1024 * 1024);
}

void converterBitsParaGB(double valor) {
    printf("%.2f Bits = %.2f GB\n", valor, valor / (8 * 1024 * 1024 * 1024));
}

void converterGBParaBits(double valor) {
    printf("%.2f GB = %.2f Bits\n", valor, valor * 8 * 1024 * 1024 * 1024);
}

void converterBitsParaTB(double valor) {
    printf("%.2f Bits = %.2f TB\n", valor, valor / (8.0 * 1024 * 1024 * 1024 * 1024));
}

void converterTBParaBits(double valor) {
    printf("%.2f TB = %.2f Bits\n", valor, valor * 8.0 * 1024 * 1024 * 1024 * 1024);
}

int ConversorDados() {
    int opcao;
    double valor;

    printf("Escolha a conversao que deseja realizar:\n");
    printf("1. Bits para Bytes\n");
    printf("2. Bytes para Bits\n");
    printf("3. Bytes para KB\n");
    printf("4. Bytes para MB\n");
    printf("5. Bytes para GB\n");
    printf("6. Bytes para TB\n");
    printf("7. KB para Bytes\n");
    printf("8. KB para MB\n");
    printf("9. KB para GB\n");
    printf("10. KB para TB\n");
    printf("11. MB para KB\n");
    printf("12. MB para Bytes\n");
    printf("13. MB para GB\n");
    printf("14. MB para TB\n");
    printf("15. GB para MB\n");
    printf("16. GB para KB\n");
    printf("17. GB para Bytes\n");
    printf("18. GB para TB\n");
    printf("19. TB para GB\n");
    printf("20. TB para MB\n");
    printf("21. TB para KB\n");
    printf("22. TB para Bytes\n");
    printf("23. Bits para KB\n");
    printf("24. KB para Bits\n");
    printf("25. Bits para MB\n");
    printf("26. MB para Bits\n");
    printf("27. Bits para GB\n");
    printf("28. GB para Bits\n");
    printf("29. Bits para TB\n");
    printf("30. TB para Bits\n");

    printf("Digite a opcao desejada: ");
    scanf("%d", &opcao);

    if (opcao < 1 || opcao > 30) {
        printf("Opcao invalida. \n");
        return 1;
    }

    printf("Digite o valor para conversao. ");
    scanf("%lf", &valor);

    switch (opcao) {
        case 1:
            converterBitsParaBytes(valor);
            break;
        case 2:
            converterBytesParaBits(valor);
            break;
        case 3:
            converterBytesParaKB(valor);
            break;
        case 4:
            converterBytesParaMB(valor);
            break;
        case 5:
            converterBytesParaGB(valor);
            break;
        case 6:
            converterBytesParaTB(valor);
            break;
        case 7:
            converterKBParaBytes(valor);
            break;
        case 8:
            converterKBParaMB(valor);
            break;
        case 9:
            converterKBParaGB(valor);
            break;
        case 10:
            converterKBParaTB(valor);
            break;
        case 11:
            converterMBParaKB(valor);
            break;
        case 12:
            converterMBParaBytes(valor);
            break;
        case 13:
            converterMBParaGB(valor);
            break;
        case 14:
            converterMBParaTB(valor);
            break;
        case 15:
            converterGBParaMB(valor);
            break;
        case 16:
            converterGBParaKB(valor);
            break;
        case 17:
            converterGBParaBytes(valor);
            break;
        case 18:
            converterGBParaTB(valor);
            break;
        case 19:
            converterTBParaGB(valor);
            break;
        case 20:
            converterTBParaMB(valor);
            break;
        case 21:
            converterTBParaKB(valor);
            break;
        case 22:
            converterTBParaBytes(valor);
            break;
        case 23:
            converterBitsParaKB(valor);
            break;
        case 24:
            converterKBParaBits(valor);
            break;
        case 25:
            converterBitsParaMB(valor);
            break;
        case 26:
            converterMBParaBits(valor);
            break;
        case 27:
            converterBitsParaGB(valor);
            break;
        case 28:
            converterGBParaBits(valor);
            break;
        case 29:
            converterBitsParaTB(valor);
            break;
        case 30:
            converterTBParaBits(valor);
            break;
        default:
            printf("Opção invalida. \n");
            break;
    }
    return 0;
}

void ConversorDeVelocidade(void) {

    double valor, resultado1, resultado2;
    int unidade = 0, opc;

    do
    {
        do
        {
            system("cls");

            printf("Insira o valor que deseja converter: ");
            scanf("%lf", &valor);

            system("cls");

            printf("Qual a unidade de medida do valor informado? \n");
            printf("1. Quilometro por hora (km/h) \n");
            printf("2. Metro por segundo (m/s) \n");
            printf("3. Milhas por hora (mph) \n");
            printf("0. Retornar ao menu \n");
            printf("Opcao: ");
            scanf("%d", &unidade);

        } while (unidade < 0 || unidade > 3);

        system("cls");

        switch (unidade) {

            case 0:
                return;

            case 1: // km/h
                resultado1 = valor / 3.6;          // Conversão para m/s
                resultado2 = valor * 0.621371;    // Conversão para mph
                printf("%.2f km/h = %.2f m/s\n", valor, resultado1);
                printf("%.2f km/h = %.2f mph\n", valor, resultado2);
                break;

            case 2: // m/s
                resultado1 = valor * 3.6;         // Conversão para km/h
                resultado2 = valor * 2.23694;     // Conversão para mph
                printf("%.2f m/s = %.2f km/h\n", valor, resultado1);
                printf("%.2f m/s = %.2f mph\n", valor, resultado2);
                break;

            case 3: // mph
                resultado1 = valor / 0.621371;    // Conversão para km/h
                resultado2 = valor / 2.23694;     // Conversão para m/s
                printf("%.2f mph = %.2f km/h\n", valor, resultado1);
                printf("%.2f mph = %.2f m/s\n", valor, resultado2);
                break;
        }

        printf("\n\nDigite 5 para realizar uma nova conversao de comprimento ou outro valor para retornar ao menu: ");
        scanf("%d", &opc);

    } while (opc == 5);
}
