#include <args/CmdArgs.h>
#include <cstdio>
#include <format.h>
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

bool checkPath(fs::path const& inputPath, fs::path const& outputPath) {
    if (!fs::exists(inputPath)) {
        std::cerr << "Input path does not exist" << std::endl;
        return false;
    }

    if (!fs::exists(outputPath)) {
        fs::create_directory(outputPath);
    }

    if (!fs::is_directory(inputPath) || !fs::is_directory(outputPath)) {
        std::cerr << "Input or output path is not a directory" << std::endl;
        return false;
    }

    if (!fs::is_empty(outputPath)) {
        std::cout << "Output directory is not empty, files will be overwritten [Y/n]: ";
        std::string input;
        std::getline(std::cin, input, '\n');
        if (input == "n" || input == "N") {
            exit(0);
        }
        fs::remove_all(outputPath);
    }

    return true;
}

// def check_custom_data_dir(output_arg) -> str:
//     if os.path.basename(output_arg) != "testdata":
//         output_arg = os.path.join(output_arg, "testdata")
//         logger.warning(f"Output directory should be named as testdata. The data will convert to {output_arg}.")
//     return output_arg

fs::path checkCustomDataDir(fs::path const& outputPath) {
    if (outputPath.filename() != "testdata") {
        auto newOutputPath = outputPath / "testdata";
        std::cerr << "Output directory should be named as testdata. The data will convert to "
                  << newOutputPath.string() << std::endl;
        return newOutputPath;
    }
    return outputPath;
}

int main(int argc, char** argv) {
    auto const& [inputPath, outputPath] = parseCmdArgs(argc, argv);

    if (!checkPath(inputPath, outputPath))
        return 1;

    std::cout << "Start to convert the data\nInput directory: \""
              << fs::absolute(inputPath).string()
              << "\"\nOutput directory: " << fs::absolute(outputPath).string() << "\"\n";

    if (isCustomData(inputPath)) {
    } else if (isHydroExport(inputPath)) {
    } else {
        std::cerr << "Input path is not a custom data directory or a hydro export directory"
                  << std::endl;
        return 1;
    }

    return 0;
}
