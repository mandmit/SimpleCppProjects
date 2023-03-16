#include <string>
#include <iomanip>
#include <iostream>
#include <fstream>
#include <map>
#include <memory>

class Person{
public:
    Person(int id, std::string type, std::string name, std::string phone, std::string mail)
    : id(id), type(type), name(name), phone(phone), mail(mail){}
    int getId() const;
    std::string getType() const;
    std::string getName() const;
    std::string getPhone() const;
    std::string getMail() const;
    virtual std::string getDepartment() const {
        return "";
    };
    void setId(int id);
    void setType(std::string type);
    void setName(std::string name);
    void setPhone(std::string phone);
    void setMail(std::string mail);
    virtual std::ofstream& getAllData(std::ofstream& stream, const std::map<std::string,size_t>& container) const{
        stream << std::left << "| " << std::setw(container.at("id")) << std::setfill(' ') << id << " | " << std::setw(container.at("type")) << std::setfill(' ') << type
            << " | " << std::setw(container.at("name")) << std::setfill(' ') << name << " | " << std::setw(container.at("phone")) << std::setfill(' ') << phone
            << " | " << std::setw(container.at("mail")) << std::setfill(' ') << mail << " | " << std::setw(container.at("department")) << "" << std::setfill(' ') << " |\n";
        return stream;
    }
protected:
    int id;
    std::string type;
    std::string name;
    std::string phone;
    std::string mail;
};

class Employee : public Person{
public:
    Employee(int id, std::string type, std::string name, std::string phone, std::string mail, std::string department)
    : Person(id,type,name,phone,mail), department(department){}
    std::string getDepartment() const override;
    void setDepartment(const std::string& dep);
    std::ofstream& getAllData(std::ofstream& stream, const std::map<std::string,size_t>& container) const override{
        stream << std::left << "| " << std::setw(container.at("id")) << std::setfill(' ') << id << " | " << std::setw(container.at("type")) << std::setfill(' ') << type
            << " | " << std::setw(container.at("name")) << std::setfill(' ') << name << " | " << std::setw(container.at("phone")) << std::setfill(' ') << phone
            << " | " << std::setw(container.at("mail")) << std::setfill(' ') << mail << " | " << std::setw(container.at("department")) << std::setfill(' ') << department << " |\n";
        return stream;
    }
private:
    std::string department;
};

class Director : public Person{
public:
    Director(int id, std::string type, std::string name, std::string phone, std::string mail)
    : Person(id,type,name,phone,mail){}
private:
};

class Customer : public Person{
public:
    Customer(int id, std::string type, std::string name, std::string phone, std::string mail)
    : Person(id,type,name,phone,mail){}
private:
};

//Singleton
class Table{
public:
    template <typename T>
    void addRecord(T s_ptr){
        table[s_ptr->getId()] = s_ptr;
        auto current_size = std::to_string(s_ptr->getId()).size();
        if(id_max_size < current_size){
            id_max_size = current_size;
        }
        current_size = s_ptr->getType().size();
        if(type_max_size < current_size){
            type_max_size = current_size;
        }
        current_size = s_ptr->getName().size();
        if(name_max_size < current_size){
            name_max_size = current_size;
        }
        current_size = s_ptr->getPhone().size();
        if(phone_max_size < current_size){
            phone_max_size = current_size;
        }
        current_size = s_ptr->getMail().size();
        if(mail_max_size < current_size){
            mail_max_size = current_size;
        }
        std::shared_ptr<Employee> temp = std::dynamic_pointer_cast<Employee>(s_ptr);
        if(temp.get()!=nullptr){
            current_size = s_ptr->getDepartment().size();
            if(department_max_size < current_size){
                department_max_size = current_size;
            }
        }
    }
    static Table* GetInstance(const std::string& path);
    ~Table();
    void clearAll();
    bool deleteRecord(int id);
protected:
    Table(const std::string& path) : path(path){}
    Table() : path("Dumb") {}
private:
    Table(Table&) = delete;
    void operator=(const Table&) = delete;
    static Table table_;
    std::map<int,std::shared_ptr<Person>> table;
    std::string path;
    static size_t id_max_size;
    static size_t type_max_size;
    static size_t name_max_size;
    static size_t phone_max_size;
    static size_t mail_max_size;
    static size_t department_max_size;
};