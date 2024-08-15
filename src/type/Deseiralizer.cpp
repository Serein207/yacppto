#include <iostream>
#include <rfl/yaml.hpp>
#include <type/Deserializer.h>

std::optional<Config> loadConfigFile(fs::path const& file) {
    auto result = rfl::yaml::load<Config>(file.string());
    if (result.error()) {
        std::cerr << "Failed to load config file: " << result.error()->what() << std::endl;
        return std::nullopt;
    }

    return result.value();
}