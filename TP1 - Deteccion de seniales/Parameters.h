//
//  Parameters.h
//  TP1 - Deteccion de seniales
//
//  Created by Gastón Montes on 4/21/15.
//  Copyright (c) 2015 Gastón Montes. All rights reserved.
//

#ifndef __TP1___Deteccion_de_seniales__Parameters__
#define __TP1___Deteccion_de_seniales__Parameters__

#include <stdio.h>

typedef enum {
    ParametersCodeOK,
    ParametersCodeFail
} ParametersCode;

typedef struct {
    ParametersCode parameters_code;
    const char *input_file;
    const char *output_file;
} Parameters;

/**
 * Create console arguments data parser.
 * @param - parameters_parser: The console parameters parser.
 * @param - parameters_count: The number of parameters.
 * @param - parameters[]: The list of parameters.
 **/
void parametersCreate(Parameters *parameters_parser,
                      int parameters_count,
                      const char *parameters[]);

void parametersDestroy(Parameters *parameters_parser);

/**
 * Returns the input file name.
 * @param - parameters: The console parameters parser.
 **/
const char *parameterInputFileName(Parameters *parameters);

/**
 * Returns the output file name.
 * @param - parameters: The console parameters parser.
 **/
const char *parameterOutputFileName(Parameters *parameters);

#endif /* defined(__TP1___Deteccion_de_seniales__Parameters__) */
