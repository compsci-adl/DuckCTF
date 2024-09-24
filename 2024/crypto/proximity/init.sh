#!/bin/sh
# Script to generate the challenge files
# Run this after any changes


# CD into script directory
cd "$(dirname "$0")"


# Check arg count
if [ $# -eq 0 ]; then
    echo "./init.sh gen|test|all"
    exit
fi


# Generate files
if [ "$1" == "gen" ] || [ "$1" == "all" ]; then
    mkdir -p dist
    rm -rf dist/*
    python src/generateKeys.py
    cp src/generateKeys.py dist/
    mv output.py dist/output.py
fi


# Test generated files against solution
if [ "$1" == "test" ] || [ "$1" == "all" ]; then
    cd dist/
    cp ../solution/solution.py solution.py

    test=$(python solution.py)
    echo "$test"
    if [ "$test" == "quack{F4C70RI547I0N_7hR0U9H_PRiM3_Cl053n332}" ]; then
        echo "Test Passed!"
    else
        echo "Test Failed!"
    fi

    rm solution.py
fi
