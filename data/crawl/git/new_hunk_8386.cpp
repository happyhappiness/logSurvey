            return False
        maxChange = int(args[0])

        if "p4ExitCode" in p4Cmd("p4 changes -m 1"):
            die("Problems executing p4");

        if self.rollbackLocalBranches:
            refPrefix = "refs/heads/"
            lines = mypopen("git rev-parse --symbolic --branches").readlines()