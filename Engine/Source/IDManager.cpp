//
// Created by Junius7 on 2023-08-29.
//

#include "Include/ne/IDManager.h"

// TODO: add thread safety
int ne::IDManager::assignEntityID() {
    if (entityIDPool.empty())
        return ++entityIDCounter;
    int returnedID = entityIDPool.back();
    entityIDPool.pop_back();
    return returnedID;
}

// TODO: add thread safety
void ne::IDManager::destroyEntityID(int ID) {
    entityIDPool.push_back(ID);
}

// TODO: add thread safety
int ne::IDManager::assignTypeID() {
    if (typeIDPool.empty())
        return ++typeIDCounter;
    int returnedID = typeIDPool.back();
    typeIDPool.pop_back();
    return returnedID;
}

void ne::IDManager::destroyTypeID(int ID) {
    typeIDPool.push_back(ID);
}
