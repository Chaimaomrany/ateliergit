#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>
#include <string.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "client.h"
int x;
int y;

void
on_ajouter_clicked                     (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
client c;
GtkWidget *input1,*input2,*input3,*input4,*input5,*input6,*input8,*produit;	
GtkWidget *ajout_cl;
GtkWidget *output3;
int b;
output3=lookup_widget(objet_graphique,"label120");
ajout_cl=lookup_widget(objet_graphique,"ajout_cl");	
input1=lookup_widget(objet_graphique,"entry1");
input2=lookup_widget(objet_graphique,"entry2");
input3=lookup_widget(objet_graphique,"entry3");
input4=lookup_widget(objet_graphique,"entry4");
input5=lookup_widget(objet_graphique,"entry5");
input6=lookup_widget(objet_graphique,"entry6");
input8=lookup_widget(objet_graphique,"entry8");
produit=lookup_widget(objet_graphique,"entry9");



strcpy(c.nom,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(c.prenom,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(c.dnaissance,gtk_entry_get_text(GTK_ENTRY(input3)));
strcpy(c.email,gtk_entry_get_text(GTK_ENTRY(input4)));
strcpy(c.cin,gtk_entry_get_text(GTK_ENTRY(input5)));
strcpy(c.n_tel,gtk_entry_get_text(GTK_ENTRY(input6)));
strcpy(c.produit,gtk_combo_box_get_active_text(GTK_COMBO_BOX(produit)));
printf(gtk_combo_box_get_active_text(GTK_COMBO_BOX(produit)));
strcpy(c.id,gtk_entry_get_text(GTK_ENTRY(input8)));

if(x==0)
{strcpy(c.sexe,"Homme");}
else
if(x==1)
{strcpy(c.sexe,"Femme");}
ajouter_client(c);
b=1;
gtk_label_set_text(GTK_LABEL(output3),"Ajout Réussie !");
}


void
on_afficher_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *ajout_cl;
GtkWidget *affiche_cl;
GtkWidget *treeview1;


ajout_cl=lookup_widget(objet,"ajout_cl");
gtk_widget_destroy(ajout_cl);
affiche_cl=lookup_widget(objet,"affiche_cl");
affiche_cl=create_affiche_cl();
gtk_widget_show(affiche_cl);
treeview1=lookup_widget(affiche_cl,"treeview1");
afficher_client(treeview1);

}


void
on_treeview1_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)

{		
		GtkTreeIter iter;
		gchar* id;
		gchar* nom;
		gchar* prenom;
		gchar* dnaissance;
		gchar* email;
		gchar* cin;
		gchar* n_tel;
		gchar* sexe;
		gchar* produit;
		client c;
		
		
GtkTreeModel *model = gtk_tree_view_get_model(treeview);
if (gtk_tree_model_get_iter(model,&iter,path)) {
gtk_tree_model_get (GTK_LIST_STORE(model),&iter,0,&id,1,&nom,2,&prenom,3,&dnaissance,4,&email,5,&cin,6,&n_tel,7,&sexe,8,&produit,-1);
strcpy(c.id,id);
strcpy(c.nom,nom);
strcpy(c.prenom,prenom);
strcpy(c.dnaissance,dnaissance);
strcpy(c.email,email);
strcpy(c.cin,cin);
strcpy(c.n_tel,n_tel);
strcpy(c.sexe,sexe);
strcpy(c.produit,produit);

afficher_client(treeview);

}}

void
on_retourcl_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)

{
GtkWidget *ajout_cl,*affiche_cl;
affiche_cl=lookup_widget(objet,"affiche_cl");
gtk_widget_destroy(affiche_cl);
ajout_cl=create_ajout_cl();
gtk_widget_show(ajout_cl);
}



void
on_supprimer_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)

{GtkWidget *ajout_cl,*supprim_cl;
GtkWidget *combo;
	FILE *f;
	char id[30];
ajout_cl=lookup_widget(objet,"ajout_cl");
gtk_widget_destroy(ajout_cl );
supprim_cl=create_supprim_cl();
combo=lookup_widget(supprim_cl,"cb_supprimer_cl");
	f=fopen("client.txt","r");
	while(fscanf(f,"%s %*s %*s %*s %*s %*s %*s %*s %*s\n",id)!=EOF)
	{
		gtk_combo_box_append_text(GTK_COMBO_BOX(combo),id);
	}
	fclose(f);
gtk_widget_show(supprim_cl);
}



