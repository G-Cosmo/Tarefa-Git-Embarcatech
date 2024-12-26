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
/*       Fontana <gui.fontana0701@gmail.com>                                  */
/*       MelkBraga <melksb@hotmail.com>                                       */
/*                                                                            */
/* ************************************************************************** */



#include "Conversores.h"


int main(){
    int opc;

    system("chcp 65001>null");

    do
    {
        clear_screen();
        printf("Escolha a opcao de conversao desejada: \n");
        printf("1. Comprimento \n");
        printf("2. Potencia \n");
        printf("3. Temperatura \n");
        printf("4. Volume \n");
        printf("5. Tempo \n");
        printf("6. Dados \n");
        printf("7. Velocidade\n");
        printf("8. Area\n");
        printf("9. Massa\n");
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
                ConversorDeTempo();
                break;
            case 6:
                ConversorDeDados();
                break; 
            case 7:
                ConversorDeVelocidade();
                break;
            case 8:
                ConversorDeArea();
                break;
            case 9:
                ConversorDeMassa();
                break;
            default:
                break;
        }
    } while (opc != 0);
}