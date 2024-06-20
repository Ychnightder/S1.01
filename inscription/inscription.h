#ifndef S1_01_INSCRIPTION_H
#define S1_01_INSCRIPTION_H
#include <string>
#include <map>
    using namespace std;

    struct Entreprise{
        string nomEntreprise;
        string roleEntreprise;

    };

    extern const int nbRole;
    extern const string roleTab[];
    extern map<int,Entreprise> tabEntreprise;
    extern int compteurEntreprise;


    bool estDejaPresent(string& nom);
    bool verifRole(string& role);
    void inscription();
    void affichageEntreprise();
#endif //S1_01_INSCRIPTION_H