#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <cstdlib>

using namespace std;
int main() {
    int seires;
    int stiles;
    char symbol;
    int first;
    int second;
    int answer;
    int paixtes;
    double synolikoi;
    double pos;
    unordered_map<string, double> playerPercentages;

    cout << "Pata to space bar na jekinisei to paixnidi";

    do {
        cin >> answer;
    } while (answer !=3);

    cout << "Posoi paixtes eiste?";
    do {
        cin >> paixtes;
    } while (paixtes <= 0);

    vector<string> playerNames(paixtes);
    for (int i = 0; i < paixtes; ++i) {
        cout << "Dwse to onoma tou paixti " << i + 1 << ":";
        cin >> playerNames[i];
    }

    int gyroi;
    cout << "Grapse posous gyrous thelete na paijoume";

    do {
        cin >> gyroi;
    } while (gyroi <= 0);

    for (int counter1 = 0; counter1 < paixtes; counter1++) {
        int counter = 1;
        int nikes = 0;
        int misesnikes = 0;

        while (counter < gyroi) {
            cout << playerNames[counter1]<< " Dwse anw fragma gia seires:";
            cin >> first;

            cout << playerNames[counter1]<< " Dwse anw fragma gia stiles:";
            cin >> second;

            int num1 = (rand() % first) + 1;
            seires = num1;

            int num2 = (rand() % second) + 1;
            stiles = num2;

            cout << "Dwse kai to symbolo pou tha kanei to sxima";
            cin >> symbol;

            for (int i = 1; i <= seires; i++) {
                for (int j = 1; j <= stiles; j++) {
                    cout << symbol;
                }
                cout << '\n';
            }
            cout << "Eftiajes kati tyxaio eisai magkas" << '\n';
            cout << "Xwris na metriseis. Diaisthitika poses grammes kai steiles yparxoyn?" << '\n';
            cout << "Na dw an eisai grigoros" << '\n';

            int guess1;
            cout << "Poses nomizeis einai oi seires?";
            cin >> guess1;

            int guess2;
            cout << "Poses nomizeis einai oi stiles?";
            cin >> guess2;

            bool flag = false;
            bool seires1 = false;
            bool stiles1 = false;
            int cnt = 0;

            if (guess1 == seires) {
                cnt += 1;
                seires1 = true;
            }
            if (guess2 == stiles) {
                cnt += 1;
                stiles1 = true;
            }

            if (cnt == 2) {
                flag = true;
                nikes++;
            }

            if (flag == true) {
                cout << "Eisai grigoros telika mpravo"<<endl;
            } 
            else {
                if (cnt == 0) {
                    cout << "Eisai xazoulhs";
                } else if (cnt == 1) {
                    misesnikes++;
                    if (seires1) {
                        cout << "Niwtheis na metras mono orizontia."<<endl;
                    }
                    if (stiles1) {
                        cout << "Niwtheis na metras mono katheta"<<endl;
                    }
                }
            }
            counter++;
        }
        synolikoi = misesnikes * 0.5 + nikes;
        if (misesnikes + nikes != 0) {
            pos = (synolikoi / (misesnikes + nikes)) * 100;
        } else {
            pos = 0;
        }
        playerPercentages[playerNames[counter1]] = pos;
    }


    std::vector<std::pair<std::string, double>> sortedPlayers(playerPercentages.begin(), playerPercentages.end());
    std::sort(sortedPlayers.begin(), sortedPlayers.end(), [](const auto& a, const auto& b) {
        return a.second > b.second;
    });


    std::cout << "\nPercentage list of each player (sorted in descending order):\n";
    for (const auto& player : sortedPlayers) {
        std::cout << "Player " << player.first << ": " << player.second << "%\n";
    }


    if (!sortedPlayers.empty()) {
        std::cout << "\nThe winner is " << sortedPlayers.front().first << " with a percentage of " << sortedPlayers.front().second << "%\n";
    }

    return 0;
}