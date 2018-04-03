                tokens = line[:-1].split("=")
                self.logSubstitutions[tokens[0]] = tokens[1]

        self.check()
        self.configFile = gitdir + "/p4-git-sync.cfg"
        self.config = shelve.open(self.configFile, writeback=True)
