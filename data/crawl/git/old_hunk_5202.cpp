git config --unset color.status
git config --unset color.ui

cat >expect <<\EOF
# On branch master
# Changes to be committed: