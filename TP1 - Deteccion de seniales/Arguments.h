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

#include "Codification.h"
#include "File.h"

typedef struct {
    int signal_lenght;
    float zero_prob;
    float one_prob;
    int noise_var;
    Codification zero_codif;
    Codification one_codif;
    float gamma;
} Arguments;

/**
 * Create a new arguments data.
 * @param - file: The file that contains the input file.
 **/
void argumentsCreate(Arguments *arguments, File *file);

/**
 * Detroy the Arguments data.
 **/
void argumentsDestroy(Arguments *arguments);

/**
 * Returns the gamma codification.
 **/
float argumentGamma(Arguments *arguments);

/**
 * Returns the cero codification.
 **/
Codification *argumentZeroCodification(Arguments *arguments);

/**
 * Returns the one codification.
 **/
Codification *argumentOneCodification(Arguments *arguments);

#endif /* defined(__TP1___Deteccion_de_seniales__Arguments__) */
