#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>
#include <gtk/gtkclist.h>
#include <gdk/gdkkeysyms.h>
#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include <string.h>
date d;
str c;
str1 c1;
str2 c2;
void on_recherchervol_clicked (GtkWidget *objet, gpointer user_data)
{
GtkWidget *cbox,*cbox1,*cboxar,*cbox1ar,*jr,*mo,*an,*he,*en,*ad,*fclass,*ecoclass,*busclass,*textsucss1 ;
date dat;
destination desti;
char h[20];
int e,adu;
int cx=0;
textsucss1=lookup_widget(objet,"sucss");
fclass=lookup_widget(objet,"firstclass");
ecoclass=lookup_widget(objet,"economique");
busclass=lookup_widget(objet,"businessclass");

cbox1=lookup_widget(objet,"payscombo");
cbox=lookup_widget(objet,"villecombo");
cboxar=lookup_widget(objet,"payscomboa");
cbox1ar=lookup_widget(objet,"villecomboa");

jr=lookup_widget(objet,"spinjour");
mo=lookup_widget(objet,"spinmois");
an=lookup_widget(objet,"spinannee");
he=lookup_widget(objet,"comboheure");
en=lookup_widget(objet,"spinenfants");
ad=lookup_widget(objet,"spinadulte");


strcpy(desti.pays,gtk_combo_box_get_active_text(GTK_COMBO_BOX(cbox1)));
strcpy(desti.ville,gtk_combo_box_get_active_text(GTK_COMBO_BOX(cbox)));
strcpy(desti.paysar,gtk_combo_box_get_active_text(GTK_COMBO_BOX(cboxar)));
strcpy(desti.villear,gtk_combo_box_get_active_text(GTK_COMBO_BOX(cbox1ar)));

dat.j=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jr));
dat.m=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mo));
dat.a=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(an));

strcpy(h,gtk_combo_box_get_active_text(GTK_COMBO_BOX(he)));
e=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(en));
adu=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(ad));
if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(fclass))){
cx=3;}
else if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(busclass))){
cx=2;}
else if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(ecoclass))){
cx=1;}





ajoutvol(desti,dat,h,e,adu,cx);
gtk_label_set_text(GTK_LABEL(textsucss1),"réservé avec succès");

}
void
on_payscombo_changed                   (GtkWidget *objet,
                                        gpointer         user_data)
{
GtkWidget *cbox1,*cbox;
destination desti;
cbox1=lookup_widget(objet,"payscombo");
cbox=lookup_widget(objet,"villecombo");
strcpy(desti.pays,gtk_combo_box_get_active_text(GTK_COMBO_BOX(cbox1)));

gtk_combo_box_remove_text(GTK_COMBO_BOX(cbox),0);
gtk_combo_box_remove_text(GTK_COMBO_BOX(cbox),1);
gtk_combo_box_remove_text(GTK_COMBO_BOX(cbox),2);
gtk_combo_box_remove_text(GTK_COMBO_BOX(cbox),3);
gtk_combo_box_remove_text(GTK_COMBO_BOX(cbox),4);
if (strcmp(desti.pays,"Tunisie")==0)
{

gtk_combo_box_remove_text(GTK_COMBO_BOX(cbox),0);
gtk_combo_box_remove_text(GTK_COMBO_BOX(cbox),1);
gtk_combo_box_remove_text(GTK_COMBO_BOX(cbox),2);
gtk_combo_box_remove_text(GTK_COMBO_BOX(cbox),3);
gtk_combo_box_remove_text(GTK_COMBO_BOX(cbox),4);

gtk_combo_box_prepend_text(GTK_COMBO_BOX(cbox),"Monastir");
gtk_combo_box_prepend_text(GTK_COMBO_BOX(cbox),"Hamamet");
gtk_combo_box_prepend_text(GTK_COMBO_BOX(cbox),"Cartage");
}
else if (strcmp(desti.pays,"France")==0)
{
//gtk_combo_box_set_button_sensitivity(GTK_COMBO_BOX(cbox1),GTK_SENSITIVITY_OFF);

gtk_combo_box_remove_text(GTK_COMBO_BOX(cbox),0);
gtk_combo_box_remove_text(GTK_COMBO_BOX(cbox),1);
gtk_combo_box_remove_text(GTK_COMBO_BOX(cbox),2);
gtk_combo_box_remove_text(GTK_COMBO_BOX(cbox),3);
gtk_combo_box_remove_text(GTK_COMBO_BOX(cbox),4);

gtk_combo_box_prepend_text(GTK_COMBO_BOX(cbox),"Monaco");
gtk_combo_box_prepend_text(GTK_COMBO_BOX(cbox),"Paris");
gtk_combo_box_prepend_text(GTK_COMBO_BOX(cbox),"Iyon");
}
else if (strcmp(desti.pays,"Usa")==0)
{

gtk_combo_box_remove_text(GTK_COMBO_BOX(cbox),0);
gtk_combo_box_remove_text(GTK_COMBO_BOX(cbox),1);
gtk_combo_box_remove_text(GTK_COMBO_BOX(cbox),2);
gtk_combo_box_remove_text(GTK_COMBO_BOX(cbox),3);
gtk_combo_box_remove_text(GTK_COMBO_BOX(cbox),4);

gtk_combo_box_prepend_text(GTK_COMBO_BOX(cbox),"Losangeles");
gtk_combo_box_prepend_text(GTK_COMBO_BOX(cbox),"Newyork");
gtk_combo_box_prepend_text(GTK_COMBO_BOX(cbox),"Lasvegas");
}
else if (strcmp(desti.pays,"Italy")==0)
{

gtk_combo_box_remove_text(GTK_COMBO_BOX(cbox),0);
gtk_combo_box_remove_text(GTK_COMBO_BOX(cbox),1);
gtk_combo_box_remove_text(GTK_COMBO_BOX(cbox),2);
gtk_combo_box_remove_text(GTK_COMBO_BOX(cbox),3);
gtk_combo_box_remove_text(GTK_COMBO_BOX(cbox),4);

gtk_combo_box_prepend_text(GTK_COMBO_BOX(cbox),"Rome");
gtk_combo_box_prepend_text(GTK_COMBO_BOX(cbox),"Milano");
gtk_combo_box_prepend_text(GTK_COMBO_BOX(cbox),"Palermo");
}
}




