static struct used_atom {
	const char *name;
	cmp_type type;
} *used_atom;
static int used_atom_cnt, need_tagged, need_symref;
static int need_color_reset_at_eol;

static struct {
	const char *name;
	cmp_type cmp_type;
