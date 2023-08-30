//
// Created by Junius7 on 2023-08-29.
//

#include "GameObject.h"
#include "Entity.h"

GameObject::GameObject(float xPos, float yPos, float scaleX, float scaleY) {
    ID = Entity::createNewID();
    this->position = sf::Vector2f (xPos, yPos);
    this->scale = sf::Vector2f (scaleX, scaleY);
}

GameObject::~GameObject() {
    Entity::destroyID(this->ID);
}