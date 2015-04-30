//
//  Arguments.c
//  TP1 - Deteccion de seniales
//
//  Created by Gastón Montes on 4/22/15.
//  Copyright (c) 2015 Gastón Montes. All rights reserved.
//

#include <stdlib.h>
#include <math.h>

#include "Arguments.h"

void argumentsCalculateGamma(Arguments *arguments) {
    // First term.
    float prob_div = arguments->zero_prob/arguments->one_prob;
    float natural_log = log(prob_div);
    float first_term = arguments->noise_var * natural_log;
    
    // Second term.
    Codification one_codif = arguments->one_codif;
    Codification zero_codif = arguments->zero_codif;
    int one_product = codificationProduct(&one_codif, &one_codif);
    int zero_product = codificationProduct(&zero_codif, &zero_codif);
    float subtraction = one_product - zero_product;
    float second_term = subtraction / 2;
    
    arguments->gamma = first_term + second_term;
}

void argumentsCreate(Arguments *arguments, File *file) {
    arguments->signal_lenght = 0;
    arguments->zero_prob = 0.0;
    arguments->one_prob = 0.0;
    arguments->noise_var = 0;
    arguments->gamma = 0.0;
    
    // Read line from input file (File is in correct format).
    char *line_buffer = (char *)malloc(sizeof(char) * LINE_MAX_LENGHT);
    fileReadLine(file, line_buffer, LINE_MAX_LENGHT);
    sscanf(line_buffer, "%d,%f,%f,%d",
           &arguments->signal_lenght,
           &arguments->zero_prob,
           &arguments->one_prob,
           &arguments->noise_var);
    
    // Create S(0) codification.
    codificationCreate(&arguments->zero_codif, file, arguments->signal_lenght);
    
    // Create S(1) codification.
    codificationCreate(&arguments->one_codif, file, arguments->signal_lenght);
    
    argumentsCalculateGamma(arguments);
    
    free(line_buffer);
}

void argumentsDestroy(Arguments *arguments) {
    arguments->signal_lenght = 0;
    arguments->zero_prob = 0;
    arguments->one_prob = 0;
    arguments->noise_var = 0;
    codificationDestroy(&arguments->zero_codif);
    codificationDestroy(&arguments->one_codif);
}

float argumentGamma(Arguments *arguments) {
    return arguments->gamma;
}

Codification *argumentZeroCodification(Arguments *arguments) {
    return &arguments->zero_codif;
}

Codification *argumentOneCodification(Arguments *arguments) {
    return &arguments->one_codif;
}
