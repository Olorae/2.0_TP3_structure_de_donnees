#include "ABR.h"
#include <iostream>
#include <stack>
#include <queue>
#include <cmath>
#include <fstream>

using namespace std;

ABR::ABR(noeud* racine) : Racine(racine)
{
}

ABR::ABR() : Racine(nullptr)
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
            cout << "La valeur \"" << d << "\" existe deja \n";
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
                    cout << "La valur \"" << d << "\" a ete ajoute \n";
                    racine->droit = noeudTemp;
                }
            }
        }
    }
}

void ABR::Supprimer(noeud* &racine, int d)
{
    if (racine == nullptr)
        return;

    // Si la valeur à supprimer est plus petite, on va dans le sous-arbre gauche
    if (d < racine->valeur)
    {
        Supprimer(racine->gauche, d);
    }
    // Si la valeur à supprimer est plus grande, on va dans le sous-arbre droit
    else if (d > racine->valeur)
    {
        Supprimer(racine->droit, d);
    }
    else
    {
        // Si on trouve le nœud à supprimer
        cout << "La valeur \"" << d << "\" a ete supprime \n";

        // Si c'est une feuille
        if (racine->gauche == nullptr && racine->droit == nullptr)
        {
            delete racine;
            racine = nullptr; 
        }
        // si une seul fils n'est pas null
        else if (racine->gauche == nullptr || racine->droit == nullptr)
        {
            noeud* temp = racine;
            if (racine->gauche != nullptr)
                racine = racine->gauche; 
            else
                racine = racine->droit;  
            delete temp;  
        }
        else
        {
            // Trouver le successeur immédiat 
            noeud* temp = trouverMin(racine->droit);
            racine->valeur = temp->valeur;  
            Supprimer(racine->droit, temp->valeur);  
        }
    }
}

// Fonction pour trouver le minimum (le plus à gauche) d'un sous-arbre
noeud* ABR::trouverMin(noeud* racine)
{
    while (racine && racine->gauche != nullptr)
        racine = racine->gauche;
    return racine;
}
/*
 * Affiche les éléments de l’arbre niveau par niveau (un niveau étant affiché sur une seule ligne). Un bonus de 5pts est donné à ceux et celles qui commencent par le dernier niveau (dernier
 * niveau étant le niveau n’ayant pas de descendants, c’est-à-dire les nœuds feuilles), puis l’avant dernier niveau, et ainsi de suite jusqu’à arriver au premier niveau qui est la racine
 */

// prenant pour acquis que l'arbre est équilibré
static stack<noeud> noeuds;
void ABR::Afficher_Arbre(noeud* racine)
{
    if (racine->valeur == -572662307){ // Valeur qui est mis sur la racine lorsque elle est effacé
        cout<< "Erreur : Impossible d'afficher un arbre Vide" << endl;
        return;
    }

    queue<noeud*> file;
    stack<vector<int>> niveau;
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
        niveau.push(currentNiveau);
    }

    // Afficher les niveaux dans l'ordre inverse
    
    while (!niveau.empty())
    {
        vector<int> level = niveau.top();
        niveau.pop();
        for (int value : level)
        {
            cout << value << " ";
        }
        cout << '\n';
    }
}

int ABR::Afficher_hauteur(noeud* racine)
{
    if (!racine)
        return 0;

    int left = Afficher_hauteur(racine->gauche);
    int right = Afficher_hauteur(racine->droit);

    return ((left > right ? left : right) + 1);
}
// Pas besoins c'est un bonus 
int ABR::Desequilibre(noeud* racine)
{
    if (racine)
    {
    }
    return 1;
}

// Pas besoins c'est un bonus 
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

noeud* ABR::getRacine()
{
    return Racine;
}

void ABR::setRacine(noeud* racine)
{
    Racine = racine;
}