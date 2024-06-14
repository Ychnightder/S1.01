

#ifndef S1_01_INSCRIPTION_H
#define S1_01_INSCRIPTION_H
#include <string>
using namespace std;

    struct Entreprise{
        int idEntreprise;
        string nomEntreprise;
        string roleEntreprise;
    };

    extern const int nbRole;
    extern const char* roleTab[];


    extern int tailleTab;
    extern Entreprise* tabEntreprise;
    extern int compteur;

    void initTabEntreprise(int taille);
    void suppTabEntreprise();
    bool estDejaEntreprise(string& nom);
    bool verifRole(string& role);
    void inscription();


#endif //S1_01_INSCRIPTION_H
