#ifndef GAMEPLAY_HPP
#define GAMEPLAY_HPP

#include"CommonFunc.hpp"
#include "Game.hpp"
#include "State.hpp"
#include "DuckGravity.hpp"
#include"HitBox.hpp"

class GamePlay : public Engine::State
{
private:
    std::shared_ptr<Context> m_context;
    sf::Sprite m_background;
    std::array<sf::Sprite, 250> m_mapTitle; 
    int m_sizeMap;

    sf::Time m_elapsedTime;
    bool m_isPaused;

    sf::Text* m_textLevel;

    DuckG *m_duck;
    sf::Vector2f m_posInit;
    sf::Vector2f m_posDest;
    sf::Sprite* m_egg;
    bool m_start, m_nextMap;
    bool m_collision, m_rotation;
    int m_level, m_count;

    void ImportMap();
    void NextLevel();
public:
    GamePlay(std::shared_ptr<Context> &context);
    ~GamePlay();

    void Init() override;
    void ProcessInput() override;
    void Update(sf::Time deltaTime) override;
    void Draw() override;
    void Pause() override;
    void Start() override;
};

#endif //GAMEPLAY_HPP