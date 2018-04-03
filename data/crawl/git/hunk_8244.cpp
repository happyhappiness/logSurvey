 ein.bahn=strasse
 EOF
 
-GIT_CONFIG=other-config git-config -l > output
+GIT_CONFIG=other-config git config -l > output
 
 test_expect_success 'alternative GIT_CONFIG' 'cmp output expect'
 
-GIT_CONFIG=other-config git-config anwohner.park ausweis
+GIT_CONFIG=other-config git config anwohner.park ausweis
 
 cat > expect << EOF
 [ein]
