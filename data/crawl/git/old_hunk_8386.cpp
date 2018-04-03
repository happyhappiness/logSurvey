            return False
        maxChange = int(args[0])

        if self.rollbackLocalBranches:
            refPrefix = "refs/heads/"
            lines = mypopen("git rev-parse --symbolic --branches").readlines()