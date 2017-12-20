#!/bin/bash
# This script updates the program (if not up to date), compiles and runs it

# This is the default argument given to run the program. Change it here or
# run the program directly from command line giving any integer you want.
args="50"

repo="https://github.com/georodop/Airport-Simple-Simulation-using-Cpp.git"
dir="Metro-Train-Simple-Simulation-using-Cpp"
progName="airport.out"
flags="-std=c++98"

git pull &> /dev/null
retval=$?
if [ $retval -ne 0 ]; then
    echo "Return code was not zero but $retval"
    git clone $repo &> /dev/null
    cd ./$dir
else
    echo "OK"
fi

g++ ./*.cpp -o $progName $flags
./$progName $args
  