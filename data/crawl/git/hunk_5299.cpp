 #include "builtin.h"
 #include "utf8.h"
 
-/*
- * FIXME! Share the code with "write-tree.c"
- */
-static void check_valid(unsigned char *sha1, enum object_type expect)
-{
-	enum object_type type = sha1_object_info(sha1, NULL);
-	if (type < 0)
-		die("%s is not a valid object", sha1_to_hex(sha1));
-	if (type != expect)
-		die("%s is not a valid '%s' object", sha1_to_hex(sha1),
-		    typename(expect));
-}
-
 static const char commit_tree_usage[] = "git commit-tree <sha1> [-p <sha1>]* < changelog";
 
 static void new_parent(struct commit *parent, struct commit_list **parents_p)
