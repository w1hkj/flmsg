tab_ics205 = new Fl_Group(0, 70, 570, 355, _("205"));
tab_ics205->align(FL_ALIGN_TOP_LEFT);
tab_ics205->hide();
	{
	Fl_Group* o = new Fl_Group(2, 76, 566, 67);
	o->box(FL_ENGRAVED_FRAME);

	txt_205_name = new Fl_Input2(113, 80, 450, 24, _("Incident Name"));
	txt_205_name->tooltip(_(""));
	txt_205_name->box(FL_DOWN_BOX);
	txt_205_name->color((Fl_Color)FL_BACKGROUND2_COLOR);
	txt_205_name->selection_color((Fl_Color)FL_SELECTION_COLOR);
	txt_205_name->labeltype(FL_NORMAL_LABEL);
	txt_205_name->labelfont(0);
	txt_205_name->labelsize(14);
	txt_205_name->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
	txt_205_name->align(FL_ALIGN_LEFT);
	txt_205_name->when(FL_WHEN_RELEASE);

	txt_205_dt_prepared = new Fl_Input2(97, 112, 155, 24, _("DT/TM Prep\'"));
	txt_205_dt_prepared->tooltip(_("ddhhmm MMM YY of preparation"));
	txt_205_dt_prepared->box(FL_DOWN_BOX);
	txt_205_dt_prepared->color((Fl_Color)FL_BACKGROUND2_COLOR);
	txt_205_dt_prepared->selection_color((Fl_Color)FL_SELECTION_COLOR);
	txt_205_dt_prepared->labeltype(FL_NORMAL_LABEL);
	txt_205_dt_prepared->labelfont(0);
	txt_205_dt_prepared->labelsize(14);
	txt_205_dt_prepared->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
	txt_205_dt_prepared->align(FL_ALIGN_LEFT);
	txt_205_dt_prepared->when(FL_WHEN_RELEASE);

	btn_205DateTime1 = new Fl_Button(254, 112, 24, 24, _("..."));
	btn_205DateTime1->tooltip(_("Set today"));
	btn_205DateTime1->callback((Fl_Callback*)cb_btn_205DateTime1);

	txt_205_dt_operational = new Fl_Input2(378, 112, 155, 24, _("DT/TM Oper\'"));
	txt_205_dt_operational->tooltip(_("ddhhmm MMM YY of preparation"));
	txt_205_dt_operational->box(FL_DOWN_BOX);
	txt_205_dt_operational->color((Fl_Color)FL_BACKGROUND2_COLOR);
	txt_205_dt_operational->selection_color((Fl_Color)FL_SELECTION_COLOR);
	txt_205_dt_operational->labeltype(FL_NORMAL_LABEL);
	txt_205_dt_operational->labelfont(0);
	txt_205_dt_operational->labelsize(14);
	txt_205_dt_operational->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
	txt_205_dt_operational->align(FL_ALIGN_LEFT);
	txt_205_dt_operational->when(FL_WHEN_RELEASE);

	btn_205_DateTime2 = new Fl_Button(536, 112, 24, 24, _("..."));
	btn_205_DateTime2->tooltip(_("Set today"));
	btn_205_DateTime2->callback((Fl_Callback*)cb_btn_205_DateTime2);

	o->end();
	} // Fl_Group* o

	{
	Fl_Group* o = new Fl_Group(2, 145, 566, 245);
	o->box(FL_ENGRAVED_FRAME);
	for (int i = 0; i < 8; i++ ) {
		txt_205_type[i] = new Fl_Input2(5, 166 + i*28, 90, 24, i == 0 ? _("Sys\' / Cache"):"");
		txt_205_type[i]->tooltip(_(""));
		txt_205_type[i]->box(FL_DOWN_BOX);
		txt_205_type[i]->color((Fl_Color)FL_BACKGROUND2_COLOR);
		txt_205_type[i]->selection_color((Fl_Color)FL_SELECTION_COLOR);
		txt_205_type[i]->labeltype(FL_NORMAL_LABEL);
		txt_205_type[i]->labelfont(0);
		txt_205_type[i]->labelsize(14);
		txt_205_type[i]->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
		txt_205_type[i]->align(FL_ALIGN_TOP_LEFT);
		txt_205_type[i]->when(FL_WHEN_RELEASE);

		txt_205_channel[i] = new Fl_Input2(97, 166 + i*28, 63, 24, i == 0 ? _("Channel"):"");
		txt_205_channel[i]->tooltip(_(""));
		txt_205_channel[i]->box(FL_DOWN_BOX);
		txt_205_channel[i]->color((Fl_Color)FL_BACKGROUND2_COLOR);
		txt_205_channel[i]->selection_color((Fl_Color)FL_SELECTION_COLOR);
		txt_205_channel[i]->labeltype(FL_NORMAL_LABEL);
		txt_205_channel[i]->labelfont(0);
		txt_205_channel[i]->labelsize(14);
		txt_205_channel[i]->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
		txt_205_channel[i]->align(FL_ALIGN_TOP_LEFT);
		txt_205_channel[i]->when(FL_WHEN_RELEASE);

		txt_205_function[i] = new Fl_Input2(164, 166 + i*28, 80, 24, i == 0 ?_("Function"):"");
		txt_205_function[i]->tooltip(_(""));
		txt_205_function[i]->box(FL_DOWN_BOX);
		txt_205_function[i]->color((Fl_Color)FL_BACKGROUND2_COLOR);
		txt_205_function[i]->selection_color((Fl_Color)FL_SELECTION_COLOR);
		txt_205_function[i]->labeltype(FL_NORMAL_LABEL);
		txt_205_function[i]->labelfont(0);
		txt_205_function[i]->labelsize(14);
		txt_205_function[i]->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
		txt_205_function[i]->align(FL_ALIGN_TOP_LEFT);
		txt_205_function[i]->when(FL_WHEN_RELEASE);

		txt_205_freqtone[i] = new Fl_Input2(247, 166 + i*28, 80, 24, i == 0 ? _("Freq/Tone"):"");
		txt_205_freqtone[i]->tooltip(_(""));
		txt_205_freqtone[i]->box(FL_DOWN_BOX);
		txt_205_freqtone[i]->color((Fl_Color)FL_BACKGROUND2_COLOR);
		txt_205_freqtone[i]->selection_color((Fl_Color)FL_SELECTION_COLOR);
		txt_205_freqtone[i]->labeltype(FL_NORMAL_LABEL);
		txt_205_freqtone[i]->labelfont(0);
		txt_205_freqtone[i]->labelsize(14);
		txt_205_freqtone[i]->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
		txt_205_freqtone[i]->align(FL_ALIGN_TOP_LEFT);
		txt_205_freqtone[i]->when(FL_WHEN_RELEASE);

		txt_205_assignment[i] = new Fl_Input2(330, 166 + i*28, 90, 24, i == 0 ? _("Assignment"):"");
		txt_205_assignment[i]->tooltip(_(""));
		txt_205_assignment[i]->box(FL_DOWN_BOX);
		txt_205_assignment[i]->color((Fl_Color)FL_BACKGROUND2_COLOR);
		txt_205_assignment[i]->selection_color((Fl_Color)FL_SELECTION_COLOR);
		txt_205_assignment[i]->labeltype(FL_NORMAL_LABEL);
		txt_205_assignment[i]->labelfont(0);
		txt_205_assignment[i]->labelsize(14);
		txt_205_assignment[i]->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
		txt_205_assignment[i]->align(FL_ALIGN_TOP_LEFT);
		txt_205_assignment[i]->when(FL_WHEN_RELEASE);

		txt_205_remarks[i] = new Fl_Input2(422, 167 + i*28, 140, 24, i == 0 ? _("Remarks"):"");
		txt_205_remarks[i]->tooltip(_(""));
		txt_205_remarks[i]->box(FL_DOWN_BOX);
		txt_205_remarks[i]->color((Fl_Color)FL_BACKGROUND2_COLOR);
		txt_205_remarks[i]->selection_color((Fl_Color)FL_SELECTION_COLOR);
		txt_205_remarks[i]->labeltype(FL_NORMAL_LABEL);
		txt_205_remarks[i]->labelfont(0);
		txt_205_remarks[i]->labelsize(14);
		txt_205_remarks[i]->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
		txt_205_remarks[i]->align(FL_ALIGN_TOP_LEFT);
		txt_205_remarks[i]->when(FL_WHEN_RELEASE);
	}
	o->end();
	} // Fl_Group* o

	{
	Fl_Group* o = new Fl_Group(2, 391, 566, 30);
	o->box(FL_ENGRAVED_BOX);
	txt_205_preparer = new Fl_Input2(77, 394, 485, 24, _("Preparer:"));
	txt_205_preparer->tooltip(_("Addressee"));
	txt_205_preparer->box(FL_DOWN_BOX);
	txt_205_preparer->color((Fl_Color)FL_BACKGROUND2_COLOR);
	txt_205_preparer->selection_color((Fl_Color)FL_SELECTION_COLOR);
	txt_205_preparer->labeltype(FL_NORMAL_LABEL);
	txt_205_preparer->labelfont(0);
	txt_205_preparer->labelsize(14);
	txt_205_preparer->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
	txt_205_preparer->align(FL_ALIGN_LEFT);
	txt_205_preparer->when(FL_WHEN_RELEASE);
	o->end();
	} // Fl_Group* o
tab_ics205->end();

