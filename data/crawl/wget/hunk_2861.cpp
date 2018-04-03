 \def\inforefzzz #1,#2,#3,#4**{\putwordSee{} \putwordInfo{} \putwordfile{} \file{\ignorespaces #3{}},
   node \samp{\ignorespaces#1{}}}
 
-% @setref{foo} defines a cross-reference point named foo.
-
-\def\setref#1{%
-\dosetq{#1-title}{Ytitle}%
-\dosetq{#1-pg}{Ypagenumber}%
-\dosetq{#1-snt}{Ysectionnumberandtype}}
-
-\def\unnumbsetref#1{%
-\dosetq{#1-title}{Ytitle}%
-\dosetq{#1-pg}{Ypagenumber}%
-\dosetq{#1-snt}{Ynothing}}
+% @node's only job in TeX is to define \lastnode, which is used in
+% cross-references.  The @node line might or might not have commas, and
+% might or might not have spaces before the first comma, like:
+% @node foo , bar , ...
+% We don't want such trailing spaces in the node name.
+%
+\parseargdef\node{\checkenv{}\donode #1 ,\finishnodeparse}
+%
+% also remove a trailing comma, in case of something like this:
+% @node Help-Cross,  ,  , Cross-refs
+\def\donode#1 ,#2\finishnodeparse{\dodonode #1,\finishnodeparse}
+\def\dodonode#1,#2\finishnodeparse{\gdef\lastnode{#1}}
 
-\def\appendixsetref#1{%
-\dosetq{#1-title}{Ytitle}%
-\dosetq{#1-pg}{Ypagenumber}%
-\dosetq{#1-snt}{Yappendixletterandtype}}
+\let\nwnode=\node
+\let\lastnode=\empty
 
-% \xref, \pxref, and \ref generate cross-references to specified points.
-% For \xrefX, #1 is the node name, #2 the name of the Info
-% cross-reference, #3 the printed node name, #4 the name of the Info
-% file, #5 the name of the printed manual.  All but the node name can be
-% omitted.
+% Write a cross-reference definition for the current node.  #1 is the
+% type (Ynumbered, Yappendix, Ynothing).
 %
-\def\pxref#1{\putwordsee{} \xrefX[#1,,,,,,,]}
+\def\donoderef#1{%
+  \ifx\lastnode\empty\else
+    \setref{\lastnode}{#1}%
+    \global\let\lastnode=\empty
+  \fi
+}
+
+% @anchor{NAME} -- define xref target at arbitrary point.
+%
+\newcount\savesfregister
+%
+\def\savesf{\relax \ifhmode \savesfregister=\spacefactor \fi}
+\def\restoresf{\relax \ifhmode \spacefactor=\savesfregister \fi}
+\def\anchor#1{\savesf \setref{#1}{Ynothing}\restoresf \ignorespaces}
+
+% \setref{NAME}{SNT} defines a cross-reference point NAME (a node or an
+% anchor), which consists of three parts:
+% 1) NAME-title - the current sectioning name taken from \thissection,
+%                 or the anchor name.
+% 2) NAME-snt   - section number and type, passed as the SNT arg, or
+%                 empty for anchors.
+% 3) NAME-pg    - the page number.
+%
+% This is called from \donoderef, \anchor, and \dofloat.  In the case of
+% floats, there is an additional part, which is not written here:
+% 4) NAME-lof   - the text as it should appear in a @listoffloats.
+%
+\def\setref#1#2{%
+  \pdfmkdest{#1}%
+  \iflinks
+    {%
+      \atdummies  % preserve commands, but don't expand them
+      \turnoffactive
+      \otherbackslash
+      \edef\writexrdef##1##2{%
+	\write\auxfile{@xrdef{#1-% #1 of \setref, expanded by the \edef
+	  ##1}{##2}}% these are parameters of \writexrdef
+      }%
+      \toks0 = \expandafter{\thissection}%
+      \immediate \writexrdef{title}{\the\toks0 }%
+      \immediate \writexrdef{snt}{\csname #2\endcsname}% \Ynumbered etc.
+      \writexrdef{pg}{\folio}% will be written later, during \shipout
+    }%
+  \fi
+}
+
+% @xref, @pxref, and @ref generate cross-references.  For \xrefX, #1 is
+% the node name, #2 the name of the Info cross-reference, #3 the printed
+% node name, #4 the name of the Info file, #5 the name of the printed
+% manual.  All but the node name can be omitted.
+%
+\def\pxref#1{\putwordsee{} \xrefX[#1,,,,,,,]}
 \def\xref#1{\putwordSee{} \xrefX[#1,,,,,,,]}
 \def\ref#1{\xrefX[#1,,,,,,,]}
 \def\xrefX[#1,#2,#3,#4,#5,#6]{\begingroup
+  \unsepspaces
   \def\printedmanual{\ignorespaces #5}%
-  \def\printednodename{\ignorespaces #3}%
-  \setbox1=\hbox{\printedmanual}%
-  \setbox0=\hbox{\printednodename}%
+  \def\printedrefname{\ignorespaces #3}%
+  \setbox1=\hbox{\printedmanual\unskip}%
+  \setbox0=\hbox{\printedrefname\unskip}%
   \ifdim \wd0 = 0pt
     % No printed node name was explicitly given.
     \expandafter\ifx\csname SETxref-automatic-section-title\endcsname\relax
       % Use the node name inside the square brackets.
-      \def\printednodename{\ignorespaces #1}%
+      \def\printedrefname{\ignorespaces #1}%
     \else
       % Use the actual chapter/section title appear inside
       % the square brackets.  Use the real section title if we have it.
-      \ifdim \wd1>0pt%
+      \ifdim \wd1 > 0pt
         % It is in another manual, so we don't have it.
-        \def\printednodename{\ignorespaces #1}%
+        \def\printedrefname{\ignorespaces #1}%
       \else
         \ifhavexrefs
           % We know the real title if we have the xref values.
-          \def\printednodename{\refx{#1-title}{}}%
+          \def\printedrefname{\refx{#1-title}{}}%
         \else
           % Otherwise just copy the Info node name.
-          \def\printednodename{\ignorespaces #1}%
+          \def\printedrefname{\ignorespaces #1}%
         \fi%
       \fi
     \fi
   \fi
   %
-  % If we use \unhbox0 and \unhbox1 to print the node names, TeX does not
-  % insert empty discretionaries after hyphens, which means that it will
-  % not find a line break at a hyphen in a node names.  Since some manuals
-  % are best written with fairly long node names, containing hyphens, this
-  % is a loss.  Therefore, we give the text of the node name again, so it
-  % is as if TeX is seeing it for the first time.
-  \ifdim \wd1 > 0pt
-    \putwordsection{} ``\printednodename'' in \cite{\printedmanual}%
+  % Make link in pdf output.
+  \ifpdf
+    \leavevmode
+    \getfilename{#4}%
+    {\turnoffactive \otherbackslash
+     \ifnum\filenamelength>0
+       \startlink attr{/Border [0 0 0]}%
+         goto file{\the\filename.pdf} name{#1}%
+     \else
+       \startlink attr{/Border [0 0 0]}%
+         goto name{\pdfmkpgn{#1}}%
+     \fi
+    }%
+    \linkcolor
+  \fi
+  %
+  % Float references are printed completely differently: "Figure 1.2"
+  % instead of "[somenode], p.3".  We distinguish them by the
+  % LABEL-title being set to a magic string.
+  {%
+    % Have to otherify everything special to allow the \csname to
+    % include an _ in the xref name, etc.
+    \indexnofonts
+    \turnoffactive
+    \otherbackslash
+    \expandafter\global\expandafter\let\expandafter\Xthisreftitle
+      \csname XR#1-title\endcsname
+  }%
+  \iffloat\Xthisreftitle
+    % If the user specified the print name (third arg) to the ref,
+    % print it instead of our usual "Figure 1.2".
+    \ifdim\wd0 = 0pt
+      \refx{#1-snt}%
+    \else
+      \printedrefname
+    \fi
+    %
+    % if the user also gave the printed manual name (fifth arg), append
+    % "in MANUALNAME".
+    \ifdim \wd1 > 0pt
+      \space \putwordin{} \cite{\printedmanual}%
+    \fi
   \else
-    % _ (for example) has to be the character _ for the purposes of the
-    % control sequence corresponding to the node, but it has to expand
-    % into the usual \leavevmode...\vrule stuff for purposes of
-    % printing. So we \turnoffactive for the \refx-snt, back on for the
-    % printing, back off for the \refx-pg.
-    {\normalturnoffactive \refx{#1-snt}{}}%
-    \space [\printednodename],\space
-    \turnoffactive \putwordpage\tie\refx{#1-pg}{}%
+    % node/anchor (non-float) references.
+    %
+    % If we use \unhbox0 and \unhbox1 to print the node names, TeX does not
+    % insert empty discretionaries after hyphens, which means that it will
+    % not find a line break at a hyphen in a node names.  Since some manuals
+    % are best written with fairly long node names, containing hyphens, this
+    % is a loss.  Therefore, we give the text of the node name again, so it
+    % is as if TeX is seeing it for the first time.
+    \ifdim \wd1 > 0pt
+      \putwordsection{} ``\printedrefname'' \putwordin{} \cite{\printedmanual}%
+    \else
+      % _ (for example) has to be the character _ for the purposes of the
+      % control sequence corresponding to the node, but it has to expand
+      % into the usual \leavevmode...\vrule stuff for purposes of
+      % printing. So we \turnoffactive for the \refx-snt, back on for the
+      % printing, back off for the \refx-pg.
+      {\turnoffactive \otherbackslash
+       % Only output a following space if the -snt ref is nonempty; for
+       % @unnumbered and @anchor, it won't be.
+       \setbox2 = \hbox{\ignorespaces \refx{#1-snt}{}}%
+       \ifdim \wd2 > 0pt \refx{#1-snt}\space\fi
+      }%
+      % output the `[mynode]' via a macro so it can be overridden.
+      \xrefprintnodename\printedrefname
+      %
+      % But we always want a comma and a space:
+      ,\space
+      %
+      % output the `page 3'.
+      \turnoffactive \otherbackslash \putwordpage\tie\refx{#1-pg}{}%
+    \fi
   \fi
+  \endlink
 \endgroup}
 
-% \dosetq is the interface for calls from other macros
-
-% Use \normalturnoffactive so that punctuation chars such as underscore
-% and backslash work in node names.  (\turnoffactive doesn't do \.)
-\def\dosetq#1#2{%
-  {\let\folio=0
-   \normalturnoffactive
-   \edef\next{\write\auxfile{\internalsetq{#1}{#2}}}%
-   \next
-  }%
-}
-
-% \internalsetq {foo}{page} expands into
-% CHARACTERS 'xrdef {foo}{...expansion of \Ypage...}
-% When the aux file is read, ' is the escape character
-
-\def\internalsetq #1#2{'xrdef {#1}{\csname #2\endcsname}}
-
-% Things to be expanded by \internalsetq
-
-\def\Ypagenumber{\folio}
-
-\def\Ytitle{\thissection}
-
-\def\Ynothing{}
-
-\def\Ysectionnumberandtype{%
-\ifnum\secno=0 \putwordChapter\xreftie\the\chapno %
-\else \ifnum \subsecno=0 \putwordSection\xreftie\the\chapno.\the\secno %
-\else \ifnum \subsubsecno=0 %
-\putwordSection\xreftie\the\chapno.\the\secno.\the\subsecno %
-\else %
-\putwordSection\xreftie\the\chapno.\the\secno.\the\subsecno.\the\subsubsecno %
-\fi \fi \fi }
-
-\def\Yappendixletterandtype{%
-\ifnum\secno=0 \putwordAppendix\xreftie'char\the\appendixno{}%
-\else \ifnum \subsecno=0 \putwordSection\xreftie'char\the\appendixno.\the\secno %
-\else \ifnum \subsubsecno=0 %
-\putwordSection\xreftie'char\the\appendixno.\the\secno.\the\subsecno %
-\else %
-\putwordSection\xreftie'char\the\appendixno.\the\secno.\the\subsecno.\the\subsubsecno %
-\fi \fi \fi }
-
-\gdef\xreftie{'tie}
+% This macro is called from \xrefX for the `[nodename]' part of xref
+% output.  It's a separate macro only so it can be changed more easily,
+% since square brackets don't work well in some documents.  Particularly
+% one that Bob is working on :).
+%
+\def\xrefprintnodename#1{[#1]}
 
-% Use TeX 3.0's \inputlineno to get the line number, for better error
-% messages, but if we're using an old version of TeX, don't do anything.
+% Things referred to by \setref.
 %
-\ifx\inputlineno\thisisundefined
-  \let\linenumber = \empty % Non-3.0.
-\else
-  \def\linenumber{\the\inputlineno:\space}
-\fi
+\def\Ynothing{}
+\def\Yomitfromtoc{}
+\def\Ynumbered{%
+  \ifnum\secno=0
+    \putwordChapter@tie \the\chapno
+  \else \ifnum\subsecno=0
+    \putwordSection@tie \the\chapno.\the\secno
+  \else \ifnum\subsubsecno=0
+    \putwordSection@tie \the\chapno.\the\secno.\the\subsecno
+  \else
+    \putwordSection@tie \the\chapno.\the\secno.\the\subsecno.\the\subsubsecno
+  \fi\fi\fi
+}
+\def\Yappendix{%
+  \ifnum\secno=0
+     \putwordAppendix@tie @char\the\appendixno{}%
+  \else \ifnum\subsecno=0
+     \putwordSection@tie @char\the\appendixno.\the\secno
+  \else \ifnum\subsubsecno=0
+    \putwordSection@tie @char\the\appendixno.\the\secno.\the\subsecno
+  \else
+    \putwordSection@tie
+      @char\the\appendixno.\the\secno.\the\subsecno.\the\subsubsecno
+  \fi\fi\fi
+}
 
 % Define \refx{NAME}{SUFFIX} to reference a cross-reference string named NAME.
 % If its value is nonempty, SUFFIX is output afterward.
-
+%
 \def\refx#1#2{%
-  \expandafter\ifx\csname X#1\endcsname\relax
+  {%
+    \indexnofonts
+    \otherbackslash
+    \expandafter\global\expandafter\let\expandafter\thisrefX
+      \csname XR#1\endcsname
+  }%
+  \ifx\thisrefX\relax
     % If not defined, say something at least.
     \angleleft un\-de\-fined\angleright
-    \ifhavexrefs
-      \message{\linenumber Undefined cross reference `#1'.}%
-    \else
-      \ifwarnedxrefs\else
-        \global\warnedxrefstrue
-        \message{Cross reference values unknown; you must run TeX again.}%
+    \iflinks
+      \ifhavexrefs
+        \message{\linenumber Undefined cross reference `#1'.}%
+      \else
+        \ifwarnedxrefs\else
+          \global\warnedxrefstrue
+          \message{Cross reference values unknown; you must run TeX again.}%
+        \fi
       \fi
     \fi
   \else
     % It's defined, so just use it.
-    \csname X#1\endcsname
+    \thisrefX
   \fi
   #2% Output the suffix in any case.
 }
 
-% This is the macro invoked by entries in the aux file.
-% 
-\def\xrdef#1{\begingroup
-  % Reenable \ as an escape while reading the second argument.
-  \catcode`\\ = 0
-  \afterassignment\endgroup
-  \expandafter\gdef\csname X#1\endcsname
+% This is the macro invoked by entries in the aux file.  Usually it's
+% just a \def (we prepend XR to the control sequence name to avoid
+% collisions).  But if this is a float type, we have more work to do.
+%
+\def\xrdef#1#2{%
+  \expandafter\gdef\csname XR#1\endcsname{#2}% remember this xref value.
+  %
+  % Was that xref control sequence that we just defined for a float?
+  \expandafter\iffloat\csname XR#1\endcsname
+    % it was a float, and we have the (safe) float type in \iffloattype.
+    \expandafter\let\expandafter\floatlist
+      \csname floatlist\iffloattype\endcsname
+    %
+    % Is this the first time we've seen this float type?
+    \expandafter\ifx\floatlist\relax
+      \toks0 = {\do}% yes, so just \do
+    \else
+      % had it before, so preserve previous elements in list.
+      \toks0 = \expandafter{\floatlist\do}%
+    \fi
+    %
+    % Remember this xref in the control sequence \floatlistFLOATTYPE,
+    % for later use in \listoffloats.
+    \expandafter\xdef\csname floatlist\iffloattype\endcsname{\the\toks0{#1}}%
+  \fi
 }
 
 % Read the last existing aux file, if any.  No error if none exists.
+%
+\def\tryauxfile{%
+  \openin 1 \jobname.aux
+  \ifeof 1 \else
+    \readauxfile
+    \global\havexrefstrue
+  \fi
+  \closein 1
+}
+
 \def\readauxfile{\begingroup
   \catcode`\^^@=\other
   \catcode`\^^A=\other
