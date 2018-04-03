	memset(&signature_check, 0, sizeof(signature_check));

	ret = check_commit_signature(lookup_commit(sha1), &signature_check);
	print_signature_buffer(&signature_check, verbose ? GPG_VERIFY_VERBOSE : 0);

	signature_check_clear(&signature_check);
	return ret;
