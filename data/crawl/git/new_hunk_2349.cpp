
struct pack_revindex *revindex_for_pack(struct packed_git *p)
{
	struct pack_revindex *rix = &p->reverse_index;
	if (!rix->revindex) {
		rix->p = p;
		create_pack_revindex(rix);
	}
	return rix;
}
