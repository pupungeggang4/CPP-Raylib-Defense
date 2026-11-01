#include "ui.hpp"

std::unordered_map<std::string, std::array<float, 6>> UI::UITitle = {
    {"text_title", {20, 20}},
    {"button_start", {160, 120, 480, 80}},
    {"text_start", {180, 140}},
    {"button_adventure", {160, 200, 480, 80}},
    {"text_adventure", {180, 220}},
    {"button_tutorial", {160, 280, 480, 80}},
    {"text_tutorial", {180, 300}},
    {"button_erase", {160, 360, 480, 80}},
    {"text_erase", {180, 380}},
    {"button_quit", {160, 440, 480, 80}},
    {"text_quit", {180, 460}},
    {"button_collection", {700, 500, 80, 80}}
};

std::unordered_map<std::string, std::array<float, 6>> UI::UILevelSelect = {
    {"text_title", {20, 20}},
    {"button_back", {740, 20, 40, 40}},
    {"button_level", {60, 80, 140, 140, 120, 120}},
    {"text_level", {20, 20}},
    {"button_prev", {60, 500, 260, 80}},
    {"text_prev", {80, 520}},
    {"button_next", {340, 500, 260, 80}},
    {"text_next", {360, 520}},
    {"button_start", {620, 500, 120, 80}},
    {"text_start", {640, 520}}
};

std::unordered_map<std::string, std::array<float, 6>> UI::UICollection = {
    {"text_title", {20, 20}},
    {"button_back", {740, 20, 40, 40}},
};

std::unordered_map<std::string, std::array<float, 6>> UI::UIBattle = {
    {"button_menu", {740, 20, 40, 40}},
};

std::unordered_map<std::string, std::array<float, 6>> UI::UIMenu = {
    {"rect", {160, 140, 480, 320}},
    {"text_paused", {180, 160}},
    {"button_resume", {160, 220, 480, 80}},
    {"text_resume", {180, 240}},
    {"button_exit", {160, 300, 480, 80}},
    {"text_exit", {180, 320}},
    {"button_quit", {160, 380, 480, 80}},
    {"text_quit", {180, 400}}
};
