#include <iostream>
#include "Sprite.h"

sf::Clock Clock;

Sprite::Sprite(int index)
{
    //ctor
    static sf::Image Image;
    bool test = Image.LoadFromFile("resources/ChomperSprites.png");
    if (test)
        std::cout << "Test " << test << std::endl;

    mIndex = index;
    mSprite.SetImage(Image);
    mDirection = RIGHT;
    Clock.Reset();
}

Sprite::~Sprite()
{
    //dtor
}

sf::Sprite Sprite::get_sprite (void)
{
    return animate();
}

sf::Sprite Sprite::animate (void)
{
    static bool toogle = false;
    int x, y;

    if (Clock.GetElapsedTime() >= 0.125) {
        Clock.Reset();
        toogle = !toogle;

        switch (mDirection) {
        case RIGHT:
            mSprite.Move(1, 0);
            break;
        case DOWN:
            mSprite.Move(0, 1);
            break;
        case LEFT:
            mSprite.Move(-1, 0);
            break;
        case UP:
            mSprite.Move(0, -1);
            break;
        }

        x = mIndex * 32;
        y = mDirection * 32;

        if (toogle)
            mSprite.SetSubRect(sf::IntRect(x, y, x + 32, y + 32));
        else
            mSprite.SetSubRect(sf::IntRect(x + 32, y, x + 64, y + 32));
    }

    return mSprite;
}

void Sprite::move(Direction dir)
{
    mDirection = dir;
}
