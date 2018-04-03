		if (len == 0)
			break;
		if (len < 1) {
			fprintf(stderr, "%s: protocol error: no band designator\n", me);
			return SIDEBAND_PROTOCOL_ERROR;
		}
		band = buf[pf] & 0xff;
		len--;
		switch (band) {
		case 3:
			buf[pf] = ' ';
			buf[pf+1+len] = '\0';
			fprintf(stderr, "%s\n", buf);
			return SIDEBAND_REMOTE_ERROR;
		case 2:
			buf[pf] = ' ';
