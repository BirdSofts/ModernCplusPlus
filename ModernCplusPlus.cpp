
// --------------------------------------------------------------------------------
/// <summary>
/// ............................::Nerd snow sayings!::............................
/// nerd Snow's sayings!
/// Learning C++
/// Programming needs patience and practical practice.
/// Programming in a way, that no nerdy dog in the future is able to compile it, is to be avoided!
/// I was almost a good nerd and emptied my Recycle Bin regularly at the night! :) So be a lamb (^.^) and stay a good nerd!
/// </summary>
/// <created>ʆϒʅ,27.11.2019</created>
/// <changed>ʆϒʅ,27.11.2019</changed>
// --------------------------------------------------------------------------------

#include "pch.h"
#include "Console.h"
#include "_1_Introduction.h"


int main ()
{
  try
  {
#pragma region Console
    // font
    COORD fontS { 16,16 };
    ConsoleFont ( L"Courier New" );
    ConsoleFontSize ( fontS );
    ConsoleFontColour ( F_WHITE );
    // screen
    COORD leftANDtop { 15,15 };
    COORD widthANDheight { 102,32 };
    COLORREF backColour { RGB ( 50,50,50 ) };
    ConsoleScreenPosition ( leftANDtop );
    ConsoleScreenSize ( widthANDheight );
    ConsoleScreenColour ( backColour );

    //// cursor
    //ConsoleCursorState ( false );

    //// codec
    //UINT consoleOutputCPstorage;
    //consoleOutputCPstorage = GetConsoleOutputCP ();
    //SetConsoleOutputCP ( CP_UTF8 );

    //// back to default codec
    //SetConsoleOutputCP ( consoleOutputCPstorage );
#pragma endregion

    //! ...................................:: References ::...................................
    // https://changkun.de/modern-cpp/en-us/00-preface/index.html
    // http://www.cplusplus.com/doc/
    // https://stackoverflow.com/
    // http://de.cppreference.com/
    // https://docs.microsoft.com/
    // https://www.ibm.com/support/knowledgecenter/en/
    // https://www.tutorialspoint.com/cplusplus/
    // C++ reference: http://www.cplusplus.com/reference/
    ColourCouter ( " -------------------------------------------------", F_bRED );
    ColourCouter ( "--------------------------------------------------\n", F_bRED );
    ColourCouter ( "References:\n", F_bWHITE );
    ColourCouter ( "https://changkun.de/modern-cpp/en-us/00-preface/index.html\n", F_YELLOW );
    ColourCouter ( "http://www.cplusplus.com/doc/\n", F_YELLOW );
    ColourCouter ( "https://stackoverflow.com/\n", F_YELLOW );
    ColourCouter ( "http://de.cppreference.com/\n", F_YELLOW );
    ColourCouter ( "https://docs.microsoft.com/\n", F_YELLOW );
    ColourCouter ( "https://www.ibm.com/support/knowledgecenter/en/\n", F_YELLOW );
    ColourCouter ( "https://www.tutorialspoint.com/cplusplus/\n", F_YELLOW );
    ColourCouter ( "C++ reference: http://www.cplusplus.com/reference/\n", F_YELLOW );
    ColourCouter ( " -------------------------------------------------", F_bRED );
    ColourCouter ( "--------------------------------------------------\n", F_bRED );
    //! ...............................:: nerd Snow's sayings! ::...............................
    ColourCouter ( "Nerd snow's sayings!\n", F_bWHITE );
    ColourCouter ( "Programming needs patience and practical practice.\n", F_YELLOW );
    ColourCouter ( "Programming in a way, that no nerdy dog in the future is able to compile it, is to be avoided!\n", F_YELLOW );
    ColourCouter ( "I was almost a good nerd and emptied my Recycle Bin regularly at the night! :) So be a lamb (^.^) and stay a good nerd!\n", F_YELLOW );
    ColourCouter ( " -------------------------------------------------", F_bRED );
    ColourCouter ( "--------------------------------------------------\n\n", F_bRED );

    ColourCouter ( " +++++++++++++++++++++++++++++++++++++++++++++++++", F_bRED );
    ColourCouter ( "++++++++++++++++++++++++++++++++++++++++++++++++++\n", F_bRED );
    ColourCouter ( ".:: Introduction ::.\n", F_CYAN );

    _01_01_Introduction ();

    //! .................................:: BASICS OF C++ ::.................................
    ColourCouter ( " +++++++++++++++++++++++++++++++++++++++++++++++++", F_bRED );
    ColourCouter ( "++++++++++++++++++++++++++++++++++++++++++++++++++\n", F_bRED );
    ColourCouter ( ".:: BASICS OF C++ ::.\n", F_CYAN );



    ColourCouter ( " +++++++++++++++++++++++++++++++++++++++++++++++++", F_bRED );
    ColourCouter ( "++++++++++++++++++++++++++++++++++++++++++++++++++\n", F_bRED );
  }
  catch (const std::exception&)
  {

  }

  // preventing the instant closing of console window, so the result could be seen
  // not a good practice anyhow with a lot discussion in the internet
  // alternatives:
  // Ctrl+F5 is, which compile without debugging
  // putting a break point at the end of the function main
  system ( "PAUSE" ); // system dependent
  std::cin.get (); // alternative and portable
  // for advanced programmer: your program should be able to handle it itself

  //return 0;
  return EXIT_SUCCESS; // see the tutorials > functions section > the return value of main
}