void
on_ajoutvolagent_clicked               (GtkWidget *objet,
                                        gpointer         user_data)
{
GtkWidget *cbo,*cbo1,*cboar,*cbo1ar,*adfclass,*adecoclass,*adbusclass,*textsucss1 ;


destination desti;

textsucss1=lookup_widget(objet,"labelajoutsucc");

adecoclass=lookup_widget(objet,"entryecoad5");
adbusclass=lookup_widget(objet,"entrybuisad6");
adfclass=lookup_widget(objet,"entryfirstad7");


cbo1=lookup_widget(objet,"paysdajou");
cbo=lookup_widget(objet,"villedajou");
cboar=lookup_widget(objet,"paysaajou");
cbo1ar=lookup_widget(objet,"villeaajou");


strcpy(desti.pays,gtk_combo_box_get_active_text(GTK_COMBO_BOX(cbo1)));
strcpy(desti.ville,gtk_combo_box_get_active_text(GTK_COMBO_BOX(cbo)));
strcpy(desti.paysar,gtk_combo_box_get_active_text(GTK_COMBO_BOX(cboar)));
strcpy(desti.villear,gtk_combo_box_get_active_text(GTK_COMBO_BOX(cbo1ar)));

strcpy(c1.adeco,gtk_entry_get_text(GTK_ENTRY(adecoclass)));
strcpy(c1.adbuis,gtk_entry_get_text(GTK_ENTRY(adbusclass)));
strcpy(c1.adfc,gtk_entry_get_text(GTK_ENTRY(adfclass)));








agentajoutvol(desti,c1);
gtk_label_set_text(GTK_LABEL(textsucss1),"ajouté avec succès");
}


