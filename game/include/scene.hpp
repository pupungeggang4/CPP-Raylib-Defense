#ifndef SCENE_HPP
#define SCENE_HPP

#include "includes.hpp"

class Game;
class Menu;

class Scene {
    public:
        Scene();
        virtual void ready(Game&);
        virtual void update(Game&);
        virtual void render(Game&);
        virtual void mouseUp(Game&, Vector2);
};

class SceneTitle : public Scene {
    public:
        SceneTitle();
        void ready(Game&) override;
        void update(Game&) override;
        void render(Game&) override;
        void mouseUp(Game&, Vector2) override;
};

class SceneLevelSelect : public Scene {
    public:
        int page = 0;
        int selectedLevel = -1;

        SceneLevelSelect();
        void ready(Game&) override;
        void update(Game&) override;
        void render(Game&) override;
        void mouseUp(Game&, Vector2) override;
};

class SceneBattle : public Scene {
    public:
        shared_ptr<Menu> menu;

        SceneBattle();
        void ready(Game&) override;
        void update(Game&) override;
        void render(Game&) override;
        void mouseUp(Game&, Vector2) override;
};

class SceneCollection : public Scene {
    public:
        SceneCollection();
        void ready(Game&) override;
        void update(Game&) override;
        void render(Game&) override;
        void mouseUp(Game&, Vector2) override;
};

class Menu : public Scene {
    public:
        Menu();
        void ready(Game&) override;
        void render(Game&) override;
        void mouseUp(Game&, Vector2) override;
};

#endif
