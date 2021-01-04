#include <gtk/gtk.h>


void
on_ajouter_clicked                     (GtkWidget      *objet_graphique,
                                        gpointer         user_data);

void
on_afficher_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_treeview1_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_retourcl_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_supprimer_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_retour_supp_cl_clicked             (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_modifier_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_confirmer_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_retour_modif_clicked                (GtkWidget      *objet,
                                        gpointer         user_data);

void
on_modif_clicked                       (GtkWidget       *objet,
                                        gpointer         user_data);



void
on_radiobutton1_homme_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton2_femme_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data);



