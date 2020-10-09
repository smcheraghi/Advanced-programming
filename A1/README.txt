Concordia University
Assignment 1
Professor Sadegh Ghaderpanah
Seyed Mohammad Cheraghi

OS: windows 10
IDE: Visual Studio 2019

---------------------------------------------------------------------------------------
A quick fix is to add the _CRT_SECURE_NO_WARNINGS definition to the project's settings:
Right-click your C++ and chose the "Properties" item to get to the properties window. 
"Configuration Properties" -> "C/C++" -> "Preprocessor" -> "Preprocessor definitions".
In the "Preprocessor definitions" add 
_CRT_SECURE_NO_WARNINGS
