//
//  Console_Arguments.c
//  TP1 - Deteccion de seniales
//
//  Created by Gastón Montes on 4/21/15.
//  Copyright (c) 2015 Gastón Montes. All rights reserved.
//

#include <string.h>

#include "Console_Arguments.h"

#define IN_FILE_PARAMETER_KEY "-i"
#define OUT_FILE_PARAMETER_KEY "-o"
#define FIRST_PARAMETER_KEY_INDEX 1
#define FIRST_PARAMETER_INDEX 2
#define SECOND_PARAMETER_KEY_INDEX 3
#define SECOND_PARAMETER_INDEX 4

void setInvalidConfiguration(ConsoleArguments *console_arguments)
{
    console_arguments->arguments_code = ConsoleArgumentsCodeFail;
    console_arguments->in_file = NULL;
    console_arguments->out_file = NULL;
}

void parseArgument(ConsoleArguments *console_arguments,
                   const char *argument,
                   const char *argument_type)
{
    if (strcmp(argument_type, IN_FILE_PARAMETER_KEY) == 0) {
        console_arguments->in_file = argument;
    } else if (strcmp(argument_type, OUT_FILE_PARAMETER_KEY) == 0) {
        console_arguments->out_file = argument;
    } else {
        setInvalidConfiguration(console_arguments);
    }
}

void consoleArgumentsCreate(ConsoleArguments *console_arguments,
                            int arguments_count,
                            const char *arguments[])
{
    switch (arguments_count) {
        case 3:
            parseArgument(console_arguments,
                          arguments[FIRST_PARAMETER_INDEX],
                          arguments[FIRST_PARAMETER_KEY_INDEX]);
            break;
        case 5:
            parseArgument(console_arguments,
                          arguments[FIRST_PARAMETER_INDEX],
                          arguments[FIRST_PARAMETER_KEY_INDEX]);
            
            if (console_arguments->arguments_code != ConsoleArgumentsCodeFail) {
                parseArgument(console_arguments,
                              arguments[SECOND_PARAMETER_INDEX],
                              arguments[SECOND_PARAMETER_KEY_INDEX]);
            }
            break;
        default:
            setInvalidConfiguration(console_arguments);
            break;
    }
}
