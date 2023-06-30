#include <stdio.h>
#include <string.h>
#include <gtk/gtk.h>
#include "bv.h"



/*int connexion(char login[],char pass[])
{
    user E;
    char role[20];
    int r=-1;
    FILE * f=fopen("user.txt", "r");
     FILE * f2=fopen("connected.txt", "w+");


    if(f!=NULL && f2!=NULL)
    {
        while(fscanf(f,"%s %s %s %s %d %d %d %d %d %d %s %d\n",E.nom,E.prenom,E.cin,E.mdp,&E.role,&E.sexe,&E.DATE.jour,&E.DATE.mois,&E.DATE.annee,&E.municipalite,E.numero,&E.vote)!=EOF)
        {
            if((strcmp(E.cin,login)==0) && (strcmp(E.mdp,pass)==0))
            {
                role==E.role;
            }
        }
        if(role!=-1){
             fprintf(f2,"%s\n",login);
        }
    }
    fclose(f);
    fclose(f2);
    return role;
}*/




//checkbutton ajout bv

void notRobot(int choix , char texte[])
{
     if (choix==1)
     strcat(texte, "je ne suis pas un Robot");
}


void numsalle(int choice , char text[])
{
     if(choice==1)
     strcpy(text,"salle1");
     if(choice==2)
     strcpy(text, "salle2");
     else
       if(choice==3)
       strcpy(text, "salle3");
}


//function pour ajouter liste
int ajouterBV(char * filename, gestion_BV L)
{
    int x=0;
    FILE * f=fopen(filename, "a");
    if(f!=NULL)
    {
        fprintf(f,"%s %d %d %s %s %s\n",L.identifiant_BV,L.capacite_electeurs,L.capacite_observateurs,L.municipalite,L.salle,L.identifiant_AG_BV);
        fclose(f);
        return 1;
    }
    else
        return 0;
}






//function pour modifier liste
int modifierBV( char * filename,char identifiant_BV[],gestion_BV nouvL )
{
    gestion_BV L;
    FILE * f=fopen(filename, "r");
    FILE * f2 =fopen("aux.txt", "w");
    if(f==NULL || f2==NULL)
        return 0;
    else
    {
        while(fscanf(f,"%s %d %d %s %s %s \n",L.identifiant_BV,&L.capacite_electeurs,&L.capacite_observateurs,L.municipalite,L.salle,L.identifiant_AG_BV)!=EOF)
        {
            if(strcmp(L.identifiant_BV,identifiant_BV)==0)
                fprintf(f2,"%s %d %d %s %s %s \n",nouvL.identifiant_BV,nouvL.capacite_electeurs,nouvL.capacite_observateurs,nouvL.municipalite,nouvL.salle,nouvL.identifiant_AG_BV);
            else

                fprintf(f2,"%s %d %d %s %s %s \n",L.identifiant_BV,L.capacite_electeurs,L.capacite_observateurs,L.municipalite,L.salle,L.identifiant_AG_BV);
        }
        fclose(f);
        fclose(f2);
        remove(filename);
        rename("aux.txt", filename);
        return 1;
    }

}
//function pour supprimer liste
int supprimerBV(char * filename, char identifiant_BV[] )
{
    int tr=0;
    gestion_BV L;
    FILE * f=fopen(filename, "r");
    FILE * f2 =fopen("nouv.txt", "w");
    if(f!=NULL || f2!=NULL)

    {
        while(fscanf(f,"%s %d %d %s %s %s \n",L.identifiant_BV,&L.capacite_electeurs,&L.capacite_observateurs,L.municipalite,L.salle,L.identifiant_AG_BV)!=EOF)
        {
            if(strcmp(L.identifiant_BV,identifiant_BV)==0)
                tr=1;
            else
                fprintf(f2,"%s %d %d %s %s %s \n",L.identifiant_BV,L.capacite_electeurs,L.capacite_observateurs,L.municipalite,L.salle,L.identifiant_AG_BV);
        }
        fclose(f);
        fclose(f2);
        remove(filename);
        rename("nouv.txt", filename);
        return tr;
    }
}
//function pour chercher liste
gestion_BV chercher_bv(char * filename, char identifiant_BV[])
{
    gestion_BV L;
    int tr=0;
    FILE * f=fopen(filename, "r");
    if(f!=NULL)
    {
        while(tr==0&& fscanf(f,"%s %d %d %s %s %s\n",L.identifiant_BV,&L.capacite_electeurs,&L.capacite_observateurs,L.municipalite,L.salle,L.identifiant_AG_BV)!=EOF)
        {
            if(strcmp(L.identifiant_BV, identifiant_BV)==0)
                tr=1;
        }
    }
    fclose(f);
    if(tr==0)
        strcpy(L.identifiant_BV,"-1");
    return L;

}


