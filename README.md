# BehTavan

A simple, yet easily-hackable benchmarking library.

## Features

### Hackable, Easily

See [HACKING.md](./docs/HACKING.md).

## Build

### Cloning

This project comes with all its dependencies, as Git modules. Clone the project by running:

```
git clone https://github.com/machitgarha/beh-tavan --recurse-submodules
```

### Compilation Process

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

**Docs:** [Environment Variables](./docs/environment-variables.md).

## Compatibility

You should be able to run this project just anywhere: Linux, OS X, Windows or BSD. For the compiling process, both of GCC and Clang should work.

### Tested Environments

-   OS: Linux, Fedora Workstation 33
    Compiler: GCC C++ Compiler (10.2.1)

## Documentation

[See here.](./docs/README.md).

## License

Licensed under GPLv3. See [LICENSE.md](./LICENSE.md).

## Miscellaneous

### History

Initially, at my university, in data structures course, there was a simple practice to print execution times of two differently-implemented power (i.e. exponentiation) functions for comparison purposes. Version 0.1.0 of BehTavan was born. This is the same reason why I named it BehTavan: A persian phrase meaning "the best power" (in the terms of exponentiation).

Moving on, there was another practice to benchmark some common sorting algorithms studied just before. However, the project was not completely inactive since its first release, I have improved it somehow, and it was close to version 0.2.0. So it was a good idea to use the same code.

Now, the word "power" (i.e. "Tavan") is the real power BehTavan gives to you. It is generalized for many use cases, that is not just limited to exponentiation functions or the like.
