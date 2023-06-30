#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "bv.h"
#include "list.h"
#include "statrin.h"
#include "Election.h"
#include "fct.h"
#include "utilisateur.h"

//////rined/////
int choix=0;
int choice=1;
char text[10]="";
char texte[100]="";
char id[10]="";
int x=0;

gestion_BV bv;
gestion_BV B;

////wassim////

int orientation=1;
int t=0;
//int z;
int w;
gestionle n;

/////nessrine/////

int nbHab=1;
int cmpt=0;
int nb_gag;
int choi[]={0,0};

/////bilel //////

utilisateur U;
//int x=0;
int se=1;
char text1[50]="";
char text2[50]="";
int cinn=0;
int a=0;

///////////////////////////////////////////////////////////////////////////////////////////////////////

//connexion

//////////////////////////////////////////////////////////////////////////////////////////////////////

void
on_buttonseconnecter_clicked           (GtkWidget       *objet,
                                        gpointer         user_data)
{
  GtkWidget *username1;
  GtkWidget *pass;
  GtkWidget *window1;
  GtkWidget *window2;
  GtkWidget *output;

char username[30],password[30];


username1 = lookup_widget(objet,"paentryid");
pass = lookup_widget(objet,"paentrymdp");
strcpy(username , gtk_entry_get_text(GTK_ENTRY(username1)));
strcpy(password,gtk_entry_get_text(GTK_ENTRY(pass)));
        
        if((strcmp(username,"admin")==0)&&(strcmp(password,"admin")==0))
        {    
          window1 = lookup_widget(objet,"Page_d_accueil");
          window2 = create_menu ();
          gtk_widget_show (window2);
          gtk_widget_hide(window1);
        }

        else
        {
           output=lookup_widget(objet, "labelidlogin");
           gtk_label_set_text(GTK_LABEL(output),"Identifiant erronnée ");
        }
}

//////////////////////////////////////////////////////////////////////////////////////////////////////

//gestion election: Nessrine Raies

//////////////////////////////////////////////////////////////////////////////////////////////////////

void
on_geradiobutton1_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
  if (gtk_toggle_button_get_active(togglebutton))
  nbHab=1;
}


void
on_geradiobutton2_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
  if (gtk_toggle_button_get_active(togglebutton))
  nbHab=2;
}


void
on_geradiobutton3_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
  if (gtk_toggle_button_get_active(togglebutton))
  nbHab=3;
}


void
on_geradiobutton6_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
  if (gtk_toggle_button_get_active(togglebutton))
  nbHab=4;
}


void
on_geradiobutton5_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
  if (gtk_toggle_button_get_active(togglebutton))
  nbHab=5;
}


void
on_geradiobutton4_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
  if (gtk_toggle_button_get_active(togglebutton))
  nbHab=6;
}


void
on_geradiobutton7_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
  if (gtk_toggle_button_get_active(togglebutton))
  nbHab=7;
}


void
on_gebuttonajouter_clicked             (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
  Election E;
char jour_e[50];
char mois_e[50];
char annee_e[50];
char nbHab_e[30];
int j,m,a;
sprintf(nbHab_e,"%d",nbHab);
GtkWidget*idelection,*jour,*mois,*annee,*municipalite,*nbconseillers,*message;

jour=lookup_widget(objet_graphique,"gespinbuttonjour");
mois=lookup_widget(objet_graphique,"gespinbuttonmois");
annee=lookup_widget(objet_graphique,"gespinbuttonannee");
idelection=lookup_widget(objet_graphique,"geentryidelection");
nbconseillers = lookup_widget(objet_graphique, "geentrynbrc");
municipalite = lookup_widget(objet_graphique, "gecomboboxentrymuniajout");

j=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour));
m=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois));
a=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee));

message = lookup_widget(objet_graphique, "gelabelmessage") ;

sprintf(jour_e,"%d",j);
sprintf(mois_e,"%d",m);
sprintf(annee_e,"%d",a);

strcpy(E.idElection,gtk_entry_get_text(GTK_ENTRY(idelection)));
strcpy(E.DE.jour,jour_e);
strcpy(E.DE.mois,mois_e);
strcpy(E.DE.annee,annee_e);
strcpy(E.municipalite,gtk_combo_box_get_active_text(GTK_COMBO_BOX(municipalite)));
strcpy(E.nbConseillers,gtk_entry_get_text(GTK_ENTRY(nbconseillers)));
strcpy(E.nbHabitants,nbHab_e);
if (ajouter_ge(E)==1) {gtk_label_set_text(GTK_LABEL(message),"Ajout avec succès");}
else {gtk_label_set_text(GTK_LABEL(message),"Echec d'ajout");}
}




void
on_buttonlogoutge_clicked              (GtkWidget       *objet,
                                        gpointer         user_data)
{
  GtkWidget *window1;
  GtkWidget *window2;
  window1 = lookup_widget(objet,"Gestion_des___lections_et_des_utilisateurs");
  window2 = create_menu ();
  gtk_widget_show (window2);
  gtk_widget_hide(window1);
}


void
on_gebuttonmodifier_clicked            (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
  Election E;
GtkWidget *idelection ,*message;

idelection=lookup_widget(objet_graphique,"geentryidelectionmd");
message=lookup_widget(objet_graphique,"gelabelmessagemd");

strcpy(E.idElection,gtk_entry_get_text(GTK_ENTRY(idelection)));

if (chercher_ge(E)==1) {gtk_label_set_text(GTK_LABEL(message),"Veuillez modifier l'élection");}
else {gtk_label_set_text(GTK_LABEL(message),"Entrer un Id existant!");}
}


void
on_gebuttonconfirmer_clicked           (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
  Election E;
char jour_e[50];
char mois_e[50];
char annee_e[50];
char nbHab_e[30];
int j,m,a;
sprintf(nbHab_e,"%d",nbHab);
GtkWidget*idelection,*jour,*mois,*annee,*municipalite,*nbconseillers,*message;

jour=lookup_widget(objet_graphique,"gespinbuttonjourmd");
mois=lookup_widget(objet_graphique,"gespinbuttonmoismd");
annee=lookup_widget(objet_graphique,"gespinbuttonanneemd");
idelection=lookup_widget(objet_graphique,"geentryidelectionmd");
nbconseillers = lookup_widget(objet_graphique, "geentrynbrcmd");
municipalite = lookup_widget(objet_graphique, "gecomboboxentrymunicipalitemd");

j=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour));
m=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois));
a=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee));

