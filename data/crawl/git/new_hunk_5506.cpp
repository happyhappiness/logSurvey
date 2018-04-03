
int launch_editor(const char *path, struct strbuf *buffer, const char *const *env)
{
	const char *editor = getenv("GIT_EDITOR");
	const char *terminal = getenv("TERM");
	int terminal_is_dumb = !terminal || !strcmp(terminal, "dumb");

	if (!editor && editor_program)
		editor = editor_program;
	if (!editor && !terminal_is_dumb)
		editor = getenv("VISUAL");
	if (!editor)
		editor = getenv("EDITOR");

	if (!editor && terminal_is_dumb)
		return error("terminal is dumb, but EDITOR unset");

	if (!editor)
		editor = "vi";
