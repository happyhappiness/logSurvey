	}
}

static int fsck_sha1(const unsigned char *sha1)
{
	struct object *obj = parse_object(sha1);
	if (!obj) {
		errors_found |= ERROR_OBJECT;
		return error("%s: object corrupt or missing",
			     sha1_to_hex(sha1));
	}
	if (obj->flags & SEEN)
		return 0;
	obj->flags |= SEEN;

	if (verbose)
		fprintf(stderr, "Checking %s %s\n",
			typename(obj->type), sha1_to_hex(obj->sha1));

	if (fsck_walk(obj, mark_used, 0))
		objerror(obj, "broken links");
	if (fsck_object(obj, check_strict, fsck_error_func))
		return -1;

	if (obj->type == OBJ_TREE) {
		struct tree *item = (struct tree *) obj;

		free(item->buffer);
		item->buffer = NULL;
	}

	if (obj->type == OBJ_COMMIT) {
		struct commit *commit = (struct commit *) obj;

		free(commit->buffer);
		commit->buffer = NULL;

		if (!commit->parents && show_root)
			printf("root %s\n", sha1_to_hex(commit->object.sha1));
	}

	if (obj->type == OBJ_TAG) {
		struct tag *tag = (struct tag *) obj;

		if (show_tags && tag->tagged) {
			printf("tagged %s %s", typename(tag->tagged->type), sha1_to_hex(tag->tagged->sha1));
			printf(" (%s) in %s\n", tag->tag, sha1_to_hex(tag->object.sha1));
		}
	}

	return 0;
}

/*
 * This is the sorting chunk size: make it reasonably
 * big so that we can sort well..
