#include <stdio.h>
#include <stdlib.h>
#include "Election.h"
#include <string.h>
#include <gtk/gtk.h>

enum
{
    EIDELECTION,
    EJOUR,
    EMOIS,
    EANNEE,
    EMUNICIPALITE,
    ENBHABITANTS,
    ENBCONSEILLERS,
    COLUMNS,
};

enum
{
    ECANDIDAT1,
    ECANDIDAT2,
    ECANDIDAT3,
    EMUNICIPALITEL,
    COLUMNSL,
};


int ajouter_ge(Election E)
{

    FILE *f = fopen("Election.txt", "a+");
    if (f != NULL && strcmp(E.idElection, "") != 0 && strcmp(E.DE.jour, "0") != 0 && strcmp(E.DE.mois, "0") != 0 && strcmp(E.municipalite, "") != 0 && strcmp(E.nbHabitants, "") != 0 && strcmp(E.nbConseillers, "") != 0)
    {
        fprintf(f, "%s %s %s %s %s %s %s\n", E.idElection, E.DE.jour, E.DE.mois, E.DE.annee, E.municipalite, E.nbHabitants, E.nbConseillers);
        fclose(f);
        return 1;
    }
    else
        return 0;
}

void afficher_election(GtkWidget *liste)
{
    Election E;
    GtkCellRenderer *renderer;
    GtkTreeViewColumn *column;
    GtkTreeIter iter;
    GtkListStore *store;

    char idElection[50];
    char jour[50];
    char mois[50];
    char annee[50];
    char municipalite[50];
    char nbHabitants[50];
    char nbConseillers[50];
    store = NULL;
    FILE *f;
    FILE *fa;
    store = gtk_tree_view_get_model(liste);

    if (store == NULL)
    {
        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("idElection", renderer, "text", EIDELECTION, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("jour", renderer, "text", EJOUR, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("mois", renderer, "text", EMOIS, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("annee", renderer, "text", EANNEE, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("municipalite", renderer, "text", EMUNICIPALITE, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("nbHabitants", renderer, "text", ENBHABITANTS, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("nbConseillers", renderer, "text", ENBCONSEILLERS, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
    }

    store = gtk_list_store_new(COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);

    f = fopen("Election.txt", "r");
    if (f == NULL)
    {
        return;
    }
    else
    {
        fa = fopen("Electionaff.txt", "w");
        while (fscanf(f, "%s %s %s %s %s %s %s\n", idElection, jour, mois, annee, municipalite, nbHabitants, nbConseillers) != EOF)
        {
            gtk_list_store_append(store, &iter);
            gtk_list_store_set(store, &iter, EIDELECTION, idElection, EJOUR, jour, EMOIS, mois, EANNEE, annee, EMUNICIPALITE, municipalite, ENBHABITANTS, nbHabitants, ENBCONSEILLERS, nbConseillers, -1);

            fprintf(fa, "%s %s %s %s %s %s %s\n", idElection, jour, mois, annee, municipalite, nbHabitants, nbConseillers);
        }
        fclose(f);
        fclose(fa);
        gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
        g_object_unref(store);
    }
}

int supprimer_ge(Election E)
{
    Election E2;
    FILE *f = fopen("Election.txt", "r");
    FILE *f2 = fopen("nouv.txt", "w");
    if (f == NULL || f2 == NULL || strcmp(E.idElection, "") == 0)
    {
        return 0;
    }
    else
    {
        while (fscanf(f, "%s %s %s %s %s %s %s\n", E2.idElection, E2.DE.jour, E2.DE.mois, E2.DE.annee, E2.municipalite, E2.nbHabitants, E2.nbConseillers) != EOF)
        {
            if (strcmp(E.idElection, E2.idElection) != 0)

                fprintf(f2, "%s %s %s %s %s %s %s\n", E2.idElection, E2.DE.jour, E2.DE.mois, E2.DE.annee, E2.municipalite, E2.nbHabitants, E2.nbConseillers);
        }
    }
    fclose(f);
    fclose(f2);
    remove("Election.txt");
    rename("nouv.txt", "Election.txt");
    return 1;
}

int chercher_ge(Election E)
{
    Election E3;
    int tr = 0;
    FILE *f = fopen("Election.txt", "r");
    if (f != NULL && strcmp(E.idElection, "") != 0)
    {
        while (fscanf(f, "%s %s %s %s %s %s %s\n", E3.idElection, E3.DE.jour, E3.DE.mois, E3.DE.annee, E3.municipalite, E3.nbHabitants, E3.nbConseillers) != EOF)
        {
            if (strcmp(E.idElection, E3.idElection) == 0)
            {
                return 1;
            }
        }
    }
    fclose(f);
    return 0;
}

int modifier_ge(Election E)
{
    int tr = 0;
    Election nouv;
    FILE *f = fopen("Election.txt", "r");
    FILE *f2 = fopen("nouv.txt", "w");
    if (f != NULL && f2 != NULL && strcmp(E.idElection, "") != 0)
    {
        while (fscanf(f, "%s %s %s %s %s %s %s\n", nouv.idElection, nouv.DE.jour, nouv.DE.mois, nouv.DE.annee, nouv.municipalite, nouv.nbHabitants, nouv.nbConseillers) != EOF)
        {
            if (strcmp(E.idElection, nouv.idElection) == 0 && strcmp(E.DE.jour, "0") != 0 && strcmp(E.DE.mois, "0") != 0 && strcmp(E.municipalite, "") != 0 && strcmp(E.nbHabitants, "") != 0 && strcmp(E.nbConseillers, "") != 0)
            {
                strcpy(nouv.idElection, E.idElection);
                strcpy(nouv.DE.jour, E.DE.jour);
                strcpy(nouv.DE.mois, E.DE.mois);
                strcpy(nouv.DE.annee, E.DE.annee);
                strcpy(nouv.municipalite, E.municipalite);
                strcpy(nouv.nbHabitants, E.nbHabitants);
                strcpy(nouv.nbConseillers, E.nbConseillers);
                tr = 1;
            }

            fprintf(f2, "%s %s %s %s %s %s %s\n", nouv.idElection, nouv.DE.jour, nouv.DE.mois, nouv.DE.annee, nouv.municipalite, nouv.nbHabitants, nouv.nbConseillers);
        }
    }
    fclose(f);
    fclose(f2);
    remove("Election.txt");
    rename("nouv.txt", "Election.txt");
    return tr;
}



/*float agemoyen(electeur e)
{

int age_tot=0 ,age_electeur=0;
int i=1;
float age_moy=0;
     FILE *f=fopen("electeur.txt", "r");
 if (f!= NULL)
    {
     while(fscanf(f,"%s %s %s %s %s %d %d %d %d %d %d %d\n" ,e.nom,e.prenom,e.cin,e.mdp,e.role,&e.sexe,&e.DATE.jour,&e.DATE.mois,&e.DATE.annee, &e.municipalite, &e.numero,&e.vote)!=EOF)
        {
           age_electeur=2022-(e.DATE.annee);
           age_tot=age_tot+age_electeur;
           age_moy=age_tot /i;
           i++;
        }
    }

  return age_moy;
}*/


/*int  gagnant(gestionle l)
{
    int cmpt=0;
    int nbhabitants;
    int nb_conseillers=4;
    Lorder tab[100];
    int n;
    triliste(tab,&n);
    int nbHabitants=0;
    int  nb_gag=0;

  
  nb_gag = (nb_conseillers / 3)*3 +(nb_conseillers % 3);
  
     FILE * f=fopen("liste.txt", "r");
     FILE * f2=fopen("lgag.txt", "w");
 
      if (f!=NULL)
        {
        
        while(fscanf(f,"%s %s %s %d %d %d %d %d %s %s %s\n" ,l.identifiant,l.nomdelaliste,l.cinpresident,&l.municipalite,&l.DATE.jour,&l.DATE.mois,&l.DATE.annee,                              &l.orientation, l.candidat1,l.candidat2,l.candidat3)!=EOF)
          {
             if(cmpt>=nb_gag) break;
             if(cmpt<nb_gag) {fprintf(f2,"%s\n",l.candidat1);cmpt++;} 
             if(cmpt<nb_gag) {fprintf(f2,"%s\n",l.candidat2);cmpt++;} 
             if(cmpt<nb_gag) {fprintf(f2,"%s\n",l.candidat3);cmpt++;}
          }
        }
 return nb_gag;
} */


/*void afficher_gagnants(GtkWidget *liste)
{
    gestionle l;
    Election E;
    int cmpt=0;
    int nb_gag;
    FILE *fe = fopen("Election.txt", "r");
     if (fe == NULL)
    {
        return;
    }
    else
    {
        while (fscanf(fe, "%s %s %s %s %s %s %s\n", E.idElection, E.DE.jour, E.DE.mois, E.DE.annee, E.municipalite, E.nbHabitants, E.nbConseillers) != EOF)
        {nb_gag=atoi(E.nbConseillers);}
    }

    GtkCellRenderer *renderer;
    GtkTreeViewColumn *column;
    GtkTreeIter iter;
    GtkListStore *store;
    
    char idliste[30];
    char nomliste[30];
    char cinpliste[30];
    char jourliste[30];
    char moisliste[30];
    char anneeliste[30];
    char orientation[30];
    char municipalite[30];
    char candidat1 [30];
    char candidat2 [30];
    char candidat3 [30];
    
    store = NULL;
    FILE *f;
    FILE *fla;
    store = gtk_tree_view_get_model(liste);

    if (store == NULL)
    {
        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("candidat1", renderer, "text", ECANDIDAT1, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("candidat2", renderer, "text", ECANDIDAT2, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("candidat3", renderer, "text", ECANDIDAT3, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("municipalite", renderer, "text", EMUNICIPALITEL, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
    }

    store = gtk_list_store_new(COLUMNSL, G_TYPE_STRING, G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);

    f = fopen("listeord.txt", "r");
    if (f == NULL)
    {
        return;
    } 
    else
    {
        fla = fopen("listeordaff.txt", "w+");
        while (fscanf(f, "%s %s %s %s %s %s %s %s %s %s %s\n" ,idliste,nomliste,cinpliste,municipalite,jourliste,moisliste,anneeliste,        orientation,candidat1,candidat2,candidat3)!=EOF)
        {
             if(cmpt>=nb_gag) break;
             if(cmpt<nb_gag) {fprintf(fla,"%s ",candidat1);cmpt++;} 
             if(cmpt<nb_gag) {fprintf(fla,"%s ",candidat2);cmpt++;} 
             if(cmpt<nb_gag) {fprintf(fla,"%s ",candidat3);cmpt++;}
                             fprintf(fla,"%s\n",municipalite);
            gtk_list_store_append(store, &iter);
            gtk_list_store_set(store, &iter, ECANDIDAT1, candidat1, ECANDIDAT2, candidat2 ,ECANDIDAT3, candidat3,  EMUNICIPALITEL, municipalite, -1);
             
           
        }
        fclose(f);
        fclose(fla);
        gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
        g_object_unref(store);
    }
}*/
