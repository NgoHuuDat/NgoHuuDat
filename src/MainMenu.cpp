#include "MainMenu.hpp"
#include"MenuMap.hpp"
#include"MoreGame.hpp"


MainMenu::MainMenu(std::shared_ptr<Context> &context)
    : m_context(context), m_isPlayButtonSelected(true),
      m_isPlayButtonPressed(false), m_isMoreButtonSelected(false),
      m_isMoreButtonPressed(false)
{
    this->m_currentTime = sf::Time::Zero;
}

MainMenu::~MainMenu()
{
}

void MainMenu::Init()
{
    //background
    m_backGround1.setTexture(m_context->m_assets->GetTexture(M_TEXTURE_BG));
    m_backGround1.setPosition(sf::Vector2f(0, 0));
    m_backGround2.setTexture(m_context->m_assets->GetTexture(M_TEXTURE_BG));
    m_backGround2.setPosition(sf::Vector2f(-1280,0));

    //Mainground
    m_mainGround.setTexture(m_context->m_assets->GetTexture(M_TEXTURE_MAIN));
    m_mainGround.setPosition(sf::Vector2f(70,16));

    //Button Play
    m_playButton.setTexture(m_context->m_assets->GetTexture(M_TEXTURE_PLAY));
    m_playButton.setPosition(sf::Vector2f(190,272));

    //Button More
    m_moreButton.setTexture(m_context->m_assets->GetTexture(M_TEXTURE_MORE));
    m_moreButton.setPosition(sf::Vector2f(190,350));
}

void MainMenu::ProcessInput()
{
    sf::Event event;
    while (m_context->m_window->pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            m_context->m_window->close();
        }
        else if (event.type == sf::Event::KeyPressed)
        {
            switch (event.key.code)
            {
            case sf::Keyboard::Up:
                if (!m_isPlayButtonSelected)
                {
                    m_isPlayButtonSelected = true;
                    m_isMoreButtonSelected = false;
                }
                break;
            case sf::Keyboard::Down:
                if (!m_isMoreButtonSelected)
                {
                    m_isPlayButtonSelected = false;
                    m_isMoreButtonSelected = true;
                }
                break;
            case sf::Keyboard::Return:
                m_isPlayButtonPressed = false;
                m_isMoreButtonPressed = false;

                if (m_isPlayButtonSelected)
                {
                    m_isPlayButtonPressed = true;
                }
                else
                {
                    m_isMoreButtonPressed = true;
                }
                break;

            default:
                break;
            }
        }
    }
}

void MainMenu::Update(sf::Time deltaTime)
{
    this->m_currentTime += deltaTime;
    if(m_currentTime.asSeconds() > 0.1f)
    {
        m_backGround1.move(sf::Vector2f(5.f,0));
        m_backGround2.move(sf::Vector2f(5.f,0));

        if(m_backGround1.getPosition().x >= (float)(1280.f))
        {
            m_backGround1.setPosition(sf::Vector2f(-1280, 0));
        }
        if(m_backGround2.getPosition().x >= (float)(1280.f))
        {
            m_backGround2.setPosition(sf::Vector2f(-1280, 0));
        }
        m_currentTime = sf::Time::Zero;
    }

    if(m_isPlayButtonPressed)
    {
        m_context->m_states->Add(std::make_unique<MenuMap>(m_context));
    }
    else if(m_isMoreButtonPressed)
    {
         m_context->m_states->Add(std::make_unique<MoreGame>(m_context));
    }
    
}

void MainMenu::Draw()
{
    m_context->m_window->clear();  
    m_context->m_window->draw(m_backGround1);
    m_context->m_window->draw(m_backGround2);
    m_context->m_window->draw(m_mainGround);
    if(m_isPlayButtonSelected)
    {
        m_context->m_window->draw(m_playButton);
    }
    else
    {
        m_context->m_window->draw(m_moreButton);
    }  
    m_context->m_window->display();
}

void MainMenu::Start()
{
    m_isPlayButtonPressed = false;
    m_isMoreButtonPressed = false;
}