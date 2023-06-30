#include <stdio.h>
#include <string.h>
#include "utilisateur.h"
#include <gtk/gtk.h>


int ajouter_u(utilisateur u, char *fileName)
{
    FILE *f= fopen(fileName, "a");
    if (f != NULL)
    { 
fprintf(f,"%s %s %s %s %d %d %d %s %s %d\n",u.prenom,u.nom,u.numero,u.MotDePasse,u.dateNaissance.annee,u.dateNaissance.mois,u.dateNaissance.jour,u.role,u.sex,u.cin);
        fclose(f);
    return 1;
    }
else 
 return 0;
}
void Genre(int se , char text1[])
{
if (se==1)
strcpy(text1,"Homme");
if (se==2)
strcpy(text1,"Femme");

}
void verification(int x,char text2[])
{
if(x==1)
strcpy(text2,"je suis pas un rebot");
}


int modifier_u(int cinn, char *fileName, utilisateur nouv)
{ 
 int tr=0;
    utilisateur u;
    FILE *f= fopen(fileName, "r");
    FILE *f2= fopen("nouv.txt", "w");
    if (f!= NULL && f2!=NULL) 
        { 
        while(fscanf(f,"%s %s %s %s %d %d %d %s %s %d\n",u.prenom,u.nom,u.numero,u.MotDePasse,&u.dateNaissance.annee,&u.dateNaissance.mois,&u.dateNaissance.jour,u.role,u.sex,&u.cin)!= EOF)
{
      if (u.cin==cinn)
      {
         fprintf(f2,"%s %s %s %s %d %d %d %s %s %d\n",nouv.prenom,nouv.nom,nouv.numero,nouv.MotDePasse,nouv.dateNaissance.annee,nouv.dateNaissance.mois,nouv.dateNaissance.jour,nouv.role,nouv.sex,nouv.cin);
tr=1;
}
else 
fprintf(f2,"%s %s %s %s %d %d %d %s %s %d\n",u.prenom,u.nom,u.numero,u.MotDePasse,u.dateNaissance.annee,u.dateNaissance.mois,u.dateNaissance.jour,u.role,u.sex,u.cin);
}
}
    fclose(f);
    fclose(f2);
    remove(fileName);
    rename("nouv.txt", fileName);
    return tr;
}

int supprimer_u(int cinn, char *fileName)
{
	int tr=0;
	utilisateur u;
	FILE *f= fopen(fileName, "r");
	FILE *f2= fopen("nouv_u.txt", "w");
	if ((f!= NULL) || (f2!=NULL)) 
        { 
		 while(fscanf(f,"%s %s %s %s %d %d %d %s %s %d\n",u.prenom,u.nom,u.numero,u.MotDePasse,&u.dateNaissance.annee,&u.dateNaissance.mois,&u.dateNaissance.jour,u.role,u.sex,&u.cin)!=EOF)
		{
   			if (u.cin==cinn)
			{tr=1;}
			else 
				fprintf(f2,"%s %s %s %s %d %d %d %s %s %d\n",u.prenom,u.nom,u.numero,u.MotDePasse,u.dateNaissance.annee,u.dateNaissance.mois,u.dateNaissance.jour,u.role,u.sex,u.cin);
		}
	
	fclose(f);
    	fclose(f2);
    	remove(fileName);
    	rename("nouv_u.txt", fileName);
    	return tr;
	}
}

          
utilisateur chercher_u(int cinn, char *fileName)
{

utilisateur u;
 int tr=0;
    FILE * f=fopen(fileName, "r");
 if(f!=NULL )
    {
while(fscanf(f,"%s %s %s %s %d %d %d %s %s %d\n",u.prenom,u.nom,u.numero,u.MotDePasse,&u.dateNaissance.annee,&u.dateNaissance.mois,&u.dateNaissance.jour,u.role,u.sex,&u.cin)!=EOF)
{if(u.cin==cinn)
tr=1;
}
}
fclose(f);
if (tr==0)
{
u.cin=0;
}

return u;

}
enum
{
PRENOM,
NOM,
CI,
DATE_J,
DATE_M,
DATE_A,
SEX,
MOT_PASSE,
NUM,
ROLE,
COLUMNS,
};

