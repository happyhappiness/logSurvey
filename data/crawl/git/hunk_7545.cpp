         return self.rebase()
 
     def rebase(self):
+        if os.system("git update-index --refresh") != 0:
+            die("Some files in your working directory are modified and different than what is in your index. You can use git update-index <filename> to bring the index up-to-date or stash away all your changes with git stash.");
+        if len(read_pipe("git diff-index HEAD --")) > 0:
+            die("You have uncommited changes. Please commit them before rebasing or stash them away with git stash.");
+
         [upstream, settings] = findUpstreamBranchPoint()
         if len(upstream) == 0:
             die("Cannot find upstream branchpoint for rebase")