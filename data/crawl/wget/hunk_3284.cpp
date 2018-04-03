 	fi
       fi
 
-      # Create an invalid libtool object if no PIC, so that we do not
-      # accidentally link it into a program.
-      if test "$build_libtool_libs" != yes; then
-	$show "echo timestamp > $libobj"
-	$run eval "echo timestamp > \$libobj" || exit $?
-      else
-	# Move the .lo from within objdir
-	$show "$mv $libobj $lo_libobj"
-	if $run $mv $libobj $lo_libobj; then :
-	else
-	  error=$?
-	  $run $rm $removelist
-	  exit $error
-	fi
-      fi
+      # Append the name of the non-PIC object the libtool object file.
+      # Only append if the libtool object file exists.
+      test -z "$run" && cat >> ${libobj}T <<EOF
+# Name of the non-PIC object.
+non_pic_object='$objname'
+
+EOF
+    else
+      # Append the name of the non-PIC object the libtool object file.
+      # Only append if the libtool object file exists.
+      test -z "$run" && cat >> ${libobj}T <<EOF
+# Name of the non-PIC object.
+non_pic_object=none
+
+EOF
     fi
 
+    $run $mv "${libobj}T" "${libobj}"
+
     # Unlock the critical section if it was locked
     if test "$need_locks" != no; then
       $run $rm "$lockfile"
