				(int)(ci.name_end - ci.name_begin), ci.name_begin,
				(int)(ci.mail_end - ci.mail_begin), ci.mail_begin);

		if (ident_shown)
			status_printf_ln(s, GIT_COLOR_NORMAL, "%s", "");

		saved_color_setting = s->use_color;
		s->use_color = 0;
