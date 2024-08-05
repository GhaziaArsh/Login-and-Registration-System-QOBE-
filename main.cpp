#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <windows.h>
#include <bits/stdc++.h>
#include <unordered_map>
#include <cstdlib>
using namespace std;
vector<string> classes;
vector <string> S1CS,S3CS,S1EE,S3EE;
vector<string> DCS,DEE,DBBA,DMT,DEL,DIS,DSS;
int totalnumber1=0;
int totalnumber2=0;
string BoardsofPakistan [29];
string student_department[2];
string teacher_department[6];
void gotoRowCol(int rpos, int cpos)
{
	int xpos=cpos, ypos = rpos;
	COORD scrn;
	HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);
	scrn.X = cpos;
	scrn.Y = rpos;
	SetConsoleCursorPosition(hOuput, scrn);
}
string teacher_ID (int a)
{
    if (a==0)
    {
        return "NUMDCS-";
    }
    else if (a==1)
    {
        return "NUMDEE-";
    }
    else if (a==2)
    {
        return "NUMDBBA-";
    }
    else if (a==3)
    {
        return "NUMDMT-";
    }
    else if (a==4)
    {
        return "NUMDEL-";
    }
    else if (a==5)
    {
        return "NUMDIS-";
    }
    else if (a==6)
    {
        return "NUMDSS-";
    }
}
int tdep ()
{
   teacher_department[0]="Department of Computer Sciences"; teacher_department[1]="Department of Electrical Engineering"; teacher_department[2]="Department of Mathematics";
   teacher_department[3]="Department of English literature"; teacher_department[4]="Department of Islamic Studies"; teacher_department[5]= "Department of Social Sciences";
   cout << "Select your department:"<<endl;
   for (int i=0; i<7; i++)
   {
       cout << i+1 << ")"<<teacher_department[i]<<endl;
   }
   int temp;
   cin>>temp;
   return (temp-1);
}
int teacher_degree ()
{
    cout << "Select your highest qualification:"<<endl;
    cout << "1)Ph.D\n2)M.Phil\n3)BS"<<endl;
    int x;
    cin>>x;
    return x;
}
string Assign_gender ()
{
    string temp1 = "Male", temp2 = "Female", temp3 = "Non-Binary";
    cout << "Select your gender:"<<endl;
    cout << "1)Male \n2)Female \n3)Non-binary"<<endl;
    int a;
    cin>>a;
    if(a==1)
    {
        return temp1;
    }
    else if (a==2)
    {
        return temp2;
    }
    else if (a==3)
    {
        return temp3;
    }
}
bool CNICC (long long int A)
{
    int c=0;
    while (A!=0)
    {
        A/=10;
        c++;
    }
    if (c==13)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void init ()
{
    classes = {"CS-1st Semester","CS-3rd Semester","EE-1st Semester","EE-3rd Semester"};
    DCS = {"Programming Fundamentals","Discrete Structures","Data Structures","Software Engineering","Computer Organization","Application of ICT"};
    DEE = {"Introduction to Electrical Engineering","Digital Logic Design","Signals and Systems", "Microprocessor Systems", "Electromagnetic Field Theory"};
    DMT = { "Multivariable Calculus", "Calculus and Analytical Geometry","Probability and Statistics", "Linear Algebra"};
    DEL = {"Functional English","Expository Writing","Technical and Business Writing","Great Books"};
    DIS = {"Islamic Studies and Ethics","Quranic Studies I","Quranic Studies II"};
    DSS = {"Pakistan Studies","Professional Ethics"};

    S1CS = {"Programming Fundamentals", "Discrete Structures", "Application of ICT", "Functional English", "Linear Algebra", "Pakistan Studies"};
    S3CS = {"Data Structures", "Multivariable Calculus","Great Books", "Computer Organization", "Quranic Studies I", "Software Engineering"};
    S1EE = {"Introduction to Electrical Engineering", "Digital Logic Design","Calculus and Analytical Geometry", "English Composition", "Pakistan Studies","Quranic Studies I"};
    S3EE = {"Signals and Systems","Microprocessor Systems","Electromagnetic Field Theory","Probability and Statistics","Technical Writing","Quranic Studies II"};

    BoardsofPakistan[0]="BISE Federal"; BoardsofPakistan[1]="BISE AJK"; BoardsofPakistan[2]="BISE Quetta";BoardsofPakistan[3]="BISE Turbat"; BoardsofPakistan[4]="BISE Zhob"; BoardsofPakistan[5]="BISE Sawat"; BoardsofPakistan[6]="BISE DI Khan"; BoardsofPakistan[7]="BISE Mardan"; BoardsofPakistan[8]="BISE Peshawar"; BoardsofPakistan[9]="BISE Kohat"; BoardsofPakistan[10]="BISE Malakand"; BoardsofPakistan[11]= "BISE Abbotabad"; BoardsofPakistan[12]="BISE Bannu";
    BoardsofPakistan[13]= "BISE Hyderabad"; BoardsofPakistan[14]="BISE Larkana"; BoardsofPakistan[15]="BISE MirpurKhas"; BoardsofPakistan[16]="BISE Sukkur"; BoardsofPakistan[17]="BISE Karachi"; BoardsofPakistan[18]= "BSEK Karachi"; BoardsofPakistan[19]="BSEK Agha Khan";
    BoardsofPakistan[20] = "BISE Lahore"; BoardsofPakistan[21]="BISE Gujrawala"; BoardsofPakistan[22]= "BISE Sahiwal"; BoardsofPakistan[23]= "BISE Bahawalpur"; BoardsofPakistan[24]= "BISE DG Khan"; BoardsofPakistan[25]="BISE Faisalabad"; BoardsofPakistan[26]="BISE Multan"; BoardsofPakistan[27]="BISE Rawalpindi"; BoardsofPakistan[28]="BISE Sargodha";
}
void class_allocation (string temp, vector<string>& AB)
{
  unordered_map<int, vector<string>*> vectorMap;
    vectorMap[0] = &S1CS; vectorMap[1]= &S3CS; vectorMap[2]=&S1EE; vectorMap[3]=&S3EE;
    for (int i = 0; i < vectorMap.size(); i++)
    {

        for (const string& elem : *vectorMap[i])
        {
            if(elem==temp)
            {
                AB.push_back(classes[i]);
            }
        }
    }
}
void tcourse (vector<int>& x, vector<string>& y,vector<string>& z,vector<string> A)
{
    vector<string> tclass;
    string temp;
    int temp1;
    cout << "Enter the number of courses you want to teach(max 2):";
    cin>>temp1;
    x.push_back(temp1);
    cout << "Enter index:"<<endl;
    cin.ignore();
    for (int i=1; i<=temp1; i++)
    {
        int temp2;
        cout << i << ".";
        cin>>temp2;
        y.push_back(A[temp2-1]);
        class_allocation(A[temp2-1],tclass);
    }
    cout << endl;
    cout << "You can teach following classes:"<<endl;
    for (int i=0; i< tclass.size(); i++)
    {
        cout << i+1<< "."<<tclass[i]<<endl;
    }
    cout << "Select any two classes:"<<endl;
    int temp3;
    cout << "1.";
    cin>>temp3;
    z.push_back(tclass[temp3-1]);
    cout << "2.";
    cin>>temp3;
    z.push_back(tclass[temp3-1]);

}
void subject_allocation (string temp,vector<int> &x, vector<string> & y,vector<string> &z)
{
    init();
    if (temp=="Department of Computer Sciences")
    {
        for(int i=0; i<DCS.size(); i++)
        {
            cout << i+1 <<  ")"<<DCS[i]<<endl;
        }
        tcourse(x,y,z,DCS);
    }
    else if (temp=="Department of Electrical Engineering")
    {
        for(int i=0; i<DEE.size(); i++)
        {
            cout << i+1 <<  ")"<<DEE[i]<<endl;
        }
        tcourse(x,y,z,DEE);
    }
    else if (temp=="Department of Business Administration")
    {
        for(int i=0; i<DBBA.size(); i++)
        {
            cout << i+1 <<  ")"<<DBBA[i]<<endl;
        }
        tcourse(x,y,z,DBBA);
    }
    else if (temp=="Department of Mathematics")
    {
        for(int i=0; i<DMT.size(); i++)
        {
            cout << i+1 <<  ")"<<DMT[i]<<endl;
        }
        tcourse(x,y,z,DMT);
    }
    else if (temp=="Department of English literature")
    {
        for(int i=0; i<DEL.size(); i++)
        {
            cout << i+1 <<  ")"<<DEL[i]<<endl;
        }
        tcourse(x,y,z,DEL);
    }
    else if (temp=="Department of Islamic Studies")
    {
        for(int i=0; i<DIS.size(); i++)
        {
            cout << i+1 <<  ")"<<DIS[i]<<endl;
        }
        tcourse(x,y,z,DIS);
    }
    else if (temp=="Department of Social Sciences")
    {
        for(int i=0; i<DSS.size(); i++)
        {
            cout << i+1 <<  ")"<<DSS[i]<<endl;
        }
        tcourse(x,y,z,DSS);
    }
}
int dep ()
{
    int yourdepartmnet;
    student_department[0]="CS"; student_department[1]="EE";
    cout << "Select department:"<<endl;
    for (int i=0; i<2; i++)
    {
        cout << i+1 << ")"<<student_department[i]<<endl;
    }
    cin>>yourdepartmnet;
    return (yourdepartmnet-1);
}
int eduation_board ()
{
    init();
    int board;
    cout << "Select Province:"<<endl;
    cout << "1)Islamabad\n2)Punjab\n3)Sindh\n4)Kyber Pakhtunkhaw\n5)Balochistan\n6)Azad-Jammu Kashmir"<<endl;
    int province;
    cin>>province;
    cout << "Select Board:"<<endl;
    if (province==1)
    {
        cout <<"1)"<< BoardsofPakistan[0]<<endl;
        cin>>board;
        return (board-1);
    }
    if (province==2)
    {
        for (int i=1; i<10; i++)
        {
            cout<< i<<")" << BoardsofPakistan[i+19]<<endl;
        }
        cin>>board;
        return (board+19);
    }
    if (province==3)
    {
        for (int i=1; i<8; i++)
        {
            cout << i << ")" << BoardsofPakistan[i+12]<<endl;
        }
        cin >> board;
        return (board+12);
    }
    if (province==4)
    {
        for (int i=1; i<9; i++)
        {
            cout << i << ")"<< BoardsofPakistan[i+5]<<endl;
        }
        cin>>board;
        return (board+5);
    }
    if (province==5)
    {
        for (int i=1; i<4; i++)
        {
            cout << i << ")" << BoardsofPakistan[i+1]<<endl;
        }
        cin>>board;
        return (board+1);
    }
    if (province==6)
    {
        cout << "1)" << BoardsofPakistan[1];
    }
    cin>>board;
    return board;
}
bool checkCaptcha(string& captcha, string& user_captcha)
{
    return captcha.compare(user_captcha) == 0;
}
string generateCaptcha(int n)
{

    time_t t;
    srand((unsigned)time(&t));
    char* chrs = "abcdefghijklmnopqrstuvwxyzABCDEFGHI"
                 "JKLMNOPQRSTUVWXYZ0123456789";
    string captcha = "";
    while (n--)
        captcha.push_back(chrs[rand() % 62]);

    return captcha;
}
class admin
{
private:
    string number[100];
    int matric_number[100];
    int inter_number[100];
    string city[100];
    string adress[100];
    string fname[100];
    string matricboard[100];
    string interboard[100];
    int matricyear[100];
    int interyear[100];
    long long int CNIC[100];
    string DOB[100];
    string teacher_domain[100];
    string tBS[100];
    int tBS_year[100];
    string tBS_inst[100];
    string tMPhil [100];
    int tMPhil_year[100];
    string tMPhil_inst[100];
    string tPHD[100];
    string tPHD_inst[100];
    string tWexp_inst1[100];
    string tWexp_inst2[100];
    string tWexp_inst3[100];
    string gender[100];
protected:
    string department [100];
    string name[100];
    string regno[100];
    string student_semester[100];
public:

    void student_input (int limit)
    {
        int year;
        int years[2]={2024,2025};
        cout<<"Enter Year :"<<endl;
        cout<<"1_ 2024"<<"                  2_2025"<<endl;
        cin>>year;
        year=year-1;

        for (int i=totalnumber1; i<(totalnumber1+limit); i++)
        {
            cin.ignore();
            cout << "PERSONAL DETAILS:"<<endl;
            cout << "Enter name:";
            getline(cin,name[i]);
            cout << "Enter Father's name:";
            getline(cin,fname[i]);
            cout << "Enter your Date of birth in format (dd-mm-yyyy):";
            getline(cin,DOB[i]);
            do
            {
             cout << "Enter your CNIC number (13-digit):";
             cin>>CNIC[i];
            }
            while (CNICC(CNIC[i]!=true));
            cin.ignore();
            cout << "Enter your city name:";
            getline(cin,city[i]);
            cout << "Enter your address:";
            getline(cin,adress[i]);
            cout << "Enter your phone number:";
            cin>>number[i];
            cout << "EDUCATIONAL DETAILS:"<<endl;
            cout << "Enter your Matric marks:";
            cin >> matric_number[i];
            cout << "Enter year of passing:";
            cin>>matricyear[i];
            matricboard[i]= BoardsofPakistan[eduation_board()];
            cout << "Enter your Intermediate marks:";
            cin>> inter_number[i];
            cout << "Enter year of passing:";
            cin>>interyear[i];
            interboard[i]= BoardsofPakistan[eduation_board()];
            department[i]= student_department[dep()];
            regno[i] = "NUM-BS" + department[i] + "-" + to_string(years[year])+ "-" + to_string(i+1);
            if (year==0)
            {
                string temp1;
                temp1 = department[i] + "-3rd Semester";
                student_semester[i]=temp1;
            }
            else if(year==1)
            {
               string temp2;
                temp2= department[i] + "-1st Semester";
                student_semester[i]=temp2;
            }
            cout <<endl;

        }
        totalnumber1+=limit;
    }

    void student_display ()
    {
         for (int i=0; i<totalnumber1; i++)
        {
            cout << i+1<<")Name:"<<name[i]<<endl;
            cout << "Father's name:"<<fname[i]<<endl;
            cout << "Registration number:"<< regno[i]<<endl;
            cout << "Department:"<< department[i]<<endl;
            cout << "Matric marks:"<<matric_number[i]<<endl;
            cout << "Matric Board:"<<matricboard[i]<<endl;
            cout << "Intermediate marks:"<<inter_number[i]<<endl;
            cout << "Inter Board:"<<interboard[i]<<endl;
            cout << "City:"<<city[i]<<endl;
            cout << "Address:"<<adress[i]<<endl;
            cout << "Phone number:"<<number[i]<<endl;
            cout << "Semester:"<<student_semester[i]<<endl;
            cout <<endl;

        }
    }
     void teacher_input (int limit)
    {
        loadDataFromFileT();
        for (int i=totalnumber2; i<(totalnumber2+limit); i++)
        {
            cin.ignore();
            cout << "PERSONAL DETAILS:"<<endl;
            cout << "Enter name:";
            getline(cin,name[i]);
            cout << "Enter Father's name:";
            getline(cin,fname[i]);
            cout << "Enter your Date of birth in format (dd-mm-yyyy):";
            getline(cin,DOB[i]);
            do
            {
             cout << "Enter your CNIC number (13-digit):";
             cin>>CNIC[i];
            }
            while (CNICC(CNIC[i])!=true);
            gender[i]= Assign_gender();
            cin.ignore();
            cout << "Enter your city name:";
            getline(cin,city[i]);
            cout << "Enter your address:";
            getline(cin,adress[i]);
            cout << "Enter your phone number:";
            cin>>number[i];
            cout << "EDUCATIONAL DETAILS:"<<endl;
            int t;
            t = teacher_degree();
            if (t==1)
            {
                cout << "Enter your Ph.D Subject:";
                cin.ignore();
                getline(cin,tPHD[i]);
                cout << "Institute:";
                getline(cin,tPHD_inst[i]);
                cout << "Enter your MPhil degree name:";
                getline(cin, tMPhil[i]);
                cout << "Year of completion:";
                cin>>tMPhil_year[i];
                cin.ignore();
                cout << "Institute:";
                getline(cin,tMPhil_inst[i]);
                cout << "Enter the name of your Bachelors' degree:";
                getline(cin,tBS[i]);
                cout << "Year of completion:";
                cin>>tBS_year[i];
                cin.ignore();
                cout << "Institute:";
                getline(cin, tBS_inst[i]);
            }
            if (t==2)
            {

                tPHD[i]="0";
                tPHD_inst[i]="0";
                cout << "Enter your MPhil degree name:";
                cin.ignore();
                getline(cin, tMPhil[i]);
                cout << "Year of completion:";
                cin>>tMPhil_year[i];
                cin.ignore();
                cout << "Institute:";
                getline(cin,tMPhil_inst[i]);
                cout << "Enter the name of your Bachelors' degree:";
                getline(cin,tBS[i]);
                cout << "Year of completion:";
                cin>>tBS_year[i];
                cin.ignore();
                cout << "Institute:";
                getline(cin, tBS_inst[i]);
            }
            if (t==3)
            {

                tPHD[i]= "0";
                tPHD_inst[i]= "0";
                tMPhil[i]= "0";
                tMPhil_year[i]=0;
                tMPhil_inst[i]= "0";
                cout << "Enter the name of your Bachelors' degree:";
                cin.ignore();
                getline(cin,tBS[i]);
                cout << "Year of completion:";
                cin>>tBS_year[i];
                cin.ignore();
                cout << "Institute:";
                getline(cin, tBS_inst[i]);
            }
            cout << "Enter your Intermediate marks:";
            cin>> inter_number[i];
            cout << "Enter year of passing:";
            cin>>interyear[i];
            interboard[i]= BoardsofPakistan[eduation_board()];
            cout << "Enter your Matric marks:";
            cin >> matric_number[i];
            cout << "Enter year of passing:";
            cin>>matricyear[i];
            matricboard[i]= BoardsofPakistan[eduation_board()];
            cin.ignore();
            string temp1;
            string temp2;
            cout << "WORK EXPERINECE:"<<endl;
            cout << "(enter 0 otherwise)"<<endl;
            cout << "Name of Institute-1:";
            getline(cin,temp1);
            if (temp1!="0")
            {
                cout << "Years (X-Y)";
                getline(cin,temp2);
                tWexp_inst1[i]= temp1 + "-" + temp2;
                cout << "Name of Institute-2:";
                getline(cin,temp1);
                if (temp1!="0")
                {
                    cout << "Years (X-Y)";
                    getline(cin,temp2);
                    tWexp_inst2[i]= temp1 + "-" + temp2;
                    cout << "Name of Institute-3:";
                    getline(cin,temp1);
                    if (temp1!="0")
                    {
                        cout << "Years (X-Y)";
                        getline(cin,temp2);
                        tWexp_inst3[i]= temp1 + "-" + temp2;
                    }
                    else
                    {
                        tWexp_inst3[i]= "0";
                    }

                }
                else
                {
                    tWexp_inst2[i] = "0";
                    tWexp_inst3[i] = "0";
                }
            }
            else
            {
                tWexp_inst1[i] = "0";
                tWexp_inst2[i] = "0";
                tWexp_inst3[i] = "0";
            }
            int temp;
            temp = tdep();
            department[i] = teacher_department[temp];
            regno[i] = teacher_ID(temp) + "2400" + to_string(i+1);
            cout <<endl;

        }
        totalnumber2+=limit;
        loadDatatoFileT();
    }


    void teacher_display ()
    {
         for (int i=0; i<totalnumber2; i++)
        {
            cout << i+1<<")Name:"<<name[i]<<endl;
            cout << "Father's name:"<<fname[i]<<endl;
            cout << "DOB:"<<DOB[i]<<endl;
            cout << "Gender:"<<gender[i]<<endl;
            cout << "Department:"<< department[i]<<endl;
            cout << "Teacher ID:" << regno[i]<<endl;
            cout << "Matric marks:"<<matric_number[i]<<endl;
            cout << "Matric Board:"<<matricboard[i]<<endl;
            cout << "Intermediate marks:"<<inter_number[i]<<endl;
            cout << "Inter Board:"<<interboard[i]<<endl;
            cout << "BS Degree:"<<tBS[i]<<endl;
            cout << "BS Institute:"<<tBS_inst[i]<<endl;
            if(tMPhil[i]!= "0")
            {
                cout << "MPhil:"<< tMPhil[i]<<endl;
                if (tPHD[i]!= "0")
                {
                    cout << "Ph.D Subject:"<<tPHD[i]<<endl;
                }
            }
            cout << "Work Experience:"<<endl;
            if (tWexp_inst1[i]!= "0")
            {
                cout << "1."<<tWexp_inst1[i]<<endl;
                if(tWexp_inst2[i]!= "0")
                {
                  cout << "2."<<tWexp_inst2[i]<<endl;
                  if (tWexp_inst3[i]!= "0")
                  {
                     cout << "3."<<tWexp_inst3[i]<<endl;
                  }
                }
            }
            else
            {
                cout << "No work Experience"<<endl;
            }
            cout << "City:"<<city[i]<<endl;
            cout << "Address:"<<adress[i]<<endl;
            cout << "Phone number:"<<number[i]<<endl;
            cout <<endl;

        }
    }
    void loadDatatoFileS ()
    {
        ofstream studentDataFile ("Student_data.txt");
        ofstream totalnumber1File ("Total_number1.txt");
        for (int i=0; i<totalnumber1; i++)
        {
          studentDataFile << name[i] << "," << fname[i] << "," <<DOB[i]<< "," << CNIC[i] << "," << regno[i] << "," << department[i] << "," << student_semester[i] << "," << matric_number[i] << "," << matricyear[i] << "," << matricboard[i] << "," << inter_number[i] << "," << interyear[i] << "," <<
          interboard[i] << ","  << city[i] << "," << adress[i] << ","  << number[i]<<endl;
        }
        studentDataFile.close();
        totalnumber1File << totalnumber1;
        totalnumber1File.close();
    }
    void loadDataFromFileS()
    {
        ifstream studentDataFile ("Student_data.txt");
        ifstream totalnumber1File ("Total_number1.txt");
        vector <string> lines;
        string line;
        while (getline(studentDataFile,line))
        {
            lines.push_back(line);
        }
        studentDataFile.close();
        for (int i=0; i<lines.size(); i++)
        {
            stringstream A(lines[i]);
            string B;
            getline(A,name[i],',');
            getline(A,fname[i], ',');
            getline(A,DOB[i], ',');
            getline(A,B, ',');
            CNIC[i]= stoll(B);
            getline(A,regno[i],',');
            getline(A,department[i], ',');
            getline(A,student_semester[i], ',');
            getline(A,B, ',');
            matric_number[i]= stoi(B);
            getline(A,B, ',');
            matricyear[i] = stoi(B);
            getline(A,matricboard[i], ',');
            getline(A,B, ',');
            inter_number[i] = stoi(B);
            getline(A,B, ',');
            interyear[i] = stoi(B);
            getline(A,interboard[i], ',');
            getline(A,city[i], ',');
            getline(A,adress[i], ',');
            getline(A,number[i], ',');

        }
        totalnumber1File>>totalnumber1;
        totalnumber1File.close();
    }
  void loadDatatoFileT()
   {
        ofstream teacherDataFile("Teacher_data.txt");
        ofstream totalnumber2File("Total_number2.txt");
        for (int i = 0; i < totalnumber2; i++)
        {
            teacherDataFile << name[i] << "," << fname[i] << "," << DOB[i] << "," << CNIC[i] << "," << city[i] << "," << adress[i] << "," << number[i] << "," << gender[i] << "," << matric_number[i] << "," << matricyear[i] << ","
            << matricboard[i] << "," << inter_number[i] << "," << interyear[i] << "," << interboard[i] << "," << tBS[i] << "," << tBS_year[i] << "," << tBS_inst[i] << "," << tMPhil[i] << "," << tMPhil_year[i] << "," << tMPhil_inst[i]
            << "," << tPHD[i] << "," << tPHD_inst[i] << "," << tWexp_inst1[i] << "," << tWexp_inst2[i] << "," << tWexp_inst3[i] << "," << department[i] << "," <<regno[i]<< endl;
        }
        teacherDataFile.close();
        totalnumber2File << totalnumber2;
        totalnumber2File.close();
    }

    void loadDataFromFileT()
    {
        ifstream teacherDataFile("Teacher_data.txt");
        ifstream totalnumber2File("Total_number2.txt");
        vector<string> lines;
        string line;
        while (getline(teacherDataFile, line)) {
            lines.push_back(line);
        }
        teacherDataFile.close();
        for (int i = 0; i < lines.size(); i++) {
            stringstream A(lines[i]);
            string B;
            getline(A, name[i], ',');
            getline(A, fname[i], ',');
            getline(A, DOB[i], ',');
            getline(A, B, ',');
            CNIC[i] = stoll(B);
            getline(A, city[i], ',');
            getline(A, adress[i], ',');
            getline(A, number[i], ',');
            getline(A, gender[i], ',');
            getline(A, B, ',');
            matric_number[i] = stoi(B);
            getline(A, B, ',');
            matricyear[i] = stoi(B);
            getline(A, matricboard[i], ',');
            getline(A, B, ',');
            inter_number[i] = stoi(B);
            getline(A, B, ',');
            interyear[i] = stoi(B);
            getline(A, interboard[i], ',');
            getline(A, tBS[i], ',');
            getline(A, B, ',');
            tBS_year[i] = stoi(B);
            getline(A, tBS_inst[i], ',');
            getline(A, tMPhil[i], ',');
            getline(A, B, ',');
            tMPhil_year[i] = stoi(B);
            getline(A, tMPhil_inst[i], ',');
            getline(A, tPHD[i], ',');
            getline(A, tPHD_inst[i], ',');
            getline(A, tWexp_inst1[i], ',');
            getline(A, tWexp_inst2[i], ',');
            getline(A, tWexp_inst3[i], ',');
            getline(A, department[i], ',');
            getline(A, regno[i], ',');
        }
        totalnumber2File >> totalnumber2;
        totalnumber2File.close();
    }
};

class Teacher : virtual public admin
{
private:
    vector<string> teacher_name;
    vector<string> teacher_password;
    vector<int> teacher_numberofcourses;
    vector<string> teacher_courses;
    vector<string> teacher_ID;
    vector<string> teacher_classes;

public:
 void teacher_credentials (int index)
 {
   loadDataFromFileT();
    string temp;
    int temp_no;
    cout << "Name:"<<name[index]<<endl;
    cout << "ID:" <<regno[index]<<endl;
    teacher_name.push_back(name[index]);
    teacher_ID.push_back(regno[index]);
    cout << "Enter your password:";
    getline(cin,temp);
    teacher_password.push_back(temp);
    cout << department[index]<<endl;
    subject_allocation(department[index],teacher_numberofcourses,teacher_courses,teacher_classes);
    cout << endl;
    LoadTeacherCredentailstoFile();
 }

 void display_teacher_credentials ()
 {
    int x=0;
    int x2=0;
    for (int i=0; i<teacher_name.size(); i++)
    {
       cout << "Name:"<<teacher_name[i]<<endl;
       cout << "ID:"<<teacher_ID[i]<<endl;
       cout << "Number of Courses:"<<teacher_numberofcourses[i]<<endl;
       int y1=1;
       for (int l=x; l<x+teacher_numberofcourses[i]; l++)
       {
           cout << y1 << ")"<<teacher_courses[l]<<endl;
           y1++;
       }
       int y2=1;
       cout << "Teacher Classes:"<<endl;
       for (int z=x2; z<x2+2; z++)
       {
           cout << y2 << ")"<<teacher_classes[z]<<endl;
       }
       x2+=2;
       x+=teacher_numberofcourses[i];
       cout << endl;
    }
 }

 void LoadTeacherCredentailstoFile ()
 {
        int x1=0;
        int x2=0;
        ofstream TeacherCredentialsFile ("TCredentials.txt");
        for (int i=0; i<teacher_name.size(); i++)
        {
            TeacherCredentialsFile << teacher_name[i] << "," << teacher_password[i] << "," <<  teacher_ID[i] << "," << teacher_numberofcourses[i];
            for (int l=x1; l<x1+teacher_numberofcourses[i]; l++)
            {

                TeacherCredentialsFile << "," <<teacher_courses[l];
            }
            x1+=teacher_numberofcourses[i];
            for (int z=x2; z<x2+2; z++)
            {
                TeacherCredentialsFile << "," <<teacher_classes[z];
            }
            x2+=2;
            TeacherCredentialsFile<<endl;
        }
        TeacherCredentialsFile.close();
 }

 void LoadTeacherCredentialsFromFile()
 {
    int x=0;
    ifstream TeacherCredentialsFile("TCredentials.txt");
    string line;
    while (getline(TeacherCredentialsFile, line))
    {
        if (line.empty())
        {
            break;
        }
        stringstream ss(line);
        string token;
        getline(ss, token, ',');
        teacher_name.push_back(token);
        getline(ss, token, ',');
        teacher_password.push_back(token);
        getline(ss,token, ',');
        teacher_ID.push_back(token);
        getline(ss, token, ',');
        int numCourses = stoi(token);
        teacher_numberofcourses.push_back(numCourses);
        for (int i=0; i < numCourses; ++i)
        {
            getline(ss, token, ',');
            teacher_courses.push_back(token);
        }
        for (int i=0; i<2; i++)
        {
            getline(ss,token, ',');
            teacher_classes.push_back(token);
        }
    }
    TeacherCredentialsFile.close();
 }

 int check1Tnameforlogin (string tname)
 {
    loadDataFromFileT();
    for (int i=0; i<totalnumber2; i++)
    {
        if (tname==name[i])
        {
            return i;
        }
    }
    return -1;
 }

 bool check2Tnameforlogin (string tname)
 {
    for (int i=0; i<teacher_name.size(); i++)
    {
        if (tname==teacher_name[i])
        {
            return false;
        }
    }
    return true;
 }
bool check3TCredentialsforlogin (string tname, string tpassword)
{
    for (int i=0; i<teacher_name.size();i++)
    {
        if(tname==teacher_name[i])
        {
            if(tpassword==teacher_password[i])
            {
                return true;
            }
            else
            {
                return false;
            }
        }

    }
}
string check4TCredentialsforlogin (string tID, string tname)
{
    string message = "Come again next time!";
    for (int i=0; i<teacher_ID.size(); i++)
    {
        if (tID==teacher_ID[i])
        {
            teacher_name[i]==tname;
            return teacher_password[i];
        }
        else
        {
            return message;
        }
    }
}
bool check5TCredentialsforlogin (string tname)
{
    for (int i=0; i<teacher_name.size(); i++)
    {
        if (tname==teacher_name[i])
        {
            return true;
        }
    }
    return false;
}
void class_selection (string tpassword, string &temp, string &temp1)
{
    for (int i=0; i<teacher_password.size(); i++)
    {
        if(tpassword==teacher_password[i])
        {
            cout << "Select Your Class:"<<endl;
            cout << "1." <<teacher_classes[i+i]<<endl;
            cout << "2."<<teacher_classes[i+i+1]<<endl;
            int a;
            cin>>a;
            if (a==1)
            {
                cout << teacher_classes[i+i]<<endl;
                temp = teacher_classes[i+i];
                cout << teacher_courses[i+i]<<endl;
                temp1= teacher_courses[i+i];
            }
            else if (a==2)
            {
                cout << teacher_classes[i+i+1]<<endl;
                temp = teacher_classes[i+i+1];
                cout << teacher_courses[i+i+1]<<endl;
                temp1= teacher_courses[i+i+1];
            }
        }
    }
}
};
class Class:virtual public admin
{
protected:
  vector<string>temp1;
  vector<string>temp2;
  vector<int>quizA1;vector<int>quizA2;vector<int>assignmentA1;vector<int>Amid;vector<int>Afinals;
  vector<int>quizB1;vector<int>quizB2;vector<int>assignmentB1;vector<int>Bmid;vector<int>Bfinals;
  vector<int>quizC1;vector<int>quizC2;vector<int>assignmentC1;vector<int>Cmid;vector<int>Cfinals;
  vector<int>quizD1;vector<int>quizD2;vector<int>assignmentD1;vector<int>Dmid;vector<int>Dfinals;
  vector<int>quizE1;vector<int>quizE2;vector<int>assignmentE1;vector<int>Emid;vector<int>Efinals;
  vector<int>quizF1;vector<int>quizF2;vector<int>assignmentF1;vector<int>Fmid;vector<int>Ffinals;
public:
void (Class::*loadtoFunctions[4])()= {&Class::loaddatacs1tofile,&Class::loaddatacs3tofile,&Class::loaddataee1tofile, &Class::loaddataee3tofile};
void (Class::*loadfromFunctions[4])()= {&Class::loaddatacs1fromfile,&Class::loaddatacs3fromfile,&Class::loaddataee1fromfile, &Class::loaddataee3fromfile};
  void initial_separation()
  {
      loadDataFromFileS();
    init();
    for (int z = 0; z < classes.size(); z++)
    {
        (this->*loadfromFunctions[z])();

        for (int i = 0; i < totalnumber1; i++)
        {
            if (student_semester[i] == classes[z])
            {
                bool found = false;
                for (int y = 0; y < temp1.size(); y++)
                {
                    if (name[i] == temp1[y])
                    {
                        found = true;
                        break;
                    }
                }
                if (!found)
                {
                    temp1.push_back(name[i]);
                    temp2.push_back(regno[i]);
                }
            }
        }
         (this->*loadtoFunctions[z])();
    }

}

void complex_selection (string temp, string coursetemp)
{ init();
    for (int i=0; i<classes.size(); i++)
    {
        if (temp==classes[i])
        {
            int temp1;
            (this->*loadfromFunctions[i])();
            display_class();
            string temp2[5];

                temp2[0]= "Quiz 1"; temp2[1]="Quiz 2"; temp2[2]= "Assignment 1";temp2[3] = "Mids"; temp2[4]= "Finals";
                cout << "Select Index:"<<endl;
                for (int i=0; i<5; i++)
                {
                   cout << i+1 << "." << temp2[i]<<endl;

                }
                cin>>temp1;
                system("cls");
                enter_marks(temp2[temp1-1],temp1,coursetemp,temp);
                (this->*loadtoFunctions[i])();
        }
    }
}

  void loaddatacs1tofile()
  {
      ofstream datacs1to("CS-1st semster.txt");
      for(int i=0; i<temp1.size(); i++)
      {
        datacs1to<< temp1[i]<<","<<temp2[i];
        if (i < quizA1.size()) datacs1to << "," << quizA1[i];
        else datacs1to << ","<<0;
        if (i < quizA2.size()) datacs1to << "," << quizA2[i];
        else datacs1to << ","<<0;
        if (i < assignmentA1.size()) datacs1to << "," << assignmentA1[i];
        else datacs1to << ","<<0;
        if (i < Amid.size()) datacs1to << "," << Amid[i];
        else datacs1to << ","<<0;
        if (i < Afinals.size()) datacs1to << "," << Afinals[i];
        else datacs1to << ","<<0;
        if (i < quizB1.size()) datacs1to << "," << quizB1[i];
        else datacs1to << ","<<0;
        if (i < quizB2.size()) datacs1to << "," << quizB2[i];
        else datacs1to << ","<<0;
        if (i < assignmentB1.size()) datacs1to << "," << assignmentB1[i];
        else datacs1to << ","<<0;
        if (i < Bmid.size()) datacs1to << "," << Bmid[i];
        else datacs1to << ","<<0;
        if (i < Bfinals.size()) datacs1to << "," << Bfinals[i];
        else datacs1to << ","<<0;
        if (i < quizC1.size()) datacs1to << "," << quizC1[i];
        else datacs1to << ","<<0;
        if (i < quizC2.size()) datacs1to << "," << quizC2[i];
        else datacs1to << ","<<0;
        if (i < assignmentC1.size()) datacs1to << "," << assignmentC1[i];
        else datacs1to << ","<<0;
        if (i < Cmid.size()) datacs1to << "," << Cmid[i];
        else datacs1to << ","<<0;
        if (i < Cfinals.size()) datacs1to << "," << Cfinals[i];
        else datacs1to << ","<<0;
        if (i < quizD1.size()) datacs1to << "," << quizD1[i];
        else datacs1to << ","<<0;
        if (i < quizD2.size()) datacs1to << "," << quizD2[i];
        else datacs1to << ","<<0;
        if (i < assignmentD1.size()) datacs1to << "," << assignmentD1[i];
        else datacs1to << ","<<0;
        if (i < Dmid.size()) datacs1to << "," << Dmid[i];
        else datacs1to << ","<<0;
        if (i < Dfinals.size()) datacs1to << "," << Dfinals[i];
        else datacs1to << ","<<0;
        if (i < quizE1.size()) datacs1to << "," << quizE1[i];
        else datacs1to << ","<<0;
        if (i < quizE2.size()) datacs1to << "," << quizE2[i];
        else datacs1to << ","<<0;
        if (i < assignmentE1.size()) datacs1to << "," << assignmentE1[i];
        else datacs1to << ","<<0;
        if (i < Emid.size()) datacs1to << "," << Emid[i];
        else datacs1to << ","<<0;
        if (i < Efinals.size()) datacs1to << "," << Efinals[i];
        else datacs1to << ","<<0;
        if (i < quizF1.size()) datacs1to << "," << quizF1[i];
        else datacs1to << ","<<0;
        if (i < quizF2.size()) datacs1to << "," << quizF2[i];
        else datacs1to << ","<<0;
        if (i < assignmentF1.size()) datacs1to << "," << assignmentF1[i];
        else datacs1to << ","<<0;
        if (i < Fmid.size()) datacs1to << "," << Fmid[i];
        else datacs1to << ","<<0;
        if (i < Ffinals.size()) datacs1to << "," << Ffinals[i];
        else datacs1to << ","<<0;
        datacs1to << endl;
      }
       datacs1to.close();
  }
  void loaddatacs3tofile()
  {

      ofstream datacs3to("CS-3rd semster.txt");
      for(int i=0; i<temp1.size(); i++)
      {
        datacs3to<< temp1[i]<<","<<temp2[i];
        if (i < quizA1.size()) datacs3to << "," << quizA1[i];
        else datacs3to << ","<<0;
        if (i < quizA2.size()) datacs3to << "," << quizA2[i];
        else datacs3to << ","<<0;
        if (i < assignmentA1.size()) datacs3to << "," << assignmentA1[i];
        else datacs3to << ","<<0;
        if (i < Amid.size()) datacs3to << "," << Amid[i];
        else datacs3to << ","<<0;
        if (i < Afinals.size()) datacs3to << "," << Afinals[i];
        else datacs3to << ","<<0;
        if (i < quizB1.size()) datacs3to << "," << quizB1[i];
        else datacs3to << ","<<0;
        if (i < quizB2.size()) datacs3to << "," << quizB2[i];
        else datacs3to << ","<<0;
        if (i < assignmentB1.size()) datacs3to << "," << assignmentB1[i];
        else datacs3to << ","<<0;
        if (i < Bmid.size()) datacs3to << "," << Bmid[i];
        else datacs3to << ","<<0;
        if (i < Bfinals.size()) datacs3to << "," << Bfinals[i];
        else datacs3to << ","<<0;
        if (i < quizC1.size()) datacs3to << "," << quizC1[i];
        else datacs3to << ","<<0;
        if (i < quizC2.size()) datacs3to << "," << quizC2[i];
        else datacs3to << ","<<0;
        if (i < assignmentC1.size()) datacs3to << "," << assignmentC1[i];
        else datacs3to << ","<<0;
        if (i < Cmid.size()) datacs3to << "," << Cmid[i];
        else datacs3to << ","<<0;
        if (i < Cfinals.size()) datacs3to << "," << Cfinals[i];
        else datacs3to << ","<<0;
        if (i < quizD1.size()) datacs3to << "," << quizD1[i];
        else datacs3to << ","<<0;
        if (i < quizD2.size()) datacs3to << "," << quizD2[i];
        else datacs3to << ","<<0;
        if (i < assignmentD1.size()) datacs3to << "," << assignmentD1[i];
        else datacs3to << ","<<0;
        if (i < Dmid.size()) datacs3to << "," << Dmid[i];
        else datacs3to << ","<<0;
        if (i < Dfinals.size()) datacs3to << "," << Dfinals[i];
        else datacs3to << ","<<0;
        if (i < quizE1.size()) datacs3to << "," << quizE1[i];
        else datacs3to << ","<<0;
        if (i < quizE2.size()) datacs3to << "," << quizE2[i];
        else datacs3to << ","<<0;
        if (i < assignmentE1.size()) datacs3to << "," << assignmentE1[i];
        else datacs3to << ","<<0;
        if (i < Emid.size()) datacs3to << "," << Emid[i];
        else datacs3to << ","<<0;
        if (i < Efinals.size()) datacs3to << "," << Efinals[i];
        else datacs3to << ","<<0;
        if (i < quizF1.size()) datacs3to << "," << quizF1[i];
        else datacs3to << ","<<0;
        if (i < quizF2.size()) datacs3to << "," << quizF2[i];
        else datacs3to << ","<<0;
        if (i < assignmentF1.size()) datacs3to << "," << assignmentF1[i];
        else datacs3to << ","<<0;
        if (i < Fmid.size()) datacs3to << "," << Fmid[i];
        else datacs3to << ","<<0;
        if (i < Ffinals.size()) datacs3to << "," << Ffinals[i];
        else datacs3to << ","<<0;
        datacs3to << endl;
      }

       datacs3to.close();
  }
   void loaddataee1tofile()
  {
      ofstream dataee1to("EE-1st semster.txt");
      for(int i=0; i<temp1.size(); i++)
      {
         dataee1to<< temp1[i]<<","<<temp2[i];
        if (i < quizA1.size()) dataee1to << "," << quizA1[i];
        else dataee1to << ","<<0;
        if (i < quizA2.size()) dataee1to << "," << quizA2[i];
        else dataee1to << ","<<0;
        if (i < assignmentA1.size()) dataee1to << "," << assignmentA1[i];
        else dataee1to << ","<<0;
        if (i < Amid.size()) dataee1to << "," << Amid[i];
        else dataee1to << ","<<0;
        if (i < Afinals.size()) dataee1to << "," << Afinals[i];
        else dataee1to << ","<<0;
        if (i < quizB1.size()) dataee1to << "," << quizB1[i];
        else dataee1to << ","<<0;
        if (i < quizB2.size()) dataee1to << "," << quizB2[i];
        else dataee1to << ","<<0;
        if (i < assignmentB1.size()) dataee1to << "," << assignmentB1[i];
        else dataee1to << ","<<0;
        if (i < Bmid.size()) dataee1to << "," << Bmid[i];
        else dataee1to << ","<<0;
        if (i < Bfinals.size()) dataee1to << "," << Bfinals[i];
        else dataee1to << ","<<0;
        if (i < quizC1.size()) dataee1to << "," << quizC1[i];
        else dataee1to << ","<<0;
        if (i < quizC2.size()) dataee1to << "," << quizC2[i];
        else dataee1to << ","<<0;
        if (i < assignmentC1.size()) dataee1to << "," << assignmentC1[i];
        else dataee1to << ","<<0;
        if (i < Cmid.size()) dataee1to << "," << Cmid[i];
        else dataee1to << ","<<0;
        if (i < Cfinals.size()) dataee1to << "," << Cfinals[i];
        else dataee1to << ","<<0;
        if (i < quizD1.size()) dataee1to << "," << quizD1[i];
        else dataee1to << ","<<0;
        if (i < quizD2.size()) dataee1to << "," << quizD2[i];
        else dataee1to << ","<<0;
        if (i < assignmentD1.size()) dataee1to << "," << assignmentD1[i];
        else dataee1to << ","<<0;
        if (i < Dmid.size()) dataee1to << "," << Dmid[i];
        else dataee1to << ","<<0;
        if (i < Dfinals.size()) dataee1to << "," << Dfinals[i];
        else dataee1to << ","<<0;
        if (i < quizE1.size()) dataee1to << "," << quizE1[i];
        else dataee1to << ","<<0;
        if (i < quizE2.size()) dataee1to << "," << quizE2[i];
        else dataee1to << ","<<0;
        if (i < assignmentE1.size()) dataee1to << "," << assignmentE1[i];
        else dataee1to << ","<<0;
        if (i < Emid.size()) dataee1to << "," << Emid[i];
        else dataee1to << ","<<0;
        if (i < Efinals.size()) dataee1to << "," << Efinals[i];
        else dataee1to << ","<<0;
        if (i < quizF1.size()) dataee1to << "," << quizF1[i];
        else dataee1to << ","<<0;
        if (i < quizF2.size()) dataee1to << "," << quizF2[i];
        else dataee1to << ","<<0;
        if (i < assignmentF1.size()) dataee1to << "," << assignmentF1[i];
        else dataee1to << ","<<0;
        if (i < Fmid.size()) dataee1to << "," << Fmid[i];
        else dataee1to << ","<<0;
        if (i < Ffinals.size()) dataee1to << "," << Ffinals[i];
        else dataee1to << ","<<0;
        dataee1to << endl;
      }

       dataee1to.close();
  }
   void loaddataee3tofile()
  {
      ofstream dataee3to("EE-3rd semster.txt");
      for(int i=0; i<temp1.size(); i++)
      {
         dataee3to<< temp1[i]<<","<<temp2[i];
        if (i < quizA1.size()) dataee3to << "," << quizA1[i];
        else dataee3to << ","<<0;
        if (i < quizA2.size()) dataee3to << "," << quizA2[i];
        else dataee3to << ","<<0;
        if (i < assignmentA1.size()) dataee3to << "," << assignmentA1[i];
        else dataee3to << ","<<0;
        if (i < Amid.size()) dataee3to << "," << Amid[i];
        else dataee3to << ","<<0;
        if (i < Afinals.size()) dataee3to << "," << Afinals[i];
        else dataee3to << ","<<0;
        if (i < quizB1.size()) dataee3to << "," << quizB1[i];
        else dataee3to << ","<<0;
        if (i < quizB2.size()) dataee3to << "," << quizB2[i];
        else dataee3to << ","<<0;
        if (i < assignmentB1.size()) dataee3to << "," << assignmentB1[i];
        else dataee3to << ","<<0;
        if (i < Bmid.size()) dataee3to << "," << Bmid[i];
        else dataee3to << ","<<0;
        if (i < Bfinals.size()) dataee3to << "," << Bfinals[i];
        else dataee3to << ","<<0;
        if (i < quizC1.size()) dataee3to << "," << quizC1[i];
        else dataee3to << ","<<0;
        if (i < quizC2.size()) dataee3to << "," << quizC2[i];
        else dataee3to << ","<<0;
        if (i < assignmentC1.size()) dataee3to << "," << assignmentC1[i];
        else dataee3to << ","<<0;
        if (i < Cmid.size()) dataee3to << "," << Cmid[i];
        else dataee3to << ","<<0;
        if (i < Cfinals.size()) dataee3to << "," << Cfinals[i];
        else dataee3to << ","<<0;
        if (i < quizD1.size()) dataee3to << "," << quizD1[i];
        else dataee3to << ","<<0;
        if (i < quizD2.size()) dataee3to << "," << quizD2[i];
        else dataee3to << ","<<0;
        if (i < assignmentD1.size()) dataee3to << "," << assignmentD1[i];
        else dataee3to << ","<<0;
        if (i < Dmid.size()) dataee3to << "," << Dmid[i];
        else dataee3to << ","<<0;
        if (i < Dfinals.size()) dataee3to << "," << Dfinals[i];
        else dataee3to << ","<<0;
        if (i < quizE1.size()) dataee3to << "," << quizE1[i];
        else dataee3to << ","<<0;
        if (i < quizE2.size()) dataee3to << "," << quizE2[i];
        else dataee3to << ","<<0;
        if (i < assignmentE1.size()) dataee3to << "," << assignmentE1[i];
        else dataee3to << ","<<0;
        if (i < Emid.size()) dataee3to << "," << Emid[i];
        else dataee3to << ","<<0;
        if (i < Efinals.size()) dataee3to << "," << Efinals[i];
        else dataee3to << ","<<0;
        if (i < quizF1.size()) dataee3to << "," << quizF1[i];
        else dataee3to << ","<<0;
        if (i < quizF2.size()) dataee3to << "," << quizF2[i];
        else dataee3to << ","<<0;
        if (i < assignmentF1.size()) dataee3to << "," << assignmentF1[i];
        else dataee3to << ","<<0;
        if (i < Fmid.size()) dataee3to << "," << Fmid[i];
        else dataee3to << ","<<0;
        if (i < Ffinals.size()) dataee3to << "," << Ffinals[i];
        else dataee3to << ","<<0;
        dataee3to << endl;
      }

       dataee3to.close();
  }
void loaddatacs1fromfile()
{
    temp1.clear();temp2.clear();
    quizA1.clear();quizA2.clear();assignmentA1.clear();Amid.clear();Afinals.clear();
    quizB1.clear();quizB2.clear();assignmentB1.clear();Bmid.clear();Bfinals.clear();
    quizC1.clear();quizC2.clear();assignmentC1.clear();Cmid.clear();Cfinals.clear();
    quizD1.clear();quizD2.clear();assignmentD1.clear();Dmid.clear();Dfinals.clear();
    quizE1.clear();quizE2.clear();assignmentE1.clear();Emid.clear();Efinals.clear();
    quizF1.clear();quizF2.clear();assignmentF1.clear();Fmid.clear();Ffinals.clear();

    string line;
    ifstream datacsf("CS-1st semster.txt");
    while (getline(datacsf, line))
    {
        if (line.empty())
            break;

        stringstream sss(line);
        string name, regno;
        getline(sss, name, ',');
        temp1.push_back(name);
        getline(sss, regno, ',');
        temp2.push_back(regno);

        getline(sss, line, ',');
        quizA1.push_back(stoi(line));
        getline(sss, line, ',');
        quizA2.push_back(stoi(line));
        getline(sss, line, ',');
        assignmentA1.push_back(stoi(line));
        getline(sss, line, ',');
        Amid.push_back(stoi(line));
        getline(sss, line, ',');
        Afinals.push_back(stoi(line));

        getline(sss, line, ',');
        quizB1.push_back(stoi(line));
        getline(sss, line, ',');
        quizB2.push_back(stoi(line));
        getline(sss, line, ',');
        assignmentB1.push_back(stoi(line));
        getline(sss, line, ',');
        Bmid.push_back(stoi(line));
        getline(sss, line, ',');
        Bfinals.push_back(stoi(line));

        getline(sss, line, ',');
        quizC1.push_back(stoi(line));
        getline(sss, line, ',');
        quizC2.push_back(stoi(line));
        getline(sss, line, ',');
        assignmentC1.push_back(stoi(line));
        getline(sss, line, ',');
        Cmid.push_back(stoi(line));
        getline(sss, line, ',');
        Cfinals.push_back(stoi(line));

        getline(sss, line, ',');
        quizD1.push_back(stoi(line));
        getline(sss, line, ',');
        quizD2.push_back(stoi(line));
        getline(sss, line, ',');
        assignmentD1.push_back(stoi(line));
        getline(sss, line, ',');
        Dmid.push_back(stoi(line));
        getline(sss, line, ',');
        Dfinals.push_back(stoi(line));

        getline(sss, line, ',');
        quizE1.push_back(stoi(line));
        getline(sss, line, ',');
        quizE2.push_back(stoi(line));
        getline(sss, line, ',');
        assignmentE1.push_back(stoi(line));
        getline(sss, line, ',');
        Emid.push_back(stoi(line));
        getline(sss, line, ',');
        Efinals.push_back(stoi(line));

        getline(sss, line, ',');
        quizF1.push_back(stoi(line));
        getline(sss, line, ',');
        quizF2.push_back(stoi(line));
        getline(sss, line, ',');
        assignmentF1.push_back(stoi(line));
        getline(sss, line, ',');
        Fmid.push_back(stoi(line));
        getline(sss, line, ',');
        Ffinals.push_back(stoi(line));
    }
    datacsf.close();
}
void loaddatacs3fromfile ()
{
    temp1.clear();temp2.clear();
    quizA1.clear();quizA2.clear();assignmentA1.clear();Amid.clear();Afinals.clear();
    quizB1.clear();quizB2.clear();assignmentB1.clear();Bmid.clear();Bfinals.clear();
    quizC1.clear();quizC2.clear();assignmentC1.clear();Cmid.clear();Cfinals.clear();
    quizD1.clear();quizD2.clear();assignmentD1.clear();Dmid.clear();Dfinals.clear();
    quizE1.clear();quizE2.clear();assignmentE1.clear();Emid.clear();Efinals.clear();
    quizF1.clear();quizF2.clear();assignmentF1.clear();Fmid.clear();Ffinals.clear();

    string line;
    ifstream datacsf("CS-3rd semster.txt");
    while (getline(datacsf, line))
    {
        if (line.empty())
            break;

        stringstream sss(line);
        string name, regno;
        getline(sss, name, ',');
        temp1.push_back(name);
        getline(sss, regno, ',');
        temp2.push_back(regno);

        getline(sss, line, ',');
        quizA1.push_back(stoi(line));
        getline(sss, line, ',');
        quizA2.push_back(stoi(line));
        getline(sss, line, ',');
        assignmentA1.push_back(stoi(line));
        getline(sss, line, ',');
        Amid.push_back(stoi(line));
        getline(sss, line, ',');
        Afinals.push_back(stoi(line));

        getline(sss, line, ',');
        quizB1.push_back(stoi(line));
        getline(sss, line, ',');
        quizB2.push_back(stoi(line));
        getline(sss, line, ',');
        assignmentB1.push_back(stoi(line));
        getline(sss, line, ',');
        Bmid.push_back(stoi(line));
        getline(sss, line, ',');
        Bfinals.push_back(stoi(line));

        getline(sss, line, ',');
        quizC1.push_back(stoi(line));
        getline(sss, line, ',');
        quizC2.push_back(stoi(line));
        getline(sss, line, ',');
        assignmentC1.push_back(stoi(line));
        getline(sss, line, ',');
        Cmid.push_back(stoi(line));
        getline(sss, line, ',');
        Cfinals.push_back(stoi(line));

        getline(sss, line, ',');
        quizD1.push_back(stoi(line));
        getline(sss, line, ',');
        quizD2.push_back(stoi(line));
        getline(sss, line, ',');
        assignmentD1.push_back(stoi(line));
        getline(sss, line, ',');
        Dmid.push_back(stoi(line));
        getline(sss, line, ',');
        Dfinals.push_back(stoi(line));

        getline(sss, line, ',');
        quizE1.push_back(stoi(line));
        getline(sss, line, ',');
        quizE2.push_back(stoi(line));
        getline(sss, line, ',');
        assignmentE1.push_back(stoi(line));
        getline(sss, line, ',');
        Emid.push_back(stoi(line));
        getline(sss, line, ',');
        Efinals.push_back(stoi(line));

        getline(sss, line, ',');
        quizF1.push_back(stoi(line));
        getline(sss, line, ',');
        quizF2.push_back(stoi(line));
        getline(sss, line, ',');
        assignmentF1.push_back(stoi(line));
        getline(sss, line, ',');
        Fmid.push_back(stoi(line));
        getline(sss, line, ',');
        Ffinals.push_back(stoi(line));
    }
    datacsf.close();
}
  void loaddataee1fromfile()
  {
    temp1.clear();temp2.clear();
    quizA1.clear();quizA2.clear();assignmentA1.clear();Amid.clear();Afinals.clear();
    quizB1.clear();quizB2.clear();assignmentB1.clear();Bmid.clear();Bfinals.clear();
    quizC1.clear();quizC2.clear();assignmentC1.clear();Cmid.clear();Cfinals.clear();
    quizD1.clear();quizD2.clear();assignmentD1.clear();Dmid.clear();Dfinals.clear();
    quizE1.clear();quizE2.clear();assignmentE1.clear();Emid.clear();Efinals.clear();
    quizF1.clear();quizF2.clear();assignmentF1.clear();Fmid.clear();Ffinals.clear();

    string line;
    ifstream datacsf("EE-1st semster.txt");
    while (getline(datacsf, line))
    {
        if (line.empty())
            break;

        stringstream sss(line);
        string name, regno;
        getline(sss, name, ',');
        temp1.push_back(name);
        getline(sss, regno, ',');
        temp2.push_back(regno);

        getline(sss, line, ',');
        quizA1.push_back(stoi(line));
        getline(sss, line, ',');
        quizA2.push_back(stoi(line));
        getline(sss, line, ',');
        assignmentA1.push_back(stoi(line));
        getline(sss, line, ',');
        Amid.push_back(stoi(line));
        getline(sss, line, ',');
        Afinals.push_back(stoi(line));

        getline(sss, line, ',');
        quizB1.push_back(stoi(line));
        getline(sss, line, ',');
        quizB2.push_back(stoi(line));
        getline(sss, line, ',');
        assignmentB1.push_back(stoi(line));
        getline(sss, line, ',');
        Bmid.push_back(stoi(line));
        getline(sss, line, ',');
        Bfinals.push_back(stoi(line));

        getline(sss, line, ',');
        quizC1.push_back(stoi(line));
        getline(sss, line, ',');
        quizC2.push_back(stoi(line));
        getline(sss, line, ',');
        assignmentC1.push_back(stoi(line));
        getline(sss, line, ',');
        Cmid.push_back(stoi(line));
        getline(sss, line, ',');
        Cfinals.push_back(stoi(line));

        getline(sss, line, ',');
        quizD1.push_back(stoi(line));
        getline(sss, line, ',');
        quizD2.push_back(stoi(line));
        getline(sss, line, ',');
        assignmentD1.push_back(stoi(line));
        getline(sss, line, ',');
        Dmid.push_back(stoi(line));
        getline(sss, line, ',');
        Dfinals.push_back(stoi(line));

        getline(sss, line, ',');
        quizE1.push_back(stoi(line));
        getline(sss, line, ',');
        quizE2.push_back(stoi(line));
        getline(sss, line, ',');
        assignmentE1.push_back(stoi(line));
        getline(sss, line, ',');
        Emid.push_back(stoi(line));
        getline(sss, line, ',');
        Efinals.push_back(stoi(line));

        getline(sss, line, ',');
        quizF1.push_back(stoi(line));
        getline(sss, line, ',');
        quizF2.push_back(stoi(line));
        getline(sss, line, ',');
        assignmentF1.push_back(stoi(line));
        getline(sss, line, ',');
        Fmid.push_back(stoi(line));
        getline(sss, line, ',');
        Ffinals.push_back(stoi(line));
    }
    datacsf.close();
  }

  void loaddataee3fromfile()
  {
    temp1.clear();temp2.clear();
    quizA1.clear();quizA2.clear();assignmentA1.clear();Amid.clear();Afinals.clear();
    quizB1.clear();quizB2.clear();assignmentB1.clear();Bmid.clear();Bfinals.clear();
    quizC1.clear();quizC2.clear();assignmentC1.clear();Cmid.clear();Cfinals.clear();
    quizD1.clear();quizD2.clear();assignmentD1.clear();Dmid.clear();Dfinals.clear();
    quizE1.clear();quizE2.clear();assignmentE1.clear();Emid.clear();Efinals.clear();
    quizF1.clear();quizF2.clear();assignmentF1.clear();Fmid.clear();Ffinals.clear();

    string line;
    ifstream datacsf("CS-3rd semster.txt");
    while (getline(datacsf, line))
    {
        if (line.empty())
            break;

        stringstream sss(line);
        string name, regno;
        getline(sss, name, ',');
        temp1.push_back(name);
        getline(sss, regno, ',');
        temp2.push_back(regno);

        getline(sss, line, ',');
        quizA1.push_back(stoi(line));
        getline(sss, line, ',');
        quizA2.push_back(stoi(line));
        getline(sss, line, ',');
        assignmentA1.push_back(stoi(line));
        getline(sss, line, ',');
        Amid.push_back(stoi(line));
        getline(sss, line, ',');
        Afinals.push_back(stoi(line));

        getline(sss, line, ',');
        quizB1.push_back(stoi(line));
        getline(sss, line, ',');
        quizB2.push_back(stoi(line));
        getline(sss, line, ',');
        assignmentB1.push_back(stoi(line));
        getline(sss, line, ',');
        Bmid.push_back(stoi(line));
        getline(sss, line, ',');
        Bfinals.push_back(stoi(line));

        getline(sss, line, ',');
        quizC1.push_back(stoi(line));
        getline(sss, line, ',');
        quizC2.push_back(stoi(line));
        getline(sss, line, ',');
        assignmentC1.push_back(stoi(line));
        getline(sss, line, ',');
        Cmid.push_back(stoi(line));
        getline(sss, line, ',');
        Cfinals.push_back(stoi(line));

        getline(sss, line, ',');
        quizD1.push_back(stoi(line));
        getline(sss, line, ',');
        quizD2.push_back(stoi(line));
        getline(sss, line, ',');
        assignmentD1.push_back(stoi(line));
        getline(sss, line, ',');
        Dmid.push_back(stoi(line));
        getline(sss, line, ',');
        Dfinals.push_back(stoi(line));

        getline(sss, line, ',');
        quizE1.push_back(stoi(line));
        getline(sss, line, ',');
        quizE2.push_back(stoi(line));
        getline(sss, line, ',');
        assignmentE1.push_back(stoi(line));
        getline(sss, line, ',');
        Emid.push_back(stoi(line));
        getline(sss, line, ',');
        Efinals.push_back(stoi(line));

        getline(sss, line, ',');
        quizF1.push_back(stoi(line));
        getline(sss, line, ',');
        quizF2.push_back(stoi(line));
        getline(sss, line, ',');
        assignmentF1.push_back(stoi(line));
        getline(sss, line, ',');
        Fmid.push_back(stoi(line));
        getline(sss, line, ',');
        Ffinals.push_back(stoi(line));
    }
    datacsf.close();
  }
  void display_class ()
  {
    cout << "NAME                 REG NO."<<endl;
    for (int i=0; i<temp1.size(); i++)
    {
        cout << temp1[i];
        gotoRowCol(i+8,20);
        cout << temp2[i]<<endl;
    }
  }
void enter_marks(string tempstring, int x, string coursetemp, string semestertemp)
{
    unordered_map<int, vector<int>*> vectorMapA;
    vectorMapA[0] = &quizA1; vectorMapA[1] = &quizA2; vectorMapA[2] = &assignmentA1; vectorMapA[3] = &Amid; vectorMapA[4] = &Afinals;
    unordered_map<int, vector<int>*> vectorMapB;
    vectorMapB[0] = &quizB1; vectorMapB[1] = &quizB2; vectorMapB[2] = &assignmentB1; vectorMapB[3] = &Bmid; vectorMapB[4] = &Bfinals;
    unordered_map<int, vector<int>*> vectorMapC;
    vectorMapC[0] = &quizC1; vectorMapC[1] = &quizC2; vectorMapC[2] = &assignmentC1; vectorMapC[3] = &Cmid; vectorMapC[4] = &Cfinals;
    unordered_map<int, vector<int>*> vectorMapD;
    vectorMapD[0] = &quizD1; vectorMapD[1] = &quizD2; vectorMapD[2] = &assignmentD1; vectorMapD[3] = &Dmid; vectorMapD[4] = &Dfinals;
    unordered_map<int, vector<int>*> vectorMapE;
    vectorMapE[0] = &quizE1; vectorMapE[1] = &quizE2; vectorMapE[2] = &assignmentE1; vectorMapE[3] = &Emid; vectorMapE[4] = &Efinals;
    unordered_map<int, vector<int>*> vectorMapF;
    vectorMapF[0] = &quizF1; vectorMapF[1] = &quizF2; vectorMapF[2] = &assignmentF1; vectorMapF[3] = &Fmid; vectorMapF[4] = &Ffinals;

    unordered_map<int, unordered_map<int, vector<int>*>*> coursemap;
    coursemap[0] = &vectorMapA; coursemap[1] = &vectorMapB; coursemap[2] = &vectorMapC;
    coursemap[3] = &vectorMapD; coursemap[4] = &vectorMapE; coursemap[5] = &vectorMapF;

    unordered_map<int, vector<string>*> vectorMap;
    vectorMap[0] = &S1CS; vectorMap[1] = &S3CS; vectorMap[2] = &S1EE; vectorMap[3] = &S3EE;

    for (int i = 0; i < classes.size(); i++)
    {
        if (semestertemp == classes[i])
        {
            for (int j = 0; j < (*vectorMap[i]).size(); j++)
            {
                const string& elem = (*vectorMap[i])[j];
                if (elem == coursetemp)
                {
                    auto selectedCourseMap = coursemap[j];
                    if (selectedCourseMap != nullptr)
                    {
                        vector<int>* targetVector = (*selectedCourseMap)[x - 1];
                        if (targetVector != nullptr)
                        {
                            cout << "NAME              " << tempstring << endl;
                            for (int k = 0; k < temp1.size(); k++)
                            {
                                cout << temp1[k];
                                gotoRowCol(k + 1, 20);
                                if ((*targetVector)[k] == 0)
                                {
                                    cin >> (*targetVector)[k];
                                }
                                else
                                {
                                    cout << (*targetVector)[k] << endl;
                                }
                            }
                        }
                    }
                }
            }
        }
    }

}
};

class student :virtual public admin, public Class
{
private:
    vector<string> student_name;
    vector<string> student_password;
    vector<string> student_ID;
    vector<string>student_s;

public:
void student_credentials (int in)
 {
    admin::loadDataFromFileS();
    LoadstudentCredentialsFromFile();
    string temp1;
    int temp_no1;
    cout << "Name:"<<name[in]<<endl;
    cout << "ID:" <<regno[in]<<endl;
    cout<<"Department:"<<student_semester[in]<<endl;
    student_name.push_back(name[in]);
    student_ID.push_back(regno[in]);
    student_s.push_back(student_semester[in]);
    cout << "Enter your password:";
    getline(cin,temp1);
    student_password.push_back(temp1);
    LoadstudentCredentailstoFile();
 }
void display_student_credentials ()
 {
    for (int i=0; i<student_name.size(); i++)
    {
       cout << "Name:"<<student_name[i]<<endl;
       cout << "ID:"<<student_ID[i]<<endl;
       cout<<"Department:"<<student_semester[i]<<endl;
       cout << endl;
    }
 }
 void LoadstudentCredentialsFromFile()
 {
     string line1;
     ifstream studentCredentialsFile("sCredentials.txt");
    while (getline(studentCredentialsFile, line1))
    {
        if (line1.empty())
        {
            break;
        }
        stringstream ss1(line1);
        string token1;
        getline(ss1, token1, ',');
        student_name.push_back(token1);
        getline(ss1, token1, ',');
        student_password.push_back(token1);
        getline(ss1,token1, ',');
        student_ID.push_back(token1);
        getline(ss1,token1, ',');
        student_s.push_back(token1);
        }
        studentCredentialsFile.close();
 }
  void LoadstudentCredentailstoFile ()
 {
        ofstream studentCredentialsFile ("sCredentials.txt");
        for (int i=0; i<student_name.size(); i++)
        {
            studentCredentialsFile << student_name[i] << "," << student_password[i] << "," <<  student_ID[i]<<","<<student_s[i];
            studentCredentialsFile<<endl;
        }
        studentCredentialsFile.close();
 }

int check1snameforlogin(string stname)
{
       loadDataFromFileS();
        for(int i=0; i<totalnumber1; i++)
        {
            if(stname==name[i])
            {
                return i;
            }
        }
        return -1;
}
 bool check2snameforlogin (string stname)
 {
    LoadstudentCredentialsFromFile();
    for (int i=0; i<student_name.size(); i++)
    {
        if (stname==student_name[i])
        {
            return false;
        }
    }
    return true;
 }
bool check3sCredentialsforlogin (string sname, string spassword)
{
    LoadstudentCredentialsFromFile();
    for (int i=0; i<student_name.size();i++)
    {
        if(sname==student_name[i])
        {
            if(spassword==student_password[i])
            {
                return true;
            }
            else
            {
                return false;
            }
        }

    }
}
string check4sCredentialsforlogin (string sID, string sname)
{
    LoadstudentCredentialsFromFile();
    string message = "Come again next time!";
    for (int i=0; i<student_ID.size(); i++)
    {
        if (sID==student_ID[i])
        {
           if( student_name[i]==sname)
           {
            return student_password[i];
           }
        }
        else
        {
            return message;
        }
    }
}
bool check5sCredentialsforlogin (string sname)
{
    LoadstudentCredentialsFromFile();
    for (int i=0; i<student_name.size(); i++)
    {
        if (sname==student_name[i])
        {
            return true;
        }
    }
    return false;
}
void student_portal (string sname)
{
    unordered_map<int, vector<int>*> vectorMapA;
    vectorMapA[0] = &quizA1; vectorMapA[1] = &quizA2; vectorMapA[2] = &assignmentA1; vectorMapA[3] = &Amid; vectorMapA[4] = &Afinals;
    unordered_map<int, vector<int>*> vectorMapB;
    vectorMapB[0] = &quizB1; vectorMapB[1] = &quizB2; vectorMapB[2] = &assignmentB1; vectorMapB[3] = &Bmid; vectorMapB[4] = &Bfinals;
    unordered_map<int, vector<int>*> vectorMapC;
    vectorMapC[0] = &quizC1; vectorMapC[1] = &quizC2; vectorMapC[2] = &assignmentC1; vectorMapC[3] = &Cmid; vectorMapC[4] = &Cfinals;
    unordered_map<int, vector<int>*> vectorMapD;
    vectorMapD[0] = &quizD1; vectorMapD[1] = &quizD2; vectorMapD[2] = &assignmentD1; vectorMapD[3] = &Dmid; vectorMapD[4] = &Dfinals;
    unordered_map<int, vector<int>*> vectorMapE;
    vectorMapE[0] = &quizE1; vectorMapE[1] = &quizE2; vectorMapE[2] = &assignmentE1; vectorMapE[3] = &Emid; vectorMapE[4] = &Efinals;
    unordered_map<int, vector<int>*> vectorMapF;
    vectorMapF[0] = &quizF1; vectorMapF[1] = &quizF2; vectorMapF[2] = &assignmentF1; vectorMapF[3] = &Fmid; vectorMapF[4] = &Ffinals;

    unordered_map<int, unordered_map<int, vector<int>*>*> coursemap;
    coursemap[0] = &vectorMapA; coursemap[1] = &vectorMapB; coursemap[2] = &vectorMapC;
    coursemap[3] = &vectorMapD; coursemap[4] = &vectorMapE; coursemap[5] = &vectorMapF;

    unordered_map<int, vector<string>*> vectorMap;
    vectorMap[0] = &S1CS; vectorMap[1] = &S3CS; vectorMap[2] = &S1EE; vectorMap[3] = &S3EE;
    system("cls");
    loadDataFromFileS();
    for (int i=0; i<totalnumber1; i++)
    {
        if (sname==name[i])
        {

            for (int j=0; j< classes.size(); j++)
                {
                    (this->*loadfromFunctions[j])();
                    if (student_semester[i]==classes[j])
                    {
                        cout << student_semester[i]<<endl;
                        cout << "Choose a subject"<<endl;
                        for (int k=0; k< (*vectorMap[j]).size(); k++)
                        {
                            const string& elem = (*vectorMap[j])[k];

                            cout << elem<<endl;
                        }
                        cin.ignore();
                        string coursetemp;
                        getline(cin,coursetemp);
                        for (int k=0; k< (*vectorMap[j]).size(); k++)
                        {
                            const string& elem = (*vectorMap[j])[k];
                            if (elem == coursetemp)
                            {
                                auto selectedCourseMap = coursemap[k];
                                cout << "1.Quiz 1\n2.Quiz 2\n3.Assignment 1 \n4.Mids \n5.Finals"<<endl;
                                int x;
                                cin>>x;
                                if (selectedCourseMap != nullptr)
                                {
                                    vector<int>* targetVector = (*selectedCourseMap)[x - 1];
                                    if (targetVector != nullptr)
                                    {
                                        for (int l=0; l< temp1.size(); l++)
                                        {
                                            if (sname==temp1[l])
                                            {
                                                cout << (*targetVector)[l] << endl;

                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
};

int main ()
{

    int program1=0;
    cout << "                                            WELCOME TO DB&LMA!!"<<endl;
    do
    {
        cout << "                                             Select Your Role:"<<endl;
        cout << "                                              1)ADMIN"<<endl;
        cout << "                                              2)TEACHER"<<endl;
        cout << "                                              3)STUDENT"<<endl;
        cout << "                                              4)Exit"<<endl;
        int role;
        cin>>role;
        admin obj1;
        admin obj2;
        Teacher obj3;
        Class obj4;
        obj4.initial_separation();
        if (role==1)
        {
            int program2=0;
            do
            {
                cout << "Do you want to \n1)Enter Data\n2)Display Data\n3)Exit"<<endl;
                int choice1;
                cin>>choice1;
                if (choice1==1)
                {
                    cout << "Do you want to enter \n1)Student Data\n2)Teacher Data"<<endl;
                    int choice2;
                    cin>>choice2;
                    if (choice2==1)
                    {
                        obj1.loadDataFromFileS();
                        int limit;
                        cout << "How many students data you want to enter?";
                        cin>>limit;
                        obj1.student_input(limit);
                        obj1.student_display();
                        obj1.loadDatatoFileS();
                        obj4.initial_separation();
                    }
                    else if (choice2==2)
                    {
                        int limit;
                        cout << "How many teachers' data you want to enter?";
                        cin>>limit;
                        obj2.teacher_input(limit);
                        obj2.teacher_display();
                    }
                }
                else if (choice1==2)
                {
                    cout << "Do you want to display \n1)Student Data\n2)Teacher Data"<<endl;
                    int choice2;
                    cin>>choice2;
                    if (choice2==1)
                    {
                        obj1.loadDataFromFileS();
                        obj1.student_display();
                    }
                    else if (choice2==2)
                    {
                        obj2.loadDataFromFileT();
                        obj2.teacher_display();
                    }
                }
                else if (choice1==3)
                {
                    break;
                }
            }
            while(program2==0);
        }
        else if (role==2)
        {
            int program3=0;
            do
            {
                cout << "1)Register \n2)Login \n3)Exit"<<endl;
                int choice2;
                cin>>choice2;
                if (choice2==1)
                {
                    obj3.LoadTeacherCredentialsFromFile();
                    cout << "Enter your name:";
                    string tempname;
                    cin.ignore();
                    getline(cin,tempname);
                    if (obj3.check1Tnameforlogin(tempname)!=-1)
                    {
                        if(obj3.check2Tnameforlogin(tempname)==true)
                        {
                            obj3.teacher_credentials(obj3.check1Tnameforlogin(tempname));
                            break;
                        }
                        else if (obj3.check2Tnameforlogin(tempname)==false)
                        {
                            cout << "You are already registered, please login now!"<<endl;
                        }
                    }
                    else if (obj3.check1Tnameforlogin(tempname)==-1)
                    {
                        cout << "Your name doesn't exist in our system. Please request Admin to first enter your data"<<endl;
                        cout << "Do you want to send request to Admin (0/1):"<<endl;
                        bool request;
                        cin>>request;
                        if (request==0)
                        {
                            cout << "See you next time"<<endl;
                            break;
                        }
                        else if (request==1)
                        {
                            for (int i=1; i<=3; i++)
                            {
                                string captcha = generateCaptcha(5);
                                cout << captcha;
                                string user_captcha;
                                cout << "\nEnter above CAPTCHA to verify your request:";
                                cin >> user_captcha;
                                if (checkCaptcha(captcha, user_captcha)==true)
                                {
                                    cout << "Your request has been successfully accepted"<<endl;
                                    obj2.teacher_input(1);
                                    break;
                                }
                                else
                                {
                                    if (i<=2)
                                    {
                                       cout << "Try again"<<endl;
                                    }
                                    else
                                    {

                                    }
                                }
                            }
                        }
                    }
                }
                else if (choice2==2)
                {
                    obj3.LoadTeacherCredentialsFromFile();
                    string name;
                    string password;
                    string ID;
                    cin.ignore();
                    cout << "Enter your name:";
                    getline(cin,name);
                    if(obj3.check5TCredentialsforlogin(name)==true)
                    {
                        for (int i=1; i<=4; i++)
                        {
                            cout << "Enter your password:";
                            cin>>password;
                            if(obj3.check3TCredentialsforlogin(name,password)==true)
                            {
                                string temp;
                                string temp1;
                                system("cls");
                                cout << "WELCOME " << name<<endl;
                                obj3.class_selection(password,temp,temp1);
                                obj4.complex_selection(temp,temp1);

                                //the reaming code after successful login will be written here
                                break;
                            }
                            else
                            {
                                if (i<=2)
                                {
                                    cout << "Incorrect Credentials"<<endl;
                                }
                                else if (i==3)
                                {
                                    string message = "Come again next time";
                                    cout << "Incorrect Credentials"<<endl;
                                    cout << "Enter your ID:";
                                    cin>>ID;
                                    if(obj3.check4TCredentialsforlogin(ID,name)!=message)
                                    {
                                        cout << "Your password is:"<<obj3.check4TCredentialsforlogin(ID,name)<<endl;
                                    }
                                    else
                                    {
                                        cout << obj3.check4TCredentialsforlogin(ID,name)<<endl;
                                        break;
                                    }
                                }
                            }
                        }
                    }
                    else if (obj3.check5TCredentialsforlogin(name)==false)
                    {
                        cout << "Register First!"<<endl;
                    }
                }
                else if (choice2==3)
                {
                    break;
                }
            }
            while(program3==0);
        }
        else if (role==3)
        {
            student obj4;
            int program4=0;
            do{
                cout << "1)Register \n2)Login \n3)Exit"<<endl;
                int choice3;
                cin>>choice3;
                if(choice3==1)
                {
                    string stuname;
                     cout << "Enter your name:";
                      cin.ignore();
                    getline(cin,stuname);
                    if (obj4.check1snameforlogin(stuname)!=-1)
                    {
                       if(obj4.check2snameforlogin(stuname)==true)
                        {
                            obj4.student_credentials(obj4.check1snameforlogin(stuname));
                            obj4.display_student_credentials();
                            break;
                        }
                        else if (obj4.check2snameforlogin(stuname)==false)
                        {
                            cout << "You are already registered, please login now!"<<endl;

                        }


                    }
                    else if (obj4.check1snameforlogin(stuname)==-1)
                    {
                        cout << "Your name doesn't exist in our system. Please request Admin to first enter your data"<<endl;
                        cout << "Do you want to send request to Admin (0/1):"<<endl;
                        bool request1;
                        cin>>request1;
                          if (request1==0)
                        {
                            cout << "See you next time"<<endl;
                            break;
                        }
                        else if (request1==1)
                        {
                            for (int i=1; i<=3; i++)
                            {
                                string captcha = generateCaptcha(7);
                                cout << captcha;
                                string user_captcha;
                                cout << "\nEnter above CAPTCHA to verify your request:";
                                cin >> user_captcha;
                                if (checkCaptcha(captcha, user_captcha)==true)
                                {
                                    cout << "Your request has been successfully accepted"<<endl;
                                    obj2.student_input(1);
                                    break;
                                }
                                else
                                {
                                    if (i<=2)
                                    {
                                       cout << "Try again"<<endl;
                                    }
                                    else
                                    {

                                    }
                                }
                            }
                        }
                    }

                }
                 else if (choice3==2)
                {

                    string name;
                    string password;
                    string ID;
                    cin.ignore();
                    cout << "Enter your name:";
                    getline(cin,name);
                    if(obj4.check5sCredentialsforlogin(name)==true)
                    {
                        for (int i=1; i<=4; i++)
                        {
                            cout << "Enter your password:";
                            cin>>password;
                            if(obj4.check3sCredentialsforlogin(name,password)==true)
                            {
                                cout << "WELCOME " << name<<endl;
                                obj4.student_portal(name);

                                //the reaming code after successful login will be written here
                                break;
                            }
                            else
                            {
                                if (i<=2)
                                {
                                    cout << "Incorrect Credentials"<<endl;
                                }
                                else if (i==3)
                                {
                                    string message = "Come again next time";
                                    cout << "Incorrect Credentials"<<endl;
                                    cout << "Enter your ID:";
                                    cin>>ID;
                                    if(obj4.check4sCredentialsforlogin(ID,name)!=message)
                                    {
                                        cout << "Your password is:"<<obj4.check4sCredentialsforlogin(ID,name)<<endl;
                                    }
                                    else
                                    {
                                        cout << obj4.check4sCredentialsforlogin(ID,name)<<endl;
                                        break;
                                    }
                                }
                            }
                        }
                    }
                    else if (obj4.check5sCredentialsforlogin(name)==false)
                    {
                        cout << "Register First!"<<endl;
                    }
                }
                 else if (choice3==3)
                {
                    break;
                }
            }while(program4==0);

        }
        else if (role==4)
        {
            cout << "Thank you for using our system"<<endl;
            break;
        }
        else
        {
            cout << "Choose correctly"<<endl;
        }
    }
    while(program1==0);
    return 0;
}
