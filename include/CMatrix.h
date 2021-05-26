#pragma once
#include <iostream>

class CMatrix {
  private:
    size_t size;
    int id;
    float **matrix;
    void create();
    bool outOfBoundsCheck(int, int);
    CMatrix multiply(int) const;
  public: 
    CMatrix();
    CMatrix(float *, size_t);
    CMatrix(size_t);
    CMatrix(const CMatrix &);
    ~CMatrix();
    int getSize();
    int getId();
    void setId(int _id);
    bool checkId(int _id);
    void transponse();
    float getElement(int, int);
    float setElement(int, int, float);
    CMatrix & operator = (const CMatrix &);
    CMatrix  operator * (const int &num) const;
    friend CMatrix operator * (const int &, const CMatrix &);
    friend std::ostream & operator<< (std::ostream &, const CMatrix &);
};