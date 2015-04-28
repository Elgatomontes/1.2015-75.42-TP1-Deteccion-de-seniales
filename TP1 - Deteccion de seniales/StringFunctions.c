//
//  StringFunctions.c
//  TP1 - Deteccion de seniales
//
//  Created by Gastón Montes on 4/28/15.
//  Copyright (c) 2015 Gastón Montes. All rights reserved.
//

#include <stdio.h>
#include <string.h>

#include "StringFunctions.h"

char *stringFunctionsStrtok_r(char *str, const char *delim, char **nextp) {
    char *ret;
    
    if (str == NULL) {
        str = *nextp;
    }
    
    str += strspn(str, delim);
    
    if (*str == '\0') {
        return NULL;
    }
    
    ret = str;
    
    str += strcspn(str, delim);
    
    if (*str) {
        *str++ = '\0';
    }
    
    *nextp = str;
    
    return ret;
}
