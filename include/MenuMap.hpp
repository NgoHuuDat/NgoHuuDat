#ifndef MENUMAP_HPP
#define MENUMAP_HPP

#include"CommonFunc.hpp"
#include "State.hpp"
#include "Game.hpp"

class MenuMap : public Engine::State
{
private:
    std::shared_ptr<Context> m_context;
    sf::Sprite m_backGround1;
    sf::Sprite m_backGround2;
    sf::Sprite m_mainGround;
    sf::Sprite m_activeLevel;
    std::array<sf::Sprite, 40> m_passLevel;
    std::array<sf::Sprite, 71> m_numLevel;

    bool m_isPlayButtonSelected;
    bool m_isPlayButtonPressed;

    int m_passLv, m_sizeNum;
    int m_activeLV;
    sf::Vector2i m_active; 

    sf::Time m_currentTime;

    void InitNumLevel();
    void InitPassLevel();
    void CaculaterActive();

public:
    MenuMap(std::shared_ptr<Context> &context);
    ~MenuMap();

    void Init() override;
    void ProcessInput() override;
    void Update(sf::Time deltaTime) override;
    void Draw() override;
    void Start() override;
};

#endif //MENUMAP_HPP