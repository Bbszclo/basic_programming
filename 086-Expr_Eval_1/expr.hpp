#include <string>
#include <iostream>
#include <sstream>
using namespace std;

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