//
// Created by Junius7 on 2023-08-29.
//

#ifndef NAMTARENGINE_GAMEOBJECT_H
#define NAMTARENGINE_GAMEOBJECT_H

#include "SFML/Graphics.hpp"

namespace ne {
    class GameObject {
    public:
        GameObject(float xPos = 0.0f, float yPos = 0.0f, float scaleX = 1.0f, float scaleY = 1.0f);
        ~GameObject();
        sf::Vector2f scale;
        sf::Vector2f position;
    private:
        int ID;
    };
}


#endif //NAMTARENGINE_GAMEOBJECT_H
