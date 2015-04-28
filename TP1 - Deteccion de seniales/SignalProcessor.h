//
//  SignalProcessor.h
//  TP1 - Deteccion de seniales
//
//  Created by Gastón Montes on 4/27/15.
//  Copyright (c) 2015 Gastón Montes. All rights reserved.
//

#ifndef __TP1___Deteccion_de_seniales__SignalProcessor__
#define __TP1___Deteccion_de_seniales__SignalProcessor__

#include <stdio.h>

#include "Arguments.h"
#include "File.h"

typedef struct {
    File *input_file;
    File *output_file;
    Arguments arguments;
} SignalProcessor;

/**
 * Create the processor to process the signals in input_file.
 * @param - arguments: The Arguments to process the signals.
 * @param - input_file: The file with the signals to process.
 * @param - output_file: The file to write the processes signals.
 **/
void signalProcessorCreate(SignalProcessor *processor,
                           Arguments *arguments,
                           File *input_file,
                           File *output_file);

/**
 * Detroy the SignalProcessor data.
 **/
void signalProcessorDestroy(SignalProcessor *processor);

#endif /* defined(__TP1___Deteccion_de_seniales__SignalProcessor__) */
