#include <iostream>

#include "CMatrix.h"
#include "CWhole.h"

#ifdef _WIN32
  #define CLEAR "cls"
#else
  #define CLEAR "clear"
#endif

using namespace std;

void pause();

int main() {
  CWhole test;
  int choice = 0; 

  do {
    system(CLEAR);
    cout << "Composition. 21 variant. Khandryga\n";
    cout << "1 - Add object\n";
    cout << "2 - Delete object by ID\n";
    cout << "3 - Find index by ID\n";
    cout << "4 - Show state \n";
    cout << "0 - Exit \n";
    cout << "> ";

    cin >> choice;

    switch(choice) {
      case 1: {
        system(CLEAR);
        int size = 0;
        int id = 0;

        cout << "Enter matrix size: \n";
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

        cout << "Enter new object ID or 0 for autofill\n> ";
        cin >> id;

        id ? test.add(m, id) : test.add(m);
      } break;

      case 2: {
        system(CLEAR);
        int id = -1;

        cout << "Enter object ID:\n > ";
        cin >> id;
        test.remove(id);
      } break;

      case 3: {
        system(CLEAR);
        int id = -1;

        cout << "Enter object ID:\n > ";
        cin >> id;
        cout << "Object with ID " << id << " has index " << test.getIndexById(id) << endl;
        pause();
      } break;

      case 4: {
        system(CLEAR);
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