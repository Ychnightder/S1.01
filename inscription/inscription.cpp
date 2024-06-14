#include <iostream>
#include <cctype>
#include "inscription.h"

const int nbRole = 3; // Nombre de rôles
const char* roleTab[nbRole] = {"AG", "OP", "IN"};

    int tailleTab = 0;
    Entreprise* tabEntreprise = nullptr; // Initialisation de la variable globale
    int compteur = 0;

    void initTabEntreprise(int taille) {
        if (taille > 0) {
            tailleTab = taille;
            tabEntreprise = new Entreprise[taille];
        } else {
            tabEntreprise = nullptr;
        }
    }

    void suppTabEntreprise() {
        delete[] tabEntreprise;
        tabEntreprise = nullptr;
    }

    bool estDejaEntreprise(string& nom) {
        for (int i = 0; i < tailleTab; ++i) {
            if (nom == tabEntreprise[i].nomEntreprise) {
                return true;
            }
         }
        return false;
    }

    bool verifRole(string& role){
        for (int i = 0; i < nbRole; ++i) {
            if (role == roleTab[i]) {
                return  true;
                break;
            }
        }
        return false;
    }

    void inscription(){
        string role;
        string nom;

        cin >> role;
        cin >> nom;

        for (char& c : role) {
            c = toupper(c);
        }

        Entreprise entrepriseTmp = *new Entreprise;

        if (estDejaEntreprise(nom)){
           cout << "Nom incorrect";
            return;
        }

        if (!verifRole(role)) {
            std::cout << "Rôle incorrect" << std::endl;
            return;
        }

        for (int i = 0; i < tailleTab; ++i) {
            if (tabEntreprise[i].nomEntreprise.empty()) {
                tabEntreprise[i].idEntreprise = compteur++;
                tabEntreprise[i].nomEntreprise = nom;
                tabEntreprise[i].roleEntreprise = role;
                std::cout << "Inscription realisee (" << compteur << ")" << std::endl;
                return;
            }
        }
    }




