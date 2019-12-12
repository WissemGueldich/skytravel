#include <stdlib.h>
#include <stdio.h>
#include "vol.h"
#include <string.h>
#include <gtk/gtk.h>
#include <ctype.h>
str2 c2;

void ajoutvol(destination dist,date d,char heure[],int enf, int adul,int classe)
{
FILE *f=fopen("volres.txt","a+");
if (f!=NULL)
{
fprintf(f,"%s %s %s %s %i/%i/%i %s %i%i %i \n", dist.pays,dist.ville,dist.paysar,dist.villear,d.j,d.m,d.a,heure,enf,adul,classe);}



fclose(f);
}

void agentajoutvol(destination dist,str1 c1)
{
FILE *f=fopen("vols.txt","a+");
if (f!=NULL)
{
fprintf(f,"%s %s %s %s %s %s %s \n", dist.pays,dist.ville,dist.paysar,dist.villear,c1.adeco,c1.adbuis,c1.adfc);}

fclose(f);
}
enum
{
	Pays_depare,
	Ville_depare,
	Pays_arrive,
	Ville_arrive,
	Date,
	Heure,
	Categorie,
	Classe,
	COLUMNS
};

void afficher_vol(GtkWidget *liste, str c)
{
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;

store=NULL;
FILE *f;

store=GTK_LIST_STORE(gtk_tree_view_get_model(GTK_TREE_VIEW(liste)));
if (store==NULL)
{
renderer=gtk_cell_renderer_text_new ();
column=gtk_tree_view_column_new_with_attributes(" pays_depart",renderer, "text",Pays_depare,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new ();
column=gtk_tree_view_column_new_with_attributes("ville_depart",renderer, "text",Ville_depare,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new ();
column=gtk_tree_view_column_new_with_attributes("pays_arrive",renderer, "text",Pays_arrive,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new ();
column=gtk_tree_view_column_new_with_attributes("ville_arrive",renderer, "text",Ville_arrive,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new ();
column=gtk_tree_view_column_new_with_attributes("date",renderer, "text",Date,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new ();
column=gtk_tree_view_column_new_with_attributes("heure",renderer, "text",Heure,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new ();
column=gtk_tree_view_column_new_with_attributes("categorie",renderer, "text",Categorie,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new ();
column=gtk_tree_view_column_new_with_attributes("classe",renderer, "text",Classe,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column);


store=gtk_list_store_new(COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);
f = fopen("volres.txt", "r");

if(f==NULL)
{return;}
else
{f = fopen("volres.txt", "a+");
 	while(fscanf(f,"%s %s %s %s %s %s %s %s \n",c.pays_depare,  c.ville_depare ,c.pays_arrive ,c.ville_arrive ,c.date ,c.heure ,c.categorie ,c.classe)!=EOF)
{
gtk_list_store_append(store, &iter);
gtk_list_store_set(store, &iter,Pays_depare,c.pays_depare,  Ville_depare,c.ville_depare ,Pays_arrive,c.pays_arrive ,Ville_arrive,c.ville_arrive,Date,c.date,Heure,c.heure,Categorie,c.categorie
,Classe,c.classe, -1);
}
fclose(f);
gtk_tree_view_set_model (GTK_TREE_VIEW (liste), GTK_TREE_MODEL (store));
g_object_unref (store);	
}
}
}
void dell_volclient(char *pays_arrive)
{str c;
FILE *old;
FILE *new=NULL;
old=fopen("volres.txt","r");
new=fopen("volres_test.txt","a");


while(fscanf(old,"%s %s %s %s %s %s %s %s",c.pays_depare,  c.ville_depare ,c.pays_arrive ,c.ville_arrive ,c.date ,c.heure ,c.categorie ,c.classe)!=EOF)
{if(strcmp(c.pays_arrive,pays_arrive)!=0)
{       

fprintf(new,"%s %s %s %s %s %s %s %s \n",c.pays_depare ,c.ville_depare ,c.pays_arrive ,c.ville_arrive ,c.date ,c.heure ,c.categorie ,c.classe);
}
}
fclose(new);   
fclose(old);
remove("volres.txt");
rename("volres_test.txt","volres.txt");

}




enum
{
	PAys_depare,
	VIlle_depare,
	PAys_arrive,
	VIlle_arrive,
	Adfc,
	Adbuis,
	Adeco,
	
	COLUMNSS
};

void afficher_vol1(GtkWidget *liste, str2 c2)
{
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;

store=NULL;
FILE *f;

store=GTK_LIST_STORE(gtk_tree_view_get_model(GTK_TREE_VIEW(liste)));
if (store==NULL)
{
renderer=gtk_cell_renderer_text_new ();
column=gtk_tree_view_column_new_with_attributes("pays_depart",renderer, "text",PAys_depare,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new ();
column=gtk_tree_view_column_new_with_attributes("ville_depart",renderer, "text",VIlle_depare,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new ();
column=gtk_tree_view_column_new_with_attributes("pays_arrive",renderer, "text",PAys_arrive,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new ();
column=gtk_tree_view_column_new_with_attributes("ville_arrive",renderer, "text",VIlle_arrive,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new ();
column=gtk_tree_view_column_new_with_attributes("adulte fc",renderer, "text",Adfc,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new ();
column=gtk_tree_view_column_new_with_attributes("adulte buis",renderer, "text",Adbuis,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new ();
column=gtk_tree_view_column_new_with_attributes("adulte eco",renderer, "text",Adeco,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column);




store=gtk_list_store_new(COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);
f = fopen("vols.txt", "r");

if(f==NULL)
{return;}
else
{f = fopen("vols.txt", "a+");
 	while(fscanf(f,"%s %s %s %s %s %s %s\n",c2.pays_depare,  c2.ville_depare,c2.pays_arrive,c2.ville_arrive,c2.adfc,c2.adbuis,c2.adeco)!=EOF)
{
gtk_list_store_append(store, &iter);
gtk_list_store_set(store, &iter,Pays_depare,c2.pays_depare,  Ville_depare,c2.ville_depare,Pays_arrive,c2.pays_arrive,Ville_arrive,c2.ville_arrive,Adfc,c2.adfc,Adbuis,c2.adbuis
 ,Adeco,c2.adeco, -1);
}
fclose(f);
gtk_tree_view_set_model (GTK_TREE_VIEW (liste), GTK_TREE_MODEL (store));
g_object_unref (store);	
}
}
}
void dell_volagent(char *pays_depare)
{

str1 c1;
FILE *old;
FILE *new=NULL;
old=fopen("vols.txt","r");
new=fopen("vols_test.txt","a");


while(fscanf(old,"%s %s %s %s %s %s %s \n",c1.pays_depare,c1.ville_depare ,c1.pays_arrive ,c1.ville_arrive ,c1.adfc ,c1.adbuis ,c1.adeco )!=EOF)
{if(strcmp(c1.pays_depare,pays_depare)!=0)
{       

fprintf(new,"%s %s %s %s %s %s %s \n",c1.pays_depare,  c1.ville_depare ,c1.pays_arrive ,c1.ville_arrive ,c1.adfc ,c1.adbuis ,c1.adeco);
}
}
fclose(new);   
fclose(old);
remove("vols.txt");
rename("vols_test.txt","vols.txt");

}

int intpays(char *pays)
{
if (strcmp(pays,"Tunisie")==0)
{return 0;}
else if (strcmp(pays,"France")==0)
{return 1;}
else if (strcmp(pays,"Italy")==0)
{return 2;}
else if (strcmp(pays,"Usa")==0)
{return 3;}
}
int intville(char *pays,char *ville)
{
if (strcmp(pays,"Tunisie")==0 && strcmp(ville,"Cartage")==0)
{return 0;}
else if (strcmp(pays,"Tunisie")==0 && strcmp(ville,"Hamamet")==0)
{return 1;}
else if (strcmp(pays,"Tunisie")==0 && strcmp(ville,"Monastir")==0)
{return 2;}

else if (strcmp(pays,"France")==0 && strcmp(ville,"Lyon")==0)
{return 0;}
else if (strcmp(pays,"France")==0 && strcmp(ville,"Paris")==0)
{return 1;}
else if (strcmp(pays,"France")==0 && strcmp(ville,"Monaco")==0)
{return 2;}

else if (strcmp(pays,"Italy")==0 && strcmp(ville,"Palermo")==0)
{return 0;}
else if (strcmp(pays,"Italy")==0 && strcmp(ville,"Milano")==0)
{return 1;}
else if (strcmp(pays,"Italy")==0 && strcmp(ville,"Roma")==0)
{return 2;}

else if (strcmp(pays,"Use")==0 && strcmp(ville,"Lasvegas")==0)
{return 0;}
else if (strcmp(pays,"Use")==0 && strcmp(ville,"Newyork")==0)
{return 1;}
else if (strcmp(pays,"Use")==0 && strcmp(ville,"Losangeles")==0)
{return 2;}

}










