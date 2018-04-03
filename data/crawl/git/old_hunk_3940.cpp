	git config -f .gitmodules  --remove-section submodule.subname
'

cat > expect << EOF
# On branch master
# Changes not staged for commit:
