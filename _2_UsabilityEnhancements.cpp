
// --------------------------------------------------------------------------------
/// <summary>
/// _1_Introduction.cpp
/// </summary>
/// <created>ʆϒʅ,27.11.2019</created>
/// <changed>ʆϒʅ,30.11.2019</changed>
// --------------------------------------------------------------------------------

#include "pch.h"
#include "Console.h"


#define Tab '\t'
#define Nline '\n'


void _02_01_LanguageUsabilityEnhancements ()
{
  try
  {
    ColourCouter ( " -------------------------------------------------", F_bRED );
    ColourCouter ( "-------------------------------------------------\n\n", F_bRED );

    //! ####################################################################
    //! ~~~~~ language usability enhancements:
    // the very same procedure of bringing an algorithm while using the concepts of a programming language,
    // such as declaration, definition of variables, constants, etc. program flow control, object-oriented paradigms,
    // implemented abstracts with the use of templates, concluding this sentence and using other words,
    // whatever occurred before the runtime at the coding or compiling stages is known as language usability,
    // which summarizes the language behaviour at these stages.
    ColourCouter ( "~~~~~ Language usability enhancements:\n", F_bWHITE );
    ColourCouter ( "Language usability wraps the way in which a language represents the algorithm on a program.\n\n", F_YELLOW );
  }
  catch (const std::exception&)
  {

  }
}


constexpr int len_function_constexpr ( const int& n )
{
  // starting from C++ 14, internal use of simple statements like local variables, loops and branches

  // to nerds, from time to time have fun setting functions at eternal recursivity! :)
  if (n < 3)
    return len_function_constexpr ( n + 1 );
  else if (n > 3)
    return len_function_constexpr ( n - 1 );
  else
    return n;
}
void _02_02_Constants ()
{
  try
  {
    //! ####################################################################
    //! ----- constants:

    //! --- nullptr
    // considering 0 and NULL, which is defined as 0 or ((void*)0) in different compilers, while traditional C++ treats them the same,
    // they result to counter-intuitive code when putting overload feature into practice.
    // in this scenario, nullptr concept appears to replace NULL, whenever defining a pointer,
    // of which the type is nullptr_t, can implicitly be converted to any pointer of different types
    // and is equally or unequally comparable to them.

    //! --- constexpr
    // as a compiler encounters constant expressions like 1+2, 3*4, to increase the performance of the program,
    // the procedure of direct optimization is thought to embed them into result at compile time.
    // with this feature compilation of a lot of illegal expression becomes possible, on the other hand using constexpr,
    // it is possible to explicitly declare the functions or constructors as compile time constant expressions.
    // the constexpr keyword supports the recursivity feature of a function.

    ColourCouter ( "----- Constants:\n", F_bWHITE );
    ColourCouter ( "Use nullptr keyword to solve the confusion when using overloads.\n", F_YELLOW );
    ColourCouter ( "Use constexpr to explicitly define elaborated language concepts as constant expressions.\n\n", F_YELLOW );

#define len_define 3
    const int len { len_define - 3 + 3 }; // legal for mast compilers
    constexpr int len_constexpr { 0 + 1 + 2 };
    std::string arrayOfString_1 [len] { "" };
    std::string arrayOfString_2 [len_constexpr] { "" };
    std::string arrayOfString_3 [len_function_constexpr ( 0 )] { "" };

    arrayOfString_1 [0] = "First storage place of array one!\n";
    arrayOfString_2 [0] = "First storage place of array two!\n";
    arrayOfString_3 [0] = "First storage place of array three!\n";

    std::cout << arrayOfString_1 [0] << arrayOfString_2 [0] << arrayOfString_3 [0] << Nline;
  }
  catch (const std::exception&)
  {

  }
}


void _02_03_VariablesAndInitialization ()
{
  try
  {
    //! ####################################################################
    //! ----- variables and initialization:
    ColourCouter ( "----- Variables and initialization:\n", F_bWHITE );

    //! --- if-switch
    // traditional C++ lacks the support for declarations within the if and switch statements,
    // for which C++ 17 provides the needed concepts to eliminate this limitation.
    ColourCouter ( "Variables declarations within the control statements if and switch are possible.\n\n", F_YELLOW );
    std::vector<char> container = { '|', ':', ')' };
    if (
      std::vector<char>::iterator entity = std::find ( container.begin (), container.end (), ':' );
      entity != container.end ()
      )
    {
      std::cout << *entity << *(entity - 1) << Nline << Nline;
    }

    //! --- initializer list
    // to declare and initialize an object of a class using uniform initialization method,
    // C++ binds the concepts of initialization list to the type and wraps it under std::initializer_list container.
    // note that this method is additionally usable with normal functions.
    ColourCouter ( "It is possible to use initializer lists when instantiating an object.\n\n", F_YELLOW );
    class SomeType
    {
    public:
      std::vector<char> container;
      std::string character;
      SomeType ( std::initializer_list<char> input )
      {
        for (std::initializer_list<char>::iterator entity = input.begin (); entity != input.end (); entity++)
        {
          if (*entity == ':')
            character = *entity;
          else
            container.push_back ( *entity );
        }
      }
    };
    SomeType theObject { '|', ':', ')' };
    for (short i = 0; i < theObject.container.size (); i++)
    {
      std::cout << theObject.character << theObject.container [i] << Tab;
    }
    std::cout << Nline << Nline;

    //! --- structured binding
    // to enclose multiple type bound together and wrapped as a container, C++ provides std::tuple,
    // consumable as function parameters and while its usefulness is clear, the procedure in C++ 11/14 are troublesome:
    //-- there is no simple direct way to define and get the elements from tuple itself
    //-- despite unpack feasibility through std::tie, the developer must be very clear about number of objects and their types.
    // C++ 17 builds upon this container to bring about the possibility to leverage its power.
    ColourCouter ( "Structured binding introduces different objects bound together as an entity.\n\n", F_YELLOW );
    auto [a, b, c] = std::tuple<int, float, char> ( std::make_tuple ( 1, .2f, 'c' ) );
    std::cout << a << Tab << b << Tab << c << Tab << Nline << Nline;
  }
  catch (const std::exception&)
  {

  }
}


