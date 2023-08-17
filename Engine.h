//
// Created by Junius7 on 2023-08-17.
//

#ifndef NAMTARENGINE_ENGINE_H
#define NAMTARENGINE_ENGINE_H

#include <SFML/Graphics.hpp>
using namespace sf;
using namespace std;

class Engine {
public:
    Engine();
    void Run();

private:
    Vector2f resolution;
    RenderWindow window;
    const unsigned int FPS = 60;


    void PhysicsUpdate();
    void Update();
};


#endif //NAMTARENGINE_ENGINE_H
