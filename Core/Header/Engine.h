//
// Created by Junius7 on 2023-08-17.
//

#ifndef NAMTARENGINE_ENGINE_H
#define NAMTARENGINE_ENGINE_H

#include "SFML/Graphics.hpp"
#include "Component.h"
#include "GameObject.h"
#include <vector>
#include <thread>
#include <string>

using namespace sf;

namespace ne {
    enum EngineState {};
    class Engine {
    public:
        Engine();
        void run();

    private:
        Vector2f resolution;
        RenderWindow window;
        const unsigned int FPS = 60;

        std::thread physicsThread;

        /**
         * Loads a scene by setting up all the gameObjects and initializing their components
         * Currently hardcoded through loading files by calling their names. Will have to change this later
         * @param sceneFileName
         */
        void loadScene(const std::string& sceneFileName);

        /**
         * Called by loadScene to initialize gameObjects(entities) and their components at the start of each scene.
         */
        void initializeGameObjects();

        void startGame();
        void draw();
        void physicsUpdate();
        void tick();
        void lateTick();

        void createWindow();

        static std::vector<GameObject> gameObjectPool;
        static std::vector<std::vector<Component>> componentPool;
    };

}

#endif //NAMTARENGINE_ENGINE_H
