 		case "$(peek_next_command)" in
 		squash)
 			EDIT_COMMIT=
+			USE_OUTPUT=output
 			cp "$MSG" "$SQUASH_MSG"
 		;;
 		*)
 			EDIT_COMMIT=-e
+			USE_OUTPUT=
 			test -f "$SQUASH_MSG" && rm "$SQUASH_MSG"
 		esac
 
