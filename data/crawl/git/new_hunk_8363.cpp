
    return val

def system(cmd):
    if not silent:
        sys.stderr.write("executing %s" % cmd)
    if os.system(cmd) != 0:
        die("command failed: %s" % cmd)



def p4CmdList(cmd):
    cmd = "p4 -G %s" % cmd
    pipe = os.popen(cmd, "rb")
