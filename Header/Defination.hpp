#pragma once

#define SCREEN_WIDTH 768
#define SCREEN_HEIGHT 700

#define SPLASH_STATE_SHOW_TIME 3.0 // how long splash screen is gonna be before going to main menu

#define SPLASH_SCENE_BACKGROUND_FILEPATH "C:\\Users\\matlo\\Desktop\\Code23\\IamBack\\Resources\\res\\Splash Background.png"
#define MAIN_MENU_BACKGROUND_FILEPATH "C:\\Users\\matlo\\Desktop\\Code23\\IamBack\\Resources\\res\\sky.png"
#define GAME_TITLE_FILEPATH "C:\\Users\\matlo\\Desktop\\Code23\\IamBack\\Resources\\res\\title.png"
#define PLAY_BUTTON_FILEPATH "C:\\Users\\matlo\\Desktop\\Code23\\IamBack\\Resources\\res\\PlayButton.png"

#define GAME_BACKGROUND_FILEPATH "C:\\Users\\matlo\\Desktop\\Code23\\IamBack\\Resources\\res\\sky.png"
#define GAME_OVER_BACKGROUND_FILEPATH "C:\\Users\\matlo\\Desktop\\Code23\\IamBack\\Resources\\res\\sky.png"

#define PIPE_DOWN_FILEPATH "C:\\Users\\matlo\\Desktop\\Code23\\IamBack\\Resources\\res\\PipeDown.png"
#define PIPE_UP_FILEPATH "C:\\Users\\matlo\\Desktop\\Code23\\IamBack\\Resources\\res\\PipeUp.png"

#define LAND_FILEPATH "C:\\Users\\matlo\\Desktop\\Code23\\IamBack\\Resources\\res\\land.png"

#define BIRD_FRAME_1_FILEPATH "C:\\Users\\matlo\\Desktop\\Code23\\IamBack\\Resources\\res\\bird-01.png"
#define BIRD_FRAME_2_FILEPATH "C:\\Users\\matlo\\Desktop\\Code23\\IamBack\\Resources\\res\\bird-02.png"
#define BIRD_FRAME_3_FILEPATH "C:\\Users\\matlo\\Desktop\\Code23\\IamBack\\Resources\\res\\bird-03.png"
#define BIRD_FRAME_4_FILEPATH "C:\\Users\\matlo\\Desktop\\Code23\\IamBack\\Resources\\res\\bird-04.png"

#define SCORRING_PIPE_FILEPATH "C:\\Users\\matlo\\Desktop\\Code23\\IamBack\\Resources\\res\\InvisibleScoringPipe.png"
#define FLAPPY_FONT_FILEPATH "C:\\Users\\matlo\\Desktop\\Code23\\IamBack\\Resources\\fonts\\FlappyFont.ttf"
#define GAME_OVERTITLE_FILEPATH "C:\\Users\\matlo\\Desktop\\Code23\\IamBack\\Resources\\res\\Game-Over-Title.png"
#define GAME_OVERBODY_FILEPATH "C:\\Users\\matlo\\Desktop\\Code23\\IamBack\\Resources\\res\\Game-Over-Body.png"
#define HIGHSCORE_FILEPATH "C:\\Users\\matlo\\Desktop\\Code23\\IamBack\\Src\\SavingHighScore.txt"

#define PIPE_MOVEMENT_SPEED 200.0f
#define PIPE_SPAWN_FREQUENCY 3.0f

#define BIRD_ANIMATION_DURATION 0.40f

#define BIRD_STATE_STILL 1
#define BIRD_STATE_FALLING 2
#define BIRD_STATE_FLYING 3

#define GRAVITY 350.0f
#define FLYING_SPEED 350.0f
#define FLYING_DURATION 0.250f
#define ROTATING_SPEED 100.0f

#define FLASH_SPEED 1500.0f
#define TIME_BEFORE_GAMEOVER_APPEARS 1.5f
enum GAME_STATES
{
    eReady,
    ePlaying,
    eGameOver
};