# translator

## Build

1. Clone this repository:

    ```shell
    git clone https://github.com/premo-inc/translator.git
    cd translator
    git submodule update --init --recursive --depth 1
    ```

2. Install required softwares:

    ```shell
    sudo apt install libboost-all-dev
    sudo apt install cmake
    ```

3. Build `loader`

    ```shell
    cd src/loader
    make
    ```

## Prerequisite

-   [Boost](https://www.boost.org/)
-   [CMake](https://cmake.org/)
