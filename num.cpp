#include<bits/stdc++.h>
using namespace std;
struct digit{
    int val=0;
    digit *prev=NULL,*next=NULL;
};

class num{
public:
    digit *head=NULL;
    digit *tail=NULL;
    num(string str){
        auto ll = getll(str,0,NULL);
        head = ll.first;
        tail = ll.second;
        printnum();
    }
    void printnum();
    pair<digit*,digit*> getll(string str,int beg,digit* prev){
        if(beg==str.length())   return make_pair((digit*)NULL,(digit*)NULL);
        digit* newdigit = getdigit(str[beg]-'0',prev,NULL);
        auto rest = getll(str,beg+1,newdigit);
        newdigit->next = rest.first;
        return make_pair(newdigit,((beg==str.length()-1)?newdigit:rest.second));
    }
    digit* getdigit(int val,digit* prev,digit* next){
        digit* ans = new digit;
        ans->val = val;
        ans->prev = prev;
        ans->next = next;
        return ans;
    }
};
void num::printnum(){
    for(digit* ptr = this->head;ptr!=NULL;ptr=ptr->next)
        cout<<ptr->val;
    return;
}

int main(){
    num("4298520");
}
struct digit add(struct digit *n1,struct digit *n2)
{
    struct digit *ansh=NULL,*c,*anst=NULL;
    int d=0;
    while(true)
    {
        c=new(struct digit);
        c->val=n1->val + n2->val+d;
        d=c->val /10;
        c->next=NULL;
        if(ansh!=NULL)
        {
            ansh->next=c;
            c->prev=ansh;
        }
        else
        {
            anst=c;
        }
        ansh=c;
        n1=n1->next;
        n2=n2->next;
        if(n1==NULL||n2==NULL)
        break;
    }
    while(n1!=NULL)
    {
        c=new(struct digit);
        c->val=n1->val+d;
        d=c->val /10;
        c->next=NULL;
        ansh->next=c;
        c->prev=ansh;
        ansh=c;
        n1=n1->next;
    }
    while(n2!=NULL)
    {
        c=new(struct digit);
        c->val=n2->val+d;
        d=c->val /10;
        c->next=NULL;
        ansh->next=c;
        c->prev=ansh;
        ansh=c;
        n2=n2->next;
    }
    return ansh;
}
