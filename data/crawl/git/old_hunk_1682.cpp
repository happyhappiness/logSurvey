		fprintf(stderr, "Checking reflog %s->%s\n",
			sha1_to_hex(osha1), sha1_to_hex(nsha1));

	fsck_handle_reflog_sha1(refname, osha1);
	fsck_handle_reflog_sha1(refname, nsha1);
	return 0;
}

