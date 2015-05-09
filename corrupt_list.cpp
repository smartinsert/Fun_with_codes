#include <iostream>

using namespace std;

typedef struct node{
    int data;
    node *next;
}node;

node* init(int a[], int n, int m){
    node *head, *p, *q;
    for(int i=0; i<n; ++i){
        node *nd = new node();
        nd->data = a[i];
        if(i==m) q = nd;
        if(i==0){
            head = p = nd;
            continue;
        }
        p->next = nd;
        p = nd;
    }
    p->next = q;
    return head;
}

node* loopstart(node *head){
    if(head==NULL) return NULL;
    node *current = head, *prev = head;
    while(current && current->next){
        current = current->next->next;
        prev = prev->next;
        if(current==prev) break;
    }
    if(!current || !current->next) return NULL;
    prev = head;
    while(current!=prev){
        current = current->next;
        prev = prev->next;
    }
    return current;
}

/*
void print(node* head)
{
 node* temp = head;
 if (temp == NULL)
 {
        cout << "Empty List" << endl;
        return;
 }
 while(temp)
 {
        cout << temp->data;
        if (temp->next == NULL)
                cout << endl;
        else
                cout << "->";
        temp = temp->next;
 }

}
*/
int main(){
    int n = 10, m = 9;// m<n
    int a[] = {
        3, 2, 1, 3, 5, 6, 2, 6, 3, 7 
    };
    node *head = init(a, n, m);
//    print(head);
    node *p = loopstart(head);
    if(p)
        cout<<p->data<<endl;
    return 0;
}
