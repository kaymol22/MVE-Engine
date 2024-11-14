@echo off
setlocal 

set BUILD_DIR=build
set CLEAN_BUILD=true

if "%CLEAN_BUILD%"=="true" (
    if exist %BUILD_DIR% (
        rmdir /S /Q %BUILD_DIR%
    )
)

if not exist %BUILD_DIR% ( 
    mkdir %BUILD_DIR%
)

pushd %BUILD_DIR%

conan install .. --profile=default --output-folder= --build=missing

cmake .. -G "Ninja" -DCMAKE_EXPORT_COMPILE_COMMANDS=ON -DCMAKE_BUILD_TYPE=Release -DCMAKE_TOOLCHAIN_FILE=Release/generators/conan_toolchain.cmake
cmake --build .

if exist mve_engine.exe (
    echo Running the executable...
    mve_engine.exe
) else (
    echo Executable not found.
)

popd

endlocal