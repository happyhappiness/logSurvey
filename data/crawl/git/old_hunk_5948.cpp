	test_cmp expect output
'

cat > expect <<EOF
set -- --foo -- '--' 'arg' '--bar=ham'
EOF