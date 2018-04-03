    # Returns the perforce file type for the given file.

    result = read_pipe("p4 opened %s" % file)
    match = re.match(".*\((.+)\)$", result)
    if match:
        return match.group(1)
    else:
        die("Could not determine file type for %s" % file)

def diffTreePattern():
    # This is a simple generator for the diff tree regex pattern. This could be
