			buf[equal] = tolower(buf[equal]);
		buf[equal] = '\0';

		if (equal == len)
			die("Missing '=': '%s'", buf);

