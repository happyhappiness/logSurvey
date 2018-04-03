
    def start(self):
        if len(self.config) > 0 and not self.reset:
            die("Cannot start sync. Previous sync config found at %s" % self.configFile)

        commits = []
        for line in mypopen("git rev-list --no-merges %s..%s" % (self.origin, self.master)).readlines():