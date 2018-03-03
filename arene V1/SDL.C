/* includes */
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>

/* déclarations des constantes */
#define MALADIE 666
#define TAILLE 10
#define HAUTEUR_PX 640
#define LARGEUR_PX 640
#define TAILLE_CASE 40


void Spawn_Maladie (SDL_Surface* tab[TAILLE][TAILLE])
{
    int x,y;
    SDL_Surface *Maladie = NULL;
    SDL_Rect position;


    Maladie = SDL_CreateRGBSurface(SDL_HWSURFACE, TAILLE_CASE, TAILLE_CASE, 32, 0, 0, 0, 0); /* Creation d'un rectangle */
    SDL_FillRect(Maladie, NULL, SDL_MapRGB(Maladie->format, 50, 200, 50)); /* remplissage du rectangle*/

        if (Maladie == NULL)// en cas d'erreur
    {
        fprintf(stderr,"Errreur: %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }
    x = rand()%TAILLE; /// aleatoire a corriger, le spawn est toujours au meme endroit
    y = rand()%TAILLE;
    tab[x][y] = Maladie;
    return EXIT_SUCCESS;

}

// permet de faire une pause dans le programme (permet d'afficher la fenêtre)
void pause()
{
    int continuer = 1;
    SDL_Event event;
    while (continuer)
    {
        SDL_WaitEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
                continuer = 0;
        }
    }
}
// crée l'arène
void creer_interface(SDL_Surface *ecran)
{
    int i,j;
    SDL_Surface *tab[TAILLE][TAILLE] = {NULL};
    int nb_joueurs;

    SDL_Surface *vide = NULL;
    //SDL_Surface *ecran = NULL;
    SDL_Surface *rectangle = NULL;
    SDL_Surface *texte = NULL;
    SDL_Rect position;


    //TTF_Font *police = NULL;
   // SDL_Color CouleurNoire = {0, 0, 0};

   // SDL_Init(SDL_INIT_VIDEO);

    ecran = SDL_SetVideoMode(LARGEUR_PX,HAUTEUR_PX,32,SDL_DOUBLEBUF|SDL_HWSURFACE); // création de la fenêtre
    if (ecran == NULL)// en cas d'erreur
    {
        fprintf(stderr,"Impossible de charger le mode vidéo: %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }

    SDL_WM_SetCaption("Arene", NULL); // on nomme la fenêtre (on met NULL au paramètre facultatif)

    SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format,17,206,112)); // couleur du fond

    position.x=(640/2) - (220/2);
    position.y=(480/2) - (180/2);
/*
    rectangle = SDL_CreateRGBSurface(SDL_HWSURFACE, 220, 180, 32, 0, 0, 0, 0);
    SDL_FillRect(rectangle, NULL, SDL_MapRGB(ecran->format,255,255,255));
    SDL_BlitSurface(rectangle, NULL, ecran,&position);

*/
vide = SDL_CreateRGBSurface(SDL_HWSURFACE, TAILLE_CASE, TAILLE_CASE, 32, 0, 0, 0, 0); /* Creation d'un rectangle */
SDL_FillRect(vide, NULL, SDL_MapRGB(vide->format, 200, 200, 200)); /* remplissage du rectangle*/

for(i=0;i<TAILLE;i++)
{

    for(j=0;j<TAILLE;j++)
    {
        tab[i][j] = vide;
        position.x=(i*43)+2; // (i*(40+nombre pour l'espace entre les cases) + décallage sur le coté : 40 = taille du carré
        position.y=(j*43)+2;
        SDL_BlitSurface(tab[i][j], NULL, ecran, &position);
    }
}



    SDL_Flip(ecran);// mise à jour de l'écran

    /// cette partie ne fonctionne pas : à vérifier avec une bonne installation de SDL_ttf{
    /*TTF_Init();
   if(TTF_Init() == -1)
{
    fprintf(stderr, "Erreur d'initialisation de TTF_Init : %s\n", TTF_GetError());
    exit(EXIT_FAILURE);
}
    police = TTF_OpenFont("angelina.ttf", 65);
    TTF_CloseFont(police);
    texte = TTF_RenderText_Blended(police, "Test!",CouleurNoire);
    pause();
    // on libère la mémoire



    TTF_CloseFont(police);*////}


    pause();
    //TTF_Quit();
    SDL_FreeSurface(rectangle);
    SDL_FreeSurface(texte);


    return EXIT_SUCCESS;
}

int main ( int argc, char* argv[] )
{
//SDL_Surface *ecran = NULL;

if(SDL_Init(SDL_INIT_VIDEO)==-1) //on démarre la SDL. Dans le cas où il y a une erreur:
    {
        fprintf(stderr,"erreur d'initialisation de la SDL : %s\n", SDL_GetError()); // écriture de l'erreur
        exit(EXIT_FAILURE);

    }
SDL_Surface *tab[TAILLE][TAILLE] = {NULL};
SDL_Rect position;
SDL_Surface *ecran = NULL;

creer_interface(ecran);
//
Spawn_Maladie(tab[TAILLE][TAILLE]); /// renvoie 3 quand on active cette fonction, sinon renvoie 0 (à corriger)
//SDL_Flip(ecran);// mise à jour de l'écran
    SDL_Quit();
return 0;

}

