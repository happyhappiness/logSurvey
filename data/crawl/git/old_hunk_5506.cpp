
int launch_editor(const char *path, struct strbuf *buffer, const char *const *env)
{
	const char *editor, *terminal;

	editor = getenv("GIT_EDITOR");
	if (!editor && editor_program)
		editor = editor_program;
	if (!editor)
		editor = getenv("VISUAL");
	if (!editor)
		editor = getenv("EDITOR");

	terminal = getenv("TERM");
	if (!editor && (!terminal || !strcmp(terminal, "dumb")))
		return error("Terminal is dumb but no VISUAL nor EDITOR defined.");

	if (!editor)
		editor = "vi";
