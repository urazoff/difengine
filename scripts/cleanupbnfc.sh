#!/bin/bash

echo "---Run BNFC to generate front-end---"
~/.cabal/bin/bnfc -m -c dfng.cf
for H in `find . -name "*.h"`; do
echo "copy ${H} to difengine/include"
cp ${H} ../include/${H}
done

echo "Fix bnfc issues"

python3 ../scripts/unredef.py Printer.c

make

echo "Delete objects files and auxiliary files"
rm *.o *.bak *.l *.y *.h
