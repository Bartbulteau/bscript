#!/usr/bin/python

print "Compiling...\n\n"

from sys import argv

registers = {
    "ax": "0",
    "bx": "1",
    "cx": "2",
    "dx": "3",
    "pc": "4"
}

def isInt(s):
    try: 
        int(s)
        return True
    except ValueError:
        return False


def clear(data):
    cleared = []
    for line in data:
        if '#' in line:
            line = ''
        line = line.translate(None, '\n')
        if line != '':
            cleared.append(line.split(' '))
    return cleared

def translate(data):
    code = ""
    i = 0
    for line in data:
        while i < len(line):

            if line[i] == 'mov':
                i += 2
                if isInt(line[i]):
                    code += '1 '
                    i -= 1
                    code += registers[line[i]]
                    i += 1
                else: 
                    code += '2 '
                    i -= 1
                    code += registers[line[i]]
                    i += 1
                    code += registers[line[i]]
        


            i += 1
    
    return code


            
    
    


if len(argv) < 2:
    print "Please give the input file name."

else: 
    #try:
        file = open(argv[1], 'r')
        data = file.readlines()
        print data
        cleared = clear(data)
        print cleared
        print "\n\n"
        code = translate(cleared)
        print code 
    #except:
        #print "Invalid file name."