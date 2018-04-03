} sub_process;

/* keep track of children so we can implement a waitpid-like routine */
static sub_process *proc_array[MAXIMUM_WAIT_OBJECTS];
static int proc_index = 0;
static int fake_exits_pending = 0;


/*
 * Fill a HANDLE list with handles to wait for.
