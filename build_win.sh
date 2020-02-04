rm -rf build
mkdir build
cd build
cmake ../platform/win -G "Visual Studio 15 Win64"
cmake --build .
Debug/render.exe