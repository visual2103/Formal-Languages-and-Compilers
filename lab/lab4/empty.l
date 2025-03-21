%{
#include <stdio.h>

	
%}
%%
\n ;
\t ;
-?(0|[1-9][0-9]*)(\.[0-9]+)? {printf("%s",yytext);}
true {printf("%s",yytext);}
false {printf("%s",yytext);}
null  {printf("%s",yytext);}
"," {printf("%s",yytext);}
"{" {printf("%s",yytext);}
"}" {printf("%s",yytext);}
":" {printf("%s",yytext);}
"[" {printf("%s",yytext);}
"]" {printf("%s",yytext);}
(").*(") {printf("%s",yytext);}
. ;
%%



