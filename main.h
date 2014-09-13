#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>


#define WIN_W 800
#define WIN_H 600
#define TRUE 1
#define FALSE 0

#define w_DB 0 
#define wout_DB  1
#define int_on 2
#define int_off 3
#define submit 4
#define fields 5



#define colour_bg 0x000000
#define colour  0x808080



typedef char bool;


typedef struct _menu_app *menu_app;
typedef struct _bouton *bouton;
typedef struct _field *field;

struct _bouton {

  int x1;
  int y1;
  int w;
  int h;
  int bouton_number;
  char * name;
  int Wttf;
  int Httf;
  char * texte;
  /*  fun_click click;*/


    };

struct _field {
  int x1;
  int y1;
  int w;
  int h;
  char *phone;
  int bouton_number;



};
 

struct _menu_app {

SDL_Surface* display;
bouton* screen;
char* select;
int nb_bouton_on;


};

void ligneHorizontale(int x, int y, int w, Uint32 coul, menu_app GLOBAL);

void ligneVerticale(int x, int y, int h, Uint32 coul,menu_app GLOBAL);

void rectangle(int x, int y, int w, int h, Uint32 coul, menu_app GLOBAL);

void FillRect(int x, int y, int w, int h, int color, menu_app GLOBAL);

bouton draw_button (int x, int y, int w, int h, menu_app GLOBAL, char * b_name, int bouton_number,  int win_wttf, int win_httf);

void init_app();

void texte (int x, int y, char *txt, menu_app GLOBAL);

void app_main_loop (menu_app GLOBAL);

void event_button_do (SDL_MouseButtonEvent b,int up_or_down, menu_app GLOBAL);

bouton find_click_button(int x,  int y, menu_app GLOBAL);

void app_end (menu_app GLOBAL);

void push_button (bouton com,   menu_app GLOBAL);

void verif (bouton com, menu_app GLOBAL);

bouton draw_field (int x, int y, int w, int h, char * b_name,  menu_app GLOBAL,int bouton_number);

void event_key_do (char key, menu_app GLOBAL);
