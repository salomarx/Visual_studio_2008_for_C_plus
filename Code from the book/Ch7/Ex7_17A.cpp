// Ex7_17A.cpp : main project file.
// Defining and using default indexed properties
// With set indexed property capability added

#include "stdafx.h"

using namespace System;

ref class Name
{
  private:
  array<String^>^ Names;

public:
  Name(...array<String^>^ names) : Names(names) {}

  // Scalar property specifying number of names
  property int NameCount
  {
    int get() {return Names->Length; }
  }

  // Indexed property to return names
  property String^ default[int]
  {
    String^ get(int index)
    {
      if(index >= Names->Length)
        throw gcnew Exception(L"Index out of range"); 
      return Names[index]; 
    }

    void set(int index, String^ name)
    {
      if(index >= Names->Length)
        throw gcnew Exception(L"Index out of range"); 
      Names[index] = name; 
    }
  }
};

int main(array<System::String ^> ^args)
{
  Name^ myName = gcnew Name(L"Ebenezer", L"Isaiah", L"Ezra", L"Inigo",
                                                               L"Whelkwhistle");
  myName[myName->NameCount - 1] = L"Oberwurst";  // Change last indexed property

  // List the names
  for(int i = 0 ; i < myName->NameCount ; i++)
    Console::WriteLine(L"Name {0} is  {1}", i+1, myName[i]);
  return 0;
}
