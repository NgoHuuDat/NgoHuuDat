#ifndef HITBOX_HPP
#define HITBOX_HPP

#include"CommonFunc.hpp"

enum GTAG
{
	WALL = 0,
	ENEMY,
	DUCK,
    EGG
};

class HitBox :public sf::RectangleShape
{
public:
	HitBox(sf::Vector2i size);
	~HitBox();

	GTAG GetTag()const;
	void SetTag(const GTAG &tag);

private:
	GTAG m_tag;
};


#endif // !HITBOX_HPP