			die("'%s' is not a commit", argv[1]);
		if (hashcmp(second_token->object.sha1, head))
			return NULL;
	}
	return second_token;
}
