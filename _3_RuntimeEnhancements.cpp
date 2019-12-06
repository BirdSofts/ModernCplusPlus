
// --------------------------------------------------------------------------------
/// <summary>
/// _1_Introduction.cpp
/// </summary>
/// <created>ʆϒʅ,06.12.2019</created>
/// <changed>ʆϒʅ,07.12.2019</changed>
// --------------------------------------------------------------------------------

#include "pch.h"
#include "Console.h"


#define Tab '\t'
#define Nline '\n'


void _03_01_ ()
{
  try
  {
    ColourCouter ( " -------------------------------------------------", F_bRED );
    ColourCouter ( "-------------------------------------------------\n\n", F_bRED );

    //! ####################################################################
    //! ~~~~~ language runtime enhancements:
    // 
    ColourCouter ( "~~~~~ Language runtime enhancements:\n", F_bWHITE );
    ColourCouter ( ".\n\n", F_YELLOW );



    //ColourCouter ( "\n", F_bYELLOW );
    //ColourCouter ( "\n", F_bCYAN );
    //! - in addition:
  }
  catch (const std::exception&)
  {

  }
}
