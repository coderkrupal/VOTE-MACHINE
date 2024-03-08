#include <iostream>
#include <string>
#include "CLEAR_SCREEN.h"
#include <fstream>
#include <stdbool.h>
#include <unistd.h>

using namespace std;

class learn
{

private:
     string user;
     string adhar;
     bool flag = true;
     int vote;
     string store_it;
     int foo;

public:
     void showmenu();
     void mainlogic();
};

void learn::showmenu()
{

     clearScreen();
     cout << "-----------vote machine----------" << endl;
     cout << endl;
     cout << "1:vote  machine" << endl;
     cout << "2:show your detail" << endl;
     cout << "3:EXIT" << endl;

     cout << endl;
}

void learn::mainlogic()
{

     cout << "enter your choice" << endl;
     cin >> vote;

     switch (vote)
     {
     case 1:

          cout << "enter your vote for:" << endl;
          cout << endl;
          cout << "\t|BJP             |\t" << endl;
          cout << "\t|CONGRESS        |\t" << endl;
          cout << "\t|AMM ADAMI PARTY |\t" << endl;
          cout << endl;

          cout << "FIRST ENTER YOUR NAME" << endl;
          cin >> user;
          cout << endl;
          cout << "ENTER YOUR ADHAR NUMBER" << endl;
          cin >> adhar;

          if (adhar.length() > 6)
          {
               cout << "adhar number not should be more than 6 digit" << endl;
               cout << "restart  your process" << endl;
               mainlogic();
          }

          cout << endl;
          cout << "  \t-------------------------------------\t" << endl;
          cout << "\t     verification successfully        \t" << endl;
          cout << "  \t------------------------------------- \t" << endl;

          cout << "enter your vote !! (1 to 3 option)" << endl;
          cin >> foo;

          cout << endl;
          if (foo == 1)
          {
               cout << "your vote is count for [BJP]" << endl;
               store_it = "your vote is count for [bjp]";
               
          }
          else if (foo == 2)
          {
               cout << "your vote is count for [congress]" << endl;
          }
          else
          {
               cout << "your vote is count for other party" << endl;
          }

          ofstream outfile;

          outfile.open("sace.dat", ios::app);

          outfile << user << endl;
          outfile << adhar << endl;

          cout << "content is successfully save in file" << endl;

          sleep(5);

          outfile.close();
          showmenu();
          mainlogic();

          break;
     }
     if (vote == 2)
     {
          cout << "------------TO SHOW YOUR DATA YOU FIRST ENTER YOUR USERNAME AND ADHARNUMBER---------" << endl;
                    cout<<endl;
   
          string a_user, v_adhar, check_user, check_adhar;

          cout << "enter yout username" << endl;
          cin >> a_user;

          cout << "enter your adhar number" << endl;
          cin >> v_adhar;

          ifstream infile;
          infile.open("sace.dat");
          cout << "your data: " << endl;
          cout << endl;
          while (infile >> check_user && infile >> check_adhar)
          {
               if (a_user == check_user && v_adhar == check_adhar)
               {
                    flag = true;
               }
               else
               {
                    flag = false;
               }
          }
     } 
     if (flag == true)
     {
          cout << "read data successfully" << endl;
          cout << "your data: "
               << "usrename" << user << ","
               << "adharnumber" << adhar << endl;
     }
     else
     {
          cout << "data fatching failed!!" << endl;
     }
}

int main()
{
     learn first;

     first.showmenu();
     first.mainlogic();

     return 0;
}