message = lookup_widget(objet_graphique, "gelabelmessagemd") ;

sprintf(jour_e,"%d",j);
sprintf(mois_e,"%d",m);
sprintf(annee_e,"%d",a);

strcpy(E.idElection,gtk_entry_get_text(GTK_ENTRY(idelection)));
strcpy(E.DE.jour,jour_e);
strcpy(E.DE.mois,mois_e);
strcpy(E.DE.annee,annee_e);
strcpy(E.municipalite,gtk_combo_box_get_active_text(GTK_COMBO_BOX(municipalite)));
strcpy(E.nbConseillers,gtk_entry_get_text(GTK_ENTRY(nbconseillers)));
strcpy(E.nbHabitants,nbHab_e);
if (modifier_ge(E)==1) {gtk_label_set_text(GTK_LABEL(message),"Modification avec succès");}
else {gtk_label_set_text(GTK_LABEL(message),"Echec de modification");}

}


void
on_geradiobutton9_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
  if (gtk_toggle_button_get_active(togglebutton))
  nbHab=2;
}


void
on_geradiobutton8_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
  if (gtk_toggle_button_get_active(togglebutton))
  nbHab=1;
}


void
on_geradiobutton10_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
  if (gtk_toggle_button_get_active(togglebutton))
  nbHab=3;
}


void
on_geradiobutton13_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
  if (gtk_toggle_button_get_active(togglebutton))
  nbHab=6;
}


void
on_geradiobutton12_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
  if (gtk_toggle_button_get_active(togglebutton))
  nbHab=5;
}


void
on_geradiobutton11_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
  if (gtk_toggle_button_get_active(togglebutton))
  nbHab=4;
}


void
on_geradiobutton14_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
  if (gtk_toggle_button_get_active(togglebutton))
  nbHab=7;
}


void
on_gebuttonafficher_clicked            (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
  GtkWidget *idelectionaff, *GEtreeviewaffich;

GEtreeviewaffich=lookup_widget(objet_graphique,"getreeviewaf");
afficher_election (GEtreeviewaffich);
}


void
on_gecheckbutton1_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
  if (gtk_toggle_button_get_active(togglebutton))
    { choi[0]=1;
      choi[1]=0;}
}


void
on_gecheckbutton2_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
  if (gtk_toggle_button_get_active(togglebutton))
   { choi[0]=0;
     choi[1]=1;}
}


void
on_gebuttonacti_clicked                (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
  Election E;
char id[50];
GtkWidget *idelection, *message;

idelection = lookup_widget(objet_graphique, "geentryidsp") ;
message = lookup_widget(objet_graphique, "gelabelerreursp") ;

strcpy(E.idElection,gtk_entry_get_text(GTK_ENTRY(idelection)));

if(supprimer_ge(E)==1){
	if (choi[0]==1 && choi[1]==0) {gtk_label_set_text(GTK_LABEL(message),"Suppression validée"); }
	else if(choi[0]==0 && choi[1]==1) {gtk_label_set_text(GTK_LABEL(message),"Suppression annulée");}
	else if(choi[0]==0 && choi[1]==0) {gtk_label_set_text(GTK_LABEL(message),"Veuillez cocher une case");}
	           } 
	   
else if(supprimer_ge(E)==0) {
         if(choi[0]==0 || choi[0]==1 || choi[1]==0 || choi[1]==1) {gtk_label_set_text(GTK_LABEL(message),"Veuillez entrer un Id!");}
	else if (choi[0]==1 && choi[1]==0) {gtk_label_set_text(GTK_LABEL(message),"Veuillez entrer un Id!"); }
	else if(choi[0]==0 && choi[1]==1) {gtk_label_set_text(GTK_LABEL(message),"Veuillez entrer un Id!");}
	else if(choi[0]==0 && choi[1]==0) {gtk_label_set_text(GTK_LABEL(message),"Veuillez entrer un Id!");}}
}

///////////////////////////////////////////////////////////////////////////////////////////////////

//gestion utilisateur:Bilel Dhifi

///////////////////////////////////////////////////////////////////////////////////////////////////

void
on_buttonlogoutgu_clicked              (GtkWidget       *objet,
                                        gpointer         user_data)
{
  GtkWidget *window1;
  GtkWidget *window2;
  window1 = lookup_widget(objet,"Gestion_des___lections_et_des_utilisateurs");
  window2 = create_menu ();
  gtk_widget_show (window2);
  gtk_widget_hide(window1);
}

void
on_guradiobuttonhomme_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
 if (gtk_toggle_button_get_active( togglebutton))
 se=1;
}


void
on_guradiobuttonfemme_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
 if (gtk_toggle_button_get_active( togglebutton))
 se=2;
}


void
on_gucheckbutton1_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
 if (gtk_toggle_button_get_active( togglebutton))
 x=1;
}

void
on_gubuttonajouter_clicked             (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
  GtkWidget *input,*output;
  GtkWidget *CIN;
  GtkWidget *Role;
  GtkWidget *markup;
  utilisateur u;
  char cino[30];
  int i=1;


  input=lookup_widget(objet_graphique, "guentrynom");
  strcpy(u.nom, gtk_entry_get_text(GTK_ENTRY(input)));
  if (strcmp(u.nom," ")==0)
   {i=0;} 
  input=lookup_widget(objet_graphique, "guentryprenom");
  strcpy(u.prenom, gtk_entry_get_text(GTK_ENTRY(input)));
  if (strcmp(u.prenom," ")==0)
    {i=0;} 
  CIN=lookup_widget(objet_graphique, "guentrycin");
  strcpy(cino, gtk_entry_get_text(GTK_ENTRY(CIN)));
  u.cin =atoi (cino);
  if ((strcmp(cino," ")==0)||(strlen(cino)!=8))
    {i=0;} 


  input=lookup_widget(objet_graphique, "guspinbuttonjour");
  u.dateNaissance.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input));
  input=lookup_widget(objet_graphique, "guspinbuttonmois");
  u.dateNaissance.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input));
  input=lookup_widget(objet_graphique, "guspinbuttonannee");
  u.dateNaissance.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input));

  input=lookup_widget(objet_graphique, "guentrymdp");
  strcpy(u.MotDePasse, gtk_entry_get_text(GTK_ENTRY(input)));
  if (strcmp(u.MotDePasse," ")==0)
    {i=0;}
  input=lookup_widget(objet_graphique, "guentrynumt");
  strcpy(u.numero, gtk_entry_get_text(GTK_ENTRY(input)));
  if (strcmp(u.numero,"")==0)
    {i=0;}


  Role=lookup_widget(objet_graphique, "gucomboboxrole");
  strcpy(u.role,gtk_combo_box_get_active_text(GTK_COMBO_BOX(Role)));

  Genre(se,text1);
  strcpy(u.sex,text1);

  if(i==1)
          {
            a=ajouter_u(u,"utilisateurs.txt");
            output=lookup_widget(objet_graphique,"gulabelmessage");
            gtk_label_set_markup(GTK_LABEL(output),"<b><span color='green'>*Ajout d'utilisateur avec succée </span></b>");
          }
  if (i!=1)
          {
            output=lookup_widget(objet_graphique,"gulabelmessage");
            gtk_label_set_markup(GTK_LABEL(output),"<b><span color='red'>*Priere de verifier vos données </span></b>");
          }

}