//fonction saisie
int verifier ( char id[100] )
{
    int tr,j,i=1,h,k;
    char string[100]="";
    strcpy(string,id);
    k=strlen(string);
    if (string[0]=='0')
    {
      for (h=k;h<1;h--)
      {
          string[h-1]=string[h];
      }
      j=atoi(string);
      while (j >= 10)
       {
        j /= 10;
        i++;
       }
     if (i==8)
        {tr=1;}
     else
        {tr=0;}
    }
    else if (string[0]!='0')
    {
        j=atoi(string);
    while (j >= 10)
    {
        j /= 10;
        i++;
    }
    if (i==9)
        tr=1;
    else
        tr=0;
    }

    return tr ;
}

//verifie agent 
int verifier_ag ( char id[100] )
{
    int tr,j,i=1,h,k;
    char string[100]="";
    strcpy(string,id);
    k=strlen(string);
    if (string[0]=='0')
    {
      for (h=k;h<1;h--)
      {
          string[h-1]=string[h];
      }
      j=atoi(string);
      while (j >= 10)
       {
        j /= 10;
        i++;
       }
     if (i==7)
        {tr=1;}
     else
        {tr=0;}
    }
    else if (string[0]!='0')
    {
        j=atoi(string);
    while (j >= 10)
    {
        j /= 10;
        i++;
    }
    if (i==8)
        tr=1;
    else
        tr=0;
    }

    return tr ;
}

//fonction chercher id
gestion_BV chercher_agbv(char * filename, char identifiant_AG_BV[])
{
    gestion_BV L;
    int tr=0;
    FILE * f=fopen(filename, "r");
    if(f!=NULL)
    {
        while(tr==0&& fscanf(f,"%s %d %d %s %s %s\n",L.identifiant_BV,&L.capacite_electeurs,&L.capacite_observateurs,L.municipalite,L.salle,L.identifiant_AG_BV)!=EOF)
        {
            if(strcmp(L.identifiant_AG_BV, identifiant_AG_BV)==0)
                tr=1;
        }
    }
    fclose(f);
    if(tr==0)
        strcpy(L.identifiant_AG_BV,"-1");
    return L;

}

//function pour calculer le nbre total d'observateur
/*int nbrobservateur(char * filename)
{
    user E;

    int nbr=0;
    FILE *f=fopen(filename, "r");
    if(f!=NULL)
    {
    while(fscanf(f,"%s %s %s %s %d %d %d %d %d %d %s %d\n",E.nom,E.prenom,E.cin,E.mdp,&E.role,&E.sexe,&E.DATE.jour,&E.DATE.mois,&E.DATE.annee,&E.municipalite,E.numero,&E.vote)!=EOF)
    {
        if(E.role==4)
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

        while(fscanf(f,"%s %s %s %s %d %d %d %d %d %d %s %d\n",E.nom,E.prenom,E.cin,E.mdp,&E.role,&E.sexe,&E.DATE.jour,&E.DATE.mois,&E.DATE.annee,&E.municipalite,E.numero,&E.vote)!=EOF)
        {
            tab[*n]=E;
            (*n)++;
        }
        for(i=0; i<(*n-1); i++)
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
            fprintf(f2,"%s %s %s %s %d %d %d %d %d %d %s %d\n",tab[i].nom,tab[i].prenom,tab[i].cin,tab[i].mdp,tab[i].role,tab[i].sexe,tab[i].DATE.jour,tab[i].DATE.mois,tab[i].DATE.annee,tab[i].municipalite,tab[i].numero,tab[i].vote);
        }


    }
    fclose(f);
    fclose(f2);
    remove(filename);
    rename("usertrier.txt",filename);
}


//fonction pour trier l'observateur
void obstrier(char *filename, user tab[],int *n)
{
    user E,tompon;
    int role=4; 
    int i,j,min;
    FILE * f=fopen(filename, "r");
    FILE * f2=fopen("obstrier.txt","w");
    if(f!=NULL)
    {

        while(fscanf(f,"%s %s %s %s %d %d %d %d %d %d %s %d\n",E.nom,E.prenom,E.cin,E.mdp,&E.role,&E.sexe,&E.DATE.jour,&E.DATE.mois,&E.DATE.annee,&E.municipalite,E.numero,&E.vote)!=EOF)
        {
            if(E.role==role)
            {
              tab[*n]=E;
              (*n)++;
            }
        }
        for(i=0; i<(*n-1); i++)
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
            fprintf(f2,"%s %s %s %s %d %d %d %d %d %d %s %d\n",tab[i].nom,tab[i].prenom,tab[i].cin,tab[i].mdp,tab[i].role,tab[i].sexe,tab[i].DATE.jour,tab[i].DATE.mois,tab[i].DATE.annee,tab[i].municipalite,tab[i].numero,tab[i].vote);
        }


    }
    fclose(f);
    fclose(f2);
    
}*/


