#include "entryRecord.hpp"

int EntryRecord::recordCount = 0;

// -----------------------------------------------------ENTRY RECORD----------------------------------------------------------
EntryRecord::EntryRecord(int id, std::string name = "NULL", bool aPermStatus = false, Time entry = Time(0), Time exit = Time(0)){
    ++recordCount;
    this->setPersonID(id);
    this->setPersonName(name);
    this->setPersonAdminPermission(aPermStatus);
    this->setPersonTimeOfEntry(entry);
    this->setPersonTimeOfExit(exit);
}

EntryRecord::~EntryRecord(){
    --recordCount;
}

void EntryRecord::setPersonID(int id){
    if(id<0) throw std::invalid_argument("Error: person's ID cannot be negative.");
    personID = id;
}

void EntryRecord::setPersonName(std::string name){
    personName = name;
}

void EntryRecord::setPersonAdminPermission(bool permission){
    adminPermission = permission;
}

void EntryRecord::setPersonTimeOfEntry(Time time){
    timeOfEntry = time;
}

void EntryRecord::setPersonTimeOfExit(Time time){
    timeOfExit = time;
}

int EntryRecord::getPersonId(){
    return personID;
}

std::string EntryRecord::getPersonName(){
    return personName;
}

bool EntryRecord::getPersonAdminPermission(){
    return adminPermission;
}

std::string EntryRecord::getPersonTimeOfEntry(timeFormat format){
    switch(format){
    case LT:
        return timeOfEntry.showTimeLT();
        break;
    case UK:
        return timeOfEntry.showTimeUK();
        break;
    default:
        return timeOfEntry.showTimeLT();
        break;
    }
}

std::string EntryRecord::getPersonTimeOfExit(timeFormat format){
    switch(format){
    case LT:
        return timeOfExit.showTimeLT();
        break;
    case UK:
        return timeOfExit.showTimeUK();
        break;
    default:
        return timeOfExit.showTimeLT();
        break;
    }
}

void EntryRecord::pushTimeOfEntry(int seconds){
    timeOfEntry.addSeconds(seconds);
}
