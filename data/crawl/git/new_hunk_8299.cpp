	if (!commit->parents && show_root)
		printf("root %s\n", sha1_to_hex(commit->object.sha1));
	if (!commit->date)
		printf("bad commit date in %s\n",
		       sha1_to_hex(commit->object.sha1));
	return 0;
}
