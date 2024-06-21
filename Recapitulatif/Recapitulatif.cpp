#include "Recapitulatif.h"
#include "iostream"
#include "iomanip"
    using namespace  std;
    map<int,mission> tabTerminer;

    void recapitulatif (){
        int idEntreprise;
        cin >> idEntreprise;

        bool  verifRecap = true;

        auto itEntreprise = tabEntreprise.find(idEntreprise);
        if (itEntreprise == tabEntreprise.end()) {
            cout << "Entreprise incorrecte" << endl;
            verifRecap = false;
        }

        if (verifRecap) {

            if (itEntreprise->second.roleEntreprise == "OP") {
                if (!tabMissionNonAttribue.empty()  ) {
                    bool estNonAttribue = false;
                    for (const auto &item: tabMissionNonAttribue) {
                        if (itEntreprise->second.nomEntreprise == item.second.entreprisePublie.nomEntreprise || itEntreprise->second.nomEntreprise == item.second.attribue.nomEntreprise) {
                            if (!estNonAttribue) {
                                cout << "* non attribuees" << endl;
                                estNonAttribue = true;
                            }

                            cout << "   "<< item.first << " "
                                 << item.second.nomMissions << " "
                                 << item.second.entreprisePublie.nomEntreprise << " "
                                 << fixed << setprecision(2) << item.second.remunerations << " "
                                 << "(" << item.second.soustraitances << ")" << endl;
                        }
                    }
                }

                if (!tabAttribue.empty()){
                    bool estAttribue = false;
                    for (const auto &item: tabAttribue) {
                        if (itEntreprise->second.nomEntreprise == item.second.entreprisePublie.nomEntreprise) {
                            if (!estAttribue){
                                cout << "* attribuees" << endl;
                                estAttribue = true;
                            }
                            cout << "   "<< item.first << " "
                                 << item.second.nomMissions << " "
                                 << item.second.entreprisePublie.nomEntreprise << " "
                                 << fixed << setprecision(2) << item.second.remunerations << " "
                                 << "(" << item.second.soustraitances << ")" << endl;
                        }
                    }
                }
                if (!tabTerminer.empty()) {
                    // Terminées

                    bool estTerminees = false;
                    for (const auto &item: tabTerminer) {
                        if (itEntreprise->second.nomEntreprise == item.second.entreprisePublie.nomEntreprise) {
                            if (!estTerminees){
                                cout << "* terminees" << endl;
                                estTerminees = true;
                            }
                            cout << "   "<< item.first << " "
                                 << item.second.nomMissions << " "
                                 << item.second.entreprisePublie.nomEntreprise << " "
                                 << fixed << setprecision(2) << item.second.remunerations << " "
                                 << "(" << item.second.soustraitances << ")" << endl;
                        }
                    }
                }
            } else if (itEntreprise->second.roleEntreprise == "AG"){
                bool hasNonAttribue = false;
                for (const auto &item: tabMissionNonAttribue) {
                    if (itEntreprise->second.nomEntreprise == item.second.entreprisePublie.nomEntreprise) {
                        if (!hasNonAttribue) {
                            cout << "* non attribuees" << endl;
                            hasNonAttribue = true;
                        }
                        cout << "  " << item.first << " "
                             << item.second.nomMissions << " "
                             << item.second.entreprisePublie.nomEntreprise << " "
                             << fixed << setprecision(2) << item.second.remunerations << " "
                             << "(" << item.second.soustraitances << ")" << endl;
                    }
                }

                bool hasRealisees = false;
                for (const auto &item: tabTerminer) {
                    if (itEntreprise->second.nomEntreprise == item.second.entreprisePublie.nomEntreprise) {
                        if (!hasRealisees) {
                            cout << "* realisees" << endl;
                            hasRealisees = true;
                        }
                        cout << " " << item.first << " "
                             << item.second.nomMissions << " "
                             << item.second.entreprisePublie.nomEntreprise << " "
                             << fixed << setprecision(2) << item.second.remunerations << " "
                             << "(" << item.second.soustraitances << ")" << endl;
                    }
                }
            }
            else{

                if (!tabAttribue.empty()) {
                    bool estARealiser = false;
                    for (const auto &item: tabAttribue) {
                        if (itEntreprise->second.nomEntreprise == item.second.attribue.nomEntreprise) {
                            if (!estARealiser){
                                cout << "* a realiser" << endl;
                                estARealiser = true;
                            }
                            cout << "   "<< item.first << " "
                                 << item.second.nomMissions << " "
                                 << item.second.entreprisePublie.nomEntreprise << " "
                                 << fixed << setprecision(2) << item.second.remunerations << " "
                                 << "(" << item.second.soustraitances << ")" << endl;
                        }
                    }
                }

                if (!tabTerminer.empty()) {
                    bool estRealiser = false;
                    for (const auto &item: tabTerminer) {
                        if (itEntreprise->second.nomEntreprise == item.second.attribue.nomEntreprise) {
                            if (!estRealiser){
                                cout << "* realisees" << endl;
                                estRealiser = true;
                            }
                            cout << "   "<< item.first << " "
                                 << item.second.nomMissions << " "
                                 << item.second.entreprisePublie.nomEntreprise << " "
                                 << fixed << setprecision(2) << item.second.remunerations << " "
                                 << "(" << item.second.soustraitances << ")" << endl;
                        }
                    }
                }



            }

        }
    }