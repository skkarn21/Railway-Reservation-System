#include <stdio.h>  // has various functions for performing input and output.
#include <conio.h>  //console input and output header file
#include <stdlib.h> //has various functions for performing general functions.
#include <string.h> // has various functions for manipulating arrays of characters.
#include <iostream> //provides basic input and output services
#include <time.h>   // has various functions for manipulating date and time.
#include <fstream>  //Input/output stream class to operate on files.
using namespace std;

void manage();            //User Management
void user();              //User menu
void database();          //admin menu
void res();               //reserve ticket
void displaypassdetail(); // display reservations
void cancel();           //cancel ticket
void enquiry();           //enquire about train information
void displaycan();        //display cancellations

char f[10] = "F";                  //First class
char s[10] = "S";                  //Second Class
int addr, ad, flag, f1, d, m, amt; //Pointer location, size, Not found status flag, day, month, amount
float tamt;                        //Total amount

class login //User Menu
{
public:
    char id[100];   //UserID
    char pass[100]; //User Password

    void getid() //take input of user id and password
    {
        cout << "Enter your id:";
        cin >> id;
        cout << "Enter the password: ";
        cin >> pass;
    }
    void displayid() //display id and password of all users
    {
        cout << id << "\t" << pass << endl;
    }
};
class detail //Train Detail
{
public:
    int tno;         //Train Number
    char tname[100]; //Train Name

    char bp[100];    //Boarding Station
    char dest[100];  //Destination Station
    int c1, c1fare;  //Seats in First class and fare
    int c2, c2fare;  //Seats in Second class and fare
    int d, m, y;     //Day Month Year
    void getdetail() //Get Train Information from admin
    {
        cout << "Enter the details as follows\n";
        cout << "Train no:";
        cin >> tno;
        cout << "Train name:";
        cin.sync();              //as cin does not consume '\n' so we must flush the input buffer
        cin.getline(tname, 100); // to get whitespaces upto '\n'
                                 // or scanf(" %[^\n]s", tname); //to get whitespace
        // cin >> tname;
        cout << "Boarding point:";
        cin >> bp;
        cout << "Destination pt:";
        cin >> dest;

        cout << "No of seats in First class & Fare per ticket:";
        cin >> c1 >> c1fare;
        cout << "No of seats in Second class & Fare per ticket:";
        cin >> c2 >> c2fare;
        cout << "Date of travel:";
        cin >> d >> m >> y;
    }
    void displaydetail() //Display Train detail
    {

        cout << tno << "\t\t" << tname << "\t" << bp << "\t\t\t" << dest << "\t\t\t";
        cout << c1 << "\t\t\t" << c1fare << "\t\t\t" << c2 << "\t\t\t" << c2fare << "\t\t\t";
        cout << d << "-" << m << "-" << y << "\t" << endl
             << endl;
    }
};
class reser //Reservation Details
{
public:
    int pnr;             //PNR Number or Passenger Name Record
    int tno;             //Train Number
    char tname[100];     //Train Name
    char bp[10];         //Boarding Station
    char dest[100];      //Destination Station
    char pname[10][100]; //Passenger Name
    int age[20];         //Passenger Age
    char clas[10];       //Class
    int nosr;            //No. of Seats Reserved
    int i;
    int d, m, y; //Day Month Year
    int con;     //Concession amount

