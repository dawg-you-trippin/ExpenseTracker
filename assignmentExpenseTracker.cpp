#include <iostream>
#include <string>
using namespace std;

//forward declaration of classes:
class ExpenseName;
class ExpensePrice;
class DateOfPurchase;

//structure of first node:
class SerialNumber{
	public:
		int id;
		ExpenseName* next;
		SerialNumber(int id){
			this->id = id;
			next = NULL;
		}
};

//structure of second node:
class ExpenseName{
	public:
		string expense;
		ExpensePrice* next;
		ExpenseName(string expense){
			this->expense = expense;
			next = NULL;
		}
};

//structure of third node:
class ExpensePrice{
	public:
		int price;
		DateOfPurchase* next;
		ExpensePrice(int price){
			this->price = price;
			next = NULL;
		}
};

//structure of fourth node:
class DateOfPurchase{
	public:
		string date;
		DateOfPurchase(string date){
			this->date = date;
		}
};

//structure of the master list that will hold the heads of all linked lists to be created:
class MasterList{
	public:
		
		SerialNumber* head;
		MasterList* next;
		MasterList(SerialNumber* head){
			this->head = head;
			next = NULL;
		}
};

class LinkedListManager{
	public:
		
		MasterList* head;
		LinkedListManager() : head(NULL){}
		
		void addExpenses(int id, string expense, int price, string date){
			
			//creates new space for four nodes:
			SerialNumber* serialNode = new SerialNumber(id);
			ExpenseName* expenseNode = new ExpenseName(expense);
			ExpensePrice* priceNode = new ExpensePrice(price);
			DateOfPurchase* dateNode = new DateOfPurchase(date);
			
			//links the four nodes:
			serialNode->next = expenseNode;
			expenseNode->next = priceNode;
			priceNode->next = dateNode;
			
			//creates new space for master list:
			MasterList* masterNode = new MasterList(serialNode);
			
			//if head is null, set the four-node-linkedlist to the head of Master list:
			if (head == NULL){
				head = masterNode;
			}
			
			//else, traverse to the last node of the Master list and place the four-node-linkedlist there:
			else{
				MasterList* temp = head;
				while (temp->next != NULL){
					temp = temp->next;
				}
				temp->next = masterNode;
			}
			
			cout<<"Expense added successfully!\n";
		}
		
		void displayLists(){
			
			if (head == NULL){
				cout<<"No expense added yet!\n";
				return;
			}
			
			MasterList* temp = head;
			int count = 1;
			while (temp != NULL){
				SerialNumber* serialNode = temp->head;
				ExpenseName* nameNode = serialNode->next;
				ExpensePrice* priceNode = nameNode->next;
				DateOfPurchase* dateNode = priceNode->next;
				
				cout<<"\n------------------------------";
				cout<<"\nEXPENSE "<<count++<<":\n";
				cout<<"Serial number: "<<serialNode->id<<"\n";
				cout<<"Expense name: "<<nameNode->expense<<"\n";
				cout<<"Expense price: "<<priceNode->price<<"\n";
				cout<<"Date: "<<dateNode->date<<"\n";
				cout<<"------------------------------";

				temp = temp->next;
			}
		}
		
		void generateReport() {
		    if (head == NULL) {
		        cout << "\nNo expenses available to generate report!\n";
		        return;
		    }
		
		    MasterList* temp = head;
		
		    int maxPrice = -1;
		    int minPrice = 1000000000; 
		
		    SerialNumber* maxExpense = NULL;
		    SerialNumber* minExpense = NULL;
		
		    while (temp != NULL) {
		        SerialNumber* serialNode = temp->head;
		        ExpenseName* nameNode = serialNode->next;
		        ExpensePrice* priceNode = nameNode->next;
		
		        if (priceNode->price > maxPrice) {
		            maxPrice = priceNode->price;
		            maxExpense = serialNode;
		        }
		
		        if (priceNode->price < minPrice) {
		            minPrice = priceNode->price;
		            minExpense = serialNode;
		        }
		
		        temp = temp->next;
		    }
		
		    if (maxExpense != NULL) {
		        ExpenseName* nameNode = maxExpense->next;
		        ExpensePrice* priceNode = nameNode->next;
		        DateOfPurchase* dateNode = priceNode->next;
		
		        cout << "\n==============================";
		        cout << "\nMost Expensive Expense:\n";
		        cout << "Serial number: " << maxExpense->id << "\n";
		        cout << "Expense name: " << nameNode->expense << "\n";
		        cout << "Expense price: " << priceNode->price << "\n";
		        cout << "Date: " << dateNode->date << "\n";
		        cout << "==============================\n";
		    }
		
		    if (minExpense != NULL) {
		        ExpenseName* nameNode = minExpense->next;
		        ExpensePrice* priceNode = nameNode->next;
		        DateOfPurchase* dateNode = priceNode->next;
		
		        cout << "\n==============================";
		        cout << "\nLeast Expensive Expense:\n";
		        cout << "Serial number: " << minExpense->id << "\n";
		        cout << "Expense name: " << nameNode->expense << "\n";
		        cout << "Expense price: " << priceNode->price << "\n";
		        cout << "Date: " << dateNode->date << "\n";
		        cout << "==============================\n";
		    }
		}
};

int main(){
	
	LinkedListManager manager;
	int input, id, price;
	string name, date;
	
	while (true) {
        cout << "\nExpense Tracking System\n";
        cout << "1. Add Expense\n";
        cout << "2. View All Expenses\n";
        cout << "3. Generate Report (Most Expensive Item)\n";
        cout << "4. Exit\n";
        cout << "Choose an option: ";
        cin >> input;

        switch (input) {
            case 1:
				cout<<"\n\nEnter serial number of the expense: ";
				cin>>id;
				cout<<"Enter name of the expense: ";
				cin.ignore();
		        getline(cin, name);
				cout<<"Enter price of the expense: ";
				cin>>price;
				cout<<"Enter the date of purchase: ";
				cin.ignore();
		        getline(cin, date);
				
				manager.addExpenses(id, name, price, date);
                break;

            case 2:
                manager.displayLists();
                break;

            case 3:
			    manager.generateReport();
			    break;

            case 4:
                cout << "Exiting...\n";
                return 0;

            default:
                cout << "Invalid option. Try again.\n";
        }
    }
}







