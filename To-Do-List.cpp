#include <iostream>
#include <string>
#include <bits/stdc++.h>
#include <limits>
using namespace std;

class ToDo {
protected:
    vector<string> tasks;

public:
    bool isEmpty() {
        if (tasks.empty()) {
            cout << "NO task added\n";
            return true;
        } else {
            return false;
        }
    }

    void addTask(string task) {
        tasks.push_back(task);
        cout << "Task Added" << endl;
    }

    void showAll() {
        if (tasks.empty()) {
            cout << "No Task Added\n" << endl;
            return;
        }
        for (int i = 0; i < tasks.size(); i++) {
            cout << i << ":" << tasks[i] << endl;
        }
    }

    void removeTask(int index) {
        if (tasks.empty()) {
            cout << "No Task Added\n" << endl;
            return;
        } else {
            if (index < 0 || index > tasks.size() - 1) {
                cout << "enter valid task number\n" << endl;
            } else if (index >= 0 && index < tasks.size()) {
                tasks.erase(tasks.begin() + index);
                cout << "Task Removed\n" << endl;
            }
        }
    }
};

class Done : public ToDo {
private:
    vector<string> completed;

public:
    void markComplete(int index) {
        if (tasks.empty()) {
            cout << "No task Added\n" << endl;
            return;
        } else {
            if (index < 0 || index > tasks.size() - 1) {
                cout << "enter valid task number\n" << endl;
            } else if (index >= 0 && index < tasks.size()) {
                completed.push_back(tasks[index]);
                cout << "Task Marked as Completed \n" << endl;
                tasks.erase(tasks.begin() + index);
            }
        }
    }

    void showCompleted() {
        if (completed.empty()) {
            cout << "No Task completed\n" << endl;
        } else {
            cout << "YAYY you completed these tasks\n" << endl;
            for (int i = 0; i < completed.size(); i++) {
                cout << i << ":" << completed[i] << endl;
            }
        }
    }
};
int main(){
    Done Mytasks;   

    while(1){
        cout<<endl;
        cout<<"To-Do-List"<<endl;
        cout<<"1- Add a Task"<<endl;
        cout<<"2- Mark Task Completed"<<endl;
        cout<<"3- show All Tasks"<<endl;
        cout<<"4- Remove Task"<<endl;
        cout<<"5- Show completed Tasks"<<endl;
        cout<<"6- Quit\n"<<endl;
        int num;
        cout<<"Enter the number from 1 to 6 :";
        cin>>num;
        cout<<"\n";

        switch(num){
        case 1: {
            string task;
            cout<<"Add Tasks \n"<<endl;
            cin.ignore();
            getline(cin,task);
            Mytasks.addTask(task);
            break;
        }
        case 2:{
            if(Mytasks.isEmpty()) break;
            Mytasks.showAll();
            int index;
            cout<<"enter index of task to mark completed :";
            cin>>index;
            cout<<"\n";
            Mytasks.markComplete(index);   
            break;
        }
        case 3:{
            cout<<"Here are your all incomplete Tasks\n"<<endl;

            Mytasks.showAll();
            break;
        }
        case 4:{
            if(Mytasks.isEmpty()) break;
            Mytasks.showAll();
            int idx;
            cout<<"enter index of task to remove:";
            cin>>idx;
            cout<<"\n";
            Mytasks.removeTask(idx);
            break;
        }
        case 5:{
            Mytasks.showCompleted();   
            break;
        }
        case 6:{
            cout<<"Ending the TO-Do-List\n"<<endl;
            return 0;
        }
        default:
            cout<<"Enter a valid number between 1 and 6"<<endl;
        }
    }
}