void
on_guradiobuttonhommemd_toggled        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
  if (gtk_toggle_button_get_active( togglebutton))
  se=1;
}


void
on_guradiobuttonfemmemd_toggled        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
  if (gtk_toggle_button_get_active( togglebutton))
  se=2;
}

void
on_gubuttonmodifier_clicked            (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
  GtkWidget *input;
  GtkWidget *output;
  int tr=0;

  input=lookup_widget(objet_graphique, "guentrycinmd");
  cinn =atoi (gtk_entry_get_text(GTK_ENTRY(input)));
  U=chercher_u(cinn,"utilisateurs.txt");
  if (U.cin!=0)
               {
                 output =lookup_widget(objet_graphique, "guentrynommd");
                 gtk_entry_set_text(GTK_ENTRY(output),U.nom);
                 output =lookup_widget(objet_graphique, "guentryprenommd");
                 gtk_entry_set_text(GTK_ENTRY(output),U.prenom);
                 output=lookup_widget(objet_graphique, "guspinbuttonjourmd");

                 gtk_spin_button_set_value(GTK_SPIN_BUTTON(output),U.dateNaissance.jour);
                 output=lookup_widget(objet_graphique, "guspinbuttonmoismd");
                 gtk_spin_button_set_value(GTK_SPIN_BUTTON(output),U.dateNaissance.mois);
                 output=lookup_widget(objet_graphique, "guspinbuttonanneemd");
                 gtk_spin_button_set_value(GTK_SPIN_BUTTON(output),U.dateNaissance.annee);

                 if (strcmp(U.sex ,"Homme")==0)
                                               {
                                                output =lookup_widget(objet_graphique, "guradiobuttonhommemd");
                                                gtk_toggle_button_set_active(GTK_RADIO_BUTTON(output), TRUE);
                                               }
                 else if (strcmp(U.sex ,"Femme")==0)
                                                    {
                                                     output =lookup_widget(objet_graphique, "guradiobuttonfemmemd");
                                                     gtk_toggle_button_set_active(GTK_RADIO_BUTTON(output), TRUE);
                                                    }

                 input=lookup_widget(objet_graphique, "guentrymdpmd");
                 gtk_entry_set_text(GTK_ENTRY(input),U.MotDePasse);
                 input=lookup_widget(objet_graphique, "guentrynumtmd");
                 gtk_entry_set_text(GTK_ENTRY(input),U.numero);

                 if(strcmp(U.role,"Agent")==0)
                                              {
                                                output=lookup_widget(objet_graphique,"gucomboboxrolemd"); 
                                                gtk_combo_box_set_active(output,0);
                                              }

                 if(strcmp(U.role,"Electeur")==0)
                                                 {
                                                   output=lookup_widget(objet_graphique,"gucomboboxrolemd"); 
                                                   gtk_combo_box_set_active(output,1);
                                                 }
                 if(strcmp(U.role,"Observateur")==0)
                                                    {
                                                      output=lookup_widget(objet_graphique,"gucomboboxrolemd"); 
                                                      gtk_combo_box_set_active(output,2);
                                                    }

                else if(strcmp(U.role,"Condidat")==0)
                                                     {
                                                      output=lookup_widget(objet_graphique,"gucomboboxrolemd"); 
                                                      gtk_combo_box_set_active(output,3);
                                                     }
             }
  else 
      {
        output =lookup_widget(objet_graphique, "gulabelmessagemd");
        gtk_label_set_markup(GTK_LABEL(output),"<b><span color='red'>*Priere de verifier cin </span></b>");
      }
}

void
on_gubuttonconfirmer_clicked           (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
  GtkWidget *output;
  GtkWidget *input;

  input =lookup_widget(objet_graphique, "guentrynommd");
  strcpy(U.nom, gtk_entry_get_text(GTK_ENTRY(input))); 
  input =lookup_widget(objet_graphique, "guentryprenommd");
  strcpy(U.prenom, gtk_entry_get_text(GTK_ENTRY(input)));
  input =lookup_widget(objet_graphique, "guentrynumtmd");
  strcpy(U.numero, gtk_entry_get_text(GTK_ENTRY(input)));
  
  input=lookup_widget(objet_graphique, "guspinbuttonjourmd");
  U.dateNaissance.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input));
  input=lookup_widget(objet_graphique, "guspinbuttonmoismd");
  U.dateNaissance.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input));
  input=lookup_widget(objet_graphique, "guspinbuttonanneemd");
  U.dateNaissance.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input));


  input=lookup_widget(objet_graphique, "gucomboboxrolemd");
  strcpy(U.role ,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input)));

  input=lookup_widget(objet_graphique, "guentrymdpmd");
  strcpy(U.MotDePasse, gtk_entry_get_text(GTK_ENTRY(input)));



 Genre(se,text1);
 strcpy(U.sex,text1);

 a=modifier_u(cinn,"utilisateurs.txt",U);
 if( a==1)
         {
          output=lookup_widget(objet_graphique,"gulabelmessagemd");
          gtk_label_set_markup(GTK_LABEL(output),"<b><span color='red'>*Utilisateur modifié avec succée </span></b>");
         }

}





void
on_gubuttonafficher_clicked            (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
  GtkWidget *treeview1;
  treeview1=lookup_widget(objet_graphique,"gutreeviewaf");
  afficher_u (treeview1);
}


