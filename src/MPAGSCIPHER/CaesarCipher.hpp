#ifndef MPAGSCIPHER_CAESARCIPHER_HPP
#define MPAGSCIPHER_CAESARCIPHER_HPP

#include <iostream>
#include <string>
#include <vector>

// For std::isalpha and std::isupper
#include <cctype>

std::string runCaesarWordSalad(std::string in, int key, bool encrypt);

#endif //MPAGSCIPHER_CAESARCIPHER_HPP