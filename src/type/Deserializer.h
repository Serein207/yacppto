#pragma once

#include <filesystem>
#include <type/Config.h>

namespace fs = std::filesystem;

std::optional<Config> loadConfigFile(fs::path const& file);
