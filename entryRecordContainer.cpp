#include "entryRecordContainer.hpp"

EntryRecordContainer::EntryRecordContainer(){
    records = std::vector<EntryRecord>();
}

EntryRecordContainer::EntryRecordContainer(std::vector<EntryRecord> array){
    setEntryRecordContainer(array);
}

EntryRecordContainer::~EntryRecordContainer(){

}

void EntryRecordContainer::setEntryRecordContainer(std::vector<EntryRecord> array){
    records = array;
}

std::vector<EntryRecord> EntryRecordContainer::getEntryRecordContainer(){
    return records;
}

void EntryRecordContainer::addRecord(EntryRecord record){
    records.push_back(record);
}

void EntryRecordContainer::deleteRecord(int position){
    records.erase(records.begin()+(position-1));
}

int EntryRecordContainer::containerSize(){
    return records.size();
}

void EntryRecordContainer::displayRecords(){
    for(int i=0; i<containerSize(); ++i){
        std::cout<<"["<<records.at(i).getPersonId()<<"] "<<records.at(i).getPersonName()<<", login: "<<records.at(i).getPersonTimeOfEntry(LT)<<", logout: "<<records.at(i).getPersonTimeOfExit(LT)<<std::endl;
    }
}

void EntryRecordContainer::exportRecords(char* fileName){
    if(containerSize()<=0) throw std::runtime_error("Runtime error: no records to export.");
    if(fileName=="" || fileName==" ") throw std::invalid_argument("Invalid file name");

    if(strstr(fileName, ".txt")==NULL)
        strncat(fileName, ".txt", strlen(".txt"));

    std::ofstream write(fileName);
    for(int i=0; i<containerSize(); ++i){
        write<<"["<<records.at(i).getPersonId()<<"] "<<records.at(i).getPersonName()<<", login: "<<records.at(i).getPersonTimeOfEntry(LT)<<", logout: "<<records.at(i).getPersonTimeOfExit(LT)<<std::endl;
    }
    write.close();
}