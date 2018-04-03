int transport_set_option(struct transport *transport,
			 const char *name, const char *value)
{
	if (transport->ops->set_option)
		return transport->ops->set_option(transport, name, value);
	return 1;
}

int transport_push(struct transport *transport,