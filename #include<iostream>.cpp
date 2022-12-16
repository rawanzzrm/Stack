#include<iostream>

using namespace std;

class node{
    public:
        int data;
        node* next;
};

class Linked_List{
public:
    
    node* head;
    
    Linked_List(){

        head = NULL;
    }

    void insertinfirst(int newvalue){

        if(isempety() == true){

            node* newnode = new node();
            newnode -> data = newvalue;
            newnode -> next = NULL;
            head = newnode;
        }
        else{

            node* newnode = new node();
            newnode -> data = newvalue;
            newnode -> next = head;
            head = newnode;
        }

    }

    void insertbefore(int item , int newvalue){
       
        if(isfound(item) == true){
            
            node* newnode = new node();
            newnode -> data = newvalue;

            node* temp = head;

            while(temp != NULL && temp -> next -> data != item){
                
                temp = temp -> next;  
            }
            
            newnode -> next = temp -> next;
            temp -> next = newnode;
        }
        else
            cout << "item is not found"<< endl;
    }

    void insertinend(int newvalue){
      
        if(isempety()){
            insertinfirst(newvalue);
        }
        else{
            node* temp;
            temp = head;
            while(temp -> next != NULL){
                temp = temp -> next;
            }
            node* newnode = new node();
            newnode -> data = newvalue;
            temp -> next = newnode;
            newnode -> next = NULL;
        }
    }

    void remove(int item){
        
        if(isempety() == true)
            cout<<"empety";
        else{
            if(head -> data == item){
                node* del = head;
                head = head -> next;
                delete del;
            }
            else{
                node* del = head;
                node* prev = NULL;

                while(del -> data != item){
                    
                    prev = del;
                    del = del -> next;
                }
                prev -> next = del ->next;
                delete del;
            }
        }
    }
    void display(){
        
        node* temp = head;
        while(temp != NULL){
            cout << temp -> data << endl;
            temp = temp -> next;
        }
    }

    bool isfound(int key){
       
        node* temp; 
        temp = head;
        
        bool found = false;
        
        while(temp != NULL){
          
            if(temp->data == key)
                found = true;
            temp = temp->next;
        }
        return found;
    }
    bool isempety(){
        return (head == NULL);
    }
};

int main(){

    Linked_List list;
    
    char c;
    cout<<"----------------------------\n";
    do{
        cout<<"1) insert in first\n2) insert before item\n3) insert in end\n4) remove\n5) display\n";
        cin >> c;

        switch(c){
            case '1' :
                int x;
                cout<<"enter element : ";
                cin >> x;
                list.insertinfirst(x);
                break;
            case '2' :
                int y;
                cout<<"enter before item : ";
                cin>>x;
                cout<<"enter element : ";
                cin>>y;
                list.insertbefore(x,y);
                break;
            case '3' :
                cout<<"enter element : ";
                cin>>x;
                list.insertinend(x);
                break;
            case '4' :
                cout<<"enter element : ";
                cin>>x;
                list.remove(x);
            case '5' : 
                list.display();
            default :
                break;
        }

    }while(c != '0');

}