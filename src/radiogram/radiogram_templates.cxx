//======================================================================
// RADIOGRAM templates
//======================================================================

#include "templates.h"

const char rg_html_template[] =
"<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0 Transitional//EN\">\n\
<HTML><HEAD><TITLE>radiogram</TITLE>\n\
<META content=\"text/html; charset=ISO-8859-1\" http-equiv=content-type>\n\
<META name=author content=w1hkj>\n\
<STYLE type=\"text/css\">\n\
p.F2 { FONT-FAMILY: \"sans-serif\"; FONT-SIZE: 8pt }\n\
p.F3 { FONT-FAMILY: \"sans-serif\"; FONT-SIZE: 14pt }\n\
p.F4 { FONT-FAMILY: \"monospace\"; FONT-SIZE: 12pt }\n\
p.F5 { FONT-FAMILY: \"sans-serif\"; FONT-SIZE: 16pt }\n\
p.F6 { FONT-FAMILY: \"sans-serif\"; FONT-SIZE: 10pt }\n\
</STYLE>\n\
\n\
<META name=GENERATOR content=\"MSHTML 8.00.6001.19154\"></HEAD>\n\
<BODY>\n\
<TABLE style=\"TEXT-ALIGN: left; WIDTH: 100%\" border=0 cellSpacing=0 \n\
cellPadding=0>\n\
  <TBODY>\n\
  <TR>\n\
    <TD style=\"VERTICAL-ALIGN: top\">\n\
      <TABLE \n\
      style=\"TEXT-ALIGN: left; WIDTH: 100%; MARGIN-LEFT: auto; MARGIN-RIGHT: auto\" \n\
      border=0 cellSpacing=0 cellPadding=2>\n\
        <TBODY>\n\
        <TR>\n\
          <TD style=\"VERTICAL-ALIGN: top\">\n\
            <DIV style=\"TEXT-ALIGN: center\">\n\
            <FONT size=3><B>THE AMERICAN RADIO RELAY LEAGUE</B></FONT><BR>\n\
            </DIV>\n\
            <DIV style=\"TEXT-ALIGN: center\">\n\
            <FONT size=6><B>RADIOGRAM</B></FONT><BR>\n\
            </DIV>\n\
            <DIV style=\"TEXT-ALIGN: center\">\n\
            <FONT size=3><B>VIA AMATEUR RADIO<BR></B></FONT>\n\
            </DIV>\n\
          </TD>\n\
        </TR>\n\
        </TBODY>\n\
      </TABLE>\n\
      <TABLE style=\"TEXT-ALIGN: left; WIDTH: 100%\" border=1 cellSpacing=0 \n\
      cellPadding=2>\n\
        <TBODY>\n\
        <TR>\n\
          <TD style=\"TEXT-ALIGN: center; WIDTH: 7%; VERTICAL-ALIGN: top\">\n\
            <p class=F2>NUMBER</p>\n\
          </TD>\n\
          <TD style=\"TEXT-ALIGN: center; WIDTH: 14%; VERTICAL-ALIGN: top\">\n\
            <p class=F2>PRECEDENCE</p>\n\
          </TD>\n\
          <TD style=\"TEXT-ALIGN: center; WIDTH: 7%; VERTICAL-ALIGN: top\">\n\
            <p class=F2>HX</p>\n\
          </TD>\n\
          <TD style=\"TEXT-ALIGN: center; WIDTH: 20%; VERTICAL-ALIGN: top\">\n\
            <p class=F2>STATION OF ORIGIN</p>\n\
          </TD>\n\
          <TD style=\"TEXT-ALIGN: center; WIDTH: 10%; VERTICAL-ALIGN: top\">\n\
            <p class=F2>CHECK</p>\n\
          </TD>\n\
          <TD style=\"TEXT-ALIGN: center; WIDTH: 20%; VERTICAL-ALIGN: top\">\n\
            <p class=F2>PLACE OF ORIGIN</p>\n\
          </TD>\n\
          <TD style=\"TEXT-ALIGN: center; WIDTH: 10%; VERTICAL-ALIGN: top\">\n\
            <p class=F2>TIME FILED</p>\n\
          </TD>\n\
          <TD style=\"TEXT-ALIGN: center; VERTICAL-ALIGN: top\">\n\
            <p class=F2>DATE</p>\n\
          </TD>\n\
        </TR>\n\
        <TR>\n\
          <TD style=\"TEXT-ALIGN: center; VERTICAL-ALIGN: top\">\n\
            <p class=F4>:nbr:<br></p>\n\
          </TD>\n\
          <TD style=\"TEXT-ALIGN: center; VERTICAL-ALIGN: top\">\n\
            <p class=F4>:prec:<br></p>\n\
          </TD>\n\
          <TD style=\"TEXT-ALIGN: center; VERTICAL-ALIGN: top\">\n\
            <p class=F4>:hx:<br></p>\n\
          </TD>\n\
          <TD style=\"TEXT-ALIGN: center; VERTICAL-ALIGN: top\">\n\
            <p class=\"F4\">:sta:<br></p>\n\
          </TD>\n\
          <TD style=\"TEXT-ALIGN: center; VERTICAL-ALIGN: top\">\n\
            <p class=F4>:ck:<br></p>\n\
          </TD>\n\
          <TD style=\"TEXT-ALIGN: center; VERTICAL-ALIGN: top\">\n\
            <p class=F4>:org:<br></p>\n\
          </TD>\n\
          <TD style=\"TEXT-ALIGN: center; VERTICAL-ALIGN: top\">\n\
            <p class=F4>:t1:<br></p>\n\
          </TD>\n\
          <TD style=\"TEXT-ALIGN: center; VERTICAL-ALIGN: top\">\n\
            <p class=F4>:d1:<br></p>\n\
          </TD>\n\
        </TR>\n\
        <TR>\n\
          <TD style=\"VERTICAL-ALIGN: top\" colSpan=4>\n\
            <table width=100% border=0 cellpadding=0 cellspacing=0>\n\
              <col width = 98%><col width = 2%>\n\
              <tr>\n\
                <td style=\"VERTICAL-ALIGN: top\"><p class=\"F2\">TO</p></td>\n\
                <td style=\"VERTICAL-ALIGN: top\"><br></td>\n\
              </tr>\n\
              <tr>\n\
                <td style=\"VERTICAL-ALIGN: top\"><pre><p class=F4>:to:</p></pre></td>\n\
                <td style=\"VERTICAL-ALIGN: top\"><br><br><br><br></td>\n\
              </tr>\n\
            </table>\n\
          </TD>\n\
          <TD style=\"VERTICAL-ALIGN: top\" colSpan=4>\n\
            <table width=100% border=0 cellpadding=0 cellspacing=0>\n\
              <col width = 98%><col width = 2%>\n\
              <tr>\n\
                <td style=\"VERTICAL-ALIGN: top; TEXT-ALIGN: center\">\n\
                  <p class=F2>THIS RADIO MESSAGE WAS RECEIVED AT</p>\n\
                </td>\n\
                <td style=\"VERTICAL-ALIGN: top\"><br></td>\n\
              </tr>\n\
              <tr>\n\
                <td style=\"VERTICAL-ALIGN: top\"><pre><p class=F4>:rx:</p><pre></td>\n\
                <td style=\"VERTICAL-ALIGN: top\"><br><br><br><br></td>\n\
              </tr>\n\
            </table>\n\
          </TD>\n\
        </TR>\n\
        <TR>\n\
          <TD style=\"VERTICAL-ALIGN: top\" colSpan=8>\n\
            <table width=100% border=0 cellpadding=0 cellspacing=0>\n\
              <col width = 98%><col width = 2%>\n\
              <tr>\n\
                <td VALIGN=top><p class=F2>PHONE NUMBER</p></td>\n\
                <td><br></td>\n\
              </tr>\n\
              <tr>\n\
                <td VALIGN=top><p class=F4>:tel:</p></td>\n\
              </tr>\n\
            </table>\n\
          </TD>\n\
        </TR>\n\
        <TR>\n\
          <TD style=\"VERTICAL-ALIGN: top\" colSpan=8>\n\
            <table width=100% border=0 cellpadding=0 cellspacing=0>\n\
              <col width = 98%><col width = 2%>\n\
              <tr>\n\
                <td VALIGN=top><pre><p class=F4>:msg:</p></pre></td>\n\
                <td><br><br><br><br><br><br><br><br></td>\n\
              </tr>\n\
              <tr>\n\
               <td VALIGN=top><p class=F4>:sig:</p></td>\n\
               <td><br></td>\n\
              </tr>\n\
            </table>\n\
        </TD>\n\
      </TR>\n\
      </TBODY>\n\
      </TABLE>\n\
      <TABLE style=\"TEXT-ALIGN: left; WIDTH: 100%\" border=0 cellSpacing=2 cellPadding=2>\n\
        <TBODY>\n\
        <TR>\n\
          <TD style=\"VERTICAL-ALIGN: top\">\n\
          <p class=F4>:exp:</p>\n\
        </TD>\n\
      </TR>\n\
      </TBODY>\n\
      </TABLE>\n\
    </TD>\n\
    </TR>\n\
    </TBODY>\n\
    </TABLE><BR>\n\
  </BODY>\n\
</HTML>\n\
";