void
on_payscomboa_changed                  (GtkWidget *objet,
                                        gpointer         user_data)
{
{
GtkWidget *cbox1,*cbox;
destination desti;
cbox1=lookup_widget(objet,"payscomboa");
cbox=lookup_widget(objet,"villecomboa");
strcpy(desti.pays,gtk_combo_box_get_active_text(GTK_COMBO_BOX(cbox1)));

gtk_combo_box_remove_text(GTK_COMBO_BOX(cbox),0);
gtk_combo_box_remove_text(GTK_COMBO_BOX(cbox),1);
gtk_combo_box_remove_text(GTK_COMBO_BOX(cbox),2);
gtk_combo_box_remove_text(GTK_COMBO_BOX(cbox),3);
gtk_combo_box_remove_text(GTK_COMBO_BOX(cbox),4);
if (strcmp(desti.pays,"Tunisie")==0)
{

gtk_combo_box_remove_text(GTK_COMBO_BOX(cbox),0);
gtk_combo_box_remove_text(GTK_COMBO_BOX(cbox),1);
gtk_combo_box_remove_text(GTK_COMBO_BOX(cbox),2);
gtk_combo_box_remove_text(GTK_COMBO_BOX(cbox),3);
gtk_combo_box_remove_text(GTK_COMBO_BOX(cbox),4);

gtk_combo_box_prepend_text(GTK_COMBO_BOX(cbox),"Monastir");
gtk_combo_box_prepend_text(GTK_COMBO_BOX(cbox),"Hamamet");
gtk_combo_box_prepend_text(GTK_COMBO_BOX(cbox),"Cartage");
}
else if (strcmp(desti.pays,"France")==0)
{
//gtk_combo_box_set_button_sensitivity(GTK_COMBO_BOX(cbox1),GTK_SENSITIVITY_OFF);

gtk_combo_box_remove_text(GTK_COMBO_BOX(cbox),0);
gtk_combo_box_remove_text(GTK_COMBO_BOX(cbox),1);
gtk_combo_box_remove_text(GTK_COMBO_BOX(cbox),2);
gtk_combo_box_remove_text(GTK_COMBO_BOX(cbox),3);
gtk_combo_box_remove_text(GTK_COMBO_BOX(cbox),4);

gtk_combo_box_prepend_text(GTK_COMBO_BOX(cbox),"Monaco");
gtk_combo_box_prepend_text(GTK_COMBO_BOX(cbox),"Paris");
gtk_combo_box_prepend_text(GTK_COMBO_BOX(cbox),"Lyon");
}
else if (strcmp(desti.pays,"Usa")==0)
{

gtk_combo_box_remove_text(GTK_COMBO_BOX(cbox),0);
gtk_combo_box_remove_text(GTK_COMBO_BOX(cbox),1);
gtk_combo_box_remove_text(GTK_COMBO_BOX(cbox),2);
gtk_combo_box_remove_text(GTK_COMBO_BOX(cbox),3);
gtk_combo_box_remove_text(GTK_COMBO_BOX(cbox),4);

gtk_combo_box_prepend_text(GTK_COMBO_BOX(cbox),"losangeles");
gtk_combo_box_prepend_text(GTK_COMBO_BOX(cbox),"newyork");
gtk_combo_box_prepend_text(GTK_COMBO_BOX(cbox),"lasvegas");
}
else if (strcmp(desti.pays,"Italy")==0)
{

gtk_combo_box_remove_text(GTK_COMBO_BOX(cbox),0);
gtk_combo_box_remove_text(GTK_COMBO_BOX(cbox),1);
gtk_combo_box_remove_text(GTK_COMBO_BOX(cbox),2);
gtk_combo_box_remove_text(GTK_COMBO_BOX(cbox),3);
gtk_combo_box_remove_text(GTK_COMBO_BOX(cbox),4);

gtk_combo_box_prepend_text(GTK_COMBO_BOX(cbox),"Rome");
gtk_combo_box_prepend_text(GTK_COMBO_BOX(cbox),"Milano");
gtk_combo_box_prepend_text(GTK_COMBO_BOX(cbox),"Palermo");
}
}


}


