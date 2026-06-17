#include <iostream>
#include<vector>
using namespace std;
struct course{
    string name;
    char grade;
    int credit;

    };
    double gradetopoint(char grade){
        switch(toupper(grade)){
            case'A':
            return 4.0;
            case'B':
            return 3.0;
            case 'C':
            return 2.0;
            case'D':
            return 1.0;
    default:
    return 0.0;
           }
    }
    int main()
    {
        int n;
        cout<<"enter your course:";
        cin>>n;
        vector<course>course(n);
        double totalpoint=0;
        double totalcredit=0;
        for(int i=0;i<n;i++){
            cout<<"course"<< i+1 <<"name:";
            cin>>course[i].name;
            cout<<"grade(A-D/F):";
            cin>>course[i].grade;
            cout<<"credit hours:";
            cin>>course[i].credit;
            totalpoint+=gradetopoint(course[i].grade)*course[i].credit;  
            totalcredit+=course[i].credit;
                 }
                 double gpa=totalpoint/totalcredit;
                 cout<<"\nfinal cgpa:"<<gpa<<endl;
    }
