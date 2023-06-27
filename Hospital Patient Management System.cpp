/* This program is a Patient Management System for
*  a hospital to manage a huge number of patients.
*  This system ensure timely patient care and medical history.
*  This ystem ensure doctors are not overburdened with too many patients.
*
*  Created by: Group C++
*  Last edited: 03/09/2021
*/

//Preprocessor Directives
#include <iostream>
#include <iomanip>
#include <fstream>
#include <climits>
#include <string>
using namespace std;

//Struct Definition
typedef struct
{
    string patient_id;
    string pat_name;
    int patient_age;
    string patient_add;
    string attending_doc;
    string diagnosis;
    string patient_stat;
    char consult_date[31];
} patient_info;

// Function Prototype
void welcome_screen();
int header();
char selection();
void read_input(patient_info data[], int loop_count);
void patient_ID(patient_info data[], int loop_count);
void patient_NAME(patient_info data[], int loop_count);
void patient_AGE(patient_info data[], int loop_count);
void patient_ADD(patient_info data[], int loop_count);
void attending_DOC(patient_info data[], int loop_count);
void Diagnosis(patient_info data[], int loop_count);
void patient_STAT(patient_info data[], int loop_count);
void consult_DATE(patient_info data[], int loop_count);
void output_data(patient_info data[], int loop_count);
void showList(patient_info data[], int loop_count);
void deleteInfo(patient_info data[], int loop_count);
void editInfo(patient_info data[], int loop_count);
//Advance search
void getMatch(patient_info data[], int loop_count);

// Main Function
int main()
{
    welcome_screen();    // Call function to display welcome screen

    int a = 0, choice;
    patient_info data[30];
    do
    {
        choice = header();    // Call function to display header

        if (choice == 1) {
            char select;
            bool right;
            right = true;
            system("CLS");

            select = selection();
            while (right == true) {

                if (select == 'N' || select == 'n') {
                    system("CLS");
                    read_input(data, a);   // Call function to read input from user
                    a++;
                    right = false;

                }
                else if (select == 'E' || select == 'e') {
                    system("CLS");
                    getMatch(data, a);   // Call function to advance searching patient
                    editInfo(data, a);   // Call function to add/edit patient info
                    right = false;
                }
                else {
                    cout << "Error input\n";
                    cout << "Enter option(N/E)>>";
                    cin >> select;
                }
            }
        }
        else if (choice == 2) {
            getMatch(data, a);    // Call function to advance searching patient
            deleteInfo(data, a);  // Call function to delete patient info
            system("CLS");
        }
        else if (choice == 3) {
            getMatch(data, a);   // Call function to advance searching patient
            editInfo(data, a);   // Call function to edit patient info
            cout << endl;
            system("CLS");
        }
        else if (choice == 4) {
            showList(data, a);   // Call function to show patient list
            cout << endl;
            system("PAUSE");
        }
        else if (choice == 5) {
            getMatch(data, a);
            system("PAUSE");
            system("CLS");
        }
        else if (choice == 6) {
            output_data(data, a);   // Call function to output data into a text file
            cout << "Successfully updated to PatientInfo.txt" << endl;
            break;
            system("CLS");
        }
        else
        {
            cout << "Error Enter. Try again.\n";
            system("PAUSE");
        }
    } while (true);

    return 0;
}

// Function Definition//
// Welcome Screen
void welcome_screen()
{
    cout << "*********************************************" << endl;
    cout << "*   This is a Patient Management System     *" << endl;
    cout << "*   ------ Created by: Group C++ ------     *" << endl;
    cout << "*********************************************" << endl << endl;

    system("PAUSE");
    system("CLS");
}

// Header
int header()
{
    system("CLS");
    int choice;
    cout << "(1) Add patient information\n";
    cout << "(2) Delete patient information\n";
    cout << "(3) Update/Edit patient information\n";
    cout << "(4) List\n";
    cout << "(5) Advcance Search\n";
    cout << "(6) Exit\n";
    cout << ">>";
    cin >> choice;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return choice;

}

// Selection in Add Patient Function
char selection()
{
    char select;
    cout << "(N) New patient\n";
    cout << "(E) Existing patient\n";
    cout << "Enter option(N/E)>>";
    cin >> select;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return select;
}

