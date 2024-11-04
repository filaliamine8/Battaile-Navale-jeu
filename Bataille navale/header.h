#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <windows.h>
#include <unistd.h>


#define SIZE 10
#define WATHER 0
#define Nbr 5

typedef enum navir{
    Torpilleur=2,
    Contre_torpilleur,
    Croiseur,
    Porte_avions,
}Navir;

enum DIrection{
    left,
    right,
    up,
    down,
};

enum{
    humain,
    machine,
};

typedef struct PlayerInfo{
    char nom[20];
    int age;
    double temps;
    int point;
    int matrice[SIZE][SIZE];
    int Print[SIZE][SIZE];
}PlayerInfo;

typedef struct BATTLESHIP{
    char name[50];
    int enemy;//machine ou humain
    int Mode;//auto ou manuelle
    int currentplayer;
    int etat;
    PlayerInfo player1;
    PlayerInfo player2;
}BATTLESHIP;


bool Ajouter_bateau(int navir, int line,int Direction,int col,int matrice[SIZE][SIZE],int mode, int nbr);//verifier si les cordonnées entrées sont possibles ou non
void Empty(int matrice[SIZE][SIZE]);// initialiser matrice a des zeros
void Placer_bateaux(int matrice[SIZE][SIZE],int mode);// placer les bateaux selon le mode choisit auto ou manuellement
bool winplayer_i(PlayerInfo player_j);// tester si un joueur a gagner ou non
void print(BATTLESHIP *battaille);
void printmaps(BATTLESHIP *battaille);
void tirer_joueur_1(BATTLESHIP *battaille);
void tirer_joueur_2(BATTLESHIP *battaille);
void tirerMachine(BATTLESHIP *battaille);
void run(BATTLESHIP *battaille);// jouer la partie tant que aucun joueur n'a encore gagné
void Joue(BATTLESHIP *battaille);// fonction principale pour commencer une partie
void Changer_etat(const char *nomFichier, const BATTLESHIP *bataille);
int loadpartie(const char *folderPath, const char *gameName, BATTLESHIP *battaille) ;
void savepartie(char *folderPath,const BATTLESHIP *battaille) ;
int count_occurrence(int matrice[SIZE][SIZE],int i);
int revisualiser_partie(const char *folderPath, const char *gameName, BATTLESHIP *battaille) ;
void statistique(BATTLESHIP *bataille) ;
int entrer_0_9();
int entrer_0_1();
void print_accueil();
void besoinAideBatailleNavale() ;



#endif // HEADER_H_INCLUDED
