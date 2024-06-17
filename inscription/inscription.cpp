#include <iostream>
#include <cctype>
#include "inscription.h"

const int nbRole = 3; // Nombre de rôles
const char* roleTab[nbRole] = {"AG", "OP", "IN"};

    int tailleTab = 0;
    Entreprise* tabEntreprise = nullptr;
    int compteurEntreprise = 1;

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
        bool  verifInscrit = true;
        cin >> role;
        cin >> nom;

        for (char& c : role) {
            c = toupper(c);
        }


        if (estDejaEntreprise(nom)){
           cout << "Nom incorrect";
            verifInscrit = false;
            return;
        }

        if (!verifRole(role)) {
            std::cout << "Rôle incorrect" << std::endl;
            verifInscrit = false;
            return;
        }
        if (verifInscrit) {
            for (int i = 0; i < tailleTab; ++i) {
                if (tabEntreprise[i].nomEntreprise.empty()) {
                    tabEntreprise[i].idEntreprise = compteurEntreprise;
                    tabEntreprise[i].nomEntreprise = nom;
                    tabEntreprise[i].roleEntreprise = role;
                    std::cout << "Inscription realisee (" << compteurEntreprise << ")" << std::endl;
                    compteurEntreprise++;
                    return;
                }
            }
        }
    }

    Entreprise* findEntreprise(int e){
        for (int i = 0; i < compteurEntreprise; ++i) {
            if (tabEntreprise[i].idEntreprise == e){
                return &tabEntreprise[i];
            }
        }
        return nullptr;
    }

    void affichageEntreprise(){
        for (int i = 0; i < compteurEntreprise; ++i) {
            cout << tabEntreprise[i].idEntreprise<< " " << tabEntreprise[i].roleEntreprise<< " " <<tabEntreprise[i].nomEntreprise << "\n";
        }
    }
    int getCompteurEntrprise(){
        return compteurEntreprise;
    }

