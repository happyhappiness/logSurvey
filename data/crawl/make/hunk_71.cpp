   open (STDERR, '>&', pop @ERRSTACK) or error("ddo: $! duping STDERR\n", 1);
 }
 
+sub _run_with_timeout
+{
+    my $code;
+    if ($^O eq 'VMS') {
+        #local $SIG{ALRM} = sub {
+        #    my $e = $ERRSTACK[0];
+        #    print $e "\nTest timed out after $test_timeout seconds\n";
+        #    die "timeout\n";
+        #};
+        #alarm $test_timeout;
+        system(@_);
+        #alarm 0;
+        my $severity = ${^CHILD_ERROR_NATIVE} & 7;
+        $code = 0;
+        if (($severity & 1) == 0) {
+            $code = 512;
+        }
+
+        # Get the vms status.
+        my $vms_code = ${^CHILD_ERROR_NATIVE};
+
+        # Remove the print status bit
+        $vms_code &= ~0x10000000;
+
+        # Posix code translation.
+        if (($vms_code & 0xFFFFF000) == 0x35a000) {
+            $code = (($vms_code & 0xFFF) >> 3) * 256;
+        }
+
+    } elsif ($port_type eq 'W32') {
+        my $pid = system(1, @_);
+        $pid > 0 or die "Cannot execute $_[0]\n";
+        local $SIG{ALRM} = sub {
+            my $e = $ERRSTACK[0];
+            print $e "\nTest timed out after $test_timeout seconds\n";
+            kill -9, $pid;
+            die "timeout\n";
+        };
+        alarm $test_timeout;
+        my $r = waitpid($pid, 0);
+        alarm 0;
+        $r == -1 and die "No such pid: $pid\n";
+        # This shouldn't happen since we wait forever or timeout via SIGALRM
+        $r == 0 and die "No process exited.\n";
+        $code = $?;
+
+    } else {
+        my $pid = fork();
+        if (! $pid) {
+            exec(@_) or die "exec: Cannot execute $_[0]\n";
+        }
+        local $SIG{ALRM} = sub {
+            my $e = $ERRSTACK[0];
+            print $e "\nTest timed out after $test_timeout seconds\n";
+            # Resend the alarm to our process group to kill the children.
+            $SIG{ALRM} = 'IGNORE';
+            kill -14, $$;
+            die "timeout\n";
+        };
+        alarm $test_timeout;
+        my $r = waitpid($pid, 0);
+        alarm 0;
+        $r == -1 and die "No such pid: $pid\n";
+        # This shouldn't happen since we wait forever or timeout via SIGALRM
+        $r == 0 and die "No process exited.\n";
+        $code = $?;
+    }
+
+    return $code;
+}
+
 # This runs a command without any debugging info.
 sub _run_command
 {
-  my $code;
-
   # We reset this before every invocation.  On Windows I think there is only
   # one environment, not one per process, so I think that variables set in
   # test scripts might leak into subsequent tests if this isn't reset--???
   resetENV();
 
-  eval {
-      if ($^O eq 'VMS') {
-          local $SIG{ALRM} = sub {
-              my $e = $ERRSTACK[0];
-              print $e "\nTest timed out after $test_timeout seconds\n";
-              die "timeout\n"; };
-#          alarm $test_timeout;
-          system(@_);
-          my $severity = ${^CHILD_ERROR_NATIVE} & 7;
-          $code = 0;
-          if (($severity & 1) == 0) {
-              $code = 512;
-          }
-
-          # Get the vms status.
-          my $vms_code = ${^CHILD_ERROR_NATIVE};
-
-          # Remove the print status bit
-          $vms_code &= ~0x10000000;
+  my $orig = $SIG{ALRM};
+  my $code = eval { _run_with_timeout(@_); };
+  $SIG{ALRM} = $orig;
 
-          # Posix code translation.
-          if (($vms_code & 0xFFFFF000) == 0x35a000) {
-              $code = (($vms_code & 0xFFF) >> 3) * 256;
-          }
-      } else {
-          my $pid = fork();
-          if (! $pid) {
-              exec(@_) or die "Cannot execute $_[0]\n";
-          }
-          local $SIG{ALRM} = sub { my $e = $ERRSTACK[0]; print $e "\nTest timed out after $test_timeout seconds\n"; die "timeout\n"; };
-          alarm $test_timeout;
-          waitpid($pid, 0) > 0 or die "No such pid: $pid\n";
-          $code = $?;
-      }
-      alarm 0;
-  };
   if ($@) {
       # The eval failed.  If it wasn't SIGALRM then die.
       $@ eq "timeout\n" or die "Command failed: $@";
-
-      # Timed out.  Resend the alarm to our process group to kill the children.
-      $SIG{ALRM} = 'IGNORE';
-      kill -14, $$;
       $code = 14;
   }
 
