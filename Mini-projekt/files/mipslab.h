/* mipslab.h
   Header file for all labs.
   This file written 2015 by F Lundevall
   Some parts are original code written by Axel Isaksson

   Latest update 2015-08-28 by F Lundevall

   For copyright and licensing, see file COPYING */

/* Declare display-related functions from mipslabfunc.c */
void display_init(void);
void display_update(void);
uint8_t spi_send_recv(uint8_t data);

/* Declare lab-related functions from mipslabfunc.c */
void labwork(void);
void quicksleep(int cyc);

/* Declare bitmap array containing font */
/* Declare bitmap array containing icon */
extern char icon[512];
/* Declare text buffer for display output */
extern char snake[4][128];

extern int lengthEnd;
extern int lengthStart;
extern int globalPage;
extern int buttonStatus;
extern int snakeHead;
extern int snakeTail[];
extern int snakeLength;
extern int column;
extern int page;
extern int pixel;
extern int apple;
extern int score;
extern int prevButtonStatus;
extern int prevButtonStatus1;
/* Declare functions written by students.
   Note: Since we declare these functions here,
   students must define their functions with the exact types
   specified in the laboratory instructions. */
/* Written as part of asm lab: delay, time2string */
void delay(int);
void time2string( char *, int );
/* Written as part of i/o lab: getbtns, getsw */
int getbtns(void);
int getsw(void);
