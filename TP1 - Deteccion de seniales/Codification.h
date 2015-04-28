//
//  Codification.h
//  TP1 - Deteccion de seniales
//
//  Created by Gastón Montes on 4/23/15.
//  Copyright (c) 2015 Gastón Montes. All rights reserved.
//

#ifndef __TP1___Deteccion_de_seniales__Codification__
#define __TP1___Deteccion_de_seniales__Codification__

#include <stdio.h>

#include "File.h"

typedef struct {
    int length;
    int *signal_codif_list;
} Codification;

/**
 * Create a new codification data.
 * @param - file: The file that contains the input file.
 * @param - length: The length of the codification.
 **/
void codificationCreate(Codification *codification, File *file, int length);

/**
 * Detroy the Codification data.
 **/
void codificationDestroy(Codification *codification);

/**
 * Returns the signal codification list.
 */
int *codificationSignalList(Codification *codification);

/**
 * Returns the multiplication between one_codif * other_codif(t).
 **/
int codificationProduct(Codification *one_codif, Codification *other_codif);

#endif /* defined(__TP1___Deteccion_de_seniales__Codification__) */
