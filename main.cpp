#include <iostream>
#include <cstdint>
#include <vector>
#include <bitset>
#include "hamming.h"
#include "evenbit.h"


int main() {
    std::vector<uint8_t> data = {0b1101, 0b1010, 0b1111};
    std::vector<uint8_t> encodedData;
    bool start = true;
    int choice = 0;
    int number = 0;
    bool numberEnter = false;
    std::vector<uint8_t> decodedData;

    while (start) {
        if (!data.empty()) {
            std::cout << "We have some default data" << std::endl;
            for (int i = 0; i < data.size(); i++) {
                std::cout << "Element #" << i + 1 << ":" << std::bitset<4>(data[i] & 0x0F) << " (" << static_cast<int>(
                    data[i] & 0x0F) << ")" << std::endl;
            }
        }

        std::cout << "Would you like to proceed with these elements[1] or you want to add more elements[2]?" <<
                std::endl;
        std::cin >> choice;
        if (choice != 1) {
            numberEnter = true;
            std::cout << "To stop entering numbers enter 256!" << std::endl;
            while (numberEnter) {
                std::cout << "\tEnter the number: ";
                std::cin >> number;
                if (number != 256) {
                    data.push_back(number);
                } else {
                    numberEnter = false;
                }
            }
        }

        std::cout << "Which encoding algorithm to use? \n1. EvenBit Algorithm \n2. Hamming 8/4" << std::endl;
        std::cin >> choice;
        if (choice != 1)
            encodedData = Encode8_4(data);
        else
            encodedData = EncodeEvenBit(data);

        std::cout << "Encoded Data: ";

        for (uint8_t n: encodedData) {
            std::cout << std::bitset<8>(n) << " ";
        }
        std::cout << std::endl;
        std::cout << "Would you like to add any bytes[1] or proceed with these[2]?" << std::endl;
        std::cin >> choice;
        if (choice != 2) {
            numberEnter = true;
            std::cout << "To stop entering bytes enter 256. The number of bytes entered by you should be even!" <<
                    std::endl;
            while (numberEnter) {
                std::cout << "Enter the number: ";
                std::cin >> number;
                if (number != 256) {
                    encodedData.push_back(number);
                } else {
                    numberEnter = false;
                }
            }
        }

        std::cout << "Would you like to add some mistakes?(Yes - 1 / No - 2)" << std::endl;
        std::cin >> choice;
        if (choice == 1) {
            int byteIndex = 0;
            int bitIndex = 0;
            std::cout << "Enter the index of the byte you want to modify (0 to " << encodedData.size() - 1 << "): " <<
                    std::endl;
            std::cin >> byteIndex;
            if (byteIndex < 0 || byteIndex >= encodedData.size()) {
                std::cerr << "Invalid byte index!" << std::endl;
            } else {
                std::cout << "Enter the bit index you want to flip (0 to 7): " << std::endl;
                std::cin >> bitIndex;
                if (bitIndex < 0 || bitIndex > 7) {
                    std::cerr << "Invalid bit index!" << std::endl;
                } else {
                    encodedData[byteIndex] ^= (1 << bitIndex);
                    std::cout << "Bit " << bitIndex << " in byte " << byteIndex << " flipped!" << std::endl;
                }
            }

            std::cout << "Encoded Data: ";

            for (uint8_t n: encodedData) {
                std::cout << std::bitset<8>(n) << " ";
            }
        }
        std::cout<<std::endl;

        std::cout << "Which decoding algorithm to use? \n1. EvenBit Algorithm \n2. Hamming 8/4" << std::endl;
        std::cin >> choice;
        if (choice != 1)
            decodedData = Decode8_4(encodedData);
        else
            decodedData = DecodeEvenBit(encodedData);
        std::cout << "Decoded Data: ";
        for (uint8_t n: decodedData) {
            std::cout << std::bitset<8>(n) << " ";
        }
        std::cout << std::endl;
        std::cout << "Would you like to continue? (Yes - 1 / No - 2)" << std::endl;
        std::cin >> choice;
        if (choice == 2) {
            start = false;
        }
    }

    return 0;
}
