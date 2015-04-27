//
//  Codification.c
//  TP1 - Deteccion de seniales
//
//  Created by Gastón Montes on 4/23/15.
//  Copyright (c) 2015 Gastón Montes. All rights reserved.
//

#include <stdlib.h>
#include <string.h>

#include "Codification.h"

#define SIGNAL_SEPARATOR ","

void parseSignal(Codification *codification, char *line, int length) {
    codification->signal_codif_list = (int *)malloc(length * sizeof(int));
    
    char *signal_element;
    for (int i = 0; i < length; i++) {
        signal_element = strsep(&line, SIGNAL_SEPARATOR);
        codification->signal_codif_list[i] = atoi(signal_element);
    }
    
    for (int i = 0; i < length; i++) {
        printf("Elemento %i de la señal de codificación es: %i\n", i, codification->signal_codif_list[i]);
    }
}

void codificationCreate(Codification *codification, File *file, int length) {
    codification->length = length;
    
    char *line_buffer = (char *)malloc(sizeof(char) * length * 2);
    fileReadLine(file, line_buffer, LINE_MAX_LENGHT);
    
    parseSignal(codification, line_buffer, length);
    
    free(line_buffer);
}

void codificationDestroy(Codification *codification) {
    codification->length = 0;
    free(codification->signal_codif_list);
}
