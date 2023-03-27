# Image-Editor Refactored

The following serves mostly learning purposes, which are not connected with the language in which it is written. Therefore, while the language used is C++, the code doesn't implement the best solutions/practices, connected with this programming language.

## Original version of the project
The project was an university assignment. The original version can be found by navigating to the original branch and is kept in order to serve as an example for others taking the same course.

## Problems pointed out by the assessment of the original project
The following are the summarized remarks given by the assessors of the original project. They might (and most likely) only be useful to people taking the same subject at the same university and even by the same assessors. However, the branch doesn't bother much with them except for pointing them out here.
- Use an environment in which debugging and compiling is easier;
- Combine more classes in the same file;
- Avoid making use of design patterns if not needed (very likely this branch will include such ones just as a way to experiment with them);
- Missing doxygen comments (this one will never be added);
- Pixel is too big;
- Jerarchy by the image types would have been better;
- Make use of passing by const reference;
- Saving the information in string and pixels is unnecessary;
- Avoid using exceptions;

Final grade: 7/10.

## Current state:
Some of the basic functionalities are functioning correctly. Only basic tests exist. There are a lot of code smells and the code is in need of refactoring.

## Future goals:
- Test the parts of the code which are testable by simple unit tests that don't require mocking/stub.
- Create tests using by making use of mocking.
- Create a better and more usable Makefile.
- Use address/leak sanitizers.
- Use static analyzer(cppcheck).
