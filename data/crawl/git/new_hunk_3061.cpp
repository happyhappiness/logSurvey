		free(head_ref);
	}

	if (!new->commit && opts->new_branch) {
		unsigned char rev[20];
		int flag;
