#ifndef DUCKGRAVITY_HPP
#define DUCKGRAVITY_HPP

#include"CommonFunc.hpp"
#include"HitBox.hpp"

class DuckG : public sf::Drawable
{
private:
    sf::Sprite m_duck;
    sf::Vector2i m_currentFrame;
    sf::Vector2i m_rectUV;
    sf::IntRect m_rect;

    HitBox* m_hitbox;

    bool m_rightleft;
    bool m_intStart;
    bool m_corner;

    void CaculaRect();
    void ApplyRect();
public:
    DuckG();
    ~DuckG();

    void Init(const sf::Texture &texture);
    void InitStart();
    void InitPosition(const sf::Vector2f& pos);
    sf::Vector2f GetPosition() const;
    
    bool GetStart() const;
    void SetStart(const bool start);
    void Rotation(const float &corner);
    bool CheckCollision(const HitBox* hitbox)const;
    void Move(const sf::Vector2f& direction);
    void Update();

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
};

#endif //DUCKGRAVITY_HPP