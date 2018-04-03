        clientPath = clientPath[:-3]
    return clientPath

def die(msg):
    sys.stderr.write(msg + "\n")
    sys.exit(1)

def currentGitBranch():
    return read_pipe("git name-rev HEAD").split(" ")[1].strip()

