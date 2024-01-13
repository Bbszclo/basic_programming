#include <string>
#include <iostream>
#include <sstream>
using namespace std;
//Each of these three classes needs a constructor that takes two Expression 
//*s (one for the left operand and one for the right operand), and they each need a toString() method.
//You may want to declare some instance variables or even create a new parent class to remove some repeated code.

class Expression{
    public:
        virtual string toString() const = 0;  
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