void
on_gutreeviewsp_row_activated          (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
   gchar *user0;
   gchar *user1;
   gchar *user2;
   gchar *user3;
   gchar *user4;
   gchar *user5;
   gchar *user6;
   gchar *user7;
   gchar *user8;
   gchar *user9;

   GtkListStore *list_store;
   list_store=gtk_tree_view_get_model(treeview);
   GtkTreeIter   iter;

          if (gtk_tree_model_get_iter(GTK_TREE_MODEL(list_store), &iter, path))
             {
               gtk_tree_model_get(GTK_TREE_MODEL(list_store),&iter,0, &user0, -1);
               gtk_tree_model_get(GTK_TREE_MODEL(list_store),&iter,1, &user1, -1);
               gtk_tree_model_get(GTK_TREE_MODEL(list_store),&iter,2, &user2, -1);
               gtk_tree_model_get(GTK_TREE_MODEL(list_store),&iter,3, &user3, -1);
               gtk_tree_model_get(GTK_TREE_MODEL(list_store),&iter,4, &user4, -1);
               gtk_tree_model_get(GTK_TREE_MODEL(list_store),&iter,5, &user5, -1);
               gtk_tree_model_get(GTK_TREE_MODEL(list_store),&iter,6, &user6, -1);
               gtk_tree_model_get(GTK_TREE_MODEL(list_store),&iter,7, &user7, -1);
               gtk_tree_model_get(GTK_TREE_MODEL(list_store),&iter,8, &user8, -1);
               gtk_tree_model_get(GTK_TREE_MODEL(list_store),&iter,9, &user9, -1);

               strcpy (U.nom ,user0);  
               strcpy (U.prenom,user1); 
               sscanf  (user2,"%d",&U.cin);          
               sscanf  (user3,"%d",&U.dateNaissance.jour);
               sscanf  (user4,"%d",&U.dateNaissance.mois);
               sscanf  (user5,"%d",&U.dateNaissance.annee);
               strcpy (U.sex, user6);
               strcpy (U.MotDePasse, user7);
               strcpy  (U.numero,user8);
               strcpy (U.role, user9);

             }

           a=supprimer_u(U.cin,"utilisateurs.txt");

}


void
on_gubuttonacti_clicked                (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
  GtkWidget *treeview1;
  treeview1=lookup_widget(objet_graphique,"gutreeviewsp");
  afficher_u (treeview1);
}

////////////////////////////////////////////////////////////////////////////////////////////////

//statistique

////////////////////////////////////////////////////////////////////////////////////////////////

void
on_buttonaffbileltaux_clicked          (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{

}


void
on_buttonaffstathf_clicked             (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{

}


void
on_buttonaffageelstat_clicked          (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{

}


void
on_buttonnbreness_clicked              (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{

}


void
on_buttonnbrobsrined_clicked           (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
  GtkWidget *markup;
  GtkWidget *output;
  char ch[20];

int x=nbrobservateur("user.txt");
sprintf(ch,"%d",x);
markup=g_markup_printf_escaped("<big><b><span color='black'>Le nombre est :%s</span></b></big>",ch);
output=lookup_widget(objet_graphique,"nbrobsrined");
gtk_label_set_markup(GTK_LABEL(output),markup);
}


void
on_buttontrieobsrined_clicked          (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{

}


void
on_buttontrieutilirined_clicked        (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{

}


void
on_buttonaffsttwass_clicked            (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{

}


void
on_buttonwasstat_clicked               (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{

}

//////////////////////////////////////////////////////////////////////////////////////////////

//gestion bureaux de votes:Rined Lazreg

//////////////////////////////////////////////////////////////////////////////////////////////

void
on_gbvbuttonlogout_clicked             (GtkWidget *objet, gpointer user_data)
{
  GtkWidget *window1;
  GtkWidget *window2;
  window1 = lookup_widget(objet,"Gestion_des_bureaux_de_vote");
  window2 = create_menu ();
  gtk_widget_show (window2);
  gtk_widget_hide(window1);
}

void
on_gbvcheckbutton_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
  if (gtk_toggle_button_get_active(togglebutton))
   {choix=1;}
}


void
on_gbvradiobutton1_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
   if (gtk_toggle_button_get_active(togglebutton))
   choice =1;
}


void
on_gbvradiobutton2_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
  if (gtk_toggle_button_get_active(togglebutton))
  choice =2;
}


void
on_gbvradiobutton3_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
  if (gtk_toggle_button_get_active(togglebutton))
  choice =3;
}


void
on_gbvbuttonajouter_clicked            (GtkWidget *objet_graphique, gpointer user_data)
{
   GtkWidget *Id;
   GtkWidget *Ce;
   GtkWidget *Co;
   GtkWidget *Municipalite;
   GtkWidget *Id_bv;
   GtkWidget *output,*output1,*output2,*output3;
   gestion_BV L ;
   int i=1 ;


//associer les objets avec variable
Id=lookup_widget(objet_graphique, "gbventryidbv");
Id_bv=lookup_widget(objet_graphique, "gbventryidabv");
Ce=lookup_widget(objet_graphique, "gbvspinbuttonce");
Co=lookup_widget(objet_graphique, "gbvspinbuttonco");
Municipalite=lookup_widget(objet_graphique, "gbvcomboboxmuniajout");


//recuperation des info
L.capacite_electeurs=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(Ce)); 
L.capacite_observateurs=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(Co)); 
strcpy(L.municipalite,gtk_combo_box_get_active_text(GTK_COMBO_BOX(Municipalite)));


strcpy(L.identifiant_BV, gtk_entry_get_text(GTK_ENTRY(Id)));
x=verifier(L.identifiant_BV);
bv=chercher_bv("bv.txt",L.identifiant_BV);

if ((x==0) || (strcmp(L.identifiant_BV, " ")==0)||(strcmp(bv.identifiant_BV,"-1")!=0))
  { 
    output1=lookup_widget(objet_graphique, "labelerreurajrined1");
    gtk_widget_show(output1);
    gtk_label_set_markup(GTK_LABEL(output1),"<b><span color='red'>*identifiant existe déjà\nou different de 9 chiffres</span></b>");
    i=0;
  }

strcpy(L.identifiant_AG_BV, gtk_entry_get_text(GTK_ENTRY(Id_bv)));
x=verifier_ag(L.identifiant_AG_BV);
bv=chercher_agbv("bv.txt", L.identifiant_AG_BV);
if ((x==0) || (strcmp(L.identifiant_AG_BV, " ")==0)||(strcmp(bv.identifiant_AG_BV,"-1")!=0))
 {
   output2=lookup_widget(objet_graphique, "labelerreuragrin");
   gtk_widget_show(output2);
   gtk_label_set_markup(GTK_LABEL(output2),"<b><span color='red'>*identifiant existe déjà\nou different de 8 chiffres</span></b>");
   i=0;
 }
notRobot( choix , texte);
numsalle(choice , text);
strcpy(L.salle,text);

if (choix !=1)
  {
     output3=lookup_widget(objet_graphique, "gbvlabelerreurrobot");
     gtk_widget_show(output3);
     gtk_label_set_markup(GTK_LABEL(output3),"<b><span color='red'>* champ obligatoire !! </span></b>");
     i=0;
  }

if (i==1)
  {
    x=ajouterBV("bv.txt" , L );
    output=lookup_widget(objet_graphique, "labelerreurajrined2");   
    gtk_label_set_markup(GTK_LABEL(output),"<b><span color='green'>* Le bureau de vote est ajouté avec succée </span></b>");
    output1=lookup_widget(objet_graphique, "labelerreurajrined1");
    gtk_widget_hide(output1);
    output2=lookup_widget(objet_graphique, "labelerreuragrin");
    gtk_widget_hide(output2);
    output3=lookup_widget(objet_graphique, "gbvlabelerreurrobot");
    gtk_widget_hide(output3);
    
  }
else 
  {
    output=lookup_widget(objet_graphique, "labelerreurajrined2");   
    gtk_label_set_markup(GTK_LABEL(output),"<b><span color='red'>*Echec de l'ajout </span></b>");
  }

}


void
on_gbvradiobutton1md_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
  if (gtk_toggle_button_get_active(togglebutton))
  choice =1;
}


void
on_gbvradiobutton3md_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
  if (gtk_toggle_button_get_active(togglebutton))
  choice =3;
}


