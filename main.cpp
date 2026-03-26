#include "list.h"

int main() {
    List myList;

    // 1. Формування списку
    myList.addElement("10");
    myList.addElement("25");
    myList.addElement("25"); // Створюємо сусідню пару для тесту
    myList.addElement("40");

    // 2. Роздрукувати список
    std::cout << "Сформований список: ";
    myList.printList();

    // 3. Виконати вказані дії (рекурсивна перевірка)
    // Результат повертається у місце виклику
    bool resultFound = myList.checkDuplicates();

    // 4. Вивести результат на екран
    std::cout << "Результат перевірки на сусідні дублікати: ";
    if (resultFound) {
        std::cout << "ТАК, знайдено" << std::endl;
    } else {
        std::cout << "НІ, не знайдено" << std::endl;
    }

    return 0;
}