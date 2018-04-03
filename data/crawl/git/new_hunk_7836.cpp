					old_hex, new_hex, ref->name);
		}
		if (will_delete_ref)
			fprintf(stderr, " - %-*s %s\n",
				SUMMARY_WIDTH, "[deleting]",
				pretty_ref);
		else if (is_null_sha1(ref->old_sha1)) {
			const char *msg;

			if (!prefixcmp(ref->name, "refs/tags/"))
				msg = "[new tag]";
			else
				msg = "[new branch]";
			fprintf(stderr, " * %-*s %s -> %s\n",
				SUMMARY_WIDTH, msg,
				pretty_peer, pretty_ref);
		}
		else {
			char quickref[83];
			char type = ' ';
			const char *msg = "";

			strcpy(quickref, find_unique_abbrev(ref->old_sha1, DEFAULT_ABBREV));
			if (ref_newer(ref->peer_ref->new_sha1, ref->old_sha1))
				strcat(quickref, "..");
			else {
				strcat(quickref, "...");
				type = '+';
				msg = " (forced update)";
			}
			strcat(quickref, find_unique_abbrev(ref->new_sha1, DEFAULT_ABBREV));

			fprintf(stderr, " %c %-*s %s -> %s%s\n",
				type,
				SUMMARY_WIDTH, quickref,
				pretty_peer, pretty_ref,
				msg);
		}
	}

