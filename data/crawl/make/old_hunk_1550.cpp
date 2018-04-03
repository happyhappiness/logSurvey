#define	access_inited	(user_uid != -1)
static enum { make, user } current_access;

static void
init_access ()
{
