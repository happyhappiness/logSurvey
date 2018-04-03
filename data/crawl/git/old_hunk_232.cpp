 */
#define PATHSPEC_LITERAL_PATH (1<<6)

extern void parse_pathspec(struct pathspec *pathspec,
			   unsigned magic_mask,
			   unsigned flags,