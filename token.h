/**
 * @brief datatype token
 * 
 */
struct token{
public:
        char type;
        double value = 0;
        token(){}
        token (char t, double v) : type (t), value (v){}
        token (char t) : type (t), value (0){}
        void change (char t, double v){
            type = t;
            value = v;
        }
        void change (char t){
            type = t;
            value = 0;
        }
    };
    // ostream& operator<<(ostream& os, const token& tt)
    // {
    //     os << "token - type: " << tt.type << "| value: " << tt.value << endl;
    //     return os;
    // }