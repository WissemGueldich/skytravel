#include <gtk/gtk.h>
#include "vol.h"

void on_recherchervol_clicked (GtkWidget *objet, gpointer user_data);

void
on_payscombo_changed                   (GtkWidget *objet,
                                        gpointer         user_data);

void
on_ajoutvolagent_clicked               (GtkWidget *objet,
                                        gpointer         user_data);

void
on_payscomboa_changed                  (GtkWidget *objet,
                                        gpointer         user_data);

void
on_paysdajou_changed                   (GtkWidget *objet,
                                        gpointer         user_data);

void
on_paysaajou_changed                   (GtkWidget *objet,
                                        gpointer         user_data);

void
on_buttonaffcli17_clicked              (GtkWidget *objet,
                                        gpointer         user_data);

void
on_treeview1_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_buttonajoucli18_clicked             (GtkWidget *objet,
                                        gpointer         user_data);

void
on_buttonsuppcli16_clicked             (GtkWidget *objet,
                                        gpointer         user_data);

void
on_buttonaffag10_clicked               (GtkWidget *objet,
                                        gpointer         user_data);

void
on_treeview2_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_buttonsuppag11_clicked              (GtkWidget *objet,
                                        gpointer         user_data);

void
on_buttonajouag9_clicked               (GtkWidget *objet,
                                        gpointer         user_data);

void
on_back1__clicked                      (GtkWidget *objet,
                                        gpointer         user_data);

void
on_back2_clicked                       (GtkWidget *objet,
                                        gpointer         user_data);

void
on_modifieragent_clicked               (GtkWidget *objet,
                                        gpointer         user_data);

void
on_modifierclient_activate             (GtkWidget *objet,
                                        gpointer         user_data);

void
on_modifierclient_clicked              (GtkWidget *objet,
                                        gpointer         user_data);
