#define SEAT 5

#include <iostream> 
#include <fstream>
#include <cstring>
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>

using namespace std;

//add student
void addStudent(string filename, int *studentCount, int *hostelFees, int *nohostelFees,int *roll, int *comp, int *it, int *entc, int *chem, int *mech, int *inst){
cout<<endl<<"Press any key to add Students details";
getchar();
ofstream file(filename.c_str(), ios::app);

char name[100];
char address[100];
char phone[10];
char DOB[50];
char gender[1];
char percentage[3];
char father_name[100];
char mother_name[100];
int Admission_fees=5000;
int Hfee= 90000;
int r=1;

*roll=*roll+1; 

cout<<endl<<"\n Enter Name of Student : ";
gets(name);
cout<<endl<<"\n Enter Address(city) : ";
gets(address);
cout<<endl<<"\n Enter phone no. : ";
gets(phone);
cout<<endl<<"\n Enter DOB(dd.mm.yyyy) : ";
gets(DOB);
cout<<endl<<"\n F/M/Other : ";
gets(gender);
while (r!=0){
if(*gender== 'f'|| *gender=='F' || *gender=='m'|| *gender=='M' || *gender=='o'|| *gender=='O' )
{
	r=0;
	}
else{
	cout<<endl<<"\n Wrong Input!! \n Please enter a valid Gender\n F/M/Other : ";
	gets(gender);
}
}

cout<<endl<<"\n Enter 12th percentage : ";
gets(percentage);
cout<<endl<<"\n Enter Name of Student's father : ";
gets(father_name);
cout<<endl<<"\n Enter Name of Student's Mother : ";
gets(mother_name);
file<<endl<<"id_"<<*roll<<"\n Name: "<<name<<"\n Address: "<<address;
file<<"\n DOB: "<<DOB<<"\n gender: "<<gender<<"\n 12th Percentage: "<<percentage;
file<<"\n Father: "<<father_name<<"\n Mother: "<< mother_name<<endl;


string S_receipt= ".txt";
S_receipt= name + S_receipt;
ofstream myfile(S_receipt.c_str(),ios::app);
myfile<<endl<<"\n					~~ VISHWAKARMA INSTITUTE OF TECHNOLOGY, PUNE ~~"<<endl;
myfile<<endl<<"id_"<<*roll<<"\n Name: "<<name<<"\n Address: "<<address;
myfile<<"\n DOB: "<<DOB<<"\n gender: "<<gender<<"\n 12th Percentage: "<<percentage<<endl;
myfile<<"\n Father: "<<father_name<<"\n Mother: "<< mother_name<<endl;

int plan;
int t=0;
while (t==0)
{
cout<<endl<<" # Select course (available seats)#";
cout<<endl<<"\n1.Computer -> Rs.1,80,000, \n# available seats: "<<*comp;
cout<<endl<<"\n2.IT -> Rs.1,72,000, \n# available seats: "<<*it;
cout<<endl<<"\n3.Electronics and Communications -> Rs.1,67,500, \n# available seats: "<<*entc;
cout<<endl<<"\n4.Mechanical -> Rs.1,59,000, \n# available seats: "<<*mech;
cout<<endl<<"\n5.Chemical -> Rs.1,59,000, \n# available seats: "<<*chem;
cout<<endl<<"\n6.Instrumentation -> Rs.1,55,000, \n# available seats: "<<*inst;

cout<<endl<<"Select any option: ";
cin>>plan;
int x;
switch (plan){
	case 1: x=*comp; break;
	case 2: x=*it; break;
	case 3: x=*entc; break;
	case 4: x=*mech; break;
	case 5: x=*chem; break;
	case 6: x=*inst; break;
	default: x=0;
}
if(x==0){
	cout<<"\n# No seats available #";
}
else{
	t=1;
}
}

int course_fee=0;
switch(plan){     	

case 1: {
	
	course_fee=180000;
	file<<"\n course opted: CS";
	myfile<<"\n course opted: CS";
	*comp=*comp-1;
	break;
}   
case 2: {
	course_fee=172000;
	file<<"\ncourse opted: IT";
	myfile<<"\ncourse opted: IT";
	*it=*it-1;
	break;
}   
case 3: {
	course_fee=167500;
	file<<"\n course opted: ENTC";
	myfile<<"\n course opted: ENTC";
	*entc=*entc-1;
	break;
}   
case 4: {
	course_fee=159000;
	file<<"\n course opted: MECH";
	myfile<<"\n course opted: MECH";
	*mech=*mech-1;
	break;
}   
case 5: {
	course_fee=159000;
	file<<"\n course opted: CHEM";
	myfile<<"\n course opted: CHEM";
	*chem=*chem-1;
	break;
}   
case 6: {
	course_fee=155000;
	file<<"\ncourse opted: INST";
	myfile<<"\ncourse opted: INST";
	*inst=*inst-1;
	break;
}   
default: cout<<endl<<"Invalid Choice..";
}


int state=-1;
cout<<endl<<"\n Hostel fee: Rs. 90,000\n Press 1. Hostel or 2. No Hostel : ";
cin>>state;

if(state==1)
{
	file<<"\n | Hostel";
	myfile<<"\n | Hostel";
}
else if(state==2)
{
	file<<"\n | No Hostel";
	myfile<<"\n | No Hostel";
}

else{
	file<<"\n | NA";
	myfile<<"\n | NA";
}


if(state==1){
*hostelFees =  course_fee + Admission_fees + Hfee;
file<<" | Total fees: "<<*hostelFees;
myfile<<" | Total fees: "<<*hostelFees;
}
else {
*nohostelFees = course_fee + Admission_fees;
file<<" | Total fees: "<<*nohostelFees;
myfile<<" | Total fees: "<<*nohostelFees;
}

*studentCount = *studentCount + 1;

file<<endl<<"\n---------------------------------------------------------------";
myfile<<endl<<"\n---------------------------------------------------------------\n";
myfile<<endl<<"Admission Successful! ";
myfile<<endl<<"\n---------------------------------------------------------------";
file.close();
myfile.close();

cout<<endl<<"Congratulations! \n Admission Successful.";
cout<<endl<<"Success: "<<S_receipt<<" is generated ";

}

