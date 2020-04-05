#! /usr/bin/env python3
"Run tests in current directory"

import sys, os
import json
import subprocess

CRED = '\033[91m'
CGREEN = '\33[32m'
CEND = '\033[0m'
CINFO = "    "

def main():
    if not sys.argv[1]:
        print("No build dir passed")
        sys.exit() 

    if os.path.exists("suite.json"):
        with open("suite.json") as suite_file:
            suite = json.load(suite_file)
            execs = sys.argv[1] + "/tests/" + suite["id"] + "/"; 
            print("Run", suite["suite_name"], "suite")
            for t in suite["tests"]:
                result = []
                print("Run", t["name"], "test...")
                exe = execs + t["exe"]
                process = subprocess.Popen(exe, stdout=subprocess.PIPE)

                while True:
                    line = process.stdout.readline().decode("utf-8")
                    if line == '':
                        break
                    if (line[0:3] == "RES"):
                        result.append(line[5:][:-1])
                    else:
                        print(CINFO + line[:-1])

                if result == t['expectations']:
                    print(CGREEN + "PASS" + CEND)               
                
    else:
        print("No suite in current directory")
        sys.exit()

if __name__ == '__main__':
    main()
