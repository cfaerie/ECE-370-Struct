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
#include <cctype>

#define MAX_SIZE 20 //Maximum size of the structure

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

//Function Prototypes
int LD2Struct(struct Person p_ptr[]);
int Add2Struct(struct Person p_ptr[],int pplIndex);
void PSearch(struct Person p_ptr[],int pplIndex);


void printStruct(struct Person p_ptr[],int index){
    for(int i=0;i<index;i++){
        cout<<p_ptr[i].ID<<endl;
        cout<<p_ptr[i].name<<endl;
        cout<<p_ptr[i].address<<endl<<endl;

    }

}



void headerTxt(){
    //Here is the text that prints when Program Begins
    //Print tips, such as case sensitivity
    printf("As a note, the answer to Yes/No questions is case sensitive in this program version.\n");
    printf("The program will first read the current addresses");
    printf("When the user inputs an address, the street name must be one word with no spaces. \n\n");
}





int main()
{
    //Person *person_ptr = new Person[20]; //allocate 20 structures, one per person
    //Having trouble getting pointer to pass through functions
    struct Person person_ptr[MAX_SIZE];
    ifstream a1("a1.txt");
    string s;
    int pplIndex = 0; //keep track of how many structures are filled or what structure is being filled
    char yesNo; //Holds the answer to a yes/no question
    int index =0;

    headerTxt();

    //Here, we are reading the text file and populating the structures
    cout<<"Loading to Structure"<<endl;
    pplIndex = LD2Struct(person_ptr); //maybe I should return an index number here, to be saved and used in other functions
    cout<<"Load Complete.\n"<< pplIndex << " people loaded.\n"<<endl;
    cout<<"Printing structure.\n"<<endl;
    printStruct(person_ptr,pplIndex); //Print what was loaded to struct
    pplIndex = Add2Struct(person_ptr,pplIndex);
    cout << "Updated index is "<<pplIndex<<"/"<<MAX_SIZE<<endl;
    PSearch(person_ptr,pplIndex);


string u_in;
string P_name; //found name

bool flag = false; //This flag will switch to true if at least one name is found via the search function




    Person *found_prsn = new Person[20]; //allocate 20 structures since it it technically
    //only possible to get 20 names as results
    int srchIndex = 0; //keep track of how many structures are filled or what structure is being filled



/*
    //Now we need to let the user search for information by last name
    while(true){
            flag = false; //when loop restarts, flag needs to be reset to false
        printf("Would you like to search for someone by last name? Y/N ");
        cin >> yesNo;
        yesNo = toupper(yesNo);
        if(yesNo == 'Y'){
            //Proceed to search structures by last name & print results
            printf("Please enter their last name (Capitalize first letter only): ");
            cin >> u_in;
            printf("Is this correct? Y/N ");
            cin >> valid;
            valid = toupper(valid);
            while(valid != 'Y'){
                //Loop prompting user to retype their input
                printf("Please enter their last name (Capitalize first letter only): ");
                cin >> u_in;
                printf("Is this correct? Y/N ");
                cin >> valid;
                valid = toupper(valid);

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
        else if(yesNo == 'N'){
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

} */


    return 0;
}

//Function contents
int LD2Struct(struct Person p_ptr[]){

    ifstream a1("a1.txt"); //contains list of People data to load
    string s;
    int pplIndex = 0;

    while (getline(a1,s)){
            if (s.size() != 0){
                    //don't do any of these steps if the line read is empty
                    p_ptr[pplIndex].ID = atoi(s.c_str()); //Store ID

                    getline(a1,s);
                    p_ptr[pplIndex].name = s; //Store Name

                    getline(a1,s);
                    p_ptr[pplIndex].address = s; //Store address

                    pplIndex ++;
            }
    }
    return pplIndex;
}

