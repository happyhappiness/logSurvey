	 test_must_fail git rev-parse refs/remotes/origin/side)
'

cat > test/expect << EOF
Pruning origin
URL: $(pwd)/one