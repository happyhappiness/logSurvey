		o->flags |= OUR_REF;
		nr_our_refs++;
	}
	if (!peel_ref(refname, peeled))
		packet_write(1, "%s %s^{}\n", sha1_to_hex(peeled), refname_nons);
	return 0;
}
