#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <gtk/gtk.h>
typedef struct {
char adeco[20];
char adbuis[20];
char adfc[20];
char enfeco[20];
char enfbuis[20];
char enffc[20];
 }classee;
typedef struct {
int j;
int m;
int a;
 }date;
typedef struct {
char pays[20];
char ville[20];
char paysar[20];
char villear[20];
}destination;

typedef struct {
char	pays_depare[20];
char	ville_depare[20];
char	pays_arrive[20];
char	ville_arrive[20];
char	date[20];
char	heure[20];
char	categorie[20];
char	classe[20];
}str;
typedef struct {
char	pays_depare[20];
char	ville_depare[20];
char	pays_arrive[20];
char	ville_arrive[20];
char	adfc[20];
char	adbuis[20];
char	adeco[20];

}str1;
typedef struct {
char	pays_depare[20];
char	ville_depare[20];
char	pays_arrive[20];
char	ville_arrive[20];
char	adfc[20];
char	adbuis[20];
char	adeco[20];

}str2;
void ajoutvol(destination dist,date d,char heure[],int enf, int adul,int classe);


void agentajoutvol(destination dist,str1 c1);
 

void afficher_vol(GtkWidget *liste ,str c);
void dell_volclient(char *date);

void afficher_vol1(GtkWidget *liste ,str2 c2);
void dell_volagent(char *pays_depare);








int intpays(char *pays);
int intville(char *pays,char *ville);

