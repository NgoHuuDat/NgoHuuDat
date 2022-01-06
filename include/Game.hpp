#ifndef GAME_HPP
#define GAME_HPP

#include"CommonFunc.hpp"
#include "AssetMan.hpp"
#include "StateMan.hpp"

enum AssetID
{
    MAIN_FONT = 0,
    M_TEXTURE_BG,
    M_TEXTURE_MAIN,
    M_TEXTURE_PLAY,
    M_TEXTURE_MORE,
    L_TEXTURE_MAIN,
    L_TEXTURE_ACTION,
    L_TEXTURE_PASS,
    L_TEXTURE_NUM,
    G_TEXTURE_TITLE,
    G_TEXTURE_BG,
    G_TEXTURE_DEADTH,
    G_TEXTURE_SW,
    G_TEXTURE_EGG,
    G_TEXTURE_DUCK,
    E_TEXTURE_BLOCK,
    E_TEXTURE_FLY,
    E_TEXTURE_SHOOTER,
    E_TEXTURE_WORM,
    E_TEXTURE_CHASE,
    E_TEXTURE_CRUSHER
};

struct Context
{
    std::unique_ptr<Engine::AssetMan> m_assets;
    std::unique_ptr<Engine::StateMan> m_states;
    std::unique_ptr<sf::RenderWindow> m_window;

    Context()
    {
        m_assets = std::make_unique<Engine::AssetMan>();
        m_states = std::make_unique<Engine::StateMan>();
        m_window = std::make_unique<sf::RenderWindow>();
    }
};

class Game
{
private:
    std::shared_ptr<Context> m_context;
    const sf::Time TIME_PER_FRAME = sf::seconds(1.f/60.f);

public:
    Game();
    ~Game();

    void Run();
};

#endif //GAME_HPP