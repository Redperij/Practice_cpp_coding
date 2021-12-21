#include "Question.h"

Question::Question(std::string q_text, std::string cor_ans) : q_text(q_text), cor_ans(cor_ans) {}

std::ostream &operator<<(std::ostream &out, const Question &question) {
    
    return out;
}
std::istream &operator>>(std::istream &in, const Question &question) {
    
    return in;
}
std::ofstream &operator<<(std::ofstream &fout, const Question &question) {
    
    return fout;
}
std::ifstream &operator>>(std::ifstream &fin, const Question &question) {
    
    return fin;
}

