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
#include <map>
#include "../CoreComponents/Helper/json.hpp"


using namespace sf;

namespace ne {

    enum EngineState {};
    class Engine {
    public:
        Engine();
        ~Engine();
        void run();

        void startEngine();

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

        using json = nlohmann::json;
        void initializeGameObjects(const json& gameObjects);
        void initializeComponents(GameObject& gameObject, const json& components);
        void recursive_iterate(const json& j);
        GameObject recursive_childObjects(const json& j);

        std::string activeSceneName;

        void draw();
        void physicsUpdate();
        void tick();
        void lateTick();

        std::map<std::string, int> componentIdentifierMap = {{"SpriteRenderer", 0}};

        void createWindow();

        // Pointer to GameObject to prevent creating gameObjects and incrementing IDs each time the vector is resized
        inline static std::vector<GameObject*> gameObjectPool;
        // Component pool type contains pointers to Components to avoid initializing and therefore creating components each time the vector is resized & object slicing
        inline static std::vector<std::vector<Component*>> componentPool;
    };

}

#endif //NAMTARENGINE_ENGINE_H
