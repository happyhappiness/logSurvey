 	case 0:
 		if (!memcmp(dst_value, "refs/", 5))
 			matched_dst = make_linked_ref(dst_value, dst_tail);
+		else if((dst_guess = guess_ref(dst_value, matched_src)))
+			matched_dst = make_linked_ref(dst_guess, dst_tail);
 		else
-			error("dst refspec %s does not match any "
-			      "existing ref on the remote and does "
-			      "not start with refs/.", dst_value);
+			error("unable to push to unqualified destination: %s\n"
+			      "The destination refspec neither matches an "
+			      "existing ref on the remote nor\n"
+			      "begins with refs/, and we are unable to "
+			      "guess a prefix based on the source ref.",
+			      dst_value);
 		break;
 	default:
 		matched_dst = NULL;
