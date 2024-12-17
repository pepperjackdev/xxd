#include <stdio.h>
#include <xxdlib.h>

int main(int argc, char **argv) {
    config_t *config = parse_args(argc, argv);
    if (config == NULL) {
        perror("Fatal error while parsing args");
        return EXIT_FAILURE;
    }
    hexdump(config);
    free(config);
}