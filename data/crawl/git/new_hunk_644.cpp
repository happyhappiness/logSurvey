#ifndef GIT_WINDOWS_NATIVE
static int child_notifier = -1;

enum child_errcode {
	CHILD_ERR_CHDIR,
	CHILD_ERR_ENOENT,
	CHILD_ERR_SILENT,
	CHILD_ERR_ERRNO
};

struct child_err {
	enum child_errcode err;
	int syserr; /* errno */
};

static void child_die(enum child_errcode err)
{
	struct child_err buf;

	buf.err = err;
	buf.syserr = errno;

	/* write(2) on buf smaller than PIPE_BUF (min 512) is atomic: */
	xwrite(child_notifier, &buf, sizeof(buf));
	_exit(1);
}

/*
 * parent will make it look like the child spewed a fatal error and died
 * this is needed to prevent changes to t0061.
 */
static void fake_fatal(const char *err, va_list params)
{
	vreportf("fatal: ", err, params);
}

static void child_error_fn(const char *err, va_list params)
{
	const char msg[] = "error() should not be called in child\n";
	xwrite(2, msg, sizeof(msg) - 1);
}

static void child_warn_fn(const char *err, va_list params)
{
	const char msg[] = "warn() should not be called in child\n";
	xwrite(2, msg, sizeof(msg) - 1);
}

static void NORETURN child_die_fn(const char *err, va_list params)
{
	const char msg[] = "die() should not be called in child\n";
	xwrite(2, msg, sizeof(msg) - 1);
	_exit(2);
}

/* this runs in the parent process */
static void child_err_spew(struct child_process *cmd, struct child_err *cerr)
{
	static void (*old_errfn)(const char *err, va_list params);

	old_errfn = get_error_routine();
	set_error_routine(fake_fatal);
	errno = cerr->syserr;

	switch (cerr->err) {
	case CHILD_ERR_CHDIR:
		error_errno("exec '%s': cd to '%s' failed",
			    cmd->argv[0], cmd->dir);
		break;
	case CHILD_ERR_ENOENT:
		error_errno("cannot run %s", cmd->argv[0]);
		break;
	case CHILD_ERR_SILENT:
		break;
	case CHILD_ERR_ERRNO:
		error_errno("cannot exec '%s'", cmd->argv[0]);
		break;
	}
	set_error_routine(old_errfn);
}

static void prepare_cmd(struct argv_array *out, const struct child_process *cmd)
