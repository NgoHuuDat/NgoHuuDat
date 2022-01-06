#include <SFML/Graphics/CircleShape.hpp>

#include "Game.hpp"
#include "MainMenu.hpp"

Game::Game() : m_context(std::make_shared<Context>())
{
    m_context->m_window->create(sf::VideoMode(WIDTH, HEIGHT), TITLE, sf::Style::Close); 
    m_context->m_states->Add(std::make_unique<MainMenu>(m_context),true);
    
    m_context->m_assets->AddTexture(G_TEXTURE_TITLE, "./Datas/Images/Game/Tiles.png");
    m_context->m_assets->AddTexture(G_TEXTURE_BG, "./Datas/Images/Game/BG.png");
    m_context->m_assets->AddTexture(G_TEXTURE_DEADTH, "./Datas/Images/Game/Death.png");
    m_context->m_assets->AddTexture(G_TEXTURE_SW, "./Datas/Images/Game/Switch.png");
    m_context->m_assets->AddTexture(G_TEXTURE_EGG, "./Datas/Images/Game/Egg.png");
    m_context->m_assets->AddTexture(G_TEXTURE_DUCK, "./Datas/Images/Game/Player.png");
    m_context->m_assets->AddFont(MAIN_FONT, "./Datas/Fonts/Pacifico.ttf");
    m_context->m_assets->AddTexture(M_TEXTURE_BG,"./Datas/Images/Menu/BG.png");
    m_context->m_assets->AddTexture(M_TEXTURE_MAIN,"./Datas/Images/Menu/Main.png");
    m_context->m_assets->AddTexture(M_TEXTURE_PLAY,"./Datas/Images/Menu/Btn_Start_Game.png");
    m_context->m_assets->AddTexture(M_TEXTURE_MORE,"./Datas/Images/Menu/Btn_More_Game.png");
    
    m_context->m_assets->AddTexture(L_TEXTURE_MAIN,"./Datas/Images/Menu/Lvl.png");
    m_context->m_assets->AddTexture(L_TEXTURE_ACTION,"./Datas/Images/Menu/Btn_Lvl_Act.png");
    m_context->m_assets->AddTexture(L_TEXTURE_PASS,"./Datas/Images/Menu/Btn_Lvl_Pas.png");
    m_context->m_assets->AddTexture(L_TEXTURE_NUM,"./Datas/Images/Menu/Nums.png");
}

Game::~Game()
{
}

void Game::Run()
{
    sf::Clock clock;
    sf::Time timeSinceLastFrame = sf::Time::Zero;

    while (m_context->m_window->isOpen())
    {
        timeSinceLastFrame += clock.restart();

        while (timeSinceLastFrame > TIME_PER_FRAME)
        {
            timeSinceLastFrame -= TIME_PER_FRAME;

            m_context->m_states->ProcessStateChange();
            m_context->m_states->GetCurrent()->ProcessInput();
            m_context->m_states->GetCurrent()->Update(TIME_PER_FRAME);
            m_context->m_states->GetCurrent()->Draw();
        }
    }
}