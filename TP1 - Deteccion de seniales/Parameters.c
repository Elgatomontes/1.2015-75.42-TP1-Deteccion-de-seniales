//
//  Parameters.c
//  TP1 - Deteccion de seniales
//
//  Created by Gastón Montes on 4/21/15.
//  Copyright (c) 2015 Gastón Montes. All rights reserved.
//

#include <string.h>

#include "Parameters.h"

#define IN_FILE_PARAMETER_KEY "-i"
#define OUT_FILE_PARAMETER_KEY "-o"
#define FIRST_PARAMETER_KEY_INDEX 1
#define FIRST_PARAMETER_INDEX 2
#define SECOND_PARAMETER_KEY_INDEX 3
#define SECOND_PARAMETER_INDEX 4

void setInvalidConfiguration(Parameters *parameters)
{
    parameters->parameters_code = ParametersCodeFail;
    parameters->input_file = NULL;
    parameters->output_file = NULL;
}

void parseParameters(Parameters *parameters,
                     const char *parameter,
                     const char *parameter_type) {
    if (strcmp(parameter_type, IN_FILE_PARAMETER_KEY) == 0) {
        parameters->input_file = parameter;
        parameters->parameters_code = ParametersCodeOK;
    } else if (strcmp(parameter_type, OUT_FILE_PARAMETER_KEY) == 0) {
        parameters->output_file = parameter;
        parameters->parameters_code = ParametersCodeOK;
    } else {
        setInvalidConfiguration(parameters);
    }
}

void parametersCreate(Parameters *parameters_parser,
                      int parameters_count,
                      const char *parameters[]) {
    setInvalidConfiguration(parameters_parser);
    
    switch (parameters_count) {
        case 1:
            parameters_parser->parameters_code = ParametersCodeOK;
            break;
        case 3:
            parseParameters(parameters_parser,
                            parameters[FIRST_PARAMETER_INDEX],
                            parameters[FIRST_PARAMETER_KEY_INDEX]);
            break;
        case 5:
            parseParameters(parameters_parser,
                            parameters[FIRST_PARAMETER_INDEX],
                            parameters[FIRST_PARAMETER_KEY_INDEX]);
            
            if (parameters_parser->parameters_code != ParametersCodeFail) {
                parseParameters(parameters_parser,
                                parameters[SECOND_PARAMETER_INDEX],
                                parameters[SECOND_PARAMETER_KEY_INDEX]);
            }
            break;
        default:
            setInvalidConfiguration(parameters_parser);
            break;
    }
}

void parametersDestroy(Parameters *parameters_parser) {
    parameters_parser->input_file = NULL;
    parameters_parser->output_file = NULL;
    parameters_parser->parameters_code = ParametersCodeFail;
}

const char *parametersInputFileName(Parameters *parameters) {
    return parameters->input_file;
}

const char *parametersOutputFileName(Parameters *parameters) {
    return parameters->output_file;
}

ParametersCode parametersCode(Parameters *parameters) {
    return parameters->parameters_code;
}
