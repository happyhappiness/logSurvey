
#ifdef TEST
print_subtree(tree, count)
    struct snmp_mib_tree *tree;
    int count;
{
    struct snmp_mib_tree *tp;
    int i;

    for(i = 0; i < count; i++)
	printf("  ");
    printf("Children of %s:\n", tree->label);
    count++;
    for(tp = tree->child_list; tp; tp = tp->next_peer){
	for(i = 0; i < count; i++)
	    printf("  ");
	printf("%s\n", tp->label);
    }
    for(tp = tree->child_list; tp; tp = tp->next_peer){
	print_subtree(tp, count);
    }
}
#endif /* TEST */

int translation_table[40];

static void build_translation_table(){
    int count;

    for(count = 0; count < 40; count++){
	switch(count){
	    case OBJID:
		translation_table[count] = TYPE_OBJID;
		break;
	    case OCTETSTR:
		translation_table[count] = TYPE_OCTETSTR;
		break;
	    case INTEGER:
		translation_table[count] = TYPE_INTEGER;
		break;
	    case NETADDR:
		translation_table[count] = TYPE_IPADDR;
		break;
	    case IPADDR:
		translation_table[count] = TYPE_IPADDR;
		break;
	    case COUNTER:
		translation_table[count] = TYPE_COUNTER;
		break;
	    case GAUGE:
		translation_table[count] = TYPE_GAUGE;
		break;
	    case TIMETICKS:
		translation_table[count] = TYPE_TIMETICKS;
		break;
	    case OPAQUE:
		translation_table[count] = TYPE_OPAQUE;
		break;
	    case NUL:
		translation_table[count] = TYPE_NULL;
		break;
	    default:
		translation_table[count] = TYPE_OTHER;
		break;
	}
    }
}
