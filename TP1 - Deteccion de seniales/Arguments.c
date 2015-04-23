//
//  Arguments.c
//  TP1 - Deteccion de seniales
//
//  Created by Gastón Montes on 4/22/15.
//  Copyright (c) 2015 Gastón Montes. All rights reserved.
//

#include "Arguments.h"

void argumentsCreate(Arguments *arguments, const char *line) {
}

void argumentsDestroy(Arguments *arguments) {
    
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
