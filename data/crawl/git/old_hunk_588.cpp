		}

		if (lmode && status != 'C') {
			if (checkout_path(lmode, &loid, src_path, &lstate))
				return error("could not write '%s'", src_path);
		}

		if (rmode && !S_ISLNK(rmode)) {