void
on_gbvradiobutton2md_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
  if (gtk_toggle_button_get_active(togglebutton))
  choice =2;
}



void
on_gbvbuttonmodifier_clicked           (GtkWidget *objet_graphique, gpointer user_data)
{
  GtkWidget* input;
   GtkWidget* output;
   GtkWidget* CE; 
   GtkWidget* CO;
   
   input= lookup_widget(objet_graphique, "gbventryidmd");
   strcpy(id, gtk_entry_get_text(GTK_ENTRY(input)));
   bv=chercher_bv("bv.txt" ,id);
   if(strcmp(bv.identifiant_BV,"-1")!=0)
    {
      //output=lookup_widget(objet_graphique,"idbv_modif");
      //gtk_entry_set_text(GTK_ENTRY(output),bv.identifiant_BV);
      output=lookup_widget(objet_graphique,"gbventryidabvmd");
      gtk_entry_set_text(GTK_ENTRY(output),bv.identifiant_AG_BV);
      
    if(strcmp(bv.municipalite,"Tunis")==0)
      {
       output=lookup_widget(objet_graphique,"gbvcomboboxmunimodif");
       gtk_combo_box_set_active(output,0);
      }

     if(strcmp(bv.municipalite,"Ariana")==0)
      {
       output=lookup_widget(objet_graphique,"gbvcomboboxmunimodif");
       gtk_combo_box_set_active(output,1);
      }

       if(strcmp(bv.municipalite,"Manouba")==0)
      {
       output=lookup_widget(objet_graphique,"gbvcomboboxmunimodif");
       gtk_combo_box_set_active(output,2);
      }

      GtkSpinButton *CE=lookup_widget(objet_graphique, "gbvspinbuttoncemd");
      gtk_spin_button_set_value(CE,bv.capacite_electeurs);

      GtkSpinButton *CO=lookup_widget(objet_graphique, "gbvspinbuttoncomd");
      gtk_spin_button_set_value(CO,bv.capacite_observateurs);

     if(strcmp(bv.salle,"salle1")==0)
       {
        output=lookup_widget(objet_graphique,"gbvradiobutton1md");
        gtk_toggle_button_set_active(GTK_RADIO_BUTTON(output),TRUE);
       }
     if(strcmp(bv.salle,"salle2")==0)
       {
        output=lookup_widget(objet_graphique,"gbvradiobutton2md");
        gtk_toggle_button_set_active(GTK_RADIO_BUTTON(output),TRUE);
       }
     else if (strcmp(bv.salle,"salle3")==0)
            {
             output=lookup_widget(objet_graphique,"gbvradiobutton3md");
             gtk_toggle_button_set_active(GTK_RADIO_BUTTON(output),TRUE);
            }
    }
  else
     {
      output=lookup_widget(objet_graphique, "labelerreurmod1");
           gtk_label_set_markup(GTK_LABEL(output),"<b><span color='red'>* Priere de verifier l'identifiant </span></b>");
      }
}




void
on_gbvbuttonconfirmer_clicked          (GtkWidget *objet_graphique, gpointer user_data)
{
  GtkWidget* output,*output2;
   GtkWidget* input;
   int x=0;
   int i=1;
   
  
   output=lookup_widget(objet_graphique, "gbventryidmd");
   gtk_entry_set_text(GTK_ENTRY(output),bv.identifiant_BV);
   output=lookup_widget(objet_graphique, "gbventryidabvmd");
   strcpy(bv.identifiant_AG_BV,gtk_entry_get_text(GTK_ENTRY(output)));
   x=verifier_ag(bv.identifiant_AG_BV);
   B=chercher_agbv("bv.txt", bv.identifiant_AG_BV);
   if ((x==0) || (strcmp(bv.identifiant_AG_BV, " ")==0)||(strcmp(B.identifiant_AG_BV,"-1")!=0))
     {
       output2=lookup_widget(objet_graphique, "labelerreurmodagbv");
       gtk_widget_show(output2);
       gtk_label_set_markup(GTK_LABEL(output2),"<b><span color='red'>*identifiant existe déjà ou different de 8 chiffres</span></b>");
       i=0;
     }

   input=lookup_widget(objet_graphique, "gbvcomboboxmunimodif");
   strcpy(bv.municipalite,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input)));


   numsalle(choice , text);
   strcpy(bv.salle, text);

   input=lookup_widget(objet_graphique, "gbvspinbuttoncemd");
   bv.capacite_electeurs=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input));

   input=lookup_widget(objet_graphique, "gbvspinbuttoncomd"); 
   bv.capacite_observateurs=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input)); 
  
   if (i==1)
    {
      x=modifierBV("bv.txt", id, bv );
      output=lookup_widget(objet_graphique, "labelerreurmod2");
      gtk_label_set_markup(GTK_LABEL(output),"<b><span color='green'>* modification de bureau de vote avec succée </span></b>");
      output2=lookup_widget(objet_graphique, "labelerreurmodagbv");
      gtk_widget_hide(output2);
    }
       
   else 
       {
           output=lookup_widget(objet_graphique, "labelerreurmod2");
           gtk_label_set_markup(GTK_LABEL(output),"<b><span color='red'>* Echec de modification </span></b>");
           
       }
}



