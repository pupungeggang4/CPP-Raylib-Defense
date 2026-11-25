#ifndef FIELD_HPP
#define FIELD_HPP

#include "includes.hpp"

class Game;
class Entity;

class Spawn {
    public:
        Spawn();
        void update(Game&);
        void render(Game&);
};

class End {
    public:
        End();
        void update(Game&);
        void render(Game&);
};

class Field {
    public:
        std::array<shared_ptr<Entity>, 256> entity;
        std::array<shared_ptr<Spawn>, 4> spawns;
        std::array<shared_ptr<End>, 4> ends;

        Field();
        void update(Game&);
        void render(Game&);
};

#endif
