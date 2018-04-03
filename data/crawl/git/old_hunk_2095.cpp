			*read_good = "good";
			return;
		} else {
			die("could not read file '%s': %s", filename,
				strerror(errno));
		}
	} else {
		strbuf_getline_lf(&str, fp);