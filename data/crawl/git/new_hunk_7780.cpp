				packet_write(out, "%s %s %s",
					old_hex, new_hex, ref->name);
		}
	}

	packet_flush(out);
	if (new_refs && !args.dry_run) {
		if (pack_objects(out, remote_refs) < 0) {
			close(out);
			return -1;
		}
	}
	close(out);

	print_push_status(dest, remote_refs);

	if (expect_status_report) {
		if (receive_status(in))
			return -1;
	}

	if (!args.dry_run && remote) {
		for (ref = remote_refs; ref; ref = ref->next)
			if (!is_null_sha1(ref->new_sha1))
				update_tracking_ref(remote, ref);
	}

	if (!new_refs)
		fprintf(stderr, "Everything up-to-date\n");
	for (ref = remote_refs; ref; ref = ref->next) {
		switch (ref->status) {
		case REF_STATUS_NONE:
		case REF_STATUS_UPTODATE:
		case REF_STATUS_OK:
			break;
		default:
			return -1;
		}
	}
	return 0;
}

static void verify_remote_names(int nr_heads, const char **heads)
