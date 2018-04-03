		const unsigned char *sha1;
		struct object *o;

		if (!p->pack_local || p->pack_keep)
			continue;
		if (open_pack_index(p))
			die("cannot open pack index");
