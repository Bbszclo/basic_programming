import sys
from sys import argv

def read_key_values(filename):
    """
    Reads a key-value delimited file (separated by first =) into a dictionary

    Args:
    filename(str): name of the file to read
    
    Returns:
    dictionary of the read items
    """
    result = {}
    with open(filename) as file:
        for line in file:
            parts = line.split("=", maxsplit=1)
            result [parts[0]] = parts [1].strip()
    return result



def create_output_filename(name):
    """
    create the output file name.  Given an input filename such as "input.txt",
    return "input.txt.counts"
    """
    if type(name) is str:
        new_name = name + ".counts"
        return new_name
    else:
        return None


def process_key_file(filename,key_values):
    """
    Loads in a key file and produces a dictionary of the count of the values 
    If a key is not found in key_values use "<unknown>"

    Args:
    filename(str): file containing keys to process
    key_values(dict): existing keys to load
    """
    #得call read_key_value 然后read 然后存在result 然后通过读result就建立新的counts dict然后来把里面的key_value pair 用ticker弄进来
    counts= {}
    with open(filename) as file:
        for line in file:
            if  line.strip() not in key_values:
                if "<unknown>" not in counts:
                    counts ["<unknown>"] = 1
                else:
                    counts ["<unknown>"] +=1

            else:
                if key_values[line.strip()] not in counts:
                    counts [key_values[line.strip()]] = 1
                else:
                    counts [key_values[line.strip()]] +=1
            
    return counts


def write_output(filename,counts):
    """
    Sort the output value the highest count descending. If two values are
    equal, arbitrarily choose 1
    filename is string, counts is dict
    """
    sorted_dicts = dict(sorted(counts.items(), key = lambda item: item[1],reverse=True))
    file = open(filename,'w')
    for key,value in sorted_dicts.items():
        file.write(key.strip()+": "+str(value)+"\n")

def process(args):
    """
    Implement your algorithm in this function
    Algorithm: (this is largely the contents/outline of "process")

    get the filename of first argument
    load the contents in a dictionary //process_key_file(filename,key_values):
    for each of the remaining files
    create a new dictionary to store the "value" and number of occurrences (i.,e "counts" dictionary)
    read the file
    foreach line
    get the corresponding value from the first dictionary
    update the counts dictionary
    output counts file
    """
    # print(args)   #Uncomment if you want to validate/see the command-line arguments
    key_values = read_key_values(args[1])

    # print(key_values)
    for filename in args[2:]:
        new_filename = create_output_filename(filename)
        counts = process_key_file(filename, key_values)
        write_output(new_filename, counts)





# __name__ == "__main__" and argv explained in the "modules" notebook
if __name__ == "__main__":
    argv = ["key_value.py","kvs1.txt",'list1a.txt','list1b.txt']
    if len(argv) < 3:
        print("Usage: python3 key_value.py file1_name file2_name ...")
        sys.exit(-1)
    process(argv)
