//
// Created by Junius7 on 2023-08-29.
//

#include "Entity.h"

Entity::Entity() {
    Entity::IDCount = 0;
}

static int Entity::createNewID() {
    if (freeIDs.empty())
        return ++IDCount;
    int returnedID = freeIDs.back();
    freeIDs.pop_back();
    return returnedID;
}

static void Entity::destroyID(int ID) {
    freeIDs.push_back(ID);
}