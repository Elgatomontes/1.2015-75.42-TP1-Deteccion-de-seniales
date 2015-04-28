//
//  Codification.c
//  TP1 - Deteccion de seniales
//
//  Created by Gastón Montes on 4/23/15.
//  Copyright (c) 2015 Gastón Montes. All rights reserved.
//

#include <stdlib.h>
#include <string.h>

#include "StringFunctions.h"
#include "Codification.h"

#define SIGNAL_SEPARATOR ","

void codificationParse(Codification *codification, char *line, int length) {
    codification->signal_codif_list = (int *)malloc(length * sizeof(int));
    
    char *signal_element;
    char *save_str;
    signal_element = stringFunctionsStrtok_r(line, SIGNAL_SEPARATOR, &save_str);
    codification->signal_codif_list[0] = atoi(signal_element);
    
    for (int i = 1; i < length; i++) {
        signal_element = stringFunctionsStrtok_r(NULL,
                                                 SIGNAL_SEPARATOR,
                                                 &save_str);
        codification->signal_codif_list[i] = atoi(signal_element);
    }
}

void codificationCreate(Codification *codification, File *file, int length) {
    codification->length = length;
    
    char *line_buffer = (char *)malloc(sizeof(char) * length * 2);
    fileReadLine(file, line_buffer, LINE_MAX_LENGHT);
    
    codificationParse(codification, line_buffer, length);
    
    free(line_buffer);
}

void codificationAbstractCreate(Codification *codification, int length) {
    codification->length = length;
    codification->signal_codif_list = (int *)malloc(length * sizeof(int));
}

void codificationDestroy(Codification *codification) {
    codification->length = 0;
    free(codification->signal_codif_list);
}

int *codificationSignalList(Codification *codification) {
    return codification->signal_codif_list;
}

int codificationSignalLength(Codification *codification) {
    return codification->length;
}

int codificationProduct(Codification *one_codif, Codification *other_codif) {
    int acum = 0;
    for (int i = 0; i < one_codif->length; i++) {
        int one_codif_element = one_codif->signal_codif_list[i];
        int other_codif_element = other_codif->signal_codif_list[i];
        
        acum += one_codif_element * other_codif_element;
    }
    
    return acum;
}

void codificationSubtract(Codification *subtraction,
                          Codification *one_codif,
                          Codification *other_codif) {
    int signal_length = codificationSignalLength(one_codif);
    for (int i = 0; i < signal_length; i++) {
        int one_element = one_codif->signal_codif_list[i];
        int other_element = other_codif->signal_codif_list[i];
        codificationSignalList(subtraction)[i] = one_element - other_element;
        subtraction->length = one_codif->length;
    }
}
