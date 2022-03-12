#include <bits/stdc++.h>

//  Library for working with json files
#include <nlohmann/json.hpp>
using namespace std;

string calcTime(string s1, string s2) {
    int h1 = stoi(s1.substr(0, 2)), h2 = stoi(s2.substr(0, 2));
    int m1 = stoi(s1.substr(3, 2)), m2 = stoi(s2.substr(3, 2));
    int h, m;
    h = h2 - h1;
    m = m2 - m1;
    if (m < 0) {
        m += 60;
        h--;
    }
    return to_string(h) + ":" + to_string(m);
}

signed main() {
    // use nlohmann library to parse json
    using json = nlohmann::json;

    // parse json file
    ifstream attendanceRegister("AttendanceRegister.json");
    json Register;
    attendanceRegister >> Register;

    string EmployeeName;
    cout << "Enter Employee Name: ";
    cin >> EmployeeName;
    bool found = false;
    // get the objects from register
    for (const auto& obj : Register) {
        // check each object for the key "name"

        if (obj["employeName"] == EmployeeName) {
            // if found, print details"
            found = true;
            cout << "Employee Name: " << obj["employeName"] << endl;
            cout << "Date: " << obj["date"] << endl;
            cout << "Department: " << obj["dept"] << endl;
            cout << "Check In: " << obj["checkinTime"] << endl;
            cout << "Check Out: " << obj["checkouttime"] << endl;
            cout << "Total Hours: "
                 << calcTime(obj["checkinTime"], obj["checkouttime"]) << endl;
            cout << endl;
            cout << " ----------- " << endl;
            cout << endl;
        }
    }
    if (!found) {
        cout << "Employee Details not found" << endl;
    }

    return 0;
}