//
// Created by Junius7 on 2023-08-29.
//

#include "../Header/GameObject.h"
#include "../Header/Entity.h"

ne::GameObject::GameObject(float xPos, float yPos, float scaleX, float scaleY) {
    ID = ne::Entity::createNewID();
    this->position = sf::Vector2f (xPos, yPos);
    this->scale = sf::Vector2f (scaleX, scaleY);
}

ne::GameObject::~GameObject() {
    ne::Entity::destroyID(this->ID);
}