const char rg_html_fcopy_template[] = 
"<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0 Transitional//EN\">\n\
<HTML><HEAD><TITLE>radiogram</TITLE>\n\
<META content=\"text/html; charset=ISO-8859-1\" http-equiv=content-type>\n\
<META name=author content=w1hkj>\n\
<STYLE type=\"text/css\">\n\
p.F2 { FONT-FAMILY: \"sans-serif\"; FONT-SIZE: 8pt }\n\
p.F3 { FONT-FAMILY: \"sans-serif\"; FONT-SIZE: 14pt }\n\
p.F4 { FONT-FAMILY: \"monospace\"; FONT-SIZE: 12pt }\n\
p.F5 { FONT-FAMILY: \"sans-serif\"; FONT-SIZE: 16pt }\n\
p.F6 { FONT-FAMILY: \"sans-serif\"; FONT-SIZE: 10pt }\n\
</STYLE>\n\
\n\
<META name=GENERATOR content=\"MSHTML 8.00.6001.19154\"></HEAD>\n\
<BODY>\n\
<TABLE style=\"TEXT-ALIGN: left; WIDTH: 100%\" border=0 cellSpacing=0 \n\
cellPadding=0>\n\
  <TBODY>\n\
  <TR>\n\
    <TD style=\"VERTICAL-ALIGN: top\">\n\
      <TABLE \n\
      style=\"TEXT-ALIGN: left; WIDTH: 100%; MARGIN-LEFT: auto; MARGIN-RIGHT: auto\" \n\
      border=0 cellSpacing=0 cellPadding=2>\n\
        <TBODY>\n\
        <TR>\n\
          <TD style=\"VERTICAL-ALIGN: top\">\n\
            <DIV style=\"TEXT-ALIGN: center\">\n\
            <FONT size=3><B>THE AMERICAN RADIO RELAY LEAGUE</B></FONT><BR>\n\
            </DIV>\n\
            <DIV style=\"TEXT-ALIGN: center\">\n\
            <FONT size=6><B>RADIOGRAM</B></FONT><BR>\n\
            </DIV>\n\
            <DIV style=\"TEXT-ALIGN: center\">\n\
            <FONT size=3><B>VIA AMATEUR RADIO<BR></B></FONT>\n\
            </DIV>\n\
          </TD>\n\
        </TR>\n\
        </TBODY>\n\
      </TABLE>\n\
      <TABLE style=\"TEXT-ALIGN: left; WIDTH: 100%\" border=1 cellSpacing=0 \n\
      cellPadding=2>\n\
        <TBODY>\n\
        <TR>\n\
          <TD style=\"TEXT-ALIGN: center; WIDTH: 7%; VERTICAL-ALIGN: top\">\n\
            <p class=F2>NUMBER</p>\n\
          </TD>\n\
          <TD style=\"TEXT-ALIGN: center; WIDTH: 14%; VERTICAL-ALIGN: top\">\n\
            <p class=F2>PRECEDENCE</p>\n\
          </TD>\n\
          <TD style=\"TEXT-ALIGN: center; WIDTH: 7%; VERTICAL-ALIGN: top\">\n\
            <p class=F2>HX</p>\n\
          </TD>\n\
          <TD style=\"TEXT-ALIGN: center; WIDTH: 20%; VERTICAL-ALIGN: top\">\n\
            <p class=F2>STATION OF ORIGIN</p>\n\
          </TD>\n\
          <TD style=\"TEXT-ALIGN: center; WIDTH: 8%; VERTICAL-ALIGN: top\">\n\
            <p class=F2>CHECK</p>\n\
          </TD>\n\
          <TD style=\"TEXT-ALIGN: center; WIDTH: 20%; VERTICAL-ALIGN: top\">\n\
            <p class=F2>PLACE OF ORIGIN</p>\n\
          </TD>\n\
          <TD style=\"TEXT-ALIGN: center; WIDTH: 10%; VERTICAL-ALIGN: top\">\n\
            <p class=F2>TIME FILED</p>\n\
          </TD>\n\
          <TD style=\"TEXT-ALIGN: center; VERTICAL-ALIGN: top\">\n\
            <p class=F2>DATE</p>\n\
          </TD>\n\
        </TR>\n\
        <TR>\n\
          <TD style=\"TEXT-ALIGN: center; VERTICAL-ALIGN: top\">\n\
            <p class=F4>:nbr:<br></p>\n\
          </TD>\n\
          <TD style=\"TEXT-ALIGN: center; VERTICAL-ALIGN: top\">\n\
            <p class=F4>:prec:<br></p>\n\
          </TD>\n\
          <TD style=\"TEXT-ALIGN: center; VERTICAL-ALIGN: top\">\n\
            <p class=F4>:hx:<br></p>\n\
          </TD>\n\
          <TD style=\"TEXT-ALIGN: center; VERTICAL-ALIGN: top\">\n\
            <p class=\"F4\">:sta:<br></p>\n\
          </TD>\n\
          <TD style=\"TEXT-ALIGN: center; VERTICAL-ALIGN: top\">\n\
            <p class=F4>:ck:<br></p>\n\
          </TD>\n\
          <TD style=\"TEXT-ALIGN: center; VERTICAL-ALIGN: top\">\n\
            <p class=F4>:org:<br></p>\n\
          </TD>\n\
          <TD style=\"TEXT-ALIGN: center; VERTICAL-ALIGN: top\">\n\
            <p class=F4>:t1:<br></p>\n\
          </TD>\n\
          <TD style=\"TEXT-ALIGN: center; VERTICAL-ALIGN: top\">\n\
            <p class=F4>:d1:<br></p>\n\
          </TD>\n\
        </TR>\n\
        <TR>\n\
          <TD style=\"VERTICAL-ALIGN: top\" colSpan=4>\n\
            <table width=100% border=0 cellpadding=0 cellspacing=0>\n\
              <col width = 98%><col width = 2%>\n\
              <tr>\n\
                <td style=\"VERTICAL-ALIGN: top\"><p class=\"F2\">TO</p></td>\n\
                <td style=\"VERTICAL-ALIGN: top\"><br></td>\n\
              </tr>\n\
              <tr>\n\
                <td style=\"VERTICAL-ALIGN: top\"><pre><p class=F4>:to:</p></pre></td>\n\
                <td style=\"VERTICAL-ALIGN: top\"><br><br><br><br></td>\n\
              </tr>\n\
            </table>\n\
          </TD>\n\
          <TD style=\"VERTICAL-ALIGN: top\" colSpan=4>\n\
            <table width=100% border=0 cellpadding=0 cellspacing=0>\n\
              <col width = 98%><col width = 2%>\n\
              <tr>\n\
                <td style=\"VERTICAL-ALIGN: top; TEXT-ALIGN: center\">\n\
                  <p class=F2>THIS RADIO MESSAGE WAS RECEIVED AT</p>\n\
                </td>\n\
                <td style=\"VERTICAL-ALIGN: top\"><br></td>\n\
              </tr>\n\
              <tr>\n\
                <td style=\"VERTICAL-ALIGN: top\"><pre><p class=F4>:rx:</p></pre></td>\n\
                <td style=\"VERTICAL-ALIGN: top\"><br><br><br><br></td>\n\
              </tr>\n\
            </table>\n\
          </TD>\n\
        </TR>\n\
        <TR>\n\
          <TD style=\"VERTICAL-ALIGN: top\" colSpan=8>\n\
            <table width=100% border=0 cellpadding=0 cellspacing=0>\n\
              <col width = 98%><col width = 2%>\n\
              <tr>\n\
                <td VALIGN=top><p class=F2>PHONE NUMBER</p></td>\n\
                <td><br></td>\n\
              </tr>\n\
              <tr>\n\
                <td VALIGN=top><p class=F4>:tel:</p></td>\n\
              </tr>\n\
            </table>\n\
          </TD>\n\
        </TR>\n\
        <TR>\n\
          <TD style=\"VERTICAL-ALIGN: top\" colSpan=8>\n\
            <table width=100% border=0 cellpadding=0 cellspacing=0>\n\
              <col width = 98%><col width = 2%>\n\
              <tr>\n\
                <td VALIGN=top><pre><p class=F4>:msg:</p></pre></td>\n\
                <td><br><br><br><br><br><br><br><br></td>\n\
              </tr>\n\
              <tr>\n\
               <td VALIGN=top><p class=F4>:sig:</p></td>\n\
               <td><br></td>\n\
              </tr>\n\
            </table>\n\
        </TD>\n\
      </TR>\n\
      </TBODY>\n\
      </TABLE>\n\
    </TD>\n\
    </TR>\n\
    </TBODY>\n\
    </TABLE><BR>\n\
    <table style=\"text-align: left; width: 100%;\" border=\"1\" cellpadding=\"2\" cellspacing=\"0\">\n\
    <tbody>\n\
    <tr>\n\
      <td VALIGN=top><p class=F4>ORIG - FROM / DATE/TIME: :ori:</p></td>\n\
    </tr>\n\
    <tr>\n\
      <td VALIGN=top><p class=F4>DLVD - TO / DATE/TIME: :dlv:</p></td>\n\
    </tr>\n\
    </tbody>\n\
    </table>\n\
</body>\n\
</html>";

const char rg_txt_template[] =
"Formated for CW/Voice: :std:\n\
:nbr: :prec::hx: :sta: :ck: :org: :t1: :d1:\n\
:to:\n\
:tel::opn:\n\
BT\n\
:msg:\n\
BT\n\
:sig::op2:\n\
AR\n\
";

