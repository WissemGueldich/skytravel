#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"



void
on_g_de_res_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)

{
GtkWidget *wagents;
GtkWidget *greservations;

wagents=lookup_widget(objet,"agent");
greservations=lookup_widget(objet,"gestion_des_reservations");
gtk_widget_destroy(wagents);
greservations=create_gestion_des_reservations();
gtk_widget_show(greservations);

}


void
on_g_de_off_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)

{
GtkWidget *wagents;
GtkWidget *gcatalogues;

wagents=lookup_widget(objet,"agent");
gcatalogues=lookup_widget(objet,"gestion_des_offres");
gtk_widget_destroy(wagents);
gcatalogues=create_gestion_des_offres();
gtk_widget_show(gcatalogues);

}



void
on_g_de_rec_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{GtkWidget *wagents;
GtkWidget *greclamations;

wagents=lookup_widget(objet,"agent");
greclamations=lookup_widget(objet,"gestion_des_reclamations");
gtk_widget_destroy(wagents);
greclamations=create_gestion_des_reclamations();
gtk_widget_show(greclamations);

}


void
on_g_de_cl_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *wagents;
GtkWidget *gclients;

wagents=lookup_widget(objet,"agent");
gclients=lookup_widget(objet,"gestion_de_clients");
gtk_widget_destroy(wagents);
gclients=create_gestion_de_clients();
gtk_widget_show(gclients);


}











void
on_retournergdc_clicked                (GtkWidget       *objet,
                                        gpointer           user_data)
{
GtkWidget *wagents;
GtkWidget *gclients;

wagents=lookup_widget(objet,"agent");
gclients=lookup_widget(objet,"gestion_de_clients");
gtk_widget_destroy(gclients);
wagents=create_agent();
gtk_widget_show(wagents);

}


void
on_retournergdr_clicked                (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *wagents;
GtkWidget *greclamations;

wagents=lookup_widget(objet,"agent");
greclamations=lookup_widget(objet,"gestion_des_reclamations");
gtk_widget_destroy(greclamations);
wagents=create_agent();
gtk_widget_show(wagents);

}



void
on_retournergdof_clicked               (GtkWidget       *objet,
                                        gpointer          user_data)
{
GtkWidget *wagents;
GtkWidget *gcatalogues;

wagents=lookup_widget(objet,"agent");
gcatalogues=lookup_widget(objet,"gestion_des_offres");
gtk_widget_destroy(gcatalogues);
wagents=create_agent();
gtk_widget_show(wagents);
}


void
on_retournerres_clicked                (GtkWidget       *objet,
                                        gpointer          user_data)
{
GtkWidget *wagents;
GtkWidget *greservations;

wagents=lookup_widget(objet,"agent");
greservations=lookup_widget(objet,"gestion_des_reservations");
gtk_widget_destroy(greservations);
wagents=create_agent();
gtk_widget_show(wagents);

}

