#Coding Standards

##Preprocessor Macros
* Don't use except for header include guards.

##Memory Management
* Don't use naked `new`.
* Use std::unique_ptr for objects which the caller should store.
* Use std::shared_ptr for objects which both the caller and callee will store.
* Temporary parameters should be passed as references or pointers. Parameters which will be stored should be passed as std::unique_ptr or std::shared_ptr. Prefer references to pointers.
* Use nullptr instead of `0` or `#define NULL 0`.

##Copy constructor and assignment operator
* Should be explicitly disabled if not used.

##Namespaces
* Don't use `using namespace std`. Prefix all std classes with std::

##Style
* Class/Struct names use CamelCase with the first letter capitalized.
* Class member variables use camelCase with an m_ prefix.
* Constants use UPPER_CASE.
* All other use camelCase with the first letter lower case.

##Comments
* Doxygen style.

##Editor Settings
* Tab = 4 spaces.
