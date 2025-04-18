#include "utils.h"

void utils::printBitboard(U64 x) {
  for (int i = 7; i >= 0; i--) {
    for (int j = 0; j < 8; j++) {
      if (x & C64(1) << (i * 8 + j)) {
        std::cout << "1 ";
      } else {
        std::cout << "0 ";
      }
    }
    std::cout << '\n';
  }
  std::cout << '\n';
}