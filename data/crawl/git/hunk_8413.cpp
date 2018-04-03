                 tokens = line[:-1].split("=")
                 self.logSubstitutions[tokens[0]] = tokens[1]
 
-        if len(self.master) == 0:
-            self.master = currentGitBranch()
-            if len(self.master) == 0 or not os.path.exists("%s/refs/heads/%s" % (gitdir, self.master)):
-                die("Detecting current git branch failed!")
-
         self.check()
         self.configFile = gitdir + "/p4-git-sync.cfg"
         self.config = shelve.open(self.configFile, writeback=True)
