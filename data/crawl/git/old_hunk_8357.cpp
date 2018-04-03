
def system(cmd):
    if verbose:
        sys.stderr.write("executing %s" % cmd)
    if os.system(cmd) != 0:
        die("command failed: %s" % cmd)

