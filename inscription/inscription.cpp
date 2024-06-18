#include <iostream>
#include <cctype>
#include "inscription.h"

    const int nbRole = 3; // Nombre de rôles
    const char* roleTab[nbRole] = {"AG", "OP", "IN"};

    const int tailleTab = 50;
    Entreprise* tabEntreprise = nullptr;
    int compteurEntreprise = 0;


    void initTabEntreprise() {
        tabEntreprise = new Entreprise[tailleTab];
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
                    tabEntreprise[i].idEntreprise = compteurEntreprise + 1;
                    tabEntreprise[i].nomEntreprise = nom;
                    tabEntreprise[i].roleEntreprise = role;
                    compteurEntreprise++;
                    std::cout << "Inscription realisee (" << compteurEntreprise << ")" << std::endl;
                    return;
                }
            }
        }
    }



    void affichageEntreprise(){
        for (int i = 0; i < compteurEntreprise; ++i) {
            cout << tabEntreprise[i].idEntreprise<< " " << tabEntreprise[i].roleEntreprise<< " " <<tabEntreprise[i].nomEntreprise << "\n";
        }
    }

    bool verifOperateurId(int id){
        for (int i = 0; i < compteurEntreprise; ++i) {
            if (tabEntreprise[i].idEntreprise == id && tabEntreprise->roleEntreprise == "OP"){
                return true;
            }
        }
        return false;
    }

    string NomEntreprisePourMission(int id){
        for (int i = 0; i < compteurEntreprise; ++i) {
            if (tabEntreprise[i].idEntreprise == id && tabEntreprise->roleEntreprise == "OP"){
                return tabEntreprise[i].nomEntreprise;
            }
        }
        return "x";
    }

    int getCompteurEntrprise(){
        return compteurEntreprise;
    }

