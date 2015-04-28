//
//  Signal.h
//  TP1 - Deteccion de seniales
//
//  Created by Gastón Montes on 4/27/15.
//  Copyright (c) 2015 Gastón Montes. All rights reserved.
//

#ifndef __TP1___Deteccion_de_seniales__Signal__
#define __TP1___Deteccion_de_seniales__Signal__

#include <stdio.h>

#include "File.h"

typedef struct {
    int signal_length;
    int *signal_list;
} Signal;

/**
 * Create a new signal data.
 * @param - file: The file that contains the input file.
 **/
void signalCreate(Signal *signal, File *file);

/**
 * Detroy the Signal data.
 **/
void signalDestroy(Signal *signal);

#endif /* defined(__TP1___Deteccion_de_seniales__Signal__) */