// Read data input Function
void read_input(patient_info data[], int loop_count)
{
    patient_ID(data, loop_count);
    patient_NAME(data, loop_count);
    patient_AGE(data, loop_count);
    patient_ADD(data, loop_count);
    attending_DOC(data, loop_count);
    Diagnosis(data, loop_count);
    patient_STAT(data, loop_count);
    consult_DATE(data, loop_count);
}

// Input Patient ID
void patient_ID(patient_info data[], int loop_count)
{
    bool correct_entry;
    do
    {
        cout << "Key in the ID of the patient (Eg. UMMY123456): ";
        cin >> data[loop_count].patient_id;
        correct_entry = true;

        if (data[loop_count].patient_id.length() > 10 || data[loop_count].patient_id.length() < 10)
        {
            correct_entry = false;
            cout << "Error input. Try again.\n";
        }
        else
        {
            for (int a = 0; a < 4; a++)
            {
                for (int i = 4; i < 10; i++)
                    if (isalpha(data[loop_count].patient_id[i]))
                        correct_entry = false;

                if (isdigit(data[loop_count].patient_id[a]))
                    correct_entry = false;
                else
                    data[loop_count].patient_id[a] = toupper(data[loop_count].patient_id[a]);
            }
            if (correct_entry == false)
                cout << "Error input. Try again.\n";
        }

    } while (correct_entry != true);
}

// Input Patient Name
void patient_NAME(patient_info data[], int loop_count)
{
    bool correct_entry;
    do
    {
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Key in the name of the patient: ";
        getline(cin, data[loop_count].pat_name);

        correct_entry = true;
        for (int a = 0; a < data[loop_count].pat_name.length(); a++)
        {
            if (isdigit(data[loop_count].pat_name[a]))
                correct_entry = false;
            else
                data[loop_count].pat_name[a] = toupper(data[loop_count].pat_name[a]);
        }
        if (correct_entry == false)
            cout << "Error input. Try again.\n";
    } while (correct_entry != true);
}

// Input Patient Age
void patient_AGE(patient_info data[], int loop_count)
{
    cout << "Enter patient's age: ";
    cin >> data[loop_count].patient_age;
    while (!(int)data[loop_count].patient_age) {
        cout << "Error input. Try again\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Enter patient's age:";
        cin >> data[loop_count].patient_age;
    }
}

// Input Patient Address
void patient_ADD(patient_info data[], int loop_count)
{
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Enter patient's address: ";
    getline(cin, data[loop_count].patient_add);
}

// Choose Attending Doctor
void attending_DOC(patient_info data[], int loop_count)
{
    string line, name;
    ifstream myfile;
    myfile.open("doctorlist.txt");
    getline(myfile, line);
    cout << "Attending doctor: ";
    cout << line << endl;
    data[loop_count].attending_doc = line;
    ofstream temp;
    temp.open("temp.txt");
    while (getline(myfile, line)) {
        if ((line.substr(0, data[loop_count].attending_doc.size()) != data[loop_count].attending_doc))
            temp << line << endl;
    }
    temp << data[loop_count].attending_doc;

    myfile.close();
    temp.close();
    remove("doctorlist.txt");
    rename("temp.txt", "doctorlist.txt");
}

// Input Diagnosis
void Diagnosis(patient_info data[], int loop_count)
{
    cout << "Enter diagnosis: ";
    getline(cin, data[loop_count].diagnosis);
}

// Input Patient Status
void patient_STAT(patient_info data[], int loop_count)
{
    cout << "Enter patient status(inpatient/outpatient): ";
    cin >> data[loop_count].patient_stat;
    while (data[loop_count].patient_stat != "inpatient" && data[loop_count].patient_stat != "outpatient") {
        cout << "Wrong input, Enter again>>\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << " Enter patient status(inpatient/outpatient):";
        cin >> data[loop_count].patient_stat;
    }
}

