#include "processCommandLine.hpp"

int processCommandLine(const std::vector<std::string>& cmdLineArgs, bool& helpRequested, bool& versionRequested, std::string& inputFile, std::string& outputFile, int& cipherKey, bool& encrypt)
{
  typedef std::vector<std::string>::size_type size_type;
  const size_type nCmdLineArgs {cmdLineArgs.size()};

  // Process command line arguments - ignore zeroth element, as we know this to
  // be the program name and don't need to worry about it
  for (size_type i {1}; i < nCmdLineArgs; ++i) {

    if (cmdLineArgs[i] == "-h" || cmdLineArgs[i] == "--help") {
      helpRequested = true;
    }
    else if (cmdLineArgs[i] == "--version") {
      versionRequested = true;
    }
    else if (cmdLineArgs[i] == "-i") {
      // Handle input file option
      // Next element is filename unless -i is the last argument
      if (i == nCmdLineArgs-1) {
	std::cerr << "[error] -i requires a filename argument" << std::endl;
	// exit main with non-zero return to indicate failure
	return 1;
      }
      else {
	// Got filename, so assign value and advance past it
	inputFile = cmdLineArgs[i+1];
	++i;
      }
    }
    else if (cmdLineArgs[i] == "-o") {
      // Handle output file option
      // Next element is filename unless -o is the last argument
      if (i == nCmdLineArgs-1) {
	std::cerr << "[error] -o requires a filename argument" << std::endl;
	// exit main with non-zero return to indicate failure
	return 1;
      }
      else {
	// Got filename, so assign value and advance past it
	outputFile = cmdLineArgs[i+1];
	++i;
      }
    }
    else if (cmdLineArgs[i] == "-k")
    {
        cipherKey = std::stoi(cmdLineArgs[i+1]);
        ++i;
    }
    else if (cmdLineArgs[i] == "-e")
    {
        if (cmdLineArgs[i+1] == "y")
        {
            encrypt = true;
        }
        else if (cmdLineArgs[i+1] == "n")
        {
            encrypt = false;
        }
        else
        {
            //error
            std::cerr << "for -e please provide y/n'" << "'\n";
            return 1;
        }                
        ++i;
    }
    else {
      // Have an unknown flag to output error message and return non-zero
      // exit status to indicate failure
      std::cerr << "[error] unknown argument '" << cmdLineArgs[i] << "'\n";
      return 1;
    }
  }

  return 0;
}
