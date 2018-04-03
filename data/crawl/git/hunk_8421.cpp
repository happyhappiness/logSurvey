         result.update(entry)
     return result;
 
+def die(msg):
+    sys.stderr.write(msg + "\n")
+    sys.exit(1)
+
 try:
     opts, args = getopt.getopt(sys.argv[1:], "", [ "continue", "git-dir=", "origin=", "reset", "master=",
                                                    "submit-log-subst=", "log-substitutions=", "interactive",
