 
     if hg.islocal(url):
         repo = hg.repository(myui, url)
+        if not os.path.exists(dirname):
+            os.makedirs(dirname)
     else:
-        local_path = os.path.join(dirname, 'clone')
-        if not os.path.exists(local_path):
+        shared_path = os.path.join(gitdir, 'hg')
+        if not os.path.exists(shared_path):
             try:
-                peer, dstpeer = hg.clone(myui, {}, url, local_path, update=True, pull=True)
+                hg.clone(myui, {}, url, shared_path, update=False, pull=True)
             except:
                 die('Repository error')
-            repo = dstpeer.local()
-        else:
-            repo = hg.repository(myui, local_path)
-            try:
-                peer = hg.peer(myui, {}, url)
-            except:
-                die('Repository error')
-            repo.pull(peer, heads=None, force=True)
+
+        if not os.path.exists(dirname):
+            os.makedirs(dirname)
+
+        local_path = os.path.join(dirname, 'clone')
+        if not os.path.exists(local_path):
+            hg.share(myui, shared_path, local_path, update=False)
+
+        repo = hg.repository(myui, local_path)
+        try:
+            peer = hg.peer(myui, {}, url)
+        except:
+            die('Repository error')
+        repo.pull(peer, heads=None, force=True)
 
     return repo
 
