#include <ostream>
#include <stdexcept>
#include "List.h"
#include "Node.h"

template <typename T>
class ListLinked : public List<T> {
private:
    Node<T>* first;
    int n;

public:

    ListLinked() : first(nullptr), n(0) {}

    // Destructor
    ~ListLinked() {
        Node<T>* aux;
        while (first != nullptr) {
            aux = first->next;
            delete first;
            first = aux;
        }
    }

    T operator[](int pos) {
        if (pos < 0 || pos >= n) {
            throw std::out_of_range("Posición inválida!");
        }
        Node<T>* aux = first;
        for (int i = 0; i < pos; ++i) {
            aux = aux->next;
        }
        return aux->data;
    }

    friend std::ostream& operator<<(std::ostream& out, const ListLinked<T>& list) {
        out << "List => [\n";
        Node<T>* aux = list.first;
        while (aux != nullptr) {
            out << "  " << aux->data << "\n";
            aux = aux->next;
        }
        out << "]";
        return out;
    }

    int size() const {
        return n;
    }

    void insert_front(const T& data) {
        first = new Node<T>(data, first);
        n++;
    }

    bool empty() const {
        return n == 0;
    }
};

