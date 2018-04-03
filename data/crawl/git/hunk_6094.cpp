 	case GREP_OPEN_PAREN:
 		*list = p->next;
 		x = compile_pattern_or(list);
-		if (!x)
-			return NULL;
 		if (!*list || (*list)->token != GREP_CLOSE_PAREN)
 			die("unmatched parenthesis");
 		*list = (*list)->next;
