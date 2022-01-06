#include "MenuMap.hpp"
#include "GamePlay.hpp"
#include<fstream>

MenuMap::MenuMap(std::shared_ptr<Context> &context)
    : m_context(context), m_isPlayButtonSelected(true),
      m_isPlayButtonPressed(false),
      m_currentTime(sf::Time::Zero)
{
    
}

MenuMap::~MenuMap()
{
}

void MenuMap::Init()
{
    //Init value
    this->m_passLv = 1;
    this->m_sizeNum = 1;
    this->m_activeLV = 1;

    //background
    m_backGround1.setTexture(m_context->m_assets->GetTexture(M_TEXTURE_BG));
    m_backGround1.setPosition(sf::Vector2f(0, 0));
    m_backGround2.setTexture(m_context->m_assets->GetTexture(M_TEXTURE_BG));
    m_backGround2.setPosition(sf::Vector2f(-1280,0));

    //Mainground
    m_mainGround.setTexture(m_context->m_assets->GetTexture(L_TEXTURE_MAIN));
    m_mainGround.setPosition(sf::Vector2f(86,32));

    //Init Num and active level
    this->InitPassLevel();
    this->InitNumLevel();
}

void MenuMap::InitPassLevel()
{
    std::fstream input; int pass;
	input.open("./Datas/Texts/level.txt", std::ios::in);
    input >> pass;
    input.close();
    m_passLv = pass;
    if(m_passLv <10)
        m_sizeNum = m_passLv;
    else
        m_sizeNum = ((m_passLv - 9) *2) + 9;
}

