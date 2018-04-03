    static time_t last_when = 0;
    static struct tm tm;
    time_t t;

    if (when != last_when) {
	last_when = when;
	xmemcpy(&tm, localtime(&when), sizeof(struct tm));
