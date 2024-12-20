/* ************************************************************************** */
/*                                                                            */
/*   Embarcatech - Subgrupo 6                                                 */
/*   Depuração e Versionamento                                                */
/*                                                                            */
/*   ConversorDeUnidades.h                                                    */
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

#ifndef CONVERSOR_H
# define CONVERSOR_H

#include    <stdio.h>
#include    <stdlib.h>
#include    <math.h>

typedef struct s_ConversorDeUnidades
{
    double  entrada;
    int     unidade;
    int     unidade_destino;
    double  valor_si; 
    double  resultado; 
    
}           t_ConversorDeUnidades;


int     converterComprimento();
void    ConversorDeVolume(void);


#endif