	return 0;
}

struct ref_to_prune {
	struct ref_to_prune *next;
	unsigned char sha1[20];
