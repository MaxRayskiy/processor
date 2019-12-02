#ifndef ASSEMBLY_READER_HPP
#define ASSEMBLY_READER_HPP


template <typename T>
T& GetLexeme(char*& ptr) {
  ptr += sizeof(T);
  return *reinterpret_cast<T*>(ptr - sizeof(T));
}

#endif // ASSEMBLY_READER_HPP
