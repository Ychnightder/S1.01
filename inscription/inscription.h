

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


    extern const int tailleTab;
    extern Entreprise* tabEntreprise;
    extern int compteurEntreprise;

    void initTabEntreprise(int taille);
    void initTabEntreprise();
    void suppTabEntreprise();
    bool estDejaEntreprise(string& nom);
    bool verifRole(string& role);
    int getCompteurEntrprise();
    void inscription();
    void affichageEntreprise();
    bool verifOperateurId(int id);
    string NomEntreprisePourMission(int id);


#endif //S1_01_INSCRIPTION_H
