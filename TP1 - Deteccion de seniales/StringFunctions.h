//
//  StringFunctions.h
//  TP1 - Deteccion de seniales
//
//  Created by Gastón Montes on 4/28/15.
//  Copyright (c) 2015 Gastón Montes. All rights reserved.
//

#ifndef __TP1___Deteccion_de_seniales__StringFunctions__
#define __TP1___Deteccion_de_seniales__StringFunctions__

#include <stdio.h>

/**
 * Safe reimplementation of function strtok_r of <string.h>
 */
char *stringFunctionsDelimit(char *str, const char *delim, char **nextp);

#endif /* defined(__TP1___Deteccion_de_seniales__StringFunctions__) */
