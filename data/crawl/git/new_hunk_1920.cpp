					 unsigned long cutoff)
{
	while (complete && cutoff <= complete->item->date) {
		print_verbose(args, "Marking %s as complete",
			      oid_to_hex(&complete->item->object.oid));
		pop_most_recent_commit(&complete, COMPLETE);
	}
}
