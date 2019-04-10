#include <iostream>

using namespace std;

int main(){

    int counter = 0;
    double totalScores = 0.0;
    bool isFinished = false;

    cout << "Enter 0 to stop program" << endl;
    while(!isFinished){

        string input;
        cout << "Enter a test score: ";
        cin >> input;

        double score = stod(input);
        isFinished = (score==0);

        if(!isFinished){
            totalScores += score;
            counter++;
        }
    }

    cout << "Read " << counter << " scores in total." << endl;
    cout << "Average score is " << (totalScores/counter) << endl;


    return 0;
}