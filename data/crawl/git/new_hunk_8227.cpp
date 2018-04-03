	if (revs.parents) {
		struct commit_list *parents = commit->parents;
		while (parents) {
			printf(" %s", sha1_to_hex(parents->item->object.sha1));
			parents = parents->next;
		}
	}
	if (revs.commit_format == CMIT_FMT_ONELINE)
		putchar(' ');