void MenuMap::InitNumLevel()
{
    float x = 154.f, y = 184.f;
    int index = 0;

    //Init level pass
    for(auto &pass: m_passLevel)
    {
        pass.setTexture(m_context->m_assets->GetTexture(L_TEXTURE_PASS));
    }
    
    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 8; j++)
        {
            m_passLevel[index].setPosition(sf::Vector2f(x + (42* j), y + (42*i)));
            index++;
        }
    }

    //Init active level
    m_activeLevel.setTexture(m_context->m_assets->GetTexture(L_TEXTURE_ACTION));
    m_activeLevel.setPosition(sf::Vector2f(x,y));

    //Init Num pass level
    int Pos[][4] = {
        {0, 0, 8, 8},
        {8, 0, 3, 8},
        {11, 0, 8, 8},
        {19, 0, 8, 8},
        {27, 0, 8, 8},
        {35, 0, 8, 8},
        {43, 0, 8, 8},
        {51, 0, 8, 8},
        {59, 0, 8, 8},
        {67, 0, 8, 8}};
    x += 16.f; y += 16.f; 

    for(auto &num: m_numLevel)
    {
        num.setTexture(m_context->m_assets->GetTexture(L_TEXTURE_NUM));
    }

    index = 0;
    //Set number on level
    for(int i = 0; i< 71; i++)
    {
        if(index < 8)
        {
            m_numLevel[i].setTextureRect(sf::IntRect(sf::Vector2i(Pos[index%10 +1][0],Pos[index%10 +1][1]),sf::Vector2i(Pos[index%10 +1][2],Pos[index%10 +1][3])));
            m_numLevel[i].setPosition(sf::Vector2f(x + (42*(index%10)), y ));
            index++;
        }
        else if(index > 7 && index < 16)
        {
            index++;
            if(index < 10)
            {
                m_numLevel[i].setTextureRect(sf::IntRect(sf::Vector2i(Pos[index%10][0],Pos[index%10][1]),sf::Vector2i(Pos[index%10][2],Pos[index%10][3])));
                m_numLevel[i].setPosition(sf::Vector2f(x, 242 ));
            }
            else
            {
                m_numLevel[i].setTextureRect(sf::IntRect(sf::Vector2i(Pos[1][0],Pos[1][1]),sf::Vector2i(Pos[1][2],Pos[1][3])));
                m_numLevel[i].setPosition(sf::Vector2f((x + (42*(index%10 +1))) - 2, 242));
                i++;
                m_numLevel[i].setTextureRect(sf::IntRect(sf::Vector2i(Pos[index%10][0],Pos[index%10][1]),sf::Vector2i(Pos[index%10][2],Pos[index%10][3])));
                m_numLevel[i].setPosition(sf::Vector2f((x + (42*(index%10 + 1))) + 3, 242));
            }
        }
        else if(index > 15 && index < 24)
        { 
            index++;
            if(index < 20)
            {
                m_numLevel[i].setTextureRect(sf::IntRect(sf::Vector2i(Pos[1][0],Pos[1][1]),sf::Vector2i(Pos[1][2],Pos[1][3])));
                m_numLevel[i].setPosition(sf::Vector2f((x + (42*((index%10) -7 ))) - 2, 284));
                i++;
                m_numLevel[i].setTextureRect(sf::IntRect(sf::Vector2i(Pos[index%10][0],Pos[index%10][1]),sf::Vector2i(Pos[index%10][2],Pos[index%10][3])));
                m_numLevel[i].setPosition(sf::Vector2f((x + (42*((index%10) -7))) + 3, 284));
            }
            else
            {
                m_numLevel[i].setTextureRect(sf::IntRect(sf::Vector2i(Pos[2][0],Pos[2][1]),sf::Vector2i(Pos[2][2],Pos[2][3])));
                m_numLevel[i].setPosition(sf::Vector2f((x + (42*((index%10) +3))) - 4, 284));
                i++;
                m_numLevel[i].setTextureRect(sf::IntRect(sf::Vector2i(Pos[index%10][0],Pos[index%10][1]),sf::Vector2i(Pos[index%10][2],Pos[index%10][3])));
                m_numLevel[i].setPosition(sf::Vector2f((x + (42*((index%10) +3))) + 4, 284));
            }
            
        }
        else if(index > 23 && index < 32)
        { 
             index++;
            if(index < 30)
            {
                m_numLevel[i].setTextureRect(sf::IntRect(sf::Vector2i(Pos[2][0],Pos[2][1]),sf::Vector2i(Pos[2][2],Pos[2][3])));
                m_numLevel[i].setPosition(sf::Vector2f((x + (42*((index%10) -5))) - 4, (y + 126)));
                i++;
                m_numLevel[i].setTextureRect(sf::IntRect(sf::Vector2i(Pos[index%10][0],Pos[index%10][1]),sf::Vector2i(Pos[index%10][2],Pos[index%10][3])));
                m_numLevel[i].setPosition(sf::Vector2f((x + (42*((index%10) -5))) + 4, (y + 126)));
            }
            else
            {
                m_numLevel[i].setTextureRect(sf::IntRect(sf::Vector2i(Pos[3][0],Pos[3][1]),sf::Vector2i(Pos[3][2],Pos[3][3])));
                m_numLevel[i].setPosition(sf::Vector2f((x + (42*((index%10) +5))) - 4, (y + 126)));
                i++;
                m_numLevel[i].setTextureRect(sf::IntRect(sf::Vector2i(Pos[index%10][0],Pos[index%10][1]),sf::Vector2i(Pos[index%10][2],Pos[index%10][3])));
                m_numLevel[i].setPosition(sf::Vector2f((x + (42*((index%10) +5))) + 4, (y + 126)));
            }
           
        }
        else if(index > 31)
        {
            index++;
            if(index < 40)
            {
                m_numLevel[i].setTextureRect(sf::IntRect(sf::Vector2i(Pos[3][0],Pos[3][1]),sf::Vector2i(Pos[3][2],Pos[3][3])));
                m_numLevel[i].setPosition(sf::Vector2f((x + (42*((index%10) -3))) - 4, (y + 168)));
                i++;
                m_numLevel[i].setTextureRect(sf::IntRect(sf::Vector2i(Pos[index%10][0],Pos[index%10][1]),sf::Vector2i(Pos[index%10][2],Pos[index%10][3])));
                m_numLevel[i].setPosition(sf::Vector2f((x + (42*((index%10) -3))) + 4, (y + 168)));
            }
            if(index > 39)
            {
                m_numLevel[i].setTextureRect(sf::IntRect(sf::Vector2i(Pos[4][0],Pos[4][1]),sf::Vector2i(Pos[4][2],Pos[4][3])));
                m_numLevel[i].setPosition(sf::Vector2f((x + (42*7)) - 4, (y + 168)));
                i++;
                m_numLevel[i].setTextureRect(sf::IntRect(sf::Vector2i(Pos[index%10][0],Pos[index%10][1]),sf::Vector2i(Pos[index%10][2],Pos[index%10][3])));
                m_numLevel[i].setPosition(sf::Vector2f((x + (42*7)) + 4, (y + 168)));
            }
            
        }
    }
}

