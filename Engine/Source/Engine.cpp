//
// Created by Junius7 on 2023-08-17.
//

#include <ne/Engine.h>
#include <ne/CoreComponents/SpriteRenderer.h>
#include <fstream>
#include <iostream>

using json = nlohmann::json;

ne::Engine::Engine() {
    createWindow();
}

ne::Engine::~Engine() {
    // Deallocate component pool
    for (const auto& i: componentPool) {
        for (auto v: i)
            delete v;
    }
    for (auto i: gameObjectPool) {
        delete i;
    }
}


void ne::Engine::startEngine() {
    // Start the physics thread
    // physicsThread = std::thread(&Engine::physicsUpdate, this);
    loadScene("D:\\GraphicsProjects\\NamtarEngine\\SceneData\\TestScene.JSON");

}

void ne::Engine::physicsUpdate() {
    // TODO: Implement job system to finish physics updates and other things as well instead of looping.

}

void ne::Engine::draw() {
    // Draw all the GameObjects with the SpriteRenderer components
    std::vector<sf::RectangleShape*>* drawStackRef = &ne::SpriteRenderer::drawStack;
    for (auto i: *drawStackRef) {
        window.draw(*i);
    }
}

void ne::Engine::run() {
    while (window.isOpen()) {
        window.clear(sf::Color::Black);
        sf::Event windowEvent;
        while (window.pollEvent(windowEvent)) {
            switch (windowEvent.type) {
                case sf::Event::Closed: {
                    window.close();
                    break;
                }
            }
        }
        tick();
        lateTick();
        draw();
        window.display();
    }
}

void ne::Engine::tick() {

    for (auto i: componentPool) {
        for (auto v: i) {
            if (v->isActive)
                v->Update();
        }
    }
}

void ne::Engine::createWindow() {
    resolution = Vector2f(800, 600);
    window.create(VideoMode(resolution.x, resolution.y), "NamtarEngine", Style::Default);
    window.setFramerateLimit(FPS);
}

void ne::Engine::initializeGameObjects(const json& gameObjects) {
    gameObjectPool.resize(gameObjects.size());
    componentPool.resize(gameObjects.size());
    componentList.resize(gameObjects.size());
    for (auto element: gameObjects) {
        GameObject object =  GameObject(
                element["name"],
                element["isActive"],
                element["position"][0],
                element["position"][1]
        );
        gameObjectPool.push_back(&object);

        // Handle components
        if (element.contains("components")) {
            initializeComponents(object, element["components"]);
        }
        // TODO: Handle child objects

    }
}

//        std::cout<<"name: "<<element["name"]<<std::endl;
//        std::cout<<"isActive: "<<element["isActive"]<<std::endl;
//        std::cout<<"PosX: "<<element["position"][0]<<std::endl;
//        std::cout<<"PosX: "<<element["position"][1]<<std::endl;
//        std::cout<<"Components num: "<<element["components"].size()<<std::endl;

void ne::Engine::initializeComponents(ne::GameObject &gameObject, const json &components) {
    for(auto component: components) {
        int typeID = componentIdentifierMap[component["identifier"]];
        int goID = gameObject.getID();
        componentPool.at(goID).resize(components.size(), nullptr);

        // Create the component in mem
        switch (typeID) {
            case 0: {
                componentPool.at(goID).at(typeID) = new ne::SpriteRenderer(
                                    (float)component["position"][0],
                                    (float)component["position"][1],
                                    0.0f,
                                    component["spriteName"]
                                    );
                break;
            }
            case 1:
                // TODO: Add other core components
                break;
        }

        // Add component to componentList
        addComponent(goID, typeID);

    }
}

ne::GameObject ne::Engine::recursive_childObjects(const json &j) {

    return GameObject();
}



void ne::Engine::loadScene(const std::string& sceneFileName) {
    // Parse json data with nlohmann JSON
    std::ifstream f(sceneFileName);
    std::cout<<"Scenefile open status: "<<f.is_open()<<std::endl;
    json data = json::parse(f);
    activeSceneName = data["sceneName"];
    initializeGameObjects(data["gameObjects"]);
    for (auto i: componentPool) {
        for (auto v: i)
            v->Start();
    }

}

void ne::Engine::lateTick() {
    for (auto i: componentPool) {
        for (auto v: i) {
            v->LateUpdate();
        }
    }
}

//TODO: Iterate through child gameObjects recursively
void ne::Engine::recursive_iterate(const json &j) {

}

void ne::Engine::addComponent(int goID, int typeID) {
    if (componentList[goID][typeID]) {
        // TODO: Add a proper logger
        std::cout<<"Could not add component! Component("<<typeID<<") already exists on object("<<goID<<")!"<<std::endl;
        return;
    }
    componentList.at(goID).flip(typeID);
}

void ne::Engine::removeComponent(int goID, int typeID) {
    if (!componentList[goID][typeID]) {
        std::cout<<"Could not remove component! Component("<<typeID<<") does not already exist on object("<<goID<<")!"<<std::endl;
        return;
    }
    componentList.at(goID).flip(typeID);
    componentList[goID].reset();
}

