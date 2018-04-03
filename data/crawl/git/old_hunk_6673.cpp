		struct emit_callback ecbdata;
		const struct userdiff_funcname *pe;

		pe = diff_funcname_pattern(one);
		if (!pe)
			pe = diff_funcname_pattern(two);
