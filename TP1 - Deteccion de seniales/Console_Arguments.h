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
    const char *in_file;
    const char *out_file;
} ConsoleArguments;

/**
 * Create console arguments data parser.
 * @param - arguments_parser: The console arguments parser.
 * @param - arguments_count: The number of arguments.
 * @param - arguments[]: The list of arguments.
 **/
void consoleArgumentsCreate(ConsoleArguments *console_arguments,
                            int arguments_count,
                            const char *arguments[]);

#endif /* defined(__TP1___Deteccion_de_seniales__Console_Arguments__) */
