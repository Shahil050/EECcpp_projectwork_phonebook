#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
using namespace std;

struct node{
    string name;
    long long int phone_number;
    node *next;
    node *prev;
};
class contactBook{
    private:
        node *head;
        string x;
        long long int y;

    public:
        contactBook();
        void createNode();
        void display();
        int search();
        void DeleteAllContacts();
        int DeleteContactBySearching();
        void BubbleSort();
        int EditContacts();
        void OfLineSave();
        void reopenCB();
        void structure();

};
contactBook::contactBook(){
    head=NULL;
    x=""; // null string showing
    y=0;
}
void contactBook::createNode(){
    if(head==NULL){
        node *newer =new node;
        cout<<" Name of contact: ";
        cin>>x;
        newer->name=x;

        cout<<" Phone number: ";
        cin>>y;
        newer->phone_number=y;

        newer->next=NULL;
        newer->prev==NULL;
        head=newer;

        cout<<" Contact Added"<<endl;
    }
    else{
        node *newer=new node;
        cout<<" Name of contact: ";
        cin>>x;

        cout<<" Phone number: ";
        cin>>y;
        newer->phone_number=y;

        newer->next=NULL;
        
        node*temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=newer;
        newer->prev=temp;
        cout<<" Contact Added "<<endl;
    }
}
void contactBook::display(){
    node *temp=head;
    int count =0;
    if(temp==NULL){
        cout<<" No Contacts.....Please Add Some Contacts"<<endl;
        cout<<" Thanks "<<endl;
    }
    else{
        BubbleSort();
        cout<<" Name: "<<"        Number: \n"<<endl;
        while(temp!=NULL){
            count++;
            cout<<"   "<<temp->name;
            cout<<"      "<<temp->phone_number<<endl;
            temp=temp->next;
        }
    }
}
int contactBook::search(){
    bool check=false;
    node *temp=head;
    cout<<"***********************"<<endl;
    cout<<"   Press 1 If You Want To Search By Name"<<endl;
    cout<<"   Press 2 If You Want To Search By Number"<<endl;
    int choice;
    cout<<"   Enter Your Choice:";
    cin>>choice;

    if(choice==1 && temp!=NULL){
        cout<<"   Enter the Name to Search: ";
        cin>>x;
        while(temp!=NULL){
            if(temp->name==x){
                cout<<"******************************"<<endl;
                cout<<"   Name:           "<<temp->name<<endl;
                cout<<"   Phone Number:   "<<temp->phone_number<<endl;
                cout<<"******************************"<<endl;
                check=true;
                break;
            }
            temp=temp->next;
        }
        if(check==false){
            cout<<"    Name Not Found"<<endl;

        }
    }
    else if(choice==2){
        cout<<"Enter the Number to Search:";
        cin>>y;
        while(temp!=NULL){
            if(temp->phone_number==y){
                cout<<"******************************"<<endl;
                cout<<"   Name:           "<<temp->name<<endl;
                cout<<"   Phone Number:   "<<temp->phone_number<<endl;
                cout<<"******************************"<<endl;
                check=true;
                break;
            }
            temp=temp->next;
        }
        if(check==false){
            cout<<"    Phone Number Not Found"<<endl;

        }

    }

}

