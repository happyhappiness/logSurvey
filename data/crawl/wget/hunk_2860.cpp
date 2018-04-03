 \let\ptexend=\end
 \let\ptexequiv=\equiv
 \let\ptexexclam=\!
+\let\ptexfootnote=\footnote
+\let\ptexgtr=>
+\let\ptexhat=^
 \let\ptexi=\i
+\let\ptexindent=\indent
+\let\ptexinsert=\insert
 \let\ptexlbrace=\{
+\let\ptexless=<
+\let\ptexnewwrite\newwrite
+\let\ptexnoindent=\noindent
+\let\ptexplus=+
 \let\ptexrbrace=\}
+\let\ptexslash=\/
 \let\ptexstar=\*
 \let\ptext=\t
 
-% We never want plain's outer \+ definition in Texinfo.
-% For @tex, we can use \tabalign.
-\let\+ = \relax
-
-
-\message{Basics,}
-\chardef\other=12
-
 % If this character appears in an error message or help string, it
 % starts a new line in the output.
 \newlinechar = `^^J
 
+% Use TeX 3.0's \inputlineno to get the line number, for better error
+% messages, but if we're using an old version of TeX, don't do anything.
+%
+\ifx\inputlineno\thisisundefined
+  \let\linenumber = \empty % Pre-3.0.
+\else
+  \def\linenumber{l.\the\inputlineno:\space}
+\fi
+
 % Set up fixed words for English if not already set.
-\ifx\putwordAppendix\undefined \gdef\putwordAppendix{Appendix}\fi
-\ifx\putwordChapter\undefined  \gdef\putwordChapter{Chapter}\fi
-\ifx\putwordfile\undefined     \gdef\putwordfile{file}\fi
-\ifx\putwordInfo\undefined     \gdef\putwordfile{Info}\fi
-\ifx\putwordMethodon\undefined \gdef\putwordMethodon{Method on}\fi
-\ifx\putwordon\undefined       \gdef\putwordon{on}\fi
-\ifx\putwordpage\undefined     \gdef\putwordpage{page}\fi
-\ifx\putwordsection\undefined  \gdef\putwordsection{section}\fi
-\ifx\putwordSection\undefined  \gdef\putwordSection{Section}\fi
-\ifx\putwordsee\undefined      \gdef\putwordsee{see}\fi
-\ifx\putwordSee\undefined      \gdef\putwordSee{See}\fi
-\ifx\putwordShortContents\undefined  \gdef\putwordShortContents{Short Contents}\fi
-\ifx\putwordTableofContents\undefined\gdef\putwordTableofContents{Table of Contents}\fi
+\ifx\putwordAppendix\undefined  \gdef\putwordAppendix{Appendix}\fi
+\ifx\putwordChapter\undefined   \gdef\putwordChapter{Chapter}\fi
+\ifx\putwordfile\undefined      \gdef\putwordfile{file}\fi
+\ifx\putwordin\undefined        \gdef\putwordin{in}\fi
+\ifx\putwordIndexIsEmpty\undefined     \gdef\putwordIndexIsEmpty{(Index is empty)}\fi
+\ifx\putwordIndexNonexistent\undefined \gdef\putwordIndexNonexistent{(Index is nonexistent)}\fi
+\ifx\putwordInfo\undefined      \gdef\putwordInfo{Info}\fi
+\ifx\putwordInstanceVariableof\undefined \gdef\putwordInstanceVariableof{Instance Variable of}\fi
+\ifx\putwordMethodon\undefined  \gdef\putwordMethodon{Method on}\fi
+\ifx\putwordNoTitle\undefined   \gdef\putwordNoTitle{No Title}\fi
+\ifx\putwordof\undefined        \gdef\putwordof{of}\fi
+\ifx\putwordon\undefined        \gdef\putwordon{on}\fi
+\ifx\putwordpage\undefined      \gdef\putwordpage{page}\fi
+\ifx\putwordsection\undefined   \gdef\putwordsection{section}\fi
+\ifx\putwordSection\undefined   \gdef\putwordSection{Section}\fi
+\ifx\putwordsee\undefined       \gdef\putwordsee{see}\fi
+\ifx\putwordSee\undefined       \gdef\putwordSee{See}\fi
+\ifx\putwordShortTOC\undefined  \gdef\putwordShortTOC{Short Contents}\fi
+\ifx\putwordTOC\undefined       \gdef\putwordTOC{Table of Contents}\fi
+%
+\ifx\putwordMJan\undefined \gdef\putwordMJan{January}\fi
+\ifx\putwordMFeb\undefined \gdef\putwordMFeb{February}\fi
+\ifx\putwordMMar\undefined \gdef\putwordMMar{March}\fi
+\ifx\putwordMApr\undefined \gdef\putwordMApr{April}\fi
+\ifx\putwordMMay\undefined \gdef\putwordMMay{May}\fi
+\ifx\putwordMJun\undefined \gdef\putwordMJun{June}\fi
+\ifx\putwordMJul\undefined \gdef\putwordMJul{July}\fi
+\ifx\putwordMAug\undefined \gdef\putwordMAug{August}\fi
+\ifx\putwordMSep\undefined \gdef\putwordMSep{September}\fi
+\ifx\putwordMOct\undefined \gdef\putwordMOct{October}\fi
+\ifx\putwordMNov\undefined \gdef\putwordMNov{November}\fi
+\ifx\putwordMDec\undefined \gdef\putwordMDec{December}\fi
+%
+\ifx\putwordDefmac\undefined    \gdef\putwordDefmac{Macro}\fi
+\ifx\putwordDefspec\undefined   \gdef\putwordDefspec{Special Form}\fi
+\ifx\putwordDefvar\undefined    \gdef\putwordDefvar{Variable}\fi
+\ifx\putwordDefopt\undefined    \gdef\putwordDefopt{User Option}\fi
+\ifx\putwordDeffunc\undefined   \gdef\putwordDeffunc{Function}\fi
+
+% In some macros, we cannot use the `\? notation---the left quote is
+% in some cases the escape char.
+\chardef\colonChar = `\:
+\chardef\commaChar = `\,
+\chardef\dotChar   = `\.
+\chardef\exclamChar= `\!
+\chardef\questChar = `\?
+\chardef\semiChar  = `\;
+\chardef\underChar = `\_
+
+\chardef\spaceChar = `\ %
+\chardef\spacecat = 10
+\def\spaceisspace{\catcode\spaceChar=\spacecat}
 
 % Ignore a token.
 %
 \def\gobble#1{}
 
