#include "list.h"

// Ініціалізація порожнього списку
List::List() : head(nullptr) {}

// Деструктор викликає рекурсивне видалення вузлів
List::~List() {
    destroyRecursive(head);
}

// Рекурсивне видалення: йдемо до кінця, видаляємо на зворотному шляху
void List::destroyRecursive(Node* current) {
    if (current == nullptr) return;
    destroyRecursive(current->next);
    delete current;
}

// Додавання нового елемента в кінець списку
void List::addElement(const std::string& valueStr) {
    int value = std::stoi(valueStr); // Перетворення рядка в число
    Node* newNode = new Node(value);

    if (head == nullptr) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Виведення значень елементів на екран
void List::printList() const {
    Node* current = head;
    if (current == nullptr) {
        std::cout << "Список порожній" << std::endl;
        return;
    }
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

// ПУБЛІЧНИЙ МЕТОД: запускає рекурсивний процес
bool List::checkDuplicates() const {
    return hasAdjacentRecursive(head);
}

// РЕКУРСИВНА ФУНКЦІЯ: опрацювання списку
bool List::hasAdjacentRecursive(Node* current) const {
    // Базовий випадок: якщо вузол останній або список порожній - пар немає
    if (current == nullptr || current->next == nullptr) {
        return false;
    }

    // Перевірка умови завдання: порівняння поточного з наступним
    if (current->data == current->next->data) {
        return true; // Пара знайдена
    }

    // Рекурсивний крок: переходимо до наступного вузла
    return hasAdjacentRecursive(current->next);
}