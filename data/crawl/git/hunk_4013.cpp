 def p4_move(src, dest):
     p4_system(["move", "-k", wildcard_encode(src), wildcard_encode(dest)])
 
+def p4_describe(change):
+    """Make sure it returns a valid result by checking for
+       the presence of field "time".  Return a dict of the
+       results."""
+
+    ds = p4CmdList(["describe", "-s", str(change)])
+    if len(ds) != 1:
+        die("p4 describe -s %d did not return 1 result: %s" % (change, str(ds)))
+
+    d = ds[0]
+
+    if "p4ExitCode" in d:
+        die("p4 describe -s %d exited with %d: %s" % (change, d["p4ExitCode"],
+                                                      str(d)))
+    if "code" in d:
+        if d["code"] == "error":
+            die("p4 describe -s %d returned error code: %s" % (change, str(d)))
+
+    if "time" not in d:
+        die("p4 describe -s %d returned no \"time\": %s" % (change, str(d)))
+
+    return d
+
 #
 # Canonicalize the p4 type and return a tuple of the
 # base type, plus any modifiers.  See "p4 help filetypes"
