     }
 }
 
-# Start off a git rev-list process and arrange to read its output
+# Start off a git log process and arrange to read its output
 proc start_rev_list {view} {
     global startmsecs
     global commfd leftover tclencoding datemode
