//
// Created by Junius7 on 2023-08-29.
//

#ifndef NAMTARENGINE_GAMEOBJECT_H
#define NAMTARENGINE_GAMEOBJECT_H

#include <bitset>
#include <SFML/Graphics.hpp>
#include "IDManager.h"
#include <string>
#include <utility>

namespace ne {
    /**
     * GameObject represents each item placed inside a scene that may hold components. It is the entity in the context of an ECS.
     */
    class GameObject {
    public:
        explicit GameObject(std::string&& name = "GameObject", bool isActive = true, float xPos = 0.0f, float yPos = 0.0f, float scaleX = 1.0f, float scaleY = 1.0f) {
            this->name = name;
            this->isActive = true;
            ID = ne::IDManager::assignEntityID();
            this->position = sf::Vector2f (xPos, yPos);
            this->scale = sf::Vector2f (scaleX, scaleY);
        }
        ~GameObject() {
            ne::IDManager::destroyEntityID(this->ID);
        }
        bool isActive;
        sf::Vector2f scale;
        std::string name;
        sf::Vector2f position;

        [[nodiscard]] int getID() const { return ID; }
    private:
        int ID;
    };
}


#endif //NAMTARENGINE_GAMEOBJECT_H