// Input Consult Date
void consult_DATE(patient_info data[], int loop_count)
{
    int day;
    int month;
    int year;
    cout << "Enter consultation date: ";
    cin >> data[loop_count].consult_date;
    do {
        if (strlen(data[loop_count].consult_date) < 10 || strlen(data[loop_count].consult_date) > 10) {
            cout << "Error input. Input format should be dd/mm/yyyy\n";
            cout << "Enter consultation date: ";
            cin >> data[loop_count].consult_date;
        }
    } while (strlen(data[loop_count].consult_date) < 10 || strlen(data[loop_count].consult_date) > 10);
    char m[3], d[3], y[5];
    int i, j;
    for (i = 0; i < 2; i++)
        d[i] = data[loop_count].consult_date[i];

    for (i = 3, j = 0; i < 5; i++, j++) {
        m[j] = data[loop_count].consult_date[i];
    }
    for (i = 6, j = 0; i < 10; i++, j++) {
        y[j] = data[loop_count].consult_date[i];
    }
    day = atoi(d);
    month = atoi(m);
    year = atoi(y);
    if ((month == 1) || (month == 3) || (month == 5) || (month == 7) ||
        (month == 8) || (month == 10) || (month == 12))
    {
        while (day > 31 || day < 0) {
            cout << "Invalid date. Enter again\n";
            cout << "Enter consultation date: ";
            cin >> data[loop_count].consult_date;
        }
    }
    else if ((month == 4) || (month == 6) || (month == 9) || (month == 11))
    {
        while (day > 30) {
            cout << "Invalid date. Enter again\n";
            cout << "Enter consultation date: ";
            cin >> data[loop_count].consult_date;
        }
    }
    else if ((month == 2) && (year % 4 == 0))
    {
        while (day > 29) {
            cout << "Invalid date. Enter again\n";
            cout << "Enter consultation date: ";
            cin >> data[loop_count].consult_date;
        }
    }
    else if ((month == 2) && (year % 4 != 0))
    {
        while (day > 28) {
            cout << "Invalid date. Enter again\n";
            cout << "Enter consultation date: ";
            cin >> data[loop_count].consult_date;
        }
    }
    while (month < 1 || month >12) {
        cout << "Invalid date. Enter again\n";
        cout << "Enter consultation date: ";
        cin >> data[loop_count].consult_date;
    }
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

// Output to "PatientInfo.txt"
void output_data(patient_info data[], int loop_count)
{
    ifstream inData("PatientInfo.txt");
    ofstream outData("PatientInfo.txt", ios::app);
    for (int a = 0; a < loop_count; a++) {
        outData << "Patient ID: " << data[a].patient_id << endl;
        outData << "Name: " << data[a].pat_name << endl;
        outData << "Age: " << data[a].patient_age << endl;
        outData << "Address: " << data[a].patient_add << endl;
        outData << "Doctor's name: " << data[a].attending_doc << endl;
        outData << "Diagnosis report: " << data[a].diagnosis << endl;
        outData << "Status: " << data[a].patient_stat << endl;
        outData << "Consultation date: " << data[a].consult_date << endl << endl;
    }
    outData.close();
}

// Show Patient List
void showList(patient_info data[], int loop_count)
{
    cout << "Patient ID    |       Name       |  Age  |   Consultation Date  |      Doctor      |    Diagnosis    |   Status   |    Address    " << endl;
    for (int b = 0; b < loop_count; b++)
    {
        cout << setw(16) << left << data[b].patient_id << setw(20) << data[b].pat_name << setw(10) << data[b].patient_age << setw(20) << data[b].consult_date
            << setw(23) << data[b].attending_doc << setw(14) << data[b].diagnosis << setw(15) << data[b].patient_stat << setw(20) << data[b].patient_add << endl;
    }
}

// Delete Patient Info
void deleteInfo(patient_info data[], int loop_count)
{

    char del_pat_name[50];
    bool correct_entry = false;
    do {
        cout << "Enter patient name to be deleted: " << endl;
        cin.get(del_pat_name, 50);
        for (int a = 0; a < strlen(del_pat_name); a++)
            del_pat_name[a] = toupper(del_pat_name[a]);
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        for (int h = 0; h < loop_count; h++)
            if (del_pat_name == data[h].pat_name) {
                for (int i = h; i < loop_count; i++) {
                    data[i].patient_id = data[i + 1].patient_id;
                    data[i].pat_name = data[i + 1].pat_name;
                    data[i].patient_age = data[i + 1].patient_age;
                    data[i].patient_add = data[i + 1].patient_add;
                    data[i].attending_doc = data[i + 1].attending_doc;
                    data[i].diagnosis = data[i + 1].diagnosis;
                    data[i].patient_stat = data[i + 1].patient_stat;
                    memset(data[i].consult_date, ' ', sizeof(data[i].consult_date));
                    for (int a = 0; a < strlen(data[i].consult_date); a++)
                        data[i].consult_date[a] = data[i + 1].consult_date[a];
                }
            }
        data[loop_count - 1].patient_id = "";
        data[loop_count - 1].pat_name = "";
        data[loop_count - 1].patient_age = NULL;
        data[loop_count - 1].patient_add = "";
        data[loop_count - 1].attending_doc = "";
        data[loop_count - 1].diagnosis = "";
        data[loop_count - 1].patient_stat = "";
        memset(data[loop_count - 1].consult_date, ' ', sizeof(data[loop_count - 1].consult_date));
        correct_entry = true;

        if (correct_entry == false) {
            cout << "The patient name was not found,please key in again:" << endl;
        }
    } while (correct_entry == false);
    cout << "Succesfully deleted" << endl;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

// Edit Patient Info
void editInfo(patient_info data[], int loop_count)
{
    int choice;
    string doctor;
    char editInput[50], doc_choice;


    cout << "Enter patient name or patient ID to edit information: ";;
    cin.get(editInput, 50);
    for (int a = 0; a < strlen(editInput); a++)
        if (isalpha(editInput[a]))
            editInput[a] = toupper(editInput[a]);
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    system("CLS");

    for (int i = 0; i < loop_count; i++)
    {
        if (editInput == data[i].pat_name || editInput == data[i].patient_id) {
            loop_count = i;
            do {
                cout << "Enter number (1)-(9) to edit:\n";
                cout << "(1) Patient ID\n(2) Name\n(3) Age\n(4) Address\n(5) Doctor's name\n(6) Diagnosis report\n(7) Patient status\n(8) Consultation date\n(9) End" << endl;
                cin >> choice;

                if (choice == 1)
                {
                    patient_ID(data, loop_count);     // Call function to Input Patient ID
                    system("CLS");
                }
                else if (choice == 2)
                {
                    patient_NAME(data, loop_count);   // Call function to Input Patient Name
                    system("CLS");
                }
                else if (choice == 3)
                {
                    patient_AGE(data, loop_count);    // Call function to Input Patient Age
                    system("CLS");
                }
                else if (choice == 4)
                {
                    patient_ADD(data, loop_count);   // Call function to Input Patient Address
                    system("CLS");
                }
                else if (choice == 5) {
                    cout << "Attending doctor: " << data[i].attending_doc << endl;
                    cout << "Want to change doctor?(y/n)" << endl;
                    cin >> doc_choice;
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    if (doc_choice == 'Y' || doc_choice == 'y') {
                        cout << "Enter Doctors name: ";
                        getline(cin, doctor);
                        data[i].attending_doc = doctor;
                        cout << "New attending doctor: " << data[i].attending_doc;
                        cout << endl << endl;

                    }
                    system("CLS");
                }
                else if (choice == 6)
                {
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    Diagnosis(data, loop_count);      // Call function to Input Patient Diagnosis
                    system("CLS");
                }
                else if (choice == 7)
                {
                    patient_STAT(data, loop_count);   // Call function to Input Patient Status
                    system("CLS");
                }
                else if (choice == 8)
                {
                    consult_DATE(data, loop_count);   // Call function to Input Patient Consult Date
                    system("CLS");
                }
                else if (choice == 9)
                {
                    cout << "Successful Edited.\n";
                    system("PAUSE");
                }
            } while (choice != 9);
        }
    }

}

//Advance Search
void getMatch(patient_info data[], int loop_count)
{
    string userInput;
    bool correct_entry;
    correct_entry = false;
    do {
        cout << "Search for patient ID or patient name: ";
        getline(cin, userInput);

        for (int a = 0; a <= userInput.length(); a++)
            if (isalpha(userInput[a]))
                userInput[a] = toupper(userInput[a]);
        for (int a = 0; a < loop_count; a++)
        {
            std::size_t contains_id = data[a].patient_id.find(userInput);
            std::size_t contains_name = data[a].pat_name.find(userInput);
            if (contains_id != std::string::npos) {
                cout << data[a].patient_id << endl;
                correct_entry = true;
            }
            else if (contains_name != std::string::npos) {
                cout << data[a].pat_name << endl;
                correct_entry = true;
            }
        }
        if (correct_entry == false)
            cout << "No entry available.\n";

    } while (correct_entry != true);

}

