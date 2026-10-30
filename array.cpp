#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;

// Menggunakan template <typename T> agar stack bersifat generik (bisa tipe data apa saja)
template <typename T>
class StackTemplate {
private:
    struct Node {
        T data;
        Node* next;
    };
    Node* head = nullptr;

public:
    bool empty() const {
        return head == nullptr;
    }

    void push(const T& value) {
        head = new Node{value, head};
    }

    void pop() {
        if (empty()) {
            throw underflow_error("Stack kosong!");
        }
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    T top() const {
        if (empty()) {
            throw underflow_error("Stack kosong!");
        }
        return head->data;
    }

    ~StackTemplate() {
        while (!empty()) {
            pop();
        }
    }
};

int main() {
    // Contoh 1: Stack dengan tipe data string (Teks)
    cout << "=== UJI STACK DENGAN TIPE DATA STRING ==\n";
    StackTemplate<string> textStack;
    
    textStack.push("Pemrograman");
    textStack.push("Struktur");
    textStack.push("Data");

    cout << "Elemen teratas (top): " << textStack.top() << "\n"; // Harus "Data"
    
    textStack.pop();
    cout << "Setelah pop, elemen teratas: " << textStack.top() << "\n\n"; // Harus "Struktur"

    // Contoh 2: Stack dengan tipe data double (Pecahan)
    cout << "=== UJI STACK DENGAN TIPE DATA DOUBLE ==\n";
    StackTemplate<double> doubleStack;
    
    doubleStack.push(3.14);
    doubleStack.push(9.81);
    
    cout << "Elemen teratas (top): " << doubleStack.top() << "\n"; // Harus 9.81

    return 0;
}