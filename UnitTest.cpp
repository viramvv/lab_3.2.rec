#include <gtest/gtest.h>
#include "list.h"

// Тест 1: Перевірка списку з дублікатами (Варіант 14)
TEST(ListTest, DetectsAdjacentDuplicates) {
    List testList;
    testList.addElement("10");
    testList.addElement("20");
    testList.addElement("20"); // Сусідня пара
    testList.addElement("30");

    EXPECT_TRUE(testList.checkDuplicates());
}

// Тест 2: Перевірка списку БЕЗ дублікатів
TEST(ListTest, NoDuplicatesReturnsFalse) {
    List testList;
    testList.addElement("5");
    testList.addElement("10");
    testList.addElement("15");

    EXPECT_FALSE(testList.checkDuplicates());
}

// Тест 3: Перевірка порожнього списку
TEST(ListTest, EmptyListReturnsFalse) {
    List testList;
    EXPECT_FALSE(testList.checkDuplicates());
}

// Тест 4: Перевірка списку з одного елемента
TEST(ListTest, SingleElementReturnsFalse) {
    List testList;
    testList.addElement("100");
    EXPECT_FALSE(testList.checkDuplicates());
}

// Тест 5: Однакові елементи, але НЕ сусідні
TEST(ListTest, NonAdjacentDuplicatesReturnsFalse) {
    List testList;
    testList.addElement("10");
    testList.addElement("20");
    testList.addElement("10"); // Такі ж, як перший, але не сусіди

    EXPECT_FALSE(testList.checkDuplicates());
}