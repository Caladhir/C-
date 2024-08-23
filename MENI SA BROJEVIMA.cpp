#include <iostream>
#include <vector>
#include <cctype>
#include <algorithm>  
#include <iterator>
using namespace std;
/*
 * This program allows the user to manage a list of integers and perform various operations on it.
 *
 * The operations include:
 * 1. Displaying all the numbers in the list.
 * 2. Adding a number to the list.
 * 3. Calculating and displaying the mean (average) of the numbers in the list.
 * 4. Finding and displaying the smallest number in the list.
 * 5. Finding and displaying the largest number in the list.
 * 6. Searching for a specific number and displaying its position if found.
 * 7. Exiting the program.
 *
 * The program uses functions for each of these operations to keep the code modular and organized.
 *
 * The program starts by displaying a menu, takes user input, and then performs the selected operation.
 * The loop continues until the user selects the option to quit ('Q').
 *
 * Main components:
 * - `vector<int>`: The list of integers managed by the user.
 * - `find`, `distance` (from <algorithm> and <iterator>): Used to search and determine the position of a number in the list.
 * - Loops and conditionals are used to handle the various operations and display appropriate messages.
 *
 * The functions handle the operations like printing the menu, adding numbers, displaying numbers, calculating the average, finding min/max numbers, and searching for a number.
 * The program also handles empty lists by showing appropriate messages when the list is empty.
 */

void prikaziMeni();
char odabirMeni();

void prikaziSveBrojeve(const vector<int> &v);
void dodajBrojeve(vector<int> &v );
void srednjaVrijednost(const vector<int> &v);
void najveciBroj(const vector<int> &v);
void najmanjiBroj(const vector<int>& v);
void pronadiBroj(const vector<int>& v);
void obrisiBrojeve(vector<int>&v);
void izlaz();
void nepoznatUnos();

void prikaziListuBrojeva(const vector<int> &v);
double izracunajSrednjuVrijednost(const vector<int>& v);
int uzmiNajmanji(const vector<int>& v);
int uzmiNajveci(const vector<int>& v);
bool pronadiBroj(const vector<int>& v, int trazeniBroj);



int main() {

    vector<int> brojevi;
    char izbor{};
    do {
        prikaziMeni();
        izbor = odabirMeni();
        switch (izbor) {
            case 'P': prikaziSveBrojeve(brojevi); break;
            case 'A': dodajBrojeve(brojevi); break;
            case 'M':srednjaVrijednost(brojevi); break;
            case 'S': najmanjiBroj(brojevi); break;
            case 'L': najveciBroj(brojevi); break;
            case 'F': pronadiBroj(brojevi); break;
            case 'D': obrisiBrojeve(brojevi); break;
            case 'Q':izlaz(); break;
            default:nepoznatUnos();
        }
    } while (izbor != 'Q');
        
    cout << endl;

    return 0;
}

void prikaziMeni()
{ cout << "MENI ZA ODABIR:" << endl;
cout << "----------------" << endl;
cout << "P - Ispisi brojeve" << endl;
cout << "A - Dodaj broj" << endl;
cout << "M - Prikazi srednju vrijednost brojeva" << endl;
cout << "S - Prikazi najamnji broj" << endl;
cout << "L - Prikazi najveci broj" << endl;
cout << "F - Pronadi zeljeni broj" << endl;
cout << "D - Obrisite brojeve iz liste" << endl;
cout << "Q - Izlaz" << endl;
cout << "-----------------------" << endl;
cout << "\nUnesite svoj izbor: ";
}

char odabirMeni()
{
    char izbor{};
    cin >> izbor;
    return toupper(izbor);
}

void prikaziSveBrojeve(const vector<int>& v)
{
    if (v.empty()) {
        cout << "[]-Lista je prazna";
    }
    else {
        prikaziListuBrojeva(v);
    }
}

void dodajBrojeve(vector<int>& v)
{
    int brojZaDodati{ 0 };
    cout << "Upisite broj koji zelite dodati u listu: ";
    cin >> brojZaDodati;
    if (find(v.begin(), v.end(), brojZaDodati) != v.end()) {
        cout << "Broj vec postoji u listi";
    }
    else {
        v.push_back(brojZaDodati);
        cout << "Dodali ste broj: " << brojZaDodati << endl;
    }
}

void srednjaVrijednost(const vector<int>& v)
{
    if (v.empty()) {
        cout << "[]-Lista je prazna";
    }
    else {
        cout<<"Srednja vrijednost je:"<< izracunajSrednjuVrijednost(v);
    }
}

void najveciBroj(const vector<int>& v)
{
    if (v.empty()) {
        cout << "[]-Lista je prazna";
    }
    else {
        uzmiNajveci(v);
    }
}

void najmanjiBroj(const vector<int>& v)
{
    if (v.empty()) {
        cout << "[]-Lista je prazna";
    }
    else {
     uzmiNajmanji(v);
    }
}

void pronadiBroj(const vector<int>& v)
{
    int trazeniBroj{};
    cout << "Unesite broj koji zelite pronaci: ";
    cin >> trazeniBroj;

    auto broj = find(v.begin(), v.end(), trazeniBroj);

    if (broj != v.end()) {
        int pozicija = distance(v.begin(), broj);  
        cout << trazeniBroj << " je pronaden i nalazi se na poziciji " << pozicija + 1 << "." << endl;
    }
    else {
        cout << trazeniBroj << " NIJE PRONADEN" << endl;
    }
}
void obrisiBrojeve(vector<int>& v)
{
    v.clear();
    cout << "Lista je ociscena" << endl;
}

void izlaz()
{
    cout << "BYE BYE!" << endl;
}

void nepoznatUnos()
{
    cout << "Krivi unos - pokušajte ponovno";
}

void prikaziListuBrojeva(const vector<int>& v)
{
    cout << "[";
    for (auto vec : v) {
        cout << vec << " ";
    }
    cout << "]"<<endl;
    
}

double izracunajSrednjuVrijednost(const vector<int>& v)
{
    int total{0};
    for (auto vec : v) {
        total += vec;
    }
    return static_cast<double>(total)/v.size();
}

int uzmiNajmanji(const vector<int>& v)
{
    int najmanji{v.at(0)};
    for (auto vec : v) {
        if (vec < najmanji) {
            najmanji = vec;
        }
    }
    return najmanji;
}

int uzmiNajveci(const vector<int>& v)
{
    int najveci{ v.at(0) };
    for (auto vec : v) {
        if (vec > najveci) {
            najveci = vec;
        }
    }
    return najveci;
}

bool pronadiBroj(const vector<int>& v, int ciljaniBroj)
{
    for (auto vec : v) {
        if (vec == ciljaniBroj) {
            return true;
        }
    }
    return false;
}
