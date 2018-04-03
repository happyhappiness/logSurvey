def parseRevision(ref):
    return read_pipe("git rev-parse %s" % ref)[:-1]

def system(cmd):
    if os.system(cmd) != 0:
        die("command failed: %s" % cmd)

def extractLogMessageFromGitCommit(commit):
    logMessage = ""

