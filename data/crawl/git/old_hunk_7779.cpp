		 *     always allowed.
		 */

		if (!args.force_update &&
		    !will_delete_ref &&
		    !is_null_sha1(ref->old_sha1) &&
		    !ref->force) {
			if (!has_sha1_file(ref->old_sha1) ||
			    !ref_newer(new_sha1, ref->old_sha1)) {
				/* We do not have the remote ref, or
				 * we know that the remote ref is not
				 * an ancestor of what we are trying to
				 * push.  Either way this can be losing
				 * commits at the remote end and likely
				 * we were not up to date to begin with.
				 */
				fprintf(stderr, " ! %-*s %s -> %s (non-fast forward)\n",
						SUMMARY_WIDTH, "[rejected]",
						pretty_peer, pretty_ref);
				ret = -2;
				continue;
			}
		}
		hashcpy(ref->new_sha1, new_sha1);
		if (!will_delete_ref)
			new_refs++;
		strcpy(old_hex, sha1_to_hex(ref->old_sha1));
		new_hex = sha1_to_hex(ref->new_sha1);

		if (!args.dry_run) {
			if (ask_for_status_report) {
				packet_write(out, "%s %s %s%c%s",
					old_hex, new_hex, ref->name, 0,
