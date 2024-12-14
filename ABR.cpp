#include "ABR.h"
#include <iostream>
#include <stack>
#include <queue>
#include <cmath>
#include <fstream>

using namespace std;

ABR::ABR::ABR(noeud* racine) : Racine(racine)
{
}

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
    noeud* noeudTemp = new noeud();
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
            if (d > racine->valeur)
            {
                if (racine->droit)
                {
                    Inserer(racine->droit, d);
                }
                if (!racine->droit)
                {
                    cout << d << " Ajoute \n";
                    racine->droit = noeudTemp;
                }
            }
        }
    }
}

void ABR::Supprimer(noeud* racine, int d)
{

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
            cout << d << " supprime \n";

            delete racine;
        }
        else
        {
            if (d > racine->valeur)
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
{
    /*
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
    while (!file.empty())
    {
        const int lengthNiveau = file.size();
        vector<int> currentNiveau;

        for (int x = 0; x < lengthNiveau; x++)
        {
            const noeud* currentNode = file.front();
            file.pop();
            currentNiveau.push_back(currentNode->valeur);

            if (currentNode->gauche) file.push(currentNode->gauche);
            if (currentNode->droit) file.push(currentNode->droit);
        }
        levels.push(currentNiveau);
    }

    // Afficher les niveaux dans l'ordre inverse
    while (!levels.empty())
    {
        vector<int> level = levels.top();
        levels.pop();
        for (int value : level)
        {
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
    if (racine)
    {
    }
    return 1;
}

void ABR::Afficher_Ascendant(noeud* racine, int d)
{
}

// Fonction récursive pour archiver l'arbre (préfixe)
void ABR::ArchiverRec(noeud* noeud, ofstream& outFile)
{
    if (outFile.is_open())
    {
        if (!noeud)
        {
            outFile << "# "; // Marqueur pour nœuds null
            return;
        }

        // Écris valeur et archive sous-arbre (gauche & droit)
        outFile << noeud->valeur << " ";
        ArchiverRec(noeud->gauche, outFile);
        ArchiverRec(noeud->droit, outFile);
    }
}

// Archiver en implémentation séquentielle l’arbre dont la racine est racine dans un fichier texte que vous allez définir
void ABR::Archiver(noeud* racine)
{
    ofstream outFile("archive.txt"); // Ouvre un fichier texte pour écrire
    if (!outFile)
    {
        cout << "Erreur : impossible de creer le fichier.\n";
        return;
    }
    ArchiverRec(racine, outFile);
    outFile.close();
    cout << "Arbre archive dans 'archive.txt'.\n";
}