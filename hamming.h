#ifndef HAMMING_H
#define HAMMING_H

#include <vector>
#include <cstdint>

// Functions for encoding and decoding with the usage of Hamming 8/4
std::vector<uint8_t> Encode8_4(std::vector<uint8_t> &vec);

std::vector<uint8_t> Decode8_4(std::vector<uint8_t> &vec);

#endif // HAMMING_H
