#include <iostream>
#include <regex>
#include <fstream>
#include <string>

#include"ABR.h"

using namespace std;
/*
   1
  / \
 2   3
/ \ / \
4 5 6 7

   4
  / \
 2   6
/ \ / \
1 3 5 7
*/
int main()
{
    noeud* racine = new noeud();
    noeud* noeud2 = new noeud();
    noeud* noeud3 = new noeud();
    noeud* noeud4 = new noeud();
    noeud* noeud5 = new noeud();
    noeud* noeud6 = new noeud();
    noeud* noeud7 = new noeud();
    noeud* noeudASupprimer = new noeud();

    racine->valeur = 4;
    noeud2->valeur = 2;
    noeud3->valeur = 6;
    noeud4->valeur = 1;
    noeud5->valeur = 3;
    noeud6->valeur = 5;
    noeud7->valeur = 7;

    racine->gauche = noeud2;
    racine->droit = noeud3;
    noeud2->gauche = noeud4;
    noeud2->droit = noeud5;
    noeud3->gauche = noeud6;
    noeud3->droit = noeud7;

    ABR* arbre = new ABR(racine);

    arbre->Afficher_Arbre(racine);
    cout << "Hauteur = " << arbre->Afficher_hauteur(racine) << endl;
    arbre->Archiver(racine);
    arbre->Inserer(racine, 8);
    arbre->Afficher_Arbre(racine);
    arbre->Supprimer(racine, 8);
    arbre->Afficher_Arbre(racine);
    arbre->supprimeTout(racine);
    arbre->Afficher_Arbre(racine);


    return 0;
}
