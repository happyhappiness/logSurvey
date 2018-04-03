 else:
     os.environ["GIT_DIR"] = gitdir
 
+if not tryGitDir(gitdir):
+    if tryGitDir(gitdir + "/.git"):
+        gitdir += "/.git"
+        os.environ["GIT_DIR"] = gitdir
+    else:
+        die("fatal: %s seems not to be a git repository." % gitdir)
+
+
 configFile = gitdir + "/p4-git-sync.cfg"
 
 origin = "origin"