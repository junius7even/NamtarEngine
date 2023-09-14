//
// Created by Junius7 on 2023-09-05.
//

#ifndef NAMTARENGINE_SPRITERENDERER_H
#define NAMTARENGINE_SPRITERENDERER_H
#include "../Header/Behaviour.h"
#include <SFML/Graphics.hpp>

namespace ne {
    class SpriteRenderer: public ne::Component {
    public:
        SpriteRenderer() {
            sf::Texture texture;
            texture.loadFromFile("");
            sprite.setTexture(texture);
            position = sf::Vector2f(0, 0);
            this->isActive = true;
        }
        explicit SpriteRenderer(float posX = 0.0f, float posY = 0.0f, float rotation = 0.0f, const std::string& imageName = "", bool isActive = true) {
            sf::Texture texture;
            texture.loadFromFile(imageName);
            sprite.setTexture(texture);
            position = sf::Vector2f(posX, posY);
            this->isActive = isActive;
        }
        void setTransparency(float transparencyRawValue);
        void Start() override {

        }

        void Update() override {
            if (isActive)
                drawStack.push_back(&sprite);
        }

        void LateUpdate() override {

        }

        inline static std::vector<sf::Sprite*> drawStack;
    private:
        bool isActive;
        int priority;
        void swapSprite(std::string imageName);
        sf::Sprite sprite;
        sf::Vector2f position;
    };
}

#endif //NAMTARENGINE_SPRITERENDERER_H