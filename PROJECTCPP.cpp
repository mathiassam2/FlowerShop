#include <iostream>
#define SIZE 10
using namespace std;

//prototype
void clear();
void error();
//class Queue;


/*
classes
-display-done
-inventory-ongoing(need to add current stock available). this does not include new upcoming stock
-queue(upcoming new stock) need to be transfered to main inventory - ongoing, (remove new stock)-ongoing
-search-not availble 
-sorting-not available
*/

typedef struct package{
	string type; // type of package
	float price; // price for each package
	int quantity; // number of package left in inventory
	int id; //id of the inventory
	
}package;

class Inventory{
	public:
		
		package *birthday = new package[SIZE];
		package *graduation = new package[SIZE];
		package *anniversary = new package[SIZE];
		package *condolence = new package[SIZE];
		
		bool emptyB, emptyG, emptyA, emptyC;
		
		int bID = 0;
		int gID = 0;
		int aID = 0;
		int cID = 0;
		
		//-----------------------------------------------PRESET DATA----------------------------------------------------
		Inventory(){
			//BIRTHDAY
			birthday[0].type = "Birthday - Best Friend";
			birthday[0].price = 25;
			birthday[0].quantity = 20;
			birthday[0].id = bID++;
			
			birthday[1].type = "Bithday - Sweetheart";
			birthday[1].price = 30;
			birthday[1].quantity = 80;
			birthday[1].id = bID++;
			
			emptyB = false;
			
			//GRADUATION
			graduation[0].type = "Graduation - Congratulations";
			graduation[0].price = 25;
			graduation[0].quantity = 50;
			graduation[0].id = gID++;
			
			graduation[1].type = "Graduation - Hope you have a job";
			graduation[1].price = 50;
			graduation[1].quantity = 30;
			graduation[1].id = gID++;
			
			emptyG = false;
			
			//ANNIVERSARY
			anniversary[0].type = "Anniversary - 99 Rosses";
			anniversary[0].price = 250;
			anniversary[0].quantity = 2;
			anniversary[0].id = aID++;
			
			anniversary[1].type = "Anniversary - Golden Anniversary";
			anniversary[1].price = 50;
			anniversary[1].quantity = 4;
			anniversary[1].id = aID++;
			
			anniversary[2].type = "Anniversary - Wedding Anniversary";
			anniversary[2].price = 40;
			anniversary[2].quantity = 45;
			anniversary[2].id = aID++;
			
			emptyA = false;
			
			//CONDOLENCE
			condolence[0].type = "Condolence - Round Set A";
			condolence[0].price = 100;
			condolence[0].quantity = 6;
			condolence[0].id = cID++;
			
			condolence[1].type = "Condolence - Standard";
			condolence[1].price = 80;
			condolence[1].quantity = 15;
			condolence[1].id = cID++;
			
			emptyC = false;
		}
		
		//*************************************CURRENT STOCK IN INVENTORY***************************************
		void currentStock(){
			
		}
		
		
		
		void displayBirthday(){
			cout << "*****************ALL BIRTHDAY PACKAGES*****************" << endl;
			noDetailsBirthday();
			
			
			
			if (!emptyB){
				for (int i = 0; i < SIZE; i++){
					if (birthday[i].type.empty()){
						break;
					}
					cout << "Bouquet ID: B" << birthday[i].id << endl;
					cout << "Flower Bouquet: " << birthday[i].type << endl;
					cout << "Price:RM " << birthday[i].price << endl;
					cout << "Quantity: " << birthday[i].quantity << "\n" << endl;
				}
			}
		}
		
		void displayGraduation(){
			cout << "*****************ALL GRADUATION PACKAGES*****************" << endl;
			noDetailsGraduation();
			if (!emptyG){
				for (int i = 0; i < SIZE; i++){
					if (graduation[i].type.empty()){
						break;
					}
					cout << "Bouquet ID: G" << graduation[i].id << endl;
					cout << "Flower Bouquet: " << graduation[i].type << endl;
					cout << "Price:RM " << graduation[i].price << endl;
					cout << "Quantity: " << graduation[i].quantity << "\n" << endl;
				}
			}
		}
		