void
on_paysdajou_changed                   (GtkWidget *objet,
                                        gpointer         user_data)
{
{
GtkWidget *cbox1,*cbox;
destination desti;
cbox1=lookup_widget(objet,"paysdajou");
cbox=lookup_widget(objet,"villedajou");
strcpy(desti.pays,gtk_combo_box_get_active_text(GTK_COMBO_BOX(cbox1)));

gtk_combo_box_remove_text(GTK_COMBO_BOX(cbox),0);
gtk_combo_box_remove_text(GTK_COMBO_BOX(cbox),1);
gtk_combo_box_remove_text(GTK_COMBO_BOX(cbox),2);
gtk_combo_box_remove_text(GTK_COMBO_BOX(cbox),3);
gtk_combo_box_remove_text(GTK_COMBO_BOX(cbox),4);
if (strcmp(desti.pays,"Tunisie")==0)
{

gtk_combo_box_remove_text(GTK_COMBO_BOX(cbox),0);
gtk_combo_box_remove_text(GTK_COMBO_BOX(cbox),1);
gtk_combo_box_remove_text(GTK_COMBO_BOX(cbox),2);
gtk_combo_box_remove_text(GTK_COMBO_BOX(cbox),3);
gtk_combo_box_remove_text(GTK_COMBO_BOX(cbox),4);

gtk_combo_box_prepend_text(GTK_COMBO_BOX(cbox),"Monastir");
gtk_combo_box_prepend_text(GTK_COMBO_BOX(cbox),"Hamamet");
gtk_combo_box_prepend_text(GTK_COMBO_BOX(cbox),"Cartage");
}
else if (strcmp(desti.pays,"France")==0)
{

gtk_combo_box_remove_text(GTK_COMBO_BOX(cbox),0);
gtk_combo_box_remove_text(GTK_COMBO_BOX(cbox),1);
gtk_combo_box_remove_text(GTK_COMBO_BOX(cbox),2);
gtk_combo_box_remove_text(GTK_COMBO_BOX(cbox),3);
gtk_combo_box_remove_text(GTK_COMBO_BOX(cbox),4);

gtk_combo_box_prepend_text(GTK_COMBO_BOX(cbox),"Monaco");
gtk_combo_box_prepend_text(GTK_COMBO_BOX(cbox),"Paris");
gtk_combo_box_prepend_text(GTK_COMBO_BOX(cbox),"Lyon");
}
else if (strcmp(desti.pays,"Usa")==0)
{

gtk_combo_box_remove_text(GTK_COMBO_BOX(cbox),0);
gtk_combo_box_remove_text(GTK_COMBO_BOX(cbox),1);
gtk_combo_box_remove_text(GTK_COMBO_BOX(cbox),2);
gtk_combo_box_remove_text(GTK_COMBO_BOX(cbox),3);
gtk_combo_box_remove_text(GTK_COMBO_BOX(cbox),4);

gtk_combo_box_prepend_text(GTK_COMBO_BOX(cbox),"Losangeles");
gtk_combo_box_prepend_text(GTK_COMBO_BOX(cbox),"Newyork");
gtk_combo_box_prepend_text(GTK_COMBO_BOX(cbox),"Lasvegas");
}
else if (strcmp(desti.pays,"Italy")==0)
{

gtk_combo_box_remove_text(GTK_COMBO_BOX(cbox),0);
gtk_combo_box_remove_text(GTK_COMBO_BOX(cbox),1);
gtk_combo_box_remove_text(GTK_COMBO_BOX(cbox),2);
gtk_combo_box_remove_text(GTK_COMBO_BOX(cbox),3);
gtk_combo_box_remove_text(GTK_COMBO_BOX(cbox),4);

gtk_combo_box_prepend_text(GTK_COMBO_BOX(cbox),"Rome");
gtk_combo_box_prepend_text(GTK_COMBO_BOX(cbox),"Milano");
gtk_combo_box_prepend_text(GTK_COMBO_BOX(cbox),"Palermo");
}


}

}


