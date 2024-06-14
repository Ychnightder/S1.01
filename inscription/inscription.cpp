#include <iostream>
#include <cctype>
#include "inscription.h"

const int nbRole = 3; // Nombre de rôles
const char* roleTab[nbRole] = {"AG", "OP", "IN"};

int tailleTab;
std::string* tabNom;
int compteur;

void initTabNom(int taille) {
    if (taille > 0) {
        tailleTab = taille;
        tabNom = new std::string[tailleTab];
    } else {
        tabNom = nullptr;
    }
}

void suppTabNom() {
    delete[] tabNom;
    tabNom = nullptr;
}

void ajouterDansTabNom(std::string& nom) {
    for (int i = 0; i < tailleTab; ++i) {
        if (tabNom[i].empty()) {
            tabNom[i] = nom;
            break; // Sortir après avoir ajouté le nom
        }
    }
}

void inscription() {
    string role;
    string nom;

    cin >> role;
    cin >> nom;
    bool verif = true;

    // Convertir le rôle en majuscules pour la vérification
    for (char& c : role) {
        c = std::toupper(c);
    }

    // Vérifier le rôle
    bool roleCorrect = false;
    for (int i = 0; i < nbRole; ++i) {
        if (role == roleTab[i]) {
            roleCorrect = true;
            break;
        }
    }

    if (!roleCorrect) {
        std::cout << "Rôle incorrect" << std::endl;
        verif = false;
    }

    // Vérifier le nom et l'ajouter si correct
    bool nomCorrect = true;
    for (int i = 0; i < tailleTab; ++i) {
        if (!tabNom[i].empty() && nom == tabNom[i]) {
            std::cout << "Nom incorrect" << std::endl;
            nomCorrect = false;
            verif = false;
            break;
        }
    }

    if (verif && nomCorrect) {
        ajouterDansTabNom(nom);
        ++compteur;
        std::cout << "Inscription réalisée (" << compteur << ")" << std::endl;
    }
}
