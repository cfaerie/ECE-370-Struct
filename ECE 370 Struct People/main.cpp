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
#include <algorithm>


#define MAX_SIZE 20 //Maximum size of the structure


using namespace std;

struct Person {
    //Each person will fill one structure
    int ID;
    string name;
    string address;

};
struct Found_p {

    int p_ID;
    string p_name;
    string p_address;

};


//Function Prototypes
int LD2Struct(struct Person p_ptr[]);
int Add2Struct(struct Person p_ptr[],int pplIndex);
void PSearch(struct Person p_ptr[],int pplIndex);
string Str2Upper(string s);

void printStruct(struct Person p_ptr[],int index)
{
    for(int i=0;i<index;i++)
    {
        cout<<p_ptr[i].ID<<endl;
        cout<<p_ptr[i].name<<endl;
        cout<<p_ptr[i].address<<endl<<endl;
    }
}


void headerTxt()
{
    //Here is the text that prints when Program Begins
    printf("Answer all Y/N questions with a single letter Y or N.\n");
    printf("The program will first read the current addresses from a file.\n");
    printf("When the user inputs an address, the street name must be one word with no spaces. \n\n");
}



int main()
{
    struct Person person_ptr[MAX_SIZE];
    ifstream a1("a1.txt");
    string s;
    int pplIndex = 0; //keep track of how many structures are filled or what structure is being filled

    headerTxt();

    cout<<"Loading to Structure"<<endl;
    pplIndex = LD2Struct(person_ptr);
    cout<<"Load Complete.\n"<< pplIndex << " people loaded.\n"<<endl;

    cout<<"Printing structure.\n"<<endl;
    printStruct(person_ptr,pplIndex); //Print what was loaded to struct

    pplIndex = Add2Struct(person_ptr,pplIndex);
    cout << "Updated index is "<<pplIndex<<"/"<<MAX_SIZE<<endl;//updated index because more people may have been added

    PSearch(person_ptr,pplIndex);

    return 0;
}


//Function contents
int LD2Struct(struct Person p_ptr[])
{
    ifstream a1("a1.txt");//contains list of people data to load
    string s;
    int pplIndex = 0;

    while (getline(a1,s))
    {
        if(s.size() != 0)
        {
            //dont do any of these steps if the line read is empty
            p_ptr[pplIndex].ID = atoi(s.c_str()); //Store ID

            getline(a1,s);
            p_ptr[pplIndex].name = s; //store name

            getline(a1,s);
            p_ptr[pplIndex].address = s; //Store address

            pplIndex++;
        }
    }
    return pplIndex;
}


