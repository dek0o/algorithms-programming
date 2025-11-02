#pragma once

#define INITIAL_CAPACITY 10

typedef struct Book {
    char author[100];    // Автор
    char title[100];     // Заглавие
    int year;            // Год издания
    double price;        // Цена
    char category[50];   // Категория
} Book;
