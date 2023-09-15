//
// Created by Junius7 on 2023-09-05.
//

#ifndef NAMTARENGINE_SPRITERENDERER_H
#define NAMTARENGINE_SPRITERENDERER_H
#include "../Header/Behaviour.h"
#include <SFML/Graphics.hpp>
#include <iostream>

namespace ne {
    class SpriteRenderer: public ne::Component {
    public:
        SpriteRenderer(): Component() {
            texture.loadFromFile("");
            sprite.setTexture(texture);
            sprite.setScale(100, 100);
            position = sf::Vector2f(0, 0);
        }
        explicit SpriteRenderer(float posX = 0.0f, float posY = 0.0f, float rotation = 0.0f, const std::string& imageName = ""): Component() {
            std::cout<<"Texture loading..."<<std::endl;
            if (imageName == "")
                texture.loadFromFile("D:\\GraphicsProjects\\NamtarEngine\\Core\\CoreComponents\\Images\\sfml-icon.png");
            else
                texture.loadFromFile(imageName);
            sprite.setTexture(texture);
            spriteRect.setSize(Vector2f(200, 200));
            spriteRect.setTexture(&texture);
            position = sf::Vector2f(posX, posY);
        }

        //TODO: Implementation
        void setTransparency(float transparencyRawValue);
        void Start() override {

        }

        void Update() override {
            if (isActive)
                drawStack.push_back(&spriteRect);
        }

        void LateUpdate() override {

        }

        inline static std::vector<sf::RectangleShape*> drawStack;
    private:
        // int priority;
        // TODO: Implementation
        void swapSprite(std::string imageName);
        sf::Texture texture;
        sf::RectangleShape spriteRect;
        sf::Sprite sprite;
        sf::Vector2f position;
    };
}

#endif //NAMTARENGINE_SPRITERENDERER_H