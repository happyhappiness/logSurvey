		if (!c || !(c->object.flags & SEEN)) {
			if (data->flags & VERBOSE)
				printf("Removing %s from .git/shallow\n",
				       sha1_to_hex(c->object.sha1));
			return 0;
		}
	}
