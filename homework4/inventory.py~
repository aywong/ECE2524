import sys
from sys import argv
import argparse

parser = argparse.ArgumentParser(description='Process some numbers.')
parser.add_argument('-f, --data-file', 
                    dest='inputFile', 
                    action='store', 
                    help='path to the data file to read at startup')
args = parser.parse_args()

#list of parts
partsArr = []

#definitions of functions
def addPart(arg):
    partsArr.append(arg)
    print 'part was added to list'
    
def removePart(arg):
    print 'r'
    
def setPart(arg):
    print 's'
    
def listPart(arg):
    if arg.find('all'):
        for parts in partsArr:
            print parts
            
def sortPart(arg):
    print 'sort'


#reading inputs and placing into a list
try:
    target = open(args.inputFile)
except IOError:
    print 'cannot open file {} '.format(args.inputFile)
else:
    for i in target:
        partsArr.append(i)
        
#carry out commands
try:
    command,param = sys.argv
except ValueError as e:
    sys.stderr.write("Usage: <command> <parameters>")
 
#dictionary (python's case statement)
myDict = {'add': addPart, 'remove': removePart, 'set': setPart, 'list': listPart, 'sort': sortPart}
 
try:
    myDict[action](param) #values of myDict are callable functions
except KeyError as e:
    sys.stderr.write("I don't know waht you mean by {}, {}\n".format(command,param))
    
    

