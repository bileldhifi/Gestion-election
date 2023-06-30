#include <gtk/gtk.h>
typedef struct
{
    char jour[50];
    char mois[50];
    char annee[50];
} date;
typedef struct
{
    char identifiant[30];
    char nomdelaliste[30];
    char cinpresident[30];
    char municipalite[30];
    date DATE;
    char orientation[30];
    char candidat1 [30];
    char candidat2 [30];
    char candidat3 [30];
} gestionle;
/*typedef struct
{
    int jour ;
    int mois;
    int annee;
}dateu;
typedef struct
{
    char nom [20];
    char prenom [20];
    char cin[20];
    char mdp[20];
    char role [20];
    int sexe;
    dateu DATE ;
    char municipalite [30];
    int numero ;
    int vote;
} electeur;*/
typedef struct
{
char nomliste[30];
int idListe;
int nbr_vote;
}Lorder;
void ajouter(gestionle l);
void afficher(GtkWidget *liste);
void supprimer(gestionle l);
gestionle chercher(char identifiant[50]);
int verifier_l(char id[]);
