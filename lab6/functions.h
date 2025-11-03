#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "book.h"

typedef enum {
    SORT_BY_AUTHOR,
    SORT_BY_TITLE,
    SORT_BY_YEAR,
    SORT_BY_PRICE,
    SORT_BY_CATEGORY
} SortingType;

void printBook(const Book *book);
void printCatalog(Book *catalog, int count);
int addBook(Book **catalog, int *count, int *capacity, const Book *newBook);
int removeBook(Book *catalog, int *count, int index);
int saveCatalogToFile(const Book *catalog, int count, const char *filename);
int loadCatalogFromFile(Book **catalog, int *count, int *capacity, const char *filename);
void sortCatalog(Book *catalog, int count, SortingType field);
void freeCatalog(Book *catalog);
