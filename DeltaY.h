using namespace std;

class Delta_Y
{
private:
double res_a;
double res_b;
double res_c;
public:
double res1;
double res2;
double res3;

    Delta_Y(double a, double b, double c)
    {
        res_a = a;
        res_b = b;
        res_c = c;
    }
    
    void transform ()
    {
        res1=(res_b*res_c)/(res_a+res_b+res_c);
        res2=(res_a*res_c)/(res_a+res_b+res_c);
        res3=(res_a*res_c)/(res_a+res_b+res_c);
     cout << endl <<"R1: "<<res1 << "\tR2:" << res2 << "\tR3" << res3 << endl;
    }
};


