
/*
 * Context-based Debugging
 */

#if 0

    /*
     * Rationale
     * ---------
     * 
     * When you have a long nested processing sequence, it is often impossible
     * for low level routines to know in what larger context they operate. If a
     * routine coredumps, one can restore the context using debugger trace.
     * However, in many case you do not want to coredump, but just want to report
     * a potential problem. A report maybe useless out of problem context.
     * 
     * To solve this potential problem, use the following approach:
     */

int
top_level_foo(const char *url)
{
    /* define current context */
    Ctx ctx = ctx_enter(url);	/* note: we stack but do not dup ctx descriptions! */
    ...
    /* go down; middle_level_bar will eventually call bottom_level_boo */
	middle_level_bar(method, protocol);
    ...
    /* exit, clean after yourself */
	ctx_exit(ctx);
}

void
bottom_level_boo(int status, void *data)
{
    /*
     * detect exceptional condition, and simply report it, the context
     * information will be available somewhere close in the log file
     */
    if (status == STRANGE_STATUS)
	debug(13, 6) ("DOS attack detected, data: %p\n", data);
    ...
}

    /*
     * Current implementation is extremely simple but still very handy. It has a
     * negligible overhead (descriptions are not duplicated).
     * 
     * When the _first_ debug message for a given context is printed, it is
     * prepended with the current context description. Context is printed with
     * the same debugging level as the original message.
     * 
     * Note that we do not print context every type you do ctx_enter(). This
     * approach would produce too many useless messages.  For the same reason, a
     * context description is printed at most _once_ even if you have 10
     * debugging messages within one context.
     * 
     * Contexts can be nested, of course. You must use ctx_enter() to enter a
     * context (push it onto stack).  It is probably safe to exit several nested
     * contexts at _once_ by calling ctx_exit() at the top level (this will pop
     * all context till current one). However, as in any stack, you cannot start
     * in the middle.
     * 
     * Analysis: 
     * i)   locate debugging message,
     * ii)  locate current context by going _upstream_ in your log file,
     * iii) hack away.
     */

#endif /* rationale */

/*
 * To-Do: 
 *       decide if we want to dup() descriptions (adds overhead) but allows to
 *       add printf()-style interface
 */

/*
 * implementation:
 *
 * descriptions for contexts over CTX_MAX_LEVEL limit are ignored, you probably
 * have a bug if your nesting goes that deep.
