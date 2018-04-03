static int *object_ix;
static int object_ix_hashsz;

/*
 * stats
 */
static uint32_t written, written_delta;
static uint32_t reused, reused_delta;


static void *delta_against(void *buf, unsigned long size, struct object_entry *entry)
{
