 	case wordend:
 	    printf("/wordend");
 
-#ifdef emacs
-	case before_dot:
-	    printf("/before_dot");
-	    break;
-
-	case at_dot:
-	    printf("/at_dot");
-	    break;
-
-	case after_dot:
-	    printf("/after_dot");
-	    break;
-
-	case syntaxspec:
-	    printf("/syntaxspec");
-	    mcnt = *p++;
-	    printf("/%d", mcnt);
-	    break;
-
-	case notsyntaxspec:
-	    printf("/notsyntaxspec");
-	    mcnt = *p++;
-	    printf("/%d", mcnt);
-	    break;
-#endif /* emacs */
-
 	case wordchar:
 	    printf("/wordchar");
 	    break;
