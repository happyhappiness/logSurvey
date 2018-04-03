int transport_set_option(struct transport *transport,
			 const char *name, const char *value)
{
	int ret = 1;
	if (transport->ops->set_option)
		ret = transport->ops->set_option(transport, name, value);
	if (ret < 0)
		fprintf(stderr, "For '%s' option %s cannot be set to '%s'\n",
			transport->url, name, value);
	if (ret > 0)
		fprintf(stderr, "For '%s' option %s is ignored\n",
			transport->url, name);
	return ret;
}

int transport_push(struct transport *transport,