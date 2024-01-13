
using namespace std;

/**
 * @brief Calculates total resistance of provided circuit.
 * @return double 
 */
class get_Capacitance{
    vector<token> tokens;
public:
    int index = 0;

    /**
     * @brief Initialize from string
     * 
     * @param input string
     */
    get_Capacitance(string input){
        make_token list(input);
        tokens = list.get_tokens_vector();
    }
    /**
     * @brief Initialize from tokens
     * 
     * @param token_list token
     */
    get_Capacitance(vector<token> token_list){
        tokens = token_list;
    }
    /**
     * @brief Calculates total resistance
     * 
     * @return double 
     */
    double calculate(){
        token t = get_token();
        if (t.type == '(' ) {
            return cal_parallel();
        } else 
        if (t.type == '[' ) {
            return cal_series();
        }
            return 0;
    }

private:
    token get_token(){
        index++;
        return tokens[index-1];
    }
    void putback(){
        index--;
    }

    double cal_series(){
        token t = get_token();
        double eq = 0;
        if (t.type == '8'){
            eq = t.value;
        } else if (t.type == '(' || t.type == '['){
            putback();
            eq = calculate();
        }
        t = get_token();

        while(t.type == ','){
            t = get_token();
            if(t.type == '(' || t.type == '[' ){
            putback();
            eq += calculate();
            } else if (t.type == '8'){
            eq += t.value;
            }
            t = get_token(); //waste ')'
        }
        return eq;
    }
    double cal_parallel(){
        token t = get_token();
        double eq = 0;
        if (t.type == '8'){
            eq = t.value;
        } else if (t.type == '(' || t.type == '['){
            putback();
            eq = calculate();
        }
        t = get_token();

        while(t.type == ','){
            t = get_token();
            if(t.type == '(' || t.type == '[' ){
            putback();
            eq = 1.0/(1.0/eq + 1.0/calculate());
            } else if (t.type == '8'){
            eq = 1.0/(1.0/eq + 1.0/t.value);
            }
            t = get_token(); //waste ']'
        }
        return eq;
    }
};