// ----------------------------------------------------------------------------
// < (C) 2014
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

#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <ctime>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <errno.h>

#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Check_Button.H>
#include <FL/fl_draw.H>
#include <FL/fl_ask.H>
#include <FL/Fl_Table_Row.H>
#include <FL/Fl_Browser.H>

Fl_Window *csv_table_editor_dialog = 0;
Fl_Browser *csv_browser = 0;

static void cb_btn_close_dialog(Fl_Button*, void*) {
	csv_table_editor_dialog->hide();
}

static int *cols;
static int ncols;

void csv_editor(std::string data)
{
	if (!csv_table_editor_dialog) {
		csv_table_editor_dialog = new Fl_Window(0, 0, 500, 300, "CSV Viewer");

// Add children to window
		csv_table_editor_dialog->begin();

		csv_browser = new Fl_Browser(5, 5, 490, 260, "");
		csv_browser->textsize(13);

		Fl_Button *close_dialog = new Fl_Button(405, 271, 80, 24, "Close");
		close_dialog->callback((Fl_Callback*)cb_btn_close_dialog);
		csv_table_editor_dialog->end();

		csv_table_editor_dialog->resizable(csv_browser);
	}

	int col = 0;
	int font = csv_browser->textfont();
	int fontsize = csv_browser->textsize();

	fl_font(font, fontsize);

	std::string line, field, temp;
	size_t p0, p1, p2;

	p0 = p1 = p2 = 0;

// replace commas with tab unless contained within a quoted std::string
	if (data[data.length()-1] != '\n') data += '\n';

	while ((p0 = data.find(",")) != std::string::npos)
		data.replace(p0, 1, "\t");

	p0 = 0;
	while ((p0 = data.find("\"", p0)) != std::string::npos) {
		p1 = data.find("\"", p0 + 1);
		if (p1 == std::string::npos) break;
		while ((p2 = data.find("\t", p0)) < p1) data.replace(p2, 1, ",");
		p0 = p1 + 1;
	}

	p0 = 0;
	while ((p0 = data.find("\"")) != std::string::npos) data.erase(p0, 1);

// count # columns
	temp = data;
	p0 = 0;
	int lcols;
	while ((p0 = temp.find("\n")) != std::string::npos) {
		line = temp.substr(0, p0);
		lcols = 0;
		p1 = 0;
		while ((p1 < line.length()) && ((p1 = line.find("\t", p1)) != std::string::npos)) {
			lcols++;
			p1++;
		}
		if (lcols > ncols) ncols = lcols;
		temp.erase(0, p0 + 1);
	}
	ncols += 2;  // columns are zero terminated so need extra column

	cols = new int[ncols];
	for (int i = 0; i < ncols; i++) cols[i] = 0;

// compute maximum size of columns
	temp = data;
	p0 = 0;
	while ((p0 = temp.find("\n")) != std::string::npos) {
		col = 0;
		line = temp.substr(0, p0);
		while (line.length() && (p1 = line.find("\t")) != std::string::npos) {
			field = line.substr(0, p1);
			if (field.length()) {
				field.append("W");
				int colw = fl_width(field.c_str()) + 4;
				if (colw > cols[col]) cols[col] = colw;
			}
			col++;
			line.erase(0, p1 + 1);
		} if (line.length()) {
			field.append("X");
			int colw = fl_width(line.c_str()) + 4;
			if (colw > cols[col]) cols[col] = colw;
		}
		temp.erase(0, p0 + 1);
	}
	if (temp.length()) {
		col = 0;
		while ((p1 = temp.find("\t")) != std::string::npos) {
			field = temp.substr(0, p1+1);
			temp.erase(p1 + 1);
			if (field.length()) {
				field.append("W");
				int colw = fl_width(field.c_str()) + 4;
				if (colw > cols[col]) cols[col] = colw;
			}
			col++;
		} if (temp.length()) {
			field.append("X");
			int colw = fl_width(temp.c_str()) + 4;
			if (colw > cols[col]) cols[col] = colw;
		}
	}

	int width = 0;
	for (int i = 0; i < ncols; i++) width += cols[i];
	width += csv_browser->scrollbar_size(); // space for vertical scrollbar
	width += 10;

	csv_table_editor_dialog->size(width + 10, csv_table_editor_dialog->h());
	csv_browser->size(width, csv_browser->h());

	csv_browser->column_widths((const int *)cols);
	csv_browser->clear();

	temp = data;
	while ((p0 = temp.find("\n")) != std::string::npos) {
		line = temp.substr(0, p0);
		csv_browser->add(line.c_str());
		temp.erase(0, p0 + 1);
	}
	if (temp.length()) {
		csv_browser->add(temp.c_str());
}

	csv_table_editor_dialog->show();
}
