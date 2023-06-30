
#ifndef utilisateur_utilisateur_H
#define utilisateur_utilisateur_H
#include <gtk/gtk.h>
typedef struct Date {
    int annee;
    int mois;
    int jour;
} Date_u;


typedef struct utilisateur{
    char prenom[100];
    char nom[100];
    char numero[100];
    char MotDePasse[100];
    Date_u dateNaissance;
    char role [30];
    char sex[30];
    int cin;
}utilisateur;

int ajouter_u(utilisateur u, char *fileName);
int modifier_u(int cinn,char *fileName ,utilisateur nouv );
int supprimer_u(int cinn, char *fileName);
utilisateur chercher_u(int cinn, char *fileName);
void afficher_u(GtkWidget *user);
utilisateur readutilisateur();
float ageMoy(char *fileName);
float tauxVoteBlanc (char *fileName);
void Genre(int se,char text1[]);
void verification(int x,char text2[]);


#endif //utilisateur_utilisateur_H


