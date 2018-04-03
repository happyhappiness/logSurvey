				  "\tPlease update the configuration manually if necessary."),
				buf2.buf);

		git_config_set_multivar_or_die(buf.buf, buf2.buf, "^$", 0);
	}

	read_branches();
