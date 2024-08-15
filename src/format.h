#pragma once

#include <filesystem>
#include <optional>
#include <type/Config.h>
#include <vector>

namespace fs = std::filesystem;

bool isCustomData(fs::path const& inputPath);

bool isHydroExport(fs::path const& inputPath);

std::vector<fs::path> getHydroExportProblems(fs::path const& inputPath);

void convertCustomDir(fs::path const& inputPath, fs::path const& outputPath);

std::optional<Config> loadDataDir(fs::path const& inputPath);