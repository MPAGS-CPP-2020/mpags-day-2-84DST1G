#ifndef MPAGSCIPHER_PROCESSCOMMANDLINE_HPP
#define MPAGSCIPHER_PROCESSCOMMANDLINE_HPP

#include <iostream>
#include <string>
#include <vector>

// For std::isalpha and std::isupper
#include <cctype>

int processCommandLine(const std::vector<std::string>& cmdLineArgs, bool& helpRequested, bool& versionRequested, std::string& inputFile, std::string& outputFile, int& cipherKey, bool& encrypt);

#endif //MPAGSCIPHER_PROCESSCOMMANDLINE_HPP