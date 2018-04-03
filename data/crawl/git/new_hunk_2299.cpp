#include "sha1-array.h"
#include "sigchain.h"

static void set_upstreams(struct transport *transport, struct ref *refs,
	int pretend)
{
