    def run(self, args):
        if len(args) == 0:
            self.master = currentGitBranch()
        elif len(args) == 1:
            self.master = args[0]
            if not branchExists(self.master):
                die("Branch %s does not exist" % self.master)
        else:
            return False

        if self.master:
            allowSubmit = gitConfig("git-p4.allowSubmit")
            if len(allowSubmit) > 0 and not self.master in allowSubmit.split(","):
                die("%s is not in git-p4.allowSubmit" % self.master)

        [upstream, settings] = findUpstreamBranchPoint()
        self.depotPath = settings['depot-paths'][0]
