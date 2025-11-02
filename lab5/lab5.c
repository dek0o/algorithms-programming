// Лабораторная 5.
// - указатели на функции
// - структуры

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Book {
    char author[100];    // Автор
    char title[100];     // Заглавие
    int year;            // Год издания
    double price;        // Цена
    char category[50];   // Категория
};

void printBook(const struct Book *book);

int main()
{
    // --- Задание 4. Структуры ---
    // Задание 4a. Объявите структуру Book, описывающую книгу
    // (автор, заглавие, год издания, цена, категория…).
    // Подумайте, какого типа могут быть поля структуры.
    // Объявление структуры рекомендуется выносить в заголовочный файл.

    // Задание 4б. Создайте разными способами (статический, динамический)
    // экземпляры (объекты) типа Book

    struct Book staticBook;

    struct Book *dynamicBook = (struct Book*)malloc(sizeof(struct Book));
    if (dynamicBook == NULL) {
        printf("Ошибка выделения памяти!\n");
        return 1;
    }

    // Задание 4в. Заполните поля созданных объектов.
    // Напоминание: в строках нужна "защита" от выхода за границы массива.

    // Заполнение статической книги
    strncpy(staticBook.author, "Стивен Халим", sizeof(staticBook.author) - 1);
    staticBook.author[sizeof(staticBook.author) - 1] = '\0';
    strncpy(staticBook.title, "Спортивное программирование", sizeof(staticBook.title) - 1);
    staticBook.title[sizeof(staticBook.title) - 1] = '\0';
    staticBook.year = 2020;
    staticBook.price = 42.42;
    strncpy(staticBook.category, "Литература победителей", sizeof(staticBook.category) - 1);
    staticBook.category[sizeof(staticBook.category) - 1] = '\0';

    // Заполнение динамической книги
    strncpy(dynamicBook->author, "Уолтер Айзексон", sizeof(dynamicBook->author) - 1);
    dynamicBook->author[sizeof(dynamicBook->author) - 1] = '\0';
    strncpy(dynamicBook->title, "Стив Джобс", sizeof(dynamicBook->title) - 1);
    dynamicBook->title[sizeof(dynamicBook->title) - 1] = '\0';
    dynamicBook->year = 2011;
    dynamicBook->price = 19.84;
    strncpy(dynamicBook->category, "Биография", sizeof(dynamicBook->category) - 1);
    dynamicBook->category[sizeof(dynamicBook->category) - 1] = '\0';

    // Задание 4г. Напишите функцию, выводящую на экран реквизиты книги.
    // Подумайте, как эффективнее передавать экземпляр Book в функцию.

    printf("Вывод статической книги:\n");
    printBook(&staticBook);

    printf("Вывод динамической книги:\n");
    printBook(dynamicBook);

    // Освобождение памяти
    free(dynamicBook);

    return 0;
}

void printBook(const struct Book *book) {
    if (book == NULL) {
        printf("Передана несуществующая книга\n");
        return;
    }
    printf("Автор: %s\n", book->author);
    printf("Название: %s\n", book->title);
    printf("Год публикации: %d\n", book->year);
    printf("Цена: %.2f\n", book->price);
    printf("Категория: %s\n", book->category);
    printf("\n");
}
