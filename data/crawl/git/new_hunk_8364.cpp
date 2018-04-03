def parseRevision(ref):
    return read_pipe("git rev-parse %s" % ref)[:-1]

def extractLogMessageFromGitCommit(commit):
    logMessage = ""

