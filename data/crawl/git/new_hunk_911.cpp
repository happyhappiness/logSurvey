sub say_n_paths {
	my $did = shift @_;
	my $cnt = scalar @_;
	if ($did eq 'added') {
		printf(__n("added %d path\n", "added %d paths\n",
			   $cnt), $cnt);
	} elsif ($did eq 'updated') {
		printf(__n("updated %d path\n", "updated %d paths\n",
			   $cnt), $cnt);
	} elsif ($did eq 'reverted') {
		printf(__n("reverted %d path\n", "reverted %d paths\n",
			   $cnt), $cnt);
	} else {
		printf(__n("touched %d path\n", "touched %d paths\n",
			   $cnt), $cnt);
	}
}

