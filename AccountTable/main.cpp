#include "classes.h"
int main(){
    Table* table = Table::GetInstance("AccountTable");
    while(true){
        char command;
        std::cout << "Enter command: ";
        std::cin >> command;
        if(command=='a'){
            char entity;
            std::cout << "Enter what type of entity (p - Person, e - Employee, d - Director, c - Customer): ";
            std::cin >> entity;
            int id = 0;
            std::string name,phone,mail;
            std::cout << "Enter id: ";(std::cin >> id).ignore();
            std::cout << "Enter name: ";std::getline(std::cin,name);
            std::cout << "Enter phone: ";std::cin >> phone;
            std::cout << "Enter mail: ";(std::cin >> mail).ignore();
            if(entity=='p'){
                table->addRecord(std::make_shared<Person>(id,"person",name,phone,mail));
            }else if(entity=='e'){
                std::string department;
                std::cout << "Enter department: ";std::getline(std::cin,department);
                table->addRecord(std::make_shared<Employee>(id,"employee",name,phone,mail,department));
            }else if(entity=='d'){
                table->addRecord(std::make_shared<Director>(id,"director",name,phone,mail));
            }else if(entity=='c'){
                table->addRecord(std::make_shared<Customer>(id,"customer",name,phone,mail));
            }else{
                std::cout << "Invalid entity type\n";
            }
        }else if(command=='d'){
            int id;
            std::cout << "Enter id of record: ";
            std::cin >> id;
            if(table->deleteRecord(id)){
                std::cout << "Record successfully deleted\n";
            }else{
                std::cout << "Error\n";
            }
        }
        else if (command == 'c') {
            table->clearAll();
        }else if(command == 'e'){
            break;
        }else{
            std::cout << "Wrong command.\nAvailable commands:\na - add account\nd - delete account\nc - clear all\ne - exit\n";
        }
    }
    std::cout << '\n';
    return 0;
}