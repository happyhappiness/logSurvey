static const char PACKED_REFS_HEADER[] =
	"# pack-refs with: peeled fully-peeled \n";

static int packed_init_db(struct ref_store *ref_store, struct strbuf *err)
{
	/* Nothing to do. */