-\hyphenation{ap-pen-dix}
-\hyphenation{mini-buf-fer mini-buf-fers}
-\hyphenation{eshell}
-\hyphenation{white-space}
+% The following is used inside several \edef's.
+\def\makecsname#1{\expandafter\noexpand\csname#1\endcsname}
+
+% Hyphenation fixes.
+\hyphenation{
+  Flor-i-da Ghost-script Ghost-view Mac-OS Post-Script
+  ap-pen-dix bit-map bit-maps
+  data-base data-bases eshell fall-ing half-way long-est man-u-script
+  man-u-scripts mini-buf-fer mini-buf-fers over-view par-a-digm
+  par-a-digms rath-er rec-tan-gu-lar ro-bot-ics se-vere-ly set-up spa-ces
+  spell-ing spell-ings
+  stand-alone strong-est time-stamp time-stamps which-ever white-space
+  wide-spread wrap-around
+}
 
 % Margin to add to right of even pages, to left of odd pages.
-\newdimen \bindingoffset
-\newdimen \normaloffset
+\newdimen\bindingoffset
+\newdimen\normaloffset
 \newdimen\pagewidth \newdimen\pageheight
 
+% For a final copy, take out the rectangles
+% that mark overfull boxes (in case you have decided
+% that the text looks ok even though it passes the margin).
+%
+\def\finalout{\overfullrule=0pt}
+
+% @| inserts a changebar to the left of the current line.  It should
+% surround any changed text.  This approach does *not* work if the
+% change spans more than two lines of output.  To handle that, we would
+% have adopt a much more difficult approach (putting marks into the main
+% vertical list for the beginning and end of each change).
+%
+\def\|{%
+  % \vadjust can only be used in horizontal mode.
+  \leavevmode
+  %
+  % Append this vertical mode material after the current line in the output.
+  \vadjust{%
+    % We want to insert a rule with the height and depth of the current
+    % leading; that is exactly what \strutbox is supposed to record.
+    \vskip-\baselineskip
+    %
+    % \vadjust-items are inserted at the left edge of the type.  So
+    % the \llap here moves out into the left-hand margin.
+    \llap{%
+      %
+      % For a thicker or thinner bar, change the `1pt'.
+      \vrule height\baselineskip width1pt
+      %
+      % This is the space between the bar and the text.
+      \hskip 12pt
+    }%
+  }%
+}
+
 % Sometimes it is convenient to have everything in the transcript file
 % and nothing on the terminal.  We don't just call \tracingall here,
-% since that produces some useless output on the terminal.
+% since that produces some useless output on the terminal.  We also make
+% some effort to order the tracing commands to reduce output in the log
+% file; cf. trace.sty in LaTeX.
 %
 \def\gloggingall{\begingroup \globaldefs = 1 \loggingall \endgroup}%
-\def\loggingall{\tracingcommands2 \tracingstats2
-   \tracingpages1 \tracingoutput1 \tracinglostchars1
-   \tracingmacros2 \tracingparagraphs1 \tracingrestores1
-   \showboxbreadth\maxdimen\showboxdepth\maxdimen
+\def\loggingall{%
+  \tracingstats2
+  \tracingpages1
+  \tracinglostchars2  % 2 gives us more in etex
+  \tracingparagraphs1
+  \tracingoutput1
+  \tracingmacros2
+  \tracingrestores1
+  \showboxbreadth\maxdimen \showboxdepth\maxdimen
+  \ifx\eTeXversion\undefined\else % etex gives us more logging
+    \tracingscantokens1
+    \tracingifs1
+    \tracinggroups1
+    \tracingnesting2
+    \tracingassigns1
+  \fi
+  \tracingcommands3  % 3 gives us more in etex
+  \errorcontextlines16
 }%
 
+% add check for \lastpenalty to plain's definitions.  If the last thing
+% we did was a \nobreak, we don't want to insert more space.
+%
+\def\smallbreak{\ifnum\lastpenalty<10000\par\ifdim\lastskip<\smallskipamount
+  \removelastskip\penalty-50\smallskip\fi\fi}
+\def\medbreak{\ifnum\lastpenalty<10000\par\ifdim\lastskip<\medskipamount
+  \removelastskip\penalty-100\medskip\fi\fi}
+\def\bigbreak{\ifnum\lastpenalty<10000\par\ifdim\lastskip<\bigskipamount
+  \removelastskip\penalty-200\bigskip\fi\fi}
+
 % For @cropmarks command.
 % Do @cropmarks to get crop marks.
-% 
+%
 \newif\ifcropmarks
 \let\cropmarks = \cropmarkstrue
 %
 % Dimensions to add cropmarks at corners.
 % Added by P. A. MacKay, 12 Nov. 1986
 %
-\newdimen\cornerlong \newdimen\cornerthick
-\newdimen\topandbottommargin
-\newdimen\outerhsize \newdimen\outervsize
-\cornerlong=1pc\cornerthick=.3pt        % These set size of cropmarks
-\outerhsize=7in
-%\outervsize=9.5in
-% Alternative @smallbook page size is 9.25in
-\outervsize=9.25in
-\topandbottommargin=.75in
+\newdimen\outerhsize \newdimen\outervsize % set by the paper size routines
+\newdimen\cornerlong  \cornerlong=1pc
+\newdimen\cornerthick \cornerthick=.3pt
+\newdimen\topandbottommargin \topandbottommargin=.75in
 
 % Main output routine.
 \chardef\PAGE = 255
