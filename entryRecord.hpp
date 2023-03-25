#ifndef ENTRYRECORD_HPP
#define ENTRYRECORD_HPP

#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include <ctime>
#include "time.cpp"

class EntryRecord {
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

    int getPersonId() const;
    std::string getPersonName() const;
    bool getPersonAdminPermission() const;
    std::string getPersonTimeOfEntry(timeFormat format) const;
    std::string getPersonTimeOfExit(timeFormat format) const;

    void pushTimeOfEntry(int seconds);
    void pushTimeOfExit(int seconds);
    std::string workTime(timeFormat format);

    static int getTotalRecordCount(){
        return recordCount;
    }

    friend std::ostream& operator<<(std::ostream& os, const EntryRecord& record);
};



#endif