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
                if (!tabMissionNonAttribue.empty()) {
                    // Non attribuées
                    cout << "* non attribuees" << endl;
                    for (const auto &item: tabMissionNonAttribue) {
                        if (itEntreprise->second.nomEntreprise == item.second.entreprisePublie.nomEntreprise) {
                            cout << "  "<< item.first << " "
                                 << item.second.nomMissions << " "
                                 << item.second.entreprisePublie.nomEntreprise << " "
                                 << fixed << setprecision(2) << item.second.remunerations << " "
                                 << "(" << item.second.soustraitances << ")" << endl;
                        }
                    }
                }

                if (!tabAttribue.empty()){
                // Attribuées
                    cout << "* attribuees" << endl;
                    for (const auto &item: tabAttribue) {
                        if (itEntreprise->second.nomEntreprise == item.second.entreprisePublie.nomEntreprise) {
                            cout << "  "<< item.first << " "
                                 << item.second.nomMissions << " "
                                 << item.second.entreprisePublie.nomEntreprise << " "
                                 << fixed << setprecision(2) << item.second.remunerations << " "
                                 << "(" << item.second.soustraitances << ")" << endl;
                        }
                    }
                }
                if (!tabTerminer.empty()) {
                    // Terminées
                    cout << "* terminees" << endl;
                    for (const auto &item: tabTerminer) {
                        if (itEntreprise->second.nomEntreprise == item.second.entreprisePublie.nomEntreprise) {
                            cout << "  "<< item.first << " "
                                 << item.second.nomMissions << " "
                                 << item.second.entreprisePublie.nomEntreprise << " "
                                 << fixed << setprecision(2) << item.second.remunerations << " "
                                 << "(" << item.second.soustraitances << ")" << endl;
                        }
                    }
                }
            } else{

                if (!tabAttribue.empty()) {
                    cout << "* a realiser" << endl;

                    for (const auto &item: tabAttribue) {
                        if (itEntreprise->second.nomEntreprise == item.second.attribue.nomEntreprise) {
                            cout << "  "<< item.first << " "
                                 << item.second.nomMissions << " "
                                 << item.second.entreprisePublie.nomEntreprise << " "
                                 << fixed << setprecision(2) << item.second.remunerations << " "
                                 << "(" << item.second.soustraitances << ")" << endl;
                        }
                    }
                }

                if (!tabTerminer.empty()) {
                    cout << "* realisees" << endl;
                    for (const auto &item: tabTerminer) {
                        if (itEntreprise->second.nomEntreprise == item.second.attribue.nomEntreprise) {
                            cout << " "<< item.first << " "
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