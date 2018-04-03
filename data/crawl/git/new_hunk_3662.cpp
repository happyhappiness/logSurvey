extern int is_in_cmdlist(struct cmdnames *cmds, const char *name);
extern void list_commands(unsigned int colopts, struct cmdnames *main_cmds, struct cmdnames *other_cmds);

/*
 * call this to die(), when it is suspected that the user mistyped a
 * ref to the command, to give suggested "correct" refs.
 */
extern void help_unknown_ref(const char *ref, const char *cmd, const char *error);
#endif /* HELP_H */