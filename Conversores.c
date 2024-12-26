
#include "Conversores.h"

void clear_screen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void ConversorDeArea(){
    double valor, valorSI;
    int unidade, opc;
    char cUnidade[9][10] = {"m2", "cm2", "mm2", "km2", "ha", "in2", "ft2", "yd2", "ac"};

    do{
        clear_screen();

        printf("Insira o valor que deseja converter: ");
        scanf(" %lf", &valor);

        do{
        clear_screen();

        printf("Qual a unidade de medida do valor informado? \n\n");
        printf("1. Metro Quadrado (m2)\n");
        printf("2. Centimetro Quadrado (cm2)\n");
        printf("3. Milimetro Quadrado (mm2)\n");
        printf("4. Kilometro Quadrado (km2) \n");
        printf("5. Hectare (ha) \n");
        printf("6. Polegadas Quadradas (in2)\n");
        printf("7. Pes Quadrados (ft2)\n");
        printf("8. Jardas Quadradas (yd2)\n");
        printf("9. Acre (ac)\n");
        printf("0. Retornar ao menu\n");
        scanf("%d", &unidade);

        }while(unidade < 0 || unidade > 9);
        clear_screen();

        switch (unidade)
        {
        case 1: valorSI = valor; break; //m2
        case 2: valorSI = valor * 1e-4; break; //cm2
        case 3: valorSI = valor * 1e-6; break;  //mm2
        case 4: valorSI = valor * 1e6; break;   //km2
        case 5: valorSI = valor * 1e4;  break;  //ha
        case 6: valorSI = valor * 0.00064516; break;    //in2
        case 7: valorSI = valor * 0.09290304; break;    //ft2
        case 8: valorSI = valor * 0.83612736; break;    //yd2
        case 9: valorSI = valor * 4046.8564224; break;  //ac
        case 0: return;

        }

        printf(" %lf %s ----> %lf m2\n", valor,cUnidade[unidade - 1], valorSI);
        printf(" %lf %s ----> %lf cm2\n", valor,cUnidade[unidade - 1], valorSI * 1e4);
        printf(" %lf %s ----> %lf mm2\n", valor,cUnidade[unidade - 1], valorSI * 1e6);
        printf(" %lf %s ----> %lf km2\n", valor,cUnidade[unidade - 1], valorSI * 1e-6);
        printf(" %lf %s ----> %lf ha\n", valor,cUnidade[unidade - 1], valorSI * 1e-4);
        printf(" %lf %s ----> %lf in2\n", valor,cUnidade[unidade - 1], valorSI / 0.00064516);
        printf(" %lf %s ----> %lf ft2\n", valor,cUnidade[unidade - 1], valorSI / 0.09290304);
        printf(" %lf %s ----> %lf yd2\n", valor,cUnidade[unidade - 1], valorSI / 0.83612736);
        printf(" %lf %s ----> %lf ac\n", valor,cUnidade[unidade - 1], valorSI / 4046.8564224);
        printf("\n\nDigite 1 para realizar uma nova conversao de área ou outro valor para retornar ao menu: \n");
        scanf("%d", &opc);
    } while(opc == 1);
}

