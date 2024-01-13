
#include <math.h>
using namespace std;

class Filter
{
private:
double res;
double cap;
double freq;
bool fil;
public:
    void freq_cal()
    {
        freq=1/2*(M_PI)*(res*cap);
        
    }
    void cap_cal()
    {
        cap=1/2*(M_PI)*(res*freq);
        
    }
    void res_cal()
    {
        res=1/2*(M_PI)*(freq*cap);
        
    }
    void Calculate()
    {
        char sw1;
        char sw2;
        cout<<"Press 'H' for high pass filter and 'L' for low pass filter \n";
        cin>>sw1;
        switch (sw1)
        {
        case 'H':
        fil=true;
            cout<<"Press 'R' if you wish to calculate resistance , 'C' for capacitance and 'F' for frequency \n";
            cin>>sw2;
            switch (sw2)
            {
            case 'R':
                cout<<"Enter value of capacitance and cut off frequency\n";
                cin>>cap>>freq;
                res_cal();
                break;
            case 'C':
                cout<<"Enter value of Resistnce and cut off frequency\n";
                cin>>res>>freq;
                cap_cal();
                break;
            case 'F':
                cout<<"Enter value of Resistnce and Capacitance\n";
                cin>>res>>cap;
                freq_cal();
                break;
            
            default:
            cout<<"Invalid choice\n";
                break;
            }

            break;


        case 'L':
        fil=false;
            cout<<"Press 'R' if you wish to calculate resistance , 'C' for capacitance and 'F' for frequency \n";
            cin>>sw2;
            switch (sw2)
            {
            case 'R':
                cout<<"Enter value of capacitance and cut off frequency\n";
                cin>>cap>>freq;
                res_cal();
                break;
            case 'C':
                cout<<"Enter value of Resistnce and cut off frequency\n";
                cin>>res>>freq;
                cap_cal();
                break;
            case 'F':
                cout<<"Enter value of Resistnce and Capacitance\n";
                cin>>res>>cap;
                freq_cal();
                break;
            
            default:
            cout<<"Invalid choice\n";
            break;
            }
            break;
        default:
        cout<<"Invalid choice\n";
            break;
        }
        output();
        
    }

    void output()
    {
        if(fil==true)
        {
            cout<<" High pass filter is across Resistor with the following values \n";
            cout<<"Resistance = "<<res<<"Ohms , Capacitance = "<<cap<<"farads and frequency = "<<freq<<"herdz"<<endl;
        }

        else
        {
            cout<<" Low pass filter is across Capacitor with the following values \n";
            cout<<"Resistance = "<<res<<"Ohms , Capacitance = "<<cap<<"Farads and frequency = "<<freq<<"herdz"<<endl;
        }
    }
};
