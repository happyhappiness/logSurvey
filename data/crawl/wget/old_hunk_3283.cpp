	fi
      fi

      # If we have no pic_flag, then copy the object into place and finish.
      if (test -z "$pic_flag" || test "$pic_mode" != default) &&
	 test "$build_old_libs" = yes; then
	# Rename the .lo from within objdir to obj
	if test -f $obj; then
	  $show $rm $obj
	  $run $rm $obj
	fi

	$show "$mv $libobj $obj"
	if $run $mv $libobj $obj; then :
	else
	  error=$?
	  $run $rm $removelist
	  exit $error
	fi

	xdir=`$echo "X$obj" | $Xsed -e 's%/[^/]*$%%'`
	if test "X$xdir" = "X$obj"; then
	  xdir="."
	else
	  xdir="$xdir"
	fi
	baseobj=`$echo "X$obj" | $Xsed -e "s%.*/%%"`
	libobj=`$echo "X$baseobj" | $Xsed -e "$o2lo"`
	# Now arrange that obj and lo_libobj become the same file
	$show "(cd $xdir && $LN_S $baseobj $libobj)"
	if $run eval '(cd $xdir && $LN_S $baseobj $libobj)'; then
	  # Unlock the critical section if it was locked
	  if test "$need_locks" != no; then
	    $run $rm "$lockfile"
	  fi
	  exit 0
	else
	  error=$?
	  $run $rm $removelist
	  exit $error
	fi
      fi

      # Allow error messages only from the first compilation.
      suppress_output=' >/dev/null 2>&1'
    fi

    # Only build a position-dependent object if we build old libraries.