int Add2Struct(struct Person p_ptr[],int pplIndex)
{
    string yesNo; //Holds the answer to a yes/no question
    string valid; // secondary Y/N question, confirm validity of what was entered
    int int_in;
    string L_name, F_name;
    string num, street, city, state, zip;
    string address;

    while ((yesNo != "Y")&&(yesNo!= "N"))
    {
        //Unless the user gives a valid response, this will continue to loop
        cin.clear();
        printf("\n Is there an additional person to add? Y/N ");
        cin >> yesNo;
           if(yesNo.length()>1)
           {
               cout<<"Input too long." <<endl;
           }
           else
            {
                yesNo = Str2Upper(yesNo);
            }

        cout << endl;
    }
    //This is multiple nested While loops. Perhaps there is a better way to do this
    //with one while loop and switch case?

    while (yesNo == "Y" && pplIndex <= MAX_SIZE)
    {
            //pplIndex will break the add person loop once the structure is full
        //get ID
        printf("Enter their ID number: ");
        cin >> int_in;
        p_ptr[pplIndex].ID = int_in;
        cout << p_ptr[pplIndex].ID<<endl;
        printf("Is this correct? Y/N ");
        cin >> valid;

        if(valid.length()>1)
       {
           cout<<"Input too long." <<endl;
       }
       else
        {
            valid = Str2Upper(valid);
        }
        //valid = toupper(valid);

        cout << endl;

        while (valid != "Y")
        {
                //This will loop until user is satisfied with their ID entry
        printf("Please re-enter the ID: ");
        cin >> int_in;
        cout << endl;
        printf("Is this correct? Y/N ");
        cin >> valid;

            if(valid.length()>1)
           {
               cout<<"Input too long." <<endl;
           }
           else
            {
                valid = Str2Upper(valid);
            }
        cout << endl;
        };
        valid = " ";

        //get name
        printf("Enter their Last Name: ");
        cin >> L_name;
        printf("Enter their First Name: ");
        cin >> F_name;
        p_ptr[pplIndex].name = L_name + "," + F_name;
        cout << endl;

        printf("Is this correct? Y/N ");
        cin >> valid;
        if(valid.length()>1)
       {
           cout<<"Input too long." <<endl;
       }
       else
        {
            valid = Str2Upper(valid);
        }
        cout << endl;

        while (valid != "Y")
        {
                    //This will loop until user is satisfied with their name entry
            printf("Enter their Last Name: ");
            cin >> L_name; //Maybe we need to figure out how to
            //keep Cin from breaking on the space or comma
            printf("Enter their First Name: ");
            cin >> F_name;
            p_ptr[pplIndex].name = L_name + "," + F_name;
            cout << endl;

            printf("Is this correct? Y/N ");
            cin >> valid;

            if(valid.length()>1)
           {
               cout<<"Input too long." <<endl;
           }
           else
            {
                valid = Str2Upper(valid);
            }

        cout << endl;
        };
        valid = " " ;


        //get address
        printf("Enter their address in this format: \n 999 StreetName City State Zipcode ");
        cin >> num >> street >> city >> state >> zip;
        p_ptr[pplIndex].address = num + ", " + street + ", " + city + ", " + state + ", " + zip;
        cout << endl;
        printf("Is this correct? Y/N ");
        cin >> valid;

        if(valid.length()>1)
       {
           cout<<"Input too long." <<endl;
       }
       else
        {
            valid = Str2Upper(valid);
        }
        cout << endl;

        while (valid != "Y")
        {
                //This will loop until user is satisfied with their ID entry
                //The street name cannot have spaces in it in this version
            printf("Enter their address in this format: \n 999 Street City MI 48230 ");
            cin >> num >> street >> city >> state >> zip;
            p_ptr[pplIndex].address = num + ", " + street + ", " + city + ", " + state + ", " + zip;
            cout << endl;
            printf("Is this correct? Y/N ");
            cin >> valid;

            if(valid.length()>1)
           {
               cout<<"Input too long." <<endl;
           }
           else
            {
                valid = Str2Upper(valid);
            }
            cout << endl;
        };
        valid = " ";



//****************************************
//This code is just for testing that the data was put into the structure
        printf("\nThis is the data you added: \n");
        printf("ID: ");
        cout << p_ptr[pplIndex].ID << endl;
        printf("Name: ");
        cout << p_ptr[pplIndex].name << endl;
        printf("Address: ");
        cout << p_ptr[pplIndex].address << endl;

//**************************************************

        pplIndex++ ;

        yesNo = " ";//clear it before entering loop.
        while(yesNo != "Y" && yesNo != "N")
        {
            printf("Is there an additional person to add? Y/N ");
            cin >> yesNo;
            if(yesNo.length()>1)
           {
               cout<<"Input too long." <<endl;
           }
           else
            {
                yesNo = Str2Upper(yesNo);
            }
            //yesNo = toupper(yesNo);
            cout << endl;
        }


    }
    return pplIndex;
}

