#include <stdio.h>
#include <string.h>
#include <gtk/gtk.h>
#include "statrin.h"



//function pour calculer le nbre total d'observateur
int nbrobservateur(char * filename)
{
    user E;

    int nbr=0;
    FILE *f=fopen(filename, "r");
    if(f!=NULL)
    {
    while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s %s %s\n",E.nom,E.prenom,E.cin,E.mdp,E.role,E.sexe,E.DATE.jour,E.DATE.mois,E.DATE.annee,E.muni,E.numero,E.vote)!=EOF)
    {
        if(strcmp(E.role,"Observateur")==0)
        {
            nbr=nbr+1;
        }
    }
    }
    fclose(f);
    return nbr;
}



//fonction pour trier l'utilisateur
void remplirtab(char *filename, user tab[],int *n)
{
    user E,tompon;
    int i,j,min;
    FILE * f=fopen(filename, "r");
    FILE * f2=fopen("usertrier.txt","w");
    if(f!=NULL)
    {

        while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s %s %s\n",E.nom,E.prenom,E.cin,E.mdp,E.role,E.sexe,E.DATE.jour,E.DATE.mois,E.DATE.annee,E.muni,E.numero,E.vote)!=EOF)
        {
            tab[*n]=E;
            (*n)++;
        }
        for(i=0; i<(*n)-1; i++)
    {
        min=i;
        for(j=i+1; j<(*n); j++)
        {
            if(tab[j].nom[0]<tab[min].nom[0])
            {
                min=j;
            }
        }
        tompon=tab[i];
        tab[i]=tab[min];
        tab[min]=tompon;
    }
    }
    if(f2!=NULL)
    {
         for(i=0; i<(*n); i++)
        {
            fprintf(f2,"%s %s %s %s %s %s %s %s %s %s %s %s\n",tab[i].nom,tab[i].prenom,tab[i].cin,tab[i].mdp,tab[i].role,tab[i].sexe,tab[i].DATE.jour,tab[i].DATE.mois,tab[i].DATE.annee,tab[i].muni,tab[i].numero,tab[i].vote);
        }


    }
    fclose(f);
    fclose(f2);
}


//fonction pour trier l'observateur
void obstrier(char *filename, user tab[],int *n)
{
    user E,tompon; 
    int i,j,min;
    FILE * f=fopen(filename, "r");
    FILE * f2=fopen("obstrier.txt","w");
    if(f!=NULL)
    {

        while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s %s %s\n",E.nom,E.prenom,E.cin,E.mdp,E.role,E.sexe,E.DATE.jour,E.DATE.mois,E.DATE.annee,E.muni,E.numero,E.vote)!=EOF)
        {
            if(strcmp(E.role,"Observateur")==0)
            {
              tab[*n]=E;
              (*n)++;
            }
        }
        for(i=0; i<(*n)-1; i++)
    {
        min=i;
        for(j=i+1; j<(*n); j++)
        {
            if(tab[j].nom[0]<tab[min].nom[0])
            {
                min=j;
            }
        }
        tompon=tab[i];
        tab[i]=tab[min];
        tab[min]=tompon;
    }
    }
    if(f2!=NULL)
    {
         for(i=0; i<(*n); i++)
        {
            fprintf(f2,"%s %s %s %s %s %s %s %s %s %s %s %s\n",tab[i].nom,tab[i].prenom,tab[i].cin,tab[i].mdp,tab[i].role,tab[i].sexe,tab[i].DATE.jour,tab[i].DATE.mois,tab[i].DATE.annee,tab[i].muni,tab[i].numero,tab[i].vote);
        }


    }
    fclose(f);
    fclose(f2);
    
}


enum {
NOM,
PRENOM,
CIN,
MP,
ROLE,
SEXE,
DATE_J,
DATE_M,
DATE_A,
MUNIE,
NUM,
VOTE,
COLUMNS,
};

void afficher_gu(GtkWidget  *liste, char *filename)
{
GtkCellRenderer *renderer;
GtkTreeViewColumn *Column;
GtkTreeIter iter;
GtkListStore *store;
user E;
char rol[30],genre[30],jour[30],mois[30],ann[30],mun[30],vot[30];
store=NULL;
FILE *f;
store=gtk_tree_view_get_model(liste);


if (store==NULL)
{
renderer=gtk_cell_renderer_text_new();
Column=gtk_tree_view_column_new_with_attributes("Nom",renderer,"text",NOM,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),Column);

renderer=gtk_cell_renderer_text_new();
Column= gtk_tree_view_column_new_with_attributes("Prenom",renderer,"text",PRENOM,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),Column);

renderer=gtk_cell_renderer_text_new();
Column=gtk_tree_view_column_new_with_attributes("CIN",renderer,"text",CIN,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),Column);

renderer=gtk_cell_renderer_text_new();
Column=gtk_tree_view_column_new_with_attributes("Mots\nde passe",renderer,"text",MP,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),Column);

renderer=gtk_cell_renderer_text_new();
Column=gtk_tree_view_column_new_with_attributes("Role",renderer,"text",ROLE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),Column);

renderer=gtk_cell_renderer_text_new();
Column=gtk_tree_view_column_new_with_attributes("Sexe",renderer,"text",SEXE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),Column);

renderer = gtk_cell_renderer_text_new();
Column = gtk_tree_view_column_new_with_attributes("Jour",renderer,"text",DATE_J, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), Column);

renderer = gtk_cell_renderer_text_new();
Column = gtk_tree_view_column_new_with_attributes("Mois",renderer,"text",DATE_M, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), Column);

renderer = gtk_cell_renderer_text_new();
Column = gtk_tree_view_column_new_with_attributes("Annee",renderer,"text",DATE_A, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), Column);

renderer = gtk_cell_renderer_text_new();
Column = gtk_tree_view_column_new_with_attributes("Municipalite",renderer,"text",MUNIE, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), Column);

renderer = gtk_cell_renderer_text_new();
Column = gtk_tree_view_column_new_with_attributes("Numero",renderer,"text",NUM, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), Column);

renderer = gtk_cell_renderer_text_new();
Column = gtk_tree_view_column_new_with_attributes("vote",renderer,"text",VOTE, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), Column);



}

store = gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);



f = fopen(filename,"r");
if (f==NULL){return;}


else { f = fopen(filename,"a+");

while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s %s %s\n",E.nom,E.prenom,E.cin,E.mdp,E.role,E.sexe,E.DATE.jour,E.DATE.mois,E.DATE.annee,E.muni,E.numero,E.vote)!=EOF)

  {
   gtk_list_store_append (store, &iter);  
   gtk_list_store_set (store, &iter, NOM,E.nom, PRENOM, E.prenom, CIN, E.cin, MP, E.mdp,  ROLE, E.role, SEXE, E.sexe, DATE_J, E.DATE.jour, DATE_M, E.DATE.mois, DATE_A, E.DATE.annee, MUNIE, E.muni, NUM, E.numero, VOTE, E.vote,-1);

  }
fclose (f);

gtk_tree_view_set_model (GTK_TREE_VIEW (liste), GTK_TREE_MODEL (store));

g_object_unref (store);
}
     
       
}

