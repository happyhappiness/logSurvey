
($sender) = expand_aliases($sender) if defined $sender;

# Now that all the defaults are set, process the rest of the command line
# arguments and collect up the files that need to be processed.
for my $f (@ARGV) {
	if (-d $f) {
		opendir(DH,$f)
			or die "Failed to opendir $f: $!";

		push @files, grep { -f $_ } map { +$f . "/" . $_ }
				sort readdir(DH);
		closedir(DH);
	} elsif (-f $f or -p $f) {
		push @files, $f;
	} else {
		print STDERR "Skipping $f - not found.\n";
	}
}

if ($validate) {
	foreach my $f (@files) {
		unless (-p $f) {
