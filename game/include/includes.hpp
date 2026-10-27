#ifndef INCLUDES_HPP
#define INCLUDES_HPP

#include <iostream>
#include <fstream>
#include <sstream>

#include <string>
#include <array>
#include <unordered_map>
#include <vector>

#include <memory>

#include <raylib.h>
#include <raymath.h>

enum SceneName {TITLE, LEVEL_SELECT, ADVENTURE_SELECT, BATTLE, COLLECTION};
enum State {NORMAL};

using std::shared_ptr;
using std::make_shared;

#endif
