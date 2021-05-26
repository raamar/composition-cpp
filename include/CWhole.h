#pragma once
#include <iostream>
#include "CMatrix.h"

class CWhole {
  private:
    size_t length;
    void _add(CMatrix obj);
  public:
    CWhole();
    ~CWhole();
    CMatrix * storage;
    void add(CMatrix obj);
    void add(CMatrix obj, int id);
    void remove(int id);
    int getIndexById(int id);
    void showInfo();
};
