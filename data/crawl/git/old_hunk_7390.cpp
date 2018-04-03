	}
}

/*
 * The entries in a tree are ordered in the _path_ order,
 * which means that a directory entry is ordered by adding
 * a slash to the end of it.
 *
 * So a directory called "a" is ordered _after_ a file
 * called "a.c", because "a/" sorts after "a.c".
 */
#define TREE_UNORDERED (-1)
#define TREE_HAS_DUPS  (-2)

static int verify_ordered(unsigned mode1, const char *name1, unsigned mode2, const char *name2)
{
	int len1 = strlen(name1);
	int len2 = strlen(name2);
	int len = len1 < len2 ? len1 : len2;
	unsigned char c1, c2;
	int cmp;

	cmp = memcmp(name1, name2, len);
	if (cmp < 0)
		return 0;
	if (cmp > 0)
		return TREE_UNORDERED;

	/*
	 * Ok, the first <len> characters are the same.
	 * Now we need to order the next one, but turn
	 * a '\0' into a '/' for a directory entry.
	 */
	c1 = name1[len];
	c2 = name2[len];
	if (!c1 && !c2)
		/*
		 * git-write-tree used to write out a nonsense tree that has
		 * entries with the same name, one blob and one tree.  Make
		 * sure we do not have duplicate entries.
		 */
		return TREE_HAS_DUPS;
	if (!c1 && S_ISDIR(mode1))
		c1 = '/';
	if (!c2 && S_ISDIR(mode2))
		c2 = '/';
	return c1 < c2 ? 0 : TREE_UNORDERED;
}

static int fsck_tree(struct tree *item)
{
	int retval;
	int has_full_path = 0;
	int has_empty_name = 0;
	int has_zero_pad = 0;
	int has_bad_modes = 0;
	int has_dup_entries = 0;
	int not_properly_sorted = 0;
	struct tree_desc desc;
	unsigned o_mode;
	const char *o_name;
	const unsigned char *o_sha1;

	if (verbose)
		fprintf(stderr, "Checking tree %s\n",
				sha1_to_hex(item->object.sha1));

	init_tree_desc(&desc, item->buffer, item->size);

	o_mode = 0;
	o_name = NULL;
	o_sha1 = NULL;
	while (desc.size) {
		unsigned mode;
		const char *name;
		const unsigned char *sha1;

		sha1 = tree_entry_extract(&desc, &name, &mode);

		if (strchr(name, '/'))
			has_full_path = 1;
		if (!*name)
			has_empty_name = 1;
		has_zero_pad |= *(char *)desc.buffer == '0';
		update_tree_entry(&desc);

		switch (mode) {
		/*
		 * Standard modes..
		 */
		case S_IFREG | 0755:
		case S_IFREG | 0644:
		case S_IFLNK:
		case S_IFDIR:
		case S_IFGITLINK:
			break;
		/*
		 * This is nonstandard, but we had a few of these
		 * early on when we honored the full set of mode
		 * bits..
		 */
		case S_IFREG | 0664:
			if (!check_strict)
				break;
		default:
			has_bad_modes = 1;
		}

		if (o_name) {
			switch (verify_ordered(o_mode, o_name, mode, name)) {
			case TREE_UNORDERED:
				not_properly_sorted = 1;
				break;
			case TREE_HAS_DUPS:
				has_dup_entries = 1;
				break;
			default:
				break;
			}
		}

		o_mode = mode;
		o_name = name;
		o_sha1 = sha1;
	}
	free(item->buffer);
	item->buffer = NULL;

	retval = 0;
	if (has_full_path) {
		objwarning(&item->object, "contains full pathnames");
	}
	if (has_empty_name) {
		objwarning(&item->object, "contains empty pathname");
	}
	if (has_zero_pad) {
		objwarning(&item->object, "contains zero-padded file modes");
	}
	if (has_bad_modes) {
		objwarning(&item->object, "contains bad file modes");
	}
	if (has_dup_entries) {
		retval = objerror(&item->object, "contains duplicate file entries");
	}
	if (not_properly_sorted) {
		retval = objerror(&item->object, "not properly sorted");
	}
	return retval;
}

static int fsck_commit(struct commit *commit)
{
	char *buffer = commit->buffer;
	unsigned char tree_sha1[20], sha1[20];
	struct commit_graft *graft;
	int parents = 0;

	if (verbose)
		fprintf(stderr, "Checking commit %s\n",
			sha1_to_hex(commit->object.sha1));

	if (memcmp(buffer, "tree ", 5))
		return objerror(&commit->object, "invalid format - expected 'tree' line");
	if (get_sha1_hex(buffer+5, tree_sha1) || buffer[45] != '\n')
		return objerror(&commit->object, "invalid 'tree' line format - bad sha1");
	buffer += 46;
	while (!memcmp(buffer, "parent ", 7)) {
		if (get_sha1_hex(buffer+7, sha1) || buffer[47] != '\n')
			return objerror(&commit->object, "invalid 'parent' line format - bad sha1");
		buffer += 48;
		parents++;
	}
	graft = lookup_commit_graft(commit->object.sha1);
	if (graft) {
		struct commit_list *p = commit->parents;
		parents = 0;
		while (p) {
			p = p->next;
			parents++;
		}
		if (graft->nr_parent == -1 && !parents)
			; /* shallow commit */
		else if (graft->nr_parent != parents)
			return objerror(&commit->object, "graft objects missing");
	} else {
		struct commit_list *p = commit->parents;
		while (p && parents) {
			p = p->next;
			parents--;
		}
		if (p || parents)
			return objerror(&commit->object, "parent objects missing");
	}
	if (memcmp(buffer, "author ", 7))
		return objerror(&commit->object, "invalid format - expected 'author' line");
	free(commit->buffer);
	commit->buffer = NULL;
	if (!commit->tree)
		return objerror(&commit->object, "could not load commit's tree %s", tree_sha1);
	if (!commit->parents && show_root)
		printf("root %s\n", sha1_to_hex(commit->object.sha1));
	if (!commit->date)
		printf("bad commit date in %s\n",
		       sha1_to_hex(commit->object.sha1));
	return 0;
}

static int fsck_tag(struct tag *tag)
{
	struct object *tagged = tag->tagged;

	if (verbose)
		fprintf(stderr, "Checking tag %s\n",
			sha1_to_hex(tag->object.sha1));

	if (!tagged) {
		return objerror(&tag->object, "could not load tagged object");
	}
	if (!show_tags)
		return 0;

	printf("tagged %s %s", typename(tagged->type), sha1_to_hex(tagged->sha1));
	printf(" (%s) in %s\n", tag->tag, sha1_to_hex(tag->object.sha1));
	return 0;
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
	if (fsck_walk(obj, mark_used, 0))
		objerror(obj, "broken links");
	if (obj->type == OBJ_BLOB)
		return 0;
	if (obj->type == OBJ_TREE)
		return fsck_tree((struct tree *) obj);
	if (obj->type == OBJ_COMMIT)
		return fsck_commit((struct commit *) obj);
	if (obj->type == OBJ_TAG)
		return fsck_tag((struct tag *) obj);

	/* By now, parse_object() would've returned NULL instead. */
	return objerror(obj, "unknown type '%d' (internal fsck error)",
			obj->type);
}

/*
 * This is the sorting chunk size: make it reasonably
 * big so that we can sort well..
