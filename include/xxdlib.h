
#ifndef XXD_XXDLIB_H

#define XXD_XXDLIB_H

#define DEFAULT_BUFFER_SIZE 16

#include <stdlib.h>
#include <stdio.h>

typedef enum {
    INPUT='i',
    OUTPUT = 'o',
} arg_t;

typedef struct {
    void *input_stream;
    void *output_stream;
    size_t buffer_size;
} config_t;

config_t* parse_args(int argc, char **argv);
void hexdump(config_t *config);

#endif