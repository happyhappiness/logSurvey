	if (!fd) {
		if (!GetConsoleMode(hcon, &mode))
			return 0;
	} else if (!GetConsoleScreenBufferInfo(hcon, &sbi))
		return 0;
