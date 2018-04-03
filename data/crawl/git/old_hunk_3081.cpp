struct date_mode *date_mode_from_type(enum date_mode_type type)
{
	static struct date_mode mode;
	mode.type = type;
	return &mode;
}