void
on_gbvbuttonfiltrer_clicked            (GtkWidget *objet_graphique, gpointer user_data)
{
  GtkWidget *treeview1;
 GtkWidget *input;
 char munie[50];
 char room[50];

 input=lookup_widget(objet_graphique,"entrymunibv");
 strcpy(munie,gtk_entry_get_text(GTK_ENTRY(input)));
 input=lookup_widget(objet_graphique,"entrysallebv");
 strcpy(room,gtk_entry_get_text(GTK_ENTRY(input)));

 filtrer ("bv.txt",munie,room) ;
 treeview1=lookup_widget(objet_graphique,"gbvtreeviewaf");
 afficher_bv (treeview1,"filtrer.txt");
}


void
on_gbvbuttonafficher_clicked           (GtkWidget *objet_graphique, gpointer user_data)
{
  GtkWidget *treeview1;



treeview1=lookup_widget(objet_graphique,"gbvtreeviewaf");
afficher_bv(treeview1, "bv.txt");
}


void
on_gbvtreeviewsp_row_activated         (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
  gchar *data0;
gchar *data1;
gchar *data2;
gchar *data3;
gchar *data4;
gchar *data5;

GtkListStore *list_store;
list_store=gtk_tree_view_get_model(treeview);
GtkTreeIter   iter;

          if (gtk_tree_model_get_iter(GTK_TREE_MODEL(list_store), &iter, path))
     {
gtk_tree_model_get(GTK_TREE_MODEL(list_store),&iter, 0, &data0, -1);
gtk_tree_model_get(GTK_TREE_MODEL(list_store),&iter,1, &data1, -1);
gtk_tree_model_get(GTK_TREE_MODEL(list_store),&iter,2, &data2, -1);
gtk_tree_model_get(GTK_TREE_MODEL(list_store),&iter, 3, &data3, -1);
gtk_tree_model_get(GTK_TREE_MODEL(list_store),&iter,4, &data4, -1);
gtk_tree_model_get(GTK_TREE_MODEL(list_store),&iter,5, &data5, -1);

strcpy (bv.identifiant_BV, data0);             
sscanf (data1,"%d",&bv.capacite_electeurs);
sscanf  (data2,"%d",&bv.capacite_observateurs);

strcpy (bv.municipalite, data3);
strcpy (bv.salle, data4);
strcpy (bv.identifiant_AG_BV, data5);


}
int x;

x=supprimerBV("bv.txt",bv.identifiant_BV);

}


void
on_gbvbuttonactirin_clicked            (GtkWidget *objet_graphique, gpointer user_data)
{
  GtkWidget *treeview1;
  GtkWidget *output;





  treeview1=lookup_widget(objet_graphique,"gbvtreeviewsp");

  afficher_bv(treeview1, "bv.txt");
  output=lookup_widget(objet_graphique, "gbvlabelerreursup");
  gtk_label_set_markup(GTK_LABEL(output),"<b><span color='green'>* Suppression avec succées </span></b>");
  //gtk_widget_hide(output);

}

/////////////////////////////////////////////////////////////////////////////////////////////////

//gestion listes electorale:Mohammed wassim ennar

/////////////////////////////////////////////////////////////////////////////////////////////////

void
on_glbuttonlogout_clicked              (GtkWidget       *objet,
                                        gpointer         user_data)
{
  GtkWidget *window1;
  GtkWidget *window2;
  window1 = lookup_widget(objet,"Gestion_des_listes___lectorales");
  window2 = create_menu ();
  gtk_widget_show (window2);
  gtk_widget_hide(window1);
}


void
on_glbuttonajouter_clicked             (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
  gestionle l;
char jour_l[50];
char mois_l[50];
char annee_l[50];
char orientation_l[30];
int j,m,a;
sprintf(orientation_l,"%d",orientation);
GtkWidget*idliste,*nomliste,*cinp,*municipalite,*jour,*mois,*annee,*candidat1,*candidat2,*candidat3,*message;
//GtkWidget *window;
//window=lookup_widget(objet_graphique,"Gestion des listes électorales");

jour=lookup_widget(objet_graphique,"glspinbuttonjour");
mois=lookup_widget(objet_graphique,"glspinbuttonmois");
annee=lookup_widget(objet_graphique,"glspinbuttonannee");
idliste=lookup_widget(objet_graphique,"glentryidliste");
nomliste = lookup_widget(objet_graphique, "glentrynomliste");
cinp = lookup_widget(objet_graphique, "glentrycinp");
candidat1=lookup_widget(objet_graphique,"glentrycandidat1");
candidat2=lookup_widget(objet_graphique,"glentrycandidat2");
candidat3=lookup_widget(objet_graphique,"glentrycandidat3");
municipalite = lookup_widget(objet_graphique, "glcomboboxmunicipalite");

j=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour));
m=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois));
a=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee));

message = lookup_widget(objet_graphique, "gllabelmessage") ;

sprintf(jour_l,"%d",j);
sprintf(mois_l,"%d",m);
sprintf(annee_l,"%d",a);

strcpy(l.identifiant,gtk_entry_get_text(GTK_ENTRY(idliste)));
strcpy(l.nomdelaliste,gtk_entry_get_text(GTK_ENTRY(nomliste)));
strcpy(l.cinpresident,gtk_entry_get_text(GTK_ENTRY(cinp)));
strcpy(l.candidat1,gtk_entry_get_text(GTK_ENTRY(candidat1)));
strcpy(l.candidat2,gtk_entry_get_text(GTK_ENTRY(candidat2)));
strcpy(l.candidat3,gtk_entry_get_text(GTK_ENTRY(candidat3)));
strcpy(l.DATE.jour,jour_l);
strcpy(l.DATE.mois,mois_l);
strcpy(l.DATE.annee,annee_l);
strcpy(l.municipalite,gtk_combo_box_get_active_text(GTK_COMBO_BOX(municipalite)));
strcpy(l.orientation,orientation_l);
w=verifier_l(l.identifiant);
if ((t==1)&&(w==0))
{ajouter(l);
gtk_label_set_text(GTK_LABEL(message),"Ajout avec succés");
}
else 
{
gtk_label_set_text(GTK_LABEL(message),"Confirmer les données!");
}
}