    float amc;
    void getresdet() //Get Reservation Details
    {
        cout << "\nEnter the details as follows\n";
        cout << "\nTrain no: ";
        cin >> tno;
        // cout << "Train name: ";
        // cin >> tname;
        cout << "\nBoarding point: ";
        cin >> bp;
        cout << "\nDestination pt: ";
        cin >> dest;
        cout << "\nNo of seats required: ";
        cin >> nosr;
        cout << "\n\n";
        for (i = 0; i < nosr; i++)
        {
            cout << "Passenger " << i + 1 << " Name: ";
            cin.sync();                 //as cin does not consume '\n' so we must flush the input buffer
            cin.getline(pname[i], 100); // to get whitespaces upto '\n'
                                        // or scanf(" %[^\n]s", tname); //to get whitespace
            cout << "Passenger " << i + 1 << " Age: ";
            cin >> age[i];
        }
        cout << "\n\nEnter Class\nF-first class\nS-second class\n: ";
        cin >> clas;
        cout << "\nDate of travel(DD MM YYYY): ";
        cin >> d >> m >> y;
        cout << "\n\nEnter the concession category\n";
        cout << "1.Military\n2.Senior citizen\n";
        cout << "3.Children below 5 yrs\n4.None\n: ";
        cin >> con;
        cout << "............END OF GETTING DETAILS............\n";
    }
    void displayresdet() //Display
    {
        cout << "\n...............................................\n";
        cout << "...............................................\n";
        cout << "PNR No: " << pnr;
        cout << "\n\nTrain No: " << tno;
        cout << "\n\nTrain Name: ";
        cout << tname;
        cout << "\n\nBoarding Point: ";
        cout << bp;
        cout << "\n\nDestination Point: ";
        cout << dest;
        cout << "\n\nNo of seats reserved: " << nosr;
        for (i = 0; i < nosr; i++)
        {
            cout << "\n\nPassenger " << i + 1 << " Name:";
            cout << pname[i];
            cout << "\nPassenger " << i + 1 << " Age:" << age[i];
        }

        cout << "\n\nYour class: ";
        cout << clas;
        cout << "\n\nDate of reservation: " << d << "-" << m << "-" << y;
        cout << "\n\nYour concession category: " << con;
        cout << "\n\nYou must pay: " << amc << endl;
        cout << "***********************************************\n";
        cout << "***********************************************\n\n";
    }
};
class canc //Cancel
{
public:
    int pnr;             //PNR Number or Passenger Name Record
    int tno;             //Train Number
    char tname[100];     //Train Name
    char bp[10];         //Boarding Station
    char dest[100];      //Destination Station
    char pname[10][100]; //Passenger Name
    int age[20];         //Passenger Age
    char clas[10];       //Class
    int nosc;            //No. of Cancellations
    int d, m, y;
    float amr;
    void getcancdet() //Get cancellation details
    {
        cout << "Enter the details as follows\n";
        cout << "PNR no: ";
        cin >> pnr;
        cout << "Date of cancellation(DD MM YYYY): ";
        cin >> d >> m >> y;
        cout << "...........END OF GETTING DETAILS...........\n";
    }
    void displaycancdet() //display cancelled ticket details
    {
        cout << "...........................................\n";
        cout << "...........................................\n";
        cout << "PNR No:" << pnr;
        cout << "\n\nTrain No: " << tno;
        cout << "\nTrain Name: ";
        cout << tname;
        cout << "\n\nBoarding Point: ";
        cout << bp;

        cout << "\n\nDestination Point: ";
        puts(dest);
        cout << "\n\nYour class: ";
        puts(clas);
        cout << "\n\nNo of seats to be cancelled: " << nosc;

        for (int i = 0; i < nosc; i++)
        {
            cout << "\n\nPassenger " << i + 1 << " Name: ";
            cout << pname[i];
            cout << "\nPassenger " << i + 1 << " Age: " << age[i];
        }

        cout << "\n\nDate of cancellation: " << d << "-" << m << "-" << y;
        cout << "\n\nYou can collect: " << amr << "rs" << endl;
        cout << "*****************************************\n";
        cout << ".........END OF CANCELLATION.............\n";
        cout << "*****************************************\n";
    }
};

int main()
{
    int ch; //Choice
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    cout << ".......WELCOME TO RAILWAY RESERVATION SYSTEM..........\n";
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    do
    {
        cout << "......................MAIN MENU......................\n";
        cout
            << "1.Admin mode\n2.User mode\n3.Exit\n";
        cout << "Enter your choice: ";
        cin >> ch;
        cout << endl;
        switch (ch)
        {
        case 1:
            database(); //Admin Mode
            break;
        case 2:
            user(); //User Mode
            break;
        case 3:
            exit(0); //Exit
        }
    } while (ch < 3);
    return 0;
}