void ConversorDeComprimento(){

    double valor, valorSI = 0;
    int opc, unidade = 0;
    char prefixo = 'a';

    do
    { 
        clear_screen();

        printf("Insira o valor que deseja converter: ");
        scanf("%lf", &valor);
    
    do{
        clear_screen();

        printf("Qual a unidade de medida do valor informado(%lf)? \n\n", valor);
        printf("1. Metro (m) \n");
        printf("2. Quilometro (Km) \n");
        printf("3. Centimetro (cm) \n");
        printf("4. Milimetro (mm) \n");
        printf("5. Micrometro (um) \n");
        printf("0. Retornar ao menu \n");
        printf("\nOpcao: ");
        scanf("%d", &unidade);
   
    }while(unidade < 0 || unidade > 5);


        clear_screen();

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

void ConversorDePotencia(){
    double valor, valorSI;
    int unidade, opc;
    char cUnidade[20];

    while(1){
        clear_screen();
        printf("Insira o valor que deseja converter: ");
        scanf("%lf", &valor);

        do{
            clear_screen();
            printf("Qual a unidade de medida do valor informado? \n\n");
            printf("1. Watt (W)\n");
            printf("2. Quilowatt (kW)\n");
            printf("3. MegaWatt (MW)\n");
            printf("4. Cavalo-vapor (cv) \n");
            printf("5. Cavalo-força (hp) \n");
            printf("6. British Thermal Unit per hour (BTU/h)\n");
            printf("0. Para sair\n");
            printf("\nSua escolha: ");
            scanf("%d", &unidade);      

        }while(unidade <0 || unidade > 6);

        switch (unidade)
        {
        case 1: valorSI = valor; strcpy(cUnidade, "W"); break;
        case 2: valorSI = valor * 1e3; strcpy(cUnidade, "kW"); break;
        case 3: valorSI = valor * 1e6; strcpy(cUnidade, "MW"); break;
        case 4: valorSI = valor * 735.5; strcpy(cUnidade, "cv"); break;
        case 5: valorSI = valor * 745.7; strcpy(cUnidade, "hp"); break;
        case 6: valorSI = valor * 0.293; strcpy(cUnidade, "BTU/h"); break;
        case 0: printf("Saindo...\n"); return;
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

void ConversorDeVolume() {
    double entrada = 0.0;
    int unidade = -1;
    double valor_si = 0.0;
    int opc;

    do
    {
    
    
        clear_screen();
        printf("Insira o valor que deseja converter: ");
        scanf("%lf", &entrada);

        while (unidade < 0 || unidade > 3) {
            clear_screen();
            printf("Qual a unidade de medida do valor informado? \n");
            printf("1. Metro Cúbico (m³) \n");
            printf("2. Litro (L) \n");
            printf("3. Mililitro (ml) \n");
            printf("0. Retornar ao menu \n");
            printf("Selecione a opção: ");
            scanf("%d", &unidade);
        }

        if (unidade == 0) {
            return;
        }

        valor_si = VolConverterParaSI(entrada, unidade);

        clear_screen();
        printf(" Valor em Metros Cúbicos (SI): %.6lf m³\n", valor_si);
        printf(" Valor em Litros: %.6lf L\n", valor_si * 1000.0);
        printf(" Valor em Mililitros: %.6lf ml\n", valor_si * 1000000.0);
        printf("\n\nDigite 1 para realizar uma nova conversao de volume ou outro valor para retornar ao menu: \n");
        scanf("%d", &opc);

    }while(opc == 1);

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
    int opc;

    do
    {
    
    
        clear_screen();
        printf("\nEscolha a escala de entrada:\n");
        printf("1 - Celsius\n2 - Fahrenheit\n3 - Kelvin\n");
        printf("Opcao: ");
        scanf("%d", &opc);

        printf("Digite o valor da temperatura: ");
        scanf("%lf", &temperatura);

        if (opc == 1) {
            celsiusParaOutros(temperatura, &fahrenheit, &kelvin);
            printf("\nCelsius: %.2f\nFahrenheit: %.2f\nKelvin: %.2f\n\n", temperatura, fahrenheit, kelvin);
        } else if (opc == 2) {
            fahrenheitParaOutros(temperatura, &celsius, &kelvin);
            printf("\nFahrenheit: %.2f\nCelsius: %.2f\nKelvin: %.2f\n\n", temperatura, celsius, kelvin);
        } else if (opc == 3) {
            kelvinParaOutros(temperatura, &celsius, &fahrenheit);
            printf("\nKelvin: %.2f\nCelsius: %.2f\nFahrenheit: %.2f\n\n", temperatura, celsius, fahrenheit);
        } else {
            printf("Opção inválida.\n");
        }
        
        printf("\n\nDigite 1 para realizar uma nova conversao de temperatura ou outro valor para retornar ao menu: \n");
        scanf("%d", &opc);

            
    } while (opc == 1);
    return;
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
    int opc;

    do{

        clear_screen();
        printf("Escolha a escala de entrada: \n");
        printf("1 - Segundos\n2 - Minutos\n3 - Horas\n");
        printf("Opcao: ");
        scanf("%d", &opc);

        printf("\nTempo: ");
        scanf("%f", &tempo);

        if (opc == 1) {
            segundosParaOutros(tempo, &min, &hora);
            printf("\nSegundos: %.0f\nMinutos: %.6f\nHoras: %.1f\n\n", tempo, min, hora);
        
        }else if(opc == 2){
            minutosParaOutros(tempo, &seg, &hora);
            printf("\nSegundos: %.0f\nMinutos: %.6f\nHoras: %.1f\n\n", seg, tempo, hora);

        }else if(opc == 3){
            horasParaOutros(tempo, &seg, &min);
            printf("\nSegundos: %.0f\nMinutos: %.6f\nHoras: %.1f\n\n", seg, min, tempo);

        }else{
            printf("Opcao invalida.\n");
        }

        printf("\n\nDigite 1 para realizar uma nova conversao de tempo ou outro valor para retornar ao menu: \n");
        scanf("%d", &opc);

    }while(opc == 1);

    return;
}

void ConversorDeDados() {
    int opc;
    double valor;

    do{

        do{
            clear_screen();

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
            scanf("%d", &opc);

        }while(opc < 1 || opc > 30);


        printf("Digite o valor para conversao. ");
        scanf("%lf", &valor);

        switch (opc) {
            case 1:
                printf("%.2f Bits = %.2f Bytes\n", valor, valor / 8);
                break;
            case 2:
                printf("%.2f Bytes = %.2f Bits\n", valor, valor * 8);
                break;
            case 3:
                printf("%.2f Bytes = %.2f KB\n", valor, valor / 1024);
                break;
            case 4:
                printf("%.2f Bytes = %.2f MB\n", valor, valor / (1024 * 1024));
                break;
            case 5:
                printf("%.2f Bytes = %.2f GB\n", valor, valor / (1024 * 1024 * 1024));
                break;
            case 6:
                printf("%.2f Bytes = %.2f TB\n", valor, valor / (1024.0 * 1024 * 1024 * 1024));
                break;
            case 7:
                printf("%.2f KB = %.2f Bytes\n", valor, valor * 1024);
                break;
            case 8:
                printf("%.2f KB = %.2f MB\n", valor, valor / 1024);
                break;
            case 9:
                printf("%.2f KB = %.2f GB\n", valor, valor / (1024 * 1024));
                break;
            case 10:
                printf("%.2f KB = %.2f TB\n", valor, valor / (1024.0 * 1024 * 1024));
                break;
            case 11:
                printf("%.2f MB = %.2f KB\n", valor, valor * 1024);
                break;
            case 12:
                printf("%.2f MB = %.2f Bytes\n", valor, valor * 1024 * 1024);
                break;
            case 13:
                printf("%.2f MB = %.2f GB\n", valor, valor / 1024);
                break;
            case 14:
                printf("%.2f MB = %.2f TB\n", valor, valor / (1024 * 1024));
                break;
            case 15:
                printf("%.2f GB = %.2f MB\n", valor, valor * 1024);
                break;
            case 16:
                printf("%.2f GB = %.2f KB\n", valor, valor * 1024 * 1024);
                break;
            case 17:
                printf("%.2f GB = %.2f Bytes\n", valor, valor * 1024 * 1024 * 1024);
                break;
            case 18:
                printf("%.2f GB = %.2f TB\n", valor, valor / 1024);
                break;
            case 19:
                printf("%.2f TB = %.2f GB\n", valor, valor * 1024);
                break;
            case 20:
                printf("%.2f TB = %.2f MB\n", valor, valor * 1024 * 1024);
                break;
            case 21:
                printf("%.2f TB = %.2f KB\n", valor, valor * 1024 * 1024 * 1024);
                break;
            case 22:
                printf("%.2f TB = %.2f Bytes\n", valor, valor * 1024.0 * 1024 * 1024 * 1024);
                break;
            case 23:
                printf("%.2f Bits = %.2f KB\n", valor, valor / (8 * 1024));
                break;
            case 24:
                printf("%.2f KB = %.2f Bits\n", valor, valor * 8 * 1024);
                break;
            case 25:
                printf("%.2f Bits = %.2f MB\n", valor, valor / (8 * 1024 * 1024));
                break;
            case 26:
                printf("%.2f MB = %.2f Bits\n", valor, valor * 8 * 1024 * 1024);
                break;
            case 27:
                printf("%.2f Bits = %.2f GB\n", valor, valor / (8LL * 1024 * 1024 * 1024));
                break;
            case 28:
                printf("%.2f GB = %.2f Bits\n", valor, valor * 8 * 1024 * 1024 * 1024);
                break;
            case 29:
                printf("%.2f Bits = %.2f TB\n", valor, valor / (8.0 * 1024 * 1024 * 1024 * 1024));
                break;
            case 30:
                printf("%.2f TB = %.2f Bits\n", valor, valor * 8.0 * 1024 * 1024 * 1024 * 1024);
                break;
            default:
                printf("Opção invalida. \n");
                break;
        }

        printf("\n\nDigite 1 para realizar uma nova conversao de dados ou outro valor para retornar ao menu: \n");
        scanf("%d", &opc);

    }while (opc == 1);

    return;
}

void ConversorDeVelocidade() {

    double valor, resultado1, resultado2;
    int unidade = 0, opc;

    do
    {
        do
        {
            clear_screen();

            printf("Insira o valor que deseja converter: ");
            scanf("%lf", &valor);

            clear_screen();

            printf("Qual a unidade de medida do valor informado? \n");
            printf("1. Quilometro por hora (km/h) \n");
            printf("2. Metro por segundo (m/s) \n");
            printf("3. Milhas por hora (mph) \n");
            printf("0. Retornar ao menu \n");
            printf("Opcao: ");
            scanf("%d", &unidade);

        } while (unidade < 0 || unidade > 3);

        clear_screen();

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

        printf("\n\nDigite 1 para realizar uma nova conversao de velocidade ou outro valor para retornar ao menu: ");
        scanf("%d", &opc);

    } while (opc == 1);
}


void ConversorDeMassa() {
    int opc;
    float valor;

    do {

        clear_screen();

        printf("\nConversao de Massas:\n");
        printf("1. Quilograma\n");
        printf("2. Grama\n");
        printf("3. Tonelada\n");
        printf("\nEscolha a unidade de entrada (1-3): ");
        scanf("%d", &opc);

        if (opc < 1 || opc > 3) {
            printf("Opção inválida. Tente novamente.\n");
            continue;
        }

        printf("Digite o valor: ");
        scanf("%f", &valor);

        switch (opc) {
            case 1: // Quilograma
                printf("\n%.2f quilograma(s) equivalem a %.2f grama(s) e %.6f tonelada(s).\n", 
                       valor, valor * 1000, valor / 1000);
                break;
            case 2: // Grama
                printf("\n%.2f grama(s) equivalem a %.6f quilograma(s) e %.6f tonelada(s).\n", 
                       valor, valor / 1000, valor / 1000000);
                break;
            case 3: // Tonelada
                printf("\n%.2f tonelada(s) equivalem a %.2f quilograma(s) e %.2f grama(s).\n", 
                       valor, valor * 1000, valor * 1000000);
                break;
        }

        printf("\n\nDigite 1 para realizar uma nova conversao de ou outro valor para retornar ao menu: ");
        scanf("%d", &opc);
    } while (opc == 1);
}

