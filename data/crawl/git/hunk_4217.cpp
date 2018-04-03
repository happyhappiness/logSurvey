         revision = ""
         self.users = {}
 
+        # Make sure no revision specifiers are used when --changesfile
+        # is specified.
+        bad_changesfile = False
+        if len(self.changesFile) > 0:
+            for p in self.depotPaths:
+                if p.find("@") >= 0 or p.find("#") >= 0:
+                    bad_changesfile = True
+                    break
+        if bad_changesfile:
+            die("Option --changesfile is incompatible with revision specifiers")
+
         newPaths = []
         for p in self.depotPaths:
             if p.find("@") != -1:
