	rm -f gitweb.log &&
	perl -- "$SCRIPT_NAME" \
		>gitweb.output 2>gitweb.log &&
	if grep '^[[]' gitweb.log >/dev/null 2>&1; then false; else true; fi

	# gitweb.log is left for debugging
	# gitweb.output is used to parse http output
}

. ./test-lib.sh