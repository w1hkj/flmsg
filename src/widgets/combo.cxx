// ----------------------------------------------------------------------------
// Copyright (C) 2014
//              David Freese, W1HKJ
//
// This file is part of flmsg
//
// flrig is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 3 of the License, or
// (at your option) any later version.
//
// flrig is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.
// ----------------------------------------------------------------------------

#include <string>

#include <cstring>
#include <cstdlib>
#include <FL/Fl.H>
#include <FL/fl_draw.H>

#include "combo.h"
#include "util.h"

void popbrwsr_cb (Fl_Widget *v, long d);

Fl_PopBrowser::Fl_PopBrowser (int X, int Y, int W, int H, const char *label)
 : Fl_Window (X, Y, W, H, label)
{
	hRow  = H;
	wRow  = W;
	clear_border();
	box(FL_BORDER_BOX);
	align(FL_ALIGN_INSIDE);
	LABEL = label;
	LABEL.append(".brwsr");
	popbrwsr = new Fl_Select_Browser(0,0,wRow,hRow, LABEL.c_str());//0);
	popbrwsr->callback ( (Fl_Callback*)popbrwsr_cb);
	popbrwsr->align(FL_ALIGN_INSIDE);
	parentCB = 0;
	end();
	set_modal();
}

Fl_PopBrowser::~Fl_PopBrowser ()
{
	delete popbrwsr;
}

int Fl_PopBrowser::handle(int event)
{
	if (!Fl::event_inside( child(0) ) && event == FL_PUSH) {
		pophide();
		return 1;
 	}
	return Fl_Group::handle(event);
}

void Fl_PopBrowser::add(char *s, void *d)
{
	popbrwsr->add(s,d);
}

void Fl_PopBrowser::clear()
{
	popbrwsr->clear();
}

void Fl_PopBrowser::sort()
{
	return;
}

void Fl_PopBrowser::popshow (int x, int y)
{
	int nRows = parentCB->numrows();
	int fh = fl_height();
	int height = nRows * fh + 4;

	if (popbrwsr->size() == 0) return;
	if (nRows > parentCB->lsize()) nRows = parentCB->lsize();

// locate first occurance of Output string value in the list
// and display that if found
	int i = parentCB->index();
	if (!(i >= 0 && i < parentCB->listsize)) {
		for (i = 0; i < parentCB->listsize; i++)
			if (!strcmp(parentCB->Output->value(), parentCB->datalist[i]->s))
				break;
		if (i == parentCB->listsize)
			i = 0;
	}

// resize and reposition the popup to insure that it is within the bounds
// of the uppermost parent widget
// preferred position is just below and at the same x position as the
// parent widget

	Fl_Widget *gparent = parentCB;
	int hp = gparent->h();

	while ((gparent = gparent->parent())) {
		hp = gparent->h();
		parentWindow = gparent;
	}

	int nu = nRows, nl = nRows;
	int hu = nu * fh + 4, hl = nl * fh + 4;
	int yu = parentCB->y() - hu;
	int yl = y;

	while (nl > 1 && (yl + hl > hp)) { nl--; hl -= fh; }
	while (nu > 1 && yu < 0) { nu--; yu += fh; hu -= fh; }

	y = yl; height = hl;
	if (nl < nu) {
		y = yu;
		height = hu;
	}

	popbrwsr->size (wRow, height);
	resize (x, y, wRow, height);

	popbrwsr->topline (i);

	popbrwsr->show();
	show();
	for (const Fl_Widget* o = popbrwsr; o; o = o->parent())
		((Fl_Widget *)o)->set_visible();

//printf("%s (%p): x %d, y %d, w %d, h %d\n", parentWindow->label(), parentWindow,
//parentWindow->x(), parentWindow->y(), parentWindow->w(), parentWindow->h());

//for (const Fl_Widget* o = popbrwsr; o; o = o->parent()) 
//	printf("%20s (%p), visible %d\n", o->label(), o, o->visible());

	parentWindow->damage(FL_DAMAGE_ALL);
	parentWindow->redraw();

	Fl::grab(this);
}

void Fl_PopBrowser::pophide ()
{
//printf("hide\n");
	hide ();

	parentWindow->damage(FL_DAMAGE_ALL);
	parentWindow->redraw();

	Fl::grab(0);
}   

void Fl_PopBrowser::popbrwsr_cb_i (Fl_Widget *v, long d)
{
	Fl_Select_Browser *SB = (Fl_Select_Browser *)(v);
	Fl_PopBrowser *PB = (Fl_PopBrowser *)(SB->parent());
	Fl_ComboBox *CB = (Fl_ComboBox *)(PB->parent());

//printf("%s ==> %s ==> %s\n", SB->label(), PB->label(), CB->label());

// update the return values
	int row = SB->value();
//printf("callback row %d\n", row);

	if (row == 0) return;
	SB->deselect();

	CB->value(SB->text(row));
	CB->idx = row - 1;

	PB->pophide();

	CB->do_callback();

	return;
}

void popbrwsr_cb (Fl_Widget *v, long d)
{
	((Fl_PopBrowser *)(v))->popbrwsr_cb_i (v, d);
	return;
}


void Fl_ComboBox::fl_popbrwsr(Fl_Widget *p)
{
	int xpos = p->x(), ypos = p->h() + p->y();
// pass the calling widget to the popup browser so that the
// correct callback function can be called when the user selects an item
// from the browser list
	Brwsr->parentCB = (Fl_ComboBox *) p;
	Brwsr->popshow(xpos, ypos);
	return;
}

