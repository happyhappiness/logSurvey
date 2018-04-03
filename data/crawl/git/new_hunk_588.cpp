		}

		if (lmode && status != 'C') {
			if (checkout_path(lmode, &loid, src_path, &lstate)) {
				ret = error("could not write '%s'", src_path);
				goto finish;
			}
		}

		if (rmode && !S_ISLNK(rmode)) {
