		} else
			output_fd = open(pack_name, O_CREAT|O_EXCL|O_RDWR, 0600);
		if (output_fd < 0)
			die("unable to create %s: %s\n", pack_name, strerror(errno));
		pack_fd = output_fd;
	} else {
		input_fd = open(pack_name, O_RDONLY);
