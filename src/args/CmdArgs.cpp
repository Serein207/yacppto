#include "CmdArgs.h"
#include <Version.h>
#include <argparse/argparse.hpp>

CmdArgs parseCmdArgs(int argc, char** argv) {
    argparse::ArgumentParser program("yacppto", VERSION_FULL);
    program.add_argument("-i", "--input-path")
        .help("The input file(.zip) path")
        .default_value(std::string("."));
    program.add_argument("-o", "--output-path")
        .help("The output file(.tar) path")
        .default_value(std::string("./out"));

    try {
        program.parse_args(argc, argv);
    } catch (const std::runtime_error& err) {
        std::cerr << err.what() << std::endl;
        std::exit(1);
    }

    return {.inputPath = program.get<std::string>("--input-path"),
            .outputPath = program.get<std::string>("--output-path")};
}