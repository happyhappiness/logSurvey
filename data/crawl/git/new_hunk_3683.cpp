	    repository=$1
	    refspec=$2
	    echo "git push using: " $repository $refspec
	    localrev=$(git subtree split --prefix="$prefix") || die
	    git push $repository $localrev:refs/heads/$refspec
	else
	    die "'$dir' must already exist. Try 'git subtree add'."
	fi