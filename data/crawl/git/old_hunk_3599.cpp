		data = patch_delta(base, base_size,
				   delta_data, delta_size,
				   &size);
		if (!data)
			die("failed to apply delta");

		free(delta_data);
	}
