
#ifndef S1_01_MISSION_H
#define S1_01_MISSION_H
#include <string>
#include "../inscription/inscription.h"

using  namespace std;

    struct mission{
        int idMission;
        string nomMissions;
        double remunerations;
        int soustraitances;
        string detail;
        Entreprise entreprisePublie;
    };

    extern map<int,mission> tabMissionNonAttribue;
    extern int compteurMission;


    void Mission();
    void affichageMission();

#endif //S1_01_MISSION_H