void MenuMap::CaculaterActive()
{
    if(m_activeLV < 9)
    {
        m_active.y = 0;
        m_active.x = m_activeLV -1;
    }
    if(m_activeLV > 8 && m_activeLV < 17)
    {
        m_active.y = 1;
        m_active.x = m_activeLV - 9;
    }
    if(m_activeLV > 16 && m_activeLV < 25)
    {
        m_active.y = 2;
        m_active.x = m_activeLV - 17;
    }
    if(m_activeLV > 24 && m_activeLV < 33)
    {
        m_active.y = 3;
        m_active.x = m_activeLV - 25;
    }
    if(m_activeLV > 32)
    {
        m_active.y = 4;
        m_active.x = m_activeLV - 33;
    }
}

void MenuMap::ProcessInput()
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
                if(m_active.y == 0 && m_passLv > 32)
                    m_activeLV += 32;
                if(m_active.y > 0 )
                    m_activeLV -= 8;
                this->CaculaterActive();
                break;
            case sf::Keyboard::Down:
                if(m_active.y == 4)
                    m_activeLV -= 32 ;
                if(m_active.y < 4 && (m_activeLV + 8) <= m_passLv)
                    m_activeLV += 8;
                this->CaculaterActive();
                break;
            case sf::Keyboard::Left:
                if(m_activeLV == 1 && m_passLv != 1)
                    m_activeLV = m_passLv;
                else if(m_activeLV > 1)
                    m_activeLV--;
                this->CaculaterActive();
                break;
            case sf::Keyboard::Right:
                if(m_activeLV == m_passLv)
                    m_activeLV = 1;
                else if(m_activeLV < m_passLv)
                    m_activeLV++;
                this->CaculaterActive();
                break;
            case sf::Keyboard::Return:
                m_isPlayButtonPressed = false;
                
                if (m_isPlayButtonSelected)
                {
                    m_isPlayButtonPressed = true;

                    std::fstream output;
                    output.open("./Datas/Texts/level.txt", std::ios::out);
                    output << m_passLv;
                    output << " ";
                    output << m_activeLV;
                    output.close();
                }
                break;
            case sf::Keyboard::Escape:
                m_context->m_states->PopCurrent();
                break;
            default:
                break;
            }
        }
    }
}

void MenuMap::Update(sf::Time deltaTime)
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

        //Set picture active level
        m_activeLevel.setPosition(sf::Vector2f(154 + (m_active.x*42),184 + (m_active.y*42)));

        m_currentTime = sf::Time::Zero;
    }

    if(m_isPlayButtonPressed)
    {
        m_context->m_states->Add(std::make_unique<GamePlay>(m_context), true);
    }    
}

void MenuMap::Draw()
{
    m_context->m_window->clear();
    m_context->m_window->draw(m_backGround1);
    m_context->m_window->draw(m_backGround2);
    m_context->m_window->draw(m_mainGround);

    for(int i = 0; i< m_passLv; i++)
    {
        m_context->m_window->draw(m_passLevel[i]);
    }
    m_context->m_window->draw(m_activeLevel);
    for(int i = 0; i< m_sizeNum; i++)
    {
        m_context->m_window->draw(m_numLevel[i]);
    }
    m_context->m_window->display();
}

void MenuMap::Start()
{
    m_isPlayButtonPressed = false;
    m_isPlayButtonSelected = true;
}