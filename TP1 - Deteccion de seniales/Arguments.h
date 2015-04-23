//
//  Arguments.h
//  TP1 - Deteccion de seniales
//
//  Created by Gastón Montes on 4/22/15.
//  Copyright (c) 2015 Gastón Montes. All rights reserved.
//

#ifndef __TP1___Deteccion_de_seniales__Arguments__
#define __TP1___Deteccion_de_seniales__Arguments__

#include <stdio.h>

typedef struct {
    int signal_lenght;
    float zero_prob;
    float one_prob;
    int noise_var;
} Arguments;

/**
 * Create a new arguments data.
 * @param - line: The line read from file with <N>, <P(0)>, <P(1)>, <var>.
 **/
void argumentsCreate(Arguments *arguments, const char *line);

/**
 * Detroy the Arguments data.
 **/
void argumentsDestroy(Arguments *arguments);

/**
 * Returns the signalLenght.
 **/
int argumentsSignalLenght(Arguments *arguments);

/**
 * Returns the zero probability argument.
 **/
float argumentsZeroProbability(Arguments *arguments);

/**
 * Returns the one probability argument.
 **/
float argumentsOneProbability(Arguments *arguments);

/**
 * Returns the noise variance.
 **/
int argumentsNoiseVariance(Arguments *arguments);

#endif /* defined(__TP1___Deteccion_de_seniales__Arguments__) */
