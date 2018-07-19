/*
Rachel
ECE 370 - HW1
****************
Program assumes that the text file being read in will have one line of blank space between each entry.
Following the pattern:
ID, Name, Address, Blank, ID,.....
The program will have to be modified if it encounters a text file that does not follow that pattern
*/


#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <cctype>
#include <algorithm>
using namespace std;

struct Person {
    //Each person will fill one structure
    int ID;
    string name;
    string address;

};
struct Found_p {
    //Trying a separate structure for the searched names list
    //As an attempt to solve an error
    int p_ID;
    string p_name;

};

/*
Starting to try and move code to functions here
void LD2Struct(Person p_ptr[], int *p_index){

    ifstream a1("a1.txt");
    string s;

    while (getline(a1,s)){
            if (s.size() != 0){
                    //don't do any of these steps if the line read is empty
                    //Save ID
                    p_ptr[p_index].ID = atoi(s.c_str());
                    cout << person_ptr[pplIndex].ID << endl;
                    getline(a1,s);
                    p_ptr[p_index].name = s;
                    cout << person_ptr[pplIndex].name << endl;
                    getline(a1,s);
                    p_ptr[p_index].address = s;
                    cout << p_ptr[p_index].address << endl;
                    p_index ++;
            }
    }
}

*/


void headerTxt(){
    //Here is the text that prints when Program Begins
    //Print tips, such as case sensitivity
    printf("As a note, the answer to Yes/No questions is case sensitive in this program version.\n");
    printf("Answer all Y/N questions with a single capital letter Y or N.\n");
    printf("The program will first read the current addresses");
    printf("When the user inputs an address, the street name must be one word with no spaces. \n\n");
}



