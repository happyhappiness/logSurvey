		 *     always allowed.
		 */

		ref->nonfastforward =
		    !ref->deletion &&
		    !is_null_sha1(ref->old_sha1) &&
		    (!has_sha1_file(ref->old_sha1)
		      || !ref_newer(new_sha1, ref->old_sha1));

		if (ref->nonfastforward && !ref->force && !args.force_update) {
			ref->status = REF_STATUS_REJECT_NONFASTFORWARD;
			continue;
		}

		hashcpy(ref->new_sha1, new_sha1);
		if (!ref->deletion)
			new_refs++;
		ref->status = REF_STATUS_OK;

		if (!args.dry_run) {
			char *old_hex = sha1_to_hex(ref->old_sha1);
			char *new_hex = sha1_to_hex(ref->new_sha1);

			if (ask_for_status_report) {
				packet_write(out, "%s %s %s%c%s",
					old_hex, new_hex, ref->name, 0,