void
on_paysaajou_changed                   (GtkWidget *objet,
                                        gpointer         user_data)
{
{GtkWidget *cbox1,*cbox;
destination desti;
cbox1=lookup_widget(objet,"paysaajou");
cbox=lookup_widget(objet,"villeaajou");
strcpy(desti.pays,gtk_combo_box_get_active_text(GTK_COMBO_BOX(cbox1)));

gtk_combo_box_remove_text(GTK_COMBO_BOX(cbox),0);
gtk_combo_box_remove_text(GTK_COMBO_BOX(cbox),1);
gtk_combo_box_remove_text(GTK_COMBO_BOX(cbox),2);
gtk_combo_box_remove_text(GTK_COMBO_BOX(cbox),3);
gtk_combo_box_remove_text(GTK_COMBO_BOX(cbox),4);
if (strcmp(desti.pays,"Tunisie")==0)
{

gtk_combo_box_remove_text(GTK_COMBO_BOX(cbox),0);
gtk_combo_box_remove_text(GTK_COMBO_BOX(cbox),1);
gtk_combo_box_remove_text(GTK_COMBO_BOX(cbox),2);
gtk_combo_box_remove_text(GTK_COMBO_BOX(cbox),3);
gtk_combo_box_remove_text(GTK_COMBO_BOX(cbox),4);

gtk_combo_box_prepend_text(GTK_COMBO_BOX(cbox),"Monastir");
gtk_combo_box_prepend_text(GTK_COMBO_BOX(cbox),"Hamamet");
gtk_combo_box_prepend_text(GTK_COMBO_BOX(cbox),"Cartage");
}
else if (strcmp(desti.pays,"France")==0)
{

gtk_combo_box_remove_text(GTK_COMBO_BOX(cbox),0);
gtk_combo_box_remove_text(GTK_COMBO_BOX(cbox),1);
gtk_combo_box_remove_text(GTK_COMBO_BOX(cbox),2);
gtk_combo_box_remove_text(GTK_COMBO_BOX(cbox),3);
gtk_combo_box_remove_text(GTK_COMBO_BOX(cbox),4);

gtk_combo_box_prepend_text(GTK_COMBO_BOX(cbox),"Monaco");
gtk_combo_box_prepend_text(GTK_COMBO_BOX(cbox),"Paris");
gtk_combo_box_prepend_text(GTK_COMBO_BOX(cbox),"Lyon");
}
else if (strcmp(desti.pays,"Usa")==0)
{

gtk_combo_box_remove_text(GTK_COMBO_BOX(cbox),0);
gtk_combo_box_remove_text(GTK_COMBO_BOX(cbox),1);
gtk_combo_box_remove_text(GTK_COMBO_BOX(cbox),2);
gtk_combo_box_remove_text(GTK_COMBO_BOX(cbox),3);
gtk_combo_box_remove_text(GTK_COMBO_BOX(cbox),4);

gtk_combo_box_prepend_text(GTK_COMBO_BOX(cbox),"Losangeles");
gtk_combo_box_prepend_text(GTK_COMBO_BOX(cbox),"Newyork");
gtk_combo_box_prepend_text(GTK_COMBO_BOX(cbox),"Lasvegas");
}
else if (strcmp(desti.pays,"Italy")==0)
{

gtk_combo_box_remove_text(GTK_COMBO_BOX(cbox),0);
gtk_combo_box_remove_text(GTK_COMBO_BOX(cbox),1);
gtk_combo_box_remove_text(GTK_COMBO_BOX(cbox),2);
gtk_combo_box_remove_text(GTK_COMBO_BOX(cbox),3);
gtk_combo_box_remove_text(GTK_COMBO_BOX(cbox),4);

gtk_combo_box_prepend_text(GTK_COMBO_BOX(cbox),"Rome");
gtk_combo_box_prepend_text(GTK_COMBO_BOX(cbox),"Milano");
gtk_combo_box_prepend_text(GTK_COMBO_BOX(cbox),"Palermo");
}
}

}




void
on_treeview1_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
gchar *str_data0;
gchar *str_data1;
gchar *str_data2;
gchar *str_data3;
gchar *str_data4;
gchar *str_data5;
gchar *str_data6;
gchar *str_data7;


GtkListStore *list_store;
list_store=GTK_LIST_STORE(gtk_tree_view_get_model(GTK_TREE_VIEW(treeview)));
GtkTreeIter iter;
  if (gtk_tree_model_get_iter(GTK_TREE_MODEL(list_store), &iter , path))
{
gtk_tree_model_get(GTK_TREE_MODEL(list_store),&iter, 0, &str_data0, -1);
gtk_tree_model_get(GTK_TREE_MODEL(list_store),&iter, 1, &str_data1, -1);
gtk_tree_model_get(GTK_TREE_MODEL(list_store),&iter, 2, &str_data2, -1);
gtk_tree_model_get(GTK_TREE_MODEL(list_store),&iter, 3, &str_data3, -1);
gtk_tree_model_get(GTK_TREE_MODEL(list_store),&iter, 4, &str_data4, -1);
gtk_tree_model_get(GTK_TREE_MODEL(list_store),&iter, 5, &str_data5, -1);
gtk_tree_model_get(GTK_TREE_MODEL(list_store),&iter, 6, &str_data6, -1);
gtk_tree_model_get(GTK_TREE_MODEL(list_store),&iter, 7, &str_data7, -1);
}
strcpy(c.pays_depare,str_data0);
strcpy(c.ville_depare,str_data1);
strcpy(c.pays_arrive,str_data2);
strcpy(c.ville_arrive,str_data3);
strcpy(c.date,str_data4);
strcpy(c.heure,str_data5);
strcpy(c.categorie,str_data6);
strcpy(c.classe,str_data7);



}


