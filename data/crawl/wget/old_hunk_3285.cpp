	# win32 will think the script is a binary if it has
	# a .exe suffix, so we strip it off here.
	case $output in
	  *.exe) output=`echo $output|${SED} 's,.exe$,,'` ;;
	esac
	# test for cygwin because mv fails w/o .exe extensions
	case $host in
	  *cygwin*) exeext=.exe ;;
	  *) exeext= ;;
	esac
	$rm $output
	trap "$rm $output; exit 1" 1 2 15

