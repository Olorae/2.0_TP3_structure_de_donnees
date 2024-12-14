#include "ABR.h"
#include <iostream>
#include <stack>
#include <queue>
#include <cmath>
using namespace std;

ABR::ABR::ABR(noeud* racine) : Racine(racine) {}

ABR::ABR::~ABR()
{
    supprimeTout(Racine);
}

void ABR::supprimeTout(noeud* racine)
{
    if (racine)
    {
        supprimeTout(racine->droit);
        supprimeTout(racine->gauche);
        delete racine;
    }
}

void ABR::Inserer(noeud* racine, int d)
{
    noeud* noeudTemp = nullptr;
    noeudTemp->valeur = d;
    
    if (racine)
    {
        if (d < racine->valeur)
        {
            if (racine->gauche)
            {
                Inserer(racine->gauche, d);
            }
            racine->gauche = noeudTemp;
        }
        else if (d == racine->valeur)
        {
            cout << d << " existe deja \n";
        }
        else 
        {
            if (d < racine->valeur)
            {
                if (racine->droit)
                {
                    Inserer(racine->droit, d);
                }
                racine->droit = noeudTemp;
            }
        }
    }
}

void ABR::Supprimer(noeud* racine, int d)
{
    noeud* noeudTemp = nullptr;
    noeudTemp->valeur = d;
    
    if (racine)
    {
        if (d < racine->valeur)
        {
            if (racine->gauche)
            {
                Supprimer(racine->gauche, d);
            }
        }
        else if (d == racine->valeur)
        {
           delete racine;
        }
        else 
        {
            if (d < racine->valeur)
            {
                if (racine->droit)
                {
                    Supprimer(racine->droit, d);
                }
            }
        }
    }
    
}
/*
 * Affiche les éléments de l’arbre niveau par niveau (un niveau étant affiché sur une seule ligne). Un bonus de 5pts est donné à ceux et celles qui commencent par le dernier niveau (dernier
 * niveau étant le niveau n’ayant pas de descendants, c’est-à-dire les nœuds feuilles), puis l’avant dernier niveau, et ainsi de suite jusqu’à arriver au premier niveau qui est la racine
 */
// prenant pour acquis que l'arbre est équilibré
static stack<noeud> noeuds;

void ABR::Afficher_Arbre(noeud* racine)
{/*
    if(racine){
        
        if (racine->gauche)
        {
            noeuds.push(*racine);
            Afficher_Arbre(racine->gauche);
        }
        if (racine->droit)
        {
            noeuds.push(*racine);
            Afficher_Arbre(racine->droit);
        }
        
        if (!racine->gauche && !racine->droit)
        {
            noeuds.push(*racine);
            //Supprimer(racine, racine->valeur);
        }
    }

    */

    if (!racine) return;

    queue<noeud*> file;
    stack<vector<int>> levels;
    file.push(racine);

    // Parcourir niveau par niveau
    while (!file.empty()) {
        const int lengthNiveau = file.size();
        vector<int> currentNiveau;

        for (int x = 0; x < lengthNiveau; x++) {
            const noeud* currentNode = file.front();
            file.pop();
            currentNiveau.push_back(currentNode->valeur);

            if (currentNode->gauche) file.push(currentNode->gauche);
            if (currentNode->droit) file.push(currentNode->droit);
        }
        levels.push(currentNiveau);
    }

    // Afficher les niveaux dans l'ordre inverse
    while (!levels.empty()) {
        vector<int> level = levels.top();
        levels.pop();
        for (int value : level) {
            cout << value << " ";
        }
        cout << '\n';
    }
}

int ABR::Afficher_hauteur(noeud* racine)
{
    if (racine)
        return 0;
  
    int left = Afficher_hauteur(racine->gauche);
    int right = Afficher_hauteur(racine->droit);
    
    return ((left > right ? left : right) + 1);
}

// Affiche le nombre de nœuds dont la valeur absolue de la différence de hauteurs de leurs sous-arbres gauche et droit est supérieure strictement à 1. (bonus 5pts)
int ABR::Desequilibre(noeud* racine)
{
    
}

void ABR::Afficher_Ascendant(noeud* racine, int d)
{
}
// Archiver en implémentation séquentielle l’arbre dont la racine est racine dans un fichier texte que vous allez définir
void ABR::Archiver(noeud* racine)
{
}


