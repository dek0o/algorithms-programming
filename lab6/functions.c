#include "functions.h"

void printBook(const Book *book) {
    if (book == NULL) {
        printf("Книга не найдена\n");
        return;
    }
    printf("Автор: %s\n", book->author);
    printf("Название: %s\n", book->title);
    printf("Год публикации: %d\n", book->year);
    printf("Цена: %.2f\n", book->price);
    printf("Категория: %s\n", book->category);
    printf("\n");
}

void printCatalog(Book *catalog, int count) {
    if (count == 0) {
        printf("Картотека пуста.\n");
        return;
    }
    printf("Картотека книг:\n");
    for (int i = 0; i < count; i++) {
        printf("Книга %d:\n", i + 1);
        printBook(&catalog[i]);
    }
}

int addBook(Book **catalog, int *count, int *capacity, const Book *newBook) {
    if (*count >= *capacity) {
        *capacity *= 2;
        *catalog = realloc(*catalog, *capacity * sizeof(Book));
        if (*catalog == NULL) {
            return 0; // Не удалось выделить память
        }
    }
    (*catalog)[*count] = *newBook;
    (*count)++;
    return 1; // Успешно добавлено
}

int removeBook(Book *catalog, int *count, int index) {
    if (index < 0 || index >= *count) {
        return 0; // Неверный индекс
    }
    for (int i = index; i < *count - 1; i++) {
        catalog[i] = catalog[i + 1];
    }
    (*count)--;
    return 1; // Успешно удалено
}

void saveCatalogToFile(const Book *catalog, int count, const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Ошибка открытия файла для записи.\n");
        return;
    }
    fprintf(file, "%d\n", count);
    for (int i = 0; i < count; i++) {
        fprintf(file, "%s\n%s\n%d\n%lf\n%s\n",
                catalog[i].author,
                catalog[i].title,
                catalog[i].year,
                catalog[i].price,
                catalog[i].category);
    }
    fclose(file);
}

int loadCatalogFromFile(Book **catalog, int *count, int *capacity, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        return 0; // Файл не найден
    }
    fscanf(file, "%d\n", count);
    if (*count == 0) {
        fclose(file);
        return 0; // Пустой файл
    }
    if (*count > *capacity) {
        *capacity = *count;
        *catalog = realloc(*catalog, *capacity * sizeof(Book));
        if (*catalog == NULL) {
            fclose(file);
            return 0; // Не удалось выделить память
        }
    }
    for (int i = 0; i < *count; i++) {
        fgets((*catalog)[i].author, sizeof((*catalog)[i].author), file);
        (*catalog)[i].author[strcspn((*catalog)[i].author, "\n")] = '\0';
        fgets((*catalog)[i].title, sizeof((*catalog)[i].title), file);
        (*catalog)[i].title[strcspn((*catalog)[i].title, "\n")] = '\0';
        fscanf(file, "%d\n", &(*catalog)[i].year);
        fscanf(file, "%lf\n", &(*catalog)[i].price);
        fgets((*catalog)[i].category, sizeof((*catalog)[i].category), file);
        (*catalog)[i].category[strcspn((*catalog)[i].category, "\n")] = '\0';
    }
    fclose(file);
    return 1; // Успешно загружено
}

int compareBooks(const Book *a, const Book *b, SortingType type) {
    switch (type) {
        case SORT_BY_AUTHOR:
            return strcmp(a->author, b->author);
        case SORT_BY_TITLE:
            return strcmp(a->title, b->title);
        case SORT_BY_YEAR:
            return a->year - b->year;
        case SORT_BY_PRICE:
            if (a->price < b->price) return -1;
            if (a->price > b->price) return 1;
            return 0;
        case SORT_BY_CATEGORY:
            return strcmp(a->category, b->category);
        default:
            return 0;
    }
}

void sortCatalog(Book *catalog, int count, SortingType type) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (compareBooks(&catalog[j], &catalog[j + 1], type) > 0) {
                Book temp = catalog[j];
                catalog[j] = catalog[j + 1];
                catalog[j + 1] = temp;
            }
        }
    }
}

void freeCatalog(Book *catalog) {
    free(catalog);
}
