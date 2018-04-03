     global verbose
     verbose = cmd.verbose
     if cmd.needsGit:
-        gitdir = cmd.gitdir
-        if len(gitdir) == 0:
-            gitdir = ".git"
-            if not isValidGitDir(gitdir):
-                gitdir = read_pipe("git rev-parse --git-dir").strip()
-                if os.path.exists(gitdir):
+        if cmd.gitdir == None:
+            cmd.gitdir = os.path.abspath(".git")
+            if not isValidGitDir(cmd.gitdir):
+                cmd.gitdir = read_pipe("git rev-parse --git-dir").strip()
+                if os.path.exists(cmd.gitdir):
                     cdup = read_pipe("git rev-parse --show-cdup").strip()
                     if len(cdup) > 0:
                         os.chdir(cdup);
 
-        if not isValidGitDir(gitdir):
-            if isValidGitDir(gitdir + "/.git"):
-                gitdir += "/.git"
+        if not isValidGitDir(cmd.gitdir):
+            if isValidGitDir(cmd.gitdir + "/.git"):
+                cmd.gitdir += "/.git"
             else:
-                die("fatal: cannot locate git repository at %s" % gitdir)
+                die("fatal: cannot locate git repository at %s" % cmd.gitdir)
 
-        os.environ["GIT_DIR"] = gitdir
+        os.environ["GIT_DIR"] = cmd.gitdir
 
     if not cmd.run(args):
         parser.print_help()