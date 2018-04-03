
sub validate_patch {
	my $fn = shift;
	open(my $fh, '<', $fn)
		or die sprintf(__("unable to open %s: %s\n"), $fn, $!);
	while (my $line = <$fh>) {
