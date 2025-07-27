#include <vector>
#include <iostream>
#include <string>

struct Task {
  std::string taskName;
  bool completed;
};

std::vector<Task> tasks;

void addTask(){
  std::string taskName{};
  bool completed{};
  char choice{};
  std::cout << "Enter your task: \n";
  std::cin.ignore();
  std::getline(std::cin, taskName);
  std::cout << "Has this task been completed? (y/n) \n";
  std::cin >> choice;
  while(choice != 'y' && choice != 'n'){
    std::cout << "Please enter 'y/n' \n";
    std::cin >> choice;
  }
  if(choice == 'y'){
    completed = 1;
  }else{
    completed = 0;
  } 
  tasks.push_back({taskName, completed});
}

void printTasks(){
  for(size_t i{0}; i < tasks.size(); i++){
    std::cout << i + 1 << ". " << tasks[i].taskName
              << " Completed: " << (tasks[i].completed ? "Yes" : "No") << "\n";
  }
}

int main(){
  
  int userAction{};
  std::cout << "Hello, you are using Brett's task manager \n";

  while(userAction != 3){
    std::cout << "Enter 1 to add a new task \n"
              << "Enter 2 to print the task list \n"
              << "Enter 3 to quit \n";
    std::cin >> userAction;

    switch (userAction) {
      case 1:
        addTask();
        break;
      case 2:
        printTasks();
        break;
      case 3:
        std::cout << "Goodbye! \n";
        break;
      default:
        std::cout << "Invalid input \n";
    }
  }
}
