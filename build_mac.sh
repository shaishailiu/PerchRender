rm -rf build
mkdir build
cd build
cmake ../platform/win -G "Xcode"
make
./Render