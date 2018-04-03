            print "Internal error: cannot locate perforce depot path from existing branches"
            sys.exit(128)

        self.clientPath = p4Where(self.depotPath)

        if len(self.clientPath) == 0:
            print "Error: Cannot locate perforce checkout of %s in client view" % self.depotPath
            sys.exit(128)

        print "Perforce checkout for depot path %s located at %s" % (self.depotPath, self.clientPath)
        self.oldWorkingDirectory = os.getcwd()
