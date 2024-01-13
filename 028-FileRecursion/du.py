import sys
import os


def du(file):
    """
    From the given directory produce output similar to the linux command: du -ac
    However rather than the number of blocks the size of the files and directories
    should be printed
    
    returns: size of the given directory and all of its subdirectories/files
    """
    size = 0

    if not os.path.isdir(file): #if not a directory (base case)-->need to exit
            size += os.path.getsize(file)
            print('{}\t{}'.format(os.path.getsize(file),file))
    else:
        for index in range(len(os.listdir(file))): #Returns a list of all of the files in a directory.
            #e.g. notebooks/answers/03-Answers (need to join)
            path = os.path.join(file, os.listdir(file)[index])  #need full path to start with
            sub_size = du(path) #tail recursion
            size += sub_size
        print('{}\t{}'.format(os.path.getsize(file),file))
        size +=  os.path.getsize(file)

    return size


if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: python du.py directory")
        sys.exit(2)
    total_size = du(sys.argv[1])
    print('{}\t{}'.format(total_size,"total"))

