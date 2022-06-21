#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstdio>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

void menu() {

//display the options for mangagement
    cout << "Add record ----- 1\n";
    cout << "Edit record ---- 2\n";
    cout << "View record ---- 3\n";
    cout << "Delete record -- 4\n";
    cout << "Exit ----------- 5\n";

}


//make a class (to later call) of all the functions for managment
class management_functions {

    public:
    void add_file();
    void edit_file();
    void view_file();
    void delete_file();

};



void management_functions::add_file() { // add a new file

    fstream file;

    cout << "Use the account holder's full name as the file name with .txt as the extension:\n";
    string file_name;
    cin >> file_name;

    //"open" or create the file (anything after this will be acted on this file)
    file.open(file_name, ios::out); 


    // if the file is not found then...
    if (!file) {
        cout<<"Error while creating the file";    
    }



    //input the name, account number and balance:
    else{

        string name;
        int acc_no;
        double balance;

        cout << "Input account holder full name:\n";
        cin >> name;

        cout << "Input account number:\n";
        cin >> acc_no;

        cout << "Input bank balance:\n";
        cin >> balance;


        //input to file:
        file << "Holder's Name: " << name << "\n" << "Account Number: " << acc_no << "\n" << "Bank balance: " << balance;
        cout << "File created successfully";

        file.close(); 
    }

}




void management_functions::edit_file() { //edit existing file

    fstream file;

    cout << "Enter the name of the file to edit with the .txt extension:\n";
    string file_name;
    cin >> file_name;

    
    file.open(file_name, ios_base::in); //open (read and write)
    system(file_name.c_str()); // open the file using appropriate extension (eg notepad)
    file.close();


}


void management_functions::view_file() { //view existing file


    cout << "What is the name of the file you want to open? (include .txt extension)\n";
    string file_name;
    cin >> file_name;                  


    fstream file;
    file.open(file_name, ios::in); //open (read and write)



    if (!file) {
        cout << "File doesnt exist.";
    }
    

    // print the contents of the file (found online):
    else {
        char x;
        
        while (1) {
            file >> x;

            if(file.eof( )) {
                break;
            }

            cout << x;
        }
    }
    file.close();

}




void management_functions::delete_file() { //delete existing file

    cout << "What is the file that you want to remove? (include .txt extension)\n";
    char file_name[20];
    cin >> file_name;

    int status;
    status = remove(file_name); //remove function from <stdlib.h>

}




void option() {

    menu();

    int opt;
    cin >> opt;

    management_functions option; 

    // if statements that call the different "management functions" 
    //from the managment_functions class:
    if (opt == 1) {
        option.add_file();
    }

    if (opt==2) {
        option.edit_file();
    }

    if (opt==3) {
        option.view_file();
    }

    if (opt==4) {
        option.delete_file();
    }

    if (opt==5) {
        exit(0);
    }

    //NB: whats the point of creating the class. why not just call the function in void option()??... 
    //answer: better organisation

}




void pw() {  //require password and carryout the program after
    string pw;

    cout << "BANK RECORD MANAGEMENT\n";
    cout << "Passsword:\n";
    cin >> pw;

    if (pw == "password") { 
        while (pw == "password") { //while loop in order to avoid manual restart after finish executing
            option(); //carry out the "managment options"
            cout << "\n"; //make space after program is finished and then restarts using while loop
        }
    }


    else {
        cout << "Incorrect password. Restart program and try again.\n";
    }

}



int main() {
    
    pw();

}