void database() //Admin Menu
{
    char password[15];
    const char *pass = "1234"; //Default Admin Password
    cout << "Enter the administrator password: ";
    cin >> password;
    detail a;                        //Train Record
    fstream f;                       //Train Detail File
    int ch;                          //Choice
    char c;                          //Continuation
    if (strcmp(pass, password) != 0) //Password Check
    {
        cout << "Enter the password correctly\n";
        cout << "You are not permitted to login in this mode\n";
    }
    if (strcmp(pass, password) == 0) //Password Matches
    {
        char c;
        do
        {
            cout << "...........ADMINISTRATOR MENU...........\n";
            cout << "1.Add Train Details in Database\n";
            cout << "2.Display All Trains Details\n3.User Management\n";
            cout << "4.Display All Reservations\n5.Display Cancellations\n6.Return to Main Menu\n";
            cout << "Enter your choice: ";
            cin >> ch;

            cout << endl;
            switch (ch)
            {
            case 1:
                f.open("trains.txt", ios::in | ios::out | ios::binary | ios::app); //open file in read, write, binary and append mode
                do
                {
                    a.getdetail();                  //Get Train Information from admin
                    f.write((char *)&a, sizeof(a)); //write train record to file
                    cout << "Do you want to add one more record?\n";
                    cout << "y-for Yes\nn-for No\n: ";
                    cin >> c;
                } while (c == 'y');
                f.close();
                break;
            case 2:
                cout << "Train No.\tTrain Name\tBoarding Station\tDestination Station\tFirst Class Seats\tFirst Class Fare\tSecond Class Seats\tSecond Class Fare\tDate\n";
                f.open("trains.txt", ios::in | ios::out | ios::binary | ios::app); //open file in read, write, binary and append mode
                f.seekg(0);                                                   //Seek read pointer to beginning of file
                while (f.read((char *)&a, sizeof(a)))                         //reads records one by one
                {
                    a.displaydetail(); //Display Train detail
                }
                f.close(); //Close file
                cout << "\n\n";
                break;
            case 3:
                manage(); //Add and See Users
                break;
            case 4:
                displaypassdetail(); //Display All Reservations
                break;
            case 5:
                displaycan(); //Display Cancellations
            }
        } while (ch < 6);

        f.close(); //Close file
    }
}

void displaycan() //Display Cancellations
{
    fstream f3;                                          //Cancel file
    canc c;                                              //Cancel Record
    f3.open("cancel.txt", ios::in | ios::out | ios::binary); //open file in read, write and binary mode
    f3.seekg(0);                                         //Seek read pointer to beginning of file
    while (f3.read((char *)&c, sizeof(c)))               //reads records one by one
    {
        c.displaycancdet(); //Displat Invidual Cancel Record
    }
    f3.close(); //Close File
}

