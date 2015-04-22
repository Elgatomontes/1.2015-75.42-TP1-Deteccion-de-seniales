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
    } else if (open_mode == FileOpenMOdeWrite) {
        return FILE_OPEN_MODE_WRITE;
    }
    
    return "";
}

void filesCreate(File *file, char *file_name, FileOpenMode open_mode) {
    file->file = NULL;
    
    if (strlen(file_name) > 0) {
        file->file = fopen(file_name, openMode(open_mode));
        
        // file can not be NULL.
        if (file->file == NULL) {
            file->operation_code = FileOperationCodeFail;
        } else {
            file->operation_code = FileOperationCodeSuccess;
        }
    } else {
        file->operation_code = FileOperationCodeFail;
    }
}
