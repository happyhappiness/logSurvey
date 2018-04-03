\let\ptexend=\end
\let\ptexequiv=\equiv
\let\ptexexclam=\!
\let\ptexi=\i
\let\ptexlbrace=\{
\let\ptexrbrace=\}
\let\ptexstar=\*
\let\ptext=\t

% We never want plain's outer \+ definition in Texinfo.
% For @tex, we can use \tabalign.
\let\+ = \relax


\message{Basics,}
\chardef\other=12

% If this character appears in an error message or help string, it
% starts a new line in the output.
\newlinechar = `^^J

% Set up fixed words for English if not already set.
\ifx\putwordAppendix\undefined \gdef\putwordAppendix{Appendix}\fi
\ifx\putwordChapter\undefined  \gdef\putwordChapter{Chapter}\fi
\ifx\putwordfile\undefined     \gdef\putwordfile{file}\fi
\ifx\putwordInfo\undefined     \gdef\putwordfile{Info}\fi
\ifx\putwordMethodon\undefined \gdef\putwordMethodon{Method on}\fi
\ifx\putwordon\undefined       \gdef\putwordon{on}\fi
\ifx\putwordpage\undefined     \gdef\putwordpage{page}\fi
\ifx\putwordsection\undefined  \gdef\putwordsection{section}\fi
\ifx\putwordSection\undefined  \gdef\putwordSection{Section}\fi
\ifx\putwordsee\undefined      \gdef\putwordsee{see}\fi
\ifx\putwordSee\undefined      \gdef\putwordSee{See}\fi
\ifx\putwordShortContents\undefined  \gdef\putwordShortContents{Short Contents}\fi
\ifx\putwordTableofContents\undefined\gdef\putwordTableofContents{Table of Contents}\fi

% Ignore a token.
%
\def\gobble#1{}

\hyphenation{ap-pen-dix}
\hyphenation{mini-buf-fer mini-buf-fers}
\hyphenation{eshell}
\hyphenation{white-space}

% Margin to add to right of even pages, to left of odd pages.
\newdimen \bindingoffset
\newdimen \normaloffset
\newdimen\pagewidth \newdimen\pageheight

% Sometimes it is convenient to have everything in the transcript file
% and nothing on the terminal.  We don't just call \tracingall here,
% since that produces some useless output on the terminal.
%
\def\gloggingall{\begingroup \globaldefs = 1 \loggingall \endgroup}%
\def\loggingall{\tracingcommands2 \tracingstats2
   \tracingpages1 \tracingoutput1 \tracinglostchars1
   \tracingmacros2 \tracingparagraphs1 \tracingrestores1
   \showboxbreadth\maxdimen\showboxdepth\maxdimen
}%

% For @cropmarks command.
% Do @cropmarks to get crop marks.
% 
\newif\ifcropmarks
\let\cropmarks = \cropmarkstrue
%
% Dimensions to add cropmarks at corners.
% Added by P. A. MacKay, 12 Nov. 1986
%
\newdimen\cornerlong \newdimen\cornerthick
\newdimen\topandbottommargin
\newdimen\outerhsize \newdimen\outervsize
\cornerlong=1pc\cornerthick=.3pt        % These set size of cropmarks
\outerhsize=7in
%\outervsize=9.5in
% Alternative @smallbook page size is 9.25in
\outervsize=9.25in
\topandbottommargin=.75in

% Main output routine.
\chardef\PAGE = 255
