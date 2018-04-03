 output () {
 	case "$VERBOSE" in
 	'')
-		"$@" > "$DOTEST"/output 2>&1
+		output=$("$@" 2>&1 )
 		status=$?
-		test $status != 0 &&
-			cat "$DOTEST"/output
+		test $status != 0 && printf "%s\n" "$output"
 		return $status
 		;;
 	*)
