

#ifndef S1_01_ACCEPTATION_H
#define S1_01_ACCEPTATION_H

#include "../inscription/inscription.h"
#include "../mission/mission.h"

    struct Acceptation{
            string idA;
            Entreprise* e;
            mission* m;
    };

    extern Acceptation* tabAttribue;
    extern const int tailleAttribue;
    extern int comteurAc;


    void acceptation();
    void initTabAttribue();
    void suppTabAttribue();
    int getCompteurAttribue();

#endif //S1_01_ACCEPTATION_H
