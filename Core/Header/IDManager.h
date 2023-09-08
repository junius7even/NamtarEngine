//
// Created by Junius7 on 2023-08-29.
//

#ifndef NAMTARENGINE_IDMANAGER_H
#define NAMTARENGINE_IDMANAGER_H
#include <vector>
#include <atomic>

namespace ne {
    /**
     * A class responsible for handing out unique IDs in a thread safe manner to every existing GameObject and Component at creation time.
     */
    class IDManager {
    public:
        IDManager() = delete;
        /**
         *
         * @return Returns a free ID or increments entityIDCount.
         */
        static int assignEntityID();

        /**
         *
         * @return Returns a free ID or increments typeIDCount.
         */
        static int assignTypeID();

        /**
         * The ID passed in is freed and stored in entityIDPool for later use.
         * @param ID The ID of an object to be destroyed.
         */
        static void destroyEntityID(int ID);

        /**
         * The ID passed in is freed and stored in typeIDPool for later use.
         * @param ID The ID of an object to be destroyed.
         */
        static void destroyTypeID(int ID);
    private:
        /**
         * Stores freed up entity IDs when a GameObject is freed.
         */
        static std::vector<int> entityIDPool;
        /**
         * Stores freed up type(component) IDs when a component is freed.
         */
        static std::vector<int> typeIDPool;

        /**
         * Increments with every instantiation of a GameObject.
         */
        inline static std::atomic<int> entityIDCounter = 0;
        /**
         * Increments with every instantiation of a unique Component child type.
         */
        inline static std::atomic<int> typeIDCounter = 0;
    };
}



#endif //NAMTARENGINE_IDMANAGER_H
