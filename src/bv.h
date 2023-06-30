#ifndef GESTION_H_INCLUDED
#define GESTION_H_INCLUDED
#include <gtk/gtk.h>

typedef struct Gestion_BV
{
    char identifiant_BV[10];
    int capacite_electeurs;
    int capacite_observateurs;
    char municipalite[50];
    char salle[50];
    char identifiant_AG_BV[10];
}gestion_BV;


/*typedef struct
{
    int jour ;
    int mois;
    int annee;
}date;
typedef struct
{
    char nom [20];
    char prenom [20];
    char cin[20];
    char mdp[20];
    int role;
    int sexe;
    date DATE ;
    int municipalite;
    char numero[20] ;
    int vote;
} user;*/





//les fonctions
int connexion(char login[],char pass[]);
void notRobot(int choix , char texte[]);
void numsalle(int choice , char text[]);
int ajouterBV(char * filename, gestion_BV L);
int verifier ( char id[100] );
int verifier_ag ( char id[100] );
int modifierBV( char * filename,char identifiant_BV[],gestion_BV nouvL );
int supprimerBV(char * filename, char identifiant_BV[] );
gestion_BV chercher_bv(char * filename, char identifiant_BV[]);
gestion_BV chercher_agbv(char * filename, char identifiant_AG_BV[]);
/*int nbrobservateur(char * filename);
void remplirtab(char *filename, user tab[],int *n);
void obstrier(char *filename, user tab[],int *n);
void trier_candidat_gagnant(char * filename,user tab[],int *n);*/
void filtrer (char *filename,char munie[], char room [] );
void afficher_bv(GtkWidget  *liste, char *filename);
//void afficher_gu(GtkWidget  *liste);
#endif