void contactBook::DeleteAllContacts(){
    node *temp=head;
    node *temp1;
    if(head==NULL){
        cout<<" Contact list is empty"<<endl;
        cout<<"***********************"<<endl;
    }else{
        while(temp!=NULL){
            temp1=temp;
            temp=temp->next;
            delete temp1;
        }
        head=NULL;
        cout<<"Sucessfully Deleted All Contacts From Contact List"<<endl;
        cout<<"***************************************************"<<endl;

    }
}
int contactBook::DeleteContactBySearching(){
    node *temp=head;
    cout<<"*************************"<<endl;
    cout<<" Press 1 If You Want To Search By Name:"<<endl;
    cout<<" Press 2 If You Want To Search By Number:"<<endl;
    int choice;
    cout<<" Ebter the choice:";
    cin>>choice;
    if(choice ==-1){
        bool Dcheck=false;
        cout<<" Enter the Name to Delete: ";
        cin>>x;
        while(temp->name==x){
                if(temp->name==x){
                cout<<"********************"<<endl;
                cout<<" Name: "<<temp->name<<endl;
                cout<<" Phone number: "<<temp->phone_number<<endl;
                cout<<"**********************"<<endl;
                Dcheck=true;
                break;
            }
            temp=temp->next;
        }
        
        if(Dcheck==true){
            int choice;
            cout<<" Press 1 to Delete The Contact: ";
            cin>>choice;
            if(choice==1 && temp==head){
                node *temp1;
                temp1=temp;
                temp=temp->next;
                delete temp1;

                temp->prev=NULL;
                head=temp;
                cout<<" Contact Deleted Successfully"<<endl;
            }
            else if(choice==1&& temp->next==NULL){
                temp->prev->next=NULL;
                delete temp;
                cout<<" Contact Deleted Successfully"<<endl;

            }
            else if(choice==1){
                node *temp1;
                temp1=temp;
                temp->prev->next=temp1->next;
                temp->next->prev=temp1->prev;
                delete temp;
                cout<<"Contact Deleted Sucessfully"<<endl;

            }
            else{
                cout<<" You Entered Wrong Choice  .... Please Try Again"<<endl;

            }
        }
        
        else if(Dcheck == false){
            cout<<"Contact Of This Name Not Found"<<endl;
        }
    }
    else{
        cout<<"You Have Enter Wrong Choice"<<endl;
    }
}
void contactBook::BubbleSort(){
    node *temp=head;
    node *i,*j;
    string n;
    long long int n2;
    if(temp==NULL){
        cout<<"Empty contact Book"<<endl;
    }
    else{
        for(i=head;i->next!=NULL;i=i->next){
            for(j=i->next;j!=NULL;j=j->next){
                if(i->name>j->name){
                    n=i->name;
                    i->name=j->name;
                    j->name=n;

                    n2=i->phone_number;
                    i->phone_number=j->phone_number;
                    j->phone_number=n2;  
                }
            }
        }
    }
}
int contactBook::EditContacts(){
    node *temp=head;
    cout<<"**********************"<<endl;
    cout<<" Press 1 If You Want To Search By Name"<<endl;
    cout<<" Press 2 If You Want To Search By Number "<<endl;
    int Echoice;
    cout<<" Enter Your Choice:";
    cin>>Echoice;

    if(Echoice==1){
        bool Echoice=false;
        cout<<"Enter the Name to Edit: ";
        cin>>x;
        while(temp!=NULL){
            if(temp->name==x){
                cout<<"****************"<<endl;
                cout<<"Name: "<<temp->name<<endl;
                cout<<"Phone Number: "<<temp->phone_number<<endl;
                cout<<"******************"<<endl;
                Echoice=true;
                break;
            }
            temp=temp->next;
        }
        if(Echoice==true){
            int choice;
            cout<<" Press 1 to Edit The Contact:";
            cin>>choice;
            if(choice==1){
                cout<<"Enter The New Name: ";
                cin>>x;
                cout<<" Enter New Number: ";
                cin>>y;

                temp->name=x;
                temp->phone_number=y;
                cout<<" Contact Edited Successfully"<<endl;

            }
            else{
                cout<<"You Enter Wrong Command .... Try Again"<<endl;

            }

        }
        else if(Echoice==false){
            cout<<"Contact Not Found"<<endl;
        }
        else if(Echoice==2){
            bool Echoice=false;
            cout<<"Enter the Number to Edit: ";
            cin>>y;
            while(temp!=NULL){
                if(temp->phone_number==y){
                    cout<<"****************"<<endl;
                    cout<<"Name: "<<temp->name<<endl;
                    cout<<"Phone Number: "<<temp->phone_number<<endl;
                    cout<<"*******************"<<endl;
                    Echoice=true;
                    break;
                }
                temp=temp->next;
            }
            if(Echoice==true){
                int choice;
                cout<<" Press 1 to Edit The Contact:";
                cin>>choice;
                if(choice==1){
                    cout<<" Enter New Name: ";
                    cin>>x;
                    cout<<"Enter New Number: ";
                    cin>>y;

                    temp->name=x;
                    temp->phone_number=y;

                    cout<<"Contact Edited Successfully"<<endl;

                }
                else{
                    cout<<" You Enter Wrong Choice:"<<endl;

                }

            }
            else if(Echoice==false){
                cout<<"There is No Contact Of This Number"<<endl;

            }
        }
        else{
            cout<<"You Have Entered Wrong Choice.   .... Please Try Again!"<<endl;

        }

    }
    

}
void contactBook::OfLineSave(){
    node *temp=head;
    ofstream myfile("Contact_Book.txt");
    if(myfile.is_open()){
        while(temp!=NULL){
            myfile<<temp->name<<endl;
            myfile<<temp->phone_number<<endl;
            temp=temp->next;
        }
        myfile.close();
        structure();

    }
    else{
        cout<<"Thanks file is Empty."<<endl;
    }
}
void contactBook::reopenCB(){
    bool isEmpty;
    ifstream myfile("Contact_Book.txt");
    if(myfile.is_open() && myfile.peek() != EOF){
        int i=0;
        while(getline(myfile,x)){
            if(i%2==0){
                if(head==NULL){
                    node *newer=new node;
                    newer->name=x;

                    newer->next=NULL;
                    newer->prev==NULL;
                    head=newer;
                }
                else{
                    node *newer=new node;
                    newer->name=x;
                    newer->next!=NULL;

                    node *temp=head;
                    while(temp->next!=NULL){
                        temp=temp->next;

                    }
                    temp->next=newer;
                    newer->prev=temp;
                }
            }
            else{
                node *temp=head;
                if(temp->phone_number==0){
                    stringstream convert(x);
                    convert>>y;
                    temp->phone_number=y;
                }
                else{
                    node *temp=head;
                    while(temp->next!=NULL){
                        temp=temp->next;
                    }
                    stringstream convert(x);
                    convert>>y;
                    temp->phone_number=y;
                }
            }
            i++;
        }
        myfile.close();
    }else{
        cout<<"File is Empty So Cannot Open ..... Sorry"<<endl;

    }
}
void contactBook::structure(){
    cout<<"***********************************"<<endl;
    cout<<" 1. Add Contact"<<endl;
    cout<<" 2. Edit the Contact"<<endl;
    cout<<" 3. Delete Contact"<<endl;
    cout<<" 4. Search Contact"<<endl;
    cout<<" 5. Display All Contacts"<<endl;
    cout<<" 6. Delete All Contacts"<<endl<<endl;

    int Schoice;
    cout<<" Enter your choice: ";
    cin>>Schoice;
    try{
        if(Schoice>=1 && Schoice<=6){
            if(Schoice==1){
                createNode();
                OfLineSave();
                structure();
            }
            else if(Schoice==2){
                EditContacts();
                OfLineSave();
                structure();

            }
            else if(Schoice==3){
                DeleteContactBySearching();
                structure();
            }
            else if(Schoice==4){
                search();
                structure();
            }
            else if(Schoice==5){
                display();
                OfLineSave();
                structure();
            }
            else if(Schoice==6){
                DeleteAllContacts();
                OfLineSave();
                structure();
            }
        }
        else{
            throw(Schoice);
        }
    }
    catch(int Schoice){
         cout<<" You Enter Wrong Command ... Run the code again"<<endl;
         structure();
    }
}
int main(){
    contactBook cb;
    cb.reopenCB();
    string n;
    cout<<"What is Your Name: ";
    cin>>n;

    cout<<"************************"<<endl;
    cout<<" "<<n<<" WELCOME TO CONTACTBOOK "<<endl;
    cb.structure();
    return 0;
}