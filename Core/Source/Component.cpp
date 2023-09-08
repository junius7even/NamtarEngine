//
// Created by Junius7 on 2023-08-30.
//

#include "../Header/Component.h"
#include "../Header/IDManager.h"

ne::Component::Component() {
    ID = IDManager::assignTypeID();
}

ne::Component::~Component() {
    IDManager::destroyTypeID(ID);
}