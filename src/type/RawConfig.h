
#include <optional>
#include <rfl/Rename.hpp>
#include <string>
#include <vector>

namespace raw {

struct Case {
    rfl::Rename<"input_file", std::string> input;
    rfl::Rename<"answer_file", std::string> answer;
};

struct Subtask {};

struct Config {
    rfl::Rename<"task_type", std::optional<std::string>> taskType;
    rfl::Rename<"judge_type", std::optional<std::string>> judgeType;
    std::vector<Case> cases;
    std::vector<Subtask> subtasks;
};

} // namespace raw
