#include "format.h"
#include <iostream>

bool isCustomData(fs::path const& inputPath) {
    bool findOutput = false;
    for (auto const& f : fs::directory_iterator(inputPath)) {
        if (fs::is_directory(f)) {
            std::cerr << f.path().string() << " is a directory, " << inputPath.string()
                      << " is not a custom data directory." << std::endl;
            return false;
        } else if (f.path().extension() == ".out" || f.path().extension() == ".ans") {
            findOutput = true;
        }
    }
    if (!findOutput) {
        std::cerr << "No output file is found in " << inputPath.string() << "." << std::endl;
        return false;
    }
    return false;
}

bool isHydroExport(fs::path const& inputPath) {
    std::cout << "Check " << inputPath.string() << " is a hydro export directory" << std::endl;

    for (auto const& f : fs::directory_iterator(inputPath)) {
        if (fs::is_directory(f) && fs::exists(f.path() / "testdata")
            && isCustomData(f.path() / "testdata")) {
            std::cout << "find " << f.path().string() << " is a problem data file" << std::endl;
            return true;
        }
    }

    std::cout << "Can not find problem file, " << inputPath.string()
              << " is not a hydro export directory" << std::endl;

    return false;
}

void convertCustomDir(fs::path const& inputPath, fs::path const& outputPath) {
    std::cout << "Custom data format is detected, try to find config.yaml or generate config"
              << std::endl;

    // auto config = loadDataDir(inputPath);
    // if (!config) {
    //     std::cerr << "Failed to load config.yaml and generate config, exit." << std::endl;
    //     exit(1);
    // }

    std::cout << "Config file is loaded from " << inputPath.string() << ", save to "
              << outputPath.string() << std::endl;

    if (!fs::exists(outputPath)) {
        fs::create_directories(outputPath);
    }

    // config->save(outputPath);

    // std::cout << "Config file is saved, start to convert the data." << std::endl;

    // convert_data_dir(*config, inputPath, outputPath);

    std::cout << "Data is converted." << std::endl;
}