void res()
{
    detail a;                                                      //Train Record
    reser b;                                                       //Reservation Record
    fstream f1, f2;                                                //Train and Reservation file
    time_t t;                                                      //Storing Calendar time
    f1.open("trains.txt", ios::in | ios::out | ios::binary);            //open file in read, write and binary mode
    f2.open("reservations.txt", ios::in | ios::out | ios::binary | ios::app); //open file in read, write, binary and append mode
    int ch;
    cout << "\nEnter Train No.: ";
    cin >> b.tno; //Choice

    while (f1.read((char *)&a, sizeof(a))) //reads records one by one
    {
        if (a.tno == b.tno) //Train No. Check
        {
            cout << "\nEnter Train No. again for confirmation\n";
            b.getresdet();              //Get Reservation details
            if (strcmp(b.clas, f) == 0) //if First class
            {
                if (a.c1 >= b.nosr) //Seats check
                {
                    strcpy(b.tname, a.tname); //Copy train name from train record to reservation record
                    amt = a.c1fare;
                    addr = f1.tellg(); //get read pointer location
                    ad = sizeof(a);
                    f1.seekp(addr - (ad)); //set write pointer one record back for updation
                    a.c1 = a.c1 - b.nosr;
                    f1.write((char *)&a, sizeof(a)); //Update Seats in Train Record
                    if (b.con == 1)
                    {
                        cout << "Concession category: MILITARY PERSONNEL\n";
                        b.amc = b.nosr * ((amt * 50) / 100); //50% concession
                    }
                    else if (b.con == 2)
                    {
                        cout << "Concession category: SENIOR CITIZEN\n";
                        b.amc = b.nosr * ((amt * 60) / 100); //60% concession
                    }
                    else if (b.con == 3)
                    {
                        cout << "Concession category: CHILDREN BELOW FIVE\n";
                        b.amc = 0.0; //Free
                    }
                    else if (b.con == 4)
                    {
                        cout << "You cannot get any concession\n";
                        b.amc = b.nosr * amt; //No Concession
                    }
                    srand((unsigned)time(&t));       //Initializes random number generator by seeding it. The srand() function sets the starting point for producing a series of pseudo-random integers. . time() returns a time_t value which vary everytime and hence the pseudo-random number vary for every program call.
                    b.pnr = rand();                  //rand() function is used in C to generate random numbers.
                    f2.write((char *)&b, sizeof(b)); //Add Record to Reservation file
                    b.displayresdet();               //Display Reservation details
                    cout << "------------------------------------------------------\n";
                    cout << "--------------Your ticket is reserved-----------\n";
                    cout << "-----------------End of reservation menu-------\n";
                }
                else //Seats full
                {
                    cout << "**********Sorry requested seats are not available********\n";
                }
            }
            else if (strcmp(b.clas, s) == 0) //if Second class
            {
                if (a.c2 >= b.nosr)
                {
                    strcpy(b.tname, a.tname); //Copy train name from train record to reservation record
                    amt = a.c2fare;
                    addr = f1.tellg(); //get read pointer location
                    ad = sizeof(a);
                    f1.seekp(addr - (ad)); //set write pointer one record back for updation
                    a.c2 = a.c2 - b.nosr;
                    f1.write((char *)&a, sizeof(a)); //Update Seats in Train Record
                    if (b.con == 1)
                    {
                        cout << "Concession category:MILITARY PERSONNEL\n";
                        b.amc = b.nosr * ((amt * 50) / 100); //50% concession
                    }
                    else if (b.con == 2)
                    {
                        cout << "Concession category:SENIOR CITIZEN\n";
                        b.amc = b.nosr * ((amt * 60) / 100); //60% concession
                    }
                    else if (b.con == 3)
                    {
                        cout << "Concession category:CHILDERN BELOW FIVE\n";
                        b.amc = 0.0; //Free
                    }
                    else if (b.con == 4)
                    {
                        cout << "You cannot get any concession\n";
                        b.amc = b.nosr * amt; //No Concession
                    }
                    srand((unsigned)time(&t));       //Initializes random number generator by seeding it. The srand() function sets the starting point for producing a series of pseudo-random integers. . time() returns a time_t value which vary everytime and hence the pseudo-random number vary for every program call.
                    b.pnr = rand();                  //rand() function is used in C to generate random numbers.
                    f2.write((char *)&b, sizeof(b)); //Add Record to Reservation file
                    b.displayresdet();               //Display Reservation details
                    cout << "---------------------------------------\n";
                    cout << "--------Your ticket is reserved--------\n";
                    cout << "------------End of reservation---------\n";
                }
                else
                {
                    cout << "********Sorry requested seats are not available*******\n";
                }
            }
            flag = 1;
            break;
        }
        else
        {
            flag = 0;
        }
    }
    if (flag == 0)
    {
        cout << "............Wrong train no......................\n";
        cout << "......Enter the train no from the data base.....\n";
    }
    f1.close();
    f2.close();
}
void displaypassdetail() // display reservations
{
    fstream f;                                         //Reservation file
    reser b;                                           //Reservation Record
    f.open("reservations.txt", ios::in | ios::out | ios::binary); //open file in read, write and binary mode
    f.seekg(0);                                        //Seek read pointer to beginning of file
    while (f.read((char *)&b, sizeof(b)))              //reads records one by one
    {
        b.displayresdet(); //Display individual record
    }
    f.close(); //Close fail
}
void enquiry() //enquire about train information
{
    cout << "Train No.\tTrain Name\tBoarding Station\tDestination Station\tFirst Class Seats\tFirst Class Fare\tSecond Class Seats\tSecond Class Fare\tDate\n";
    fstream f;                                         //Train file
    f.open("trains.txt", ios::in | ios::out | ios::binary); //open file in read, write and binary mode
    detail a;
    while (f.read((char *)&a, sizeof(a))) //reads records one by one
    {
        a.displaydetail(); //dispaly individual train record
    }
    f.close(); //Close file
}