int main()
{
    Person *person_ptr = new Person[20]; //allocate 20 structures, one per person
    ifstream a1("a1.txt");
    string s;
    int pplIndex = 0; //keep track of how many structures are filled or what structure is being filled

    headerTxt();

//Here, we are reading the text file and populating the structures
    while (getline(a1,s)){
            if (s.size() != 0){
                    //don't do any of these steps if the line read is empty
                    //Save ID
                    person_ptr[pplIndex].ID = atoi(s.c_str());
                    cout << person_ptr[pplIndex].ID << endl;
                    getline(a1,s);
                    person_ptr[pplIndex].name = s;
                    cout << person_ptr[pplIndex].name << endl;
                    getline(a1,s);
                    person_ptr[pplIndex].address = s;
                    cout << person_ptr[pplIndex].address << endl;
                    pplIndex ++;
            }
    }









    string yesNo = ""; //Holds the answer to a yes/no question


    //This will ask the user to add a person
    while ((yesNo.compare("Y")!=0)&&(yesNo.compare("N")!=0)){
            //Unless the user gives a valid response, this will continue to loop
       printf("\n Is there an additional person to add? (Case Sensitive) Y/N ");
        cin >> yesNo;
        cout << endl;
    }

    //Now we need to add people if the user said Yes
    //define variables to be used in loop where user adds people to the structure

    //Input is taken, but is not being put into the structure
    string valid;
    string tp;
    int int_in;
    string L_name, F_name;
    string num, street, city, state, zip;


    while (yesNo == "Y" && pplIndex <= 20){
            //pplIndex will break the add person loop once the structure is full
        //get ID
        printf("Enter their ID number: ");
        cin >> int_in;
        person_ptr[pplIndex].ID = int_in;
        cout << person_ptr[pplIndex].ID<<endl;
        printf("Is this correct? (Case Sensitive) Y/N ");
        cin >> valid;
        cout << endl;

        while (valid != "Y"){
                //This will loop until user is satisfied with their ID entry
        printf("Please re-enter the ID: ");
        cin >> int_in;
        cout << endl;
        printf("Is this correct? (Case Sensitive) Y/N ");
        cin >> valid;
        cout << endl;
        };
        //save to structure
       // person_ptr[pplIndex].ID = *userInput;
        valid.clear();


        //get name
        printf("Enter their Last Name: ");
        cin >> L_name; //Maybe we need to figure out how to
        //keep Cin from breaking on the space or comma
        printf("Enter their First Name: ");
        cin >> F_name;
        person_ptr[pplIndex].name = L_name + "," + F_name;
        cout << endl;
        printf("Is this correct? (Case Sensitive) Y/N ");
        cin >> valid; //For some reason this is getting skipped
        cout << endl;

        while (valid != "Y"){
                //This will loop until user is satisfied with their name entry
        printf("Enter their Last Name: ");
        cin >> L_name; //Maybe we need to figure out how to
        //keep Cin from breaking on the space or comma
        printf("Enter their First Name: ");
        cin >> F_name;
        person_ptr[pplIndex].name = L_name + "," + F_name;
        cout << endl;

        //cin >> *userInput;
        printf("Is this correct? (Case Sensitive) Y/N ");
        cin >> valid;
        cout << endl;
        };
        //save to structure
        //person_ptr[pplIndex].name = *userInput;
        valid.clear();

        //get address
        printf("Enter their address in this format: \n 999 StreetName City State Zipcode ");
        cin >> num >> street >> city >> state >> zip;
        person_ptr[pplIndex].address = num + ", " + street + ", " + city + ", " + state + ", " + zip;
        cout << endl;
        printf("Is this correct? (Case Sensitive) Y/N ");
        cin >> valid;
        cout << endl;

        while (valid != "Y"){
                //This will loop until user is satisfied with their ID entry
                //The street name cannot have spaces in it in this version
       printf("Enter their address in this format: \n 999 Street City MI 48230 ");
        cin >> num >> street >> city >> state >> zip;
        person_ptr[pplIndex].address = num + ", " + street + ", " + city + ", " + state + ", " + zip;
        cout << endl;
        printf("Is this correct? (Case Sensitive)Y/N ");
        cin >> valid;
        cout << endl;
        };
        //save to structure
        //person_ptr[pplIndex].address = *userInput;
        valid.clear();


//****************************************
//This code is just for testing that the data was put into the structure
        printf("This is the data you added: \n");
        printf("ID: ");
        cout << person_ptr[pplIndex].ID << endl;
        printf("Name: ");
        cout << person_ptr[pplIndex].name << endl;
        printf("Address: ");
        cout << person_ptr[pplIndex].address << endl;

//**************************************************

        pplIndex++ ;
        printf("Is there an additional person to add? Y/N ");
        cin >> yesNo;
        cout << endl;
    }

string u_in;
string P_name; //found name

bool flag = false; //This flag will switch to true if at least one name is found via the search function




    Person *found_prsn = new Person[20]; //allocate 20 structures since it it technically
    //only possible to get 20 names as results
    int srchIndex = 0; //keep track of how many structures are filled or what structure is being filled




    //Now we need to let the user search for information by last name
    while(true){
            flag = false; //when loop restarts, flag needs to be reset to false
        printf("Would you like to search for someone by last name? Y/N ");
        cin >> yesNo;
        if(yesNo == "Y"){
            //Proceed to search structures by last name & print results
            printf("Please enter their last name (Capitalize first letter only): ");
            cin >> u_in;
            printf("Is this correct? Y/N ");
            cin >> valid;
            while(valid != "Y"){
                //Loop prompting user to retype their input
                printf("Please enter their last name (Capitalize first letter only): ");
                cin >> u_in;
                printf("Is this correct? Y/N ");
                cin >> valid;

            }
            //u_in = toupper(u_in.c_str());
            transform(u_in.begin(),u_in.end(), u_in.begin(), ::toupper);
            //now use  last name string to search
            for(int i=0; i<20; i++){
                    //Searching the entire structure for last name
                L_name = person_ptr[i].name;
                L_name.resize(u_in.size());
                transform(L_name.begin(),L_name.end(), L_name.begin(), ::toupper);
                    if(u_in.compare(L_name)==0){
                        //If comparison is true, then print result
                        printf("\nID: ");
                        cout << person_ptr[i].ID << endl;
                        printf("Name: ");
                        cout << person_ptr[i].name << endl;
                        printf("Address: ");
                        cout << person_ptr[i].address << endl;
                        //Save to found structure
                        //search found structure to see if last name already exists
                        for(int i=0;i<20;i++){
                                P_name = found_prsn[i].name;
                        P_name.resize(u_in.size());
                            if(u_in.compare(P_name)!=0 && P_name.size()!= 0){
                                //if the searched last name isn't already in structure, add it
                                found_prsn[srchIndex].ID = person_ptr[i].ID;
                                found_prsn[srchIndex].name = person_ptr[i].name;
                                found_prsn[srchIndex].address = person_ptr[i].address;
                                srchIndex++;

                            }
                        }
                        //toggle flag to true
                        flag = true;
                    }


            }
            if(flag == true){
                printf("\nSearch results are listed above. \n");
            }
            else{
                printf("\nThat last name is not in our records. \n");
            }

        }
        else if(yesNo == "N"){
            break; //break the While Loop
        }
    }

printf("\nComplete Search History: \n");
for(int i=0;i<20;i++){
    //print found search results
    printf("ID: ");
    cout << found_prsn[i].ID <<endl;
    printf("Name: ");
    cout << found_prsn[i].name << endl;
    printf("Address: ");
    cout << found_prsn[i].address <<endl <<endl;

}


    return 0;
}
