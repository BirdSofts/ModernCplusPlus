
// --------------------------------------------------------------------------------
/// <summary>
/// pch.h
/// </summary>
/// <created>ʆϒʅ,27.11.2019</created>
/// <changed>ʆϒʅ,27.11.2019</changed>
// --------------------------------------------------------------------------------

#ifndef PCH_H
#define PCH_H


#if WIN32
#define WIN32_LEAN_AND_MEAN // rarely-used stuff exclusion
#endif // WIN32


#include <stdio.h> // C language standard input output library
#include <tchar.h> // Microsoft string's differences coverage library

#include <iostream> // C++ standard input and output streams
#include <iomanip> // C++ standard i/o manipulators

#include <string> // C++ standard string class

#include <cwchar> // C++ standard library to work with C wide strings
#include <Windows.h> // Windows standard API's

#include <sstream> // C++ standard string streams

#include <thread> // C++ standard threads

#include <cstdlib> // C++ standard general utilities

#include <array> // C++ standard array container

#include <new> // C++ standard to manage dynamic memory

#include <fstream> // C++ standard file streams

#include <vector> // C++ standard vector container

#include <algorithm> // C++ standard algorithm header


#endif // !PCH_H
