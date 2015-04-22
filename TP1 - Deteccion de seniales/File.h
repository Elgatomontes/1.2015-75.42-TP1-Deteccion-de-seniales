//
//  File.h
//  TP1 - Deteccion de seniales
//
//  Created by Gastón Montes on 4/22/15.
//  Copyright (c) 2015 Gastón Montes. All rights reserved.
//

#ifndef __TP1___Deteccion_de_seniales__File__
#define __TP1___Deteccion_de_seniales__File__

#include <stdio.h>

typedef enum {
    FileOperationCodeSuccess,
    FileOperationCodeFail,
} FileOperationCode;

typedef enum {
    FileOpenModeRead,
    FileOpenMOdeWrite
} FileOpenMode;

typedef struct {
    FILE *file;
    FileOperationCode operation_code;
} File;

/**
 * Create the file.
 * @param - file: File to initialize.
 * @param - file_name: the name of the file to open/create.
 * @param - open_mode: Mode to open the file.
 */
void filesCreate(File *file, char *file_name, FileOpenMode open_mode);

#endif /* defined(__TP1___Deteccion_de_seniales__File__) */