void cancel() //cancel ticket
{
    detail a;                                                           //Train record
    reser b;                                                            //Reservation record
    canc c;                                                             //Cancel record
    int flagc = 0;                                                      //Not found status flag
    fstream f1, f2, f3, temp;                                           //Train, Reservation, cancellation and temp file
    f1.open("trains.txt", ios::in | ios::out | ios::binary);                 //open file in read, write and binary mode
    f2.open("reservations.txt", ios::in | ios::out | ios::binary);                 //open file in read, write and binary mode
    f3.open("cancel.txt", ios::in | ios::out | ios::binary | ios::app);     //open file in read, write, binary and append mode
    temp.open("temp.txt", ios::in | ios::out | ios::binary | ios::app); //open file in read, write, binary and append mode
    cout << "**********CANCELLATION MENU*********\n";
    c.getcancdet();                        //get cancel details
    while (f2.read((char *)&b, sizeof(b))) //reads records one by one
    {
        if (b.pnr == c.pnr) //PNR check
        {
            c.tno = b.tno;            //Copy Train no.
            strcpy(c.tname, b.tname); //Copy train name
            strcpy(c.bp, b.bp);       //Copy Boarding station
            strcpy(c.dest, b.dest);   //Copy Destination station
            c.nosc = b.nosr;          //Copy Seats
            for (int j = 0; j < c.nosc; j++)
            {
                strcpy(c.pname[j], b.pname[j]); //Copy Passeger name
                c.age[j] = b.age[j];            //Copy Passeger age
            }
            strcpy(c.clas, b.clas);     //Copy class
            if (strcmp(c.clas, f) == 0) //First class check
            {
                while (f1.read((char *)&a, sizeof(a))) //reads records one by one
                {

                    if (a.tno == c.tno)
                    {
                        a.c1 = a.c1 + c.nosc;
                        d = a.d;
                        m = a.m;
                        addr = f1.tellg(); //get read pointer location
                        ad = sizeof(a);
                        f1.seekp(addr - (ad));
                        f1.write((char *)&a, sizeof(a)); //Update Seats in Train Record
                        tamt = b.amc;

                        //Calculate deduction amount
                        if ((c.d == d) && (c.m == m))
                        {
                            cout << "You are cancelling at the date of departure\n";
                            c.amr = tamt - ((tamt * 60) / 100);
                        }
                        else if (c.m == m)
                        {
                            cout << "You are cancelling at the month of departure\n";
                            c.amr = tamt - ((tamt * 50) / 100);
                        }
                        else if (m > c.m)
                        {
                            cout << "You are cancelling one atleast month before the date of departure\n";
                            c.amr = tamt - ((tamt * 20) / 100);
                        }
                        else
                        {
                            cout << "Cancelling after the departure\n";
                            cout << "Your request cannot be completed\n";
                        }
                        c.displaycancdet(); //Display cancelled Record
                    }
                }
            }
            else if (strcmp(c.clas, s) == 0) //Second class check
            {
                while (f1.read((char *)&a, sizeof(a))) //reads records one by one
                {

                    if (a.tno == c.tno)
                    {
                        a.c2 = a.c2 + c.nosc;
                        d = a.d;
                        m = a.m;
                        addr = f1.tellg(); //get read pointer location
                        ad = sizeof(a);
                        f1.seekp(addr - (ad));
                        f1.write((char *)&a, sizeof(a)); //Update Seats in Train Record
                        tamt = b.amc;

                        //Calculate deduction amount
                        if ((c.d == d) && (c.m == m))
                        {
                            cout << "You are cancelling at the date of departure\n";
                            c.amr = tamt - ((tamt * 60) / 100);
                        }
                        else if (c.m == m)
                        {
                            cout << "You are cancelling at the month of departure\n";
                            c.amr = tamt - ((tamt * 50) / 100);
                        }
                        else if (m > c.m)
                        {
                            cout << "You are cancelling one month before the date of departure\n";
                            c.amr = tamt - ((tamt * 20) / 100);
                        }
                        else
                        {
                            cout << "Cancelling after the departure\n";
                            cout << "Your request cannot be completed\n";
                        }

                        c.displaycancdet(); //Display cancelled Record
                    }
                }
            }
            flagc = 1; //Found
        }
        else
        {
            if (flagc != 1)
            {
                flagc = 0; //Not found
            }
            temp.write((char *)&b, sizeof(b)); //Write every record except cancelled record
        }
    }
    if (flagc == 0)
    {
        cout << "\n\nEnter the correct PNR no\n\n";
    }
    f3.write((char *)&c, sizeof(c)); //Add record in cancel file
    f1.close();                      //Close files
    f2.close();
    f3.close();
    remove("reservations.txt");             //remove old Reservation File
    rename("temp.txt", "reservations.txt"); //renames temp to new Reservation file
}