//fonction pour trier les candidat gagnant
/*void trier_candidat_gagnant(char * filename,user tab[],int *n)
{
    user E,tompon;
    int i,j,min;
    FILE * f=fopen(filename, "r");
    FILE * f2=fopen("candidatgagnanttrier.txt","w");
    if(f!=NULL)
    {

        while(fscanf(f,"%s %s %s %s %d %d %d %d %d %d %s %d\n",E.nom,E.prenom,E.cin,E.mdp,&E.role,&E.sexe,&E.DATE.jour,&E.DATE.mois,&E.DATE.annee,&E.municipalite,E.numero,&E.vote)!=EOF)
        {
            tab[*n]=E;
            (*n)++;
        }
        for(i=0; i<(*n-1); i++)
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
            fprintf(f2,"%s %s %s %s %d %d %d %d %d %d %s %d\n",tab[i].nom,tab[i].prenom,tab[i].cin,tab[i].mdp,tab[i].role,tab[i].sexe,tab[i].DATE.jour,tab[i].DATE.mois,tab[i].DATE.annee,tab[i].municipalite,tab[i].numero,tab[i].vote);
        }


    }

    fclose(f);
    fclose(f2);
    remove(filename);
    rename("candidatgagnanttrier.txt",filename);
}*/




void filtrer (char *filename,char munie[], char room [] )
{
    gestion_BV L;
    FILE * f=fopen(filename, "r");
    FILE * f2=fopen("filtrer.txt", "w");
    if(f!=NULL)
    {
        while(fscanf(f,"%s %d %d %s %s %s\n",L.identifiant_BV,&L.capacite_electeurs,&L.capacite_observateurs,L.municipalite,L.salle,L.identifiant_AG_BV)!=EOF)
        {
            if(strcmp (L.municipalite ,munie)==0)
                {
                fprintf(f2,"%s %d %d %s %s %s\n",L.identifiant_BV,L.capacite_electeurs,L.capacite_observateurs,L.municipalite,L.salle,L.identifiant_AG_BV);
                }
            if (strcmp(L.salle,room)==0)
               {
                fprintf(f2,"%s %d %d %s %s %s\n",L.identifiant_BV,L.capacite_electeurs,L.capacite_observateurs,L.municipalite,L.salle,L.identifiant_AG_BV);
                }
            
                
            if ((strcmp(L.salle,room)==0)&& (strcmp(L.municipalite ,munie)==0))
               {
                fprintf(f2,"%s %d %d %s %s %s\n",L.identifiant_BV,L.capacite_electeurs,L.capacite_observateurs,L.municipalite,L.salle,L.identifiant_AG_BV);
               }
                 
         }
    }
    fclose(f);
    fclose(f2);
} 




enum {
IDBV,
CAPELE,
CAPOBS,
MUNI,
SALLE,
IDABV,
COLUMNS,
};

void afficher_bv(GtkWidget  *liste, char *filename)
{
GtkCellRenderer *renderer;
GtkTreeViewColumn *Column;
GtkTreeIter iter;
GtkListStore *store;
gestion_BV L;
char cap1[30],cap2[30];
store=NULL;
FILE *f;
store=gtk_tree_view_get_model(liste);


if (store==NULL)
{
renderer=gtk_cell_renderer_text_new();
Column=gtk_tree_view_column_new_with_attributes("Id_bv",renderer,"text",IDBV,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),Column);

renderer=gtk_cell_renderer_text_new();
Column= gtk_tree_view_column_new_with_attributes("capacite\nelecteurs",renderer,"text",CAPELE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),Column);

renderer=gtk_cell_renderer_text_new();
Column=gtk_tree_view_column_new_with_attributes("capacite\nobservateurs",renderer,"text",CAPOBS,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),Column);

renderer=gtk_cell_renderer_text_new();
Column=gtk_tree_view_column_new_with_attributes("municipalite",renderer,"text",MUNI,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),Column);

renderer = gtk_cell_renderer_text_new();
Column = gtk_tree_view_column_new_with_attributes(" Salle",renderer,"text",SALLE, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), Column);

renderer = gtk_cell_renderer_text_new();
Column = gtk_tree_view_column_new_with_attributes("Id_agentbv",renderer,"text",IDABV, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), Column);



}

store = gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);




f = fopen(filename,"r");
if (f==NULL){return;}


else { f = fopen(filename,"a+");

while(fscanf(f,"%s %d %d %s %s %s\n",L.identifiant_BV,&L.capacite_electeurs,&L.capacite_observateurs,L.municipalite,L.salle,L.identifiant_AG_BV)!=EOF)

{

sprintf(cap1,"%d",L.capacite_electeurs);
sprintf(cap2,"%d",L.capacite_observateurs);
gtk_list_store_append (store, &iter);  

gtk_list_store_set (store, &iter, IDBV,L.identifiant_BV, CAPELE, cap1, CAPOBS, cap2, MUNI, L.municipalite,SALLE,L.salle,IDABV,L.identifiant_AG_BV,-1);


}
fclose (f);

gtk_tree_view_set_model (GTK_TREE_VIEW (liste), GTK_TREE_MODEL (store));

g_object_unref (store);
}
     
       
}






