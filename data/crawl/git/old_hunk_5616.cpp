			len += c - 'A' + 10;
			continue;
		}
		die("protocol error: bad line length character");
	}
	if (!len)
		return 0;
	len -= 4;
