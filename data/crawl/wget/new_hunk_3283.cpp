	fi
      fi

      # Append the name of the PIC object to the libtool object file.
      test -z "$run" && cat >> ${libobj}T <<EOF
pic_object='$objdir/$objname'

EOF

      # Allow error messages only from the first compilation.
      suppress_output=' >/dev/null 2>&1'
    else
      # No PIC object so indicate it doesn't exist in the libtool
      # object file.
      test -z "$run" && cat >> ${libobj}T <<EOF
pic_object=none

EOF
    fi

    # Only build a position-dependent object if we build old libraries.
