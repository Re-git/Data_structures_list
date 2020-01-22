#ifndef READFILE_H
#define READFILE_H
#include <stdlib.h>
#include <stdio.h>
#include "list.h"

int read_number(FILE * file, int * value);

int read_char(FILE * file, char * value);

void parse_file(const char* file, List* lista);

#endif // READFILE_H