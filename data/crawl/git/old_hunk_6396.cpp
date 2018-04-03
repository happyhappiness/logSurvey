int transport_push(struct transport *transport,
		   int refspec_nr, const char **refspec, int flags)
{
	if (!transport->push)
		return 1;
	return transport->push(transport, refspec_nr, refspec, flags);
}

const struct ref *transport_get_remote_refs(struct transport *transport)
{
	if (!transport->remote_refs)
		transport->remote_refs = transport->get_refs_list(transport);
	return transport->remote_refs;
}

