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
