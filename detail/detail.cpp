#include "iostream"
#include "detail.h"
#include "iomanip"
using namespace std;
    void detail(){
        int idMission;
        cin >> idMission;

        auto it = tabMissionNonAttribue.find(idMission);
        if (it != tabMissionNonAttribue.end()) {
            const mission& mission = it->second;
            cout << mission.idMission << " "
                 << mission.nomMissions << " "
                 << mission.entreprisePublie.nomEntreprise << " "
                 << fixed << setprecision(2) << mission.remunerations << " ("
                 << mission.soustraitances << ")\n";

            for (int i = nbDetail - 1; i >= 0; --i) {
                if (!mission.detail[i].empty()) {
                    cout << mission.detail[i] << endl;
                }
            }

        } else {
            cout << "Identifiant incorrect" << endl;
        }

    }

