#include <iostream>
#include <ciso646>
using namespace std;
/*
 * This program determines the day of the week for a given date and checks if it's a working day.
 *
 * The user is prompted to input a date in the format DD MM YYYY.
 *
 * The program performs the following steps:
 * 1. It checks if the given date is January 1st or December 25th, which are considered holidays
 *    (non-working days). If so, it sets a flag (`jeLiPraznik`) to true.
 *
 * 2. For dates before October 15th, 1582 (Julian calendar), it calculates the day of the week
 *    using Zeller's congruence algorithm adjusted for the Julian calendar.
 *
 * 3. For dates after October 4th, 1582 (Gregorian calendar), it calculates the day of the week
 *    using Zeller's congruence algorithm adjusted for the Gregorian calendar.
 *
 * 4. If the date falls between October 5th and October 14th, 1582 (a period that doesn't exist
 *    due to the calendar transition), the program outputs that the date does not exist.
 *
 * 5. The program checks if the calculated day is Saturday or Sunday. If so, it sets the `jeLiPraznik`
 *    flag to true.
 *
 * 6. Finally, the program outputs the day of the week in abbreviated form (e.g., "NED" for Sunday,
 *    "PON" for Monday, etc.), and then it outputs whether the day is a working day or a non-working day
 *    based on the value of the `jeLiPraznik` flag.
 *
 * Note: Zeller's algorithm is used to calculate the day of the week where:
 * - 0 corresponds to Saturday
 * - 1 corresponds to Sunday
 * - 2 corresponds to Monday
 * and so forth.
 */

int main() {
    bool jeLiPraznik = false;
    cout << "Upisi datum u formatu DD MM GGGG: ";
    int dan, mjesec, godina;
    cin >> dan >> mjesec >> godina;
    if ((dan == 01 and mjesec == 01) or (dan == 25 and mjesec == 12)) {
        jeLiPraznik = true;
    }else if (mjesec == 1) {
        mjesec = 13;
        godina--;
    }
    if (mjesec == 2) {
        mjesec = 14;
        godina--;
    }
    int q = dan;
    int m = mjesec;
    int k = godina%100;
    int j = godina / 100;


    if (godina < 1582 || (godina == 1582 && (mjesec < 10 || (mjesec == 10 && dan <= 4)))) {
        //JULIJANSKI KALENDAR/JULIAN CALENDAR
        int h= q + 13 * (m + 1) / 5 + k+k/4 + 5 - j;
        h = h % 7;
        cout << dan << "." << mjesec << "." << godina << " pada u ";
        switch (h) {
        case 0: cout << "SUB"; jeLiPraznik = true;break; 
        case 1: cout << "NED"; jeLiPraznik = true; break;
        case 2: cout << "PON"; break;
        case 3: cout << "UTO"; break;
        case 4: cout << "SRI"; break;
        case 5: cout << "CET"; break;
        case 6: cout << "PET"; break;
        }
    }
    else if (godina > 1582 || (godina == 1582 && (mjesec > 10 || (mjesec == 10 && dan >= 15)))) {
        // Raèunanje dana u tjednu prema Gregorijanskom kalendaru/GREGORIAN CALENDAR
        int h = q + 13 * (m + 1) / 5 + k + k / 4 +j/4 -2* j;
        h = h % 7;
        cout << dan << "." << mjesec << "." << godina << " pada u ";
        switch (h) {
        case 0: cout << "SUB"; jeLiPraznik = true; break;
        case 1: cout << "NED"; jeLiPraznik = true; break;
        case 2: cout << "PON"; break;
        case 3: cout << "UTO"; break;
        case 4: cout << "SRI"; break;
        case 5: cout << "CET"; break;
        case 6: cout << "PET"; break;
        }
    }else {
        cout << "Datum ne postoji (5-14.10.1582)." << endl;
    }
    if (jeLiPraznik) {
        cout << ". neRADNI DAN JE" << endl;
    }
    else {
        cout << ". RADNI DAN JE" << endl;
    }
   
    return 0;
}