int Add2Struct(struct Person p_ptr[],int pplIndex){
    char yesNo; //Holds the answer to a yes/no question
    char valid; // secondary Y/N question, confirm validity of what was entered
    int int_in;
    string L_name, F_name;
    string num, street, city, state, zip;
    string address;

    while ((yesNo != 'Y')&&(yesNo!= 'N')){
            //Unless the user gives a valid response, this will continue to loop
       printf("\n Is there an additional person to add? Y/N ");
        cin >> yesNo;
        yesNo = toupper(yesNo);
        cout << yesNo << endl;
        cout << endl;
    }
    //This is multiple nested While loops. Perhaps there is a better way to do this
    //with one while loop and switch case?
    while (yesNo == 'Y' && pplIndex <= 20){
            //pplIndex will break the add person loop once the structure is full

        printf("Enter their ID number: "); //get ID
        cin >> int_in;  //So far there is no limit on how long of a number
        p_ptr[pplIndex].ID = int_in; //Add ID to Struct

        cout << p_ptr[pplIndex].ID<<endl; //to confirm what was added
        printf("Is this correct? Y/N ");
        cin >> valid;
        valid = toupper(valid);
        cout << endl;

        while (valid != 'Y'){
                //This will loop until user is satisfied with their ID entry
        printf("Please re-enter the ID: ");
        cin >> int_in;
        cout << endl;
        printf("Is this correct? Y/N ");
        cin >> valid;
        valid = toupper(valid);
        cout << endl;
        };
        //save to structure
       // person_ptr[pplIndex].ID = *userInput;
        valid = ' ';


        //get name
        printf("Enter their Last Name: ");
        cin >> L_name;
        printf("Enter their First Name: ");
        cin >> F_name;
        p_ptr[pplIndex].name = L_name + "," + F_name;
        cout << endl;
        printf("Is this correct? Y/N ");
        cin >> valid;
        valid = toupper(valid);
        cout << endl;

        while (valid != 'Y'){
                //This will loop until user is satisfied with their name entry
        printf("Enter their Last Name: ");
        cin >> L_name; //Maybe we need to figure out how to
        //keep Cin from breaking on the space or comma
        printf("Enter their First Name: ");
        cin >> F_name;
        p_ptr[pplIndex].name = L_name + "," + F_name;
        cout << endl;

        //cin >> *userInput;
        printf("Is this correct? Y/N ");
        cin >> valid;
        valid = toupper(valid);
        cout << endl;
        };
        valid = ' ';

        //get address
        printf("Enter their address in this format: \n 1234 MeadowBrookLn Detroit MI 48230 \n ");
        cin >> num >> street >> city >> state >> zip;
        p_ptr[pplIndex].address = num + " " + street + ", " + city + ", " + state + " " + zip;
       //cin >> address;  //not working, doesn't print correctly using cout
       //p_ptr[pplIndex].address = address; //not working
        cout << endl;
        cout << p_ptr[pplIndex].address << endl;
        printf("Is this correct? Y/N ");
        cin >> valid;
        valid = toupper(valid);
        cout << endl;

        while (valid != 'Y'){
                //This will loop until user is satisfied with their ID entry
                //The street name cannot have spaces in it in this version
       printf("Enter their address in this format: \n 1234 MeadowBrook Ln, Detroit, MI 48230 \n");
        cin >> num >> street >> city >> state >> zip;
        p_ptr[pplIndex].address = num + ", " + street + ", " + city + ", " + state + " " + zip;
        //cin >> address;  //not working
        //p_ptr[pplIndex].address = address;  //not working
        //cout << p_ptr[pplIndex].address << endl;
        printf("Is this correct? Y/N ");
        cin >> valid;
        valid = toupper(valid);
        cout << endl;
        };
        //save to structure
        //person_ptr[pplIndex].address = *userInput;
        valid = ' ';


//****************************************
//This code is just for testing that the data was put into the structure
        printf("This is the data you added: \n");
        printf("ID: ");
        cout << p_ptr[pplIndex].ID << endl;
        printf("Name: ");
        cout << p_ptr[pplIndex].name << endl;
        printf("Address: ");
        cout << p_ptr[pplIndex].address << endl; //address not printing correctly. Seems to print the memory address?

//**************************************************

        pplIndex++ ;
        printf("Is there an additional person to add? Y/N ");
        cin >> yesNo;
        yesNo = toupper(yesNo);
        cout << endl;
    }
    return pplIndex;

}

