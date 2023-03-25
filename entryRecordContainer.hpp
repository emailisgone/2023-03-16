#ifndef ENTRYRECORDCONTAINER_HPP
#define ENTRYRECORDCONTAINER_HPP

#include <fstream>
#include "string.h"
#include "entryRecord.cpp"

class EntryRecordContainer{
    private:
    std::vector<EntryRecord> records;


    public:
    EntryRecordContainer();
    EntryRecordContainer(std::vector<EntryRecord> array);
    ~EntryRecordContainer();
    void setEntryRecordContainer(std::vector<EntryRecord> array);
    std::vector<EntryRecord> getEntryRecordContainer();

    void addRecord(EntryRecord record);
    void deleteRecord(int position);
    int containerSize() const;
    void displayRecords();
    void exportRecords(char* fileName);

    EntryRecordContainer& operator+=(const EntryRecordContainer& rhs);
};


#endif