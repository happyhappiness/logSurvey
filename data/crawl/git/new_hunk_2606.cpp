		return;
	}

	o = parse_object(ref->old_oid.hash);
	if (!o) {
		fprintf(stderr,
			"Unable to parse object %s for remote ref %s\n",
			oid_to_hex(&ref->old_oid), ls->dentry_name);
		aborted = 1;
		free(ref);
		return;
	}

	strbuf_addf(buf, "%s\t%s\n",
		    oid_to_hex(&ref->old_oid), ls->dentry_name);

	if (o->type == OBJ_TAG) {
		o = deref_tag(o, ls->dentry_name, 0);
