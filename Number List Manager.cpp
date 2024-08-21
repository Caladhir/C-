#include <iostream>
#include <vector>
using namespace std;
/*
 * This program provides a menu-driven application where the user can perform operations on a list of numbers.
 *
 * The available options are:
 * - 'P': Display all numbers in the list. If the list is empty, a message is shown indicating that.
 * - 'A': Add a number to the list. The user is prompted to enter a number, which is then added to the list.
 * - 'M': Display the average (mean) of the numbers in the list. If the list is empty, a message is shown indicating that.
 * - 'S': Display the smallest number in the list. If the list is empty, a message is shown indicating that.
 * - 'L': Display the largest number in the list. If the list is empty, a message is shown indicating that.
 * - 'Q': Quit the program.
 *
 * The program uses a `do-while` loop to continuously display the menu and process user inputs until the user chooses to quit by selecting 'Q' or 'q'.
 * The program ensures that operations like finding the smallest, largest, or calculating the average are only performed when there are numbers in the list.
 */


int main() {
    
    char izbor{};
    vector <int>brojevi{};

    do {
        cout << "MENI ZA ODABIR:" << endl;
        cout << "----------------" << endl;
        cout << "P - Ispisi brojeve" << endl;
        cout << "A - Dodaj broj" << endl;
        cout << "M - Prikazi srednju vrijednost brojeva" << endl;
        cout << "S - Prikazi najamnji broj" << endl;
        cout << "L - Prikazi najveci broj" << endl;
        cout << "Q - Izlaz" << endl;
        cout << "-----------------------"<<endl;
        cin >> izbor;

        if (izbor == 'P' || izbor == 'p') {
            if (brojevi.empty()) {
                cout << "[] - lista je prazna" << endl;;
            }
            else {
                cout << endl;
                cout << "Lista brojeva je:" << endl;
                cout << "[ ";
                for (auto b : brojevi)
                    cout << b<<" ";
                cout << "}"<<endl;
                cout << endl;

            }
        }
        if (izbor == 'a' || izbor == 'A') {
            int broj{};
            cout << "Unesite broj koji zelite:";
            cin >> broj;
            brojevi.push_back(broj);
            cout << "Broj koji ste dodali je: " << broj << endl;
            cout << endl;

        }
        
        if (izbor == 'm' || izbor == 'M') {
            if (brojevi.empty()) {
                cout << "Ne može se izracunati jer nema podataka"<<endl;
            }
            else {
                int suma{};
                double srednjaVrijednost{};
                for (auto b : brojevi) {
                    suma += b;
                }
                srednjaVrijednost = static_cast<double>(suma) / brojevi.size();
                cout << endl;
                cout << "Srednja vrijednost brojeva je: " <<srednjaVrijednost << endl;
                cout << endl;
            }
        }

        if (izbor == 'S' || izbor == 's') {
            if (brojevi.empty()) {
                cout << "Nema brojeva." << endl;
            }
            else {
                int najmanji=brojevi.at(0);

                for (auto b : brojevi) {
                    if(b<najmanji){
                        najmanji = b;
                    }
                }
                cout << "Najmanji broj je: " << najmanji << endl;
                cout << endl;
            }
        }
        
        if (izbor == 'L' || izbor == 'l') {
            if (brojevi.empty()) {
                cout << "Nema brojeva." << endl;
            }
            else {
                int najveci = brojevi.at(0);

                for (auto b : brojevi) {
                    if (b > najveci) {
                        najveci = b;
                    }
                }
                cout << "Najveci broj je: " << najveci<< endl;
                cout << endl;
            }
        }

    } while (izbor != 'q' && izbor != 'Q');

    return 0;
}