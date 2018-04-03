			remote->uploadpack = xstrdup(value);
		else
			error("more than one uploadpack given, using the first");
	}
	return 0;
}
