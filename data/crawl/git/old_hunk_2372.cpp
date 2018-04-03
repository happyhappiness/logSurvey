    def run(self, args):
        if len(args) == 0:
            self.master = currentGitBranch()
            if len(self.master) == 0 or not gitBranchExists("refs/heads/%s" % self.master):
                die("Detecting current git branch failed!")
        elif len(args) == 1:
            self.master = args[0]
            if not branchExists(self.master):
                die("Branch %s does not exist" % self.master)
        else:
            return False

        allowSubmit = gitConfig("git-p4.allowSubmit")
        if len(allowSubmit) > 0 and not self.master in allowSubmit.split(","):
            die("%s is not in git-p4.allowSubmit" % self.master)

        [upstream, settings] = findUpstreamBranchPoint()
        self.depotPath = settings['depot-paths'][0]
