#pragma once

#include <filesystem>

struct CmdArgs {
    std::filesystem::path inputPath;
    std::filesystem::path outputPath;
};

CmdArgs parseCmdArgs(int argc, char** argv);