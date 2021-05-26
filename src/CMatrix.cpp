#include "../include/CMatrix.h"

CMatrix::CMatrix(): size(4) {
  create();
}

CMatrix::CMatrix(float *source, size_t s_size): size(s_size) {
  create();
  for(size_t i = 0; i < s_size; i++)
    for(size_t j = 0; j < s_size; j++)
      matrix[i][j] = *((source + i * s_size) + j);
}

CMatrix::CMatrix(size_t s_size): size(s_size) {
  create();
}

CMatrix::CMatrix(const CMatrix & N): size(N.size) {
  create();
  for (int i = 0; i < size; i++)
    for (int j = 0; j < size; j++)
      matrix[i][j] = N.matrix[i][j];
}

void CMatrix::create() {
  matrix = new float*[size];
  for (int i = 0; i < size; i++) {
    matrix[i] = new float[size];
    for (int j = 0; j < size; j++) {
      matrix[i][j] = (float)(i * size + j);
    }
  }
}


CMatrix::~CMatrix() {
  for (int i = 0; i < size; i++) 
    delete []matrix[i];

  delete []matrix;
}

int CMatrix::getSize() {
  return size;
}

int CMatrix::getId() {
  return id;
}

void CMatrix::setId(int _id) {
  id = _id;
}

bool CMatrix::checkId(int _id) {
  return id == _id;
}

float CMatrix::getElement(int i, int j) { 
  if (outOfBoundsCheck(i, j)) return 0;
  return matrix[i][j]; 
}

float CMatrix::setElement(int i, int j, float value) {
  if (outOfBoundsCheck(i, j)) return 0;
  return matrix[i][j] = value;
}

CMatrix CMatrix::multiply(int m) const {
  for (int i = 0; i < size; i++)
    for (int j = 0; j < size; j++)
      matrix[i][j] *= m;

  return *this;
}

void CMatrix::transponse() {
  CMatrix tmp(*this);
  
  for(int i = 0; i < size; i++)
    for (int j = 0; j < size; j++)
      matrix[i][j] = tmp.matrix[j][i];
}

CMatrix & CMatrix::operator = (const CMatrix & right) {
  size = right.size;
  create();
  
  for (int i = 0; i < right.size; i++)
    for (int j = 0; j < right.size; j++)
      matrix[i][j] = right.matrix[i][j];

  id = right.id;
  return *this;
}

CMatrix CMatrix::operator *(const int & num) const {
  CMatrix temp(*this);
  return temp.multiply(num);
}

CMatrix operator * (const int & num, const CMatrix &m) {
  return (m * num);
}

std::ostream & operator<< (std::ostream &out, const CMatrix &M) {
  for(int i = 0; i < M.size; i++) {
    for (int j = 0; j < M.size; j++) {
      out << M.matrix[i][j];
      out << "\t";
    }

    out << std::endl;
  }

  return out;
}

bool CMatrix::outOfBoundsCheck(int i, int j) {
  if(i > size - 1 || j > size - 1 || j < 0 || i < 0) {
    std::cout << "Ошибка! Индексы за пределами матрицы! \n";
    return true;
  }
  return false;
}