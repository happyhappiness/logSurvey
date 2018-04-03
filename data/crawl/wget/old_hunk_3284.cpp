	fi
      fi

      # Create an invalid libtool object if no PIC, so that we do not
      # accidentally link it into a program.
      if test "$build_libtool_libs" != yes; then
	$show "echo timestamp > $libobj"
	$run eval "echo timestamp > \$libobj" || exit $?
      else
	# Move the .lo from within objdir
	$show "$mv $libobj $lo_libobj"
	if $run $mv $libobj $lo_libobj; then :
	else
	  error=$?
	  $run $rm $removelist
	  exit $error
	fi
      fi
    fi

    # Unlock the critical section if it was locked
    if test "$need_locks" != no; then
      $run $rm "$lockfile"
