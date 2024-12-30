#include <iostream>
#include <vector>

using namespace std;

int is_free(string *tab, int size){
    for(int i=0; i<size; i++){
        if(tab[i]=="") return i;
    }
    return 1000;
}

class Appointment{
private:
    struct Doctor{
        string dr_name;
        string date[10];
        string free[3];
    };
    vector<Doctor> doctors;

public:
    Appointment();
    void bookAppointment(int date_idx, string name, string doctor);
    void showDetails(string name);
};

Appointment::Appointment(){
    Doctor W, K, N;
    W.dr_name = "Wiśniewski";
    doctors.push_back(W);
    K.dr_name = "Kowalska";
    doctors.push_back(K);
    N.dr_name = "Nowak";
    doctors.push_back(N);
}

void Appointment::bookAppointment(int date_idx, string name, string doctor){
    for(auto &dr : doctors){
        if(dr.dr_name == doctor){
            int f = is_free(dr.free, 3);

            if(f != 1000){
                if(dr.date[date_idx]==""){
                    dr.date[date_idx] = name;
                    dr.free[f]=name;
                    cout<<"The appointment has been booked:"<<endl;
                    cout<<"Date: "<<date_idx<<", Patient: "<<name<<", Doctor: "<<doctor<<endl<<endl;
                }
                else{
                    cout<<"The appointment date "<<date_idx<<" is already booked."<<endl<<endl;
                }
            }
            else{
                cout<<"Doctor "<<doctor<<" already has the maximum number of patients."<<endl<<endl;
            }

        }
    }
}

void Appointment::showDetails(string name){
    bool found = false;
    for(auto &dr : doctors){
        for(int i=0;i<10;i++){
            if(dr.date[i] == name){
                cout<<"Appointment:"<<endl;
                cout<<"Date: "<<i<<endl;
                found = true;
                goto next;
            }
            else{

            }
        }
    }

    next:
    if(!found){
        cout<<"No appointment found for patient "<<name<<"."<<endl;
        goto end;
    }

    cout<<"Patient: "<<name<<endl;

    for(auto &dr : doctors){
        for(int i=0;i<10;i++){
            if(dr.date[i] == name) cout<<"Doctor: "<<dr.dr_name<<endl;
        }
    }

    end:
    cout<<endl;
}

int main(){
    Appointment app;
    int my_date;
    string patient, my_doctor;

    for(int i=0; i<5; i++){
        cin>>my_date>>patient>>my_doctor;
        app.bookAppointment(my_date, patient, my_doctor);
    }

    for(int i=0; i<3; i++){
        cin>>patient;
        app.showDetails(patient);
    }
    return 0;
}