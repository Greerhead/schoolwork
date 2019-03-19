#include <iostream>
#include <cstring>
#include <time.h>
#include <stdlib.h>

using namespace std;

class Horse {
  private:
    int position;
  public:
    Horse(){
        position = 0;
    }
	void advance(){
	    int a;
	    a = rand() % 2;
        if (a == 1){
                position ++;
        }
	}
	int getPosition(){
		return position;
	}//end getPos
}; // end class def

class Race {
  private:
    Horse h[5];
  public:
    int length;
   // Race();
    Race(int newLength);
    void printLane(int horseNum);
    void start();

}; // end class def

//Race::Race(){
  //  length = 10;
   // h = new Horse[5];

}
Race::Race(int newLength){
    length = newLength;
    //h = new Horse[5];
}
void Race::printLane(int horseNum){
    int v;
    for (v = 0 ; v < length; v++){
        if (v == h[horseNum].getPosition()){
            cout << horseNum;
        }//end if
        else {
            cout << ".";
        }//end else
    }//end for
    cout << endl;
}//end printLane
void Race::start(){
    int horseNum;
    bool keepGoing = true;
    while (keepGoing == true){
        for (horseNum = 0; horseNum < 5; horseNum ++){
            h[horseNum].advance();
            printLane(horseNum);
            //cout << h[horseNum].getPosition();
            if (h[horseNum].getPosition() == Race::length){
                cout << "Horse " << horseNum  << " wins" << endl;
                keepGoing = false;
            }//end if

        }//end for
        cout<< "press enter to continue"<<endl;
            cin.ignore();
    }//end while
}//end race

int main(){
    srand(time(NULL));
    Race r;
    r.start();
    return 0;
}