void PSearch(struct Person p_ptr[],int pplIndex)
{
    string u_in; //user input
    string L_name; //Stores the last name
    string P_name; //found name, Person's name
    string yesNo;
    string valid;

    int srchIndex = 0; //keep track of how many structures are filled or what structure is being filled
    bool flag = false; //this flag will switch to tru if at least one name is found

    Person *found_prsn = new Person[MAX_SIZE]; //allocate a number of structures

    //Now we need to let the user search for information by last name

    while(true)
    {
        flag = false; //when loop restarts, flag needs to be reset to false
        printf("\nWould you like to search for someone by last name? Y/N ");
        cin >>yesNo;
            if(yesNo.length()>1)
           {
               cout<<"Input too long." <<endl;
           }
           else
            {
                yesNo = Str2Upper(yesNo);
            }


            if(yesNo == "Y")
            {
                //Proceed to search structures by last name & print results
                printf("Please enter their last name: ");
                cin >> u_in;
                printf("Is this correct? Y/N ");
                cin >> valid;

                if(valid.length()>1)
                   {
                       cout<<"Input too long." <<endl;
                   }
                   else
                    {
                        valid = Str2Upper(valid);
                    }

                while(valid != "Y")
                {
                    //Loop prompting user to retype their input
                    printf("Please enter their last name: ");
                    cin >> u_in;
                    printf("Is this correct? Y/N ");
                    cin >> valid;

                    if(valid.length()>1)
                   {
                       cout<<"Input too long." <<endl;
                   }
                   else
                    {
                        valid = Str2Upper(valid);
                    }
                }
            transform(u_in.begin(),u_in.end(), u_in.begin(), ::toupper);
            //now use  last name string to search
            for(int i=0; i<pplIndex; i++){
                    //Searching the entire structure for last name
                L_name = p_ptr[i].name;
                L_name.resize(u_in.size());
                transform(L_name.begin(),L_name.end(), L_name.begin(), ::toupper);
                    if(u_in.compare(L_name)==0)
                    {
                        //Save to found structure
                        //search found structure to see if last name already exists
                        for(int j=0;j<MAX_SIZE;j++)
                        {
                            P_name = found_prsn[j].name;
                                if(P_name.empty() != true)
                                {
                                    P_name.resize(u_in.size());
                                    transform(P_name.begin(),P_name.end(), P_name.begin(), ::toupper);
                                }

                            //Maybe re-order if statements to get things to work better?
                            //first check if we are at the end of the array
                            //Then check if the indexed spot in the array is empty or same as searched


                            //If P_name is not at that index, continue search
                            if(u_in.compare(P_name)!=0 && srchIndex != 0 && j < MAX_SIZE && P_name.empty()!=true)
                            {
                                    cout<<"Searching..."<<endl;
                                    //continue;
                               //break; //should break from this if elseif set
                            }
                            //If P_name IS at that index, break and don't add to struct
                            else if(u_in.compare(P_name)==0)
                            {
                                //THIS IS GETTING SKIPPED
                                    cout<<"\n\nName has already been found previously."<<endl;
                                    cout<<"Please search a different name."<<endl;
                                    break;
                            }

                            //If end of struct is reached and P_name is not found, add P_name to struct
                            else if(u_in.compare(P_name)!=0 && j <= srchIndex)
                            {

                                //if the searched last name isn't already in structure, add it
                                found_prsn[srchIndex].ID = p_ptr[i].ID;
                                found_prsn[srchIndex].name = p_ptr[i].name;
                                found_prsn[srchIndex].address = p_ptr[i].address;
                                srchIndex++;
                                i = MAX_SIZE+1;
                                break;

                            }
                            else
                            {
                                cout<<"Error."<<endl;
                            }
                        }
                        //toggle flag to true
                        flag = true;
                    }


            }
            if(flag == true){
                printf("\n\nName was found. \n");
            }
            else{
                printf("\nThat last name is not in our records. \n");
            }

        }

        else if(yesNo == "N")
            {
                break; //break the While Loop
            }
        else
        {
            continue;

        }
    }//END FINAL WHILE

printf("\n\nComplete Search History: \n");
for(int i=0;i<srchIndex;i++)
    {
    //print found search results
    printf("ID: ");
    cout << found_prsn[i].ID <<endl;
    printf("Name: ");
    cout << found_prsn[i].name << endl;
    printf("Address: ");
    cout << found_prsn[i].address <<endl <<endl;


    }
return;
};

string Str2Upper(string s)
{
    transform(s.begin(),s.end(), s.begin(), ::toupper);
    return s;
}

