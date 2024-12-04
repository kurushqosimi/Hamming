#include <iostream>
#include <cstdint>
#include <vector>
#include <bitset>
#include "hamming.h"
#include "evenbit.h"


// std::vector<uint8_t> EncodeEvenBit(std::vector<uint8_t> &vec) {
//     std::vector<uint8_t> newVector;
//
//     for (int n: vec) {
//         uint8_t temp = n;
//         int ones = 0;
//
//         while (temp) {
//             ones += temp & 1;
//             temp >>= 1;
//         }
//
//         uint8_t parityBit = (ones % 2 == 0) ? 0 : 1;
//
//         newVector.push_back((n << 1) | parityBit);
//     }
//
//     return newVector;
// }
//
//
// std::vector<uint8_t> DecodeEvenBit(std::vector<uint8_t> &vec) {
//     std::vector<uint8_t> newVector;
//
//     for (int n: vec) {
//         uint8_t temp1 = n;
//         int ones = 0;
//
//         uint8_t parityBit = temp1 & 0x01;
//
//         uint8_t temp2 = temp1 >> 1;
//
//         temp1 = temp2;
//         while (temp1) {
//             ones += temp1 & 1;
//             temp1 >>= 1;
//         }
//
//         if (ones % 2 != parityBit) {
//             std::cout << "Parity error detected!" << std::endl;
//         }
//
//         newVector.push_back(temp2);
//     }
//
//     return newVector;
// }


// std::vector<uint8_t> Encode8_4(std::vector<uint8_t> &vec) {
//     std::vector<uint8_t> newVector;
//     for (int n: vec) {
//         int d1 = (n >> 7) & 0x01;
//         int d2 = (n >> 6) & 0x01;
//         int d3 = (n >> 5) & 0x01;
//         int d4 = (n >> 4) & 0x01;
//         int d5 = (n >> 3) & 0x01;
//         int d6 = (n >> 2) & 0x01;
//         int d7 = (n >> 1) & 0x01;
//         int d8 = n & 0x01;
//         int p1 = 1 ^ d1 ^ d3 ^ d4;
//         int p2 = 1 ^ d1 ^ d2 ^ d4;
//         int p3 = 1 ^ d1 ^ d2 ^ d3;
//         int p4 = 1 ^ p1 ^ d1 ^ p2 ^ d2 ^ p3 ^ d3 ^ d4;
//         uint8_t encoded1 = (p1 << 7) | (d1 << 6) | (p2 << 5) | (d2 << 4) |
//                            (p3 << 3) | (d3 << 2) | (p4 << 1) | d4;
//         newVector.push_back(encoded1);
//
//         int p5 = 1 ^ d5 ^ d7 ^ d8;
//         int p6 = 1 ^ d5 ^ d6 ^ d8;
//         int p7 = 1 ^ d5 ^ d6 ^ d7;
//         int p8 = 1 ^ p5 ^ d5 ^ p6 ^ d6 ^ p7 ^ d7 ^ d8;
//         uint8_t encoded2 = (p5 << 7) | (d5 << 6) | (p6 << 5) | (d6 << 4) |
//                            (p7 << 3) | (d7 << 2) | (p8 << 1) | d8;
//         newVector.push_back(encoded2);
//     }
//     return newVector;
// }
//
// std::uint16_t Decode8T4Helper(uint8_t n, int byteNum) {
//     bool p1 = ((n >> 7) & 0x01) != 0;
//     bool d1 = ((n >> 6) & 0x01) != 0;
//     bool p2 = ((n >> 5) & 0x01) != 0;
//     bool d2 = ((n >> 4) & 0x01) != 0;
//     bool p3 = ((n >> 3) & 0x01) != 0;
//     bool d3 = ((n >> 2) & 0x01) != 0;
//     bool p4 = ((n >> 1) & 0x01) != 0;
//     bool d4 = (n & 0x01) != 0;
//
//     bool A = p1 ^ d1 ^ d3 ^ d4 == 1;
//     bool B = p2 ^ d1 ^ d2 ^ d4 == 1;
//     bool C = p3 ^ d1 ^ d2 ^ d3 == 1;
//     bool D = p1 ^ p2 ^ p3 ^ p4 ^ d1 ^ d2 ^ d3 ^ d4 == 1;
//
//     std::cout<<"A: "<<A<<" B: "<<B<<" C: "<<C<<" D: "<<D<<std::endl;
//
//     if ((!A || !B || !C) && D)
//         return 256;
//
//     int temp = !A + !B * 2 + !C * 4 + !D * 8;
//
//     std::cout<<"TEMP: "<<temp<<std::endl;
//
//     if (temp > 0)
//         std::cout << "Strange... Searching for an error in byte #" << byteNum + 1<<std::endl;
//
//     switch (temp) {
//         case 15:
//             d1 ^= 1;
//             std::cout << " Correcting 7-th bit...";
//             break;
//         case 14:
//             d2 ^= 1;
//             std::cout << " Correcting 5-th bit...";
//             break;
//         case 13:
//             d3 ^= 1;
//             std::cout << " Correcting 3-rd bit...";
//             break;
//         case 11:
//             d4 ^= 1;
//             std::cout << " Correcting 1-st bit...";
//             break;
//     }
//
//     return (d1 << 3) | (d2 << 2) | (d3 << 1) | d4;
// }
//
// std::vector<uint8_t> Decode8_4(std::vector<uint8_t> &vec) {
//     std::vector<uint8_t> newVector;
//
//     if (vec.size() % 2 != 0) {
//         std::cerr << "Incorrect number of encoded bytes. Should have been even number" << std::endl;
//     }
//
//     for (int i = 0; i < vec.size(); i += 2) {
//         uint8_t encoded1 = vec[i];
//         uint8_t encoded2 = (i + 1 < vec.size()) ? vec[i + 1] : 0;
//
//         uint16_t res1 = Decode8T4Helper(encoded1, i);
//         uint16_t res2 = Decode8T4Helper(encoded2, i + 1);
//         if (res1 == 256 || res2 == 256) {
//             std::cerr << "Encountered double error. The decoding of " << i << " and " << i + 1 <<
//                     " failed! Skipping them..." << std::endl;
//         } else {
//             uint8_t decodedByte = (res1 << 4) | (res2 & 0x0F);
//             newVector.push_back(decodedByte);
//         }
//     }
//
//     return newVector;
// }


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
