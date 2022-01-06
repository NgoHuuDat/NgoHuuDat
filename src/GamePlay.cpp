#include "GamePlay.hpp"
#include "GameOver.hpp"
#include "PauseGame.hpp"

#include<fstream>
#include<iostream>

GamePlay::GamePlay(std::shared_ptr<Context> &context)
    : m_context(context),
      m_elapsedTime(sf::Time::Zero)
{
    srand(time(nullptr));
}

GamePlay::~GamePlay()
{
    if(m_duck != nullptr)
        delete m_duck;
    if(m_egg != nullptr)
        delete m_egg;
    if(m_textLevel != nullptr)
        delete m_textLevel;
}

void GamePlay::Init()
{
    //Set defaul
    m_posDest = sf::Vector2f(0,0);
    m_posInit = sf::Vector2f(0,0);
    m_isPaused = false;
    m_nextMap = false;
    m_start = true;
    m_rotation = true;

    m_background.setTexture(m_context->m_assets->GetTexture(G_TEXTURE_BG));

    m_egg = new sf::Sprite();
    m_egg->setTexture(m_context->m_assets->GetTexture(G_TEXTURE_EGG));
    m_egg->setTextureRect(sf::IntRect(sf::Vector2i(0,0),sf::Vector2i(TILE_SIZE,TILE_SIZE)));
    
    for (auto &map : m_mapTitle)
    {
        map.setTexture(m_context->m_assets->GetTexture(G_TEXTURE_TITLE));
    }

    //Importmap
    this->ImportMap();

   
    m_textLevel = new sf::Text();
    m_textLevel->setFont(m_context->m_assets->GetFont(MAIN_FONT));
    m_textLevel->setPosition(sf::Vector2f(10,10));
    std::string m_temp = "level: " + std::to_string(m_level);
    m_textLevel->setString(m_temp);
    m_textLevel->setCharacterSize(20);

    // //Import Player
    m_duck = new DuckG();
    m_duck->Init(m_context->m_assets->GetTexture(G_TEXTURE_DUCK));
    m_duck->InitPosition(m_posInit);
}

void GamePlay::ImportMap()
{
    int level, pass, index = 0, counter = 0; 
    std::fstream input;
	input.open("./Datas/Texts/level.txt", std::ios::in);
    input >> pass;
    input >> level;
    input.close();
    m_level = level;
    std::string m_namePath = std::to_string(level); 
    input.open("./Datas/Maps/" + m_namePath +".txt", std::ios::in);

    while (!input.eof())
    {
        if(counter == 6)
        {
            for (int i = 0; i < 15; i++)
            {
                for (int j = 0; j < 20; j++)
                {
                    input >> level;
                    if(level != -1)
                    {
                        m_mapTitle[index].setTextureRect(sf::IntRect(sf::Vector2i((level %11) * TILE_SIZE, (level /11) *TILE_SIZE),sf::Vector2i(TILE_SIZE,TILE_SIZE)));
                        m_mapTitle[index].setPosition(sf::Vector2f(j* TILE_SIZE, i *TILE_SIZE));
                        index++;
                        switch (level)
                        {
                        case 36:
                            m_egg->setPosition(sf::Vector2f((j + 1)*TILE_SIZE, (i + 2)* TILE_SIZE));
                            m_egg->setRotation(180.f);
                            break;
                        case 37:
                            m_egg->setPosition(sf::Vector2f((j - 1)*TILE_SIZE, (i + 1)* TILE_SIZE));
                            m_egg->setRotation(270.f);
                            break;
                        case 38:
                            m_egg->setPosition(sf::Vector2f(j*TILE_SIZE, (i - 1)* TILE_SIZE));
                            m_egg->setRotation(0.f);
                            break;
                        case 39:
                            m_egg->setPosition(sf::Vector2f((j + 1 )*TILE_SIZE, (i + 1)* TILE_SIZE));
                            m_egg->setRotation(90.f);
                            break;
                        default:
                            break;
                        }
                    }
                }
            }
            
        }
        else if(counter < 3)
        {
            input >> level;
            switch (counter)
            {
            case 0:
                m_posInit.x = level * TILE_SIZE + 16;
                break;
            case 1:
                m_posInit.y = level * TILE_SIZE + 16;
                break;
            default:
                
                break;
            }
        }
        else if(counter > 2 && counter < 6)
        {
            input >> level;
            switch (counter)
            {
            case 3:
                m_posDest.x = level* TILE_SIZE;
                break;
            case 4:
                m_posDest.y = (14 - level)* TILE_SIZE;
                break;
            default:
               
                break;
            }
        }
        else if(counter > 6)
        {
            input >> level;
            switch (counter)
            {
            case 7:
               
                break;
            default:
               
                break;
            }
        }

        counter++;
    }

    m_sizeMap = index;
    input.close();
}

