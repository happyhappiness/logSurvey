		int branch_existed = 0, remote_tracking = 0;
		struct strbuf buf = STRBUF_INIT;

		if (kinds != REF_LOCAL_BRANCH)
			die(_("-a and -r options to 'git branch' do not make sense with a branch name"));

