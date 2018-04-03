		else
			*flags &= ~TRANSPORT_PUSH_FOLLOW_TAGS;
		return 0;
	}

	return git_default_config(k, v, NULL);
