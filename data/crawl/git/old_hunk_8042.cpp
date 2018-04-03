			remote->receivepack = xstrdup(value);
		else
			error("more than one receivepack given, using the first");
	}
	return 0;
}
