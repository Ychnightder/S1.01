

#ifndef S1_01_RAPPORT_H
#define S1_01_RAPPORT_H
#include "string"
#include "../mission/mission.h"

using namespace std;

    enum CodeRapport {
        ZERO = 0,
        UN = 1,
        DEUX = 2,
        TROIS = 3
    };

    struct rapport{
        CodeRapport code;
        string Signification;
        double majoration;
    };

    extern const int tailleTabR;
    extern rapport tabRapport[];



    string getDetail(int  cr);
    double getMajoration(int cr);
    void Rapport();
    bool verifiCode(int c);
    double majorerMission(double prixMission , double codeR);


#endif //S1_01_RAPPORT_H
