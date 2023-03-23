//#include "entryRecord.cpp"
#include "entryRecordContainer.cpp"

int main(){
    // Nr. 1
    /*std::vector<Time> timeArray;
    int n = 0;
    while(n!=2){
        int second, minute, hour;
        std::cin>>second>>minute>>hour;
        try{
            timeArray.push_back(Time(hour, minute, second));
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
            --n;
        }
        ++n;
    }*/
    
    EntryRecordContainer records;
    try{
        records.exportRecords("log");
    }
    catch(const std::exception& e){
        std::cerr << e.what() << '\n';
    }


    return 0;
}
