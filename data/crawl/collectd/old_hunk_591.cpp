
static void cpu_init (void)
{
#ifdef HAVE_LIBKSTAT
	kstat_t *ksp_chain;

	numcpu = 0;
