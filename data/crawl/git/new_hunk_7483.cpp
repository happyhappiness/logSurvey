	git add dir2/added
'

test_expect_success 'status (1)' '

	grep -e "use \"git rm --cached <file>\.\.\.\" to unstage" output

'

cat > expect << \EOF
# On branch master
# Changes to be committed:
