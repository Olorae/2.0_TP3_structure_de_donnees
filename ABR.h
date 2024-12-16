#pragma once
#include <fstream>

using namespace std;

struct noeud
{
    int valeur;
    noeud* gauche;
    noeud* droit;
};

class ABR
{
    // Variables
    noeud* Racine;
    
public:
    // Fonctions

    // Constructeur / Destructeur
    ABR(noeud* racine);
    ABR();
    ~ABR();

    void supprimeTout(noeud* racine);

    void Inserer(noeud* racine, int d);
    
    noeud* trouverMin(noeud* racine);

    void Supprimer(noeud* &racine, int d);

    void Afficher_Arbre(noeud* racine);

    int Afficher_hauteur(noeud* racine);

    int Desequilibre(noeud* racine);

    void Afficher_Ascendant(noeud* racine, int d);

    void ArchiverRec(noeud* noeud, ofstream& ofstream);
    void Archiver(noeud* racine);

    void setRacine(noeud* racine);
    noeud* getRacine();
};
