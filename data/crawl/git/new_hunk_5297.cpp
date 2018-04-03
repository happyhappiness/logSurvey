			strbuf_reset(&header);
		}

		mf1.size = fill_textconv(textconv_one, one, &mf1.ptr);
		mf2.size = fill_textconv(textconv_two, two, &mf2.ptr);

		pe = diff_funcname_pattern(one);
		if (!pe)
