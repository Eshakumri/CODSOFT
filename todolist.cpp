#include <iostream>
#include <string>
#include <list>
#include <ctime>
using namespace std;
class todolist
{
private:
    int id;
    string description;

public:
    bool completed;
    todolist() : id(0), description(" "), completed(false) {}
    ~todolist() = default;
    bool create(string new_description)
    {
        id = rand() % 100 + 1;
        description = new_description;
        return true;
    }
    int getid() { return id; }
    string getdescription() { return description; }
    bool iscompleted() { return completed; }
    void setcompleted(bool val) { completed = val; }
};

int main()
{
    int choice;
    int input_id;
    int tasknumber;
    string input_description;
    list<todolist> todolists;

    list<todolist>::iterator it;
    srand(time(0));

    todolists.clear();
    while (1)
    {
        system("cls");
        cout << "----------To do list---------" << endl<<endl<<endl<<endl;
        for (it = todolists.begin(); it != todolists.end(); it++)
        {
            string completed = it->iscompleted() ? " done" : "not done";
            cout << it->getid() << " " << it->getdescription() << " | " << completed << endl;
        }
        if (todolists.empty())
        {
            cout << "add your tasks " << endl;
        }
        cout << "1->add task" << endl;
        cout << "2->To mark a task completed" << endl;
         cout << "3->to remove a task"<<endl;
         cout<<"4->quit"<<endl<<endl;
        cout << "Enter your choice" << endl;
        cin >> choice;
        if (choice == 4)
        {
            break;
        }
        else if (choice == 1)
        {
            cout << "Add a task" << endl;
            cin.clear();
            cin.ignore();
            getline(cin, input_description);
            todolist newlist;
            newlist.create(input_description);
            todolists.push_back(newlist);
        }
        else if(choice ==3){
            cout<<"Enter a task id to remove"<<endl;
             cin >> input_id;
             for (it = todolists.begin(); it != todolists.end(); it++)
            {
                if (input_id == it->getid())
                {
                    todolists.erase(it);
                    break;
        }
            }
        }
        else if (choice == 2)
        {
            cout << " Enter the task id to mark completed" << endl;
            cin >> input_id;
            for (it = todolists.begin(); it != todolists.end(); it++)
            {
                if (input_id == it->getid())
                {
                    it->setcompleted(true);
                    break;
                }
            }
        }
    }
    return 0;
}