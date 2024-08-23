#include <iostream>
#include <vector>
#include <limits>
#include <string>
#include <cstdlib>

using namespace std;
// This program simulates a basic ATM-like system where the user can:
// 1. Set a PIN and later authenticate with that PIN before accessing other functionalities.
// 2. Check their account balance, deposit funds, withdraw funds, and view the transaction history.
// 3. The user can set an initial balance, change the PIN, and see warnings if the account balance goes negative.

// Functions Overview:
// 1. `postaviPin` - Function to set the initial PIN. The user is prompted to input a 4-digit PIN.
// 2. `validanPin` - Function that allows the user to enter the PIN with a maximum of 3 attempts before locking them out.
// 3. `prikaziMenu` - Displays the menu options for the user to choose from.
// 4. `odabirMenu` - Takes user input to choose a menu option.
// 5. `prikaziIznos` - Displays the current account balance, with a warning if the balance is negative.
// 6. `Uplata` - Allows the user to deposit funds into the account.
// 7. `Isplata` - Allows the user to withdraw funds from the account, updating the balance accordingly.
// 8. `prikazPovijestiTransakcija` - Displays the transaction history.
// 9. `postaviPocetnoStanje` - Allows the user to set an initial account balance.
// 10. `promjenaPINA` - Allows the user to change the PIN.
// 11. `izlaz` - Displays a goodbye message when the user chooses to exit the program.
// 12. `validanUnos` - Validates user input, checking for errors in input and ensuring valid numeric entries.

void postaviPin(string& p);
bool validanPin(string &p);

void prikaziMenu();
int odabirMenu();


void prikaziIznos(const double& n);
void Uplata(double& n, vector<string>&t);
void Isplata(double& n, vector<string>& t);
void prikazPovijestiTransakcija(const vector<string>& t);
void postaviPocetnoStanje(double& n);
void promjenaPINA(string& p);
bool validanUnos();

void izlaz();

///************************MAIN***************************************
int main() {
    string pin{};
    postaviPin(pin);

    cout << "PIN uspjesno postavljen!";

    if (!validanPin(pin)) {
        cout << "Previse puta ste upisali krivi PIN. Izlaz iz programa." << endl;
        return 1;
    }




    double iznosNaRacunu{0};
    int izbor{0};
    vector<string>transakcije{};
    do {
        prikaziMenu();
        cout << "Upisite koju opciju zelite: ";
        izbor = odabirMenu();

        switch (izbor) {
        case 1: prikaziIznos(iznosNaRacunu); break;
        case 2: Uplata(iznosNaRacunu, transakcije); break;
        case 3: Isplata(iznosNaRacunu, transakcije); break;
        case 4: prikazPovijestiTransakcija(transakcije); break;
        case 5: postaviPocetnoStanje(iznosNaRacunu); break;
        case 6: promjenaPINA(pin); break;
        case 7: izlaz(); break;
        default: cout << "Pogresna opcija" << endl;
        }
    } while (izbor != 7);
    

    return 0;
}

///**************************************FUNKCIJE************************************
void postaviPin(string& p)
{   
    cout << "DOBRODOSLI,\nMolimo unesite PIN koji zelite koristiti (4 znamenke-XXXX):";
    cin >> p;
    while (p.length() != 4) {
        cout << "Neispravan PIN.PIN mora sadrzavati 4 znamenke.\n Pokusajte ponovno." << endl;
    }
    system("cls");
}

bool validanPin(string& p)
{
    string uneseniPin{};
    int brojPokusaja{};
    int dozvoljeniPokusaji{ 3 };
    while (brojPokusaja < dozvoljeniPokusaji) {
        

        cout << "Unesite PIN: ";
        cin >> uneseniPin;

        if (uneseniPin == p) {
            return true;
        }
        else {
            brojPokusaja++;
            cout << "Preostalo jos " << dozvoljeniPokusaji - brojPokusaja<< " pokusaja." << endl;
            system("pause"); 
            system("cls");
        }
    }
    return false;
}

void prikaziMenu() {
    cout << "**********MENU********" << endl;
    cout << "1. Provjeri iznos" << endl;
    cout << "2. Uplata" << endl;
    cout << "3. Isplata" << endl;
    cout << "4. Povijest transakcija" << endl;
    cout << "5. Postavi pocetno stanje" << endl;
    cout << "6. Promijeni PIN" << endl;
    cout << "7. IZLAZ" << endl;
    cout << "**********************" << endl;
    cout << endl;
}

int odabirMenu()
{
    int izbor{};
    cin >> izbor;
    return izbor;
 
}



void prikaziIznos(const double &n)
{
    double iznos = n;
    cout <<"Trenutno stanje racuna je: " << iznos << endl;
    if (iznos < 0) {
        cout << "OPREZ!!! , stanje na raèunu je u minusu" << endl;
    }
    system("pause");
    system("cls");
    cout << endl;
    
}

void Uplata(double& n, vector<string>& t)
{
    double iznosUplate{};
    cout << "Unesite iznos koji zelite uplatiti: ";
    cin >> iznosUplate;
    if (iznosUplate > 0) {
        n += iznosUplate;
        cout << "Uspjesno ste uplatili " << iznosUplate<<endl;
        cout << "Iznos na racunu je sada: " << n << endl;
    }
    else {
        cout << "Iznos uplate mora biti pozitivan" << endl;
    }
    cout << endl;
}

void Isplata(double& n, vector<string>& t)
{
    double iznosIsplate{};
    cout << "unesite iznos koji zelite isplatiti: ";
    cin >> iznosIsplate;
    if (iznosIsplate > 0) {
        n -= iznosIsplate;
        cout << "Isplaceno je: " << iznosIsplate<<endl;
        cout << "Trenutno stanje racuna je: " << n << endl;
    }
    else {
        cout << "Iznos ne može biti negativan" << endl;
    }
    cout << endl;
}

void prikazPovijestiTransakcija(const vector<string>& t)
{
    cout << "Povijest transakcija: " << endl;
    if (t.empty()) {
        cout << "Nema dosadasnjih transakcija!" << endl;
    }
    else for (const auto& transakcija : t) {
        cout << transakcija << endl;
    }
    cout << endl;
}

void postaviPocetnoStanje(double& n)
{
    cout << "Postavi pocetno stanje: ";
    while (true) {
        if (validanUnos()) {
            cin >> n;
            cout << "Stanje racuna postavljeno na: " << n << " eura" << endl;
            break;
        }
        else {
            cout << "Neispravan unos";
        }
    }
    cout << endl;
}

void promjenaPINA(string& p)
{
    string noviPIN{};
    cout << "Unesite novi PIN(4 znamenke-XXXX): ";
    cin >> noviPIN;
    if (noviPIN.length() == 4 && validanUnos()) {
        p = noviPIN;
        cout << "PIN uspjesno promjenjen." << endl;
    }
    else {
        cout << "Neispravan PIN, Motra imati 4 znamenke.";
    }

}

void izlaz()
{
    cout << endl;
    cout << "BOK " << endl;
    cout << endl;
}
bool validanUnos() {
    if (cin.fail()) {
        cin.clear(); 
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
        return false;
    }
    return true;
}