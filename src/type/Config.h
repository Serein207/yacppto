#pragma once

#include "rfl/Literal.hpp"
#include "rfl/TaggedUnion.hpp"
#include <optional>
#include <string>
#include <vector>

struct Case {
    std::string input;
    std::string answer;
    int time = 1000;
    int memory = 100;
    std::optional<int> score;
};

struct Subtask {
    int time = 1000;
    int memory = 256;
    int score;
    std::vector<Case> cases;
};

struct Judge {
    std::string judgeType = "classic";
};

struct ResourceLimits {
    int time = 1000;
    int memory = 256;
};

struct SubtaskTask {
    using Tag = rfl::Literal<"subtasks", "SubtaskTask">;
    std::vector<Subtask> subtasks;
};

struct CaseTask {
    using Tag = rfl::Literal<"simple", "CaseTask">;
    std::vector<Case> cases;
};

using Task = rfl::TaggedUnion<"taskType", SubtaskTask, CaseTask>;

struct Config {
    int score = 100;
    Judge judge;
    ResourceLimits resourceLimits;
    Task task;
};