		void displayAnniversary(){
			cout << "*****************ALL ANNIVERSARY PACKAGES*****************" << endl;
			noDetailsAnniversary();
			if (!emptyA){
				for (int i = 0; i < SIZE; i++){
					if (anniversary[i].type.empty()){
						break;
					}
					cout << "Bouquet ID: A" << anniversary[i].id << endl;
					cout << "Flower Bouquet: " << anniversary[i].type << endl;
					cout << "Price:RM " << anniversary[i].price << endl;
					cout << "Quantity: " << anniversary[i].quantity << "\n" << endl;
				}
			}
		}
		
		void displayCondolence(){
			cout << "*****************ALL CONDOLENCE PACKAGES*****************" << endl;
			noDetailsCondolence();
			if (!emptyC){
				for (int i = 0; i < SIZE; i++){
					if (condolence[i].type.empty()){
						break;
					}
					cout << "Bouquet ID: C" << condolence[i].id << endl;
					cout << "Flower Bouquet: " << condolence[i].type << endl;
					cout << "Price:RM " << condolence[i].price << endl;
					cout << "Quantity: " << condolence[i].quantity << "\n" << endl;
				}
			}
		}
		
		//-------------TO CHECK IF THE INVENTORY IS EMPTY----------------------------
		void noDetailsBirthday(){
			if (birthday[0].type.empty()){
				cout << "Birthday inventory empty\n";
				emptyB = true;
			}
		}
		
		void noDetailsGraduation(){
			if (graduation[0].type.empty()){
				cout << "Birthday inventory empty\n";
				emptyG = true;
			}
		}
		
		void noDetailsAnniversary(){
			if (anniversary[0].type.empty()){
				cout << "Birthday inventory empty\n";
				emptyA = true;
			}
		}
		
		void noDetailsCondolence(){
			if (condolence[0].type.empty()){
				cout << "Birthday inventory empty\n";
				emptyC = true;
			}
		}
		
};

//*********************************EDIT UPCOMING STOCK BEFORE PUTTING IN THE INVENTORY CLASS*****************************ONGOING*****************
//make sure it loops back to the queue class to keep getting new stocks until confirmation to put in the inventory - done
//and able to delete the new stock before putting in main inventory - ongoing
class Queue{
	Inventory qinv;
	
	private:
		package *newBirthday = new package[SIZE];
		package *newGraduation = new package[SIZE];
		package *newAnniversary = new package[SIZE];
		package *newCondolence = new package[SIZE];
		
		// element 0 is for birthday, 1 is for grad and so on
		int rear[4];
		int front[4];
		
		bool full[4];
		bool empty[4];
		
	public:
		Queue(){
			for (int i = 0; i < 4; i++){
				rear[i] = -1;
				front[i] = -1;
				empty[i] = true;
				full[i] = false;
			}
		}
		
		//checking if the queue is empty or not
		void isEmpty(){
			for (int i = 0; i < 4; i++){
				if (front[i] == -1 && rear[i] == -1){
					if (i == 0){
						//cout << "Birthday queue is empty" << endl;
						empty[0] = true;
					}
					if (i == 1){
						//cout << "Graduation queue is empty" << endl;
						empty[1] = true;
					}
					if (i == 2){
						//cout << "Anniversary queue is empty" << endl;
						empty[2] = true;
					}
					if (i == 3){
						//cout << "Condolence queue is empty" << endl;
						empty[3] = true;
					}
				}
			}
		}
		
		//checking if the queue is full or not
		void isFull(){
			for (int i = 0; i < 4; i++){
				if (rear[i] == SIZE-1){
					if (i == 0){
						cout << "Birthday queue is full" << endl;
						full[0] = true;
					}
					if (i == 1){
						cout << "Graduation queue is full" << endl;
						full[1] = true;
					}
					if (i == 2){
						cout << "Anniversary queue is full" << endl;
						full[2] = true;
					}
					if (i == 3){
						cout << "Condolence queue is full" << endl;
						full[3] = true;
					}
				}
			}
		}
		
