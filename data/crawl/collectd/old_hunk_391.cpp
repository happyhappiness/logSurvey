	my $vl   = shift;

	if (scalar (@$ds) != scalar (@{$vl->{'values'}})) {
		plugin_log (LOG_WARNING,
			"DS number does not match values length");
		return;
	}

