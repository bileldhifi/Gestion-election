#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif
#include <gtk/gtk.h>
#include "fct.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//Ajouter
void ajoutervote(gestion b)
{
    FILE * f=fopen("vote.txt", "a+");
    if(f!=NULL)
    {
        fprintf(f,"%s %s \n",b.idlist,b.list);
        fclose(f);
    }
}
