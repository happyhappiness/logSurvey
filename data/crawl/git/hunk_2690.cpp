         self.p4HasMoveCommand = p4_has_move_command()
         self.branch = None
 
+        if gitConfig('git-p4.largeFileSystem'):
+            die("Large file system not supported for git-p4 submit command. Please remove it from config.")
+
     def check(self):
         if len(p4CmdList("opened ...")) > 0:
             die("You have files opened with perforce! Close them before starting the sync.")
