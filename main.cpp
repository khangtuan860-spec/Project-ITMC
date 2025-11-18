#include <bits/stdc++.h>

using namespace std;
struct student
{
    string id,name,carenote;
};
class studentcare
{
private:
    vector<student>studentlist;
    const string filename="Studentlist.txt";
    void loadFromFile() {
        ifstream file(filename);
        if (file.is_open()) {
            student s;
            while (file >> s.id) {
                file.ignore();
                getline(file, s.name);
                getline(file, s.carenote);
                studentlist.push_back(s);
            }
            file.close();
        }
    }

    void saveToFile() {
        ofstream file(filename);
        for (const auto& x : studentlist) {
            file << x.id << " " << x.name << "\n" << x.carenote << "\n";
        }
        file.close();
    }
public:
    studentcare()
    {
        loadFromFile();
    }
    ~ studentcare()
    {
        saveToFile();
    }
    void add(string& id,string& name,string& carenote)
    {
        studentlist.push_back({id,name,carenote});
        cout<<"Add successfully.\n";
    }
    void view() const
    {
        for(auto &x:studentlist)
        {
            cout<<"MSSV: "<<x.id<<", "<<"Full name: "<<x.name<<", "<<"Care Note: "<<x.carenote<<'\n';
        }
    }
    void searchstudent(string id)
    {
        auto it=find_if(studentlist.begin(),studentlist.end(),[id] (const student& x) {return x.id==id;});
        if(it!=studentlist.end())
        {
            cout<<"MSSV: "<<it->id<<", Full name: "<<it->name<<", Care Note: "<<it->carenote<<'\n';
        }
        else cout<<"MSSV errol.\n";
    }
};
int main()
{
    studentcare system;
    int select;
    do{
        cout<<"Sudent Care Menu:\n";
        cout<<"1.Add student.\n";
        cout<<"2.Student list.\n";
        cout<<"3.Search student by MSSV.\n";
        cout<<"4.Exit.\n";
        cin>>select;

        if(select == 1)
        {
            string id,name,carenote;
            cout<<"MSSV: ";cin>>id;
            cin.ignore();
            cout<<"Full name: ";getline(cin,name);
            cout<<"Care note of student: ";getline(cin,carenote);
            system.add(id,name,carenote);
        }
        if(select == 2)
        {
            system.view();
        }
        if(select == 3)
        {
            string id_find;
            cout<<"Enter the MSSV to find: ";cin>>id_find;
            system.searchstudent(id_find);
        }

    }while(select!=4);
}
