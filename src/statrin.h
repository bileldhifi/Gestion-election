
#include <gtk/gtk.h>


typedef struct
{
    char jour[20];
    char mois[20];
   char annee[20];
}Date;
typedef struct
{
    char nom [20];
    char prenom [30];
    char cin[20];
    char mdp[30];
    char role [20];
    char sexe[20];
    Date DATE ;
    char muni[30];
    char numero[20];
    char vote [20]
} user;


int nbrobservateur(char * filename);
void remplirtab(char *filename, user tab[],int *n);
void obstrier(char *filename, user tab[],int *n);
void afficher_gu(GtkWidget  *liste, char *filename);

