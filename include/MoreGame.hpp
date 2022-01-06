#ifndef MOREGAME_HPP
#define MOREGAME_HPP

#include"CommonFunc.hpp"
#include "Game.hpp"
#include "State.hpp"

class MoreGame : public Engine::State
{
private:
    std::shared_ptr<Context> m_context;
    sf::Text m_pauseTitle;

    sf::Time m_currentTime;

public:
    MoreGame(std::shared_ptr<Context> &context);
    ~MoreGame();

    void Init() override;
    void ProcessInput() override;
    void Update(sf::Time deltaTime) override;
    void Draw() override;
};

#endif //MOREGAME_HPP