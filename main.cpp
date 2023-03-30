#include "entryRecordContainer.cpp"

int main(){
   /*Time a(0,22,23), b(0,100,0);
    Time c = a + b;
    //std::cout<<c.showTimeLT(); // Turi buti 02:02:23, bet kazkodel 01:02:23??????
    Time d;
    d += 11;
    Time e(1,11,1), f(0,11,1);
    //std::cout<<(f!=e); 
    // << operator via class method
    //e<<std::cout<<std::endl;   
    // << operator via friend modifier
    //std::cout<<e<<std::endl;
    Time g;
    //std::cin>>g; +
    //std::cout<<g<<" "<<e<<" "<<f<<" "<<d;
    //system("pause");
    //std::cout<<g++<<" "<<++g<<std::endl;
    Time h = ++g;
    //std::cout<<h;*/

    /*const Time constant(0,0,1);
    Time g;
    //++constant;
    //--constant;
    //constant++;
    //constant--;
    //constant+=g;
    //std::cin>>constant;
    //std::cout<<constant<<" "<<(g>constant);   // THIS WORKS, UNCOMMENT
    g += constant;
    //std::cout<<g<<std::endl;

    EntryRecord entry(1, "Adam", false, Time(0,0,1), Time(0,10,11));
    entry.pushTimeOfEntry(20);
    //std::cout<<entry.getPersonTimeOfEntry(LT);
    //std::cout<<entry;

    std::vector<EntryRecord> v1, v2;
    v1.push_back(entry);
    v2.push_back(EntryRecord(2, "Lisa", false, Time(11,17,56), Time(22,10,19)));
    v2.push_back(EntryRecord(3, "Diluc", true, Time(7,00,00), Time(11,00,00)));
    EntryRecordContainer cont1(v1), cont2(v2);
    cont1.displayRecords();
    cont1+=cont2;
    cont1.displayRecords();*/

    Time a(5,0,0), b(7,0,0);
    Time c = a+b;
    std::cout<<c<<std::endl;
    c+=-46800;
    std::cout<<c;


    return 0;
}
