        if len(p4CmdList("opened ...")) > 0:
            die("You have files opened with perforce! Close them before starting the sync.")

    def start(self):
        if len(self.config) > 0 and not self.reset:
            die("Cannot start sync. Previous sync config found at %s\n"
                "If you want to start submitting again from scratch "
                "maybe you want to call git-p4 submit --reset" % self.configFile)

        commits = []
        for line in read_pipe_lines("git rev-list --no-merges %s..%s" % (self.origin, self.master)):
            commits.append(line.strip())
        commits.reverse()

        self.config["commits"] = commits

    # replaces everything between 'Description:' and the next P4 submit template field with the
    # commit message
    def prepareLogMessage(self, template, message):
