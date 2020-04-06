#! /usr/bin/env python3
"Run tests in directory"

import sys, os
import argparse
import json
import subprocess

CRED = '\033[91m'
CGREEN = '\33[32m'
CEND = '\033[0m'
CINFO = "    "

def passed(msg):
    print(CGREEN + msg + CEND)

def failed(msg):
    print(CRED + msg + CEND)

def info(msg):
    print(CINFO + msg)

def main(args):
    if os.path.exists(args.suite_dir + "/suite.json"):
        with open(args.suite_dir + "/suite.json") as suite_file:
            suite = json.load(suite_file)
            execs = args.build_dir + "/tests/" + suite["id"] + "/";
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
                        if args.verbose:
                            info(line[:-1])

                if result == t['expectations']:
                    passed("PASS")
                    if args.verbose:
                        for r in result:
                            info(r)

                else:
                    if args.verbose:
                        failed("FAIL: Obtained result")
                        for r in result:
                            info(r)

                        failed("FAIL: Expected result")
                        for e in t['expectations']:
                            info(e)
                    else:
                        failed("FAIL")
    else:
        print("No suite file. Check the suite_dir passed.")
        sys.exit()

if __name__ == '__main__':
    parser = argparse.ArgumentParser(description='Run tests in directory.')
    parser.add_argument("build_dir", help='Build directory')
    parser.add_argument("suite_dir", help='Suite directory')
    parser.add_argument("-v", "--verbose", dest="verbose", action='store_true',
                        help='Verbose output')

    args = parser.parse_args()
    main(args)
