import sys
import argparse
parser = argparse.ArgumentParser(description='Process some numbers.')
args = parser.parse_args()

prod = 1;

while True:
    try:
        input = raw_input()
        
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
