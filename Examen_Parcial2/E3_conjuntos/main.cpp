#include <cstdlib>
#include "LinkedList.h"
#include "Pila.h"

using namespace std;
using namespace vcn;

vector<string> &split(const string &s, char delim, vector<string> &elems) {
    stringstream ss(s);
    string item;
    while (getline(ss, item, delim)) 
    {
        elems.push_back(item);
    }
    return elems;
}

vector<string> split(string &s, char delim) {
    vector<string> elems;
    split(s, delim, elems);
    return elems;
}

LinkedList<int> * Union(LinkedList<int> * a, LinkedList<int> * b) {
    LinkedList<int> * temp = new LinkedList<int>();
    for (int i = 0; i < a->size(); ++i)
        temp->insertBack(a->at(i)->getInfo());
    for (int j = 0; j < b->size(); ++j) {
        bool esta = false;
        for (int k = 0; k < a->size(); ++k) {
            if (a->at(k)->getInfo() == b->at(j)->getInfo())
                esta = true;
        }
        if (!esta)
            temp->insertBack((b->at(j)->getInfo()));
    }

    return temp;
}

LinkedList<int> * Intersection(LinkedList<int> * a, LinkedList<int> * b) {
    LinkedList<int> * temp = new LinkedList<int>();
    for (int i = 0; i < a->size(); ++i)
        for (int j = 0; j < b->size(); ++j)
            if (a->at(i)->getInfo() == b->at(j)->getInfo())
                temp->insertBack(a->at(i)->getInfo());

    return temp;
}

LinkedList<int> * Product(LinkedList<int> * a, LinkedList<int> * b) {
    LinkedList<int> * temp = new LinkedList<int>();
    for (int i = 0; i < a->size(); ++i)
        for (int j = 0; j < b->size(); ++j)
            temp->insertBack(a->at(i)->getInfo() * b->at(j)->getInfo());

    return temp;
}

LinkedList<int> * Substraction(LinkedList<int> * a, LinkedList<int> * b) {
    LinkedList<int> * temp = new LinkedList<int>();
    for (int i = 0; i < a->size(); ++i) {
        bool esta = false;
        for (int j = 0; j < b->size(); ++j) {
            if (a->at(i)->getInfo() == b->at(j)->getInfo()) {
                esta = true;
                break;
            }
        }
        if (!esta)
            temp->insertBack(a->at(i)->getInfo());
    }
}

bool isMathInitialDelimiter(char c){
    switch (c) {
        case '(':
            return true;
            break;
        case '{':
            return true;
            break;
        case '[':
            return true;
            break;
        default:
            return false;
            break;
    }
}

bool isMathFinalDelimiter(char c){
    switch (c) {
        case ')':
            return true;
            break;
        case '}':
            return true;
            break;
        case ']':
            return true;
            break;
        default:
            return false;
            break;
    }
}

char closerForOpener(char c){
    switch (c) {
        case '(':
            return ')';
            break;
        case '{':
            return '}';
            break;
        case '[':
            return ']';
            break;
        default:
            return ')';
            break;
    }
}

bool isSet(string expression){
    const char * asdf = expression.c_str();
    return asdf[0]=='{' && asdf[expression.length()-1]=='}';
}

LinkedList<int> * setFromExpression(string expression){
    vector<string> numbers = split(expression, ',');
    LinkedList<int> * set = new LinkedList<int>();
    for (int i = 0; i < numbers.size(); ++i) {
        if (i==0) {
            int num = atoi(split(numbers[0], '{')[1].c_str());
            set->insertFront(num);
        }
        else if (i==numbers.size()-1){
            int num = atoi(split(numbers[i], '}')[0].c_str());
            set->insertFront(num);
        }
        else{
            int num = atoi(numbers[i].c_str());
            set->insertFront(num);
        }
    }
    return set;
}

LinkedList<int> * parseExpression(std::string expression){
    if (isSet(expression)) {
        return setFromExpression(expression);
    }
    else{
        const char * charMathEquation = expression.c_str();
        vector<std::string> subExpressions;
        string subExpression = "";
        for (int i = 0; i < expression.length(); ++i) {
            char currentChar = charMathEquation[i];
            if (isMathInitialDelimiter(currentChar)) {
            }
            else if (isMathFinalDelimiter(currentChar)){

            }
        }
    }
}

int main(int argc, const char * argv[]) {
    std::string expression = Helper::read<std::string>("Enter an expresssion:");
    std::vector<std::string> splitplus = split(expression, '+');
    for (int i = 0; i < splitplus.size(); ++i) {
        Helper::print(splitplus[i]);
    }
    return 0;
}