void btnComboBox_cb (Fl_Widget *v, void *d)
{
	Fl_Widget *p = v->parent();
	((Fl_ComboBox *)p)->fl_popbrwsr (p);
	return;
}


Fl_ComboBox::Fl_ComboBox (int X,int Y,int W,int H, const char *lbl)
 : Fl_Group (X, Y, W, H, lbl)
{
	width = W; height = H - 4;
	Btn = new Fl_Button (X + W - 18, Y + 1, 18, H - 2, "@#-32>");
	Btn->callback ((Fl_Callback *)btnComboBox_cb, 0);
	Output = new Fl_Input (X, Y, W-18, H, "cb_output");
	Output->align(FL_ALIGN_INSIDE);

	Brwsr = 0;
	datalist = new datambr *[FL_COMBO_LIST_INCR];
	maxsize = FL_COMBO_LIST_INCR;
	for (int i = 0; i < FL_COMBO_LIST_INCR; i++) datalist[i] = 0;
	listsize = 0;
	listtype = 0;

	LABEL = lbl;
	LABEL.append(".popup");
	Brwsr = new Fl_PopBrowser(X, Y, W, H, LABEL.c_str());
	Brwsr->align(FL_ALIGN_INSIDE);

	idx = 0;

	end();

	numrows_ = 8;
}

Fl_ComboBox::~Fl_ComboBox()
{
	delete Brwsr;
	for (int i = 0; i < listsize; i++) {
		if (datalist[i]) {
			if (datalist[i]->s) delete [] datalist[i]->s;
			delete datalist[i];
		}
	}
	delete [] datalist;
}

void Fl_ComboBox::type (int t)
{
	listtype = t;
}

void Fl_ComboBox::readonly()
{
	Output->type(FL_NORMAL_OUTPUT);
}

// ComboBox value is contained in the Output widget

void Fl_ComboBox::value( const char *s )
{
	int i;
	if ((listtype & FL_COMBO_UNIQUE_NOCASE) == FL_COMBO_UNIQUE_NOCASE) {
		for (i = 0; i < listsize; i++) {
			if (strcasecmp (s, datalist[i]->s) == 0)
				break;
		}
	} else {
		for (i = 0; i < listsize; i++) {
			if (strcmp (s, datalist[i]->s) == 0)
				break;
		}
	}
	if ( i < listsize) {
		Output->value(datalist[i]->s);
		idx = i;
	}
}

void Fl_ComboBox::put_value(const char *s)
{
	value(s);
}

void Fl_ComboBox::index(int i)
{
	if (i >= 0 && i < listsize)
		Output->value( datalist[idx = i]->s);
}


const char *Fl_ComboBox::value()
{
	return (Output->value ());
}

int Fl_ComboBox::index() {
	return idx;
}

void * Fl_ComboBox::data() {
	return retdata; 
}

void Fl_ComboBox::add( const char *s, void * d)
{
// test for uniqueness of entry if required
	if ((listtype & FL_COMBO_UNIQUE) == FL_COMBO_UNIQUE) {
		if ((listtype & FL_COMBO_UNIQUE_NOCASE) == FL_COMBO_UNIQUE_NOCASE) {
			for (int i = 0; i < listsize; i++) {
				if (strcasecmp (s, datalist[i]->s) == 0)
				return;
			}
		} else {
			for (int i = 0; i < listsize; i++) {
				if (strcmp (s, datalist[i]->s) == 0)
				return;
			}
		}
	}
// not unique or not in list, so add this entry
	datalist[listsize] = new datambr;
	datalist[listsize]->s = new char [strlen(s) + 1];
	datalist[listsize]->s[0] = 0;
	strcpy (datalist[listsize]->s, s);
	datalist[listsize]->d = d;
	Brwsr->add(datalist[listsize]->s,d);
	listsize++;
	if (listsize == maxsize) {
		int nusize = maxsize + FL_COMBO_LIST_INCR;
		datambr **temparray = new datambr *[nusize];
		for (int i = 0; i < listsize; i++)	temparray[i] = datalist[i];
		delete [] datalist;
		datalist = temparray;
		maxsize = nusize;
	}
}

void Fl_ComboBox::clear()
{
	Brwsr->clear();
	
	if (listsize == 0) return;
	for (int i = 0; i < listsize; i++) {
		delete [] datalist[i]->s;
		delete datalist[i];
	}
	listsize = 0;
}

int DataCompare( const void *x1, const void *x2 )
{
	int cmp;
	datambr *X1, *X2;
	X1 = *(datambr **)(x1);
	X2 = *(datambr **)(x2);
	cmp = strcasecmp (X1->s, X2->s);
	if (cmp < 0)
		return -1;
	if (cmp > 0)
		return 1;
	return 0;
}

void Fl_ComboBox::sort() {
	Brwsr->clear ();
	qsort (&datalist[0],
		 listsize,
		 sizeof (datambr *),
		 DataCompare);
	for (int i = 0; i < listsize; i++)
		Brwsr->add (datalist[i]->s, datalist[i]->d);
}

void Fl_ComboBox::textfont (int fnt)
{
	Output->textfont (fnt);
}

void Fl_ComboBox::textsize (uchar n)
{
	Output->textsize (n);
}

void Fl_ComboBox::textcolor( Fl_Color c)
{
	Output->textcolor (c);
}

void Fl_ComboBox::color(Fl_Color c)
{
	_color = c;
	Output->color(c);
	if (Brwsr) Brwsr->color(c);
}



