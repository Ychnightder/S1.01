
#ifndef S1_01_MISSION_H
#define S1_01_MISSION_H
#include <string>
#include "../inscription/inscription.h"
#include "../rapport/rapport.h"

using  namespace std;

    struct mission{
        int idMission;
        string nom;
        double prix;
        Entreprise* e;
        int soustraitance;
        rapport rapport;
    };
    extern int tailleTabM;
    extern mission* tabMission;
    extern int compteurM;


    void initTabMission(int taille);
    void suppTabMission();
    bool estDejaMission(int& id);
    void Mission();
    int getCompteurMission();
    void affichageMission();
#endif //S1_01_MISSION_H
