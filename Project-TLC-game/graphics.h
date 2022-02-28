#ifndef GRAPHICS
#define GRAPHICS

/* mipslab.h
   Header file for all labs.
   This file written 2015 by F Lundevall
   Some parts are original code written by Axel Isaksson

   Latest update 2015-08-28 by F Lundevall

   For copyright and licensing, see file COPYING */

/* Declare display-related functions from mipslabfunc.c */
void display_image(int x, const uint8_t *data);
void display_init(void);
void display_string(int line, char *s);

void display_update(void);
uint8_t spi_send_recv(uint8_t data);

/* Declare lab-related functions from mipslabfunc.c */
char *itoaconv( int num );
void labwork(void);
void quicksleep(int cyc);
void tick( unsigned int * timep );

/* Declare display_debug - a function to help debugging.

   After calling display_debug,
   the two middle lines of the display show
   an address and its current contents.

   There's one parameter: the address to read and display.

   Note: When you use this function, you should comment out any
   repeated calls to display_image; display_image overwrites
   about half of the digits shown by display_debug.
*/
void display_debug( volatile int * const addr );

/* Declare bitmap array containing font */
extern const uint8_t const font[128*8];
/* Declare bitmap array containing icon */
extern const uint8_t const icon[128];
/* Declare text buffer for display output */
extern char textbuffer[4][16];

/* Declare functions written by students.
   Note: Since we declare these functions here,
   students must define their functions with the exact types
   specified in the laboratory instructions. */

//texture
extern const uint8_t const arrow1[128];
extern const uint8_t const arrow2[128];
extern const uint8_t const arrow3[128];
extern const uint8_t const arrow4[128];
extern uint8_t dino1[128];
extern const uint8_t const ground[128];



extern const uint8_t const ground[128];
/* Written as part of asm lab: delay, time2string */
void delay(int);
void time2string( char *, int );
/* Written as part of i/o lab: getbtns, getsw, enable_interrupt */

//io.h
int getbtns(void);
int getsw(void);

char btn_right();
char btn_p();
char btn_left();

//interrupts
void enable_interrupt(void);

//score.h
typedef struct Score{
    char name[3];
    int points;
    char position; 

} Score;

extern struct Score score_list[32];

char print_score();
void init_highscore_list();
void delete_score_list();
void update_list();
void show_score();

#endif
