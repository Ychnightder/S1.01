#include "consultation.h"
#include "iostream"
#include <iomanip>


    void consultation(){
        if (tabMissionNonAttribue.empty()){
            cout << "Aucune mission disponible" << endl;
        } else{
            for (const auto& item : tabMissionNonAttribue) {
                cout << item.first<< " "
                     << item.second.nomMissions<< " "
                     << item.second.entreprisePublie.nomEntreprise<< ""
                     << fixed << setprecision(2)<< " "
                     << item.second.remunerations<< " "
                     <<"("
                     <<item.second.soustraitances<<")"
                     <<endl;
            }
        }
    }
