
#ifndef NO_PTHREADS
	if (list.nr || cached || show_in_pager)
		use_threads = 0;
#else
	use_threads = 0;
#endif

#ifndef NO_PTHREADS
	if (use_threads) {
		if (!(opt.name_only || opt.unmatch_name_only || opt.count)
		    && (opt.pre_context || opt.post_context ||
			opt.file_break || opt.funcbody))
