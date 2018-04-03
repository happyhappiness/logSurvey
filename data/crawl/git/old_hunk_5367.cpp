	 */
	if (opt->count && count) {
		char buf[32];
		opt->output(opt, name, strlen(name));
		snprintf(buf, sizeof(buf), "%c%u\n",
			 opt->null_following_name ? '\0' : ':', count);
		opt->output(opt, buf, strlen(buf));
	}
	return !!last_hit;
