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

int createFile(Parameters *parameters, File *input_file, File *output_file) {
    // Create input file.
    fileCreate(input_file,
               (char *)parametersInputFileName(parameters),
               FileOpenModeRead);
    if (fileOperationCode(input_file) == FileOperationCodeFail) {
        parametersDestroy(parameters);
        return EXECUTION_FILES_ERROR;
    }
    
    // Create output file.
    fileCreate(output_file,
               (char *)parametersOutputFileName(parameters),
               FileOpenModeWrite);
    if (fileOperationCode(output_file) == FileOperationCodeFail) {
        parametersDestroy(parameters);
        fileDestroy(input_file);
        return EXECUTION_FILES_ERROR;
    }
    
    return EXECUTION_NORMAL; 
}

int main(int argc, const char * argv[]) {
    Parameters console_parameter;
    File input_file;
    File output_file;
    Arguments arguments;
    char *line_buffer;
    
    // Create parameter.
    parametersCreate(&console_parameter, argc, argv);
    if (parametersCode(&console_parameter) == ParametersCodeFail) {
        return EXECUTION_INVALID_PARAMETERS;
    }
    
    // Create input and output files.
    int f_creation = createFile(&console_parameter, &input_file, &output_file);
    if (f_creation != EXECUTION_NORMAL) {
        return f_creation;
    }
    
    // Read line from input file (File is in correct format).
    line_buffer = (char *)malloc(sizeof(char)*LINE_MAX_LENGHT);
    fileReadLine(&input_file, line_buffer, LINE_MAX_LENGHT);
    
    // Create arguments.
    argumentsCreate(&arguments, line_buffer);
    
    // Destroy all data.
    parametersDestroy(&console_parameter);
    fileDestroy(&input_file);
    fileDestroy(&output_file);
    argumentsDestroy(&arguments);
    free(line_buffer);
    
    return EXECUTION_NORMAL;
}
