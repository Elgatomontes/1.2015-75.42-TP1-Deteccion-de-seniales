//
//  Signal.c
//  TP1 - Deteccion de seniales
//
//  Created by Gastón Montes on 4/27/15.
//  Copyright (c) 2015 Gastón Montes. All rights reserved.
//

#include <stdlib.h>
#include <string.h>

#include "StringFunctions.h"
#include "Signal.h"

#define SIGNAL_SEPARATOR ","

void signalSetLength(Signal *signal, const char *line) {
    // Copy the line.
    char *signal_line = (char *)malloc(strlen(line)*sizeof(char));
    snprintf(signal_line, strlen(line)*sizeof(char), "%s",line);
    
    int length_counter = 0;
    
    char *save_str;
    char *signal_element = stringFunctionsStrtok_r(signal_line,
                                                   SIGNAL_SEPARATOR,
                                                   &save_str);
    while (signal_element != NULL) {
        length_counter++;
        signal_element = stringFunctionsStrtok_r(NULL,
                                                 SIGNAL_SEPARATOR,
                                                 &save_str);
    }
    
    signal->signal_length = length_counter;
    
    free(signal_line);
}

void signalParseSignal(Signal *signal, const char *line) {
    // Copy the line.
    char *signal_line = (char *)malloc(strlen(line)*sizeof(char));
    snprintf(signal_line, strlen(line)*sizeof(char), "%s",line);
    
    signal->signal_list = (int *)malloc(signal->signal_length * sizeof(int));
    
    int signal_length = signal->signal_length;
    char *save_str;
    char *signal_element = stringFunctionsStrtok_r(signal_line,
                                                   SIGNAL_SEPARATOR,
                                                   &save_str);
    signal->signal_list[0] = atoi(signal_element);
    for (int i = 1; i < signal_length; i++) {
        char *element = stringFunctionsStrtok_r(NULL,
                                                SIGNAL_SEPARATOR,
                                                &save_str);
        signal->signal_list[i] = atoi(element);
    }
    
    free(signal_line);
}

SignalCreateCode signalCreate(Signal *signal, File *file) {
    signal->signal_length = 0;
    signal->signal_list = NULL;
    
    char *line_buffer = (char *)malloc(sizeof(char) * LINE_MAX_LENGHT);
    fileReadLine(file, line_buffer, LINE_MAX_LENGHT);
    
    if (fileEndOfFile(file) == EOF) {
        free(line_buffer);
        return SignalCreateCodeFail;
    }
    
    signalSetLength(signal, line_buffer);
    signalParseSignal(signal, line_buffer);
    
    free(line_buffer);
    
    return SignalCreateCodeOK;
}

void signalDestroy(Signal *signal) {
    signal->signal_length = 0;
    free(signal->signal_list);
}

int signalLength(Signal *signal) {
    return signal->signal_length;
}

int *signalList(Signal *signal) {
    return signal->signal_list;
}
