//
// Created by Junius7 on 2023-08-29.
//

#include "Entity.h"

Entity::Entity() {
    Entity::IDCount = 0;
}

// TODO: add thread safety
int Entity::createNewID() {
    if (freeIDs.empty())
        return ++IDCount;
    int returnedID = freeIDs.back();
    freeIDs.pop_back();
    return returnedID;
}

// TODO: add thread safety
void Entity::destroyID(int ID) {
    freeIDs.push_back(ID);
}