			}
	}

	if (!prefixcmp(name, "refs/tags/"))
		name += 10;
	printf("tag %s\nfrom :%d\n%.*s%sdata %d\n%.*s\n",
	       name, get_object_mark(tag->tagged),
	       (int)(tagger_end - tagger), tagger,
	       tagger == tagger_end ? "" : "\n",
	       (int)message_size, (int)message_size, message ? message : "");
