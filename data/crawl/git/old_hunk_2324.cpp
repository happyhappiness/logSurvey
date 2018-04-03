			strcpy(buffer, data[i].from);
			to = func(buffer);
		}
		if (strcmp(to, data[i].to)) {
			error("FAIL: %s(%s) => '%s' != '%s'\n",
				funcname, data[i].from, to, data[i].to);
			failed = 1;
		}
	}
	return failed;
}
