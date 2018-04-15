	my $vl   = shift;

	if (scalar (@$ds) != scalar (@{$vl->{'values'}})) {
		Collectd::plugin_log (Collectd::LOG_WARNING,
			"DS number does not match values length");
		return;
	}