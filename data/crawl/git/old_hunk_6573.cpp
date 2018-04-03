
	if (!prefixcmp(name, "refs/tags/"))
		name += 10;
	printf("tag %s\nfrom :%d\n%.*s\ndata %d\n%.*s\n",
	       name, get_object_mark(tag->tagged),
	       (int)(tagger_end - tagger), tagger,
	       (int)message_size, (int)message_size, message ? message : "");
}

