//
// Created by Junius7 on 2023-09-05.
//

#ifndef NAMTARENGINE_GAMEMANAGER_H
#define NAMTARENGINE_GAMEMANAGER_H

#include

class GameManager: MonoInstance {
public:
    enum GameState{MAIN_MENU, LEVEL_SELECTION, GAME_PLAYING, GAME_PAUSED, GAME_OVER, };
    /**
     *
     * @return returns a function static variable of the GameManager
     */
    static GameManager& get() {
        static GameManager gManager;
        return gManager;
    }

    GameManager();
};


#endif //NAMTARENGINE_GAMEMANAGER_H
