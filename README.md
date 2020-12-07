# BehTavan

A very simple, yet easily-hackable program to show how generally we can optimize things, and specifically in this project, power functions.

**Note:** The sole purpose of this program was comparing relative performance of different algorithms, and the output of the power functions are only to assert they produce the same output. As a result, we have not used any library providing big numbers (e.g. GMP), so the results of the functions are wrong for big inputs.

## Features

### Hackable, Easily

Add your own power function with your custom implementation. Let the program know about that. Recompile. Now you see it in the results. Yes, as easy as that: You don't need to touch anywhere else!

Maybe want to test other functions? That should require more hacking, but should be easy too.

Want to know more? See [HACKING.md](./docs/HACKING.md).

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

Although this is not a big project, but a minimal documentation is available. It lives in `docs` directory, [check it out now](./docs/README.md).

### Analysis

Data itself is not useful at all. What makes it useful is analyzing it, isn't it? See [what we understand from the output of the program](./docs/analysis/README.md).

## License

Licensed under GPLv3. See [LICENSE.md](./LICENSE.md).

## Miscellaneous

### Project Name?

Yes. It consists of two words in Persian: "Beh", which means the best, and "Tavan", which means exponentiation.

### Why at all?

The result of a practice of my university. Data structures course. That's all of it.
