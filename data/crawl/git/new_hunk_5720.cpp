	return unless defined $glob_spec;
	my $ref = $glob_spec->{ref};
	my $path = $glob_spec->{path};
	foreach (command(qw#for-each-ref --format=%(refname) refs/#)) {
		next unless m#^$ref->{regex}$#;
		my $p = $1;
		my $pathname = desanitize_refname($path->full_path($p));
		my $refname = desanitize_refname($ref->full_path($p));
		if (my $existing = $fetch->{$pathname}) {
			if ($existing ne $refname) {
				die "Refspec conflict:\n",
				    "existing: $existing\n",
				    " globbed: $refname\n";
			}
			my $u = (::cmt_metadata("$refname"))[0];
			$u =~ s!^\Q$url\E(/|$)!! or die
			  "$refname: '$url' not found in '$u'\n";
			if ($pathname ne $u) {
				warn "W: Refspec glob conflict ",
				     "(ref: $refname):\n",
				     "expected path: $pathname\n",
				     "    real path: $u\n",
				     "Continuing ahead with $u\n";
