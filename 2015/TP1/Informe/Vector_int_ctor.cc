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
