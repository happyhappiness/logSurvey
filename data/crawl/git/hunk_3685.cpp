     ref = parser[1]
     parser.next()
 
-    if ref != 'refs/heads/master':
-        die("bzr doesn't support multiple branches; use 'master'")
+    if ref.startswith('refs/heads/'):
+        name = ref[len('refs/heads/'):]
+        branch = branches[name]
+    else:
+        die('unknown ref')
 
     commit_mark = parser.get_mark()
     parser.next()
