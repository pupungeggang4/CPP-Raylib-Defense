#include "ui.hpp"

std::unordered_map<std::string, std::vector<float>> UI::UITitle = {
    {"text_title", {20.0f, 20.0f}},
    {"button_start", {160.0f, 120.0f, 480.0f, 80.0f}},
    {"text_start", {180.0f, 140.0f}},
    {"button_erase", {160.0f, 200.0f, 480.0f, 80.0f}},
    {"text_erase", {180.0f, 220.0f}},
    {"button_quit", {160.0f, 280.0f, 480.0f, 80.0f}},
    {"text_quit", {180.0f, 300.0f}},
};

std::unordered_map<std::string, std::vector<float>> UI::UILevelSelect = {
    {"text_title", {20.0f, 20.0f}},
    {"button_back", {740.0f, 20.0f, 40.0f, 40.0f}}
};

std::unordered_map<std::string, std::vector<float>> UI::UIBattle = {
};
