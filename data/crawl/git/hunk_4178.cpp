         return path.lower().startswith(prefix.lower())
     return path.startswith(prefix)
 
+def getClientSpec():
+    """Look at the p4 client spec, create a View() object that contains
+       all the mappings, and return it."""
+
+    specList = p4CmdList("client -o")
+    if len(specList) != 1:
+        die('Output from "client -o" is %d lines, expecting 1' %
+            len(specList))
+
+    # dictionary of all client parameters
+    entry = specList[0]
+
+    # just the keys that start with "View"
+    view_keys = [ k for k in entry.keys() if k.startswith("View") ]
+
+    # hold this new View
+    view = View()
+
+    # append the lines, in order, to the view
+    for view_num in range(len(view_keys)):
+        k = "View%d" % view_num
+        if k not in view_keys:
+            die("Expected view key %s missing" % k)
+        view.append(entry[k])
+
+    return view
+
+def getClientRoot():
+    """Grab the client directory."""
+
+    output = p4CmdList("client -o")
+    if len(output) != 1:
+        die('Output from "client -o" is %d lines, expecting 1' % len(output))
+
+    entry = output[0]
+    if "Root" not in entry:
+        die('Client has no "Root"')
+
+    return entry["Root"]
+
 class Command:
     def __init__(self):
         self.usage = "usage: %prog [options]"
