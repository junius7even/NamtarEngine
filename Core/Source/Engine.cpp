//
// Created by Junius7 on 2023-08-17.
//

#include "../Header/Engine.h"


ne::Engine::Engine() {
    createWindow();
}

void ne::Engine::startGame() {
    // Start the physics thread
    physicsThread = std::thread(&Engine::physicsUpdate, this);
}

void ne::Engine::physicsUpdate() {
    // TODO: Implement job system to finish physics updates and other things as well intesd of looping.

}

void ne::Engine::draw() {

}

void ne::Engine::run() {
    draw();
}

void ne::Engine::tick() {

}

void ne::Engine::createWindow() {
    resolution = Vector2f(800, 600);
    window.create(VideoMode(resolution.x, resolution.y), "Pong", Style::Default);
    window.setFramerateLimit(FPS);
}

void ne::Engine::loadScene(const std::string& sceneFileName) {

}

void ne::Engine::initializeGameObjects() {
    //TODO: Implement JSON integration for scene reading and others
    int totalGameObjects = 3;
    gameObjectPool.resize(totalGameObjects);

    int compIDToAdd = 3;
    GameObject gameObjectToAdd = GameObject();
    for (int i = 0; i < 3; i++) {
        gameObjectToAdd.addComponent(compIDToAdd);

    }
    gameObjectPool.push_back(gameObjectToAdd);
}

void ne::Engine::lateTick() {

}
