#include <gtk/gtk.h>

typedef struct 
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
}client;

void afficher_client(GtkWidget *liste);
void ajouter_client(client );
void Supprimer_client (client);
void Modifier_client(client );
