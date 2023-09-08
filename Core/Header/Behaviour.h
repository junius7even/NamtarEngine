//
// Created by Junius7 on 2023-08-30.
//

#ifndef NAMTARENGINE_BEHAVIOUR_H
#define NAMTARENGINE_BEHAVIOUR_H
#include "Component.h"

namespace ne {
    class Behaviour: public Component {
    public:
        Behaviour(): Component()
        {

        }
        virtual void Start() {};
        /**
         * Executed every tick of the game (frame).
         */
        virtual void Update() {};
        /**
         * Executed on the physics thread, separate from the rendering.
         */
        virtual void PhysicsUpdate() {};
        /**
         * Executed after game logic updates, used potentially for UI and friends.
         */
        virtual void LateUpdate() {};
    };
}

#endif //NAMTARENGINE_BEHAVIOUR_H
