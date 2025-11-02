#include "functions.h"
#include "book.h"

int main()
{
    // Задание 6.1. Создаем «картотеку» книг (структура Book из ЛР5).
    // «Картотека» - это массив структур => нужно такой массив создать.
    // Замечание: размер массива придется увеличивать по мере добавления книг

    // Пользователь должен иметь возможность выполнять
    // разные действия с картотекой => нужно такую возможность ему
    // предоставить: это может выглядеть как вывод "меню" (перечень
    // возможных действий и соответствующих реакций пользователя), например:
    // Распечатать содержимое картотеки (1)
    // Ввести новую книгу (2)
    // Удалить существующую(ие) (3)
    // Записать текущее содержимое картотеки в файл (4)
    // Считать из файла содержимое в картотеку (5)
    // ... // по желанию можно добавить другие опции
    // Выход из программы

    // для файлового ввода/вывода используйте функции fprintf и fscanf

    // Задание 2. Предоставьте пользователю возможность выводить перечень книг
    // в определенном порядке - напишите функцию (функции) сортировки массива
    // по любому из полей структуры.
    // Замечание: признак "по какому полю сортируем" можно ввести с помощью перечисления

    struct Book *catalog = malloc(INITIAL_CAPACITY * sizeof(struct Book));
    if (catalog == NULL) {
        printf("Ошибка выделения памяти.\n");
        return 1;
    }
    int count = 0;
    int capacity = INITIAL_CAPACITY;
    int choice;

    // Загрузка картотеки из файла при запуске
    loadCatalogFromFile(&catalog, &count, &capacity, "catalog.txt");

    do {
        printf("\nМеню картотеки книг:\n");
        printf("1. Распечатать содержимое картотеки\n");
        printf("2. Ввести новую книгу\n");
        printf("3. Удалить книгу\n");
        printf("4. Записать картотеку в файл\n");
        printf("5. Считать картотеку из файла\n");
        printf("6. Сортировать картотеку\n");
        printf("0. Выход\n");
        printf("Выберите действие: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printCatalog(catalog, count);
                break;
            case 2: {
                struct Book newBook;
                printf("Введите автора: ");
                scanf(" %[^\n]", newBook.author);
                printf("Введите название: ");
                scanf(" %[^\n]", newBook.title);
                printf("Введите год: ");
                scanf("%d", &newBook.year);
                printf("Введите цену: ");
                scanf("%lf", &newBook.price);
                printf("Введите категорию: ");
                scanf(" %[^\n]", newBook.category);
                // Очистка буфера ввода
                while (getchar() != '\n');
                if (addBook(&catalog, &count, &capacity, &newBook)) {
                    printf("Книга добавлена.\n");
                } else {
                    printf("Не удалось добавить книгу.\n");
                }
                break;
            }
            case 3: {
                int index;
                printf("Введите индекс книги для удаления (0-%d): ", count - 1);
                scanf("%d", &index);
                if (removeBook(catalog, &count, index)) {
                    printf("Книга удалена.\n");
                } else {
                    printf("Не удалось удалить книгу.\n");
                }
                break;
            }
            case 4:
                saveCatalogToFile(catalog, count, "catalog.txt");
                printf("Картотека сохранена в файл.\n");
                break;
            case 5:
                if (loadCatalogFromFile(&catalog, &count, &capacity, "catalog.txt")) {
                    printf("Картотека загружена из файла.\n");
                } else {
                    printf("Не удалось загрузить картотеку.\n");
                }
                break;
            case 6: {
                int sortChoice;
                printf("Выберите поле для сортировки:\n");
                printf("1. Автор\n");
                printf("2. Название\n");
                printf("3. Год\n");
                printf("4. Цена\n");
                printf("5. Категория\n");
                scanf("%d", &sortChoice);
                SortingType type;
                switch (sortChoice) {
                    case 1: type = SORT_BY_AUTHOR; break;
                    case 2: type = SORT_BY_TITLE; break;
                    case 3: type = SORT_BY_YEAR; break;
                    case 4: type = SORT_BY_PRICE; break;
                    case 5: type = SORT_BY_CATEGORY; break;
                    default: printf("Ошибка: несуществующий тип сортировки.\n"); continue;
                }
                sortCatalog(catalog, count, type);
                printf("Картотека отсортирована.\n");
                break;
            }
            case 0:
                printf("Выход.\n");
                break;
            default:
                printf("Ошибка: несуществующий вариант выбора.\n");
        }
    } while (choice != 0);

    freeCatalog(catalog);
    return 0;
}
