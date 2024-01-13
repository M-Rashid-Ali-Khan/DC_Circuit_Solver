#include"colours.h"
#include <limits>
#include <exception>
#include "circuitSolver.h"
#include "DeltaY.h"
#include "func_Implent.h"

using namespace std;


void Display(){
    int select = 0;
    bool retry = 0,back = 0;

    do{
        if(retry) cout << RED "Please enter a valid digit corresponding to each item in menu....\n" NC;
        retry = false;
        cout << CYN "\t\t\t\t ------ DC Circut Solver --------\n" NC
            << CYN "\t\t\t\t| " NC  "1. Instructions                " CYN "|\n" NC
            << CYN "\t\t\t\t| " NC  "2. Resistance                  " CYN "|\n" NC
            << CYN "\t\t\t\t| " NC  "3. Capacitance                 " CYN "|\n" NC
            << CYN "\t\t\t\t| " NC  "4. Inductance                  " CYN "|\n" NC
            << CYN "\t\t\t\t| " NC  "5. Delta - Y Transform         " CYN "|\n" NC
            << CYN "\t\t\t\t| " NC  "6. Filter Design               " CYN "|\n" NC
            << CYN "\t\t\t\t| " NC  "7. Thevenin                    " CYN "|\n" NC
            << CYN "\t\t\t\t| " NC  "8. Norton                      " CYN "|\n" NC
            << CYN "\t\t\t\t| " NC  "9. About                       " CYN "|\n" NC
            << CYN "\t\t\t\t -------------------------------- \n" NC
            << "Select an option by entering its number(or 0 to exit):";
        cin >> select;
        switch (select) {
            case 1:
                Instructions(); back = true;
                break;
            case 2:
                Resistance(); back = true;
                break;
            case 3:
                Capacitance(); back = true;
                break;
            case 4:
                Inductance(); back = true;
                break;
            case 5:
                DeltaY(); back = true;
                break;
            case 6:
                RC(); back = true;
                break;
            case 7:
                Thevenin(); back = true;
                break;
            case 8:
                Norton(); back = true;
                break;
            case 9:
                About(); back = true;
                break;
            case 0:
                system("CLS");
                cout << "\t\t\tThank You! Good Bye....\n";
                system("pause");
                return;
            default:
            retry = true; back = true;
            reset_cin();
        }
    } while(back);//To return to first screen
    system("CLS");
    cout << "\t\t\tThank You! Good Bye....\n";
    system("pause");
}

int main(){
    try{
        Display();
    }catch(runtime_error r){
        cerr << "Runtime error :: " << r.what() << endl;
    } catch (exception &e) {
        cerr << "Exception caught :: " << e.what() << endl;
    } catch (...) {
        cerr << "Unexpected exception\n";
    }
}