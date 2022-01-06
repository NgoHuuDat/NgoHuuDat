#ifndef PAUSEGAME_HPP
#define PAUSEGAME_HPP

#include"CommonFunc.hpp"
#include "State.hpp"
#include "Game.hpp"

class PauseGame : public Engine::State
{
private:
    std::shared_ptr<Context> m_context;
    sf::Text m_pauseTitle;

    sf::Time m_currentTime;

public:
    PauseGame(std::shared_ptr<Context> &context);
    ~PauseGame();

    void Init() override;
    void ProcessInput() override;
    void Update(sf::Time deltaTime) override;
    void Draw() override;
};

#endif //PAUSEGAME_HPP