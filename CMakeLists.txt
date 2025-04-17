cmake_minimum_required(VERSION 3.10)
project(DNAStegoToolkit)

set(CMAKE_CXX_STANDARD 17)

add_executable(dna-stego
    src/main.cpp
    src/encoder.cpp
    src/decoder.cpp
)

