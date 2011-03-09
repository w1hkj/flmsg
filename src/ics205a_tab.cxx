tab_ics205a = new Fl_Group(0, 70, 597, 355, _("205a"));
tab_ics205a->align(FL_ALIGN_TOP_LEFT);
tab_ics205a->hide();
	tab_ics205a_type = new Fl_Tabs(0, 72, 597, 352);
	tab_ics205a_type->align(FL_ALIGN_TOP_LEFT);
		tab_205a_1 = new Fl_Group(0, 95, 570, 325, _("Incident"));
			{
			Fl_Group* o = new Fl_Group(2, 102, 566, 135);
			o->box(FL_ENGRAVED_FRAME);
			o->align(FL_ALIGN_TOP_LEFT|FL_ALIGN_INSIDE);

				txt_205a_incident = new Fl_Input2(135, 108, 425, 24, _("Incident Name"));
				txt_205a_incident->tooltip(_("Incident name"));
				txt_205a_incident->box(FL_DOWN_BOX);
				txt_205a_incident->color((Fl_Color)FL_BACKGROUND2_COLOR);
				txt_205a_incident->selection_color((Fl_Color)FL_SELECTION_COLOR);
				txt_205a_incident->labeltype(FL_NORMAL_LABEL);
				txt_205a_incident->labelfont(0);
				txt_205a_incident->labelsize(14);
				txt_205a_incident->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
				txt_205a_incident->align(FL_ALIGN_LEFT);
				txt_205a_incident->when(FL_WHEN_RELEASE);

				txt_205a_date_fm = new Fl_Input2(135, 135, 155, 24, _("From date"));
				txt_205a_date_fm->tooltip(_("Starting date"));
				txt_205a_date_fm->box(FL_DOWN_BOX);
				txt_205a_date_fm->color((Fl_Color)FL_BACKGROUND2_COLOR);
				txt_205a_date_fm->selection_color((Fl_Color)FL_SELECTION_COLOR);
				txt_205a_date_fm->labeltype(FL_NORMAL_LABEL);
				txt_205a_date_fm->labelfont(0);
				txt_205a_date_fm->labelsize(14);
				txt_205a_date_fm->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
				txt_205a_date_fm->align(FL_ALIGN_LEFT);
				txt_205a_date_fm->when(FL_WHEN_RELEASE);

				btn_205a_date_fm = new Fl_Button(294, 137, 20, 20, _("..."));
				btn_205a_date_fm->tooltip(_("Set today"));
				btn_205a_date_fm->callback((Fl_Callback*)cb_205a_set_date_fm);

				txt_205a_time_fm = new Fl_Input2(135, 160, 103, 24, _("From time"));
				txt_205a_time_fm->tooltip(_("Starting time"));
				txt_205a_time_fm->box(FL_DOWN_BOX);
				txt_205a_time_fm->color((Fl_Color)FL_BACKGROUND2_COLOR);
				txt_205a_time_fm->selection_color((Fl_Color)FL_SELECTION_COLOR);
				txt_205a_time_fm->labeltype(FL_NORMAL_LABEL);
				txt_205a_time_fm->labelfont(0);
				txt_205a_time_fm->labelsize(14);
				txt_205a_time_fm->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
				txt_205a_time_fm->align(FL_ALIGN_LEFT);
				txt_205a_time_fm->when(FL_WHEN_RELEASE);

				btn_205a_time_fm = new Fl_Button(247, 162, 20, 20, _("..."));
				btn_205a_time_fm->tooltip(_("Set time now"));
				btn_205a_time_fm->callback((Fl_Callback*)cb_205a_set_time_fm);

				txt_205a_date_to = new Fl_Input2(135, 185, 155, 24, _("To date"));
				txt_205a_date_to->tooltip(_("Ending date"));
				txt_205a_date_to->box(FL_DOWN_BOX);
				txt_205a_date_to->color((Fl_Color)FL_BACKGROUND2_COLOR);
				txt_205a_date_to->selection_color((Fl_Color)FL_SELECTION_COLOR);
				txt_205a_date_to->labeltype(FL_NORMAL_LABEL);
				txt_205a_date_to->labelfont(0);
				txt_205a_date_to->labelsize(14);
				txt_205a_date_to->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
				txt_205a_date_to->align(FL_ALIGN_LEFT);
				txt_205a_date_to->when(FL_WHEN_RELEASE);

				btn_205a_date_to = new Fl_Button(294, 187, 20, 20, _("..."));
				btn_205a_date_to->tooltip(_("Set today"));
				btn_205a_date_to->callback((Fl_Callback*)cb_205a_set_date_to);

				txt_205a_time_to = new Fl_Input2(135, 210, 103, 24, _("To time"));
				txt_205a_time_to->tooltip(_("Ending time"));
				txt_205a_time_to->box(FL_DOWN_BOX);
				txt_205a_time_to->color((Fl_Color)FL_BACKGROUND2_COLOR);
				txt_205a_time_to->selection_color((Fl_Color)FL_SELECTION_COLOR);
				txt_205a_time_to->labeltype(FL_NORMAL_LABEL);
				txt_205a_time_to->labelfont(0);
				txt_205a_time_to->labelsize(14);
				txt_205a_time_to->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
				txt_205a_time_to->align(FL_ALIGN_LEFT);
				txt_205a_time_to->when(FL_WHEN_RELEASE);

				btn_205a_time_to = new Fl_Button(247, 212, 20, 20, _("..."));
				btn_205a_time_to->tooltip(_("Set time now"));
				btn_205a_time_to->callback((Fl_Callback*)cb_205a_set_time_to);

				o->end();
			} // Fl_Group* o

			{
			Fl_Group* o = new Fl_Group(2, 237, 566, 80);
				o->box(FL_ENGRAVED_FRAME);

				txt_205a_prepared_by = new Fl_Input2(135, 240, 425, 24, _("Prepared by"));
				txt_205a_prepared_by->tooltip(_("Name of preparer"));
				txt_205a_prepared_by->box(FL_DOWN_BOX);
				txt_205a_prepared_by->color((Fl_Color)FL_BACKGROUND2_COLOR);
				txt_205a_prepared_by->selection_color((Fl_Color)FL_SELECTION_COLOR);
				txt_205a_prepared_by->labeltype(FL_NORMAL_LABEL);
				txt_205a_prepared_by->labelfont(0);
				txt_205a_prepared_by->labelsize(14);
				txt_205a_prepared_by->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
				txt_205a_prepared_by->align(FL_ALIGN_LEFT);
				txt_205a_prepared_by->when(FL_WHEN_RELEASE);

				txt_205a_preparer_position = new Fl_Input2(135, 265, 425, 24, _("Position"));
				txt_205a_preparer_position->tooltip(_("Preparer's Position"));
				txt_205a_preparer_position->box(FL_DOWN_BOX);
				txt_205a_preparer_position->color((Fl_Color)FL_BACKGROUND2_COLOR);
				txt_205a_preparer_position->selection_color((Fl_Color)FL_SELECTION_COLOR);
				txt_205a_preparer_position->labeltype(FL_NORMAL_LABEL);
				txt_205a_preparer_position->labelfont(0);
				txt_205a_preparer_position->labelsize(14);
				txt_205a_preparer_position->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
				txt_205a_preparer_position->align(FL_ALIGN_LEFT);
				txt_205a_preparer_position->when(FL_WHEN_RELEASE);

				txt_205a_preparer_date_time = new Fl_Input2(135, 290, 425, 24, _("Date/Time"));
				txt_205a_preparer_date_time->tooltip(_("Date / Time"));
				txt_205a_preparer_date_time->box(FL_DOWN_BOX);
				txt_205a_preparer_date_time->color((Fl_Color)FL_BACKGROUND2_COLOR);
				txt_205a_preparer_date_time->selection_color((Fl_Color)FL_SELECTION_COLOR);
				txt_205a_preparer_date_time->labeltype(FL_NORMAL_LABEL);
				txt_205a_preparer_date_time->labelfont(0);
				txt_205a_preparer_date_time->labelsize(14);
				txt_205a_preparer_date_time->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
				txt_205a_preparer_date_time->align(FL_ALIGN_LEFT);
				txt_205a_preparer_date_time->when(FL_WHEN_RELEASE);

				o->end();
			} // Fl_Group* o

		tab_205a_1->end();

		tab_205a_2 = new Fl_Group(0, 95, 597, 325, _("Basic Info"));
		tab_205a_2->hide();

			{
			Fl_Box* o = new Fl_Box(5, 106, 120, 20, _("Assignment"));
			o->box(FL_DOWN_BOX);
			o->color((Fl_Color)215);
			} // Fl_Box* o

			{
			Fl_Box* o = new Fl_Box(126, 106, 150, 20, _("Name"));
			o->box(FL_DOWN_BOX);
			o->color((Fl_Color)215);
			} // Fl_Box* o

			{
			Fl_Box* o = new Fl_Box(277, 106, 270, 20, _("Method of Contact"));
				o->box(FL_DOWN_BOX);
				o->color((Fl_Color)215);
			} // Fl_Box* o

			{
			Fl_Scroll* o = new Fl_Scroll(4, 128, 560, 290);
				o->type(2);
				o->box(FL_DOWN_BOX);
				o->color((Fl_Color)215);
				for (int i = 0; i < 32; i++) {

					txt_205a_comm_position[i] = new Fl_Input2(5, 130 + i*24, 120, 24);
					txt_205a_comm_position[i]->tooltip(_(""));
					txt_205a_comm_position[i]->box(FL_DOWN_BOX);
					txt_205a_comm_position[i]->color((Fl_Color)FL_BACKGROUND2_COLOR);
					txt_205a_comm_position[i]->selection_color((Fl_Color)FL_SELECTION_COLOR);
					txt_205a_comm_position[i]->labeltype(FL_NORMAL_LABEL);
					txt_205a_comm_position[i]->labelfont(0);
					txt_205a_comm_position[i]->labelsize(14);
					txt_205a_comm_position[i]->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
					txt_205a_comm_position[i]->align(FL_ALIGN_CENTER);
					txt_205a_comm_position[i]->when(FL_WHEN_RELEASE);
					
					txt_205a_comm_name[i] = new Fl_Input2(126, 130 + i*24, 150, 24);
					txt_205a_comm_name[i]->tooltip(_(""));
					txt_205a_comm_name[i]->box(FL_DOWN_BOX);
					txt_205a_comm_name[i]->color((Fl_Color)FL_BACKGROUND2_COLOR);
					txt_205a_comm_name[i]->selection_color((Fl_Color)FL_SELECTION_COLOR);
					txt_205a_comm_name[i]->labeltype(FL_NORMAL_LABEL);
					txt_205a_comm_name[i]->labelfont(0);
					txt_205a_comm_name[i]->labelsize(14);
					txt_205a_comm_name[i]->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
					txt_205a_comm_name[i]->align(FL_ALIGN_CENTER);
					txt_205a_comm_name[i]->when(FL_WHEN_RELEASE);

					txt_205a_comm_info[i] = new Fl_Input2(277, 130 + i*24, 270, 24);
					txt_205a_comm_info[i]->tooltip(_(""));
					txt_205a_comm_info[i]->box(FL_DOWN_BOX);
					txt_205a_comm_info[i]->color((Fl_Color)FL_BACKGROUND2_COLOR);
					txt_205a_comm_info[i]->selection_color((Fl_Color)FL_SELECTION_COLOR);
					txt_205a_comm_info[i]->labeltype(FL_NORMAL_LABEL);
					txt_205a_comm_info[i]->labelfont(0);
					txt_205a_comm_info[i]->labelsize(14);
					txt_205a_comm_info[i]->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
					txt_205a_comm_info[i]->align(FL_ALIGN_CENTER);
					txt_205a_comm_info[i]->when(FL_WHEN_RELEASE);
				}
				o->end();
			} // Fl_Scroll* o
		tab_205a_2->end();

	tab_ics205a_type->end();
	Fl_Group::current()->resizable(tab_ics205a_type);
tab_ics205a->end();
