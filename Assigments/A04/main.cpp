/*****************************************************************************
*                    
*  Author:           Miguel Mendoza
*  Email:            miguelmen.1017@gmail.com   
*  Label:            A03
*  Title:            Basic Project Organization
*  Course:           2143 OOP
*  Semester:         Fall 2022  
* 
*  Description:A Circular Queue is a special version of queue where the last element of the Queue is  connected to the first element of 
    the queue forming a circle
*      
* 
*  Usage:
*        You can Just Press Run and it will run whats inside of main.
* 
*  Files:            Main.cpp, A04.txt
*****************************************************************************/
#include <iostream>

using namespace std;

//Starts Class Name With Attributes which contain Pointers
class CircularArrayQue {
private:
    int *Container;
    int Front;
    int Rear;
    int QueSize; // items in the queue
    int CurrentSize;
    void init(int size = 0) {
        Front = Rear = CurrentSize = 0;
        QueSize = size;
    }
    // Bool Function To return true false
    bool Full() {
        return CurrentSize == QueSize;
    }
//Acsess specifiers with Constructors 
public:
    CircularArrayQue() {
        Container = new int[10];
        init(10);
    }
    CircularArrayQue(int size) {
        Container = new int[size];
        init(size);
    }
    //This Function Will Enqueue(Push)
    void Push(int item) {
        if (!Full()) {
            Container[Rear] = item;
            Rear = (Rear + 1) % QueSize;
            CurrentSize++;
        } else {
            cout << "FULL!!!!" << endl;
        }
    }
    //This Function Will Dequeue(Pop)
    int Pop() {
        int temp = Container[Front];
        Front = (Front + 1) % QueSize;
        CurrentSize--;
        return temp;
    }
    friend ostream &operator<<(ostream &os, const CircularArrayQue &other);
};

ostream &operator<<(ostream &os, const CircularArrayQue &other) {

    for (int i = other.Front; i < other.CurrentSize; i = (i + 1) % other.QueSize) {
        os << other.Container[i] << " ";
    }
    os << endl;
    return os;
}

/**
 * Main Driver
 * 
 * For this program, the main driver was used to test the CircularArrayQue class
 * 
 */
int main() {
    CircularArrayQue C1(5);

    // C1.Push(34);
    // C1.Push(38);
    // C1.Push(44);
    // C1.Push(22);
    // C1.Push(99);
    // C1.Push(100);

    C1.Push(1);
    C1.Push(2);
    C1.Push(3);
    // C1.Push(6);
    // C1.Push(7);
    cout << C1 << endl;

    // C1.Push(1);
    // C1.Push(2);
    // C1.Push(3);

    cout << C1 << endl;
}
