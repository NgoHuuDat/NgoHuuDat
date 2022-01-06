#ifndef COMMONFUNC_HPP
#define COMMONFUNC_HPP

#include <memory>
#include <stack>
#include <list>
#include <array>
#include <map>
#include <string>
#include <stdlib.h>
#include <time.h>

#include<SFML/Graphics.hpp>
#include<SFML/Window.hpp>
#include<SFML/Audio.hpp>
#include<SFML/Config.hpp>

#define WIDTH 640
#define HEIGHT 480
#define TITLE "CORNMOON"

#define MAX_X 24
#define MAX_Y 19
#define MAX_X_NO_PADDING 22
#define MAX_Y_NO_PADDING 17

#define PADDING_START_X 64.0f
#define PADDING_START_Y 64.0f
#define PADDING_FULL_X 704.0f
#define PADDING_FULL_Y 544.0f

#define RADIAN 57.2958f

#define GRAVITY 0.65f
#define MAX_VELOCITY 13.0f

#define MENU_BG_MAX_OFFSET 1280

#define PLAYER_SIZE 16

#define TILE_SIZE 32
#define TILE_SIZE_HALF 16
#define TILE_MAX 44

#define SWITCH_MAX 10
#define SWITCH_SIZE 20

#define BTN_LVL_START_INIT_X 67
#define BTN_LVL_START_INIT_Y 224
#define BTN_LVL_START_X 153
#define BTN_LVL_START_Y 256
#define BTN_LVL_SIZE 40
#define BTN_LVL_SIZE_FULL 42
#define BTN_LVL_MAX 41 // 40 + 1 (Level start at 1)
#define BTN_LVL_MAX_REAL 40
#define BTN_LVL_MAX_PER_ROW 8

#define ENEMY_MAX 25

#define BULLET_FLY_CHASE_OFFSET 3.0f

#endif