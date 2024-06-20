
#ifndef S1_01_MISSION_H
#define S1_01_MISSION_H
#include <string>
#include "../inscription/inscription.h"

using  namespace std;

 const int nbDetail = 5;

struct mission{
        int idMission;
        string nomMissions;
        double remunerations;
        int soustraitances;
        string detail[nbDetail];
        Entreprise entreprisePublie;
        Entreprise attribue;
    };

    extern map<int,mission> tabMissionNonAttribue;
    extern int compteurMission;

    void Mission();
    void affichageMission();

#endif //S1_01_MISSION_H