		//********************************BIRTHDAY QUEUE**********************************
		//[0] - birthday
		void enqueueB(){
			if(full[0]){
				return;
			}
			
			isEmpty();
			if(empty[0]){
				rear[0] = front[0] = 0;
				empty[0] = false;
			}
			else {
				rear[0]++;
			}
			
			cout << "Enter type of package: ";
			fflush(stdin);
			getline(cin, newBirthday[rear[0]].type) ;
			
			cout << "Enter price for " << newBirthday[rear[0]].type << ": ";
			cin >> newBirthday[rear[0]].price;
			
			cout << "Enter quantity: ";
			cin >> newBirthday[rear[0]].quantity;
			
			cout << "Enter ID for " << newBirthday[rear[0]].type << ": ";
			cin >> newBirthday[rear[0]].id;
		}
		
		void enqueueG(){
			if(full[1]){
				return;
			}
			
			isEmpty();
			if(empty[1]){
				rear[1] = front[1] = 0;
				empty[1] = false;
			}
			else {
				rear[1]++;
			}
			
			cout << "Enter type of package: ";
			fflush(stdin);
			getline(cin, newGraduation[rear[1]].type) ;
			
			cout << "Enter price for " << newGraduation[rear[1]].type << ": ";
			cin >> newGraduation[rear[1]].price;
			
			cout << "Enter quantity: ";
			cin >> newGraduation[rear[1]].quantity;
			
			cout << "Enter ID for " << newGraduation[rear[1]].type << ": ";
			cin >> newGraduation[rear[1]].id;
		}
		void enqueueA(){
			if(full[2]){
				return;
			}
			
			isEmpty();
			if(empty[2]){
				rear[2] = front[2] = 0;
				empty[2] = false;
			}
			else {
				rear[0]++;
			}
			
			cout << "Enter type of package: ";
			fflush(stdin);
			getline(cin, newAnniversary[rear[2]].type) ;
			
			cout << "Enter price for " << newAnniversary[rear[2]].type << ": ";
			cin >> newAnniversary[rear[2]].price;
			
			cout << "Enter quantity: ";
			cin >> newAnniversary[rear[2]].quantity;
			
			cout << "Enter ID for " << newAnniversary[rear[2]].type << ": ";
			cin >> newAnniversary[rear[2]].id;
		}
		void enqueueC(){
			if(full[3]){
				return;
			}
			
			isEmpty();
			if(empty[3]){
				rear[3] = front[3] = 0;
				empty[3] = false;
			}
			else {
				rear[3]++;
			}
			
			cout << "Enter type of package: ";
			fflush(stdin);
			getline(cin, newCondolence[rear[3]].type) ;
			
			cout << "Enter price for " << newCondolence[rear[3]].type << ": ";
			cin >> newCondolence[rear[3]].price;
			
			cout << "Enter quantity: ";
			cin >> newCondolence[rear[3]].quantity;
			
			cout << "Enter ID for " << newCondolence[rear[3]].type << ": ";
			cin >> newCondolence[rear[3]].id;
		}
		
		//DISPLAY BIRTHDAY STOCK
		void displayB(){
			for (int i = 0; i < SIZE; i++){
				if (newBirthday[i].type.empty()){
					break;
				}
				cout << endl;
				cout << newBirthday[i].type << endl;
				cout << newBirthday[i].price << endl;
				cout << newBirthday[i].quantity << endl;
				cout << newBirthday[i].id << endl;
			}
		}
		
		//DISPLAY GRADUATION STOCK
		void displayG(){
			for (int i = 0; i < SIZE; i++){
				if (newGraduation[i].type.empty()){
					break;
				}
				cout << endl;
				cout << newGraduation[i].type << endl;
				cout << newGraduation[i].price << endl;
				cout << newGraduation[i].quantity << endl;
				cout << newGraduation[i].id << endl;
			}
		}
		
		//DISPLAY ANNIVERSARY STOCK
		void displayA(){
			for (int i = 0; i < SIZE; i++){
				if (newAnniversary[i].type.empty()){
					break;
				}
				cout << endl;
				cout << newAnniversary[i].type << endl;
				cout << newAnniversary[i].price << endl;
				cout << newAnniversary[i].quantity << endl;
				cout << newAnniversary[i].id << endl;
			}
		}
		
		
		//DISPLAY CONDOLENCE STOCK
		void displayC(){
			for (int i = 0; i < SIZE; i++){
				if (newCondolence[i].type.empty()){
					break;
				}
				cout << endl;
				cout << newCondolence[i].type << endl;
				cout << newCondolence[i].price << endl;
				cout << newCondolence[i].quantity << endl;
				cout << newCondolence[i].id << endl;
			}
		}
		
};

