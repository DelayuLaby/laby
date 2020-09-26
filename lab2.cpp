

#include <iostream>
#include <string.h>

using namespace std;

class kotik {
private:
    string name;
    string diagnosis;
    int id;
public:
    kotik() : name("Vasua"), diagnosis("kruglyi pupok"), id(rand() % 1000){}
    kotik(string n, string d, int i) {
        name = n;
        diagnosis = d;
        id = i;
    }
    ~kotik(){}
    friend void printkotik(kotik obj);
    friend class veterenar;
    void rename(string& z) {
        name = z;
    }
};

class veterenar {
public:
    static void set_diagnosis(kotik& obj, string diag) {
        obj.diagnosis = diag;
    }
};

void printkotik(kotik obj) {
    cout << obj.id << ". " << obj.name << " - diagnosis: " << obj.diagnosis << endl;

}



int main() {
    kotik obj1;
    printkotik(obj1);
    kotik obj2("KUZYA", "vsyo super", 14);
    printkotik(obj2);
    int id;
    string name, diagn;
    cout << "vvedite imya\n";
    cin >> name;
    cout << "vvedite diagnoz\n";
    cin >> diagn;
    cout << "vvedite ID";
    cin >> id;
    if (id < 0) {
        cout << "davai po novoi";
        return 0;
    }
    kotik obj3(name, diagn, id);
    printkotik(obj3);
    veterenar::set_diagnosis(obj1, "kruglyi pupok");
    veterenar::set_diagnosis(obj2, "vsyo super");
    veterenar::set_diagnosis(obj3, diagn);
    printkotik(obj1);
    printkotik(obj2);
    printkotik(obj3);
    kotik arr[3] = { obj1, obj2, obj3 };
    for (int i = 0; i < 3; i++){
        printkotik(arr[i]);
        veterenar::set_diagnosis(arr[i], "odno i to je");
        printkotik(arr[i]);
    }
    return 0;
}
