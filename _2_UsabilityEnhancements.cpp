
// --------------------------------------------------------------------------------
/// <summary>
/// _1_Introduction.cpp
/// </summary>
/// <created>ʆϒʅ,27.11.2019</created>
/// <changed>ʆϒʅ,06.12.2019</changed>
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


template<typename tType>
const auto& evaluation ( const tType& input )
{
  if constexpr (std::is_signed_v<tType>)
    return "Negative";
  else
    return "Positive";
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

    //! --- if constexpr
    // from C++17 the condition of a constant expression can be declared using if statement,
    // which results to efficiency considering that the compilation of branch judgement happens at compile time.
    ColourCouter ( "Using if constexpr, it is possible to evaluate constant expressions at compile time.\n\n", F_YELLOW );
    std::cout << evaluation ( -3 ) << Nline << Nline;

    //! --- range-based for loop
    // modern C++ introduces range-based iterative method, resulting to code containing concise loops.
    ColourCouter ( "To iterate more concise, modern C++ interposes range-based loops.\n\n", F_YELLOW );
    std::vector<char> container = { 'a', 'b', 'c' };
    if (
      auto entity = std::find ( container.begin (), container.end (), 'd' );
      entity == container.end ()
      )
    {
      container.push_back ( 'd' );
    }
    for (auto& entity : container) // read/write privilege
    {
      std::cout << entity << Tab;
      entity -= 32;
    }
    std::cout << Nline;
    for (auto entity : container) // read privilege
    {
      std::cout << entity << Tab;
    }
    std::cout << Nline << Nline;
  }
  catch (const std::exception&)
  {

  }
}


template<typename typeOne, typename typeTwo>
class tempType
{
public:
  typeOne one;
  typeTwo two;
};
template<typename typeOne>
using alias = tempType<std::vector<typeOne>, std::string>;

template<typename tTypeA = int, typename tTypeB = float>
auto addition ( tTypeA a, tTypeB b )
{
  return a + b;
}

template<typename... tTypeInfinite> // zero to an infinite number template paramters
class infinite_A {};
template<typename tTypeRequired, typename... tTypeOthers> // at least one template parameter
class infinite_B {};

// method: recursive template function: recursively traverse all template parameters
template<typename tTemp>
void unpack_rec ( tTemp arg )
{
  std::cout << arg << Nline;
};
template<typename tTypeReq, typename... tTypeArgs>
void unpack_rec ( tTypeReq arg, tTypeArgs... elements )
{
  std::cout << arg << Tab;
  unpack_rec ( elements... );
};
// method: variable parameter template expansion: recursive in one function (from C++17)
template<typename tTypeReq, typename... tTypeArgs>
void unpack_prmE ( tTypeReq arg, tTypeArgs... elements )
{
  std::cout << arg << Tab;
  if constexpr (sizeof...(elements) > 0)
    unpack_prmE ( elements... );
  else
    std::cout << Nline;
};
// method: initialize list expansion: using the features provided by Lambada expressions
template<typename tTypeReq, typename... tTypeArgs>
void unpack_initialE ( tTypeReq arg, tTypeArgs... elements )
{
  std::cout << arg << Tab;

  // after list initialization, the expansion of Lambada expression happens,
  // and the comma operator initiates the execution of preceding expression first,
  // through which the output is complete.
  // note that the explicit conversion to void is to avoid compiler warnings
  // note try debugging the lines to watch the algorithm behaviour step by step.
  (void) std::initializer_list<tTypeReq>
  {
    // (Lambada expression, arg)
    ([&elements] { std::cout << elements << Tab; }(), arg)...
  };

  std::cout << Nline << Nline;
};

template<typename... tTempType>
auto multiplyThePack ( tTempType... input )
{
  return (input * ...);
};

