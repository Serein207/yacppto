#pragma once

#include <filesystem>

namespace fs = std::filesystem;

bool isCustomData(fs::path const& inputPath);

bool isHydroExport(fs::path const& inputPath);

void convertCustomDir(fs::path const& inputPath, fs::path const& outputPath);

void loadDataDir(fs::path const& inputPath);