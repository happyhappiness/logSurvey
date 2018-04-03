	}
	if (o->type == OBJ_TAG) {
		o = deref_tag(o, refname, 0);
		packet_write(1, "%s %s^{}\n", sha1_to_hex(o->sha1), refname);
	}
	return 0;
}