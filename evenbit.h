#ifndef EVENBIT_H
#define EVENBIT_H

#include <vector>
#include <cstdint>


// Functions for encoding and decoding with the usage of even bit
std::vector<uint8_t> EncodeEvenBit(std::vector<uint8_t> &vec);

std::vector<uint8_t> DecodeEvenBit(std::vector<uint8_t> &vec);

#endif // EVENBIT_H
