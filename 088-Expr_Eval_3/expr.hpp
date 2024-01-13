#include <string>
#include <iostream>
#include <sstream>
using namespace std;
//For this part, declare this abstract method in Expression:
//long evaluate() const = 0;
//and implement it in each concrete subclass of Expression.

class Expression{
    public:
        virtual string toString() const = 0;  
        virtual long evaluate() const = 0; //adding this
        virtual ~Expression() {}
    };

class NumExpression : public Expression{
    long num;
    public:
        NumExpression(long n): num(n) {} 
        virtual string toString() const{
        stringstream sstream;
        sstream<<num;
        return sstream.str();
        }
    virtual long evaluate() const { return num; } //here as well
    virtual ~NumExpression() {}
};

class OpExpression : public Expression {
    private:	
        const char *op; 
        Expression *lhs;
        Expression *rhs;

    public:
        OpExpression(const char *op, Expression *lhs, Expression *rhs) : 
        op(op), 
        lhs(lhs), 
        rhs(rhs) {}
        virtual string toString() const {
            stringstream sstream;
            sstream << "(" << lhs->toString() << " " << op << " " << rhs->toString() << ")";
            return sstream.str();
        }
        virtual long evaluate() const {
            switch (*op) { //when during with one variable, using switch is easier than 'if'
                case '+':
                    return lhs->evaluate() + rhs->evaluate();
                case '-':
                    return lhs->evaluate() - rhs->evaluate();
                case '*':
                    return lhs->evaluate() * rhs->evaluate();
                case '/':
                    return lhs->evaluate() / rhs->evaluate();
                default:
                    cerr << "operation charactor incorrect." << endl;
                    abort();
            }
        }
        virtual ~OpExpression() {
            //desturctor
            delete lhs;
            delete rhs;
        }
};

class PlusExpression : public OpExpression{
    public:
        PlusExpression(Expression * lhs, Expression * rhs): OpExpression("+",lhs,rhs){}
};

class MinusExpression : public OpExpression {
    public:
        MinusExpression(Expression * lhs, Expression * rhs) : OpExpression("-", lhs, rhs) {} //just similar to plus
};

class TimesExpression : public OpExpression {
    public:
        TimesExpression(Expression * lhs, Expression * rhs) : OpExpression("*", lhs, rhs) {} //just similar to plus
};

class DivExpression : public OpExpression {
    public:
        DivExpression(Expression * lhs, Expression * rhs) : OpExpression("/", lhs, rhs) {} //just similar to plus
};