void
on_buttonajoucli18_clicked             (GtkWidget *objet,
                                        gpointer         user_data)
{GtkWidget *windowvolclient;
GtkWidget *windowtreeclient;



windowvolclient=lookup_widget(objet,"windowvolclient");
windowtreeclient=lookup_widget(objet,"windowtreeclient");

windowvolclient=create_windowvolclient();
gtk_widget_destroy(windowtreeclient);
gtk_widget_show(windowvolclient);




}


void
on_buttonsuppcli16_clicked             (GtkWidget *objet,
                                        gpointer         user_data)
{
GtkWidget *windowtreeclient;
GtkWidget *treeview1;



dell_volclient(c.pays_arrive);


windowtreeclient=lookup_widget(objet,"windowtreeclient");
gtk_widget_destroy(windowtreeclient);
windowtreeclient=create_windowtreeclient();
gtk_widget_show(windowtreeclient);


treeview1=lookup_widget(windowtreeclient,"treeview1");
afficher_vol(treeview1,c);
}





void
on_treeview2_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{gchar *str_data0;
gchar *str_data1;
gchar *str_data2;
gchar *str_data3;
gchar *str_data4;
gchar *str_data5;
gchar *str_data6;

GtkListStore *list_store;
list_store=GTK_LIST_STORE(gtk_tree_view_get_model(GTK_TREE_VIEW(treeview)));
GtkTreeIter iter;
  if (gtk_tree_model_get_iter(GTK_TREE_MODEL(list_store), &iter , path))
{
gtk_tree_model_get(GTK_TREE_MODEL(list_store),&iter, 0, &str_data0, -1);
gtk_tree_model_get(GTK_TREE_MODEL(list_store),&iter, 1, &str_data1, -1);
gtk_tree_model_get(GTK_TREE_MODEL(list_store),&iter, 2, &str_data2, -1);
gtk_tree_model_get(GTK_TREE_MODEL(list_store),&iter, 3, &str_data3, -1);
gtk_tree_model_get(GTK_TREE_MODEL(list_store),&iter, 4, &str_data4, -1);
gtk_tree_model_get(GTK_TREE_MODEL(list_store),&iter, 5, &str_data5, -1);
gtk_tree_model_get(GTK_TREE_MODEL(list_store),&iter, 6, &str_data6, -1);
}
strcpy(c2.pays_depare,str_data0);
strcpy(c2.ville_depare,str_data1);
strcpy(c2.pays_arrive,str_data2);
strcpy(c2.ville_arrive,str_data3);
strcpy(c2.adfc,str_data4);
strcpy(c2.adbuis,str_data5);
strcpy(c2.adeco,str_data6);


}


void
on_buttonsuppag11_clicked              (GtkWidget *objet,
                                        gpointer         user_data)
{

GtkWidget *windowtreeag;
GtkWidget *treeview2;



dell_volagent(c2.pays_depare);


windowtreeag=lookup_widget(objet,"windowtreeag");
gtk_widget_destroy(windowtreeag);
windowtreeag=create_windowtreeag();
gtk_widget_show(windowtreeag);


treeview2=lookup_widget(windowtreeag,"treeview2");
afficher_vol1(treeview2,c2);

}


void
on_buttonajouag9_clicked               (GtkWidget *objet,
                                        gpointer         user_data)
{
GtkWidget *windowvolagent;
GtkWidget *windowtreeag;



windowvolagent=lookup_widget(objet,"windowvolagent");
windowtreeag=lookup_widget(objet,"windowtreeag");

windowvolagent=create_windowvolagent();
gtk_widget_destroy(windowtreeag);
gtk_widget_show(windowvolagent);
}


