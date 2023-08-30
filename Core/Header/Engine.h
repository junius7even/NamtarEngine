//
// Created by Junius7 on 2023-08-17.
//

#ifndef NAMTARENGINE_ENGINE_H
#define NAMTARENGINE_ENGINE_H

#include "SFML/Graphics.hpp"
#include <vector>
#include <thread>

using namespace sf;
using namespace std;

class Engine {
public:
    Engine();
    void run();

private:
    Vector2f resolution;
    RenderWindow window;
    const unsigned int FPS = 60;

    std::thread physicsThread;


    void startGame();
    void draw();
    void physicsUpdate();
    void update();
};


#endif //NAMTARENGINE_ENGINE_H
