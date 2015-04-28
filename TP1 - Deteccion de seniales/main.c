//
//  main.c
//  TP1 - Deteccion de seniales
//
//  Created by Gastón Montes on 4/21/15.
//  Copyright (c) 2015 Gastón Montes. All rights reserved.
//

#include <stdio.h>

#include "SignalProcessor.h"
#include "Parameters.h"
#include "Arguments.h"
#include "File.h"

#define EXECUTION_NORMAL 0
#define EXECUTION_INVALID_PARAMETERS 1
#define EXECUTION_FILES_ERROR 2

int createFiles(Parameters *parameters, File *input_file, File *output_file) {
    // Create input file.
    fileCreate(input_file,
               (char *)parametersInputFileName(parameters),
               FileOpenModeRead);
    
    // Create output file.
    fileCreate(output_file,
               (char *)parametersOutputFileName(parameters),
               FileOpenModeWrite);
    
    if (fileOperationCode(input_file) == FileOperationCodeFail ||
        fileOperationCode(output_file) == FileOperationCodeFail) {
        return EXECUTION_FILES_ERROR;
    }
    
    return EXECUTION_NORMAL; 
}

int main(int argc, const char * argv[]) {
    Parameters parameter;
    File input_file;
    File output_file;
    Arguments arguments;
    SignalProcessor processor;
    
    // Create parameter.
    parametersCreate(&parameter, argc, argv);
    if (parametersCode(&parameter) == ParametersCodeFail) {
        return EXECUTION_INVALID_PARAMETERS;
    }
    
    // Create input and output files.
    int creation_code = createFiles(&parameter, &input_file, &output_file);
    if (creation_code != EXECUTION_NORMAL) {
        parametersDestroy(&parameter);
        fileDestroy(&input_file);
        fileDestroy(&output_file);
        return creation_code;
    }
    
    // Create arguments.
    argumentsCreate(&arguments, &input_file);
    
    // Create a sample signal.
    signalProcessorCreate(&processor, arguments, &input_file, &output_file);
    signalProcessorProcess(&processor);
    
    // Destroy all data.
    parametersDestroy(&parameter);
    fileDestroy(&input_file);
    fileDestroy(&output_file);
    argumentsDestroy(&arguments);
    signalProcessorDestroy(&processor);
    
    return EXECUTION_NORMAL;
}