void
on_glcheckbutton_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
   if (gtk_toggle_button_get_active(togglebutton))
   {t=1;}
}


void
on_glradiobuttondr_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
  if (gtk_toggle_button_get_active(togglebutton))
  orientation=1;
}


void
on_glradiobuttong_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
  if (gtk_toggle_button_get_active(togglebutton))
  orientation=2;
}


void
on_glradiobuttonce_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
  if (gtk_toggle_button_get_active(togglebutton))
  orientation=3;
}


void
on_glbuttonmodifier_clicked            (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
  GtkWidget*id_chercher,*NL,*CP,*MUN,*JOURS,*MOISS,*ANNEES,*ORIEN,*C1,*C2,*C3,*message;
	 
	  GtkWidget *orientation1, *orientation2, *orientation3;

	id_chercher=lookup_widget(objet_graphique,"glentryidlistemd");
	NL =lookup_widget(objet_graphique,"glentrynomlistemd");
	CP =lookup_widget(objet_graphique,"glentrycinpmd");
	C1 =lookup_widget(objet_graphique,"glentrycandidat1md");
	C2 =lookup_widget(objet_graphique,"glentrycandidat2md");
	C3 =lookup_widget(objet_graphique,"glentrycandidat3md");
	orientation1=lookup_widget(objet_graphique,"glradiobuttondmd");
	orientation2=lookup_widget(objet_graphique,"glradiobuttongmd");
	orientation3=lookup_widget(objet_graphique,"glradiobuttoncmd");

	char id_ch[50];
	int  jo,mo,an;

	strcpy(id_ch,gtk_entry_get_text(GTK_ENTRY(id_chercher)));
	
	n= chercher(id_ch);

if(strcmp(n.identifiant,"-1")!=0)
{	
message= lookup_widget (objet_graphique ,"gllabelmessagemd");
gtk_label_set_text(GTK_LABEL(message),"La liste existe!");
gtk_widget_show (message);

	jo=atoi(n.DATE.jour);
	mo=atoi(n.DATE.mois);
	an=atoi(n.DATE.annee);
	
	 JOURS=lookup_widget(objet_graphique,"glspinbuttonjourmd");
         gtk_spin_button_set_value(JOURS,jo);
	 MOISS=lookup_widget(objet_graphique,"glspinbuttonmoismd");
         gtk_spin_button_set_value(MOISS,mo);
	 ANNEES=lookup_widget(objet_graphique,"glspinbuttonanneemd");
         gtk_spin_button_set_value(ANNEES,an);
	 gtk_entry_set_text(GTK_ENTRY(NL),n.nomdelaliste);
	 gtk_entry_set_text(GTK_ENTRY(CP),n.cinpresident);
	 gtk_entry_set_text(GTK_ENTRY(C1),n.candidat1);
	 gtk_entry_set_text(GTK_ENTRY(C2),n.candidat2);
	 gtk_entry_set_text(GTK_ENTRY(C3),n.candidat3);

if(strcmp(n.orientation,"1")==0)
       {
        gtk_toggle_button_set_active(GTK_RADIO_BUTTON(orientation1),TRUE);
       }
     else if(strcmp(n.orientation,"2")==0)
       {
        gtk_toggle_button_set_active(GTK_RADIO_BUTTON(orientation2),TRUE);
       }
           else {
             
             gtk_toggle_button_set_active(GTK_RADIO_BUTTON(orientation3),TRUE);
		}

	 MUN=lookup_widget(objet_graphique,"glcomboboxmunicipalitemd");
	 if(strcmp(n.municipalite,"Tunis")==0)
		{
         	gtk_combo_box_set_active(MUN,0);
		}
	 else if(strcmp(n.municipalite,"Bizerte")==0)
		{
         	gtk_combo_box_set_active(MUN,1);
		}
	 else if(strcmp(n.municipalite,"Ariana")==0)
		{
         	gtk_combo_box_set_active(MUN,2);
		}
	 else if(strcmp(n.municipalite,"Kairaouan")==0)
		{
         	gtk_combo_box_set_active(MUN,3);
		}
	 else 
		{
         	gtk_combo_box_set_active(MUN,4);
	        }
}
	else{
	message= lookup_widget (objet_graphique,"gllabelmessagemd");
	gtk_label_set_text(GTK_LABEL(message),"La liste n'existe pas");
	gtk_widget_show (message);
	}

}


void
on_glbuttonconfirmer_clicked           (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
  gestionle l2;
char jour_l[50];
char mois_l[50];
char annee_l[50];
char orientation_l[30];
int j,m,a;
sprintf(orientation_l,"%d",orientation);
GtkWidget*idliste,*nomliste,*cinp,*municipalite,*jour,*mois,*annee,*candidat1,*candidat2,*candidat3,*message;
//GtkWidget *window;
//window=lookup_widget(objet_graphique,"Gestion des listes électorales");

jour=lookup_widget(objet_graphique,"glspinbuttonjourmd");
mois=lookup_widget(objet_graphique,"glspinbuttonmoismd");
annee=lookup_widget(objet_graphique,"glspinbuttonanneemd");
idliste=lookup_widget(objet_graphique,"glentryidlistemd");
nomliste = lookup_widget(objet_graphique,"glentrynomlistemd");
cinp = lookup_widget(objet_graphique, "glentrycinpmd");
candidat1=lookup_widget(objet_graphique,"glentrycandidat1md");
candidat2=lookup_widget(objet_graphique,"glentrycandidat2md");
candidat3=lookup_widget(objet_graphique,"glentrycandidat3md");
municipalite = lookup_widget(objet_graphique, "glcomboboxmunicipalitemd");

j=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour));
m=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois));
a=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee));

message = lookup_widget(objet_graphique, "gllabelmessagecf") ;

sprintf(jour_l,"%d",j);
sprintf(mois_l,"%d",m);
sprintf(annee_l,"%d",a);

