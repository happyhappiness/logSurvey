		       remote_msg, base,
		       num_ours, (num_ours == 1) ? "" : "s");
	else if (!num_ours)
		printf("Your branch is behind the tracked%s branch '%s' "
		       "by %d commit%s,\n"
		       "and can be fast-forwarded.\n",
		       remote_msg, base,
