        clientPath = clientPath[:-3]
    return clientPath

def currentGitBranch():
    return read_pipe("git name-rev HEAD").split(" ")[1].strip()

