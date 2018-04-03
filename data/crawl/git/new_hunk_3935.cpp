	else
		packet_write(1, "%s %s\n", sha1_to_hex(sha1), refname_nons);
	capabilities = NULL;
	if (!peel_ref(refname, peeled))
		packet_write(1, "%s %s^{}\n", sha1_to_hex(peeled), refname_nons);
	return 0;
}

static void upload_pack(void)
{
	if (advertise_refs || !stateless_rpc) {