template<int number, typename T>
void printOne ( T text )
{
  std::cout << text << Tab << number << Nline;
};
template<auto input>
void printTwo ( const std::string& text )
{
  std::cout << text << Tab << input << Nline;
};
void _02_06_Templates ()
{
  try
  {
    //! ####################################################################
    //! ----- templates:
    // the known black magic of C++ language has been expanded with new features in moderner versions.
    ColourCouter ( "----- Templates:\n", F_bWHITE );
    ColourCouter ( "In modern C++ templates and generic codes are even more elaborated.\n\n", F_YELLOW );

    //! --- extern templates
    // the conventional way in traditional C++ is to instantiate each defined template code
    // in the instance it is encountered by compiler, which results to increased compile time if instantiations are repeated.
    // interposing extern keyword, C++11 extends the templates definition syntax,
    // which manipulates the original compiler behaviour,
    // providing the ability to explicitly decide where and when to instantiate the defined template.
    ColourCouter ( "Modern C++ introduces the possibility to enforce template instantiations.\n\n", F_YELLOW );

    // to force instantiation in a compilation unit:
    //template class std::vector<int>;

    // to prevent instantiation in a compilation unit:
    // note that the same instantiation must have already been encountered by compiler
    // in another object file in connection with current compilation unit
    //extern temlate class std::vector<int>;

    //! --- continuous right angle brackets
    // concerning templates definitions, modern C++ treat continuous right angle brackets correctly.
    // in traditional C++  two of the were accepted an compiled to right shift operator.
    ColourCouter ( "In modern C++ complex templates can be compiled.\n\n", F_YELLOW );
    std::vector<std::vector<int>> _2D_array; // a not-compilable expression in traditional c++
    for (int i = 0; i < 3; i++)
    {
      _2D_array.push_back ( { i, i } );
    }
    for (auto entity : _2D_array)
    {
      for (auto element : entity)
      {
        std::cout << element << Tab;
      }
      std::cout << Nline;
    }
    std::cout << Nline;

    //! --- template type alias
    // in modern C++ using keyword can be used to introduces aliases for template types.
    ColourCouter ( "The keyword using aliases template types likewise.\n\n", F_YELLOW );
    alias<int> test;
    test.one.push_back ( 1 );
    test.two = " is odd.";
    std::cout << test.one.front () << test.two << Nline << Nline;

    //! --- default template parameters
    // to prevent the constant need to specify the template type at the moment of each instantiation,
    // C++11 provide the ability to define default parameters of a template type.
    ColourCouter ( "Templates can introduce their default template parameters.\n\n", F_YELLOW );
    std::cout << addition ( 1, .1f ) << Nline << Nline;

    //! --- variadic templates
    // modern C++ provides the concept of templates with an infinite number of template parameters of any category
    // as a pack without the need to specify the number of parameters at definition time.
    // note syntax template<typename... tName> class class_name;
    // this template class can accept zero to infinite number of template parameters without restriction.
    ColourCouter ( "Templates can be introduced with an infinite number of parameters.\n\n", F_YELLOW );
    infinite_A<> testOne; // zero template parameters
    infinite_B<short, int, float, double> testTwo; // four template parameters

    infinite_B<int> testThree; // at least one template parameter

    //! - in addition:
    // there are different methods to unpack the template parameter pack
    //--- the number of arguments is determined by sizeof...() operator
    // note pay close attention to the use of infinite number operator (...)
    unpack_rec ( "Method: recursive template function\t", 1, 2, 3.3 );
    unpack_prmE ( "Method: variable parameter template expansion", 1, 2, 3.3 ); // (from C++17)
    unpack_initialE ( "Method: initialize list expansion\t", 1, 2, 3.3 );

    //! - research: using std::bind to forward and bind the template parameters

    //! --- fold expression
    // from C++ 17, packed template parameters can additionally be expanded and used in simple expressions.
    ColourCouter ( "Expression can harness the features provided through packed template parameters.\n\n", F_YELLOW );
    std::cout << multiplyThePack ( 2, 2, 2, 2, 2, 2, 2, 2, 2, 2 ) << Nline << Nline;

    //! --- not-type template parameter deduction
    // modern C++ makes type deduction even in template parameters possible
    // and in C++17 the more elaborated version of this feature is introduced to further simplify the process
    // by using the auto keyword and not providing the exact type of template parameter.
    ColourCouter ( "Template parameters types can be deduced.\n\n", F_YELLOW );
    printOne<1> ( "Not using auto keyword:" );
    printTwo<1> ( "Using auto keyword:" ); // from C++17
    std::cout << Nline;
  }
  catch (const std::exception&)
  {

  }
}


class delegate
{
private:
  int entity;
public:
  delegate () : entity ( 3 ) {};
  delegate ( int input ) : delegate ()
  {
    for (int i = 0; i < entity; i++)
      input *= input;
    entity = input;
  };
  int getResult () { return entity; };
};
class inherited : public delegate
{
public:
  using delegate::delegate; // inherit constructors of base class
};
class Base
{
private:
public:
  virtual void toOverload () {};
  virtual void notToOverload () final {}; // final: overloading not possible
};
class Subclass final : public Base // final: no further inheritance is possible
{
private:
public:
  void toOverload () override {}; // legal: virtual function exists
  //void toOverload ( int a ) override {}; // illegal: no virtual function exists
  //void notToOverload () {}; // illegal: final
};
//class SubTwo : public Subclass // illegal: final
//{
//private:
//public:
//};
void _02_07_ObjectOriented ()
{
  try
  {
    //! ####################################################################
    //! ----- object-oriented:
    // as development of C++ language steps forward, the concepts of OOP becomes more elaborated.
    ColourCouter ( "----- Object-oriented:\n", F_bWHITE );
    ColourCouter ( "C++ language as an object-oriented programming language is in constant expansion.\n\n", F_YELLOW );

    //! --- delegate constructor
    // for convenient and simplicity sake, C++11 equips the concept of classes with delegate constructor,
    // to which a call from the constructor of the class is to undertake.
    ColourCouter ( "A class constructor can call other constructors of the class as its delegate.\n\n", F_YELLOW );
    delegate one ( 2 );
    std::cout << "The result is:" << Tab << one.getResult () << Nline << Nline;

    //! --- inheritance constructor
    // using the using keyword,
    // modern C++ (from C++11) expands the concepts of inheritance between classes even to their constructors further,
    // thus cutting on efficiency issues, when passing arguments to constructors of a base class.
    ColourCouter ( "In modern C++ the constructors of a base class can be inherited.\n\n", F_YELLOW );
    inherited subOne ( 2 );
    std::cout << "The result is:" << Tab << subOne.getResult () << Nline << Nline;

    //! --- explicit virtual function overwrite
    // accidental overloading or not overloading virtual functions by programmer,
    // either reasoned through the wish of having two functions with the same name,
    // or a deleted virtual function inherited and not overloaded because of the ownership over the deleted version,
    // are catastrophic, for which to overcome C++11 introduces the keywords override and final.

    //! the keyword override
    // preceded by overload's declaration, explicitly tells the compiler to overload,
    // resulting to no compilation if virtual function doesn't exist.

    //! the keyword final
    // preceded by virtual function's declaration, explicitly makes the overload process impossible.
    // preceded by class's declaration, explicitly breaks the inheritance feature there of.
    ColourCouter ( "Ownership over virtual functions can be explicitly controlled.\n\n", F_YELLOW );
  }
  catch (const std::exception&)
  {

  }
}
