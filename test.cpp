#include <iostream>

#include "include/CMatrix.h"
#include "include/CWhole.h"

using namespace std;

void pause();

int main() {
  CWhole test;
  int choice = 0; 

  do {
    system("clear");
    cout << "Лабораторная работа №7 Хандрыга Р.В.\n";
    cout << "1 - Добавить объект\n";
    cout << "2 - Удалить объект по ID\n";
    cout << "3 - Найти индекс объекта по ID\n";
    cout << "4 - Показать состояние \n";
    cout << "0 - Выход \n";
    cout << "> ";

    cin >> choice;

    switch(choice) {
      case 1: {
        system("clear");
        int size = 0;
        int id = 0;

        cout << "Введите размер матрицы: \n";
        cout << "> ";
        cin >> size;
        CMatrix m(size);

        for (int col = 0; col < size; col++) {
          for (int row = 0; row < size; row++) {
            float tmp = 0;

            cout << "matrix[" << col << "][" << row << "] = ";
            cin >> tmp;
            m.setElement(col, row, tmp);
          }
        }

        cout << "Введите ID объекта или 0 для автозаполнения \n> ";
        cin >> id;

        id ? test.add(m, id) : test.add(m);
      } break;

      case 2: {
        system("clear");
        int id = -1;

        cout << "Введите ID объекта: \n > ";
        cin >> id;
        test.remove(id);
      } break;

      case 3: {
        system("clear");
        int id = -1;

        cout << "Введите ID объекта: \n > ";
        cin >> id;
        cout << "Объект с ID " << id << " имеет индекс " << test.getIndexById(id) << endl;
        pause();
      } break;

      case 4: {
        system("clear");
        test.showInfo();
        pause();
      } break;
    }
  } while(choice);

  return 0;
}

void pause() {
  cout << "Press enter...";
  cin.ignore();
  cin.get();
};