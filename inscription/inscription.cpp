#include <iostream>
#include <cctype>
#include "inscription.h"

    const int nbRole = 3; // Nombre de rôles
    const string roleTab[nbRole] = {"AG", "OP", "IN"};

    map <int,Entreprise> tabEntreprise;

    int compteurEntreprise = 1;


    bool estDejaPresent(string& nom) {
        for (const auto& pair: tabEntreprise) {
            if (pair.second.nomEntreprise == nom){
                return true;
                break;
            }
        }
        return false;
    }

    bool verifRole(string& role){
        for (int i = 0; i < nbRole; ++i) {
            if (role == roleTab[i]) {
                return true;
                break;
            }
        }
        return false;
    }

    void inscription(){
        bool  verifInscrit = true;
        string role;
        string nom;

        cin >> role;
        cin >> nom;

        for (char& c : role) {
            c = toupper(c);
        }


        if (estDejaPresent(nom)){
           cout << "Nom incorrect"<< endl;
            verifInscrit = false;
        }
         if (!verifRole(role)) {
            cout << "Role incorrect" << endl;
            verifInscrit = false;
        }

        if (verifInscrit) {
            Entreprise e = {nom, role};
            tabEntreprise[compteurEntreprise] = e;
            tabEntreprise.insert({compteurEntreprise, e});
            cout << "Inscription realisee (" << compteurEntreprise << ")" << endl;
            compteurEntreprise++;
        }
        return;
    }



    void affichageEntreprise(){
        for (auto item = tabEntreprise.begin(); item != tabEntreprise.end(); item++ ) {
            cout << item->first << " " << item->second.nomEntreprise << " " << item->second.roleEntreprise << endl;
        }
    }




