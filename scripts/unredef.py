#! /usr/bin/env python3
"Delete redefines from passed C code"

import sys, os
  
ppIdent_redef = (
                 "\nvoid ppIdent(String s, int i)\n"
                 "{\n"
                 "  renderS(s);\n"
                 "}\n\n"
                ) 

shIdent_redef = (
                 "\n\nvoid shIdent(String s)\n"
                 "{\n"
                 "  bufAppendC('\\\"');\n"
                 "  bufAppendS(s);\n"
                 "  bufAppendC('\\\"');\n"
                 "}\n\n"
                )

def main():
    if not sys.argv[1:]:
        print("No filenames passed")
    for filename in sys.argv[1:]:
        if os.path.isdir(filename):
            print(filename, "Directory!")
            continue
        with open(filename, "rb") as f:
            data = f.read()
        if b'\0' in data:
            print(filename, "Binary!")
            continue
        newdata = data.replace(ppIdent_redef.encode(), b"\n")
        newdata = newdata.replace(shIdent_redef.encode(), b"\n")
        if newdata != data:
            print(filename)
            with open(filename, "wb") as f:
                f.write(newdata)

if __name__ == '__main__':
    main()
