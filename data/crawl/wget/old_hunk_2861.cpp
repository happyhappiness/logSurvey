\def\inforefzzz #1,#2,#3,#4**{\putwordSee{} \putwordInfo{} \putwordfile{} \file{\ignorespaces #3{}},
  node \samp{\ignorespaces#1{}}}

% @setref{foo} defines a cross-reference point named foo.

\def\setref#1{%
\dosetq{#1-title}{Ytitle}%
\dosetq{#1-pg}{Ypagenumber}%
\dosetq{#1-snt}{Ysectionnumberandtype}}

\def\unnumbsetref#1{%
\dosetq{#1-title}{Ytitle}%
\dosetq{#1-pg}{Ypagenumber}%
\dosetq{#1-snt}{Ynothing}}

\def\appendixsetref#1{%
\dosetq{#1-title}{Ytitle}%
\dosetq{#1-pg}{Ypagenumber}%
\dosetq{#1-snt}{Yappendixletterandtype}}

% \xref, \pxref, and \ref generate cross-references to specified points.
% For \xrefX, #1 is the node name, #2 the name of the Info
% cross-reference, #3 the printed node name, #4 the name of the Info
% file, #5 the name of the printed manual.  All but the node name can be
% omitted.
%
\def\pxref#1{\putwordsee{} \xrefX[#1,,,,,,,]}
\def\xref#1{\putwordSee{} \xrefX[#1,,,,,,,]}
\def\ref#1{\xrefX[#1,,,,,,,]}
\def\xrefX[#1,#2,#3,#4,#5,#6]{\begingroup
  \def\printedmanual{\ignorespaces #5}%
  \def\printednodename{\ignorespaces #3}%
  \setbox1=\hbox{\printedmanual}%
  \setbox0=\hbox{\printednodename}%
  \ifdim \wd0 = 0pt
    % No printed node name was explicitly given.
    \expandafter\ifx\csname SETxref-automatic-section-title\endcsname\relax
      % Use the node name inside the square brackets.
      \def\printednodename{\ignorespaces #1}%
    \else
      % Use the actual chapter/section title appear inside
      % the square brackets.  Use the real section title if we have it.
      \ifdim \wd1>0pt%
        % It is in another manual, so we don't have it.
        \def\printednodename{\ignorespaces #1}%
      \else
        \ifhavexrefs
          % We know the real title if we have the xref values.
          \def\printednodename{\refx{#1-title}{}}%
        \else
          % Otherwise just copy the Info node name.
          \def\printednodename{\ignorespaces #1}%
        \fi%
      \fi
    \fi
  \fi
  %
  % If we use \unhbox0 and \unhbox1 to print the node names, TeX does not
  % insert empty discretionaries after hyphens, which means that it will
  % not find a line break at a hyphen in a node names.  Since some manuals
  % are best written with fairly long node names, containing hyphens, this
  % is a loss.  Therefore, we give the text of the node name again, so it
  % is as if TeX is seeing it for the first time.
  \ifdim \wd1 > 0pt
    \putwordsection{} ``\printednodename'' in \cite{\printedmanual}%
  \else
    % _ (for example) has to be the character _ for the purposes of the
    % control sequence corresponding to the node, but it has to expand
    % into the usual \leavevmode...\vrule stuff for purposes of
    % printing. So we \turnoffactive for the \refx-snt, back on for the
    % printing, back off for the \refx-pg.
    {\normalturnoffactive \refx{#1-snt}{}}%
    \space [\printednodename],\space
    \turnoffactive \putwordpage\tie\refx{#1-pg}{}%
  \fi
\endgroup}

% \dosetq is the interface for calls from other macros

% Use \normalturnoffactive so that punctuation chars such as underscore
% and backslash work in node names.  (\turnoffactive doesn't do \.)
\def\dosetq#1#2{%
  {\let\folio=0
   \normalturnoffactive
   \edef\next{\write\auxfile{\internalsetq{#1}{#2}}}%
   \next
  }%
}

% \internalsetq {foo}{page} expands into
% CHARACTERS 'xrdef {foo}{...expansion of \Ypage...}
% When the aux file is read, ' is the escape character

\def\internalsetq #1#2{'xrdef {#1}{\csname #2\endcsname}}

% Things to be expanded by \internalsetq

\def\Ypagenumber{\folio}

\def\Ytitle{\thissection}

\def\Ynothing{}

\def\Ysectionnumberandtype{%
\ifnum\secno=0 \putwordChapter\xreftie\the\chapno %
\else \ifnum \subsecno=0 \putwordSection\xreftie\the\chapno.\the\secno %
\else \ifnum \subsubsecno=0 %
\putwordSection\xreftie\the\chapno.\the\secno.\the\subsecno %
\else %
\putwordSection\xreftie\the\chapno.\the\secno.\the\subsecno.\the\subsubsecno %
\fi \fi \fi }

\def\Yappendixletterandtype{%
\ifnum\secno=0 \putwordAppendix\xreftie'char\the\appendixno{}%
\else \ifnum \subsecno=0 \putwordSection\xreftie'char\the\appendixno.\the\secno %
\else \ifnum \subsubsecno=0 %
\putwordSection\xreftie'char\the\appendixno.\the\secno.\the\subsecno %
\else %
\putwordSection\xreftie'char\the\appendixno.\the\secno.\the\subsecno.\the\subsubsecno %
\fi \fi \fi }

\gdef\xreftie{'tie}

% Use TeX 3.0's \inputlineno to get the line number, for better error
% messages, but if we're using an old version of TeX, don't do anything.
%
\ifx\inputlineno\thisisundefined
  \let\linenumber = \empty % Non-3.0.
\else
  \def\linenumber{\the\inputlineno:\space}
\fi

% Define \refx{NAME}{SUFFIX} to reference a cross-reference string named NAME.
% If its value is nonempty, SUFFIX is output afterward.

\def\refx#1#2{%
  \expandafter\ifx\csname X#1\endcsname\relax
    % If not defined, say something at least.
    \angleleft un\-de\-fined\angleright
    \ifhavexrefs
      \message{\linenumber Undefined cross reference `#1'.}%
    \else
      \ifwarnedxrefs\else
        \global\warnedxrefstrue
        \message{Cross reference values unknown; you must run TeX again.}%
      \fi
    \fi
  \else
    % It's defined, so just use it.
    \csname X#1\endcsname
  \fi
  #2% Output the suffix in any case.
}

% This is the macro invoked by entries in the aux file.
% 
\def\xrdef#1{\begingroup
  % Reenable \ as an escape while reading the second argument.
  \catcode`\\ = 0
  \afterassignment\endgroup
  \expandafter\gdef\csname X#1\endcsname
}

% Read the last existing aux file, if any.  No error if none exists.
\def\readauxfile{\begingroup
  \catcode`\^^@=\other
  \catcode`\^^A=\other
