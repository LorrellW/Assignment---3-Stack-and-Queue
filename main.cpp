//Lorrell Winfield 
//Assignment - 3 (Queue)
//17 APR 2023
//main.cpp

#include "pch.h"

using namespace std;

int main(){
    cout << "  *********************" << endl; // Print name of program
    cout << "  **  Queue creator  **" << endl;
    cout << "  *********************" << endl;

    Queue q;                                   //Create instance of Queue 
        int user = 0, value;
    
        while (user != 6) {                    //Print menu to screen 
            cout << "------------" << endl;  
            cout << "1 - Add (rear)" << endl;
            cout << "2 - Remove & Return (front)" << endl;
            cout << "3 - View 1st value" << endl;
            cout << "4 - Is Empty?" << endl;
            cout << "5 - Size of Queue" << endl;
            cout << "6 - Quit" << endl;
            cout << "------------" << endl;
            cout << "-->:";
            
            cin >> user;                    //Get user input
            switch (user) {                 //User input will define switch cases
            case 1:
                cout << "Enter the value to add: ";
                cin >> value;
                q.enqueue(value);
                break;
            case 2:
                cout << "Value removed: " << q.dequeue() << endl;
                break;
            case 3:
                cout << "1st value: " << q.peek() << endl;
                break;     
            case 4:
                if (q.isEmpty()) {
                    cout << "Queue is empty." << endl;
                }
                else {
                    cout << "Queue is NOT empty." << endl;
                }
                break;
            case 5:
                cout << "Size: " << q.size() << " element(s) in Queue" << endl;
                break;    
            case 6:
                cout << endl << endl << "    ****************" << endl;    //Print exit menu to the screen
                cout << "    **  GoodBye!  **" << endl;
                cout << "    ****************" << endl;
                break;
            default:
                cout << "Invalid choice." << endl;
                break;
            }
        }
        cout << endl;
    
    
    }

