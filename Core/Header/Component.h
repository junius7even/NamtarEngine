//
// Created by Junius7 on 2023-08-30.
//

#ifndef NAMTARENGINE_COMPONENT_H
#define NAMTARENGINE_COMPONENT_H

namespace ne {
    class Component {
    public:
        Component();
        virtual ~Component();
    private:
        int ID;
    };
}

#endif //NAMTARENGINE_COMPONENT_H
