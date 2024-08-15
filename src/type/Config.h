#pragma once

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
    std::optional<int> id;
    int time = 1000;
    int memory = 256;
    int score;
    std::string type = "min";
    std::vector<std::string> condition;
    std::vector<Case> cases;
};

struct Config {
    std::string judge_type = "classic";
    std::string task_type = "simple";
    int score = 100;
    int time_limit = 1000;
    int memory_limit = 256;
    std::vector<Subtask> subtasks;
    std::vector<Case> cases;
};
