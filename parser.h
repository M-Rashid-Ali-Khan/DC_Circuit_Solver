using namespace std;

/**
 * @brief converts string to vector of make_token::token
 * @param string input sequence
 * @return tokenize the input sequence
 */
class make_token{
public: 
    make_token(string temp);
    /**
     * @brief Return token vector
     * 
     * @return vector<token> 
     */
    vector<token> get_tokens_vector(){
        return tokens;
    }
    vector<token> tokens;
private:
    string input;
    unsigned int parse_counter;

    double float_part();
    char parse();
    void putback();
    
    token num_tok(char temp){
        token piece;
        double num = 0;
        if(temp >= '0' && temp <= '9'){
            num = (temp - '0');
        } else {
            num = float_part();
        }
        while(true){
            char check = parse();
            if(check >= '0' && check <= '9' ) {
                double n2 = (check - '0');
                num *= 10;
                num += n2;
            }
            else if (check == '.'){
                num += float_part();
            }
            else {
                putback();
                piece.value = num;
                piece.type = '8';
                return piece;
            }
        }
    }
};

    make_token::make_token(string temp) : parse_counter(0), input(temp) {
        while(parse_counter < input.length()){
            char temp = parse();
            token piece;
            if(temp == ' '){;}
            else if(temp == '(' || temp == ')' || temp == '[' || temp == ']' || temp == ',') {
                piece.type = temp;
                tokens.push_back(piece);
                // tokens.push_back(piece);
            } else if((temp >= '0' && temp <= '9')||(temp == '.')){
                 piece = num_tok(temp);
                tokens.push_back(piece);
             }
        }
    }
    void make_token::putback(){
        parse_counter--;
    }

    double make_token::float_part(){
        int times = 1;
        while(true){
            char check = parse();
            double num = 0;
            if(check >= '0' && check <= '9' ) {
                    double n2 = (check - '0');
                    n2 /= 10*times;
                    num += n2;
                    times++;
            } else {
                putback();
                return num;
            }
        }
    }

        char make_token::parse(){
        if(parse_counter >= input.length()){
            cerr << "Exception: No more inputs are available.\n";
            return 0;
        } else {
            parse_counter++;
            return input[parse_counter-1];
        }        
    }
