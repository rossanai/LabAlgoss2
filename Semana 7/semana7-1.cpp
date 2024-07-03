#include <iostream> 
using namespace std; 
 
/*Aqui implemente una cola usando una lista enlazada, donde node representa un
nodo en la cola que contiene el valor data y luego el constructor del nodo*/ 
struct CustomQueue {
    struct Node {
        long long data;
        Node* next;
        Node(long long val) : data(val), next(nullptr) {}
    };

    Node* front;
    Node* rear;

    CustomQueue() : front(nullptr), rear(nullptr) {}

/*Implemente un metodo para ir agregando un elemento a la cola y seguido de este
un metodo para eliminar el elemento frontal de la cola*/
    void push(long long val) {
        Node* newNode = new Node(val);
        if (rear == nullptr) {
            front = newNode;
            rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    void pop() {
        if (front != nullptr) {
            Node* temp = front;
            front = front->next;
            delete temp;
            if (front == nullptr) {
                rear = nullptr;
            }
        }
    }

    /*En esta seccion se imprime el elemento*/
    void printFront() {
        if (front != nullptr) {
            printf("%lld\n", front->data);
        } else {
            printf("Empty!\n");
        }
    }
};

/*Por ultimo en el main, lee los numeros de consulta, los procesa y hace la
operacion correspondiente a la cola*/
int main() {
    int T;
    scanf("%d", &T);
    CustomQueue q;

    for (int i = 0; i < T; ++i) {
        int query;
        scanf("%d", &query);

        if (query == 1) {
            long long n;
            scanf("%lld", &n);
            q.push(n);
        } else if (query == 2) {
            q.pop();
        } else if (query == 3) {
            q.printFront();
        }
    }

    return 0;
}