#include<iostream>
using namespace std;
class node{
    public:
    int v;
    node *p;
};
node *head = NULL;
void add_start(int x){
    node *n=new node();
    n->v = x;
    
    (*n).p = head;
    head=n;
}
void display(){
    node *temp = head;
    while(temp != NULL){
        cout<< temp->v<<" ";
        temp = temp->p;
    }
    cout<<endl;
}
void insert(int x,int y){
    node *p1 = new node();
    p1->v = x;
    node *temp=head;
    for(int i=1;i<y;i++){
        temp = temp->p;
    }
    p1->p = temp->p;
    temp->p = p1;
}
void del(int n){
    node *temp=head;
    for(int i=0;i<n-1;i++){
        temp=temp->p;
    }
    node *temp2=head;
    for(int i=0;i<n-2;i++){
        temp2=temp2->p;
    }
    temp2->p = temp->p;
    delete(temp);

}
void reverse(){
    node * x,*y,*z;
    x= NULL;
    y= head;
    while(y!= NULL){
        z = y->p;
        y->p=x;
        x=y;
        y=z;
        
        }
    head = x;

}
void reverse_rec(node *h){
    //node *p1 = head;
    if(h->p == NULL){
        head = h;
        return;
    }
    reverse_rec(h->p);
    (h->p)->p = h;
    h->p= NULL;
}
int main(){
    add_start(1);
    add_start(3);
    add_start(6);
    add_start(2);
    display();
    insert(5,3);
    add_start(10);
    display();
    del(3);
    display();
    reverse();
    display();
    reverse_rec(head);
    display();

    return 0;
} 
