     */
    type = get_token(fp, token);
    while (type != EQUALS) {
      switch (type) {
        case DESCRIPTION:
          type = get_token(fp, token);
          if (type != QUOTESTRING) {
              print_error("Bad DESCRIPTION", token, type);
              free_node(np);
              return 0;
          }
#ifdef TEST
printf("Description== \"%.50s\"\n", quoted_string_buffer);
#endif
	  np->description = quoted_string_buffer;
	  quoted_string_buffer = (char *)calloc(1, MAXQUOTESTR);
          break;

	case REFERENCE:
	  type = get_token(fp, token);
	  if (type != QUOTESTRING) {
	      print_error("Bad DESCRIPTION", token, type);
	      free_node(np);
	      return 0;
	  }
	  break;
        case INDEX:
        case DEFVAL:
	case AUGMENTS:
	case NUM_ENTRIES:
          if (tossObjectIdentifier(fp) != OBJID) {
              print_error("Bad Object Identifier", token, type);
              free_node(np);
              return 0;
          }
          break;

        default:
          print_error("Bad format of optional clauses", token,type);
          free_node(np);
          return 0;

      }
      type = get_token(fp, token);
    }
    if (type != EQUALS){
	print_error("Bad format", token, type);
	free_node(np);
	return 0;
    }
    length = getoid(fp, oid, 32);
    if (length > 1 && length <= 32){
	/* just take the last pair in the oid list */
	if (oid[length - 2].label)
	    strncpy(np->parent, oid[length - 2].label, MAXLABEL);
