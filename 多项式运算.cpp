#include <iostream>
using namespace std;

struct polyment{
    float coefficient;
    int exponent;
    polyment *next;
    polyment(float cf=0,int exp=0,polyment *nt=NULL):coefficient(cf),exponent(exp),next(nt){}
    ~polyment(){}
};
polyment *add(polyment *poly_head1,polyment *poly_head2){
    polyment *head,*p;
    polyment *p1=poly_head1, *p2=poly_head2;
    if(p1==NULL||p2==NULL){
        head = p1 == NULL ? p2 : p1;
        return head;
    }
    if(p1->exponent>p2->exponent){
        head = new polyment(p1->coefficient,p1->exponent,NULL);
        p = head;
        p1 = p1->next;
        while (p1 != NULL){
            p = p->next = new polyment(p1->coefficient, p1->exponent, NULL);
            p1 = p1->next;
        }
        p = head;
        while(p2!=NULL){
            while (p->next != NULL && p2->exponent < p->exponent){
                polyment *q = p;
                p = p->next;
                if (p->exponent == p2->exponent){
                    p->coefficient += p2->coefficient;
                    break;
                }
                else if(p->exponent<p2->exponent){
                    q->next = new polyment(p2->coefficient,p2->exponent,p);
                    break;
                }
            }
            if(p->next==NULL&&p2->exponent<p->exponent){
                p->next = p2;
                return head;
            }
            p2 = p2->next;
        }
    }
    else{
        head = new polyment(p2->coefficient, p2->exponent, NULL);
        p = head;
        p2 = p2->next;
        while (p2 != NULL){
            p = p->next = new polyment(p2->coefficient, p2->exponent, NULL);
            p2 = p2->next;
        }
        p = head;
        while (p1 != NULL){
            while (p->next != NULL && p1->exponent < p->exponent){
                polyment *q = p;
                p = p->next;
                if (p->exponent == p1->exponent){
                    p->coefficient += p1->coefficient;
                    break;
                }
                else if (p->exponent < p1->exponent){
                    q->next = new polyment(p1->coefficient, p1->exponent, p);
                    break;
                }
            }
            if (p->next == NULL && p1->exponent < p->exponent){
                p->next = p1;
                return head;
            }
            p1 = p1->next;
        }
    }
    return head;
    /*if(p1->exponent==p2->exponent){
        head = new polyment(p1->coefficient+p2->coefficient,p1->exponent,NULL);
        p = head;
        p1 = p1->next;
        p2 = p2->next;
        if(p1==NULL||p2==NULL){
            p->next = p1 == NULL ? p2 : p1;
            return head;
        }
    }
    else if(p1->exponent>p2->exponent){
        head = new polyment(p1->coefficient,p1->exponent,NULL);
        p = head;
        p1 = p1->next;
        if(p1==NULL){
            p->next = p2;
            return head;
        }
    }
    else{
        head = new polyment(p2->coefficient, p2->exponent, NULL);
        p2 = p2->next;
        if(p2==NULL){
            p->next = p1;
            return head;
        }
    }
    while(p1!=NULL||p2!=NULL){
        if(p1->exponent==p2->exponent){
            p=p->next = new polyment(p1->coefficient + p2->coefficient, p1->exponent, NULL);
            p1 = p1->next;
            p2 = p2->next;
            if (p1 == NULL || p2 == NULL){
                p->next = p1 == NULL ? p2 : p1;
                return head;
            }
        }
        else if (p1->exponent > p2->exponent){
            p=p->next = new polyment(p1->coefficient, p1->exponent, NULL);
            p1 = p1->next;
            if (p1 == NULL){
                p->next = p2;
                return head;
            }
        }
        else{
            p=p->next = new polyment(p2->coefficient, p2->exponent, NULL);
            p2 = p2->next;
            if (p2 == NULL){
                p->next = p1;
                return head;
            }
        }
    }
    while(p1!=NULL){
        p=p->next = new polyment(p1->coefficient, p1->exponent, NULL);
        p1 = p1->next;
    }
    while(p2!= NULL){
        p=p->next = new polyment(p2->coefficient, p2->exponent, NULL);
        p2 = p2->next;
    }
    return head;*/
}
polyment *multiply(polyment *poly_head1,polyment *poly_head2){
    polyment *head,*p;
    polyment *p1 = poly_head1, *p2 = poly_head2;
    head = new polyment(p1->coefficient * p2->coefficient, p1->exponent + p2->exponent, NULL);
    p2 = p2->next;
    p = head;
    float coff;
    int exp;
    while(p1!=NULL){
        while(p2!=NULL){
            coff = p1->coefficient * p2->coefficient;
            exp = p1->exponent + p2->exponent;
            while(exp<p->exponent&&p->next!=NULL){
                polyment *q=p;
                p = p->next;
                if(p->exponent==exp){
                    p->coefficient += coff;
                    break;
                }
                else if(p->exponent<exp){
                    q->next = new polyment(coff,exp,p);
                    break;
                }
            }
            if (exp < p->exponent && p->next == NULL){
                p=p->next = new polyment(coff,exp,NULL);
            }
            p = head;
            p2=p2->next;
        }
        p2 = poly_head2;
        p1 = p1 -> next;
    }
    return head;
}
int main(){
    polyment *head1, *head2;
    char comma;
    float number1;
    int  number2;
    std::cin >> number1 >> comma >> number2;
    head1 = new polyment(number1,number2,NULL);
    polyment *p=head1;
    while(true){
      if (cin.get() == '\n')
        break;
      std::cin >> number1 >> comma >> number2;
      p = p->next = new polyment(number1, number2, NULL);
    }
    std::cin >> number1 >> comma >> number2;
    head2 = new polyment(number1, number2, NULL);
    polyment *q = head2;
    while (true){
        if (cin.get() == '\n')
            break;
        std::cin >> number1 >> comma >> number2;
        q=q->next = new polyment(number1, number2, NULL);
    }
    polyment *polyment1, *polyment2;
    char op;
    std::cout << "Please input add(a) or mutiply(m):";
    std::cin >> op;
    if (op=='a'){
        polyment1 = add(head1, head2);
        while (polyment1 != NULL)
        {
            std::cout << polyment1->coefficient << "," << polyment1->exponent<<" ";
            polyment1 = polyment1->next;
        }
        std::cout << std::endl;
    }
    if(op=='m'){
        polyment2 = multiply(head1, head2);
        while (polyment2 != NULL)
        {
            std::cout << polyment2->coefficient << "," << polyment2->exponent<<" ";
            polyment2 = polyment2->next;
        }
        std::cout << std::endl;
    }
    std::system("pause");
    return 0;
}