        # make gitdir absolute so we can cd out into the perforce checkout
        gitdir = os.path.abspath(gitdir)
        os.environ["GIT_DIR"] = gitdir

        if len(args) == 0:
            self.master = currentGitBranch()
            if len(self.master) == 0 or not os.path.exists("%s/refs/heads/%s" % (gitdir, self.master)):
                die("Detecting current git branch failed!")
        elif len(args) == 1:
            self.master = args[0]
        else:
            return False

        depotPath = ""
        if gitBranchExists("p4"):
            [depotPath, dummy] = extractDepotPathAndChangeFromGitLog(extractLogMessageFromGitCommit("p4"))
