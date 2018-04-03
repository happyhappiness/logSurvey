	print_commit_list(tried, "%s\n", "%s\n");
	if (bad)
		printf("%s\n", oid_to_hex(bad));
	printf(_("We cannot bisect more!\n"));
	exit(2);
}

