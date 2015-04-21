//
//  Console_Arguments.h
//  TP1 - Deteccion de seniales
//
//  Created by Gastón Montes on 4/21/15.
//  Copyright (c) 2015 Gastón Montes. All rights reserved.
//

#ifndef __TP1___Deteccion_de_seniales__Console_Arguments__
#define __TP1___Deteccion_de_seniales__Console_Arguments__

#include <stdio.h>

typedef enum {
    ConsoleArgumentsCodeOK,
    ConsoleArgumentsCodeFail
} ConsoleArgumentsCode;

typedef struct {
    ConsoleArgumentsCode arguments_code;
    char *in_file;
    char *out_file;
} ConsoleArguments;

void consoleArgumentsCreate(ConsoleArguments *arguments_parser,
                            int arguments_count,
                            const char *arguments[]);

#endif /* defined(__TP1___Deteccion_de_seniales__Console_Arguments__) */
