	commit->object.flags &= ~(ADDED | SEEN | SHOWN);
}

void show_reflog_message(struct reflog_walk_info *info, int oneline,
	enum date_mode dmode)
{
	if (info && info->last_commit_reflog) {
		struct commit_reflog *commit_reflog = info->last_commit_reflog;
		struct reflog_info *info;

		info = &commit_reflog->reflogs->items[commit_reflog->recno+1];
		if (oneline) {
			printf("%s@{", commit_reflog->reflogs->ref);
			if (commit_reflog->flag || dmode)
				printf("%s", show_date(info->timestamp,
						       info->tz,
						       dmode));
			else
				printf("%d", commit_reflog->reflogs->nr
				       - 2 - commit_reflog->recno);
			printf("}: %s", info->message);
		}
		else {
			printf("Reflog: %s@{", commit_reflog->reflogs->ref);
			if (commit_reflog->flag || dmode)
				printf("%s", show_date(info->timestamp,
							info->tz,
							dmode));
			else
				printf("%d", commit_reflog->reflogs->nr
				       - 2 - commit_reflog->recno);
			printf("} (%s)\nReflog message: %s",
			       info->email, info->message);
		}
	}
}
