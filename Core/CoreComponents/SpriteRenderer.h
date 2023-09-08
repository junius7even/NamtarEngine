//
// Created by Junius7 on 2023-09-05.
//

#ifndef NAMTARENGINE_SPRITERENDERER_H
#define NAMTARENGINE_SPRITERENDERER_H
#include "../Header/Behaviour.h"
#include <SFML/Graphics.hpp>

class SpriteRenderer: public ne::Behaviour {
public:
    // SpriteRenderer(const sf::Image& img = sf::Image(""), const sf::Vector2f& position = sf::Vector2f(0, 0), float rotation = 0.0f, );
    void setTransparency(float transparencyRawValue);
private:
    void swapSprite(sf::Image& img);
    sf::Sprite sprite;
    sf::Vector2f position;
};

#endif //NAMTARENGINE_SPRITERENDERER_H