void PSearch(struct Person p_ptr[],int pplIndex){
    string u_in; //user input
    string L_name;
    string P_name; //found name, Person's name
    char yesNo;
    char valid;
    int srchIndex = 0; //keep track of how many structures are filled or what structure is being filled
    bool flag = false; //This flag will switch to true if at least one name is found via the search function

    Person *found_prsn = new Person[MAX_SIZE]; //allocate a number of structures


    //Now we need to let the user search for information by last name
    while(true){
        flag = false; //when loop restarts, flag needs to be reset to false
        printf("Would you like to search for someone by last name? Y/N ");
        cin >> yesNo;
        yesNo = toupper(yesNo);

        if(yesNo == 'Y'){
            //Proceed to search structures by last name & print results
            printf("Please enter their last name: ");
            cin >> u_in;
            printf("Is this correct? Y/N ");
            cin >> valid;
            valid = toupper(valid);
            while(valid != 'Y'){
                //Loop prompting user to retype their input
                printf("Please enter their last name: ");
                cin >> u_in;
                printf("Is this correct? Y/N ");
                cin >> valid;
                valid = toupper(valid);

            }
            //u_in = toupper(u_in.c_str());
            transform(u_in.begin(),u_in.end(), u_in.begin(), ::toupper);
            //now use  last name string to search
            for(int i=0; i<pplIndex; i++){
                    //Searching the entire structure for last name
                L_name = p_ptr[i].name;
                L_name.resize(u_in.size());
                transform(L_name.begin(),L_name.end(), L_name.begin(), ::toupper);
                    if(u_in.compare(L_name)==0){
                        //If comparison is true, then print result
                        printf("\nID: ");
                        cout << p_ptr[i].ID << endl;
                        printf("Name: ");
                        cout << p_ptr[i].name << endl;
                        printf("Address: ");
                        cout << p_ptr[i].address << endl;
                        //Save to found structure
                        //search found structure to see if last name already exists
                        for(int j=0;j<MAX_SIZE;j++){
                            P_name = found_prsn[j].name;
                            P_name.resize(u_in.size());
                            //Maybe re-order if statements to get things to work better?
                            //first check if we are at the end of the array
                            //Then check if the indexed spot in the array is empty or same as searched


                            //If P_name is not at that index, continue search
                            if(u_in.compare(P_name)!=0 && P_name.size()!= 0 && j < MAX_SIZE){
                                    //continue;
                               //break; //should break from this if elseif set
                               }
                            //If P_name IS at that index, break and don't add to struct
                            else if(u_in.compare(P_name)==0 && P_name.size()!= 0){
                                //THIS IS GETTING SKIPPED
                                    cout<<"Name has already been found previously."<<endl;
                                    cout<<"Please search a different name."<<endl;
                                    break;
                            }

                            //If end of struct is reached and P_name is not found, add P_name to struct
                            else if(u_in.compare(P_name)!=0 && P_name.size()!= 0 && j <= srchIndex){
                                //if the searched last name isn't already in structure, add it
                                //This should be at the END of the search through the array.
                                found_prsn[srchIndex].ID = int(p_ptr[i].ID);
                                found_prsn[srchIndex].name = string(p_ptr[i].name);
                                found_prsn[srchIndex].address = string(p_ptr[i].address);
                                srchIndex++;

                            }
                            else{
                                cout<<"Error."<<endl;
                            }



                        }
                        //toggle flag to true, since a name was found
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
        else if(yesNo == 'N'){
            break; //break the While Loop
        }
    }

printf("\nComplete Search History: \n");
for(int i=0;i<20;i++){
    //print found search results
    //not printing correctly. No results in the containers.
    printf("ID: ");
    cout << found_prsn[i].ID <<endl;
    printf("Name: ");
    cout << found_prsn[i].name << endl;
    printf("Address: ");
    cout << found_prsn[i].address <<endl <<endl;

}

};

void PSearch2(struct Person p_ptr[],int pplIndex){
    string u_in; //user input
    string L_name;
    string P_name; //found name, Person's name
    char yesNo;
    char valid;
    int srchIndex = 0; //keep track of how many structures are filled or what structure is being filled
    bool brkFor = false; //This flag helps to break the nested FOR loop early

    Person *found_prsn = new Person[MAX_SIZE]; //allocate a number of structures

    //User inputs a last name, program searches p_ptr for that name
    while(yesNo != 'Y' || yesNo != 'N'){
        cout << "Would you like to search for someone by last name? Y/N ";
        cin >> yesNo;
        yesNo = toupper(yesNo);

        if(yesNo == 'Y'){
            //Perform search
             //Proceed to search structures by last name & print results
            cout << "Please enter their last name: ";
            cin >> u_in;
            cout << "Is this correct? Y/N ";
            cin >> valid;
            valid = toupper(valid);
            while(valid != 'Y'){
                //Loop prompting user to retype their input
                printf("Please enter their last name: ");
                cin >> u_in;
                printf("Is this correct? Y/N ");
                cin >> valid;
                valid = toupper(valid);
            }
            //Now search for u_in against P_ptr
            //u_in = toupper(u_in.c_str());
            transform(u_in.begin(),u_in.end(), u_in.begin(), ::toupper);//Convert U_in to uppercase
            //now use  last name string to search
            for(int i=0; i<pplIndex; i++){
                    if(brkFor == true){
                        brkFor = false;
                        break;
                    }
                    //Searching the entire structure for last name
                L_name = p_ptr[i].name;
                L_name.resize(u_in.size());
                transform(L_name.begin(),L_name.end(), L_name.begin(), ::toupper);
                cout << "Compare user input to indexed last name. " << u_in.compare(L_name) <<endl; //Expecting 0 when the names match, GETTING SKIPPED
                if(u_in.compare(L_name)==0){
                        //print the found struct
                        printf("\nID: ");
                        cout << p_ptr[i].ID << endl;
                        printf("Name: ");
                        cout << p_ptr[i].name << endl;
                        printf("Address: ");
                        cout << p_ptr[i].address << endl;
                        //add the found struct to search results if it hasn't already been added
                        if(srchIndex == 0){ //This is getting skipped
                            //the struct is empty. Just add the item.
                            cout << "Adding first searched item to list" <<endl;
                            found_prsn[srchIndex].ID = int(p_ptr[i].ID);
                            found_prsn[srchIndex].name = string(p_ptr[i].name);
                            found_prsn[srchIndex].address = string(p_ptr[i].address);
                            srchIndex++;
                            break;//break from FOR loop to ask if user wants to search again

                        }

                        //won't even enter this for loop if the struct is empty


                        for(int j=0;j<srchIndex;j++){
                            P_name = found_prsn[j-1].name; //Is there a name in the struct?
                            P_name.resize(u_in.size());

                            //If P_name IS at that index, and P_Name isn't empty, break from For loop and don't add to struct
                            if(u_in.compare(P_name)==0 && P_name.size()!= 0){
                                //THIS IS GETTING SKIPPED
                                    cout<<"Name has already been found previously."<<endl;
                                    cout<<"Please search a different name."<<endl;
                                    brkFor = true; //to exist the nested FOR loop
                                    break; //exit the for loop, but need to break from the next FOR loop as well. Maybe need a flag here?
                            }
                             //If P_name is not at that index, and P_name is not empty, continue search
                            else if(u_in.compare(P_name)!=0 && P_name.size()!= 0 && j < MAX_SIZE){
                                    //if u_in is not the same as P_name, and P_name is not empty, and we aren't at the end of the struct
                                    //continue searching

                                    continue;//jumps to the end of this for loop
                                    //should break from this if elseif set, skip the remaining conditions
                               }

                            //If end of struct is reached and P_name is not found, add P_name to struct
                            else if(u_in.compare(P_name)!=0 && j == srchIndex-1){
                                //if the searched last name isn't already in structure, add it
                                //This should be at the END of the search through the array.
                                cout<<"Adding searched name to search history." <<endl;
                                found_prsn[j].ID = int(p_ptr[i].ID);
                                found_prsn[j].name = string(p_ptr[i].name);
                                found_prsn[j].address = string(p_ptr[i].address);
                                srchIndex++;
                                brkFor = true;//set a flag to be used to break from the primary FOR loop
                                break; //break from this for loop

                            }
                            else{
                                cout<<"Error."<<endl;
                            }



                        }
                        //ask if use would like to continue searching
                        break; //jump out of the for loop and it will ask user if they want to search again

                }
                else {
                    //name was not found
                    cout<< "That name was not found."<<endl;
                    //ask user if they would like to search again
                    break; //jump out of the for loop and it will ask the user if they want to search again
                }


    }

}
else if (yesNo == 'N'){
            //They don't want to perform a search. End the function.
            return; //return ends a function
        }
    }
}
