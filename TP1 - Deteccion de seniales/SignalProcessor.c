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

void signalProcessorPrintProcess(SignalProcessor *processor, int *process) {
    
}

void signalProcessorProduct(int *process,
                            Signal *signal,
                            Codification *codification) {
    int signal_length = signalLength(signal);
    int *signal_list = signalList(signal);
    int sub_length = codificationSignalLength(codification);
    int *sub_list = codificationSignalList(codification);
    
    int process_lenght = signal_length / sub_length;
    
    for (int i = 0; i < process_lenght; i++) {
        int acum = 0;
        for (int j = 0; j < sub_length; j++) {
            int signal_element = signal_list[i * signal_length + j];
            int sub_element = sub_list[j];
            int product = signal_element * sub_element;
            acum += product;
        }
        process[i] = acum;
    }
}

void signalProcessorFunction(SignalProcessor *processor, Signal *signal) {
    Codification *subtraction = (Codification *)malloc(sizeof(Codification));
    Codification *one_codif = argumentOneCodification(&processor->arguments);
    Codification *zero_codif = argumentZeroCodification(&processor->arguments);
    codifiationSubtract(subtraction, one_codif, zero_codif);
    
    int signal_length = signalLength(signal);
    int sub_length = codificationSignalLength(subtraction);
    int process_length = signal_length / sub_length;
    int *process = malloc(process_length * sizeof(int));
    signalProcessorProduct(process, signal, subtraction);
    
    signalProcessorPrintProcess(processor, process);
    
    free(subtraction);
    free(process);
}

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
        signalProcessorFunction(processor, signal);
        free(signal);
        signal = (Signal *)malloc(sizeof(Signal));
    }
    
    free(signal);
}
