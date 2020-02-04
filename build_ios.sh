rm -rf build
mkdir build
cd build
cmake ../platform/ios/staticlib -G Xcode -DCMAKE_TOOLCHAIN_FILE=../platform/ios/ios.toolchain.cmake -DPLATFORM=OS
cmake --build . --config Release --target install