void
on_retour_supp_cl_clicked             (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *supprim_cl,*ajout_cl; 
supprim_cl=lookup_widget(objet,"supprim_cl");
gtk_widget_destroy(supprim_cl);
ajout_cl=create_ajout_cl();
gtk_widget_show(ajout_cl);
}


void
on_modifier_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)

{GtkWidget *ajout_cl,*modif_cl;
GtkWidget *combo;
	FILE *f;
	char id[30];

ajout_cl=lookup_widget(objet,"ajout_cl");
gtk_widget_destroy(ajout_cl);
modif_cl=create_modif_cl();
combo=lookup_widget(modif_cl,"cb_modif_cl");
	f=fopen("client.txt","r");
	while(fscanf(f,"%s %*s %*s %*s %*s %*s %*s %*s %*s\n",id)!=EOF)
	{
		gtk_combo_box_append_text(GTK_COMBO_BOX(combo),id);
	}
	fclose(f);
gtk_widget_show(modif_cl);
}

void
on_confirmer_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)

{	client c;
GtkWidget *input;
GtkWidget *output;
output=lookup_widget(objet,"label122");
int b;
input= lookup_widget(objet,"cb_supprimer_cl");
strcpy(c.id,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input)));
Supprimer_client(c);
b=1;
gtk_label_set_text(GTK_LABEL(output),"Suppression Réussie !");
}


void
on_retour_modif_clicked                (GtkWidget       *objet,
                                        gpointer         user_data)

{
GtkWidget *modif_cl,*ajout_cl;
modif_cl=lookup_widget(objet,"modif_cl");
gtk_widget_destroy(modif_cl);
ajout_cl=create_ajout_cl();
gtk_widget_show(ajout_cl);
}


void
on_modif_clicked                       (GtkWidget       *objet,
                                        gpointer         user_data)
{
client c;
GtkWidget *modif_cl; 	
GtkWidget *id,*nom,*prenom,*dnaissance,*email,*cin,*n_tel,*sexe,*produit;
GtkWidget *output2;
output2=lookup_widget(objet,"label121");
int b;
modif_cl=lookup_widget(objet,"modif_cl");
id= lookup_widget(objet,"cb_modif_cl");
nom= lookup_widget(objet,"mentry1");
prenom= lookup_widget(objet,"mentry2");
dnaissance=lookup_widget(objet,"mentry3");
email=lookup_widget(objet,"mentry4");
cin=lookup_widget(objet,"mentry5");
n_tel=lookup_widget(objet,"mentry6");
sexe=lookup_widget(objet,"mentry7");
produit=lookup_widget(objet,"mentry9");

strcpy(c.id,gtk_combo_box_get_active_text(GTK_COMBO_BOX(id)));
strcpy(c.nom,gtk_entry_get_text(GTK_ENTRY(nom)));
strcpy(c.prenom,gtk_entry_get_text(GTK_ENTRY(prenom)));
strcpy(c.dnaissance,gtk_entry_get_text(GTK_ENTRY(dnaissance)));
strcpy(c.email,gtk_entry_get_text(GTK_ENTRY(email)));
strcpy(c.cin,gtk_entry_get_text(GTK_ENTRY(cin)));
strcpy(c.n_tel,gtk_entry_get_text(GTK_ENTRY(n_tel)));
strcpy(c.sexe,gtk_entry_get_text(GTK_ENTRY(sexe)));
strcpy(c.produit,gtk_combo_box_get_active_text(GTK_COMBO_BOX(produit)));
Modifier_client(c);
b=1;
gtk_label_set_text(GTK_LABEL(output2),"Modification Réussie !");
}

  
void
on_radiobutton1_homme_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
{
x=0;
}
}
void
on_radiobutton2_femme_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data)

{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
{
x=1;
}
}




