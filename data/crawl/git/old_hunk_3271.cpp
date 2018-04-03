		return 0;
	}
	if (args->atomic && !atomic_supported)
		die(_("server does not support --atomic push"));

	use_atomic = atomic_supported && args->atomic;
