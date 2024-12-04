#include "evenbit.h"
#include <iostream>


std::vector<uint8_t> EncodeEvenBit(std::vector<uint8_t> &vec) {
    std::vector<uint8_t> newVector;

    for (int n: vec) {
        uint8_t temp = n;
        int ones = 0;

        while (temp) {
            ones += temp & 1;
            temp >>= 1;
        }

        uint8_t parityBit = (ones % 2 == 0) ? 0 : 1;

        newVector.push_back((n << 1) | parityBit);
    }

    return newVector;
}


std::vector<uint8_t> DecodeEvenBit(std::vector<uint8_t> &vec) {
    std::vector<uint8_t> newVector;

    for (int n: vec) {
        uint8_t temp1 = n;
        int ones = 0;

        uint8_t parityBit = temp1 & 0x01;

        uint8_t temp2 = temp1 >> 1;

        temp1 = temp2;
        while (temp1) {
            ones += temp1 & 1;
            temp1 >>= 1;
        }

        if (ones % 2 != parityBit) {
            std::cout << "Parity error detected!" << std::endl;
        }

        newVector.push_back(temp2);
    }

    return newVector;
}
