#include "IntegerLinkedList.hpp"


IntegerLinkedList::IntegerLinkedList(): head(nullptr) {}

IntegerLinkedList::IntegerLinkedList(const IntegerLinkedList &rhs) : head(nullptr) {
    copyNodes(rhs.head);    
}

void IntegerLinkedList::copyNodes(IntegerLinkedListNode* currentRHS) {
    while (currentRHS != nullptr) {
        this->appendDigit(currentRHS->data);
        currentRHS = currentRHS->next;
    }
}

void IntegerLinkedList::deallocateNodes() {
    IntegerLinkedListNode* cur= head;
    IntegerLinkedListNode* next;

    while (cur != nullptr) {
        next = cur->next;
        delete cur;
        cur = next;
    }
    head=nullptr;

}


IntegerLinkedList & IntegerLinkedList::operator=(const IntegerLinkedList &rhs) {
    deallocateNodes();
    copyNodes(rhs.head);
    return *this;
}

IntegerLinkedList::IntegerLinkedList(IntegerLinkedList &&rhs): head(rhs.head) {
    rhs.head = nullptr;
}

IntegerLinkedList & IntegerLinkedList::operator=(IntegerLinkedList &&rhs){
    deallocateNodes();
    head = rhs.head;
    rhs.head = nullptr;

    return *this;
}



IntegerLinkedList::~IntegerLinkedList() {
     deallocateNodes();
}

IntegerLinkedList IntegerLinkedList::operator+(const IntegerLinkedList & rhs) {
    IntegerLinkedList cur;
    IntegerLinkedListNode *left = head;
    IntegerLinkedListNode *right = rhs.head;
    int indic = 0;

    while (left||right||indic) {
        int sum=indic+(left?left->data:0) +(right?right->data:0);
        indic = sum/10;
        cur.appendDigit(sum%10);

        if(left) 
        {
            left = left->next;
        }
        if(right) 
        {
            right = right->next;
        }
    }

    return cur;

}


bool IntegerLinkedList::operator==(const IntegerLinkedList& rhs) const {
    IntegerLinkedListNode* comparing=rhs.head;
    IntegerLinkedListNode* cur=this->head;
    while(cur!=nullptr&&comparing!=nullptr)
    {
        if(cur->data!=comparing->data)
        {
            return false;
        }
        cur=cur->next;
        comparing=comparing->next;
    }
    if(cur!=nullptr||comparing!=nullptr)
    {
        return false;
    }
    return  true;
}

bool IntegerLinkedList::operator!=(const IntegerLinkedList& rhs) const {
    return !(IntegerLinkedList::operator==(rhs));
}

IntegerLinkedList IntegerLinkedList::fromString(const std::string& s) {
    IntegerLinkedList cur=IntegerLinkedList();
    for(int i=s.size()-1;i>=0;i--)
    {
        if(isdigit(s[i]))
        {
            cur.appendDigit(s[i]-'0'); 
        }
    }
    return cur;

}

IntegerLinkedList IntegerLinkedList::fromInt(int i) {
    IntegerLinkedList cur=IntegerLinkedList();
    while(i>0)
    {
        cur.appendDigit(i%10);
        i/=10;
    }
    return cur;
}



std::ostream & operator<<(std::ostream & s, const IntegerLinkedList & rhs) {
    std::string ret="";
    IntegerLinkedListNode* cur=rhs.head;
    while(cur!=nullptr)
    {
        ret.insert(0,std::to_string(cur->data));
        cur=cur->next;
    }
    s<<ret;
    return s;
}