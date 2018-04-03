 		return 0;
 	} else if (show_info->any_rebase) {
 		printf_ln(_(" merges with remote %s"), merge->items[0].string);
-		also = _("    and with remote");
+		width++;
 	} else {
 		printf_ln(_("merges with remote %s"), merge->items[0].string);
-		also = _("   and with remote");
 	}
 	for (i = 1; i < merge->nr; i++)
-		printf("    %-*s %s %s\n", show_info->width, "", also,
+		printf(_("%-*s    and with remote %s\n"), width, "",
 		       merge->items[i].string);
 
 	return 0;