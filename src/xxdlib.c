#include <xxdlib.h>
#include <stdio.h>
#include <stdlib.h>

config_t* default_config() {
    // memory allocation for config object
    config_t *config = malloc(sizeof(config_t));
    if (config == NULL) {
        return NULL;
    }

    config->input_stream = stdin;
    config->output_stream = stdout;
    config->buffer_size = DEFAULT_BUFFER_SIZE;

    return config;
}

// FIXME: weak argument parsing system
config_t* parse_args(int argc, char **argv) {
    config_t *config = default_config();

    for (int i = 1; i < argc; i++) {
        char *current = argv[i];
        if (current[0] == '-') {
            switch (current[1]) {
                case INPUT:
                    FILE *input = fopen(argv[i + 1], "rb");
                    config->input_stream = input;
                    break;
                case OUTPUT:
                    FILE *output = fopen(argv[i + 1], "wb");
                    config->output_stream = output;
                    break;
                default:
                    break;
            }
        }
    }

    return config;
}

void hexdump(config_t *config) {
    char *buffer = malloc(config->buffer_size);
    if (buffer == NULL) {
        perror("Fatal error: could not create buffer");
        return;
    }

    size_t bytes_read;
    for (long long index = 0; (bytes_read = fread(buffer, 1, config->buffer_size, config->input_stream)) > 0; index += bytes_read) {
        // Printing the index
        fprintf(config->output_stream, "%08llx: ", index);

        // Printing the binary content in hex
        for (size_t i = 0; i < bytes_read; i++) {
            fprintf(config->output_stream, "%02x", buffer[i]);
            if ((i + 1) % 2 == 0) fprintf(config->output_stream, " ");  // Add space every 2 bytes
        }

        // Pad with spaces if fewer than buffer_size bytes were read
        for (size_t i = bytes_read; i < config->buffer_size; i++) {
            fprintf(config->output_stream, "  ");
            if ((i + 1) % 2 == 0) fprintf(config->output_stream, " ");
        }

        // Printing the ASCII representation
        fprintf(config->output_stream, "  ");
        for (size_t i = 0; i < bytes_read; i++) {
            unsigned char current = buffer[i];
            if (current >= 32 && current <= 126) {
                fprintf(config->output_stream, "%c", current);
            } else {
                fprintf(config->output_stream, ".");
            }
        }

        // Newline
        fprintf(config->output_stream, "\n");
    }

    if (ferror(config->input_stream)) {
        perror("Error reading input stream");
    }

    // Free the allocated buffer
    free(buffer);
}
