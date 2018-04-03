    a plus sign, it is also executable"""
    return (re.search(r"(^[cku]?x)|\+.*x", kind) != None)

def diffTreePattern():
    # This is a simple generator for the diff tree regex pattern. This could be
    # a class variable if this and parseDiffTreeEntry were a part of a class.
