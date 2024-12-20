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
    double  valor_si;     
}           t_ConversorDeUnidades;


void     ConversorDeComprimento(void);
void    ConversorDeVolume(void);


#endif