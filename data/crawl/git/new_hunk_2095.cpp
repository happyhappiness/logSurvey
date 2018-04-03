			*read_good = "good";
			return;
		} else {
			die_errno("could not read file '%s'", filename);
		}
	} else {
		strbuf_getline_lf(&str, fp);