//
//  Signal.c
//  TP1 - Deteccion de seniales
//
//  Created by Gastón Montes on 4/27/15.
//  Copyright (c) 2015 Gastón Montes. All rights reserved.
//

#include <stdlib.h>
#include <string.h>

#include "Signal.h"

#define SIGNAL_SEPARATOR ","

void signalSetLength(Signal *signal, const char *line) {
    // Copy the line.
    char *signal_line = (char *)malloc(strlen(line)*sizeof(char));
    strcpy(signal_line, line);
    
    int length_counter = 0;
    
    char *signal_element = strsep(&signal_line, SIGNAL_SEPARATOR);
    while (signal_element != NULL) {
        length_counter++;
        signal_element = strsep(&signal_line, SIGNAL_SEPARATOR);
    }

    signal->signal_length = length_counter;
    
    free(signal_line);
}

void signalParseSignal(Signal *signal, const char *line) {
    // Copy the line.
    char *signal_line = (char *)malloc(strlen(line)*sizeof(char));
    strcpy(signal_line, line);

    signal->signal_list = (int *)malloc(signal->signal_length * sizeof(int));
    
    int signal_length = signal->signal_length;
    for (int i = 0; i < signal_length; i++) {
        char *signal_element;
        signal_element = strsep(&signal_line, SIGNAL_SEPARATOR);
        signal->signal_list[i] = atoi(signal_element);
    }
    
    free(signal_line);
}

SignalCreateCode signalCreate(Signal *signal, File *file) {
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
