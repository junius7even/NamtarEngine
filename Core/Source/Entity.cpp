//
// Created by Junius7 on 2023-08-29.
//

#include "../Header/Entity.h"

ne::Entity::Entity() {
    Entity::IDCount = 0;
}

// TODO: add thread safety
int ne::Entity::createNewID() {
    if (freeIDs.empty())
        return ++IDCount;
    int returnedID = freeIDs.back();
    freeIDs.pop_back();
    return returnedID;
}

// TODO: add thread safety
void ne::Entity::destroyID(int ID) {
    freeIDs.push_back(ID);
}