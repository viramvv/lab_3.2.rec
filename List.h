#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <string>

// Структура одного елемента списку
struct Node {
    int data;           // Інформаційне поле
    Node* next;         // Вказівник на наступний елемент

    Node(int val) : data(val), next(nullptr) {}
};

class List {
private:
    Node* head;         // Початок списку (приватна змінна)

    // Приватна рекурсивна функція для перевірки сусідніх елементів
    // Параметр: current - поточний вузол для порівняння з наступним
    bool hasAdjacentRecursive(Node* current) const;

    // Рекурсивна функція для очищення пам'яті (деструктор)
    void destroyRecursive(Node* current);

public:
    List();             // Конструктор
    ~List();            // Деструктор

    // Функція додавання елемента (через рядок для валідації)
    void addElement(const std::string& valueStr);

    // Функція виведення списку на екран (cout)
    void printList() const;

    // Функція-обгортка для запуску рекурсії
    // Повертає true, якщо знайдено пару сусідніх однакових елементів
    bool checkDuplicates() const;
};

#endif