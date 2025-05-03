#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

class Abiturient {
private:
    string lastName;
    string firstName;
    string patronymic;
    string address;
    string phone;
    vector<int> grades;

public:
    Abiturient(string ln, string fn, string pn, string addr, string ph, vector<int> gr)
        : lastName(ln), firstName(fn), patronymic(pn), address(addr), phone(ph), grades(gr) {}

    double getAverageGrade() const {
        double sum = 0;
        for (int grade : grades) sum += grade;
        return grades.empty() ? 0 : sum / grades.size();
    }

    bool hasBadGrades() const {
        for (int grade : grades) {
            if (grade < 4) return true;
        }
        return false;
    }

    void print() const {
        cout << lastName << " " << firstName << " " << patronymic
             << " | Avg: " << fixed << setprecision(2) << getAverageGrade() << endl;
    }
};

void printBadGradeAbiturients(const vector<Abiturient>& abiturients) {
    cout << "Abiturients with unsatisfactory grades:
";
    for (const auto& ab : abiturients) {
        if (ab.hasBadGrades()) ab.print();
    }
}

void printAboveAverageAbiturients(const vector<Abiturient>& abiturients, double threshold) {
    cout << "Abiturients with average grade above " << threshold << ":
";
    for (const auto& ab : abiturients) {
        if (ab.getAverageGrade() > threshold) ab.print();
    }
}

int main() {
    vector<Abiturient> abiturients = {
        {"Иванов", "Иван", "Иванович", "Ростов", "123456", {5, 4, 3}},
        {"Петров", "Петр", "Петрович", "Москва", "654321", {5, 5, 5}},
        {"Сидоров", "Сидор", "Сидорович", "Казань", "987654", {4, 2, 3}},
    };

    printBadGradeAbiturients(abiturients);
    cout << endl;
    printAboveAverageAbiturients(abiturients, 4.0);

    return 0;
}
