#include <iostream>
#include <stdexcept>

using namespace std;

struct Node { 
    int v; 
    Node* next; 
};

class StackList {
    Node* head = nullptr;
public:
    bool empty() const { return !head; }
    
    void push(int x) {
        head = new Node{x, head};
    }
    
    void pop() {
        if (empty()) throw underflow_error("kosong");
        Node* old = head;
        head = head->next;
        delete old;
    }
    
    int top() const {
        if (empty()) throw underflow_error("kosong");
        return head->v;
    }
    
    ~StackList() { 
        while (!empty()) pop(); 
    }
}; // <--- PASTIKAN KURUNG KURAWAL DAN TITIK KOMA INI ADA DI AKHIR KELAS!

int main() {
    StackList s;
    s.push(10);
    s.push(20);
    cout << "Top: " << s.top() << endl;
    return 0;
}