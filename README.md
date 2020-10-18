# BehTavan

A very simple, yet easily-hackable program to show how generally we can optimize things, and specifically in this project, power functions.

## Build

Just like many other C++ projects, you need a compiler, Make support and CMake tool. Then:

```
cmake -B build
make -C build
```

## Runtime

After compiling using the above steps, run it via:

```
./build/BehTavan
```

### Environment Variables

(Make sure you are using a POSIX-compatible shell)

-   `INTERACTIVE=0`: This leaves the program with default values, instead of getting them from the user. This should be useful if you want to run the program multiple times in a row. 

## Compatibility

You should be able to run this project just anywhere: Linux, OS X, Windows or BSD. For the compiling process, both of GCC and Clang should work.

### Tested Environments

-   OS: Linux, Fedora Workstation 32
    Compiler: GCC C++ Compiler

## License

Licensed under GPLv3. See [LICENSE.md](./LICENSE.md).

## Miscellaneous

### Project Name?

Yes. It consists of two words in Persian: "Beh", which means the best, and "Tavan", which means exponentiation.
