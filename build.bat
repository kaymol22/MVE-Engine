@echo off
setlocal

rem Set build dir
set BUILD_DIR="build"

if "!CLEAN_BUILD!"=="true" (
    rmdir /s /q %BUILD_DIR%
    mkdir %BUILD_DIR%
)

if not exist %BUILD_DIR% mkdir %BUILD_DIR%

pushd %BUILD_DIR%

cmake .. -G "Ninja" -DCMAKE_BUILD_TYPE=Debug -DCMAKE_EXPORT_COMPILE_COMMANDS=ON ..

cmake --build .

echo Running the executable
lve_engine.exe

rem Go back to original directory
popd

endlocal