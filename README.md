# Multi-FX board
This repository tracks the code of Multi-FX board. The aim of the project is to build a functional multi-fx board for guitar playing with several effects, presets, snapshots and nice GUI to connect it all together.
<!--You find the hardware design [here](https://github.com/artfulbytes/nsumo_hardware.git).-->

<!--<img src="/docs/nsumo.jpg">-->

## Directory structure
The directory structure is based on the [pitchfork layout] but it had to be adjusted due to STM32CubeMX generating its own directories. The whole structure was built so genereated files and personal files are as separate as possible with minimum modification of generated files.

| Directory     | Description                                                 |
|---------------|-------------------------------------------------------------|
| .devcontainer/| Development container configuration files                   |
| .github/      | Configuration file for GitHub actions                       |
| build/        | Build output (object files + executable)                    |
| docs/         | Documentation (e.g., coding guidelines, images, datasheets) |
| Core/         | STM32CubeMX generated main project folder (.c/.h)           |
| Drivers/      | STM32H7 HAL and CMSIS (.c/.h)                               |
| external/     | External dependencies (as git submodules if possible)       |
| src/          | Source files (.c/.h)                                        |
| src/app/      | Source files for the application layer (see SW architecture)|
| src/common/   | Source files for code used across the project               |
| src/drivers/  | Source files for the driver layer (see SW architecture)     |
| src/test/     | Source files related to test code                           |
| tools/        | Scripts, configs, binaries                                  |

## Build
Make is used as a build system for this project. STM32CubeMX is used to create a boilerplate _Makefile_ which is then heavily edited to include commands like:
- make all (project building)
- make flash (flashing to microcontroller)
- make clean (clean the build directory)
- make format (reformat .c/.h files according to our rules)
- make cppcheck (static analysis)

When re-generating code using STM32CubeMX, it's best to check if any of our Makefile edits were overwritten and use Git to track its changes if anything breaks.

Cross-toolchain used for this project is available on [GitLab in ARM toolchain directory](https://gitlab.arm.com/tooling/gnu-toolchains-for-arm/-/tree/releases/15.3.rel1).

There is a _Makefile_ to build the code with _make_ from the command-line using:
``` Bash
make
```

## Code editor
For this project any favourite code editor can be used. Recommended one is Visual Studio Code with these extensions:
- [C/C++ Themes](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools-themes)
- [Dev Containers](https://marketplace.visualstudio.com/items?itemName=ms-vscode-remote.remote-containers)
- [vscode-pdf](https://marketplace.visualstudio.com/items?itemName=tomoki1207.pdf)
- [Draw\.io integration](https://marketplace.visualstudio.com/items?itemName=hediet.vscode-drawio)

STM32CubeIDE should rather be avoided due to not being flexible and complex usage with Git.

## Tests
There are no unit tests, but there are test functions inside src/test/test.c, which are written to test isolated parts of the code. They run on target but are not built as part of the normal build. Only one test function can be built at a time, and it's
built as follows (test_assert as an example):

``` C
make TARGET=LAUNCHPAD TEST=test_assert
```

## Pushing a new change
These are the typical steps taken for each change.

1. Create a local branch
2. Make the code changes
3. Build the code
4. Flash and test the code on the target
5. Static analyse the code
6. Format the code
7. Commit the code
8. Push the branch to GitHub
9. Open a pull-request
10. Merge the pull request (must pass CI first)

This workflow is described further in [this video](https://www.youtube.com/watch?v=dh1NFAIoZCI).

## Commit message
Commit messages should follow the specification laid out by
[Conventional Commits](https://www.conventionalcommits.org/en/v1.0.0/). Since this is project was built as a learning platform for me I tried my best but didn't completely adhere to it especially not at beginning due to not taking special attention to it because I rather focused on other more important things.

## Continuous Integration (CI)
There is simple continuous integration (CI) system in place to have some form of protection against breaking code changes. This system is realized through GitHub actions and is configured in **cicd.yml** located under **.github/workflows**. The action builds and analyses (cppcheck) each commit pushed to GitHub and blocks them from being merged until they pass. The action runs inside a docker container, which has the required cross-toolchain installed. The dockerfile is located under **tools/**, and the docker image is available in a [repository at Docker Hub](https://hub.docker.com/repository/docker/nikskarabot/multi_fx_board-dev_env/general).

Note, the CI system provides weak protection against breaking code changes since it only builds and
static analyses the code. It's mainly there to demonstrate the principle. A more rigorous CI system
(professional environment) would unit-test the code and test it on the real target.

## Code formatter
The codebase follows certain formatting rules, which are enforced by the code formatter **clang-format**. These rules are specified in the **.clang-format** located in the root directory. There is a rule in the **Makefile** to format all source files with one command.

``` Bash
make format
```

Sometimes it's desirable to ignore these formatting rules, and this can be achieved with special comments.

``` C
// clang-format off
typedef enum {
    IO_10, IO_11, IO_12, IO_13, IO_14, IO_15, IO_16, IO_17,
    IO_20, IO_21, IO_22, IO_23, IO_24, IO_25, IO_26, IO_27,
    IO_30, IO_31, IO_32, IO_33, IO_34, IO_35, IO_36, IO_37,
} io_generic_e;
// clang-format on
```

## Coding guidelines
Apart from the basic formatting rules, the codebase also follows certain coding guidelines.
These are described in **docs/coding_guidelines.md**.

## Static analysis
To catch coding mistakes early on (in addition to the ones the compiler catches), I use a static
analyzer, **cppcheck**. There is a rule in the **Makefile** to analyse all files with **cppcheck**.

``` Bash
make cppcheck
```

## Memory footprint analysis
<!--The memory footprint on a microcontroller is very limited. The MSP430G2553 only has
16 KB (16 000 bytes) of read-only memory (ROM) or flash memory. This means one has to
be conscious of how much space each code snippet takes, which is one of the challenges
with microcontroller programming. For this reason, it's useful to have tools in place
to analyse the space occupied. There are two such programs available in the toolchain
(_readelf_ and _objdump_), and two corresponding rules in the _Makefile_.

One rule to see how much total space is occupied,
```
make size
```
and another rule to see how much space is occupied by individual symbols (functions + variables):
```
make symbols
```
which is useful to track down the worst offenders.-->

<!--
## Assert
Several things happen when an assert occurs to make it easy to detect and localize.
First it triggers a breakpoint (if a debugger is attached), then it traces the address
of the assert, and finally it endlessly blinks an LED. The address printed, is the
program counter, and _addr2line can be used to retrieve the file and line number,
and there is a makefile rule for it. For example, if an assert triggered at address
0x1234, you can run

```
make HW=LAUNCHPAD addr2line ADDR=0x1234
```
-->

## Diagrams
Diagrams were created using DrawIO.

## Schematic
Schematic is available as [pdf](docs/MultiFX_board.pdf) in the _docs/_ directory.

<!--
## Software architecture
<img src="/docs/sw_arch.png">

## Block diagram
<img src="/docs/sysdiag.jpg">

## State machine
<img src="/docs/state_machine.png">
<img src="/docs/retreat_state.png">
-->

## Memorable mentions
As part of this project I would like to mention a few important YouTube channels and resources used to build this project.
First is [Artful Bytes NSumo project](https://github.com/artfulbytes/nsumo_video/tree/main) and its embedded programming series on Youtube. This project workflow and general design is heavily inspired by this project. I used it as a reference to my design and tried to improve on it.
Second resource is [Phil's Lab YouTube channel](https://www.youtube.com/@PhilsLab) which proved to be super useful resource for configuring my audio section with STM32.