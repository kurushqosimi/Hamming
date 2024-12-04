
# Hamming and EvenBit Encoding/Decoding

This project implements two error correction algorithms: **Hamming 8/4** and **EvenBit**. It provides functionalities for encoding and decoding data, simulating transmission errors, and correcting them using the selected algorithms. 

## Table of Contents
1. [Installation](#installation)
2. [Usage](#usage)
3. [Code Explanation](#code-explanation)
4. [Contributing](#contributing)
5. [License](#license)

## Installation

To build and run this project, follow these steps:

### Prerequisites

Before you begin, ensure you have the following installed:

- **CMake** - Version 3.28 or higher.
- **C++ Compiler** - A compiler that supports C++17, such as `g++` or `clang++`.
- **Git** - For cloning the repository.

### Steps

1. **Clone the repository:**

   Clone the project to your local machine using the following command:

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

   After building the project, you can run the program:

   ```bash
   ./Hamming
   ```

## Usage

When you run the program, you'll interact with a simple text-based interface that allows you to encode, decode, and simulate transmission errors. Below are the key features and steps:

### Key Features

1. **Default Data:** The program provides predefined 4-bit numbers to start with.
2. **Custom Data Entry:** You can enter custom data to be encoded and decoded.
3. **Encoding Algorithms:** Choose from the following encoding methods:
   - **EvenBit Algorithm:** Adds a parity bit to each byte to ensure even parity.
   - **Hamming 8/4:** Uses Hamming code to add error-correcting bits to the data.
4. **Error Simulation:** After encoding, you can simulate transmission errors by flipping bits in the encoded data.
5. **Decoding Algorithms:** After introducing errors, select a decoding algorithm to recover the original data.
6. **Interactive Flow:** You can continue encoding, decoding, simulating errors, and adding more data until you decide to exit.

### Example Workflow

1. Choose **Hamming 8/4** or **EvenBit** encoding.
2. Enter some data to encode.
3. Optionally simulate transmission errors by flipping bits.
4. Decode the data using the corresponding decoding method to correct any errors.
5. Repeat the process as needed or exit.

## Code Explanation

### `main.cpp`

This file contains the main logic for:

- Taking user input for data encoding and decoding.
- Calling the appropriate encoding and decoding functions.
- Simulating errors and correcting them based on the selected algorithm.

### `hamming.cpp`

This file implements the **Hamming 8/4** encoding and decoding functions:

- **`Encode8_4`**: Encodes data using the Hamming 8/4 algorithm.
- **`Decode8_4`**: Decodes Hamming-encoded data, correcting single-bit errors if any.

### `evenbit.cpp`

This file implements the EvenBit encoding and decoding functions:

- **`EncodeEvenBit`**: Encodes data by adding a parity bit to ensure even parity.
- **`DecodeEvenBit`**: Decodes data and checks for parity errors.

### `CMakeLists.txt`

This file is used to configure the build process. It defines how to compile the project and link any necessary libraries.

## Contributing

We welcome contributions to improve this project! To contribute:

1. Fork the repository.
2. Create a new branch for your changes.
3. Commit your changes and push to your fork.
4. Open a pull request for review.

Please make sure to write clear commit messages and follow the project’s coding style.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.


### Improvements made:
1. **Clarity in Installation and Usage**: Steps are more clear and precise, making it easier for users to follow.
2. **Section Titles**: Added section for **Contributing** and **License**, which is standard for open-source projects.
3. **Workflow Example**: Provided a sample workflow for a clearer understanding of how the application works.
4. **Code Organization**: Added descriptions for code files with detailed explanations for each file's purpose.
5. **Text formatting**: Improved consistency in headings and list formatting.