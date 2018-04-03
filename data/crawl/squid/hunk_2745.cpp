 /// prepares and initiates entry loading sequence
 void
 Rock::Rebuild::start() {
+    // in SMP mode, only the disker is responsible for populating the map
+    if (UsingSmp() && !IamDiskProcess()) {
+        debugs(47, 2, "Non-disker skips rebuilding of cache_dir #" <<
+           sd->index << " from " << sd->filePath);
+        mustStop("non-disker");
+        return;
+    }
+
     debugs(47, DBG_IMPORTANT, "Loading cache_dir #" << sd->index <<
            " from " << sd->filePath);
 
