         return 1;
 }
 
-# This function is called when plugin_log () has been used.
-sub monitorus_log
-{
-        my $level = shift;
-        my $msg   = shift;
-
-        print "LOG: $level - $msg\n";
-        return 1;
-} # monitorus_log ()
-
 1;