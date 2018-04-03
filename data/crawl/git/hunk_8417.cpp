 def currentGitBranch():
     return os.popen("git-name-rev HEAD").read().split(" ")[1][:-1]
 
+def isValidGitDir(path):
+    if os.path.exists(path + "/HEAD") and os.path.exists(path + "/refs") and os.path.exists(path + "/objects"):
+        return True;
+    return False
+
+def system(cmd):
+    if os.system(cmd) != 0:
+        die("command failed: %s" % cmd)
+
 class P4Debug:
     def __init__(self):
         self.options = [
