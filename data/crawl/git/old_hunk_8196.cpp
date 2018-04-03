		case "$(peek_next_command)" in
		squash)
			EDIT_COMMIT=
			cp "$MSG" "$SQUASH_MSG"
		;;
		*)
			EDIT_COMMIT=-e
			test -f "$SQUASH_MSG" && rm "$SQUASH_MSG"
		esac

