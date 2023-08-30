//
// Created by Junius7 on 2023-08-29.
//

#ifndef NAMTARENGINE_GAMEOBJECT_H
#define NAMTARENGINE_GAMEOBJECT_H

#include <SFML/Graphics.hpp>

class GameObject {
public:
    explicit GameObject(float xPos = 0.0, float yPos = 0.0, float scaleX = 1.0, float scaleY = 1.0);
    ~GameObject();
    sf::Vector2f scale;
    sf::Vector2f position;
private:
    int ID;
};

#endif //NAMTARENGINE_GAMEOBJECT_H
