		char *private;
		unsigned char sha1[20];

		if (ref->deletion)
			die("remote-helpers do not support ref deletion");

		private = apply_refspecs(data->refspecs, data->refspec_nr, ref->name);
		if (private && !get_sha1(private, sha1)) {
			strbuf_addf(&buf, "^%s", private);
