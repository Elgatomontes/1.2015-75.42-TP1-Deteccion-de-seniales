//
//  File.c
//  TP1 - Deteccion de seniales
//
//  Created by Gastón Montes on 4/22/15.
//  Copyright (c) 2015 Gastón Montes. All rights reserved.
//

#include <string.h>

#include "File.h"

#define FILE_OPEN_MODE_READ "rb"
#define FILE_OPEN_MODE_WRITE "w"

char *openMode(FileOpenMode open_mode) {
    if (open_mode == FileOpenModeRead) {
        return FILE_OPEN_MODE_READ;
    } else if (open_mode == FileOpenModeWrite) {
        return FILE_OPEN_MODE_WRITE;
    }
    
    return "";
}

void setStandardFile(File *file, FileOpenMode open_mode) {
    if (open_mode == FileOpenModeRead) {
        file->file = stdin;
    } else if (open_mode == FileOpenModeWrite) {
        file->file = stdout;
    }
}

void fileCreate(File *file, char *file_name, FileOpenMode open_mode) {
    file->file = NULL;
    file->end_of_file = 0;
    
    if (file_name != NULL && strlen(file_name) > 0) {
        file->file = fopen(file_name, openMode(open_mode));
    } else {
        setStandardFile(file, open_mode);
    }
    
    // file can not be NULL.
    if (file->file == NULL) {
        file->operation_code = FileOperationCodeFail;
    } else {
        file->operation_code = FileOperationCodeSuccess;
    }
}

void fileDestroy(File *file) {
    file->end_of_file = EOF;
    if (file->file != NULL && file->file != stdin && file->file != stdout) {
        fclose(file->file);
    }
}

FileOperationCode fileOperationCode(File *file) {
    return file->operation_code;
}

void fileReadLine(File *file, char *line, int max_lenght) {
    if (fgets(line, max_lenght, file->file) == NULL) {
        file->end_of_file = EOF;
    }
}

int fileEndOfFile(File *file) {
    return file->end_of_file;
}

void filePrint(File *file, char *line) {
    if (file->file != stdin && file->file != stdout) {
        fprintf(file->file, "%s",line);
    } else {
        printf("%s", line);
    }
}
