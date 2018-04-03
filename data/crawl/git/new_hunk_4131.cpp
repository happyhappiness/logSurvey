		>&3 2>git_daemon_output &
	GIT_DAEMON_PID=$!
	{
		read line <&7
		echo >&4 "$line"
		cat <&7 >&4 &
	} 7<git_daemon_output &&

	# Check expected output
	if test x"$(expr "$line" : "\[[0-9]*\] \(.*\)")" != x"Ready to rumble"
	then
		kill "$GIT_DAEMON_PID"
		wait "$GIT_DAEMON_PID"
		trap 'die' EXIT
		error "git daemon failed to start"
	fi
}

stop_git_daemon() {