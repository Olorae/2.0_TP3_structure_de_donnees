#include <iostream>
#include <regex>
#include <fstream>
#include <string>

#include"ABR.h"

using namespace std;

int main()
{
    /*
    Arbre Test
    ----------
       4
      / \
     2   6
    / \ / \
    1 3 5 7
    */
    // Variables
    noeud* racine = new noeud();
    noeud* racine1 = new noeud();
    noeud* noeud2 = new noeud();
    noeud* noeud3 = new noeud();
    noeud* noeud4 = new noeud();
    noeud* noeud5 = new noeud();
    noeud* noeud6 = new noeud();
    noeud* noeud7 = new noeud();
    string input;
    ABR* arbre1;
    ABR* arbre = new ABR();
    char operation;
    int valeurNoeud;

    // Ajouts des noeuds tests
    racine1->valeur = 4;
    noeud2->valeur = 2;
    noeud3->valeur = 6;
    noeud4->valeur = 1;
    noeud5->valeur = 3;
    noeud6->valeur = 5;
    noeud7->valeur = 7;


    racine1->gauche = noeud2;
    racine1->droit = noeud3;
    noeud2->gauche = noeud4;
    noeud2->droit = noeud5;
    noeud3->gauche = noeud6;
    noeud3->droit = noeud7;

    arbre1 = new ABR(racine1);

    while (input != "T")
    {
        cout << "Entrez l'une des commandes suivantes pour effectuer une operation :\n"
            << "\tI : Insertion - Inserer un element de valeur d dans l'arbre binaire de recherche\n"
            << "\tS : Suppression - Supprimer un element de valeur d de l'arbre binaire de recherche\n"
            << "\tA : Affichage - Afficher les elements de l'arbre niveau par niveau (de gauche a droite)\n"
            << "\tH : Hauteur - Afficher la hauteur de l'arbre (chemin le plus long de la racine a une feuille)\n"
            << "\tD : Noeuds desequilibres - Nombre de noeuds ou |hauteur gauche - hauteur droite| > 1\n"
            << "\tT : Archivage - Sauvegarder l'arbre dans un fichier texte en format sequentiel\n>";
        cin >> input;

        while (true)
        {
            regex commandRegex("^[ISAHDGT]$");
            transform(input.begin(), input.end(), input.begin(), ::toupper);
            if (regex_match(input, commandRegex))
            {
                cout << "Commande valide : " << input << endl;
                break;
            }
            else
            {
                cout << "Commande invalide !" << endl;
                cout << "Entrez une commande (I, S, A, H, D, T) : ";
                cin >> input;
            }
        }
        operation = input[0];
        if (!arbre->getRacine() && operation == 'I')
        {
            cout << "Entrez la racine de l'arbre: ";
            cin >> valeurNoeud;
            racine->valeur = valeurNoeud;
        }
        else if (arbre->getRacine())
        {
            switch (operation)
            {
            case 'I':
                cout << "Entrez le nouvel element de l'arbre: ";
                cin >> valeurNoeud;
                arbre->Inserer(racine, valeurNoeud);
                break;
            case 'S':
                cout << "Entrez l'element a supprimer de l'arbre: ";
                cin >> valeurNoeud;
                arbre->Inserer(racine, valeurNoeud);arbre->Supprimer(racine, valeurNoeud);
                break;
            case 'A': arbre->Afficher_Arbre(racine);
                break;
            case 'H': arbre->Afficher_hauteur(racine);
                break;
            case 'D': arbre->Desequilibre(racine);
                break;
            case 'T': arbre->Archiver(racine);
                break;
            default:
                cout << "Erreur : une commande invalide a ete accepte";
                break;
            }
        }
        else
        {
            cout << "l'arbre est vide, commencez par inserer une valeur" << endl;
            input = "I";
        }
    }

    return 0;
}
