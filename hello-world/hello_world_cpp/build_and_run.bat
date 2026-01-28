@echo off
cd /d "%~dp0"
"C:\Program Files\Microsoft Visual Studio\18\Insiders\VC\Auxiliary\Build\vcvarsall.bat" x64
cl "hello world.cpp"
if exist hello.exe (
  echo Running hello.exe...
  hello.exe
) else (
  echo hello.exe not found; check compiler output above.
)
pause
