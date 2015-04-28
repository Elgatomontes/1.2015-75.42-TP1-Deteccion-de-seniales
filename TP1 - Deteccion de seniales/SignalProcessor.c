//
//  SignalProcessor.c
//  TP1 - Deteccion de seniales
//
//  Created by Gastón Montes on 4/27/15.
//  Copyright (c) 2015 Gastón Montes. All rights reserved.
//

#include <stdlib.h>

#include "SignalProcessor.h"
#include "Signal.h"

void signalProcessorCreate(SignalProcessor *processor,
                           Arguments arguments,
                           File *input_file,
                           File *output_file) {
    processor->arguments = arguments;
    processor->input_file = input_file;
    processor->output_file = output_file;
}

void signalProcessorDestroy(SignalProcessor *processor) {
}

void signalProcessorProcess(SignalProcessor *processor) {
    
    Signal *signal = (Signal *)malloc(sizeof(Signal));
    
    while (signalCreate(signal, processor->input_file) == SignalCreateCodeOK) {
        printf("--------------- SignalProcessor --------------\n");
        printf("Entre a procesar\n");
        free(signal);
        signal = (Signal *)malloc(sizeof(Signal));
    }
    
    free(signal);
}
