	fi
}

check_push () {
	local expected_ret=$1 ret=0 ref_ret=0 IFS=':'

	shift
	git push origin "$@" 2> error
	ret=$?
	cat error

	while read branch kind
	do
		case "$kind" in
		'new')
			grep "^ \* \[new branch\] *${branch} -> ${branch}$" error || ref_ret=1
			;;
		'non-fast-forward')
			grep "^ ! \[rejected\] *${branch} -> ${branch} (non-fast-forward)$" error || ref_ret=1
			;;
		'')
			grep "^   [a-f0-9]*\.\.[a-f0-9]* *${branch} -> ${branch}$" error || ref_ret=1
			;;
		esac
		let 'ref_ret' && echo "match for '$branch' failed" && break
	done

	if let 'expected_ret != ret || ref_ret'
	then
		return 1
	fi

	return 0
}

setup () {
	(
	echo "[ui]"
