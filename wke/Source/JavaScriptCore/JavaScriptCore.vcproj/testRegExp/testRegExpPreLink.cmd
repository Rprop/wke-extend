mkdir 2>NUL "%INTDIR%\lib"

if exist "%WEBKITLIBRARIESDIR%\lib\icuuc%LIBRARYCONFIGSUFFIX%.lib" copy /y "%WEBKITLIBRARIESDIR%\lib\icuuc%LIBRARYCONFIGSUFFIX%.lib" "%INTDIR%\lib\libicuuc%LIBRARYCONFIGSUFFIX%.lib"
if exist "%WEBKITLIBRARIESDIR%\lib\icuin%LIBRARYCONFIGSUFFIX%.lib" copy /y "%WEBKITLIBRARIESDIR%\lib\icuin%LIBRARYCONFIGSUFFIX%.lib" "%INTDIR%\lib\libicuin%LIBRARYCONFIGSUFFIX%.lib"

if exist "%WEBKITLIBRARIESDIR%\lib\libicuuc%LIBRARYCONFIGSUFFIX%.lib" copy /y "%WEBKITLIBRARIESDIR%\lib\libicuuc%LIBRARYCONFIGSUFFIX%.lib" "%INTDIR%\lib"
if exist "%WEBKITLIBRARIESDIR%\lib\libicuin%LIBRARYCONFIGSUFFIX%.lib" copy /y "%WEBKITLIBRARIESDIR%\lib\libicuin%LIBRARYCONFIGSUFFIX%.lib" "%INTDIR%\lib"

cmd /c
