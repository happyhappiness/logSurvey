		 * If this is the head, and it's not okay to update
		 * the head, and the old value of the head isn't empty...
		 */
		sprintf(display, "! %-*s %s -> %s  (can't  fetch in current branch)",
			SUMMARY_WIDTH, "[rejected]", remote, pretty_ref);
		return 1;
	}

	if (!is_null_sha1(ref->old_sha1) &&
	    !prefixcmp(ref->name, "refs/tags/")) {
		sprintf(display, "- %-*s %s -> %s",
			SUMMARY_WIDTH, "[tag update]", remote, pretty_ref);
		return s_update_ref("updating tag", ref, 0);
	}

	current = lookup_commit_reference_gently(ref->old_sha1, 1);
	updated = lookup_commit_reference_gently(ref->new_sha1, 1);
	if (!current || !updated) {
		const char *msg;
		const char *what;
		if (!strncmp(ref->name, "refs/tags/", 10)) {
			msg = "storing tag";
			what = "[new tag]";
		}
		else {
			msg = "storing head";
			what = "[new branch]";
		}

		sprintf(display, "* %-*s %s -> %s",
			SUMMARY_WIDTH, what, remote, pretty_ref);
		return s_update_ref(msg, ref, 0);
	}

	if (in_merge_bases(current, &updated, 1)) {
		char quickref[83];
		strcpy(quickref, find_unique_abbrev(current->object.sha1, DEFAULT_ABBREV));
		strcat(quickref, "..");
		strcat(quickref, find_unique_abbrev(ref->new_sha1, DEFAULT_ABBREV));
		sprintf(display, "  %-*s %s -> %s  (fast forward)",
			SUMMARY_WIDTH, quickref, remote, pretty_ref);
		return s_update_ref("fast forward", ref, 1);
	} else if (force || ref->force) {
		char quickref[84];
		strcpy(quickref, find_unique_abbrev(current->object.sha1, DEFAULT_ABBREV));
		strcat(quickref, "...");
		strcat(quickref, find_unique_abbrev(ref->new_sha1, DEFAULT_ABBREV));
		sprintf(display, "+ %-*s %s -> %s  (forced update)",
			SUMMARY_WIDTH, quickref, remote, pretty_ref);
		return s_update_ref("forced-update", ref, 1);
	} else {
		sprintf(display, "! %-*s %s -> %s  (non fast forward)",
			SUMMARY_WIDTH, "[rejected]", remote, pretty_ref);
		return 1;
	}
}

static void store_updated_refs(const char *url, struct ref *ref_map)
{
	FILE *fp;
	struct commit *commit;
	int url_len, i, note_len, shown_url = 0;
	char note[1024];
	const char *what, *kind;
	struct ref *rm;
