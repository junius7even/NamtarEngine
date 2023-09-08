//
// Created by Junius7 on 2023-08-29.
//

#include "../Header/GameObject.h"
#include "../Header/IDManager.h"

void ne::GameObject::addComponent(int typeID) {
    if (componentList[typeID]) {
        // TODO: Log a message saying the component had already been added

    }
    componentList[typeID].flip();
}

void ne::GameObject::removeComponent(int typeID) {
    if (!componentList[typeID]) {
        // TODO: Log a message saying the component is not there in the first place.

    }
    componentList[typeID].flip();
}