void GamePlay::NextLevel()
{
    int pass;
    m_level++;
    if(m_level < 41)
    {
        std::fstream input;
        input.open("./Datas/Texts/level.txt", std::ios::in);
        input >> pass;
        input.close();
        
        if(m_level > pass)
        {
            input.open("./Datas/Texts/level.txt", std::ios::out);
            input << m_level;
            input << " ";
            input << m_level;
            input.close();
        }
        else
        {
            input.open("./Datas/Texts/level.txt", std::ios::out);
            input << pass;
            input << " ";
            input << m_level;
            input.close();
        }

        //Import text level
        std::string m_temp = "level: " +std::to_string(m_level);
        m_textLevel->setString(m_temp);

        //Importmap
        this->ImportMap();

        //Import Player
        m_duck->InitPosition(m_posInit);
    }
}

void GamePlay::ProcessInput()
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
                if(!m_start)
                {

                }
                break;
            case sf::Keyboard::Down:
                if(!m_start)
                {
                    
                }
                break;
            case sf::Keyboard::Left:
                if(!m_start)
                {
                    m_duck->Move(sf::Vector2f(-7.f,0));
                }
                break;
            case sf::Keyboard::Right:
                if(!m_start)
                {
                    m_duck->Move(sf::Vector2f(7.f,0));
                }
                break;
            case sf::Keyboard::Space:
                if(!m_start)
                {   
                    if(m_rotation){
                        m_duck->Rotation(180.f);
                        m_rotation = false;
                    }
                    else{
                        m_duck->Rotation(0.f);
                        m_rotation = true;
                    }
                }
                break;
            case sf::Keyboard::Escape:
                m_context->m_states->Add(std::make_unique<PauseGame>(m_context));
                break;

            default:
                break;
            }
        }
    }
}

void GamePlay::Update(sf::Time deltaTime)
{
    if(!m_isPaused)
    {
        m_elapsedTime += deltaTime;

        if (m_elapsedTime.asSeconds() > 0.1)
        {
            if (m_start)
            {
                m_duck->InitStart();
                m_start = m_duck->GetStart();
            }
            else
                m_duck->Update();

            if(m_duck->GetPosition().x >= m_posDest.x - 16)
            {
                m_nextMap = true;
                m_start = true;
                m_duck->SetStart(true);
            }
            if(m_nextMap)
            {
                m_nextMap = false;
                this->NextLevel();
            }
            m_elapsedTime = sf::Time::Zero;
        }

    }
}

void GamePlay::Draw()
{
    m_context->m_window->clear();
    m_context->m_window->draw(m_background);
    for(int i = 0; i< m_sizeMap; i++)
        m_context->m_window->draw(m_mapTitle[i]);
    m_context->m_window->draw(*m_egg);
    m_context->m_window->draw(*m_textLevel);
    m_context->m_window->draw(*m_duck);
    m_context->m_window->display();
}

void GamePlay::Pause()
{
    m_isPaused = true;
}

void GamePlay::Start()
{
    m_isPaused = false;
}