 */
static int
parse_asntype(fp, name, ntype, ntoken)
    FILE *fp;
    char *name;
    int *ntype;
    char *ntoken;
{
    int type, i;
    char token[MAXTOKEN];
    struct enum_list *ep = 0;
    struct tc *tcp;
    int level;
    
    type = get_token(fp, token);
    if (type == SEQUENCE){
	while((type = get_token(fp, token)) != ENDOFFILE){
	    if (type == RIGHTBRACKET){
		*ntype = get_token(fp, ntoken);
		return 1;
	    }
	}
	print_error("Expected \"}\"", token, type);
	return 0;
    } else {
	if (!strcmp(token, "TEXTUAL-CONVENTION")){
	    while (type != SYNTAX)
		type = get_token(fp, token);
	    type = get_token(fp, token);
	}
	/* textual convention */
	for(i = 0; i < MAXTC; i++){
	    if (tclist[i].type == 0)
		break;
	}
	if (i == MAXTC){
	    print_error("No more textual conventions possible.", token, type);
	    return 0;
	}
	tcp = &tclist[i];
	strcpy(tcp->descriptor, name);
	if (!(type & SYNTAX_MASK)){
	    print_error("Textual convention doesn't map to real type.", token,
			type);
	    return 0;
	}
	tcp->type = type;
	*ntype = get_token(fp, ntoken);
	if (*ntype == LEFTPAREN){
	    level = 1;
	    /* don't record any constraints for now */
	    while(level > 0){
		*ntype = get_token(fp, ntoken);
		if (*ntype == LEFTPAREN)
		    level++;
		if (*ntype == RIGHTPAREN)
		    level--;		
	    }
	    *ntype = get_token(fp, ntoken);
	} else if (*ntype == LEFTBRACKET) {
	    /* if there is an enumeration list, parse it */
	    while((type = get_token(fp, token)) != ENDOFFILE){
		if (type == RIGHTBRACKET)
		    break;
		if (type == LABEL){
		    /* this is an enumerated label */
		    if (tcp->enums == 0){
			ep = tcp->enums = (struct enum_list *)
			    Malloc(sizeof(struct enum_list));
		    } else {
