#ifndef SPRITE_H
#define SPRITE_H

#include <SFML/Graphics.hpp>

class Sprite
{
    public:

        enum Direction
        {
            RIGHT = 0,
            DOWN,
            LEFT,
            UP,
        };

        sf::Sprite mSprites[8];
        sf::Sprite mSprite;
        float mTime;
        int mIndex;
        Direction mDirection;

        Sprite(int index);
        virtual ~Sprite();

        sf::Sprite get_sprite(void);
        sf::Sprite animate(void);
        void move(Direction dir);
    protected:
    private:
};

#endif // SPRITE_H
