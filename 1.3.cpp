#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>

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

    void print() const {
        cout << lastName << " " << firstName << " " << patronymic
             << " | Avg: " << fixed << setprecision(2) << getAverageGrade() << endl;
    }
};

void printTopAbiturients(const vector<Abiturient>& abiturients, int count) {
    vector<Abiturient> sorted = abiturients;
    sort(sorted.begin(), sorted.end(), [](const Abiturient& a, const Abiturient& b) {
        return a.getAverageGrade() > b.getAverageGrade();
    });

    cout << "Top " << count << " abiturients by average grade:
";
    for (int i = 0; i < min(count, (int)sorted.size()); ++i) {
        sorted[i].print();
    }
}

int main() {
    vector<Abiturient> abiturients = {
        {"Иванов", "Иван", "Иванович", "Ростов", "123456", {5, 4, 3}},
        {"Петров", "Петр", "Петрович", "Москва", "654321", {5, 5, 5}},
        {"Сидоров", "Сидор", "Сидорович", "Казань", "987654", {4, 2, 3}},
        {"Смирнова", "Анна", "Алексеевна", "Самара", "555666", {5, 5, 4}},
    };

    printTopAbiturients(abiturients, 2);

    return 0;
}
