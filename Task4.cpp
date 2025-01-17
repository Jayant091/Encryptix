#include <iostream>
#include <string>
#include <list>

using namespace std;
class TodoItem {
private:
    int id;
    string description;
    bool completed;

public:
    TodoItem() : id(0), description(""), completed(false) {}
    ~TodoItem() = default;

bool create(std::string new_description) {
        id = rand() % 10 + 1;
        description = new_description;
        return true;

    }

    int getId() { return id; }
    string getDescription() { return description; }
    bool isCompleted() { return completed; }
    void setCompleted(bool val) { completed = val;}


};

void deleteTask(list<TodoItem>& todoItems, int id) {
    for (auto it = todoItems.begin(); it != todoItems.end(); ++it) {
        if (it->getId() == id) {
            todoItems.erase(it);
            break;
        }
    }
}
int main()
{
    char input_option;
    int input_id;
    string input_description;
    string version = "v0.1.0";
    list<TodoItem> todoItems;
    list<TodoItem>::iterator it;


    todoItems.clear();

    while (1) {
        system("cls");
        cout << "Todo List Maker - " << version << endl;
        cout << endl << endl;

        for (it = todoItems.begin(); it != todoItems.end(); it++) {

            string completed = it->isCompleted() ? "done" : "not done";

            cout << it->getId() << " | " << it->getDescription() << " | "
                << completed << endl;
        }

        if (todoItems.empty()) {
            cout << "Add your first todo!" << endl;
        }

        cout << endl << endl;

        cout << "[a]dd a new Task" << endl;
        cout << "[c]omplete a Task" << endl;
        cout<<"[d]elete a Task"<<endl;
        cout << "[q]uit" << endl;

        cout << "choice: ";

        cin >> input_option;

        if (input_option == 'q') {
            cout << "Have a great day now!" << endl;
            break;
        }
        else if (input_option == 'a') {
            cout << "Add a new description: ";
            cin.clear();
            cin.ignore();
            getline(cin, input_description);

            TodoItem newItem;
             newItem.create(input_description);
            todoItems.push_back(newItem);

        }
        else if (input_option == 'c') {
            cout << "Enter id to mark completed: ";
            cin >> input_id;

            for (it = todoItems.begin(); it != todoItems.end(); it++) {

                if (input_id == it->getId()) {
                    it->setCompleted(true);
                    break;
                }
            }
        }
        else if (input_option == 'd') {
            cout << "Enter id to delete: ";
           cin >> input_id;
        deleteTask(todoItems, input_id);
        }

    }


    return 0;
}
