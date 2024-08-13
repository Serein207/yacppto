#include <args/CmdArgs.h>
#include <filesystem>
#include <iostream>

/*
Usage: yarusto [--help] [--version] [--input-path VAR] [--output-path VAR]

Optional arguments:
  -h, --help         shows help message and exits 
  -v, --version      prints version information and exits 
  -i, --input-path   The input file(.zip) path [nargs=0..1] [default: "."]
  -o, --output-path  The output file(.tar) path [nargs=0..1] [default: "./out"]
*/

namespace fs = std::filesystem;

int main(int argc, char** argv) {
    auto [inputPath, outputPath] = parseCmdArgs(argc, argv);

    if (!fs::is_directory(inputPath) || !fs::is_directory(outputPath)) {
        std::cerr << "Input or output path is not a directory" << std::endl;
        return 1;
    }

    if (!fs::exists(inputPath)) {
        std::cerr << "Input path does not exist" << std::endl;
        return 1;
    }

    if (!fs::exists(outputPath)) {
        fs::create_directory(outputPath);
    }

    if (!fs::is_empty(outputPath)) {
        std::cout << "Output directory is not empty, files will be overwritten." << std::endl;
        fs::remove_all(outputPath);
    }

    return 0;
}
