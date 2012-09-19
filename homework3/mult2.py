import sys
import argparse
parser = argparse.ArgumentParser(description='Process some numbers.')
parser.add_argument('--ignore', action='ignore', help='ignores')

args = parser.parse_args()

from sys import argv
from os.path import exists

script, infile = argv

in_file = open(infile)
indata = in_file.read()

if exists(infile)
    while True:
        try:
            input = in_file.readline()
            
            if input != "":
                prod *= int(input)
            else:
                print prod
        except EOFError:
            print '^D'
            break
        except ValueError:
            print 'could not convert string to int: ' + input
            sys.exit(1)  
        
    print prod
