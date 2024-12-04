#include "hamming.h"
#include <iostream>
#include <cstdint>

std::vector<uint8_t> Encode8_4(std::vector<uint8_t> &vec) {
    std::vector<uint8_t> newVector;
    for (int n: vec) {
        int d1 = (n >> 7) & 0x01;
        int d2 = (n >> 6) & 0x01;
        int d3 = (n >> 5) & 0x01;
        int d4 = (n >> 4) & 0x01;
        int d5 = (n >> 3) & 0x01;
        int d6 = (n >> 2) & 0x01;
        int d7 = (n >> 1) & 0x01;
        int d8 = n & 0x01;
        int p1 = 1 ^ d1 ^ d3 ^ d4;
        int p2 = 1 ^ d1 ^ d2 ^ d4;
        int p3 = 1 ^ d1 ^ d2 ^ d3;
        int p4 = 1 ^ p1 ^ d1 ^ p2 ^ d2 ^ p3 ^ d3 ^ d4;
        uint8_t encoded1 = (p1 << 7) | (d1 << 6) | (p2 << 5) | (d2 << 4) |
                           (p3 << 3) | (d3 << 2) | (p4 << 1) | d4;
        newVector.push_back(encoded1);

        int p5 = 1 ^ d5 ^ d7 ^ d8;
        int p6 = 1 ^ d5 ^ d6 ^ d8;
        int p7 = 1 ^ d5 ^ d6 ^ d7;
        int p8 = 1 ^ p5 ^ d5 ^ p6 ^ d6 ^ p7 ^ d7 ^ d8;
        uint8_t encoded2 = (p5 << 7) | (d5 << 6) | (p6 << 5) | (d6 << 4) |
                           (p7 << 3) | (d7 << 2) | (p8 << 1) | d8;
        newVector.push_back(encoded2);
    }
    return newVector;
}

std::uint16_t Decode8T4Helper(uint8_t n, int byteNum) {
    bool p1 = ((n >> 7) & 0x01) != 0;
    bool d1 = ((n >> 6) & 0x01) != 0;
    bool p2 = ((n >> 5) & 0x01) != 0;
    bool d2 = ((n >> 4) & 0x01) != 0;
    bool p3 = ((n >> 3) & 0x01) != 0;
    bool d3 = ((n >> 2) & 0x01) != 0;
    bool p4 = ((n >> 1) & 0x01) != 0;
    bool d4 = (n & 0x01) != 0;

    bool A = p1 ^ d1 ^ d3 ^ d4 == 1;
    bool B = p2 ^ d1 ^ d2 ^ d4 == 1;
    bool C = p3 ^ d1 ^ d2 ^ d3 == 1;
    bool D = p1 ^ p2 ^ p3 ^ p4 ^ d1 ^ d2 ^ d3 ^ d4 == 1;

    std::cout << "A: " << A << " B: " << B << " C: " << C << " D: " << D << std::endl;

    if ((!A || !B || !C) && D)
        return 256;

    int temp = !A + !B * 2 + !C * 4 + !D * 8;

    std::cout << "TEMP: " << temp << std::endl;

    if (temp > 0)
        std::cout << "Strange... Searching for an error in byte #" << byteNum + 1 << std::endl;

    switch (temp) {
        case 15:
            d1 ^= 1;
            std::cout << " Correcting 7-th bit...";
            break;
        case 14:
            d2 ^= 1;
            std::cout << " Correcting 5-th bit...";
            break;
        case 13:
            d3 ^= 1;
            std::cout << " Correcting 3-rd bit...";
            break;
        case 11:
            d4 ^= 1;
            std::cout << " Correcting 1-st bit...";
            break;
    }

    return (d1 << 3) | (d2 << 2) | (d3 << 1) | d4;
}

std::vector<uint8_t> Decode8_4(std::vector<uint8_t> &vec) {
    std::vector<uint8_t> newVector;

    if (vec.size() % 2 != 0) {
        std::cerr << "Incorrect number of encoded bytes. Should have been even number" << std::endl;
    }

    for (int i = 0; i < vec.size(); i += 2) {
        uint8_t encoded1 = vec[i];
        uint8_t encoded2 = (i + 1 < vec.size()) ? vec[i + 1] : 0;

        uint16_t res1 = Decode8T4Helper(encoded1, i);
        uint16_t res2 = Decode8T4Helper(encoded2, i + 1);
        if (res1 == 256 || res2 == 256) {
            std::cerr << "Encountered double error. The decoding of " << i << " and " << i + 1 <<
                    " failed! Skipping them..." << std::endl;
        } else {
            uint8_t decodedByte = (res1 << 4) | (res2 & 0x0F);
            newVector.push_back(decodedByte);
        }
    }

    return newVector;
}
