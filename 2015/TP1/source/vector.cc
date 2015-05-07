// ------------------------------------------------------------------------- //
// Facultad de Ingeniería de la Universidad de Buenos Aires
// Algoritmos y Programación II
// 1° Cuatrimestre de 2015
// Trabajo Práctico 1: Recursividad
// Cálculo de DFT
// 
// vector.cc
// Implementación de la clase Vector
// ------------------------------------------------------------------------- //

//#include "vector.h"

// Constructor por defecto
template <typename T>
Vector<T>::Vector()
{
  ptr_ = NULL;
  size_ = 0;
}

// Constructor con argumento
template <typename T>
Vector<T>::Vector(int s)
{
  if (s <= 0)
  {
    exit(1);
  }
  else
  {
    size_ = s;
    ptr_ = new T[size_];
  }
}

// Constructor por copia 
template <class T>
Vector<T>::Vector(const Vector<T> &v)
{
  size_ = v.size_ ;
  ptr_ = new T[size_];
  for (int i=0; i < size_; i++)
    ptr_[i] = v.ptr_[i];
}


template <typename T>
Vector<T>::~Vector()
{
  if (ptr_)
    delete [] ptr_;
}


template <typename T>
int
Vector<T>::size() const
{
  return size_;
}


// Operador asignacion
template <typename T>
const Vector<T> &
Vector<T>::operator=(const Vector<T> &rigth)
{
  if (this != &rigth)
  {
    if (size_ != rigth.size_)
    {
      T *aux;
      aux = new T[rigth.size_];
      delete [] ptr_; // si llegó acá es que obtuvo el espacio;libera el anterior espacio

      size_ = rigth.size_;
      ptr_ = aux;
      for (int i=0; i < size_; i++)
        ptr_[i] = rigth.ptr_[i];
  
      return *this;
    }
    else 
    {
      for (int i=0; i < size_; i++)
        ptr_[i] = rigth.ptr_[i];
      
      return *this;
    }
  }
  return *this;
}


// Operador Sub-índice que devuelve rvalue constante
// En caso de pasar un sub-índice fuera de rango el programa finaliza con error
template <typename T>
const T &
Vector<T>::operator[](int i) const
{
  if (i < 0 || i >= size_)
    exit(1);

  return ptr_[i];
}

// Operador Sub-índice que devuelve lvalue modificable
// En caso de pasar un sub-índice fuera de rango el programa finaliza con error
template <typename T>
T &
Vector<T>::operator[](int i)
{
  if (i < 0 || i >= size_)
    exit(1);

  return ptr_[i];
}



// Alta al final
template <typename T>
void
Vector<T>::push_back(const T & data)
{
  T *aux;
  aux = new T[size_ + 1];
  for(int i=0; i<size_; i++)
    aux[i] = ptr_[i];
  aux[size_] = data;
  
  delete [] ptr_;
  ptr_ = aux;
  size_++;  
}



// Baja al final
template <typename T>
void
Vector<T>::pop_back()
{
  T *aux;
  aux = new T[size_ - 1];
  for(int i=0; i<(size_-1); i++)
    aux[i] = ptr_[i];
  
  delete [] ptr_;
  ptr_ = aux;
  size_--;  
}
  
