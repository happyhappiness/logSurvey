		}

		fprintf (use_stdio == 1 ? stdout : stderr,
			 "PUTVAL %s interval=%i %s\n",
			 filename, vl->interval, values);
		return (0);
	}

