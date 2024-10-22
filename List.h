#ifndef LIST_H
#define LIST_H

#include <stdexcept>  // Necesario para lanzar excepciones std::out_of_range

// Clase abstracta pura y genérica para List<T>
template <typename T>
class List {
public:
    // Método virtual puro para insertar un elemento en la posición 'pos'
    virtual void insert(int pos, T e) = 0;

    // Método virtual puro para añadir un elemento al final de la lista
    virtual void append(T e) {
        insert(size(), e);  // Reutilizamos insert para añadir al final
    }

    // Método virtual puro para añadir un elemento al principio de la lista
    virtual void prepend(T e) {
        insert(0, e);  // Reutilizamos insert para añadir al principio
    }

    // Método virtual puro para eliminar y devolver el elemento en 'pos'
    virtual T remove(int pos) = 0;

    // Método virtual puro para obtener el elemento en 'pos'
    virtual T get(int pos) = 0;

    // Método virtual puro para buscar el índice del elemento 'e'
    virtual int search(T e) = 0;

    // Método virtual puro para comprobar si la lista está vacía
    virtual bool empty() const = 0;

    // Método virtual puro para obtener el número de elementos en la lista
    virtual int size() const = 0;

    // Destructor virtual para permitir la correcta destrucción de las subclases
    virtual ~List() {}
};

#endif

