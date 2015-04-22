//
//  main.c
//  TP1 - Deteccion de seniales
//
//  Created by Gastón Montes on 4/21/15.
//  Copyright (c) 2015 Gastón Montes. All rights reserved.
//

#include <stdio.h>

#include "Parameters.h"

#define EXECUTION_NORMAL 0
#define EXECUTION_INVALID_PARAMETERS 1
#define EXECUTION_FILES_ERROR 2

int main(int argc, const char * argv[]) {
    Parameters console_parameter;
    parametersCreate(&console_parameter, argc, argv);
    
    if (console_parameter.parameters_code == ParametersCodeFail) {
        return EXECUTION_INVALID_PARAMETERS;
    }
    
    return EXECUTION_NORMAL;
}
