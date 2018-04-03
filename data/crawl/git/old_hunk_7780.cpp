				packet_write(out, "%s %s %s",
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
			const char *old_abb;
			old_abb = find_unique_abbrev(ref->old_sha1, DEFAULT_ABBREV);
			strcpy(quickref, old_abb ? old_abb : old_hex);
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

	packet_flush(out);
	if (new_refs && !args.dry_run)
		ret = pack_objects(out, remote_refs);
	close(out);

	if (expect_status_report) {
		if (receive_status(in))
			ret = -4;
	}

	if (!args.dry_run && remote && ret == 0) {
		for (ref = remote_refs; ref; ref = ref->next)
			if (!is_null_sha1(ref->new_sha1))
				update_tracking_ref(remote, ref);
	}

	if (!new_refs && ret == 0)
		fprintf(stderr, "Everything up-to-date\n");
	return ret;
}

static void verify_remote_names(int nr_heads, const char **heads)
