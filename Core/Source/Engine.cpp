//
// Created by Junius7 on 2023-08-17.
//

#include "../Header/Engine.h"


Engine::Engine() {
    resolution = Vector2f(800, 600);
    window.create(VideoMode(resolution.x, resolution.y), "Pong", Style::Default);
    window.setFramerateLimit(FPS);
}

void Engine::startGame() {
    // Start the physics thread
    physicsThread = thread(&Engine::physicsUpdate, this);
}

void Engine::physicsUpdate() {

}

void Engine::draw() {

}

void Engine::run() {
    draw();
}

void Engine::update() {

}
