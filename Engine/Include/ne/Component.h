//
// Created by Junius7 on 2023-08-30.
//

#ifndef NAMTARENGINE_COMPONENT_H
#define NAMTARENGINE_COMPONENT_H

#include "IDManager.h"

namespace ne {
    class Component {
    public:
        virtual void Start()=0;
        /**
         * Executed every tick of the game (frame).
         */
        virtual void Update()=0;
        /**
         * Executed on the physics thread, separate from the rendering.
         */
        virtual void PhysicsUpdate() { };
        /**
         * Executed after game logic updates, used potentially for UI and friends.
         */
        virtual void LateUpdate()=0;

        Component() {
            isActive = true;
            ID = IDManager::assignTypeID();
        }

        virtual ~Component() {
            IDManager::destroyTypeID(ID);
        }
        bool isActive;

    protected:
        int ID;
    };
}

#endif //NAMTARENGINE_COMPONENT_H
