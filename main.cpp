#include <iostream>
#include <vector>
#include <time.h>


using namespace std;


int main() {
    double probability;
    int no_of_nuclei=0;
    int time_=0;
    double num=0;
    int j=0,n=0;

    cout << "Enter number of nuclei: ";
    cin >> no_of_nuclei;

    cout << "Enter the probability for decay: ";
    cin >> probability;

    cout << "Enter time in seconds: ";
    cin >> time_;

    cout << endl;
    cout << "No. " << endl;
    
    srand(time(0));
    while(n!=no_of_nuclei) {
        if(n<9) cout << " " << n+1 << ": ";
        else cout << n+1 << ": ";
        while(j!=time_) {
            num = (rand() % 100 +1)/100.0;
            if(num>=probability) {
                if((static_cast<int>(num*100)%10)==0)
                cout << num << "   ";
                else cout << num << "  ";
                j++;
            }
            else {
                if((static_cast<int>(num*100)%10)==0)
                cout << num << "   ";
                else cout << num << "  ";
                j=time_;
                break;
            }
        }
        cout << endl;
        j=0;
        n++;
    }
    
    
        char c;
        cout << "Enter q to quit." << endl;
        while(true) {
        cin >> c;
        if(c=='q' || c=='Q') 
        return 0;
        else cout << "Enter q." << endl;
    }
    
}