void afficher_u(GtkWidget *user)
{
    utilisateur u;
    GtkCellRenderer *renderer;
    GtkTreeViewColumn *Column;
    GtkTreeIter iter;
    GtkListStore *store;

    char dta[20],dtm[20],dtj[20],ci[50];
store=NULL;
FILE *f;
store=gtk_tree_view_get_model(user);

if(store==NULL)
{
  renderer=gtk_cell_renderer_text_new(); 
Column=gtk_tree_view_column_new_with_attributes("Nom",renderer,"text",NOM,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(user),Column);

renderer=gtk_cell_renderer_text_new(); 
Column=gtk_tree_view_column_new_with_attributes("Prenom",renderer,"text",PRENOM,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(user),Column); 

renderer=gtk_cell_renderer_text_new(); 
Column=gtk_tree_view_column_new_with_attributes("Cin",renderer,"text",CI,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(user),Column);

renderer=gtk_cell_renderer_text_new(); 
Column=gtk_tree_view_column_new_with_attributes("Jour",renderer,"text",DATE_J,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(user),Column);   

renderer=gtk_cell_renderer_text_new(); 
Column=gtk_tree_view_column_new_with_attributes("Mois",renderer,"text",DATE_M,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(user),Column);

renderer=gtk_cell_renderer_text_new(); 
Column=gtk_tree_view_column_new_with_attributes("Annee",renderer,"text",DATE_A,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(user),Column);

renderer=gtk_cell_renderer_text_new(); 
Column=gtk_tree_view_column_new_with_attributes("Sex",renderer,"text",SEX,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(user),Column);

renderer=gtk_cell_renderer_text_new(); 
Column=gtk_tree_view_column_new_with_attributes("Mot de passe",renderer,"text",MOT_PASSE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(user),Column);

renderer=gtk_cell_renderer_text_new(); 
Column=gtk_tree_view_column_new_with_attributes("Numero",renderer,"text",NUM,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(user),Column);

renderer=gtk_cell_renderer_text_new(); 
Column=gtk_tree_view_column_new_with_attributes("Role",renderer,"text",ROLE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(user),Column);

}
store=
gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);

    f= fopen("utilisateurs.txt","r");
    if (f== NULL) 
 { return;}
else
{
f= fopen("utilisateurs.txt","a+");

        while(fscanf(f,"%s %s %s %s %d %d %d %s %s %d\n",u.prenom,u.nom,u.numero,u.MotDePasse,&u.dateNaissance.annee,&u.dateNaissance.mois,&u.dateNaissance.jour,u.role,u.sex,&u.cin)!= EOF)
        {
 sprintf(ci,"%d",u.cin);
 sprintf(dtj,"%d",u.dateNaissance.jour);
 sprintf(dtm,"%d",u.dateNaissance.mois);
 sprintf(dta,"%d",u.dateNaissance.annee);
 gtk_list_store_append (store,&iter);
 gtk_list_store_set(store,&iter,NOM,u.nom,PRENOM,u.prenom,CI,ci,DATE_J,dtj,DATE_M,dtm,DATE_A,dta,SEX,u.sex,MOT_PASSE,u.MotDePasse,NUM,u.numero,ROLE,u.role,-1);
}
fclose(f);
gtk_tree_view_set_model (GTK_TREE_VIEW (user), GTK_TREE_MODEL (store));

g_object_unref (store);
}

}

/*float ageMoy(char *fileName)
{
utilisateur u;
int i=0;
int b=0;
float moy;
FILE *f = fopen(fileName, "r");
        if (f != NULL) 
{
while(fscanf(f,"%s %s %s %s %d %d %d %s %s %d %d %d \n",u.prenom,u.nom,u.email,u.MotDePasse,&u.dateNaissance.annee,&u.dateNaissance.mois,&u.dateNaissance.jour,u.role,u.sex,&u.cin,&u.vote,&u.numbv)!= EOF)
   { 
b++;
i+= 2022 - u.dateNaissance.annee;
   }
   }
moy=(float)i/b;
fclose(f);
return (moy);
}


float tauxVoteBlanc (char *fileName)
{
utilisateur u;
int k=0;
int a=0;
float tauxvoteblanc;
FILE *f = fopen(fileName, "r");
        if (f != NULL) 
{
while(fscanf(f,"%s %s %s %s %d %d %d %s %s %d %d %d \n",u.prenom,u.nom,u.email,u.MotDePasse,&u.dateNaissance.annee,&u.dateNaissance.mois,&u.dateNaissance.jour,u.role,u.sex,&u.cin,&u.vote,&u.numbv)!= EOF)
{ if (strcmp(u.role,"electeur")==0)
a++;
if (u.vote ==0) {
k=k+1;
} 
}
tauxvoteblanc=(float)k/a;
fclose(f);
return (tauxvoteblanc);
}
}*/



