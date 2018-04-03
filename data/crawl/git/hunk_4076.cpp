                 if i < last:
                     quit = False
                     while True:
-                        print "What do you want to do?"
-                        response = raw_input("[s]kip this commit but apply"
-                                             " the rest, or [q]uit? ")
-                        if not response:
-                            continue
+                        # prompt for what to do, or use the option/variable
+                        if self.conflict_behavior == "ask":
+                            print "What do you want to do?"
+                            response = raw_input("[s]kip this commit but apply"
+                                                 " the rest, or [q]uit? ")
+                            if not response:
+                                continue
+                        elif self.conflict_behavior == "skip":
+                            response = "s"
+                        elif self.conflict_behavior == "quit":
+                            response = "q"
+                        else:
+                            die("Unknown conflict_behavior '%s'" %
+                                self.conflict_behavior)
+
                         if response[0] == "s":
                             print "Skipping this commit, but applying the rest"
                             break