void
on_back1__clicked                      (GtkWidget *objet,
                                        gpointer         user_data)
{GtkWidget *windowvolclient;
GtkWidget *windowtreeclient;
GtkWidget *treeview1;



windowvolclient=lookup_widget(objet,"windowvolclient");
windowtreeclient=lookup_widget(objet,"windowtreeclient");

windowtreeclient=create_windowtreeclient();
gtk_widget_destroy(windowvolclient);
gtk_widget_show(windowtreeclient);




treeview1=lookup_widget(windowtreeclient,"treeview1");
afficher_vol(treeview1,c);

}


void
on_back2_clicked                       (GtkWidget *objet,
                                        gpointer         user_data)
{GtkWidget *windowvolagent;
GtkWidget *windowtreeag;
GtkWidget *treeview2;


windowvolagent=lookup_widget(objet,"windowvolagent");
windowtreeag=lookup_widget(objet,"windowtreeag");
 

gtk_widget_destroy(windowvolagent);
windowtreeag=create_windowtreeag();
gtk_widget_show(windowtreeag);



treeview2=lookup_widget(windowtreeag,"treeview2");
afficher_vol1(treeview2,c2);

}


void
on_modifieragent_clicked               (GtkWidget *objet,
                                        gpointer         user_data)
{


GtkWidget *windowvolagent;
GtkWidget *windowtreeag;

GtkWidget *cbo,*cbo1,*cboar,*cbo1ar,*adfclass,*adecoclass,*adbusclass,*textsucss1 ;

dell_volagent(c2.pays_depare);

windowvolagent=lookup_widget(objet,"windowvolagent");
windowtreeag=lookup_widget(objet,"windowtreeag");

windowvolagent=create_windowvolagent();
gtk_widget_destroy(windowtreeag);
gtk_widget_show(windowvolagent);




textsucss1=lookup_widget(windowvolagent,"labelajoutsucc");

adecoclass=lookup_widget(windowvolagent,"entryecoad5");
adbusclass=lookup_widget(windowvolagent,"entrybuisad6");
adfclass=lookup_widget(windowvolagent,"entryfirstad7");

cbo1=lookup_widget(windowvolagent,"paysdajou");
cbo=lookup_widget(windowvolagent,"villedajou");
cboar=lookup_widget(windowvolagent,"paysaajou");
cbo1ar=lookup_widget(windowvolagent,"villeaajou");

gtk_combo_box_set_active(GTK_COMBO_BOX(cbo1),intpays(c2.pays_depare));
gtk_combo_box_set_active(GTK_COMBO_BOX(cboar),intpays(c2.pays_arrive));
gtk_combo_box_set_active(GTK_COMBO_BOX(cbo),intville(c2.pays_depare,c2.ville_depare));
gtk_combo_box_set_active(GTK_COMBO_BOX(cbo1ar),intville(c2.pays_arrive,c2.ville_arrive));

gtk_entry_set_text(GTK_ENTRY(adfclass),c2.adfc);
gtk_entry_set_text(GTK_ENTRY(adbusclass),c2.adbuis);
gtk_entry_set_text(GTK_ENTRY(adecoclass),c2.adeco);






}





void
on_modifierclient_clicked              (GtkWidget *objet,
                                        gpointer         user_data)
{GtkWidget *cbox,*cbox1,*cboxar,*cbox1ar,*textsucss1 ;
GtkWidget *windowvolclient;
GtkWidget *windowtreeclient;

dell_volclient(c.pays_arrive);

windowvolclient=lookup_widget(objet,"windowvolclient");
windowtreeclient=lookup_widget(objet,"windowtreeclient");

windowvolclient=create_windowvolclient();
gtk_widget_destroy(windowtreeclient);
gtk_widget_show(windowvolclient);





textsucss1=lookup_widget(objet,"sucss");


cbox1=lookup_widget(objet,"payscombo");
cbox=lookup_widget(objet,"villecombo");
cboxar=lookup_widget(objet,"payscomboa");
cbox1ar=lookup_widget(objet,"villecomboa");

gtk_combo_box_set_active(GTK_COMBO_BOX(cbox1),intpays(c.pays_depare));
gtk_combo_box_set_active(GTK_COMBO_BOX(cboxar),intpays(c.pays_arrive));
gtk_combo_box_set_active(GTK_COMBO_BOX(cbox),intville(c.pays_depare,c.ville_depare));
gtk_combo_box_set_active(GTK_COMBO_BOX(cbox1ar),intville(c.pays_arrive,c.ville_arrive));


}

