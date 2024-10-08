#include "type/Config.h"
#include <filesystem>
#include <format.h>
#include <iostream>

bool isCustomData(fs::path const& inputPath) {
    bool findOutput = false;
    for (auto const& f : fs::directory_iterator(inputPath)) {
        if (fs::is_directory(f)) {
            std::cerr << "\"" << fs::absolute(f.path()).string() << "\" is a directory, but \""
                      << fs::absolute(inputPath).string() << "\" is not a custom data directory\n";
            return false;
        } else if (f.path().extension() == ".out" || f.path().extension() == ".ans") {
            findOutput = true;
        }
    }
    if (!findOutput) {
        std::cerr << "No output file is found in \"" << fs::absolute(inputPath).string() << "\"\n";
        return false;
    }
    return false;
}

bool isHydroExport(fs::path const& inputPath) {
    std::cout << "Check \"" << fs::absolute(inputPath).string() << "\" is a hydro export directory"
              << std::endl;

    for (auto const& f : fs::directory_iterator(inputPath)) {
        if (fs::is_directory(f) && fs::exists(f.path() / "testdata")
            && isCustomData(f.path() / "testdata")) {
            std::cout << "find \"" << f.path().string() << "\" is a problem data file\n";
            return true;
        }
    }

    std::cout << "Can not find problem file, \"" << fs::absolute(inputPath).string()
              << "\" is not a hydro export directory" << std::endl;

    return false;
}

std::vector<fs::path> getHydroExportProblems(fs::path const& inputPath) {
    std::vector<fs::path> problems;
    for (auto const& f : fs::directory_iterator(inputPath)) {
        if (fs::is_directory(f) && fs::exists(f.path() / "testdata")
            && isCustomData(f.path() / "testdata")) {
            problems.push_back(f);
        }
    }
    return problems;
}

void convertCustomDir(fs::path const& inputPath, fs::path const& outputPath) {
    std::cout << "Custom data format is detected, try to find config.yaml or generate config\n";

    // auto config = loadDataDir(inputPath);
    // if (!config) {
    //     std::cerr << "Failed to load config.yaml and generate config, exit." << std::endl;
    //     exit(1);
    // } // config->save(outputPath);

    // std::cout << "Config file is saved, start to convert the data." << std::endl;

    // convert_data_dir(*config, inputPath, outputPath);

    std::cout << "Data is converted." << std::endl;
}

std::optional<Config> loadDataDir(fs::path const& inputPath) {
    auto configFilePath = inputPath / "config.yaml";
    if (!fs::exists(configFilePath) || !fs::is_regular_file(configFilePath)) {
        return std::nullopt;
    }
    //auto config = loadConfigFile(configFilePath);
}
