	return (0);
}

void
submit_counter(const char *type, const char *inst, counter_t val, int usegauge)
{
#ifndef TEST
	value_t		values[1];
	value_list_t	vl = VALUE_LIST_INIT;

	if (usegauge)
		values[0].gauge = val;
	else
		values[0].counter = val;

	vl.values = values;
	vl.values_len = 1;
	sstrncpy (vl.host, hostname_g, sizeof (vl.host));
	sstrncpy (vl.plugin, "pf", sizeof (vl.plugin));
	sstrncpy (vl.type, type, sizeof(vl.type));
	sstrncpy (vl.type_instance, inst, sizeof(vl.type_instance));
	plugin_dispatch_values(&vl);
#else
	printf("%s.%s: %lld\n", type, inst, val);
#endif
}

#ifdef TEST
int
main(int argc, char *argv[])
{
	if (pf_init())
		err(1, "pf_init");
	if (pf_read())
		err(1, "pf_read");
	return (0);
}
#else
void module_register(void) {
	plugin_register_init("pf", pf_init);
	plugin_register_read("pf", pf_read);
}
#endif