
#ifdef HAVE_CONGIG_H
# include <config.h>
#endif
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "client.h"
#include <gtk/gtk.h>
enum
{
   
  ID,
  NOM,
  PRENOM,
  DNAISSANCE,
  EMAIL,
  CIN,
  NTEL,
  SEXE,
  PRODUIT,
  COLUMNS,
};

void ajouter_client(client c)
{
FILE* f;
f=fopen("client.txt","a+");
  if(f!=NULL)
   {
   fprintf(f,"%s %s %s %s %s %s %s  %s %s  \n",c.id,c.nom,c.prenom,c.dnaissance,c.email,c.cin,c.n_tel,c.sexe,c.produit);
   }
fclose(f);
}

void Modifier_client(client cl)
{
client c;
FILE *f;
FILE *g;

f=fopen("client.txt","a+");
g=fopen("client2.txt","a+");
if(f!=NULL)
{
while (fscanf(f,"%s %s %s %s %s %s %s %s %s ",c.id,c.nom,c.prenom,c.dnaissance,c.email,c.cin,c.n_tel,c.sexe,c.produit)!=EOF)
{ if (strcmp(c.id,cl.id)==0)
	fprintf(g,"%s %s %s %s %s %s %s %s %s \n",cl.id,cl.nom,cl.prenom,cl.dnaissance,cl.email,cl.cin,cl.n_tel,cl.sexe,cl.produit);
else
	fprintf(g,"%s %s %s %s %s %s %s %s %s \n",c.id,c.nom,c.prenom,c.dnaissance,c.email,c.cin,c.n_tel,c.sexe,c.produit);
}
fclose(f);
fclose(g);
remove("client.txt");
rename("client2.txt","client.txt");

}}

void Supprimer_client (client c)
{
client cl;	
FILE *f;
FILE *g;

f=fopen("client.txt","a+");
g=fopen("client2.txt","a+");
if (f!=NULL )
    {
	while (fscanf(f,"%s %s %s %s %s %s %s %s %s \n",cl.id,cl.nom,cl.prenom,cl.dnaissance,cl.email,cl.cin,cl.n_tel,cl.sexe,cl.produit)!=EOF)
	{	if (strcmp(c.id,cl.id)!=0)	
			{fprintf(g,"%s %s %s %s %s %s %s %s %s \n",cl.id,cl.nom,cl.prenom,cl.dnaissance,cl.email,cl.cin,cl.n_tel,cl.sexe,cl.produit);
			}
	}

	fclose(f);
	fclose(g);
	remove("client.txt");
	rename("client2.txt","client.txt");

   }
}

void afficher_client(GtkWidget *liste)
{
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;

{

char id[30];
char nom[30];
char prenom[30];
char dnaissance[30];
char email[30];
char cin[30];
char n_tel[30];
char sexe[30];
char produit[30];
store=NULL;

FILE  *f;

store=gtk_tree_view_get_model(liste);

  if(store==NULL)
  {
   
   renderer=gtk_cell_renderer_text_new();
   column=gtk_tree_view_column_new_with_attributes("id                         ",renderer,"text",ID,NULL);
   gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);	

   renderer=gtk_cell_renderer_text_new();
   column=gtk_tree_view_column_new_with_attributes("nom                         ",renderer,"text",NOM,NULL);
   gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

   renderer=gtk_cell_renderer_text_new();
   column=gtk_tree_view_column_new_with_attributes("prenom                      ",renderer,"text",PRENOM,NULL);
   gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


   renderer=gtk_cell_renderer_text_new();
   column=gtk_tree_view_column_new_with_attributes("dnaissance                 ",renderer,"text",DNAISSANCE,NULL);
   gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column); 


   renderer=gtk_cell_renderer_text_new();
   column=gtk_tree_view_column_new_with_attributes("email                      ",renderer,"text",EMAIL,NULL);
   gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	
 

   renderer=gtk_cell_renderer_text_new();
   column=gtk_tree_view_column_new_with_attributes("cin                       ",renderer,"text",CIN,NULL);
   gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
   
   renderer=gtk_cell_renderer_text_new();
   column=gtk_tree_view_column_new_with_attributes("n_tel                     ",renderer,"text",NTEL,NULL);
   gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
   
    renderer=gtk_cell_renderer_text_new();
   column=gtk_tree_view_column_new_with_attributes("sexe                      ",renderer,"text",SEXE,NULL);
   gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

   renderer=gtk_cell_renderer_text_new();
   column=gtk_tree_view_column_new_with_attributes("produit                   ",renderer,"text",PRODUIT,NULL);
   gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

   store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);

   f=fopen("client.txt","r");

     if(f==NULL)
{ return;}
else
        {
         f=fopen("client.txt","a+");
         while(fscanf(f,"%s %s %s %s %s %s %s %s %s",id,nom,prenom,dnaissance,email,cin,n_tel,sexe,produit)!=EOF)
          {
           gtk_list_store_append(store,&iter);
           gtk_list_store_set(store,&iter,ID,id,NOM,nom,PRENOM,prenom,DNAISSANCE,dnaissance,EMAIL,email,CIN,cin,NTEL,n_tel,SEXE,sexe,PRODUIT,produit,-1);
          }
        }
   fclose(f);

   gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
   g_object_unref(store);  

   }
}}


