		if (defined($format_patch)) {
			return $format_patch;
		}
		die sprintf(__ <<EOF, $f, $f);
File '%s' exists but it could also be the range of commits
to produce patches for.  Please disambiguate by...

    * Saying "./%s" if you mean a file; or
    * Giving --format-patch option if you mean a range.
EOF
	} catch Git::Error::Command with {
