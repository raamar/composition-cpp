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
int mainMenu();
void addObjectTo(CWhole & storage);
void deleteObjectTo(CWhole & storage);
void findObjectTo(CWhole & storage);
void showStateOf(CWhole & storage);

int main() {
  CWhole storage;
  int choice = 0;

  do {
    choice = mainMenu();
    switch(choice) {
      case 1: addObjectTo(storage); break;
      case 2: deleteObjectTo(storage); break;
      case 3: findObjectTo(storage); break;
      case 4: showStateOf(storage); break;
    }
  } while(choice);

  return 0;
}

void addObjectTo(CWhole & storage) {
  int size = 0;
  int id = 0;

  system(CLEAR);
  cout << "Enter matrix size:\n> ";
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

  id ? storage.add(m, id) : storage.add(m);
}

void deleteObjectTo(CWhole & storage) {
  system(CLEAR);
  int id = -1;

  cout << "Enter object ID:\n > ";
  cin >> id;

  storage.remove(id);
}

void findObjectTo(CWhole & storage) {
  system(CLEAR);
  int id = -1;

  cout << "Enter object ID:\n> ";
  cin >> id;

  cout << "Object with ID " << id << " has index " << storage.getIndexById(id) << endl;
  
  pause();
}

void showStateOf(CWhole & storage) {
  system(CLEAR);
  storage.showInfo();
  pause();
}

int mainMenu() {
  int choice = 0;

  system(CLEAR);
  cout << "Composition. 21 variant. Khandryga\n";
  cout << "1 - Add object\n";
  cout << "2 - Delete object by ID\n";
  cout << "3 - Find index by ID\n";
  cout << "4 - Show state \n";
  cout << "0 - Exit \n> ";
  cin >> choice;

  return choice;
}

void pause() {
  cout << "Press enter...";
  cin.ignore();
  cin.get();
};