	run_rewrite_hook(&old_head->object.oid, new_head);
}

static const char implicit_ident_advice_noconfig[] =
N_("Your name and email address were configured automatically based\n"
"on your username and hostname. Please check that they are accurate.\n"
