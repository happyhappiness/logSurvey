
($sender) = expand_aliases($sender) if defined $sender;

# returns 1 if the conflict must be solved using it as a format-patch argument
sub check_file_rev_conflict($) {
	my $f = shift;
	try {
		$repo->command('rev-parse', '--verify', '--quiet', $f);
		if (defined($format_patch)) {
			print "foo\n";
			return $format_patch;
		}
		die(<<EOF);
File '$f' exists but it could also be the range of commits
to produce patches for.  Please disambiguate by...

    * Saying "./$f" if you mean a file; or
    * Giving --format-patch option if you mean a range.
EOF
	} catch Git::Error::Command with {
		return 0;
	}
}

# Now that all the defaults are set, process the rest of the command line
# arguments and collect up the files that need to be processed.
my @rev_list_opts;
while (my $f = pop @ARGV) {
	if ($f eq "--") {
		push @rev_list_opts, "--", @ARGV;
		@ARGV = ();
	} elsif (-d $f and !check_file_rev_conflict($f)) {
		opendir(DH,$f)
			or die "Failed to opendir $f: $!";

		push @files, grep { -f $_ } map { +$f . "/" . $_ }
				sort readdir(DH);
		closedir(DH);
	} elsif ((-f $f or -p $f) and !check_file_rev_conflict($f)) {
		push @files, $f;
	} else {
		push @rev_list_opts, $f;
	}
}

if (@rev_list_opts) {
	push @files, $repo->command('format-patch', '-o', tempdir(CLEANUP => 1), @rev_list_opts);
}

if ($validate) {
	foreach my $f (@files) {
		unless (-p $f) {
