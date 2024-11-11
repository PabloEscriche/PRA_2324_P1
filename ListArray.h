#include <ostream>
#include <stdexcept>
#include "List.h"

template <typename T>
class ListArray : public List<T> {
private:
    T* arr;
    int max;
    int n; 
    static const int MINSIZE = 2;

    void resize(int new_size) {
        T* new_arr = new T[new_size];
        for (int i = 0; i < n; i++) {
            new_arr[i] = arr[i];
        }
        delete[] arr;
        arr = new_arr;
        max = new_size;
    }

public:
    ListArray() : arr(new T[MINSIZE]), max(MINSIZE), n(0) {}

    ~ListArray() {
        delete[] arr;
    }

    int size() const override {
        return n;
    }

    bool empty() const override {
        return n == 0;
    }

    void insert(int pos, const T& value) override {
        if (pos < 0 || pos > n) {
            throw std::out_of_range("Posición inválida!");
        }
        if (n == max) {
            resize(max * 2);
        }
        for (int i = n; i > pos; --i) {
            arr[i] = arr[i - 1];
        }
        arr[pos] = value;
        n++;
    }

    T remove(int pos) override {
        if (pos < 0 || pos >= n) {
            throw std::out_of_range("Posición inválida!");
        }
        T removed_value = arr[pos];
        for (int i = pos; i < n - 1; ++i) {
            arr[i] = arr[i + 1];
        }
        n--;
        if (n < max / 4 && max / 2 >= MINSIZE) {
            resize(max / 2);
        }
        return removed_value;
    }

    T get(int pos) const override {
        if (pos < 0 || pos >= n) {
            throw std::out_of_range("Posición inválida!");
        }
        return arr[pos];
    }

    T operator[](int pos) const {
        if (pos < 0 || pos >= n) {
            throw std::out_of_range("Posición inválida!");
        }
        return arr[pos];
    }

    void append(const T& value) override {
        insert(n, value);
    }

    void prepend(const T& value) override {
        insert(0, value);
    }

    int search(const T& value) const override {
        for (int i = 0; i < n; i++) {
            if (arr[i] == value) {
                return i;
            }
        }
        return -1;
    }

    friend std::ostream& operator<<(std::ostream &out, const ListArray<T> &list) {
        out << "List => [";
        for (int i = 0; i < list.n; i++) {
            out << "\n  " << list.arr[i];
        }
        out << "\n]";
        return out;
    }
};
