#ifndef Election_H_INCLUDED
#define Election_H_INCLUDED
#include <stdio.h>
#include <string.h>
#include <gtk/gtk.h>

typedef struct DateElection
{
char jour[50];
char mois[50];
char annee[50]; 
}DateElection;

typedef struct
{
    char idElection[50] ;
    DateElection DE;
    char municipalite[50];
    char nbHabitants[50];
    char nbConseillers[50];
  
} Election;
/*typedef struct
{
    char jour[30] ;
    char mois[30];
    char annee[30];
}datee;*/

/*typedef struct
{
    char identifiant[30];
    char nomdelaliste[30];
    char cinpresident[30];
    char municipalite[30];
    datee DATE;
    char orientation[30];
    char candidat1 [30];
    char candidat2 [30];
    char candidat3 [30];
    int nbVote;
} gestionle;

typedef struct
{
char nomliste[30];
int idListe;
int nbr_vote;
}Lorder;*/

/*typedef struct
{
    int jour ;
    int mois;
    int annee;
}dateu;*/
/*typedef struct
{
    char nom [20];
    char prenom [20];
    char cin[20];
    char mdp[20];
    char role [20];
    int sexe;
    dateu DATE ;
    int municipalite;
    int numero ;
    int vote;
} electeur;*/

int ajouter_ge(Election E );
void afficher_election (GtkWidget *liste);
int supprimer_ge(Election E);
int chercher_ge(Election E);
int modifier_ge(Election E);
void afficher_gagnants(GtkWidget *liste);
//float agemoyen(electeur e);
/*void triliste(Lorder tab[100],int *n);
int  gagnant( int nbhabitants,gestionle l, char *filename,char *filename2);*/

#endif // Election_H_INCLUDED
