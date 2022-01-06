#include "HitBox.hpp"

HitBox::HitBox(sf::Vector2i size) :RectangleShape((sf::Vector2f)size)
{
	this->setFillColor(sf::Color(0, 0, 0, 0));
	this->setOutlineColor(sf::Color::Red);
	this->setOutlineThickness(1.f);
    this->setOrigin(sf::Vector2f(size.x/2, size.y/2));
    m_tag = DUCK;
}

HitBox::~HitBox()
{
}

GTAG HitBox::GetTag()const
{
    return m_tag;
}
void HitBox::SetTag(const GTAG &tag)
{
    m_tag = tag;
}