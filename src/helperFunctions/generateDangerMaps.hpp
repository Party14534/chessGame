#ifndef DANGERMAP_HPP
#define DANGERMAP_HPP
#include "chessPiece.hpp"
#include <stdint.h>
#include <bitset>

inline int64_t whiteDangerMap = 0x0000000000000000LL;
inline int64_t blackDangerMap = 0x0000000000000000LL;

void generateWhiteDangerMap(std::vector<std::vector<char>> &board);
void generateBlackDangerMap(std::vector<std::vector<char>> &board);

#endif