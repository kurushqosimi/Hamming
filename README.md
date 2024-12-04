# Hamming and EvenBit Encoding/Decoding

This project implements two error correction algorithms: **Hamming 8/4** and **EvenBit**. It provides functionalities for encoding and decoding data, simulating transmission errors, and correcting them using the selected algorithms.

## Table of Contents
1. [Installation](#installation)
2. [Usage](#usage)
3. [Code Explanation](#code-explanation)

## Installation

To build and run this project, follow these steps:

### Prerequisites

1. **CMake** - The project uses CMake for the build system. You will need at least CMake 3.28.
2. **C++ Compiler** - The project is written in C++17, so you'll need a compatible compiler like `g++` or `clang++`.
3. **Git** - If you plan to clone the repository.

### Steps

1. **Clone the repository:**

   If you haven't already cloned the repository, you can do so with the following command:

   ```bash
   git clone https://github.com/kurushqosimi/Hamming.git
   cd Hamming 
   ```

2. **Build the project:**

   Create a build directory and use CMake to configure the project:

    ```bash
   mkdir build
    cd build
    cmake ..
    make
   ```
   
3. **Run the executable:**
    
    After building the project, you can run the program using the following command:
    
    ```bash
    ./Hamming
    ```

## Usage

When you run the program, you will interact with a simple text-based interface for encoding and decoding data. Below are the key features:

1. **Default Data:** You can start with some predefined data, which consists of a few 4-bit numbers.
2. **Data Entry:** You can add custom data to be encoded.
3. **Encoding Algorithms:** You will be asked to select an encoding algorithm:
 - **EvenBit Algorithm:** Adds a parity bit to each byte to ensure even parity.
 - **Hamming 8/4:** Adds error-correcting bits to the data using the Hamming code.
4. **Error Simulation:** After encoding, you can simulate transmission errors by flipping bits in the encoded data.
5. **Decoding Algorithms:** After errors (if any), you will choose a decoding algorithm to recover the original data.
6. **Interactive Flow:** You can continue encoding, decoding, adding errors, and adding more data until you decide to exit.

## Code Explanation

```main.cpp```

This file contains the main logic for:

- Taking user input for data encoding and decoding.
- Calling encoding and decoding functions.
- Simulating errors and correcting them based on the selected algorithm.

```hamming.cpp```

This file contains the **Hamming 8/4** encoding and decoding functions:

- ```Encode8_4```: Encodes data using the Hamming 8/4 algorithm.
- ```Decode8_4```: Decodes Hamming-encoded data, correcting single-bit errors if any.

```evenbit.cpp```

This file contains the EvenBit encoding and decoding functions:

- ```EncodeEvenBit```: Encodes data by adding a parity bit to ensure even parity.
- ```DecodeEvenBit```: Decodes data and checks for parity errors.


```CMakeLists.txt```
This file is used to configure the build process:

- It defines how to compile the project and link the necessary libraries.

