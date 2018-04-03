$wiki_name =~ s/^.*@//;

# Commands parser
while (<STDIN>) {
	chomp;

	if (!parse_command($_)) {
		last;
	}

