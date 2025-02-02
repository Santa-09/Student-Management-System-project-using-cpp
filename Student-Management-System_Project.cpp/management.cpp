#include <iostream>
#include <string>
using namespace std;

class Student{
public:
    string name;
    string registrationNo;
    string section;
    string branch;
    string gender;

    // Passing the student details through parameter
    void setDetails(string n, string r, string s, string b, string g){
        name=n;
        registrationNo=r;
        section=s;
        branch=b;
        gender=g;
    }

    void display(){
        cout<<"Name: "<<name<<", Registration No.: "<<registrationNo<<", Section: "<<section<<", Branch: "<<branch<<", Gender: "<<gender<<endl;
    }
};

// Define the StudentDetails class, inheriting the Student class
class StudentDetails : public Student{
public:
    Student students[5];
    int count=0;

    // TO add Student Details
    void addStudent(){
        if(count>=5){
            cout<<"Maximum limit of 5 students reached!"<<endl;
            return;
        }
        string n, r, s, b, g;

        cout<<"Enter Student Name: ";
        cin.ignore();
        getline(cin, n);

        cout<<"Enter Registration Number: ";
        getline(cin, r);

        cout<<"Enter Section: ";
        cin>>s;

        cout<<"Enter Branch: ";
        cin>>b;

        cin.ignore();
        cout<<"Enter Gender: ";
        getline(cin, g);

        students[count].setDetails(n, r, s, b, g);
        count++;
        cout<<"Student added successfully!"<<endl;
    }

    // Display student details
    void displayStudents(){
        if(count==0){
            cout<<"No students to display!"<<endl;
            return;
        }
        cout<<"List of Students:"<<endl;
        for(int i=0;i<count;i++){
            students[i].display();
        }
    }

    // Search by student Name
    void searchByName(){
        string searchName;
        cin.ignore();
        cout<<"Enter Name to search: ";
        getline(cin, searchName);

        for(int i=0;i<count;i++){
            if(students[i].name==searchName){
                cout<<"Student Found: "<<endl;
                students[i].display();
                return;
            }
        }
        cout<<"Student with Name "<<searchName<<"not found!"<<endl;
    }

    // Search by Registration Number
    void searchByRegistrationNo(){
        string searchRegNo;
        cin.ignore();
        cout<<"Enter Registration Number to search: ";
        getline(cin, searchRegNo);

        for(int i=0;i<count;i++){
            if (students[i].registrationNo==searchRegNo){
                cout<<"Student Found: "<<endl;
                students[i].display();
                return;
            }
        }
        cout<<"Student with Registration No. "<<searchRegNo<<" not found!"<<endl;
    }

    // Update Student Details individually
    void updateStudent(){
    if(count==0){
        cout<<"No students available to update!"<<endl;
        return;
    }
    string searchByName;
    cin.ignore();
    cout<<"Enter the name of the student you want to update: ";
    getline(cin, searchByName);

    for(int i=0;i<count;i++){
        if(students[i].name==searchByName){
            cout<<"Student found!"<<endl;
            students[i].display();
            cout<<"\nSelect the field to update:\n";
            cout<<"1 -> Update Name\n";
            cout<<"2 -> Update Registration No.\n";
            cout<<"3 -> Update Section\n";
            cout<<"4 -> Update Branch\n";
            cout<<"5 -> Update Gender\n";

            int choice;
            cin>>choice;
            cin.ignore(); // Clear buffer
            switch(choice){
                case 1:
                    cout<<"Enter updated Name: ";
                    getline(cin, students[i].name);
                    break;
                case 2:
                    cout<<"Enter updated Registration No.: ";
                    getline(cin, students[i].registrationNo);
                    break;
                case 3:
                    cout<<"Enter updated Section: ";
                    cin>>students[i].section;
                    break;
                case 4:
                    cout<<"Enter updated Branch: ";
                    cin>>students[i].branch;
                    break;
                case 5:
                    cin.ignore();
                    cout<<"Enter updated Gender: ";
                    getline(cin, students[i].gender);
                    break;
                default:
                    cout<<"Invalid choice! No changes made."<<endl;
                    return;
                }
            cout<<"Student details updated successfully!"<<endl;
            return;
            }
        }
    cout<<"Student with name "<<searchByName<<" not found!"<<endl;
    }

    // Delete student's details
    void deleteStudent(){
        string searchByName;
        cin.ignore();
        cout<<"Enter Name of the student to delete: ";
        getline(cin, searchByName);
        for(int i=0;i<count;i++){
            if(students[i].name==searchByName){
                for(int j=i;j<count-1;j++){
                    students[j]=students[j+1];
                }
                count--;
                cout<<"Student deleted successfully!"<<endl;
                return;
            }
        }
        cout<<"Student with name "<<searchByName<<" not found!"<<endl;
    }
};

int main(){
    StudentDetails s1;
    for(;;){
        cout<<"\nStudent Management System\n";
        cout<<"1 -> Add Student\n";
        cout<<"2 -> Display Students\n";
        cout<<"3 -> Search Student by Name\n";
        cout<<"4 -> Search Student by Registration Number\n";
        cout<<"5 -> Update Student Details\n";
        cout<<"6 -> Delete Student Details\n";
        cout<<"7 -> Exit\n";
        cout<<"Enter your choice: ";
        int choice;
        cin>>choice;
        switch(choice){
            case 1:
                s1.addStudent();
                break;
            case 2:
                s1.displayStudents();
                break;
            case 3:
                s1.searchByName();
                break;
            case 4:
                s1.searchByRegistrationNo();
                break;
            case 5:
                s1.updateStudent();
                break;
            case 6:
                s1.deleteStudent();
                break;
            case 7:
                cout<<"Thank you for using the Student Management System."<<endl;
                return 0;
            default:
                cout<<"Invalid choice! Please try again."<<endl;
        }
    }
}