def currentGitBranch():
    return os.popen("git-name-rev HEAD").read().split(" ")[1][:-1]

class P4Debug:
    def __init__(self):
        self.options = [