void user()
{
    login a;   //User Record
    int flagu; //Not found status flag
    int ch;    //Choice
    cout << "*****************************************************\n";
    cout << "***********WELCOME TO THE USER MENU****************\n";
    cout << "****************************************************\n";
    char password[15]; //User Password

    fstream f;                                          //User file
    f.open("id.txt", ios::in | ios::out | ios::binary); //open file in read, write and binary mode
    char id[100];                                       //UserID
    cout << "Enter your id: ";
    cin >> id;

    cout << "Enter the password: ";
    cin >> password;
    while (f.read((char *)&a, sizeof(a))) //reads records one by one
    {
        if ((strcmp(a.id, id) == 0) && (strcmp(a.pass, password) == 0)) //login check
        {
            do
            {
                cout << "1.Reserve\n2.Cancel\n3.Enquiry\n4.Return to the main menu\n";
                cout << "Enter your choice:";
                cin >> ch;
                cout << endl;
                switch (ch)
                {
                case 1:
                    res(); //reserve ticket
                    break;
                case 2:
                    cancel(); //cancel ticket
                    break;
                case 3:
                    enquiry(); //enquire about train information
                    break;
                }
            } while (ch <= 3);

            return;
        }
        else
        {
            flagu = 1;
        }
    }
    if (flagu == 1)
    {
        cout << "Enter your user id and password correctly\n";
    }
}

void manage() //User Management
{
    int ch;    //Choice
    fstream f; //User file
    char c;    //Continuation
    login a;   //User Record
    cout << ".........WELCOME TO THE USER MANAGEMENT MENU........\n";
    do
    {
        cout << "1.Add User in Database\n";
        cout << "2.Display details\n3.Return to the main menu\n";
        cout << "Enter your choice:";
        cin >> ch;
        cout << endl;
        switch (ch)
        {
        case 1:
            f.open("id.txt", ios::in | ios::out | ios::binary | ios::app); //open file in read, write, binary and append mode
            do
            {
                a.getid();                      //Store UserID and password
                f.write((char *)&a, sizeof(a)); //Add to User file
                cout << "Do you want to add one more record\n";
                cout << "y-Yes\nn-No\n";
                cin >> c;
            } while (c == 'y');
            f.close(); //Close file
            break;

        case 2:
            f.open("id.txt", ios::in | ios::out | ios::binary); //open file in read, write and binary mode

            f.seekg(0); //Seek read pointer to beginning of file
            cout << "UserID\tPassword\n";
            while (f.read((char *)&a, sizeof(a))) //reads records one by one
            {
                a.displayid(); //Dispaly User Record
            }
            f.close(); //Close file
            break;
        }
    } while (ch < 3);
}
