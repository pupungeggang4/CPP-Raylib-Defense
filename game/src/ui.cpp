#include "ui.hpp"

std::unordered_map<std::string, std::vector<float>> UI::UITitle = {
    {"text_title", {20, 20}},
    {"button_start", {160, 120, 480, 80}},
    {"text_start", {180, 140}},
    {"button_adventure", {160, 200, 480, 80}},
    {"text_adventure", {180, 220}},
    {"button_erase", {160, 280, 480, 80}},
    {"text_erase", {180, 300}},
    {"button_quit", {160, 360, 480, 80}},
    {"text_quit", {180, 380}},
};

std::unordered_map<std::string, std::vector<float>> UI::UILevelSelect = {
    {"text_title", {20, 20}},
    {"button_back", {740, 20, 40, 40}},
    {"button_level", {60, 80, 140, 140, 120, 120}},
    {"text_level", {20, 20}},
    {"button_start", {620, 500, 160, 80}},
    {"text_start", {640, 520}}
};

std::unordered_map<std::string, std::vector<float>> UI::UIAdventureSelect = {
    {"text_title", {20, 20}},
    {"button_back", {740, 20, 40, 40}},
};

std::unordered_map<std::string, std::vector<float>> UI::UIBattle = {
};
