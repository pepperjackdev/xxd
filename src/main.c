#include <stdio.h>
#include <xxdlib.h>

int main(int argc, char **argv) {
    config_t *config = parse_args(argc, argv);
    hexdump(config);
    free(config);
}