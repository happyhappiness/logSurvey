
		f = fopen(file, "r");
		if (!f) {
			error("cannot open mail %s (%s)", file, strerror(errno));
			goto out;
		}

		if (strbuf_getwholeline(&buf, f, '\n')) {
			error("cannot read mail %s (%s)", file, strerror(errno));
			goto out;
		}

