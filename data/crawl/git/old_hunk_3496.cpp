pathx/ju/nk
EOF

test_expect_success \
    'validate git ls-files -k output.' \
    'test_cmp .expected .output'

test_expect_success \
    'git ls-files -m to show modified files.' \