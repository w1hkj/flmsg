//======================================================================
// IARU templates
//======================================================================

#include "templates.h"

const char iaru_html_template[] =
"<!DOCTYPE html PUBLIC \"-//W3C//DTD HTML 4.01//EN\" \"http://www.w3.org/TR/html4/strict.dtd\">\n\
<html><head><meta content=\"text/html; charset=ISO-8859-1\" http-equiv=\"content-type\"><title>iaru</title>\n\
<meta content=\"w1hkj\" name=\"author\">\n\
<style>\n\
F2{font-family: \"sans-serif\"; font-size: 10pt}\n\
F3{font-family: \"sans-serif\"; font-size: 14pt}\n\
F4{font-family: \"monospace\"; font-size: 12pt}\n\
F5{font-family: \"sans-serif\"; font-size: 16pt}\n\
</style>\n\
</head>\n\
<body>\n\
<table style=\"text-align: left; width: 100%;\" border=0 cellpadding=0 cellspacing=0>\n\
<tr>\n\
<td VALIGN=top ALIGN=center><F5><b>IARU MESSAGE</b></F5></td>\n\
</tr>\n\
</tbody>\n\
</table>\n\
\n\
<table style=\"text-align: left; width: 100%;\" border=\"1\" cellpadding=\"2\" cellspacing=\"0\">\n\
<tr>\n\
<td style=\"vertical-align: top; text-align: center; width: 15%;\"><F2>NUMBER</F2></td>\n\
<td style=\"vertical-align: top; text-align: center; width: 15%;\"><F2>PRECEDENCE</F2></td>\n\
<td style=\"vertical-align: top; text-align: center; width: 20%;\"><F2>STATION OF ORIGIN</F2></td>\n\
<td style=\"vertical-align: top; text-align: center; width: 10%;\"><F2>CHECK</F2></td>\n\
<td style=\"vertical-align: top; text-align: center; width: 20%;\"><F2>PLACE OF ORIGIN</F2></td>\n\
<td style=\"vertical-align: top; text-align: center; width: 10%;\"><F2>FILING TIME</F2></td>\n\
<td style=\"vertical-align: top; text-align: center; width: 10%;\"><F2>FILING DATE</F2></td>\n\
</tr>\n\
<tr>\n\
<td style=\"vertical-align: top; text-align: center;\"><F4>:nbr:</F4></td>\n\
<td style=\"vertical-align: top; text-align: center;\"><F4>:prec:</F4></td>\n\
<td style=\"vertical-align: top; text-align: center;\"><F4>:sta:</F4></td>\n\
<td style=\"vertical-align: top; text-align: center;\"><F4>:ck:</F4></td>\n\
<td style=\"vertical-align: top; text-align: center;\"><F4>:org:</F4></td>\n\
<td style=\"vertical-align: top; text-align: center;\"><F4>:t1:</F4></td>\n\
<td style=\"vertical-align: top; text-align: center;\"><F4>:d1:</F4></td>\n\
</tr>\n\
</table>\n\
<br>\n\
<table width=100% border=1 cellpadding=2 cellspacing=0>\n\
<tr><td>\n\
<table width=100% border=0 cellpadding=0 cellspacing=0>\n\
<col width = 98%><col width = 2%>\n\
<tr>\n\
	<td VALIGN=top><F2><B>To:</B></F2><br><F4>:to:</F4></td>\n\
	<td><br><br><br></td>\n\
</tr>\n\
<tr>\n\
	<td VALIGN=top><F4>:msg:</F4></td>\n\
	<td><F4><br><br><br><br><br><br><br><br><br></F4></td>\n\
</tr>\n\
<tr>\n\
	<td VALIGN=top><F2><B>From:</B></F2><F4><br>:fm:</F4></td>\n\
	<td><F4><br><br><br></F4></td>\n\
</tr>\n\
</table>\n\
</td></tr>\n\
</table>\n\
<br>\n\
<table style=\"text-align: left; width: 100%;\" border=\"1\" cellpadding=\"2\" cellspacing=\"0\">\n\
<tr>\n\
<td style=\"vertical-align: top; text-align: center; width: 24%;\"><F2>RECEIVED FROM</F2></td>\n\
<td style=\"vertical-align: top; text-align: center; width: 10%;\"><F2>DATE</F2></td>\n\
<td style=\"vertical-align: top; text-align: center; width: 10%;\"><F2>TIME</F2></td>\n\
<td style=\"vertical-align: top; text-align: center; width: 4%;\" ROWSPAN=2></td>\n\
<td style=\"vertical-align: top; text-align: center; width: 24%;\"><F2>SENT TO</F2></td>\n\
<td style=\"vertical-align: top; text-align: center; width: 10%;\"><F2>DATE</F2></td>\n\
<td style=\"vertical-align: top; text-align: center; width: 10%;\"><F2>TIME</F2></td>\n\
<tr>\n\
<td style=\"vertical-align: top; text-align: center;\"><F4>:rcv:</F4></td>\n\
<td style=\"vertical-align: top; text-align: center;\"><F4>:d2:</F4></td>\n\
<td style=\"vertical-align: top; text-align: center;\"><F4>:t2:</F4></td>\n\
<td style=\"vertical-align: top; text-align: center;\"><F4>:sto:</F4></td>\n\
<td style=\"vertical-align: top; text-align: center;\"><F4>:d3:</F4></td>\n\
<td style=\"vertical-align: top; text-align: center;\"><F4>:t3:</F4></td>\n\
</tr>\n\
</table>\n\
</td>\n\
</tr>\n\
</table>\n\
<br>\n\
</body></html>\n\
";

const char iaru_txt_template[] =
":nbr: :prec: :sta: :ck: :org: :t1: :d1:\n\
:to:\n\
BT\n\
:msg:\n\
BT\n\
:fm:\n\
AR\n\
";

