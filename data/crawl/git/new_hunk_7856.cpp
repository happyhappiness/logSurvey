    a plus sign, it is also executable"""
    return (re.search(r"(^[cku]?x)|\+.*x", kind) != None)

def setP4ExecBit(file, mode):
    # Reopens an already open file and changes the execute bit to match
    # the execute bit setting in the passed in mode.

    p4Type = "+x"

    if not isModeExec(mode):
        p4Type = getP4OpenedType(file)
        p4Type = re.sub('^([cku]?)x(.*)', '\\1\\2', p4Type)
        p4Type = re.sub('(.*?\+.*?)x(.*?)', '\\1\\2', p4Type)
        if p4Type[-1] == "+":
            p4Type = p4Type[0:-1]

    system("p4 reopen -t %s %s" % (p4Type, file))

def getP4OpenedType(file):
    # Returns the perforce file type for the given file.

    result = read_pipe("p4 opened %s" % file)
    match = re.match(".*\((.+)\)$", result)
    if match:
        return match.group(1)
    else:
        die("Could not determine file type for %s" % file)

def diffTreePattern():
    # This is a simple generator for the diff tree regex pattern. This could be
    # a class variable if this and parseDiffTreeEntry were a part of a class.
