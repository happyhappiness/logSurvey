
    def start(self):
        if len(self.config) > 0 and not self.reset:
            die("Cannot start sync. Previous sync config found at %s\n"
                "If you want to start submitting again from scratch "
                "maybe you want to call git-p4 submit --reset" % self.configFile)

        commits = []
        if self.directSubmit:
