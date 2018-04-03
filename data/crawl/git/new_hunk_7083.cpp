'
. ./test-lib.sh

cp ../t4109/patch1.patch .
cp ../t4109/patch2.patch .
cp ../t4109/patch3.patch .
cp ../t4109/patch4.patch .

test_expect_success "S = git apply (1)" \
    'git apply patch1.patch patch2.patch'
