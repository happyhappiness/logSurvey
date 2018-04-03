 
 
         self.gitStream.close()
+        if importProcess.wait() != 0:
+            die("fast-import failed: %s" % self.gitError.read())
         self.gitOutput.close()
         self.gitError.close()
-        importProcess.wait()
 
         return True
 