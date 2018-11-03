\NeedsTeXFormat{LaTeX2e}
\ProvidesClass{../share/cpslide}[2011/12/23 Competitive programming slides]

\makeatletter

% Option management
\RequirePackage{kvoptions}
\RequirePackage{kvoptions-patch}
\SetupKeyvalOptions{
    family=my,
    prefix=my@
}

% Class options
\def\beameroptions{12pt}
\DeclareVoidOption{handout}{\edef\beameroptions{\beameroptions,handout}}
\DeclareStringOption{code}
\DeclareStringOption{title}
\ProcessKeyvalOptions*

\RequirePackage[utf8]{inputenc}
\RequirePackage[T1]{fontenc}
\RequirePackage{lmodern}

\LoadClass[\beameroptions]{beamer}

% Packages
\RequirePackage{graphicx}
\RequirePackage{listings}
\RequirePackage{amsmath}
\RequirePackage{amsfonts}
\RequirePackage{verbatim}
\RequirePackage{stmaryrd}
\RequirePackage{tikz}
\RequirePackage{xcolor}
\RequirePackage{listings}

\usetheme{Warsaw}

% Slide stuff
\newcommand{\slideinit}{
  \title{Unit \emph{\my@code}: \my@title} 
  \author{The beOI Instructors}
  \titlegraphic{\includegraphics[width=2cm]{../share/beoi-logo.png}}
}

\newcommand{\slidebegin}{
  \begin{frame}
    \titlepage
  \end{frame}
}

% Complexity
\renewcommand{\O}[1]{
  \ensuremath{\mathcal{O}(#1)}
}

\newcommand{\On}{\O{n}}
\newcommand{\Onlogn}{\O{n\log n}}
\newcommand{\Onsq}{\O{n^2}}
\newcommand{\Ologn}{\O{\log n}}
\newcommand{\Ove}{\O{VE}}
\newcommand{\Ovloge}{\O{V\log E}}

% Listings
\lstset{
  language=C++,
  basicstyle=\tiny\ttfamily,
  keywordstyle=\bfseries\color{orange!20!red!70!black},
  commentstyle=\itshape\color{black!50},
  tabsize=4,
  numbers=left,
  stepnumber=1}
\newcommand{\code}[1]{\lstinputlisting{#1}}
\newcommand{\src}[1]{\code{./src/#1}}

\makeatother