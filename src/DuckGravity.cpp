#include "DuckGravity.hpp"
#include<iostream>


DuckG::DuckG() 
{
   this->m_currentFrame = sf::Vector2i(6,0);
   this->m_rectUV = sf::Vector2i(0,0);
   this->m_rightleft = true;
   this->m_intStart = true;
   this->m_corner = false;
}

DuckG::~DuckG()
{
   if(m_hitbox != nullptr)
      delete m_hitbox;
}


void DuckG::Init(const sf::Texture &texture)
{
   m_hitbox = new HitBox(sf::Vector2i(28,30));
   m_hitbox->SetTag(GTAG::DUCK);
   
   m_duck.setTexture(texture);
   m_duck.setOrigin(sf::Vector2f(TILE_SIZE/2,TILE_SIZE/2));
   m_duck.setTextureRect(sf::IntRect(sf::Vector2i(6*32, 0),sf::Vector2i(32,32)));
}

void DuckG::InitPosition(const sf::Vector2f& pos)
{
   m_duck.setPosition(pos);
   m_hitbox->setPosition(pos);
}

sf::Vector2f DuckG::GetPosition() const
{
   return m_duck.getPosition();
}

void DuckG::Rotation(const float& corner)
{
   m_duck.setRotation(corner);
   m_corner = !m_corner;
}

void DuckG::InitStart()
{
   this->m_currentFrame.x++;
   if(this->m_currentFrame.x > 6)
      this->m_currentFrame = {0,1};
   this->CaculaRect();
   this->ApplyRect();
   if(m_currentFrame.y == 1)
   {
      if (m_currentFrame.x >5)
      {
         m_intStart = false;
         m_currentFrame = {6,1};
      }
   }
}

void DuckG::SetStart(const bool start)
{
   m_intStart = start;
   m_corner = false;
   m_currentFrame = {6,0};
   this->CaculaRect();
   this->ApplyRect();
}

bool DuckG::GetStart() const
{
   return m_intStart;
}

bool DuckG::CheckCollision(const HitBox* hitbox)const
{
   double distX = (m_hitbox->getPosition().x + (m_hitbox->getSize().x / 2.f)) - (hitbox->getPosition().x + (hitbox->getSize().x / 2.f));
	if (distX < 0)
		distX = -distX;

	double distW = (m_hitbox->getSize().x + hitbox->getSize().x) / 2.f;

	int distY = (int)((m_hitbox->getPosition().y + (m_hitbox->getSize().y / 2.f)) - (hitbox->getPosition().y + (hitbox->getSize().y / 2.f)));
	if (distY < 0)
		distY = -distY;

	int distH = (int)((m_hitbox->getSize().y + hitbox->getSize().y) / 2.f);

   if((distX <= distW && distY <= distH))
   {
      if(hitbox->GetTag()== GTAG::EGG)
      {
         return true;
      }
      if(hitbox->GetTag() == GTAG::WALL) 
         return true;
      if(hitbox->GetTag() == GTAG::ENEMY)
         return true;  
   }

	return false;
}

void DuckG::Move(const sf::Vector2f& direction)
{
   if(m_currentFrame.y == 1)
      m_currentFrame.y = 0;
   if(direction.x > 0)
      m_rightleft = true;
   else
      m_rightleft = false;
   m_hitbox->setPosition(m_hitbox->getPosition() + direction);
   m_duck.setPosition(m_hitbox->getPosition());
   m_currentFrame.x++;
}

void DuckG::CaculaRect()
{
   this->m_rectUV.x = this->m_currentFrame.x * TILE_SIZE;
	this->m_rectUV.y = this->m_currentFrame.y * TILE_SIZE;
}

void DuckG::ApplyRect()
{
   if(!m_corner)
   {
      if(m_rightleft)
         this->m_rect = sf::IntRect(m_rectUV,sf::Vector2i(TILE_SIZE,TILE_SIZE));
      else
         this->m_rect = sf::IntRect(m_rectUV,sf::Vector2i(-TILE_SIZE,TILE_SIZE));
   }
   else{
      if(m_rightleft)
         this->m_rect = sf::IntRect(m_rectUV,sf::Vector2i(-TILE_SIZE,TILE_SIZE));
      else
         this->m_rect = sf::IntRect(m_rectUV,sf::Vector2i(TILE_SIZE,TILE_SIZE));
   }
   this->m_duck.setTextureRect(m_rect);
}

void DuckG::Update()
{
   if(m_currentFrame.y == 0)
   {
      if(!m_corner){
         if(m_rightleft){
            if(m_currentFrame.x > 5)
               m_currentFrame.x = 0;
         }
         else{
            if(m_currentFrame.x > 6)
               m_currentFrame.x = 1;
         }
      }
      else{
         if(m_rightleft){
            if(m_currentFrame.x > 6)
               m_currentFrame.x = 1;
         }
         else{
            if(m_currentFrame.x > 5)
               m_currentFrame.x = 0;
         }
      }
   }
   this->CaculaRect();
   this->ApplyRect();
}

void DuckG::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
   target.draw(m_duck);
}