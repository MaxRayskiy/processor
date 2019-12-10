#pragma once

template <typename T>
T& GetLexeme(char*& ptr) {
  ptr += sizeof(T);
  return *reinterpret_cast<T*>(ptr - sizeof(T));
}