strcpy(l2.identifiant,gtk_entry_get_text(GTK_ENTRY(idliste)));
strcpy(l2.nomdelaliste,gtk_entry_get_text(GTK_ENTRY(nomliste)));
strcpy(l2.cinpresident,gtk_entry_get_text(GTK_ENTRY(cinp)));
strcpy(l2.candidat1,gtk_entry_get_text(GTK_ENTRY(candidat1)));
strcpy(l2.candidat2,gtk_entry_get_text(GTK_ENTRY(candidat2)));
strcpy(l2.candidat3,gtk_entry_get_text(GTK_ENTRY(candidat3)));
strcpy(l2.DATE.jour,jour_l);
strcpy(l2.DATE.mois,mois_l);
strcpy(l2.DATE.annee,annee_l);
strcpy(l2.municipalite,gtk_combo_box_get_active_text(GTK_COMBO_BOX(municipalite)));
strcpy(l2.orientation,orientation_l);

supprimer(n);

ajouter(l2);

gtk_label_set_text(GTK_LABEL(message),"Modification avec succés");
}


void
on_glradiobuttondroitemd_toggled       (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
  if (gtk_toggle_button_get_active(togglebutton))
  orientation=1;
}


void
on_glradiobuttongauchemd_toggled       (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
  if (gtk_toggle_button_get_active(togglebutton))
  orientation=2;
}


void
on_glradiobuttoncentremd_toggled       (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
  if (gtk_toggle_button_get_active(togglebutton))
  orientation=3;
}


void
on_glbuttonafficher_clicked            (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
   GtkWidget *treeview;
  treeview= lookup_widget(objet_graphique, "gltreeviewaf");
  afficher(treeview);
}


void
on_gltreeviewsp_row_activated          (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
   gestionle l;
gchar *pc0;
gchar *pc1;
gchar *pc2;
gchar *pc3;
gchar *pc4;
gchar *pc5;
gchar *pc6;
gchar *pc7;
gchar *pc8;
gchar *pc9;
gchar *pc10;


GtkListStore *list_store;
list_store=gtk_tree_view_get_model(treeview);
GtkTreeIter   iter;

          if (gtk_tree_model_get_iter(GTK_TREE_MODEL(list_store), &iter, path))
     {
gtk_tree_model_get(GTK_TREE_MODEL(list_store),&iter, 0, &pc0, -1);
gtk_tree_model_get(GTK_TREE_MODEL(list_store),&iter,1, &pc1, -1);
gtk_tree_model_get(GTK_TREE_MODEL(list_store),&iter,2, &pc2, -1);
gtk_tree_model_get(GTK_TREE_MODEL(list_store),&iter, 3, &pc3, -1);
gtk_tree_model_get(GTK_TREE_MODEL(list_store),&iter,4, &pc4, -1);
gtk_tree_model_get(GTK_TREE_MODEL(list_store),&iter,5, &pc5, -1);
gtk_tree_model_get(GTK_TREE_MODEL(list_store),&iter, 6, &pc6, -1);
gtk_tree_model_get(GTK_TREE_MODEL(list_store),&iter,7, &pc7, -1);
gtk_tree_model_get(GTK_TREE_MODEL(list_store),&iter,8, &pc8, -1);
gtk_tree_model_get(GTK_TREE_MODEL(list_store),&iter, 9, &pc9, -1);
gtk_tree_model_get(GTK_TREE_MODEL(list_store),&iter,10, &pc10, -1);


strcpy (l.identifiant, pc0);            
strcpy (l.nomdelaliste, pc1);
strcpy (l.cinpresident, pc2);
strcpy (l.municipalite, pc3);
strcpy (l.DATE.jour, pc4);            
strcpy (l.DATE.mois, pc5);
strcpy (l.DATE.annee, pc6);
strcpy (l.orientation, pc7);
strcpy (l.candidat1, pc8);            
strcpy (l.candidat2, pc9);
strcpy (l.candidat3, pc10);
}
supprimer(l);
afficher(treeview);
}


void
on_glbuttonsp_clicked                  (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
   GtkWidget *treeview1;
  treeview1=lookup_widget(objet_graphique,"gltreeviewsp");
  afficher(treeview1);
}


////////////////////////////////////////////////////////////////////////////////////////////////////////

//vote

////////////////////////////////////////////////////////////////////////////////////////////////////////

void
on_buttonvoter_clicked                 (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
  gestion b;
  GtkWidget*idlel,*liste,*message;

  idlel=lookup_widget(objet_graphique,"entry5");

  liste = lookup_widget(objet_graphique, "combobox5");

  //message = lookup_widget(objet_graphique, "label3") ;

  strcpy(b.idlist,gtk_entry_get_text(GTK_ENTRY(idlel)));
  strcpy(b.list,gtk_combo_box_get_active_text(GTK_COMBO_BOX(liste)));

  ajoutervote(b);
  //gtk_label_set_text(GTK_LABEL(message),"Vote avec succés");
}

///////////////////////////////////////////////////////////////////////////////////////////////////////

//Menu

///////////////////////////////////////////////////////////////////////////////////////////////////////

void
on_buttonesel_clicked                  (GtkWidget       *objet,
                                        gpointer         user_data)
{
  GtkWidget *window1;
  GtkWidget *window2;
  window1 = lookup_widget(objet,"menu");
  window2 = create_Gestion_des___lections_et_des_utilisateurs ();
  gtk_widget_show (window2);
  gtk_widget_hide(window1);
}


void
on_buttonbv_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{
  GtkWidget *window1;
  GtkWidget *window2;
  window1 = lookup_widget(objet,"menu");
  window2 = create_Gestion_des_bureaux_de_vote ();
  gtk_widget_show (window2);
  gtk_widget_hide(window1);
}


void
on_buttonelecteur_clicked              (GtkWidget       *objet,
                                        gpointer         user_data)
{
  GtkWidget *window1;
  GtkWidget *window2;
  window1 = lookup_widget(objet,"menu");
  window2 = create_Gestion_des_listes___lectorales ();
  gtk_widget_show (window2);
  gtk_widget_hide(window1);
}


void
on_buttondec_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)
{
  GtkWidget *window1;
  GtkWidget *window2;
  window1 = lookup_widget(objet,"menu");
  window2 = create_Page_d_accueil ();
  gtk_widget_show (window2);
  gtk_widget_destroy(window1);
}




