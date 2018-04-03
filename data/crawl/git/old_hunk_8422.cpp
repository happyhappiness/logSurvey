if len(args) == 1:
    origin = args[0]

def die(msg):
    sys.stderr.write(msg + "\n")
    sys.exit(1)

def system(cmd):
    if os.system(cmd) != 0: