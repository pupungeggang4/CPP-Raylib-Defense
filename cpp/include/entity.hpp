#ifndef ENTITY_HPP
#define ENTITY_HPP

#include "includes.hpp"

class Game;

class Entity {
    public:
        bool valid = false;
        Entity();
        virtual void update(Game&);
        virtual void render(Game&);
};

class Unit : public Entity {
    public:
        Unit();
        void update(Game&) override;
        void render(Game&) override;
};

class Projectile : public Entity {
    public:
        Projectile();
        void update(Game&) override;
        void render(Game&) override;
};

#endif
