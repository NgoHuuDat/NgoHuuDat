#ifndef MAINMENU_HPP
#define MAINMENU_HPP

#include"CommonFunc.hpp"
#include "State.hpp"
#include "Game.hpp"

class MainMenu : public Engine::State
{
private:
    std::shared_ptr<Context> m_context;
    sf::Sprite m_playButton;
    sf::Sprite m_moreButton;
    sf::Sprite m_backGround1;
    sf::Sprite m_backGround2;
    sf::Sprite m_mainGround;

    bool m_isPlayButtonSelected;
    bool m_isPlayButtonPressed;

    bool m_isMoreButtonSelected;
    bool m_isMoreButtonPressed;

    sf::Time m_currentTime;

public:
    MainMenu(std::shared_ptr<Context> &context);
    ~MainMenu();

    void Init() override;
    void ProcessInput() override;
    void Update(sf::Time deltaTime) override;
    void Draw() override;
    void Start() override;
};

#endif //MAINMENU_HPP