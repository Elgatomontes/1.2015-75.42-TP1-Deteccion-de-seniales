//
//  Arguments.c
//  TP1 - Deteccion de seniales
//
//  Created by Gastón Montes on 4/22/15.
//  Copyright (c) 2015 Gastón Montes. All rights reserved.
//

#include <stdlib.h>

#include "Arguments.h"

#define LINE_MAX_LENGHT 255

void argumentsCreate(Arguments *arguments, File *file) {
    // Read line from input file (File is in correct format).
    char *line_buffer = malloc(sizeof(char) * LINE_MAX_LENGHT);
    fileReadLine(file, line_buffer, LINE_MAX_LENGHT);
    sscanf(line_buffer, "%d,%f,%f,%d",
           &arguments->signal_lenght,
           &arguments->zero_prob,
           &arguments->one_prob,
           &arguments->noise_var);
    printf("---------- Argumentos leídos ----------\n Longitud de señales: %d.\n Probabilidad de cero: %f.\n Probabilidad de uno: %f.\n Varianza del ruido: %d.\n",
           arguments->signal_lenght,
           arguments->zero_prob,
           arguments->one_prob,
           arguments->noise_var);
    
    // Create S(0) codification.
    fileReadLine(file, line_buffer, LINE_MAX_LENGHT);
    
    // Create S(1) codification.
    fileReadLine(file, line_buffer, LINE_MAX_LENGHT);
    
    free(line_buffer);
}

void argumentsDestroy(Arguments *arguments) {
    arguments->signal_lenght = 0;
    arguments->zero_prob = 0;
    arguments->one_prob = 0;
    arguments->noise_var = 0;
}

int argumentsSignalLenght(Arguments *arguments) {
    return arguments->signal_lenght;
}

float argumentsZeroProbability(Arguments *arguments) {
    return arguments->zero_prob;
}

float argumentsOneProbability(Arguments *arguments) {
    return arguments->one_prob;
}

int argumentsNoiseVariance(Arguments *arguments) {
    return arguments->noise_var;
}
