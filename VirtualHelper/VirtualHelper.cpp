// VirtualHelper.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Variables for storing the user's inputs
string us;
string subject;
string info;
string userIn;
string userIn2 = "yes";
void AIHelper()
{
    fstream iFile("input.txt");
QUESTION:
    cout << "Read or Write mode?\n";
    cin >> userIn;
    // display everything the user has told the ai helper
    if (userIn == "read")
    {
        iFile.open("myText");
        string line;
        while (getline(iFile, line))
        {
            cout << line << endl;
        }
        // close the file
        iFile.close();
    }
    // Store info for the ai to remember
    else if (userIn == "write")
    {
        iFile.open("myText", ios::out| ios :: in|ios::app);
        // ask for the user's name
        cout << "What is your name?\n";
        cin >> us;
        cout << "Hello " << us << endl;
        // choose what type of information the ai needs to store
        HELP:
        cout << "What do you want me to remember?\n";
        cout << "Available commands: age, item, shopping, appointment, other.\n ";
        cin >> subject;
        // Remember a certain person's age
        if (subject == "age")
        {
            subject.append(" ");
            cout << "Who's age do you want me to remember?\n";
            string age;
            cin >> age;
            cout << "\n How old is " << age << "?\n";
            cin >> info;
            cout << "\n I will remember that " << age << " is currently " << info << " years old.\n";
            subject.append(age);
            subject.append(" ");
            subject.append(info);
        }
        // remember where an item was placed
        else if (subject == "item")
        {
            subject.append(" ");
            cout << "What item do you want me to remember?\n";
            string item;
            cin >> item;
            cout << "\n Where is the " << item << " placed?\n";
            cin >> info;
            cout << "\n I will remember " << item << " is currently place in/on the " << info << endl;
            subject.append(item);
            subject.append(" ");
            subject.append(info);
        }
        // remember where an item was placed
        else if (subject == "appointment")
        {
            subject.append(" ");
            cout << "Where is the appoinment?\n";
            string appointment;
            cin >> appointment;
            cout << "\n What time does the appointment start?\n";
            cin >> info;
            cout << "I will remember that you have an appointment scheduled for " << appointment << " at " << info << endl;
            subject.append(appointment);
            subject.append(" ");
            subject.append(info);
        }
        // remember an item the user needs to buy
        else if (subject == "shopping")
        {
            subject.append(" ");
            cout << "What do need to buy?\n";
            cin >> info;
            cout << "\n I will remember that you need to buy " << info << endl;
            subject.append(info);

            subject.append("\n");
        }
        // remember another piece of information
        else if (subject == "other")
        {
            subject.append(" ");
            cout << "What did you want me to remember?\n";
            string other;
            cin >> other;
            cout << "\n What do you want me to remember about the " << other << "?\n";
            cin >> info;
            cout << "I will remember " << other << " and " << info << endl;
            subject.append(other);
            subject.append(" ");
            subject.append(info);
        }
        // if the user misspells, immediatley give them another chance to issue a command
        else
        {
            cout << "Invalid response\n";
            goto HELP;
        }
        // store the information and close the file
        subject.append("\n");
        iFile << subject;

        iFile.close();
    }
    else
    {
        cout << "Invalid response, please type yes or no.\n";
        goto QUESTION;
    }
}
int main()
{
    while (userIn2 != "no")
    {
        AIHelper();
        CONTINUE:
        cout << "Would you like to continue?\n";
        cin >> userIn2;
        if (userIn2 != "yes" && userIn2 != "no")
        {
            cout << "Invalid response. Type yes or no\n";
            goto CONTINUE;
        }
    }
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
