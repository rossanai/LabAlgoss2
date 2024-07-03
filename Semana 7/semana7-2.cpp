#include <iostream> 
using namespace std; 

/*Aqui implemente una pila usando una estructura de nodos enlazada, donde node representa un
nodo en la cola que contiene el valor data, luego el constructor del nodo y el 
customstack que es el constructor de la pila*/ 
struct Node {
    long long data;
    Node* next;
    Node(long long val) : data(val), next(nullptr) {}
};

struct CustomStack {
    Node* top;

    CustomStack() : top(nullptr) {}

/*Implemente un metodo para ir agregando un elemento a la pila y el metodo que 
sigue para eliminar el elemento superior de la pila */
    void push(long long val) {
        Node* newNode = new Node(val);
        newNode->next = top;
        top = newNode;
    }

    void pop() {
        if (top != nullptr) {
            Node* temp = top;
            top = top->next;
            delete temp;
        }
    }

/*Aqui se obtiene el valor del elemento superior de la pila y se comprueba si
la pila esta vacia o no*/
    long long topElement() {
        if (top != nullptr) {
            return top->data;
        }
        return -1;
    }

    bool empty() {
        return top == nullptr;
    }
};

/*Por ultimo en el main, lee los numeros de consulta, los procesa y hace la
operacion correspondiente a la cola*/
int main() {
    int T;
    scanf("%d", &T);

    CustomStack stack;

    for (int i = 0; i < T; ++i) {
        int query;
        scanf("%d", &query);

        if (query == 1) {
            long long n;
            scanf("%lld", &n);
            stack.push(n);
        } else if (query == 2) {
            stack.pop();
        } else if (query == 3) {
            if (!stack.empty()) {
                printf("%lld\n", stack.topElement());
            } else {
                printf("Empty!\n");
            }
        }
    }

    return 0;
}