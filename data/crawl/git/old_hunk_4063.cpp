	if (!deref_tags)
		return 0;

	if ((flag & REF_ISPACKED) && !peel_ref(refname, peeled)) {
		if (!is_null_sha1(peeled)) {
			hex = find_unique_abbrev(peeled, abbrev);
			printf("%s %s^{}\n", hex, refname);
		}
	}
	else {
		obj = parse_object(sha1);
		if (!obj)
			die("git show-ref: bad ref %s (%s)", refname,
			    sha1_to_hex(sha1));
		if (obj->type == OBJ_TAG) {
			obj = deref_tag(obj, refname, 0);
			if (!obj)
				die("git show-ref: bad tag at ref %s (%s)", refname,
				    sha1_to_hex(sha1));
			hex = find_unique_abbrev(obj->sha1, abbrev);
			printf("%s %s^{}\n", hex, refname);
		}
	}
	return 0;
}
