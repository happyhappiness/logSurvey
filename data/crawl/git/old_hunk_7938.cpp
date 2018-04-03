		strcpy(old_hex, sha1_to_hex(ref->old_sha1));
		new_hex = sha1_to_hex(ref->new_sha1);

		if (ask_for_status_report) {
			packet_write(out, "%s %s %s%c%s",
				     old_hex, new_hex, ref->name, 0,
				     "report-status");
			ask_for_status_report = 0;
			expect_status_report = 1;
		}
		else
			packet_write(out, "%s %s %s",
				     old_hex, new_hex, ref->name);
		if (will_delete_ref)
			fprintf(stderr, "deleting '%s'\n", ref->name);
		else {
