}


static void
tar_help (struct argp_state *state)
{
  argp_fmtstream_t fs;
  state->flags |= ARGP_NO_EXIT;
  argp_state_help (state, state->out_stream,
		   ARGP_HELP_STD_HELP & ~ARGP_HELP_BUG_ADDR);
  /* FIXME: use struct uparams.rmargin (from argp-help.c) instead of 79 */
  fs = argp_make_fmtstream (state->out_stream, 0, 79, 0);

  argp_fmtstream_printf (fs, "\n%s\n\n",
		       _("Valid arguments for --quoting-style options are:"));
  tar_list_quoting_styles (fs, "  ");

  argp_fmtstream_puts (fs, _("\n*This* tar defaults to:\n"));
  show_default_settings_fs (fs);
  argp_fmtstream_putc (fs, '\n');
  argp_fmtstream_printf (fs, _("Report bugs to %s.\n"),
			 argp_program_bug_address);
  argp_fmtstream_free (fs);
}

static error_t
