#include "Question.h"

Question::Question(std::string q_text, std::string cor_ans, std::vector<std::string> alt_ans) : q_text(q_text), cor_ans(cor_ans), alt_ans(alt_ans) {
#if DEBUG
    if (this->alt_ans.size() < 3) {
        std::cout << "Generating " << 3 - this->alt_ans.size() << " stupid alternatives." << std::endl;
    }
#endif
    while (this->alt_ans.size() < 3) {
        //Add random stupid alternatives. (We always must have at leas 3 alternatives)
        alt_ans.push_back("I don't know.");
    }
}

/// <summary>
/// Show question with 3 randomly chosen alternative answers (one of them is correct).
/// </summary>
/// <returns>Correct answer position.</returns>
unsigned int Question::show_question() {
    std::vector<std::string> chosen_answers;
    unsigned int pos_corr_ans;
    {
        std::vector<unsigned int> pos_alt_ans;
        UniqueRng r_gen1(0, this->alt_ans.size());
        UniqueRng r_gen2(0, 2);
        
        //Generating random numbers.
        generate(pos_alt_ans.begin(), pos_alt_ans.end(), r_gen1);
        pos_corr_ans = r_gen2();

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
    
    std::cout << *this << std::endl;
    for (unsigned int i = 1; i <= chosen_answers.size(); i++) {
        std::cout << i << ") " << chosen_answers[i - 1] << std::endl;
    }
    return pos_corr_ans;
}
//Prints question text.
std::ostream &operator<<(std::ostream &out, const Question &question) {
    std::cout << question.q_text;
    return out;
}
//Get question from user.
std::istream &operator>>(std::istream &in, const Question &question) {
    //I hate it.
    return in;
}
//Print question info to file.
std::ofstream &operator<<(std::ofstream &fout, const Question &question) {
    // 'question';'cor_ans';'alt_ans'*n\n //encode all inner ";" as "\;"
    // or json
    
    return fout;
}
//Get question info from file.
std::ifstream &operator>>(std::ifstream &fin, const Question &question) {
    // 'question';'cor_ans';'alt_ans'*n\n //decode all inner "\;" as ";"
    // or json

    return fin;
}

