#include <iostream>
#include <map>
#include <limits>
using namespace std;


void add_task( multimap<int , string> &m);

void delete_task(multimap<int , string> &m);

void check_task(multimap<int , string> &m , multimap<int , string> &m2);

void print_list(const multimap<int , string> &m);


int main()
{
    multimap<int,string>List /*= {{1,"AA"},{2,"BB"}}*/;
    multimap<int,string>Finished_Tasks_List;


   while (true)
    {
        int choice;
        cout << "Choose an option: \n1. Add Task\n2. Delete Task\n3. Check Task\n4. Print List\n5. Print Finished Tasks\n6. Exit\n";
        cin >> choice;

        switch (choice)
        {
            case 1:
                add_task(List);
                break;
            case 2:
                delete_task(List);
                break;
            case 3:
                check_task(List, Finished_Tasks_List);
                break;
            case 4:
                print_list(List);
                break;
            case 5:
                print_list(Finished_Tasks_List);
                break;
            case 6:
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                break;
        }

   }



    return 0;
}



void add_task( multimap<int , string> &m)
    {
        string T;
        int H;

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout<<"Enter the task which you want to be added"<<endl;
        getline(cin , T);

        cout<<"Enter the time of that task"<<endl;
        cin>>H;

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        m.insert({H,T});


        /*multimap<int , string>::iterator it = m.begin();
        for(; it != m.end() ; it++ )
        {
            cout<<it->first<<"-->" <<it->second<<endl;
        }cout<<endl<<endl;

        for(auto it1 : m)
        {
            cout<<it1.first<<" - " <<it1.second<<endl;
        }cout<<endl<<endl;

        for (const auto& it2 : m)
        {
        cout << it2.first << " - " << it2.second << endl;
        }*/


    }


void delete_task(multimap<int , string> &m)
    {

        string T;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout<<"Enter the task which you want to be deleted"<<endl;
        getline(cin,T);

        auto it3 = m.begin();
        while(it3 != m.end())
        {
            if(it3->second == T)
            {
                it3 = m.erase(it3);
                break;
            }
            else
            {
                it3++;
            }
        }


        /*for (const auto& it4 : m)
        {
        cout << it4.first << "-->" << it4.second << endl;
        }cout<<endl<<endl;
        */
    }



void check_task(multimap<int , string> &m , multimap<int , string> &m2)
    {



        string T;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout<<"Enter the task which you want to be checked as finished"<<endl;
        getline(cin,T);

        auto it3 = m.begin();
        while(it3 != m.end())
        {
            if(it3->second == T)
            {
                m2.insert({it3->first, it3->second});
                it3 = m.erase(it3);
            }
            else
            {
                it3++;
            }
        }



    }



void print_list(const multimap<int , string> &m)
    {

        for (const auto& it4 : m)
        {
        cout << it4.second << " at " << it4.first <<" O'clock" <<endl;
        }cout<<endl<<endl;

    }
