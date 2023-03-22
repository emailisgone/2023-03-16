#ifndef ENTRYRECORD_HPP
#define ENTRYRECORD_HPP

#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include <ctime>
#include "time.cpp"

class EntryRecord{
    private:
    static int recordCount;
    int personID;
    std::string personName;
    bool adminPermission;
    Time timeOfEntry;
    Time timeOfExit;

    public:
    EntryRecord(int id, std::string name, bool aPermStatus, Time entry, Time exit);
    ~EntryRecord();

    void setPersonID(int id);
    void setPersonName(std::string name);
    void setPersonAdminPermission(bool permission);
    void setPersonTimeOfEntry(Time time);
    void setPersonTimeOfExit(Time time);

    int getPersonId();
    std::string getPersonName();
    bool getPersonAdminPermission();
    std::string getPersonTimeOfEntry(timeFormat format);
    std::string getPersonTimeOfExit(timeFormat format);

    void pushTimeOfEntry(int seconds);
    std::string workTime(timeFormat format);

    static int getTotalRecordCount(){
        return recordCount;
    }
};



#endif