#define T "\t\t\t\t"

void reset_cin(){
    if(!cin) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}
void error(string s){
    cout << RED << s << NC;
    reset_cin();
}
void Instructions(){
    system("CLS"); //Clear screen
    cout << T << "________DC Circut Solver_________\n"
    <<"It is afree program to solve problems of DC circuits and can be utilied by students taking subjects\n"
    <<"like Electric Circut Analysis. The program has a lot of features and proper guidance is provided inside\n"
    <<"the program.\n"
    <<endl
    <<"The home page lists all the options available in the program. To select any option, click the number\n"
    <<"of that option. Rest of the procedure is documented inside the program.\n";
    system("pause"); //Press any key to continue . . . 
    system("CLS");
}
void Resistance(){
    system("CLS");
    cout << T << CYN "___________RESISTANCE CALCULATOR___________\n" NC
    << "Enter the values of resistances in the following format to calculate total resistances:\n"
    << "1. Enter values of resistors in a list from positive to negative terminal and putting commas in between.\n"
    << "2. Resistors in series should be enclosed in parentheses like this (2,4,345,56)\n"
    << "3. resistors in parallel should be enclosed in square brackets [33,56,667,56]\n"
    << "4. Combination of series and parallel is allowed through nesting [2,4(4,5,[4,6],5)]\n\n"
    << "Enter your expression:\n"
    ;
    string input; double result;
    cin >> input;
    make_token temp(input);
    get_Resistance total( temp.get_tokens_vector());
    result = total.calculate();
    cout << "Equivalent Resistance: " << result << " ohm "<< endl << endl;
    system("pause");
    system("CLS");
}
void Capacitance(){
    system("CLS");
    cout << T << CYN "___________CAPACITANCE CALCULATOR___________\n" NC
    << "Enter the values of capacitance in the following format to calculate total capacitance:\n"
    << "1. Enter values of capacitance in a list from positive to negative terminal and putting commas in between.\n"
    << "2. Capacitance in series should be enclosed in parentheses like this (2,4,345,56)\n"
    << "3. Capacitance in parallel should be enclosed in square brackets [33,56,667,56]\n"
    << "4. Combination of series and parallel is allowed through nesting [2,4(4,5,[4,6],5)]\n\n"
    << "Enter your expression:\n"
    ;
    string input; double result;
    cin >> input;
    make_token temp(input);
    get_Capacitance total( temp.get_tokens_vector());
    result = total.calculate();
    cout << "Equivalent Capacitance: " << result << " Farads "<< endl << endl;
    system("pause");
    system("CLS");
}
void Inductance(){
    system("CLS");
    cout << T << CYN "___________INDUCTANCE CALCULATOR___________\n" NC
    << "Enter the values of inductance in the following format to calculate total inductance:\n"
    << "1. Enter values of inductance in a list from positive to negative terminal and putting commas in between.\n"
    << "2. Inductors in series should be enclosed in parentheses like this (2,4,345,56)\n"
    << "3. Inductiors in parallel should be enclosed in square brackets [33,56,667,56]\n"
    << "4. Combination of series and parallel is allowed through nesting [2,4(4,5,[4,6],5)]\n\n"
    << "Enter your expression:\n"
    ;
    string input; double result;
    cin >> input;
    make_token temp(input);
    get_Resistance total( temp.get_tokens_vector());
    result = total.calculate();
    cout << "Equivalent Inductance: " << result << " Henry" << endl << endl;
    system("pause");
    system("CLS");
}
void DeltaY(){
    system("CLS");
    cout << T << CYN "___________DELTA-Y TRANSFORM___________\n" NC ;
    double r1 =0,r2=0,r3=0;
    cout << "Enter the values of Ra,Rb and Rc...\n";
    cout << "Ra:" ;
    cin >> r1;
    cout << "Rb:" ;
    cin >> r2; 
    cout << "Rc:";
    cin >> r3;
    Delta_Y dY(r1,r2,r3);
    dY.transform();
    system("pause");
    system("CLS");

}
void RC(){
    system("CLS");
    cout << T << CYN "___________Filter Design___________\n" NC ;
    Filter rc;
    rc.Calculate();
    system("pause");
    system("CLS");
}
void Thevenin(){
    system("CLS");
    cout << T << CYN "___________Thevenin Equivalent___________\n" NC 
    << "To calculate Thevenin, first provide the circuit network....\n";
    double voltS = 0.0, var_res = 0;
    cout << "Enter the value of of voltage source:";
    cin >> voltS;
    cout
    << "Now enter the values of resistances in the following format :\n"
    << "1. Enter values of resistors in a list from positive to negative terminal and putting commas in between.\n"
    << "2. Resistors in series should be enclosed in parentheses like this (2,4,345,56)\n"
    << "3. resistors in parallel should be enclosed in square brackets [33,56,667,56]\n"
    << "4. Combination of series and parallel is allowed through nesting [2,4(4,5,[4,6],5)]\n\n"
    << "Enter your expression:\n"
    ;
    string input; double result;
    cin >> input;
    make_token temp(input);
    get_Resistance total( temp.get_tokens_vector());
    result = total.calculate();
    cout << endl << "......Thevenin Equivalent is ready.......\n";
    char replace = 0;
    do{
        cout << "Enter the value of variable resistor:";
        cin >> var_res;
        cout << "Voltage accross resistor: " << var_res*(voltS/(var_res+result)) << endl
        << "Current through resistor: " << (voltS/(var_res+result)) << endl << endl
        << "Press R to replace resistor, E to return to home screen:";
        cin >> replace;
    }while(replace == 'R');
        system("CLS");
}
void Norton(){
    system("CLS");
    cout << T << CYN "___________Norton Equivalent___________\n" NC 
    << "To calculate Norton, first provide the circuit network....\n";
    double currS = 0.0, var_res = 0;
    cout << "Enter the value of of current source:";
    cin >> currS;
    cout
    << "Now enter the values of resistances in the following format :\n"
    << "1. Enter values of resistors in a list from positive to negative terminal and putting commas in between.\n"
    << "2. Resistors in series should be enclosed in parentheses like this (2,4,345,56)\n"
    << "3. resistors in parallel should be enclosed in square brackets [33,56,667,56]\n"
    << "4. Combination of series and parallel is allowed through nesting [2,4(4,5,[4,6],5)]\n\n"
    << "Enter your expression:\n"
    ;
    string input; double result;
    cin >> input;
    make_token temp(input);
    get_Resistance total( temp.get_tokens_vector());
    result = total.calculate();
    cout << endl << "......Norton Equivalent is ready.......\n";
    char replace = 0;
    do{
        cout << "Enter the value of variable resistor:";
        cin >> var_res;
        cout << "Voltage accross resistor: " << var_res*(currS*result/(result+var_res)) << endl
        << "Current through resistor: " << (currS*result/(result+var_res)) << endl
        << "Press R to replace resistor, E to return to home screen:";
        cin >> replace;
    }while(replace == 'R');
    system("CLS");
}
void About(){
    system("CLS");
    cout << "This DC Circuit Solver is created by Muhammad Rashid Ali Khan.\n"
    "The program is initially designed to be presented as a project.\n"
    "This is a stable version. Beta version is in development and soon be made open source.\n";
    system("pause");
    system("CLS");
    }
