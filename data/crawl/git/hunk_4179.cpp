             print "Internal error: cannot locate perforce depot path from existing branches"
             sys.exit(128)
 
-        self.clientPath = p4Where(self.depotPath)
+        self.useClientSpec = False
+        if gitConfig("git-p4.useclientspec", "--bool") == "true":
+            self.useClientSpec = True
+        if self.useClientSpec:
+            self.clientSpecDirs = getClientSpec()
+
+        if self.useClientSpec:
+            # all files are relative to the client spec
+            self.clientPath = getClientRoot()
+        else:
+            self.clientPath = p4Where(self.depotPath)
 
-        if len(self.clientPath) == 0:
-            print "Error: Cannot locate perforce checkout of %s in client view" % self.depotPath
-            sys.exit(128)
+        if self.clientPath == "":
+            die("Error: Cannot locate perforce checkout of %s in client view" % self.depotPath)
 
         print "Perforce checkout for depot path %s located at %s" % (self.depotPath, self.clientPath)
         self.oldWorkingDirectory = os.getcwd()
