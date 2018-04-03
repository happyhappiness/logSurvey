        # make gitdir absolute so we can cd out into the perforce checkout
        gitdir = os.path.abspath(gitdir)
        os.environ["GIT_DIR"] = gitdir
        depotPath = ""
        if gitBranchExists("p4"):
            [depotPath, dummy] = extractDepotPathAndChangeFromGitLog(extractLogMessageFromGitCommit("p4"))
