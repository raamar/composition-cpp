#include "../include/CWhole.h"

CWhole::CWhole() {
  length = 0;
  storage = (CMatrix *) malloc(0);
}

void CWhole::_add(CMatrix obj) {
  length++;
  storage = (CMatrix *) realloc(storage, sizeof(CMatrix) * length);
  storage[length - 1] = obj;
}

void CWhole::add(CMatrix obj) {
  int id = 0;
  _add(obj);
  while(getIndexById(id) != -1) id++;
  storage[length - 1].setId(id);
}

void CWhole::add(CMatrix obj, int id) {
  if (getIndexById(id) != -1) {
    std::cout << "Объект с таким ID уже существует!\n";
    return;
  }

  _add(obj);
  storage[length - 1].setId(id);
}

void CWhole::remove(int id) {
  int index = getIndexById(id);
  if (index == -1) return;

  for (int i = index; i < length - 1; i++)
    storage[i] = storage[i + 1];

  length--;
  storage = (CMatrix *) realloc(storage, sizeof(CMatrix) * length);
}

int CWhole::getIndexById(int id) {
  for (int i = 0; i < length; i++)
    if (storage[i].checkId(id)) return i;

  return -1;
};

void CWhole::showInfo() {
  std::cout << "CWhole length: " << length << std::endl;
  std::cout << std::endl;
  for (int i = 0; i < length; i++) {
    std::cout << "storage[" << i << "] - ID: " << storage[i].getId() << std::endl;
    std::cout << storage[i] << std::endl;
  }
}