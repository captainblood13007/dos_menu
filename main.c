
#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>

#define WIN_W 640
#define WIN_H 480

SDL_Surface* affichage;
SDL_Surface* mypic;
SDL_Surface* texte;


void ligneHorizontale(int x, int y, int w, Uint32 coul);
void ligneVerticale(int x, int y, int h, Uint32 coul);
void rectangle(int x, int y, int w, int h, Uint32 coul);
void FillRect(int x, int y, int w, int h, int color);
void draw_button (int x, int y, int w, int h, Uint32 colour, Uint32 colour_bg);
void init_app();

void My_SDL_Init (void)
{
  if (SDL_Init (SDL_INIT_VIDEO) == -1)
    {
      fprintf (stderr, "Impossible d'initialiser la SDL.\n");
      exit (EXIT_FAILURE);
    }
  atexit (SDL_Quit);
}




int main (int argc, char *argv[])
{

  init_app();


  return 0;

}

void init_app()
 {


  TTF_Font *police = NULL;
  SDL_Rect position;

  My_SDL_Init ();
  TTF_Init();
  SDL_Color couleurJaune = {255,255,0};
  affichage = SDL_SetVideoMode (WIN_W, WIN_H, 32, SDL_HWSURFACE);
  if (affichage == NULL)
    {
      fprintf (stderr, "Impossible de sélectionner le mode vidéo choisi.\n");
      exit (EXIT_FAILURE);
    }



  if (affichage == NULL) {
    fprintf(stderr, "Impossible d'activer le mode graphique : %s\n", SDL_GetError());
    exit(EXIT_FAILURE);
  }


  SDL_WM_SetCaption("Technical support program (2014) - NT ", NULL);

    mypic = SDL_CreateRGBSurface(0, WIN_W, WIN_H, 32,
			       0xFF000000,
			       0x00FF0000,
			       0x0000FF00,
			       0x000000FF);




  SDL_FillRect(affichage, NULL, SDL_MapRGB(affichage->format, 0, 0, 128));

  rectangle(20, 20, 600, 440,SDL_MapRGB(affichage->format, 255, 255, 0));
  rectangle(25, 25, 590, 430,SDL_MapRGB(affichage->format, 255, 255, 0));


  draw_button (WIN_W /11, WIN_H / 4, 140, 45, 0x808080, 0x000000);
  draw_button (WIN_W /11 , (WIN_H / 3) + 15, 140, 45, 0x808080, 0x000000);


  draw_button (WIN_W /11, (WIN_H / 2) + 50, 180, 45, 0x808080, 0x000000);
  draw_button (WIN_W - 150  , (WIN_H - 95), 100, 45, 0x808080, 0x000000);

  draw_button (WIN_W /11 , (WIN_H / 2) + 115, 180, 45, 0x808080, 0x000000);

  ligneVerticale((WIN_W / 2) - 50, 30 , 420,SDL_MapRGB(affichage->format, 255, 255, 0));
  ligneVerticale((WIN_W / 2) - 45, 30 , 420,SDL_MapRGB(affichage->format, 255, 255, 0));

  FillRect((WIN_W / 2) + 75 ,WIN_H / 3, 130, 25,0x000000);


  police = TTF_OpenFont("DOS.ttf", 17);
  TTF_SetFontStyle(police,TTF_STYLE_NORMAL );  /*TTF_STYLE_ITALIC | TTF_STYLE_UNDERLINE*/
  texte = TTF_RenderText_Blended(police,"Phone number", couleurJaune);

  position.x = (WIN_W / 2) + 85;
  position.y = (WIN_H / 3) - 25;
  SDL_BlitSurface(texte, NULL, affichage, &position); /* Blit du texte */

  SDL_Flip (affichage);

  SDL_Delay (5000);


 }


/*
 void setPixel(int x, int y, Uint32 coul)
{
  *((Uint32*)(affichage->pixels) + x + y * affichage->w) = coul;
  }*/


void ligneHorizontale(int x, int y, int w, Uint32 coul)
{
  SDL_Rect r;

  r.x = x;
  r.y = y;
  r.w = w;
  r.h = 1;

  SDL_FillRect(affichage, &r, coul);
}

void rectangle(int x, int y, int w, int h, Uint32 coul)
{
  ligneHorizontale(x, y, w, coul);
  ligneHorizontale(x, y + h - 1, w, coul);
  ligneVerticale(x, y + 1, h - 2, coul);
  ligneVerticale(x + w - 1, y + 1, h - 2, coul);
}

void ligneVerticale(int x, int y, int h, Uint32 coul)
{
  SDL_Rect r;

  r.x = x;
  r.y = y;
  r.w = 1;
  r.h = h;

  SDL_FillRect(affichage, &r, coul);
}

void FillRect(int x, int y, int w, int h, int color)
{
  SDL_Rect rect = {x,y,w,h};   /* x, y, w et h pour la structy sdl  */
  SDL_FillRect(affichage, &rect, color);
}


/*  Todo
choisir police de caracteres.
ecrire caractere avec TTL et choisir couleurs



intteractions :
detecter appuis bouton.
changer sprite bouton en bouton enfonce(faire disparaitre rectangle noir).
permettre la saisie de caractere dans le champ numore de telephone.





*/
void draw_button (int x, int y, int w, int h, Uint32 colour, Uint32 colour_bg)
{

  FillRect(x +5 ,y + 5, w, h,colour_bg);
  FillRect(x  ,y , w, h, colour);
  rectangle(x + 5, y  +5, w -10, h -10,SDL_MapRGB(affichage->format, 255, 0, 0));

}