//student withdrawl
void withdraw(const string fileName,int *studentCount){
    
ifstream is(fileName.c_str()); 
  
    // open file in write mode or out mode 
    ofstream ofs; 
    ofs.open("temp.txt", ofstream::out); 
  
    // loop getting single characters 
    char c; 
    int line_no = 1; 
    int no=0;
    int line=4;
    int p=0;
    	cout << "Enter the ID: ";
	cin >> no;
	for(int j=0;j<no;j++)
	line=line + (13*j);
    while (is.get(c)) 
    { 
        // if a newline character 
        if (c == '\n') 
        line_no++; 
  
       p=line;
       	if (line_no <= line ) 
            ofs << c; 
/*        for (int x=0; x<15;x++){
            	if(line_no == p){
            		ofs<<"removed"<<endl;
            	}
        	p++;
		}*/
         if (line_no > (line+13)) 
            ofs << c; 

      
    } 
  
    // closing output file 
    ofs.close(); 
  
    // closing input file 
    is.close(); 
  
    // remove the original file 
    remove(fileName.c_str()); 
  
    // rename the file 
    rename("temp.txt", fileName.c_str()); 

  
    *studentCount = *studentCount-1;
	

}
//All student DATA
void generateReport(const string filename, const int *studentCount){
	int temp= *studentCount -1;
if(temp==0){
cout<<endl<<"Error: There should be atleast one record to generate report.";
}
else{
cout<<endl<<"Success: Student data "<<filename<<" generated ";
cout<<endl<<"\n	Total number of students: "<<temp<<endl;

}

}



//Main function
int main(int argc, char** argv) {
	
int choice = 0;
string fileName = "r_report.txt";
int studentCount =1;
int hostelFees = 0;
int nohostelFees =0;
int roll=0;

		int comp=SEAT;
		int it=SEAT;
		int entc=SEAT;
		int chem=SEAT;
		int mech=SEAT;
		int inst=SEAT;
		
//empty file if it already exist
ofstream file(fileName.c_str(), ios::out);
file<<endl<<"\n					~~ VISHWAKARMA INSTITUTE OF TECHNOLOGY, PUNE ~~"<<endl;
file.close();

cout<<endl<<"\n					~~ VISHWAKARMA INSTITUTE OF TECHNOLOGY, PUNE ~~"<<endl;
while(choice!=-1){

cout<<endl<<"\n## (College Student Tuition) ##"<<endl;
cout<<endl<<" 1 Add Student Details";
cout<<endl<<" 2 All Student Data";
cout<<endl<<" 3 Show All Available Seats";
cout<<endl<<" 4 Student Withdrawl";
cout<<endl<<" -1 Exit";
cout<<"\n\n Enter your choice : ";
cin>>choice;

switch(choice){
case 1: 
{
	addStudent(fileName, &studentCount, &hostelFees, &nohostelFees,&roll, &comp,&it,&entc,&chem,&mech,&inst);
	break;
}
case 2:
{
	generateReport(fileName, &studentCount);
	break;
}
case 3:
{
	cout<<endl<<"\n1.Computer: "<<comp;
	cout<<endl<<"\n2.IT: "<<it;
	cout<<endl<<"\n3.Electronics and Communications: "<<entc;
	cout<<endl<<"\n4.Mechanical: "<<mech;
	cout<<endl<<"\n5.Chemical: "<<chem;
	cout<<endl<<"\n6.Instrumentation: "<<inst;	
	break;
}
case 4:
	{
		withdraw(fileName,&studentCount);
		break;
	}
case -1: cout<<endl<<"thank you!!";
	break;
default: cout<<endl<<"Invalid Choice.."; getchar();
	
}
	
}

return 1;
}


