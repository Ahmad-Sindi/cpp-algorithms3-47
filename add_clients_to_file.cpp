#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

/*
 * Algorithm Challenge – Level 3 | #47 Add Clients Data to Text File
 *
 * This program demonstrates how to collect client information from the user, convert the data into a single formatted text line, and store it permanently inside a text file.
 *
 * The algorithm represents a real-world file-based system where:
 *   - Data is entered manually
 *   - Records are serialized into text format
 *   - Each client is stored as a single line in a file
 *
 * This approach is widely used in legacy systems and lightweight applications where databases are not required.
 */

// Global variable that stores the file name
const string ClientFileName = "Clients.txt";

// Structure that represents a client record
struct ClientStructData
{
    string AccountNumber;
    string PinCode;
    string Name;
    string Phone;
    double AccountBalance;
};

// Reads client data from the user
ClientStructData ReadClientData()
{
    ClientStructData ClientData;

    cout << "Enter Account Number : ";
    getline(cin >> ws, ClientData.AccountNumber); 
    // std::ws is used to ignore leftover whitespace in the input buffer

    cout << "Enter Pin Code       : ";
    getline(cin, ClientData.PinCode);

    cout << "Enter Full Name      : ";
    getline(cin, ClientData.Name);

    cout << "Enter Phone Number   : ";
    getline(cin, ClientData.Phone);

    cout << "Enter Account Balance: ";
    cin >> ClientData.AccountBalance;

    return ClientData;
}

// Converts a client record into a single text line
string ConvertRecordToLine(ClientStructData Client, string Separator = "#//#")
{
    string ClientRecord = "";

    ClientRecord += Client.AccountNumber + Separator;
    ClientRecord += Client.PinCode + Separator;
    ClientRecord += Client.Name + Separator;
    ClientRecord += Client.Phone + Separator;
    ClientRecord += to_string(Client.AccountBalance);

    return ClientRecord;
}

// Writes a single line of client data to the file
void AddClientDataLineToFile(string FileName, string DataLine)
{
    fstream FileClientData;
    FileClientData.open(FileName, ios::out | ios::app);

    if (FileClientData.is_open())
    {
        FileClientData << DataLine << endl;
        FileClientData.close();
    }
}

// Handles adding one new client
void AddNewClient()
{
    ClientStructData Client;

    Client = ReadClientData();
    AddClientDataLineToFile(ClientFileName, ConvertRecordToLine(Client));
}

// Allows adding multiple clients
void AddClients()
{
    char AddMore = 'Y';

    do
    {
        system("cls"); // Clear console screen (Windows only)

        cout << "Add New Client\n";
        cout << "----------------------\n";

        AddNewClient();

        cout << "\nClient added successfully.\n";
        cout << "Do you want to add more clients? (Y/N): ";
        cin >> AddMore;

    } while (toupper(AddMore) == 'Y');
}

int main()
{
    AddClients();
    return 0;
}
