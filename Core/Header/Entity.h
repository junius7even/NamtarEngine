//
// Created by Junius7 on 2023-08-29.
//

#ifndef NAMTARENGINE_ENTITY_H
#define NAMTARENGINE_ENTITY_H
#include <vector>

namespace ne {
    class Entity {
    public:
        Entity();
        static int createNewID();
        static void destroyID(int ID);
    private:
        static std::vector<int> freeIDs;
        static int IDCount;
    };
}



#endif //NAMTARENGINE_ENTITY_H
