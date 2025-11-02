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

void printBook(const struct Book *book);
void printCatalog(struct Book *catalog, int count);
int addBook(struct Book **catalog, int *count, int *capacity, const struct Book *newBook);
int removeBook(struct Book *catalog, int *count, int index);
void saveCatalogToFile(const struct Book *catalog, int count, const char *filename);
int loadCatalogFromFile(struct Book **catalog, int *count, int *capacity, const char *filename);
void sortCatalog(struct Book *catalog, int count, SortingType field);
void freeCatalog(struct Book *catalog);