class Display{
	Inventory inv;
	Queue q;
	
	private:
		int displayOption;
		int mode;
		
	public:
		int displayMenu(){
			cout << "1)View Inventory\n2)Edit Inventory\n0)Exit Program\nEnter mode: ";
			cin >> mode;
			return mode;
		}
		
		void view(){
			VIEW:
			cout << "1 - Display all" << endl;
			cout << "2 - Display birthday" << endl;
			cout << "3 - Display graduation" << endl;
			cout << "4 - Display anniversary" << endl;
			cout << "5 - Display condolence" << endl;
			cout << "0 - Select mode" << endl;
			cout << "Enter option: ";
			
			cin >> displayOption;
			
			if (displayOption == 1){
				clear();
				inv.displayBirthday();
				inv.displayGraduation();
				inv.displayAnniversary();
				inv.displayCondolence();
			}
			else if (displayOption == 2){
				clear();
				inv.displayBirthday();
			}
			else if (displayOption == 3){
				clear();
				inv.displayGraduation();
			}
			else if (displayOption == 4){
				clear();
				inv.displayAnniversary();
			}
			else if (displayOption == 5){
				clear();
				inv.displayCondolence();
			}
			else {
				clear();
				error();
				goto VIEW;
			}
		}
		
		void addStock(){
			clear();
			int batch;
			int selection;
			cout << "Select batch of new stocks" << endl;
			cout << "1 - Morning batch" << endl;
			cout << "2 - Noon batch" << endl;
			cin >> batch;
			clear();
			if (batch == 1){
				do{
					clear();
					cout << "Morning batch selected\nEnter details for new stock\n";
					cout << "1 - Add Birthday stock" << endl;
					cout << "2 - Add Graduation stock" << endl;
					cout << "3 - Add Anniversary stock" << endl;
					cout << "4 - Add Condolence stock" << endl;
					cout << "5 - Remove recently added stock" << endl;
					cout << "0 - Confirm new stock" << endl;
					
					cin >> selection;
					
					if (selection == 1){
						q.enqueueB();
					}
					else if (selection == 2){
						q.enqueueG();
					}
					else if (selection == 3){
						q.enqueueA();
					}
					else if (selection == 4){
						q.enqueueC();
					}
					else if (selection == 5){
						
					}
					else if (selection < 0 || selection > 5){
						clear();
						error();
					}
				}while(selection !=0);
				
				//**************************NEW BATCH CONFIRMATION**************************
				q.displayB();
				q.displayG();
				q.displayA();
				q.displayC();
				system("PAUSE");
			}
			else if (batch == 2){
				cout << "Noon batch selected\nEnter details for new stock\n";
				
			}
		}
		
		int edit(){
			EDIT:
			int choice;
			cout << "1 - Add stock" << endl;
			cout << "2 - Remove stock" << endl;
			cout << "0 - Main Menu" << endl;
			cin >> choice;
			
			if (choice == 1){
				addStock();
			}
			else if (choice == 2){
				
			}
			else if (choice == 0){
				return choice;
			}
			else {
				clear();
				error();
				goto EDIT;
			}
		}
		
};

int main (){
	Display display;
	while(true){
		clear();
		
		MAINMENU:
		int mainMenu; //main menu option // 1, 2, 0
		mainMenu = display.displayMenu();
		
		//view inventory
		if (mainMenu == 1){ 
			clear();
			display.view();
		}
		
		//edit inventory
		else if (mainMenu == 2){
			clear();
			if (display.edit() == 0){
				clear();
				goto MAINMENU;
			}
		}
		
		//exit program
		else if (mainMenu == 0){
			cout << "Thank you and have a great day!";
			exit(0);
		}
		
		//invalid input
		else {
			error();
		}
		
	system("PAUSE");
	}
	return 0;
}


void clear(){
	system("cls");
}

void error(){
	cout << "INVALID INPUT. PLEASE RE-ENTER\n";
}
