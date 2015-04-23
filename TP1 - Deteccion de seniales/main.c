//
//  main.c
//  TP1 - Deteccion de seniales
//
//  Created by Gastón Montes on 4/21/15.
//  Copyright (c) 2015 Gastón Montes. All rights reserved.
//

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "Parameters.h"
#include "Arguments.h"
#include "File.h"

#define EXECUTION_NORMAL 0
#define EXECUTION_INVALID_PARAMETERS 1
#define EXECUTION_FILES_ERROR 2

#define LINE_MAX_LENGHT 255

int main(int argc, const char * argv[]) {
    Parameters console_parameter;
    File input_file;
    File output_file;
    Arguments arguments;
    char *line_buffer;
    
    parametersCreate(&console_parameter, argc, argv);
    if (parametersCode(&console_parameter) == ParametersCodeFail) {
        return EXECUTION_INVALID_PARAMETERS;
    }
    
    fileCreate(&input_file,
               (char *)parametersInputFileName(&console_parameter),
               FileOpenModeRead);
    if (fileOperationCode(&input_file) == FileOperationCodeFail) {
        parametersDestroy(&console_parameter);
        return EXECUTION_FILES_ERROR;
    }
    
    fileCreate(&output_file,
               (char *)parametersOutputFileName(&console_parameter),
               FileOpenModeWrite);
    if (fileOperationCode(&output_file) == FileOperationCodeFail) {
        parametersDestroy(&console_parameter);
        fileDestroy(&input_file);
        return EXECUTION_FILES_ERROR;
    }
    
    line_buffer = (char *)malloc(sizeof(char)*LINE_MAX_LENGHT);
    if (fileReadLine(&input_file, line_buffer, LINE_MAX_LENGHT) == FileOperationCodeFail) {
        parametersDestroy(&console_parameter);
        fileDestroy(&input_file);
        fileDestroy(&output_file);
    }
    argumentsCreate(&arguments, line_buffer);
    
    // Destroy all data.
    parametersDestroy(&console_parameter);
    fileDestroy(&input_file);
    fileDestroy(&output_file);
    argumentsDestroy(&arguments);
    free(line_buffer);
    
    return EXECUTION_NORMAL;
}
