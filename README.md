# Hexdump, `xxd`
A simple C implementation of the Unix command line utility `xxd` written in C.

## Building

This project uses `CMake` as build script generator. To generate the build script of your favourite building system, just create a `build` directory under the root folder of the project and move inside it. Once in the `build` dir, just run

    cmake ..

This will generate by default a build script for `ninja`. You can alternatively specify an alternative build system with the `-G` arg followed by the identifier of your favourite building system.

You can now build the project using `ninja` by running

    ninja

The executable will by placed under `build/src` as `xxd`.

## Credits
Inspired from the original project of Juergen Weigert.
