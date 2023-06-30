#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif
#include <gtk/gtk.h>
#include "list.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//Ajouter
void ajouter(gestionle l )
{
    FILE * f=fopen("list.txt", "a+");
    if(f!=NULL)
    {
        fprintf(f,"%s %s %s %s %s %s %s %s %s %s %s \n",l.identifiant,l.nomdelaliste,l.cinpresident,l.municipalite,l.DATE.jour,l.DATE.mois,l.DATE.annee,l.orientation,l.candidat1,l.candidat2,l.candidat3);
        fclose(f);
    }
}
//Afficher
enum {
IDLISTE,
NOMLISTE,
CINP,
MUNICIPALITE,
JOUR,
MOIS,
ANNEE,
ORIENTATION,
CANDIDAT1,
CANDIDAT2,
CANDIDAT3,
COLUMNS,
};

void afficher(GtkWidget  *liste)
{
GtkCellRenderer *renderer;
GtkTreeViewColumn *Column;
GtkTreeIter iter;
GtkListStore *store;
gestionle l;
store=NULL;
FILE *f;
store=gtk_tree_view_get_model(liste);


if (store==NULL)
{
renderer=gtk_cell_renderer_text_new();
Column=gtk_tree_view_column_new_with_attributes("identifiant",renderer,"text",IDLISTE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),Column);

renderer=gtk_cell_renderer_text_new();
Column=gtk_tree_view_column_new_with_attributes("nomdelaliste",renderer,"text",NOMLISTE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),Column);

renderer=gtk_cell_renderer_text_new();
Column=gtk_tree_view_column_new_with_attributes("cinpresident",renderer,"text",CINP,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),Column);

renderer=gtk_cell_renderer_text_new();
Column=gtk_tree_view_column_new_with_attributes("municipalite",renderer,"text",MUNICIPALITE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),Column);

renderer = gtk_cell_renderer_text_new();
Column =gtk_tree_view_column_new_with_attributes("jour",renderer,"text",JOUR,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), Column);

renderer = gtk_cell_renderer_text_new();
Column =gtk_tree_view_column_new_with_attributes("mois",renderer,"text",MOIS,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), Column);

renderer = gtk_cell_renderer_text_new();
Column=gtk_tree_view_column_new_with_attributes("annee",renderer,"text",ANNEE,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), Column);

renderer = gtk_cell_renderer_text_new();
Column=gtk_tree_view_column_new_with_attributes("orientation",renderer,"text",ORIENTATION,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), Column);

renderer = gtk_cell_renderer_text_new();
Column=gtk_tree_view_column_new_with_attributes("candidat1",renderer,"text",CANDIDAT1,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), Column);

renderer = gtk_cell_renderer_text_new();
Column=gtk_tree_view_column_new_with_attributes("candidat2",renderer,"text",CANDIDAT2,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), Column);

renderer = gtk_cell_renderer_text_new();
Column=gtk_tree_view_column_new_with_attributes("candidat3",renderer,"text",CANDIDAT3,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), Column);

}

store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);


f = fopen("list.txt","r");
if (f==NULL){return;}


else { f = fopen("list.txt","a+");

while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s %s\n",l.identifiant,l.nomdelaliste,l.cinpresident,l.municipalite,l.DATE.jour,l.DATE.mois,l.DATE.annee,l.orientation,l.candidat1,l.candidat2,l.candidat3)!=EOF)

{

gtk_list_store_append (store, &iter);  

gtk_list_store_set(store,&iter,IDLISTE,l.identifiant,NOMLISTE,l.nomdelaliste,CINP,l.cinpresident,MUNICIPALITE,l.municipalite,JOUR,l.DATE.jour,MOIS,l.DATE.mois,ANNEE,l.DATE.annee,ORIENTATION,l.orientation,CANDIDAT1,l.candidat1,CANDIDAT2,l.candidat2,CANDIDAT3,l.candidat3,-1);

}
fclose (f);

gtk_tree_view_set_model (GTK_TREE_VIEW (liste), GTK_TREE_MODEL (store));

g_object_unref (store);
}          
}
//Supprimer
void supprimer(gestionle l)
    {   gestionle k;
	FILE *f, *g;
	f=fopen("list.txt","r");
	g=fopen("nouv.txt","w");
	if(f==NULL || g==NULL)
	  { return;
	  }
	else
	{ while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s %s\n",k.identifiant,k.nomdelaliste,k.cinpresident,k.municipalite,k.DATE.jour,k.DATE.mois,k.DATE.annee,k.orientation,k.candidat1,k.candidat2,k.candidat3)!=EOF)
	   {
if(strcmp(l.identifiant,k.identifiant)!=0||strcmp(l.nomdelaliste,k.nomdelaliste)!=0 || strcmp(l.cinpresident,k.cinpresident)!=0||strcmp(l.municipalite,k.municipalite)!=0||strcmp(l.DATE.jour,k.DATE.jour)!=0||strcmp(l.DATE.mois,k.DATE.mois)!=0||strcmp(l.DATE.annee,k.DATE.annee)!=0|| strcmp(l.orientation,k.orientation)!=0||strcmp(l.candidat1,k.candidat1)!=0|| strcmp(l.candidat2,k.candidat2)||strcmp(l.candidat3,k.candidat3)!=0) 
fprintf(g,"%s %s %s %s %s %s %s %s %s %s %s \n",k.identifiant,k.nomdelaliste,k.cinpresident,k.municipalite,k.DATE.jour,k.DATE.mois,k.DATE.annee,k.orientation,k.candidat1,k.candidat2,k.candidat3);
	   }
fclose(f);
fclose(g);
remove("list.txt");
rename("nouv.txt","list.txt");
	}
    }
//Chercher
gestionle chercher(char identifiant[50])
{
    gestionle l;
    int tr=0;
    FILE * f=fopen("list.txt", "r");
    if(f!=NULL)
    {
        while(tr==0 && fscanf(f,"%s %s %s %s %s %s %s %s %s %s %s\n",l.identifiant,l.nomdelaliste,l.cinpresident,l.municipalite,l.DATE.jour,l.DATE.mois,l.DATE.annee,l.orientation,l.candidat1,l.candidat2,l.candidat3)!=EOF)
        {
            if(strcmp(l.identifiant,identifiant)==0)
                tr=1;
        }
    }
    fclose(f);
    if(tr==0)
        strcpy(l.identifiant,"-1");
    return l;

}
//Vérifier id
int verifier_l(char id[])
{
    gestionle l;
    int t=0;
    FILE *f=fopen("list.txt", "r");
    if(f!=NULL)
    {
        while(t==0 && fscanf(f,"%s %s %s %s %s %s %s %s %s %s %s\n",l.identifiant,l.nomdelaliste,l.cinpresident,l.municipalite,l.DATE.jour,l.DATE.mois,l.DATE.annee,l.orientation,l.candidat1,l.candidat2,l.candidat3)!=EOF)
        {
          if(strcmp(l.identifiant,id)==0)
           {     t=1;}
else
  {t=0;}
        }

    }
    fclose(f);  
    return t;

}

