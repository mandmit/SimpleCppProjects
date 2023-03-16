#include "classes.h"

int Person::getId() const {
    return id;
}
std::string Person::getType() const {
    return type;
}
std::string Person::getName() const {
    return name;
}
std::string Person::getPhone() const {
    return phone;
}
std::string Person::getMail() const {
    return mail;
}
void Person::setId(int id){
    this->id = id;
}
void Person::setType(std::string type){
    this->type = type;
}
void Person::setName(std::string name){
    this->name = name;
}
void Person::setPhone(std::string phone){
    this->phone = phone;
}
void Person::setMail(std::string mail){
    this->mail = mail;
}

std::string Employee::getDepartment() const{
    return department;
}
void Employee::setDepartment(const std::string& dep){
    this->department = dep;
}

Table Table::table_;
size_t Table::id_max_size = 2;
size_t Table::type_max_size = 4;
size_t Table::name_max_size = 4;
size_t Table::phone_max_size = 5;
size_t Table::mail_max_size = 4;
size_t Table::department_max_size = 10;

Table* Table::GetInstance(const std::string& path){
    if(table_.path != path) {
        table_.path = path;
    }
    return &table_;
}

Table::~Table(){
    std::ofstream f_stream;
    if (path.find(".txt") == std::string::npos) {
        path += ".txt";
    }
    f_stream.open(path, std::ios::out);
    const std::map<std::string, size_t> column{ {"id",id_max_size},{"name",name_max_size},{"type",type_max_size},{"phone",phone_max_size},{"mail",mail_max_size},{"department",department_max_size} };
    for(const auto& c : table){
        c.second->getAllData(f_stream,column);
    }
    f_stream.close();
}
void Table::clearAll(){
    table.clear();
}
bool Table::deleteRecord(int id){
    return table.erase(id);
}