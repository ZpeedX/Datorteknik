/* mipslabdata.c
   This file compiled 2015 by F Lundevall
   from original code written by Axel Isaksson

   For copyright and licensing, see file COPYING */

#include <stdint.h>   /* Declarations of uint_32 and the like */
#include <pic32mx.h>  /* Declarations of system-specific addresses etc */
#include "mipslab.h"  /* Declatations for these labs */

#define dLengthEnd (80)
#define dGlobalPage (2)
#define dLengthStart (60)

char snake[4][128];
int lengthEnd = dLengthEnd;
int lengthStart = dLengthStart;
int globalPage = dGlobalPage;
int snakeLength = dLengthEnd - dLengthStart;
int buttonStatus = 1;
int snakeTail[512];

int column;
int page;
int pixel;
int apple;
int score;
int prevButtonStatus = 0;
int prevButtonStatus1 = 0;

int snakeHead = 8 * (dLengthEnd + (dGlobalPage * 128));
char icon[] = {
    255, 1, 1, 1, 1, 1, 1, 1, 
    1, 1, 1, 1, 1, 1, 1, 1, 
    1, 1, 1, 1, 1, 1, 1, 1, 
    1, 1, 1, 1, 1, 1, 1, 1, 
    1, 1, 1, 1, 1, 1, 1, 1, 
    1, 1, 1, 1, 1, 1, 1, 1, 
    1, 1, 1, 1, 1, 1, 1, 1, 
    1, 1, 1, 1, 1, 1, 1, 1, 
    1, 1, 1, 1, 1, 1, 1, 1, 
    1, 1, 1, 1, 1, 1, 1, 1, 
    1, 1, 1, 1, 1, 1, 1, 1, 
    1, 1, 1, 1, 1, 1, 1, 1, 
    1, 1, 1, 1, 1, 1, 1, 1, 
    1, 1, 1, 1, 1, 1, 1, 1, 
    1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 255,
    255, 0, 0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 0, 255,
    255, 0, 0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 0, 255,
    255, 128, 128, 128, 128, 128, 128, 128, 
    128, 128, 128, 128, 128, 128, 128, 128, 
    128, 128, 128, 128, 128, 128, 128, 128,
    128, 128, 128, 128, 128, 128, 128, 128, 
    128, 128, 128, 128, 128, 128, 128, 128, 
    128, 128, 128, 128, 128, 128, 128, 128, 
    128, 128, 128, 128, 128, 128, 128, 128, 
    128, 128, 128, 128, 128, 128, 128, 128, 
    128, 128, 128, 128, 128, 128, 128, 128, 
    128, 128, 128, 128, 128, 128, 128, 128, 
    128, 128, 128, 128, 128, 128, 128, 128, 
    128, 128, 128, 128, 128, 128, 128, 128, 
    128, 128, 128, 128, 128, 128, 128, 128, 
    128, 128, 128, 128, 128, 128, 128, 128, 
    128, 128, 128, 128, 128, 128, 128, 128, 
    128, 128, 128, 128, 128, 128, 128, 255,
};