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

#define LINE_MAX_LENGHT 255

typedef enum {
    FileOperationCodeSuccess,
    FileOperationCodeFail,
} FileOperationCode;

typedef enum {
    FileOpenModeRead,
    FileOpenModeWrite
} FileOpenMode;

typedef struct {
    FILE *file;
    FileOperationCode operation_code;
    int end_of_file;
} File;

/**
 * Create the file.
 * @param - file: File to initialize.
 * @param - file_name: the name of the file to open/create.
 * @param - open_mode: Mode to open the file.
 */
void fileCreate(File *file, char *file_name, FileOpenMode open_mode);

/**
 * Close the file.
 **/
void fileDestroy(File *file);

/**
 * Returns the operation code of the file opening.
 **/
FileOperationCode fileOperationCode(File *file);

/**
 * Returns the file openned.
 **/
FILE *fileOpenned(File *file);

/**
 * Read a line from file.
 * @param - line: The buffer to set the line read.
 * @param - max_lenght: The maxium number of characters for a line.
 **/
void fileReadLine(File *file, char *line, size_t max_lenght);

/**
 * Check the end of file of the file.
 **/
int fileEndOfFile(File *file);

#endif /* defined(__TP1___Deteccion_de_seniales__File__) */
