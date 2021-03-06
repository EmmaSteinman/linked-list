//=======================================================
// Emma Steinman
// February 7, 2017
// This program tests various features of strings.
//=======================================================

#include <iostream>
#include <string>
using namespace std;

//=======================================================
// main
//=======================================================

int main (void)
{
    string first; 
    string last;
    string full;

    first = "Emma";
    last = "Steinman";
   // full = first + " " + last;

    first.append(" ");
    first.append(last);
    first.append(10, 'X');

    string first2;
    first2 = first.substr(0,5);
   
    
    //cout << length << endl;

    cout << first2[1] << endl;
    
    cout << "First = " << first << endl;
    
    first.replace(1,2, "liz");
    
    first.erase(14, 19);

    cout << "First = " << first << endl;
    cout << "Last = " << last << endl;
    cout << "Full = " << full << endl;

    return 0;
}
