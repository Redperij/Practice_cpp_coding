#include "Question.h"

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// CONSTRUCTORS //
//////////////////

Question::Question(std::string q_text, std::string cor_ans, std::vector<std::string> alt_ans) : q_text(q_text), cor_ans(cor_ans), alt_ans(alt_ans) {}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// FUNCTIONS //
///////////////

// Show question with 3 randomly chosen alternative answers (one of them is correct).
// Returns: Correct answer position.
unsigned int Question::show_question(){
    std::vector<std::string> chosen_answers;
    unsigned int pos_corr_ans;

    //Making sure that nothing will go wrong.
    this->generate_alt(); //Generate random alt answers if not having enough.
    {
        std::vector<unsigned int> pos_alt_ans(2);
        UniqueRng r_gen1(0, this->alt_ans.size() - 1); //alt_size must never be lower than 3.
        UniqueRng r_gen2(0, 2);
        
        //Generating random numbers.
        generate(pos_alt_ans.begin(), pos_alt_ans.end(), r_gen1);
        pos_corr_ans = r_gen2();

        //Positioning chosen anwers to chosen positions.
        unsigned int q = 0;
        for (unsigned int i = 0; i < 3; i++) {
            if (i == pos_corr_ans) {
                chosen_answers.push_back(this->cor_ans);
            }
            else {
                chosen_answers.push_back(this->alt_ans[pos_alt_ans[q]]);
                q++;
            }
        }
    }
    
    //Presenting question with chosen answers.
    std::cout << *this << std::endl;
    for (unsigned int i = 1; i <= chosen_answers.size(); i++) {
        std::cout << i << ") " << chosen_answers[i - 1] << std::endl;
    }
    return pos_corr_ans + 1;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// OPERATORS //
///////////////

//Prints question text.
std::ostream &operator<<(std::ostream &out, const Question &question) {
    out << question.q_text;
    return out;
}
//Get question from user.
std::istream &operator>>(std::istream &in, Question &question) {
    std::string q_text;
    std::string cor_ans;
    std::vector<std::string> alt_ans;
    bool ack = false;
    std::string input;
    //Reading question text. Not escapable.
    while (!ack) {
        std::cout << "Write question text." << std::endl << "Input: ";
        std::getline(in, input);
        ack = question.validate(input);
    }
    q_text = input;
    ack = false;

    //Reading Correct answer. Not escapable.
    while (!ack) {
        std::cout << "Write correct answer." << std::endl << "Input: ";
        std::getline(in, input);
        ack = question.validate(input);
    }
    cor_ans = input;
    ack = false;

    //Reading alt answers. Escapable.
    {
        unsigned int loop = 1;
        input = "";
        std::cout << "Write incorrect alternative No *" << loop << "* or escape with \"/stop\"." << std::endl << "Alt " << loop << ": ";
        while (std::getline(in, input) && input != "/stop") {
            ack = question.validate(input);
            if (ack) {
                alt_ans.push_back(input);
                loop++;
            }
            ack = false;
            std::cout << "Write incorrect alternative No *" << loop << "* or escape with \"/stop\"." << std::endl << "Alt " << loop << ": "; 
        }
    }
    question = Question(q_text, cor_ans, alt_ans);
    return in;
}
//Print question info to file.
std::ofstream &operator<<(std::ofstream &fout, const Question &question) {
    json j(question);
    fout << std::setw(4) << j << std::endl;
    return fout;
}
//Get question info from file.
std::ifstream &operator>>(std::ifstream &fin, Question &question) {
    json j;
    fin >> j;
    from_json(j, question);
    return fin;
}
//Compares questions based on question strings.
bool Question::operator==(const Question &q) const {
    if (this->q_text == q.q_text) return true;
    return false;
}
//Compares question string to string.
bool Question::operator==(const std::string &str) const {
    if (this->q_text == str) return true;
    return false;
}
//Returns question string based comparison.
bool Question::operator<(const Question &q) const {
    if (this->q_text < q.q_text) return true;
    return false;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// JSON PARSING //
//////////////////

void to_json(json &j, const Question &q) {
    j = json{{"q_text", q.q_text}, {"cor_ans", q.cor_ans}, {"alt_ans", q.alt_ans}};
}

void from_json(const json &j, Question &q) {
    j.at("q_text").get_to(q.q_text);
    j.at("cor_ans").get_to(q.cor_ans);
    j.at("alt_ans").get_to(q.alt_ans);
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// HELPERS //
/////////////

//Generates random alternative answers.
void Question::generate_alt() {
#if DEBUG
    if (this->alt_ans.size() < 3) {
        std::cout << "Generating " << 3 - this->alt_ans.size() << " stupid alternatives." << std::endl;
    }
#endif
    //Add random stupid alternatives. (Must have at least 3 alternatives for quiz to work correctly)
    UniqueRng rnd(0, 5);
    while (this->alt_ans.size() < 3) {
        switch (rnd())
        {
        case 0:
            this->alt_ans.push_back("I don't know.");
            break;
        case 1:
            this->alt_ans.push_back("No idea.");
            break;
        case 2:
            this->alt_ans.push_back("...");
            break;
        case 3:
            this->alt_ans.push_back("FREE ME FROM THIS NIGHTMARE.");
            break;
        case 4:
            this->alt_ans.push_back("Somebody messed up!");
            break;
        case 5:
            this->alt_ans.push_back("Give me next question.");
            break;
        default:
            //Note: UniqueRng shouldn't allow to get here.
            std::cout << "What have you done!? (Question::generate_alt())" << std::endl;
            break;
        }
    }
}

//Asks user whether input is correct.
bool Question::validate(const std::string &str) const{
    std::string input;
    std::cout << "Double check:\n\"" << str << "\"\nIs this correct?" << std::endl << "Y/N: ";
    std::getline(std::cin, input);
    for (char &c : input) {
        c = std::toupper(c);
    }
#if RAPID_INPUT
    if ( input == "Y" || input == "YES" || input == "YE" || input == "") return true;
    else return false;
#else
    if ( input == "Y" || input == "YES" || input == "YE" ) return true;
    else return false;
#endif
}