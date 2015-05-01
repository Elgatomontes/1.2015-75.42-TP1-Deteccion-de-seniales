//
//  SignalProcessor.c
//  TP1 - Deteccion de seniales
//
//  Created by Gastón Montes on 4/27/15.
//  Copyright (c) 2015 Gastón Montes. All rights reserved.
//

#include <stdlib.h>
#include <string.h>

#include "SignalProcessor.h"
#include "Signal.h"

void signalProcessorPrint(SignalProcessor *processor,
                          int *process,
                          int process_length) {
    float gamma_value = argumentGamma(&processor->arguments);
    
    for (int i = 0; i < process_length; i++) {
        int value_to_print = -1;
        char *format_to_print = NULL;
        
        if (process[i] > gamma_value) {
            value_to_print = 1;
        } else {
            value_to_print = 0;
        }
        
        size_t format_length = 0;
        if (i == process_length - 1) {
            format_to_print = "%d\n";
            format_length = snprintf(NULL, 0, "%d\n", value_to_print) + 1;
        } else {
            format_to_print = "%d,";
            format_length = snprintf(NULL, 0, "%d,", value_to_print) + 1;
        }
        
        char *char_to_print = (char *)malloc(format_length * sizeof(char));
        snprintf(char_to_print, format_length, format_to_print, value_to_print);
        
        filePrint(processor->output_file, char_to_print);
        free(char_to_print);
    }
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
            int signal_element = signal_list[i * sub_length + j];
            int sub_element = sub_list[j];
            int product = signal_element * sub_element;
            acum += product;
        }
        process[i] = acum;
    }
}

void signalProcessorFunction(SignalProcessor *processor, Signal *signal) {
    Codification *one_codif = argumentOneCodification(&processor->arguments);
    Codification *zero_codif = argumentZeroCodification(&processor->arguments);
    Codification *subtraction = (Codification *)malloc(sizeof(Codification));
    int codif_length = codificationSignalLength(one_codif);
    codificationAbstractCreate(subtraction, codif_length);
    codificationSubtract(subtraction, one_codif, zero_codif);
    
    int signal_length = signalLength(signal);
    int sub_length = codificationSignalLength(subtraction);
    int process_length = signal_length / sub_length;
    int *process = malloc(process_length * sizeof(int));
    signalProcessorProduct(process, signal, subtraction);
    
    signalProcessorPrint(processor, process, process_length);
    
    codificationDestroy(subtraction);
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
        signalProcessorFunction(processor, signal);
        signalDestroy(signal);
        free(signal);
        signal = (Signal *)malloc(sizeof(Signal));
    }
    
    signalDestroy(signal);
    free(signal);
}
