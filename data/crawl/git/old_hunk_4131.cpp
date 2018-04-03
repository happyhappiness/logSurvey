		>&3 2>git_daemon_output &
	GIT_DAEMON_PID=$!
	{
		read line
		echo >&4 "$line"
		cat >&4 &

		# Check expected output
		if test x"$(expr "$line" : "\[[0-9]*\] \(.*\)")" != x"Ready to rumble"
		then
			kill "$GIT_DAEMON_PID"
			wait "$GIT_DAEMON_PID"
			trap 'die' EXIT
			error "git daemon failed to start"
		fi
	} <git_daemon_output
}

stop_git_daemon() {