template<typename tTypeOne, typename tTypeTwo>
auto concat_one ( tTypeOne a, tTypeTwo b ) -> decltype(a + b) // C++11
{
  return a + b;
}
template<typename tTypeOne, typename tTypeTwo>
auto concat_two ( tTypeOne a, tTypeTwo b ) // C++14
{
  return a + b;
}
decltype(auto) forwarder ()
{
  return concat_two ( 1, 2 );
}
void _02_04_TypeInference ()
{
  try
  {
    //! ####################################################################
    //! ----- type inference:
    // in traditional C++, definitions must be clear, this limitation, when it comes to complex template types,
    // is nothing more than costs on developer's efficiency and unreadable code.
    // modern C++ introduces auto and decltype keywords to derive types,
    // thus like modern languages it is possible to handle the types easier.
    // note that type inferences shall mainly be used when the type can't be determined easily,
    // or them not being used is at the costs of readability.
    ColourCouter ( "----- Type inference:\n", F_bWHITE );
    ColourCouter ( "To deduce the types, when the need to do so is obvious.\n", F_YELLOW );

    //! --- auto
    // auto as an long introduced keyword in C++ language has been coexisting with register keyword
    // in a way to provide the concept that if a declaration is not explicitly a register,
    // it is automatically to be treated as an auto.
    // with deprecation of register as a concept and upholding it as just keyword in C++ 17,
    // the mentioned concept doesn't make sense anymore.
    // therefore the semantic of auto is naturally changed to put automatic derivation into practice.
    // note not possible use cases: function arguments, array types

    // other common use cases, which their real need is discussable, since they are at cost of readability! :)
    //auto var { 3 }; // integer variable
    //auto arr_1 { new auto (3) }; // dynamic integer array
    //auto arr_2 [3] { arr_1 }; // illegal

    ColourCouter ( "The keyword auto introduces automatic derivation of complex data types.\n\n", F_YELLOW );
    std::vector<char> container = { '|', ':', ')' };
    if (
      auto entity = std::find ( container.begin (), container.end (), ':' );
      entity != container.end ()
      )
    {
      std::cout << *entity << *(entity - 1) << Nline << Nline;
    }

    //! --- decltype
    // to overcome the limitation of auto keyword which is usable to declare variables using automatic deduction,
    // modern C++ provides decltype keyword with a very similar usage to sizeof,
    // introducing the calculation of expression types.
    // note syntax:
    // decltype (expression);
    ColourCouter ( "Using the keyword decltype, the type of an expression can be inferred for further usage.\n\n", F_YELLOW );
    auto a { 1 };
    auto b { 2 };
    decltype (a + b) resultType; // note: an uninitialized variable
    if (std::is_same_v<decltype(a), decltype(resultType)>)
      std::cout << "Both variables are of type ";
    if (std::is_same<decltype(a), int>::value)
      std::cout << "integer." << Nline << Nline;

    //! --- tail type inference
    // to derive the return type of functions, combining the keywords auto and decltype,
    // C++11 introduces the concept of trailing return type.
    // from C++14 the same concept is elevated to directly derive the return type of a normal function.
    // note that concerning templates, the keyword typename is the newer and is foreseen to eliminate
    // the ambiguity of variable definitions with nested dependency type in the template.
    ColourCouter ( "Using tail type inference return type of a function can be derived.\n\n", F_YELLOW );
    auto smily { concat_one<char, std::string> ( ':', "|" ) };
    auto number { concat_two<int, short> ( 0, 1 ) };
    std::cout << "Smily " << smily << " is the number " << number << "." << Nline;
    if (std::is_same_v<decltype(smily), std::string>)
      std::cout << "Smily variable type is string." << Nline << Nline;

    //! --- decltype(auto)
    // to complete the set of deduction features, this slightly more complicated use has been added
    // to derive the return type of a forwarding function or package.
    // it builds upon the concepts of parameter forwarding (later chapters).
    ColourCouter ( "The keyword combination decltype(auto) is to derive the return type of a forwarding function.\n\n", F_YELLOW );
    std::cout << "The result of forwarder function: " << forwarder () << Nline << Nline;
  }
  catch (const std::exception&)
  {

  }
}


void _02_05_ControlFlow ()
{
  try
  {
    //! ####################################################################
    //! ----- control flow:
    // 
    ColourCouter ( "----- Control flow:\n", F_bWHITE );
    ColourCouter ( "To some extend modern C++ expands the features of statement and flow control.\n\n", F_YELLOW );

    //! ---
    //
    ColourCouter ( ".\n\n", F_YELLOW );



    //ColourCouter ( "\n", F_bYELLOW );
    //ColourCouter ( "\n", F_bCYAN );
    //! - in addition:
  }
  catch (const std::exception&)
  {

  }
}
