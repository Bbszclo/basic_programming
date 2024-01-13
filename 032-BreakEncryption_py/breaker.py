from curses.ascii import isalpha
import sys
from sys import argv
import os

def deencrypt(f):
    map = {}
    while True:
        c = f.read(1)
        if not c: break     # legal syntax, useful for this situation

        if c.isalpha():
            c = c.lower()
            frequency = map.get(c, 0) + 1 
            map[c] = frequency

    first = sorted(map, key = map.get,reverse=True)[0]
    second = sorted(map, key = map.get,reverse=True)[1]
    if map[first] == map[second]:
        raise ValueError
    flag = (ord(first) - ord('e') + 26) % 26
    print(flag) 


if __name__ == "__main__":
    if len(argv) != 2 and len(argv) != 1:
        print("Usage: python3 breaker.py input_file_name")
        sys.exit(1)

    try:
        if argv[0] != "breaker.py":
            raise ValueError
        if os.path.getsize(argv[1]) == 0:
            raise ValueError
        file = open(argv[1])
        deencrypt(file)

    except ValueError:
        print("Invalid key: Must be a non-zero integer")
        sys.exit(1)

    