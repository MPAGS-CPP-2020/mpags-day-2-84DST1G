// Standard Library includes
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

// For std::isalpha and std::isupper
#include <cctype>

#include "TransformChar.hpp"
#include "processCommandLine.hpp"
#include "CaesarCipher.hpp"

// Main function of the mpags-cipher program
int main(int argc, char* argv[])
{
  // Convert the command-line arguments into a more easily usable form
  const std::vector<std::string> cmdLineArgs {argv, argv+argc};

  // Add a typedef that assigns another name for the given type for clarity
  //typedef std::vector<std::string>::size_type size_type;
  

  // Options that might be set by the command-line arguments
  bool helpRequested {false};
  bool versionRequested {false};
  std::string inputFile {""};
  std::string outputFile {""};
  int cipherKey {0};
  bool encrypt {true};

  if (processCommandLine(cmdLineArgs, helpRequested, versionRequested, inputFile, outputFile, cipherKey, encrypt) != 0)
  {
    return 1;
  }

  

  // Handle help, if requested
  if (helpRequested) {
    // Line splitting for readability
    std::cout
      << "Usage: mpags-cipher [-i <file>] [-o <file>]\n\n"
      << "Encrypts/Decrypts input alphanumeric text using classical ciphers\n\n"
      << "Available options:\n\n"
      << "  -h|--help        Print this help message and exit\n\n"
      << "  --version        Print version information\n\n"
      << "  -i FILE          Read text to be processed from FILE\n"
      << "                   Stdin will be used if not supplied\n\n"
      << "  -o FILE          Write processed text to FILE\n"
      << "                   Stdout will be used if not supplied\n\n";
    // Help requires no further action, so return from main
    // with 0 used to indicate success
    return 0;
  }

  // Handle version, if requested
  // Like help, requires no further action,
  // so return from main with zero to indicate success
  if (versionRequested) {
    std::cout << "0.1.0" << std::endl;
    return 0;
  }

  // Initialise variables for processing input text
  char inputChar {'x'};
  std::string inputText {""};

  // Read in user input from stdin/file
  // Warn that input file option not yet implemented

  bool cmdIn {false};
  if (!inputFile.empty()) {
    std::ifstream in_file {inputFile};
    if (in_file.good())
    {
      while(in_file >> inputChar)
      {
        // Uppercase alphabetic characters
        inputText += translateChar(inputChar);

        // If the character isn't alphabetic or numeric, DONT add it.
        // Our ciphers can only operate on alphabetic characters.
      }
    }
    else
    {
      cmdIn = true;
    }
    

  }
  else
  {
    cmdIn = true;
  }


  if (cmdIn)
  {
    // Loop over each character from user input
    // (until Return then CTRL-D (EOF) pressed)
    while(std::cin >> inputChar)
    {
      // Uppercase alphabetic characters
      inputText += translateChar(inputChar);

      // If the character isn't alphabetic or numeric, DONT add it.
      // Our ciphers can only operate on alphabetic characters.
    }
  }

  std::string outputText {runCaesarWordSalad(inputText, cipherKey, encrypt)};

  // Output the transliterated text
  // Warn that output file option not yet implemented
  bool cmdOut {false};
  if (!outputFile.empty()) {
    std::ofstream out_file {inputFile};
    if (out_file.good())
    {
      out_file << outputText << std::endl;
    }
    else
    {
      cmdOut = true;
    }
  }
  else
  {
    cmdOut = true;
  }

  if (cmdOut)
  {
    //Output via cmd lime
    std::cout << outputText << std::endl;
  }


  // No requirement to return from main, but we do so for clarity
  // and for consistency with other functions
  return 0;
}
