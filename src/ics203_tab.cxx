			{ tab_ics203 = new Fl_Group(0, 70, 607, 355, _("203"));
			tab_ics203->align(FL_ALIGN_TOP_LEFT);
			tab_ics203_type = new Fl_Tabs(0, 73, 607, 352);
			tab_ics203_type->selection_color((Fl_Color)246);
			tab_ics203_type->align(FL_ALIGN_TOP_LEFT);
				{ // tab_203_orglist
				tab_203_1 = new Fl_Group(0, 95, 570, 325, _("Org List"));
					{ // group_203_orglist_1
					Fl_Group* group_203_orglist_1 = new Fl_Group(2, 101, 566, 115);
					group_203_orglist_1->box(FL_ENGRAVED_FRAME);
					group_203_orglist_1->align(FL_ALIGN_TOP_LEFT|FL_ALIGN_INSIDE);
					{	txt_203_incident = new Fl_Input2(135, 107, 425, 24, _("1. Incident Name"));
						txt_203_incident->tooltip(_("Incident name"));
						txt_203_incident->box(FL_DOWN_BOX);
						txt_203_incident->color((Fl_Color)FL_BACKGROUND2_COLOR);
						txt_203_incident->selection_color((Fl_Color)FL_SELECTION_COLOR);
						txt_203_incident->labeltype(FL_NORMAL_LABEL);
						txt_203_incident->labelfont(0);
						txt_203_incident->labelsize(14);
						txt_203_incident->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
						txt_203_incident->align(FL_ALIGN_LEFT);
						txt_203_incident->when(FL_WHEN_RELEASE);
					} // Fl_Input2* txt_203_incident
					{	txt_203_date = new Fl_Input2(135, 134, 155, 24, _("2. Date Prepared"));
						txt_203_date->tooltip(_("Date prepared"));
						txt_203_date->box(FL_DOWN_BOX);
						txt_203_date->color((Fl_Color)FL_BACKGROUND2_COLOR);
						txt_203_date->selection_color((Fl_Color)FL_SELECTION_COLOR);
						txt_203_date->labeltype(FL_NORMAL_LABEL);
						txt_203_date->labelfont(0);
						txt_203_date->labelsize(14);
						txt_203_date->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
						txt_203_date->align(FL_ALIGN_LEFT);
						txt_203_date->when(FL_WHEN_RELEASE);
					} // Fl_Input2* txt_203_date
					{	btn_203_date = new Fl_Button(294, 136, 20, 20, _("..."));
						btn_203_date->tooltip(_("Set today"));
						btn_203_date->callback((Fl_Callback*)cb_btn_203_date);
					} // Fl_Button* btn_203_date
					{	txt_203_time = new Fl_Input2(135, 159, 103, 24, _("3. Time Prepared"));
						txt_203_time->tooltip(_("Time prepared"));
						txt_203_time->box(FL_DOWN_BOX);
						txt_203_time->color((Fl_Color)FL_BACKGROUND2_COLOR);
						txt_203_time->selection_color((Fl_Color)FL_SELECTION_COLOR);
						txt_203_time->labeltype(FL_NORMAL_LABEL);
						txt_203_time->labelfont(0);
						txt_203_time->labelsize(14);
						txt_203_time->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
						txt_203_time->align(FL_ALIGN_LEFT);
						txt_203_time->when(FL_WHEN_RELEASE);
					} // Fl_Input2* txt_203_time
					{	btn_203_time = new Fl_Button(247, 161, 20, 20, _("..."));
						btn_203_time->tooltip(_("Set time now"));
						btn_203_time->callback((Fl_Callback*)cb_btn_203_time);
					} // Fl_Button* btn_203_time
					{	txt_203_op_period = new Fl_Input2(135, 187, 425, 24, _("4. Oper\' Period"));
						txt_203_op_period->tooltip(_("Date / Time"));
						txt_203_op_period->box(FL_DOWN_BOX);
						txt_203_op_period->color((Fl_Color)FL_BACKGROUND2_COLOR);
						txt_203_op_period->selection_color((Fl_Color)FL_SELECTION_COLOR);
						txt_203_op_period->labeltype(FL_NORMAL_LABEL);
						txt_203_op_period->labelfont(0);
						txt_203_op_period->labelsize(14);
						txt_203_op_period->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
						txt_203_op_period->align(FL_ALIGN_LEFT);
						txt_203_op_period->when(FL_WHEN_RELEASE);
					} // Fl_Input2* txt_203_op_period
					group_203_orglist_1->end();
					} // group_203_orglist_1
					{ // group_203_orglist_2
					Fl_Group* group_203_orglist_2 = new Fl_Group(2, 217, 566, 167, _("Incident Command and Staff"));
					group_203_orglist_2->box(FL_ENGRAVED_FRAME);
					group_203_orglist_2->align(FL_ALIGN_TOP|FL_ALIGN_INSIDE);
						txt_203_incident_commander = new Fl_Input2(133, 238, 425, 24, _("Commander"));
						txt_203_incident_commander->tooltip(_("Incident name"));
						txt_203_incident_commander->box(FL_DOWN_BOX);
						txt_203_incident_commander->color((Fl_Color)FL_BACKGROUND2_COLOR);
						txt_203_incident_commander->selection_color((Fl_Color)FL_SELECTION_COLOR);
						txt_203_incident_commander->labeltype(FL_NORMAL_LABEL);
						txt_203_incident_commander->labelfont(0);
						txt_203_incident_commander->labelsize(14);
						txt_203_incident_commander->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
						txt_203_incident_commander->align(FL_ALIGN_LEFT);
						txt_203_incident_commander->when(FL_WHEN_RELEASE);

						txt_203_incident_deputy = new Fl_Input2(133, 267, 425, 24, _("Deputy"));
						txt_203_incident_deputy->tooltip(_("Incident name"));
						txt_203_incident_deputy->box(FL_DOWN_BOX);
						txt_203_incident_deputy->color((Fl_Color)FL_BACKGROUND2_COLOR);
						txt_203_incident_deputy->selection_color((Fl_Color)FL_SELECTION_COLOR);
						txt_203_incident_deputy->labeltype(FL_NORMAL_LABEL);
						txt_203_incident_deputy->labelfont(0);
						txt_203_incident_deputy->labelsize(14);
						txt_203_incident_deputy->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
						txt_203_incident_deputy->align(FL_ALIGN_LEFT);
						txt_203_incident_deputy->when(FL_WHEN_RELEASE);

						txt_203_incident_safety_officer = new Fl_Input2(133, 296, 425, 24, _("Safety Officer"));
						txt_203_incident_safety_officer->tooltip(_("Incident name"));
						txt_203_incident_safety_officer->box(FL_DOWN_BOX);
						txt_203_incident_safety_officer->color((Fl_Color)FL_BACKGROUND2_COLOR);
						txt_203_incident_safety_officer->selection_color((Fl_Color)FL_SELECTION_COLOR);
						txt_203_incident_safety_officer->labeltype(FL_NORMAL_LABEL);
						txt_203_incident_safety_officer->labelfont(0);
						txt_203_incident_safety_officer->labelsize(14);
						txt_203_incident_safety_officer->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
						txt_203_incident_safety_officer->align(FL_ALIGN_LEFT);
						txt_203_incident_safety_officer->when(FL_WHEN_RELEASE);

						txt_203_incident_info_officer = new Fl_Input2(133, 325, 425, 24, _("Information Off\'"));
						txt_203_incident_info_officer->tooltip(_("Incident name"));
						txt_203_incident_info_officer->box(FL_DOWN_BOX);
						txt_203_incident_info_officer->color((Fl_Color)FL_BACKGROUND2_COLOR);
						txt_203_incident_info_officer->selection_color((Fl_Color)FL_SELECTION_COLOR);
						txt_203_incident_info_officer->labeltype(FL_NORMAL_LABEL);
						txt_203_incident_info_officer->labelfont(0);
						txt_203_incident_info_officer->labelsize(14);
						txt_203_incident_info_officer->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
						txt_203_incident_info_officer->align(FL_ALIGN_LEFT);
						txt_203_incident_info_officer->when(FL_WHEN_RELEASE);

						txt_203_liaison_officer = new Fl_Input2(133, 355, 425, 24, _("Liaison Officer"));
						txt_203_liaison_officer->tooltip(_("Incident name"));
						txt_203_liaison_officer->box(FL_DOWN_BOX);
						txt_203_liaison_officer->color((Fl_Color)FL_BACKGROUND2_COLOR);
						txt_203_liaison_officer->selection_color((Fl_Color)FL_SELECTION_COLOR);
						txt_203_liaison_officer->labeltype(FL_NORMAL_LABEL);
						txt_203_liaison_officer->labelfont(0);
						txt_203_liaison_officer->labelsize(14);
						txt_203_liaison_officer->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
						txt_203_liaison_officer->align(FL_ALIGN_LEFT);
						txt_203_liaison_officer->when(FL_WHEN_RELEASE);

					group_203_orglist_2->end();
					} // group_203_orglist_2
					{ // group_203_orglist_3
					Fl_Group* group_203_orglist_3 = new Fl_Group(2, 385, 565, 35);
					group_203_orglist_3->box(FL_ENGRAVED_FRAME);
						txt_203_prepared_by = new Fl_Input2(133, 389, 425, 24, _("Prepared By"));
						txt_203_prepared_by->tooltip(_("Incident name"));
						txt_203_prepared_by->box(FL_DOWN_BOX);
						txt_203_prepared_by->color((Fl_Color)FL_BACKGROUND2_COLOR);
						txt_203_prepared_by->selection_color((Fl_Color)FL_SELECTION_COLOR);
						txt_203_prepared_by->labeltype(FL_NORMAL_LABEL);
						txt_203_prepared_by->labelfont(0);
						txt_203_prepared_by->labelsize(14);
						txt_203_prepared_by->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
						txt_203_prepared_by->align(FL_ALIGN_LEFT);
						txt_203_prepared_by->when(FL_WHEN_RELEASE);
					group_203_orglist_3->end();
					} // group_203_orglist_3
				tab_203_1->end();
				} // Fl_Group* tab_203_orglist
				{ // tab_203_agency
				tab_203_agency = new Fl_Group(0, 95, 570, 325, _("Agency"));
				tab_203_agency->hide();
				{ Fl_Group* o = new Fl_Group(2, 106, 566, 314, _("Agency Representatives"));
				o->box(FL_ENGRAVED_FRAME);
				o->align(FL_ALIGN_TOP_LEFT|FL_ALIGN_INSIDE);
				for (int i = 0; i < 7; i++) {
					txt_203_agency[i] = new Fl_Input2(11, 149 + 39*i, 275, 24, _("Agency"));
					txt_203_agency[i]->tooltip(_("Incident name"));
					txt_203_agency[i]->box(FL_DOWN_BOX);
					txt_203_agency[i]->color((Fl_Color)FL_BACKGROUND2_COLOR);
					txt_203_agency[i]->selection_color((Fl_Color)FL_SELECTION_COLOR);
					txt_203_agency[i]->labeltype(FL_NORMAL_LABEL);
					txt_203_agency[i]->labelfont(0);
					txt_203_agency[i]->labelsize(14);
					txt_203_agency[i]->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
					txt_203_agency[i]->align(FL_ALIGN_TOP);
					txt_203_agency[i]->when(FL_WHEN_RELEASE);

					txt_203_agency_name[i] = new Fl_Input2(290, 149 + 39*i, 275, 24, _("Name"));
					txt_203_agency_name[i]->tooltip(_("Incident name"));
					txt_203_agency_name[i]->box(FL_DOWN_BOX);
					txt_203_agency_name[i]->color((Fl_Color)FL_BACKGROUND2_COLOR);
					txt_203_agency_name[i]->selection_color((Fl_Color)FL_SELECTION_COLOR);
					txt_203_agency_name[i]->labeltype(FL_NORMAL_LABEL);
					txt_203_agency_name[i]->labelfont(0);
					txt_203_agency_name[i]->labelsize(14);
					txt_203_agency_name[i]->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
					txt_203_agency_name[i]->align(FL_ALIGN_TOP);
					txt_203_agency_name[i]->when(FL_WHEN_RELEASE);
				}
				o->end();
				} // Fl_Group* o
				tab_203_agency->end();
			  } // Fl_Group* tab_203_agency
				{ // tab_203_planning
				tab_203_planning = new Fl_Group(0, 95, 570, 325, _("Planning"));
				tab_203_planning->hide();
				{ Fl_Group* o = new Fl_Group(2, 101, 566, 289, _("Planning Section"));
				o->box(FL_ENGRAVED_FRAME);
				o->align(FL_ALIGN_TOP_LEFT|FL_ALIGN_INSIDE);
					txt_203_planning_chief = new Fl_Input2(158, 122, 400, 24, _("Chief"));
					txt_203_planning_chief->tooltip(_("Incident name"));
					txt_203_planning_chief->box(FL_DOWN_BOX);
					txt_203_planning_chief->color((Fl_Color)FL_BACKGROUND2_COLOR);
					txt_203_planning_chief->selection_color((Fl_Color)FL_SELECTION_COLOR);
					txt_203_planning_chief->labeltype(FL_NORMAL_LABEL);
					txt_203_planning_chief->labelfont(0);
					txt_203_planning_chief->labelsize(14);
					txt_203_planning_chief->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
					txt_203_planning_chief->align(FL_ALIGN_LEFT);
					txt_203_planning_chief->when(FL_WHEN_RELEASE);

					txt_203_planning_deputy = new Fl_Input2(158, 151, 400, 24, _("Deputy"));
					txt_203_planning_deputy->tooltip(_("Incident name"));
					txt_203_planning_deputy->box(FL_DOWN_BOX);
					txt_203_planning_deputy->color((Fl_Color)FL_BACKGROUND2_COLOR);
					txt_203_planning_deputy->selection_color((Fl_Color)FL_SELECTION_COLOR);
					txt_203_planning_deputy->labeltype(FL_NORMAL_LABEL);
					txt_203_planning_deputy->labelfont(0);
					txt_203_planning_deputy->labelsize(14);
					txt_203_planning_deputy->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
					txt_203_planning_deputy->align(FL_ALIGN_LEFT);
					txt_203_planning_deputy->when(FL_WHEN_RELEASE);

					txt_203_resources_unit = new Fl_Input2(158, 181, 400, 24, _("Resources Unit"));
					txt_203_resources_unit->tooltip(_("Incident name"));
					txt_203_resources_unit->box(FL_DOWN_BOX);
					txt_203_resources_unit->color((Fl_Color)FL_BACKGROUND2_COLOR);
					txt_203_resources_unit->selection_color((Fl_Color)FL_SELECTION_COLOR);
					txt_203_resources_unit->labeltype(FL_NORMAL_LABEL);
					txt_203_resources_unit->labelfont(0);
					txt_203_resources_unit->labelsize(14);
					txt_203_resources_unit->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
					txt_203_resources_unit->align(FL_ALIGN_LEFT);
					txt_203_resources_unit->when(FL_WHEN_RELEASE);

					txt_203_situation_unit = new Fl_Input2(158, 210, 400, 24, _("Situation Unit"));
					txt_203_situation_unit->tooltip(_("Incident name"));
					txt_203_situation_unit->box(FL_DOWN_BOX);
					txt_203_situation_unit->color((Fl_Color)FL_BACKGROUND2_COLOR);
					txt_203_situation_unit->selection_color((Fl_Color)FL_SELECTION_COLOR);
					txt_203_situation_unit->labeltype(FL_NORMAL_LABEL);
					txt_203_situation_unit->labelfont(0);
					txt_203_situation_unit->labelsize(14);
					txt_203_situation_unit->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
					txt_203_situation_unit->align(FL_ALIGN_LEFT);
					txt_203_situation_unit->when(FL_WHEN_RELEASE);

					txt_203_documentation_unit = new Fl_Input2(158, 240, 400, 24, _("Documentation Unit"));
					txt_203_documentation_unit->tooltip(_("Incident name"));
					txt_203_documentation_unit->box(FL_DOWN_BOX);
					txt_203_documentation_unit->color((Fl_Color)FL_BACKGROUND2_COLOR);
					txt_203_documentation_unit->selection_color((Fl_Color)FL_SELECTION_COLOR);
					txt_203_documentation_unit->labeltype(FL_NORMAL_LABEL);
					txt_203_documentation_unit->labelfont(0);
					txt_203_documentation_unit->labelsize(14);
					txt_203_documentation_unit->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
					txt_203_documentation_unit->align(FL_ALIGN_LEFT);
					txt_203_documentation_unit->when(FL_WHEN_RELEASE);

					txt_203_demobilization_unit = new Fl_Input2(158, 269, 400, 24, _("Demobilization Unit"));
					txt_203_demobilization_unit->tooltip(_("Incident name"));
					txt_203_demobilization_unit->box(FL_DOWN_BOX);
					txt_203_demobilization_unit->color((Fl_Color)FL_BACKGROUND2_COLOR);
					txt_203_demobilization_unit->selection_color((Fl_Color)FL_SELECTION_COLOR);
					txt_203_demobilization_unit->labeltype(FL_NORMAL_LABEL);
					txt_203_demobilization_unit->labelfont(0);
					txt_203_demobilization_unit->labelsize(14);
					txt_203_demobilization_unit->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
					txt_203_demobilization_unit->align(FL_ALIGN_LEFT);
					txt_203_demobilization_unit->when(FL_WHEN_RELEASE);

					for (int i = 0; i < 3; i++) {
						txt_203_tech_spc[i] = new Fl_Input2(158, 299 + i*29, 400, 24, _("Technical Specialist"));
						txt_203_tech_spc[i]->tooltip(_("Name"));
						txt_203_tech_spc[i]->box(FL_DOWN_BOX);
						txt_203_tech_spc[i]->color((Fl_Color)FL_BACKGROUND2_COLOR);
						txt_203_tech_spc[i]->selection_color((Fl_Color)FL_SELECTION_COLOR);
						txt_203_tech_spc[i]->labeltype(FL_NORMAL_LABEL);
						txt_203_tech_spc[i]->labelfont(0);
						txt_203_tech_spc[i]->labelsize(14);
						txt_203_tech_spc[i]->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
						txt_203_tech_spc[i]->align(FL_ALIGN_LEFT);
						txt_203_tech_spc[i]->when(FL_WHEN_RELEASE);
					} // Fl_Input2* txt_203_tech_spc[i]
					o->end();
					} // Fl_Group* o
				tab_203_planning->end();
				} // tab_203_planning
				{ // tab_203_logistics
				tab_203_logistics = new Fl_Group(0, 95, 570, 325, _("Logistics"));
				tab_203_logistics->hide();
				{ Fl_Group* o = new Fl_Group(2, 102, 566, 318, _("Logistics Section"));
				o->box(FL_ENGRAVED_FRAME);
				o->align(FL_ALIGN_TOP_LEFT|FL_ALIGN_INSIDE);
					txt_203_logistics_chief = new Fl_Input2(165, 119, 395, 24, _("Chief"));
					txt_203_logistics_chief->tooltip(_("Incident name"));
					txt_203_logistics_chief->box(FL_DOWN_BOX);
					txt_203_logistics_chief->color((Fl_Color)FL_BACKGROUND2_COLOR);
					txt_203_logistics_chief->selection_color((Fl_Color)FL_SELECTION_COLOR);
					txt_203_logistics_chief->labeltype(FL_NORMAL_LABEL);
					txt_203_logistics_chief->labelfont(0);
					txt_203_logistics_chief->labelsize(14);
					txt_203_logistics_chief->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
					txt_203_logistics_chief->align(FL_ALIGN_LEFT);
					txt_203_logistics_chief->when(FL_WHEN_RELEASE);

					txt_203_logistics_deputy = new Fl_Input2(165, 146, 395, 24, _("Deputy"));
					txt_203_logistics_deputy->tooltip(_("Incident name"));
					txt_203_logistics_deputy->box(FL_DOWN_BOX);
					txt_203_logistics_deputy->color((Fl_Color)FL_BACKGROUND2_COLOR);
					txt_203_logistics_deputy->selection_color((Fl_Color)FL_SELECTION_COLOR);
					txt_203_logistics_deputy->labeltype(FL_NORMAL_LABEL);
					txt_203_logistics_deputy->labelfont(0);
					txt_203_logistics_deputy->labelsize(14);
					txt_203_logistics_deputy->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
					txt_203_logistics_deputy->align(FL_ALIGN_LEFT);
					txt_203_logistics_deputy->when(FL_WHEN_RELEASE);

					{ Fl_Group* o = new Fl_Group(6, 175, 558, 118, _("a. Support"));
					o->box(FL_THIN_DOWN_BOX);
					o->align(FL_ALIGN_TOP_LEFT|FL_ALIGN_INSIDE);
						txt_203_support_director = new Fl_Input2(165, 182, 395, 24, _("Director"));
						txt_203_support_director->tooltip(_("Incident name"));
						txt_203_support_director->box(FL_DOWN_BOX);
						txt_203_support_director->color((Fl_Color)FL_BACKGROUND2_COLOR);
						txt_203_support_director->selection_color((Fl_Color)FL_SELECTION_COLOR);
						txt_203_support_director->labeltype(FL_NORMAL_LABEL);
						txt_203_support_director->labelfont(0);
						txt_203_support_director->labelsize(14);
						txt_203_support_director->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
						txt_203_support_director->align(FL_ALIGN_LEFT);
						txt_203_support_director->when(FL_WHEN_RELEASE);

						txt_203_supply_unit = new Fl_Input2(165, 209, 395, 24, _("Supply Unit"));
						txt_203_supply_unit->tooltip(_("Incident name"));
						txt_203_supply_unit->box(FL_DOWN_BOX);
						txt_203_supply_unit->color((Fl_Color)FL_BACKGROUND2_COLOR);
						txt_203_supply_unit->selection_color((Fl_Color)FL_SELECTION_COLOR);
						txt_203_supply_unit->labeltype(FL_NORMAL_LABEL);
						txt_203_supply_unit->labelfont(0);
						txt_203_supply_unit->labelsize(14);
						txt_203_supply_unit->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
						txt_203_supply_unit->align(FL_ALIGN_LEFT);
						txt_203_supply_unit->when(FL_WHEN_RELEASE);

						txt_203_facilities_unit = new Fl_Input2(165, 236, 395, 24, _("Facilities Unit"));
						txt_203_facilities_unit->tooltip(_("Incident name"));
						txt_203_facilities_unit->box(FL_DOWN_BOX);
						txt_203_facilities_unit->color((Fl_Color)FL_BACKGROUND2_COLOR);
						txt_203_facilities_unit->selection_color((Fl_Color)FL_SELECTION_COLOR);
						txt_203_facilities_unit->labeltype(FL_NORMAL_LABEL);
						txt_203_facilities_unit->labelfont(0);
						txt_203_facilities_unit->labelsize(14);
						txt_203_facilities_unit->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
						txt_203_facilities_unit->align(FL_ALIGN_LEFT);
						txt_203_facilities_unit->when(FL_WHEN_RELEASE);

						txt_203_ground_support = new Fl_Input2(165, 264, 395, 24, _("Ground Support Unit"));
						txt_203_ground_support->tooltip(_("Incident name"));
						txt_203_ground_support->box(FL_DOWN_BOX);
						txt_203_ground_support->color((Fl_Color)FL_BACKGROUND2_COLOR);
						txt_203_ground_support->selection_color((Fl_Color)FL_SELECTION_COLOR);
						txt_203_ground_support->labeltype(FL_NORMAL_LABEL);
						txt_203_ground_support->labelfont(0);
						txt_203_ground_support->labelsize(14);
						txt_203_ground_support->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
						txt_203_ground_support->align(FL_ALIGN_LEFT);
						txt_203_ground_support->when(FL_WHEN_RELEASE);
					o->end();
					} // Fl_Group* o
					{ Fl_Group* o = new Fl_Group(6, 294, 558, 123, _("b. Service"));
					o->box(FL_THIN_DOWN_BOX);
					o->align(FL_ALIGN_TOP_LEFT|FL_ALIGN_INSIDE);
						txt_203_service_director = new Fl_Input2(165, 307, 395, 24, _("Director"));
						txt_203_service_director->tooltip(_("Incident name"));
						txt_203_service_director->box(FL_DOWN_BOX);
						txt_203_service_director->color((Fl_Color)FL_BACKGROUND2_COLOR);
						txt_203_service_director->selection_color((Fl_Color)FL_SELECTION_COLOR);
						txt_203_service_director->labeltype(FL_NORMAL_LABEL);
						txt_203_service_director->labelfont(0);
						txt_203_service_director->labelsize(14);
						txt_203_service_director->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
						txt_203_service_director->align(FL_ALIGN_LEFT);
						txt_203_service_director->when(FL_WHEN_RELEASE);

						txt_203_communications_unit = new Fl_Input2(165, 334, 395, 24, _("Communications Unit"));
						txt_203_communications_unit->tooltip(_("Incident name"));
						txt_203_communications_unit->box(FL_DOWN_BOX);
						txt_203_communications_unit->color((Fl_Color)FL_BACKGROUND2_COLOR);
						txt_203_communications_unit->selection_color((Fl_Color)FL_SELECTION_COLOR);
						txt_203_communications_unit->labeltype(FL_NORMAL_LABEL);
						txt_203_communications_unit->labelfont(0);
						txt_203_communications_unit->labelsize(14);
						txt_203_communications_unit->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
						txt_203_communications_unit->align(FL_ALIGN_LEFT);
						txt_203_communications_unit->when(FL_WHEN_RELEASE);

						txt_203_medical_unit = new Fl_Input2(165, 362, 395, 24, _("Medical Unit"));
						txt_203_medical_unit->tooltip(_("Incident name"));
						txt_203_medical_unit->box(FL_DOWN_BOX);
						txt_203_medical_unit->color((Fl_Color)FL_BACKGROUND2_COLOR);
						txt_203_medical_unit->selection_color((Fl_Color)FL_SELECTION_COLOR);
						txt_203_medical_unit->labeltype(FL_NORMAL_LABEL);
						txt_203_medical_unit->labelfont(0);
						txt_203_medical_unit->labelsize(14);
						txt_203_medical_unit->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
						txt_203_medical_unit->align(FL_ALIGN_LEFT);
						txt_203_medical_unit->when(FL_WHEN_RELEASE);

						txt_203_food_unit = new Fl_Input2(165, 390, 395, 24, _("Food Unit"));
						txt_203_food_unit->tooltip(_("Incident name"));
						txt_203_food_unit->box(FL_DOWN_BOX);
						txt_203_food_unit->color((Fl_Color)FL_BACKGROUND2_COLOR);
						txt_203_food_unit->selection_color((Fl_Color)FL_SELECTION_COLOR);
						txt_203_food_unit->labeltype(FL_NORMAL_LABEL);
						txt_203_food_unit->labelfont(0);
						txt_203_food_unit->labelsize(14);
						txt_203_food_unit->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
						txt_203_food_unit->align(FL_ALIGN_LEFT);
						txt_203_food_unit->when(FL_WHEN_RELEASE);
					o->end();
					} // Fl_Group* o
				o->end();
				} // Fl_Group* o
				tab_203_logistics->end();
				} // Fl_Group* tab_203_logistics
				{ // tab_203_opsA
				tab_203_opsA = new Fl_Group(0, 95, 570, 325, _("Ops A"));
				tab_203_opsA->hide();
				{ Fl_Group* o = new Fl_Group(2, 102, 566, 318);
				o->box(FL_ENGRAVED_FRAME);
				o->align(FL_ALIGN_TOP_LEFT|FL_ALIGN_INSIDE);
				{ txt_203_ops_chief = new Fl_Input2(132, 111, 425, 24, _("Chief"));
				txt_203_ops_chief->tooltip(_("Incident name"));
				txt_203_ops_chief->box(FL_DOWN_BOX);
				txt_203_ops_chief->color((Fl_Color)FL_BACKGROUND2_COLOR);
				txt_203_ops_chief->selection_color((Fl_Color)FL_SELECTION_COLOR);
				txt_203_ops_chief->labeltype(FL_NORMAL_LABEL);
				txt_203_ops_chief->labelfont(0);
				txt_203_ops_chief->labelsize(14);
				txt_203_ops_chief->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
				txt_203_ops_chief->align(FL_ALIGN_LEFT);
				txt_203_ops_chief->when(FL_WHEN_RELEASE);
				} // Fl_Input2* txt_203_ops_chief
				{ txt_203_ops_deputy = new Fl_Input2(132, 138, 425, 24, _("Deputy"));
				txt_203_ops_deputy->tooltip(_("Incident name"));
				txt_203_ops_deputy->box(FL_DOWN_BOX);
				txt_203_ops_deputy->color((Fl_Color)FL_BACKGROUND2_COLOR);
				txt_203_ops_deputy->selection_color((Fl_Color)FL_SELECTION_COLOR);
				txt_203_ops_deputy->labeltype(FL_NORMAL_LABEL);
				txt_203_ops_deputy->labelfont(0);
				txt_203_ops_deputy->labelsize(14);
				txt_203_ops_deputy->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
				txt_203_ops_deputy->align(FL_ALIGN_LEFT);
				txt_203_ops_deputy->when(FL_WHEN_RELEASE);
				} // Fl_Input2* txt_203_ops_deputy
				{ Fl_Group* o = new Fl_Group(6, 166, 558, 248, _("Branch I - Division/Groups"));
				o->box(FL_THIN_DOWN_FRAME);
				o->align(FL_ALIGN_TOP_LEFT|FL_ALIGN_INSIDE);
				{ txt_203_b1_director = new Fl_Input2(132, 190, 425, 24, _("Branch Director"));
				txt_203_b1_director->tooltip(_("Incident name"));
				txt_203_b1_director->box(FL_DOWN_BOX);
				txt_203_b1_director->color((Fl_Color)FL_BACKGROUND2_COLOR);
				txt_203_b1_director->selection_color((Fl_Color)FL_SELECTION_COLOR);
				txt_203_b1_director->labeltype(FL_NORMAL_LABEL);
				txt_203_b1_director->labelfont(0);
				txt_203_b1_director->labelsize(14);
				txt_203_b1_director->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
				txt_203_b1_director->align(FL_ALIGN_LEFT);
				txt_203_b1_director->when(FL_WHEN_RELEASE);
				} // Fl_Input2* txt_203_b1_director
				{ txt_203_b1_deputy = new Fl_Input2(133, 221, 425, 24, _("Deputy"));
				txt_203_b1_deputy->tooltip(_("Incident name"));
				txt_203_b1_deputy->box(FL_DOWN_BOX);
				txt_203_b1_deputy->color((Fl_Color)FL_BACKGROUND2_COLOR);
				txt_203_b1_deputy->selection_color((Fl_Color)FL_SELECTION_COLOR);
				txt_203_b1_deputy->labeltype(FL_NORMAL_LABEL);
				txt_203_b1_deputy->labelfont(0);
				txt_203_b1_deputy->labelsize(14);
				txt_203_b1_deputy->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
				txt_203_b1_deputy->align(FL_ALIGN_LEFT);
				txt_203_b1_deputy->when(FL_WHEN_RELEASE);
				} // Fl_Input2* txt_203_b1_deputy
				for (int i = 0; i < 5; i++) {
					// Fl_Input2* txt_203_b1_div[i]
					txt_203_b1_div[i] = new Fl_Input2(134, 250 + i*23, 161, 24, i == 0 ? _("Division / Group"):"");
					txt_203_b1_div[i]->tooltip(_("division"));
					txt_203_b1_div[i]->box(FL_DOWN_BOX);
					txt_203_b1_div[i]->color((Fl_Color)FL_BACKGROUND2_COLOR);
					txt_203_b1_div[i]->selection_color((Fl_Color)FL_SELECTION_COLOR);
					txt_203_b1_div[i]->labeltype(FL_NORMAL_LABEL);
					txt_203_b1_div[i]->labelfont(0);
					txt_203_b1_div[i]->labelsize(14);
					txt_203_b1_div[i]->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
					txt_203_b1_div[i]->align(FL_ALIGN_LEFT);
					txt_203_b1_div[i]->when(FL_WHEN_RELEASE);
					// Fl_Input2* txt_203_b1_grp[i]
					txt_203_b1_grp[i] = new Fl_Input2(297, 250 + i*23, 261, 24);
					txt_203_b1_grp[i]->tooltip(_("group"));
					txt_203_b1_grp[i]->box(FL_DOWN_BOX);
					txt_203_b1_grp[i]->color((Fl_Color)FL_BACKGROUND2_COLOR);
					txt_203_b1_grp[i]->selection_color((Fl_Color)FL_SELECTION_COLOR);
					txt_203_b1_grp[i]->labeltype(FL_NORMAL_LABEL);
					txt_203_b1_grp[i]->labelfont(0);
					txt_203_b1_grp[i]->labelsize(14);
					txt_203_b1_grp[i]->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
					txt_203_b1_grp[i]->align(FL_ALIGN_LEFT|FL_ALIGN_INSIDE);
					txt_203_b1_grp[i]->when(FL_WHEN_RELEASE);
				}
				o->end();
				} // Fl_Group* o
				o->end();
				} // Fl_Group* o
				tab_203_opsA->end();
			  } // Fl_Group* tab_203_opsA
				{ // tab_203_opsB
				tab_203_opsB = new Fl_Group(0, 95, 570, 325, _("Ops B"));
				tab_203_opsB->hide();
				{ Fl_Group* o = new Fl_Group(2, 102, 566, 318, _("Branch II - Divisions/Groups"));
				o->box(FL_ENGRAVED_FRAME);
				o->align(FL_ALIGN_TOP_LEFT|FL_ALIGN_INSIDE);
				{ Fl_Group* o = new Fl_Group(6, 127, 558, 248);
				o->box(FL_THIN_DOWN_FRAME);
				o->align(FL_ALIGN_TOP_LEFT|FL_ALIGN_INSIDE);
				{ txt_203_b2_director = new Fl_Input2(132, 143, 425, 24, _("Branch Director"));
				txt_203_b2_director->tooltip(_("Director"));
				txt_203_b2_director->box(FL_DOWN_BOX);
				txt_203_b2_director->color((Fl_Color)FL_BACKGROUND2_COLOR);
				txt_203_b2_director->selection_color((Fl_Color)FL_SELECTION_COLOR);
				txt_203_b2_director->labeltype(FL_NORMAL_LABEL);
				txt_203_b2_director->labelfont(0);
				txt_203_b2_director->labelsize(14);
				txt_203_b2_director->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
				txt_203_b2_director->align(FL_ALIGN_LEFT);
				txt_203_b2_director->when(FL_WHEN_RELEASE);
				} // Fl_Input2* txt_203_b2_director
				{ txt_203_b2_deputy = new Fl_Input2(132, 174, 425, 24, _("Deputy"));
				txt_203_b2_deputy->tooltip(_("Deputy"));
				txt_203_b2_deputy->box(FL_DOWN_BOX);
				txt_203_b2_deputy->color((Fl_Color)FL_BACKGROUND2_COLOR);
				txt_203_b2_deputy->selection_color((Fl_Color)FL_SELECTION_COLOR);
				txt_203_b2_deputy->labeltype(FL_NORMAL_LABEL);
				txt_203_b2_deputy->labelfont(0);
				txt_203_b2_deputy->labelsize(14);
				txt_203_b2_deputy->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
				txt_203_b2_deputy->align(FL_ALIGN_LEFT);
				txt_203_b2_deputy->when(FL_WHEN_RELEASE);
				} // Fl_Input2* txt_203_b2_deputy
				for (int i = 0; i < 5; i++) {
				txt_203_b2_div[i] = new Fl_Input2(132, 203 + i*33, 161, 24, _("Division / Group"));
				txt_203_b2_div[i]->tooltip(_("division"));
				txt_203_b2_div[i]->box(FL_DOWN_BOX);
				txt_203_b2_div[i]->color((Fl_Color)FL_BACKGROUND2_COLOR);
				txt_203_b2_div[i]->selection_color((Fl_Color)FL_SELECTION_COLOR);
				txt_203_b2_div[i]->labeltype(FL_NORMAL_LABEL);
				txt_203_b2_div[i]->labelfont(0);
				txt_203_b2_div[i]->labelsize(14);
				txt_203_b2_div[i]->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
				txt_203_b2_div[i]->align(FL_ALIGN_LEFT);
				txt_203_b2_div[i]->when(FL_WHEN_RELEASE);
				// Fl_Input2* txt_203_b2_div[i]
				txt_203_b2_grp[i] = new Fl_Input2(295, 203 + i*33, 261, 24);
				txt_203_b2_grp[i]->tooltip(_("group"));
				txt_203_b2_grp[i]->box(FL_DOWN_BOX);
				txt_203_b2_grp[i]->color((Fl_Color)FL_BACKGROUND2_COLOR);
				txt_203_b2_grp[i]->selection_color((Fl_Color)FL_SELECTION_COLOR);
				txt_203_b2_grp[i]->labeltype(FL_NORMAL_LABEL);
				txt_203_b2_grp[i]->labelfont(0);
				txt_203_b2_grp[i]->labelsize(14);
				txt_203_b2_grp[i]->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
				txt_203_b2_grp[i]->align(FL_ALIGN_LEFT|FL_ALIGN_INSIDE);
				txt_203_b2_grp[i]->when(FL_WHEN_RELEASE);
				} // Fl_Input2* txt_203_b2_grp[i]
				o->end();
				} // Fl_Group* o
				o->end();
				} // Fl_Group* o
				tab_203_opsB->end();
			  } // Fl_Group* tab_203_opsB
				{ // tab_203_opsC
				tab_203_opsC = new Fl_Group(0, 95, 570, 325, _("OPs C"));
				tab_203_opsC->hide();
				{ Fl_Group* o = new Fl_Group(2, 102, 566, 318, _("Branch III - Divisions/Groups"));
				o->box(FL_ENGRAVED_FRAME);
				o->align(FL_ALIGN_TOP_LEFT|FL_ALIGN_INSIDE);
				{ Fl_Group* o = new Fl_Group(6, 127, 558, 248);
				o->box(FL_THIN_DOWN_FRAME);
				o->align(FL_ALIGN_TOP_LEFT|FL_ALIGN_INSIDE);
				{ txt_203_b3_director = new Fl_Input2(132, 143, 425, 24, _("Branch Director"));
				txt_203_b3_director->tooltip(_("Incident name"));
				txt_203_b3_director->box(FL_DOWN_BOX);
				txt_203_b3_director->color((Fl_Color)FL_BACKGROUND2_COLOR);
				txt_203_b3_director->selection_color((Fl_Color)FL_SELECTION_COLOR);
				txt_203_b3_director->labeltype(FL_NORMAL_LABEL);
				txt_203_b3_director->labelfont(0);
				txt_203_b3_director->labelsize(14);
				txt_203_b3_director->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
				txt_203_b3_director->align(FL_ALIGN_LEFT);
				txt_203_b3_director->when(FL_WHEN_RELEASE);
				} // Fl_Input2* txt_203_b3_director
				{ txt_203_b3_deputy = new Fl_Input2(132, 174, 425, 24, _("Deputy"));
				txt_203_b3_deputy->tooltip(_("Incident name"));
				txt_203_b3_deputy->box(FL_DOWN_BOX);
				txt_203_b3_deputy->color((Fl_Color)FL_BACKGROUND2_COLOR);
				txt_203_b3_deputy->selection_color((Fl_Color)FL_SELECTION_COLOR);
				txt_203_b3_deputy->labeltype(FL_NORMAL_LABEL);
				txt_203_b3_deputy->labelfont(0);
				txt_203_b3_deputy->labelsize(14);
				txt_203_b3_deputy->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
				txt_203_b3_deputy->align(FL_ALIGN_LEFT);
				txt_203_b3_deputy->when(FL_WHEN_RELEASE);
				} // Fl_Input2* txt_203_b3_deputy
				for (int i = 0; i < 5; i++) {
				txt_203_b3_div[i] = new Fl_Input2(132, 203, 161, 24, _("Division / Group"));
				txt_203_b3_div[i]->tooltip(_("Division"));
				txt_203_b3_div[i]->box(FL_DOWN_BOX);
				txt_203_b3_div[i]->color((Fl_Color)FL_BACKGROUND2_COLOR);
				txt_203_b3_div[i]->selection_color((Fl_Color)FL_SELECTION_COLOR);
				txt_203_b3_div[i]->labeltype(FL_NORMAL_LABEL);
				txt_203_b3_div[i]->labelfont(0);
				txt_203_b3_div[i]->labelsize(14);
				txt_203_b3_div[i]->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
				txt_203_b3_div[i]->align(FL_ALIGN_LEFT);
				txt_203_b3_div[i]->when(FL_WHEN_RELEASE);
				// Fl_Input2* txt_203_b3_div[i]
				txt_203_b3_grp[i] = new Fl_Input2(295, 203, 261, 24);
				txt_203_b3_grp[i]->tooltip(_("Group"));
				txt_203_b3_grp[i]->box(FL_DOWN_BOX);
				txt_203_b3_grp[i]->color((Fl_Color)FL_BACKGROUND2_COLOR);
				txt_203_b3_grp[i]->selection_color((Fl_Color)FL_SELECTION_COLOR);
				txt_203_b3_grp[i]->labeltype(FL_NORMAL_LABEL);
				txt_203_b3_grp[i]->labelfont(0);
				txt_203_b3_grp[i]->labelsize(14);
				txt_203_b3_grp[i]->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
				txt_203_b3_grp[i]->align(FL_ALIGN_LEFT|FL_ALIGN_INSIDE);
				txt_203_b3_grp[i]->when(FL_WHEN_RELEASE);
				} // Fl_Input2* txt_203_b3_grp[i]
				o->end();
				} // Fl_Group* o
				o->end();
				} // Fl_Group* o
				tab_203_opsC->end();
			  } // Fl_Group* tab_203_opsC
				{ // tab_203_opsD
				tab_203_opsD = new Fl_Group(0, 95, 570, 325, _("OPs D"));
				tab_203_opsD->hide();
				{ Fl_Group* o = new Fl_Group(2, 102, 566, 318, _("Air Operations Branch"));
				o->box(FL_ENGRAVED_FRAME);
				o->align(FL_ALIGN_TOP_LEFT|FL_ALIGN_INSIDE);
				{ Fl_Group* o = new Fl_Group(6, 130, 558, 183);
				o->box(FL_THIN_DOWN_FRAME);
				o->align(FL_ALIGN_TOP_LEFT|FL_ALIGN_INSIDE);
				{ txt_203_air_ops_br_dir = new Fl_Input2(228, 146, 300, 24, _("Air Operations Br. Dir."));
				txt_203_air_ops_br_dir->tooltip(_("Incident name"));
				txt_203_air_ops_br_dir->box(FL_DOWN_BOX);
				txt_203_air_ops_br_dir->color((Fl_Color)FL_BACKGROUND2_COLOR);
				txt_203_air_ops_br_dir->selection_color((Fl_Color)FL_SELECTION_COLOR);
				txt_203_air_ops_br_dir->labeltype(FL_NORMAL_LABEL);
				txt_203_air_ops_br_dir->labelfont(0);
				txt_203_air_ops_br_dir->labelsize(14);
				txt_203_air_ops_br_dir->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
				txt_203_air_ops_br_dir->align(FL_ALIGN_LEFT);
				txt_203_air_ops_br_dir->when(FL_WHEN_RELEASE);
				} // Fl_Input2* txt_203_air_ops_br_dir
				{ txt_203_air_tactical_group_sup = new Fl_Input2(228, 177, 300, 24, _("Air Tactical Group Sup."));
				txt_203_air_tactical_group_sup->tooltip(_("Incident name"));
				txt_203_air_tactical_group_sup->box(FL_DOWN_BOX);
				txt_203_air_tactical_group_sup->color((Fl_Color)FL_BACKGROUND2_COLOR);
				txt_203_air_tactical_group_sup->selection_color((Fl_Color)FL_SELECTION_COLOR);
				txt_203_air_tactical_group_sup->labeltype(FL_NORMAL_LABEL);
				txt_203_air_tactical_group_sup->labelfont(0);
				txt_203_air_tactical_group_sup->labelsize(14);
				txt_203_air_tactical_group_sup->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
				txt_203_air_tactical_group_sup->align(FL_ALIGN_LEFT);
				txt_203_air_tactical_group_sup->when(FL_WHEN_RELEASE);
				} // Fl_Input2* txt_203_air_tactical_group_sup
				{ txt_203_air_support_group_sup = new Fl_Input2(228, 206, 300, 24, _("Air Support Group Sup."));
				txt_203_air_support_group_sup->tooltip(_("Incident name"));
				txt_203_air_support_group_sup->box(FL_DOWN_BOX);
				txt_203_air_support_group_sup->color((Fl_Color)FL_BACKGROUND2_COLOR);
				txt_203_air_support_group_sup->selection_color((Fl_Color)FL_SELECTION_COLOR);
				txt_203_air_support_group_sup->labeltype(FL_NORMAL_LABEL);
				txt_203_air_support_group_sup->labelfont(0);
				txt_203_air_support_group_sup->labelsize(14);
				txt_203_air_support_group_sup->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
				txt_203_air_support_group_sup->align(FL_ALIGN_LEFT);
				txt_203_air_support_group_sup->when(FL_WHEN_RELEASE);
				} // Fl_Input2* txt_203_air_support_group_sup
				{ txt_203_helicopter_coordinator = new Fl_Input2(228, 239, 300, 24, _("Helicopter Coordinator"));
				txt_203_helicopter_coordinator->tooltip(_("Incident name"));
				txt_203_helicopter_coordinator->box(FL_DOWN_BOX);
				txt_203_helicopter_coordinator->color((Fl_Color)FL_BACKGROUND2_COLOR);
				txt_203_helicopter_coordinator->selection_color((Fl_Color)FL_SELECTION_COLOR);
				txt_203_helicopter_coordinator->labeltype(FL_NORMAL_LABEL);
				txt_203_helicopter_coordinator->labelfont(0);
				txt_203_helicopter_coordinator->labelsize(14);
				txt_203_helicopter_coordinator->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
				txt_203_helicopter_coordinator->align(FL_ALIGN_LEFT);
				txt_203_helicopter_coordinator->when(FL_WHEN_RELEASE);
				} // Fl_Input2* txt_203_helicopter_coordinator
				{ txt_203_air_tanker_fixed_wing = new Fl_Input2(228, 273, 300, 24, _("Air Tanker / Fixed Wing Crd."));
				txt_203_air_tanker_fixed_wing->tooltip(_("Incident name"));
				txt_203_air_tanker_fixed_wing->box(FL_DOWN_BOX);
				txt_203_air_tanker_fixed_wing->color((Fl_Color)FL_BACKGROUND2_COLOR);
				txt_203_air_tanker_fixed_wing->selection_color((Fl_Color)FL_SELECTION_COLOR);
				txt_203_air_tanker_fixed_wing->labeltype(FL_NORMAL_LABEL);
				txt_203_air_tanker_fixed_wing->labelfont(0);
				txt_203_air_tanker_fixed_wing->labelsize(14);
				txt_203_air_tanker_fixed_wing->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
				txt_203_air_tanker_fixed_wing->align(FL_ALIGN_LEFT);
				txt_203_air_tanker_fixed_wing->when(FL_WHEN_RELEASE);
				} // Fl_Input2* txt_203_air_tanker_fixed_wing
				o->end();
				} // Fl_Group* o
				o->end();
				} // Fl_Group* o
				tab_203_opsD->end();
			  } // Fl_Group* tab_203_opsD
				{ // tab_203_admin
				tab_203_admin = new Fl_Group(0, 95, 570, 326, _("Admin"));
				tab_203_admin->hide();
				{ Fl_Group* o = new Fl_Group(2, 102, 566, 318, _("Finance/Admin Section"));
				o->box(FL_ENGRAVED_FRAME);
				o->align(FL_ALIGN_TOP_LEFT|FL_ALIGN_INSIDE);
				{ Fl_Group* o = new Fl_Group(6, 132, 558, 215);
				o->box(FL_THIN_DOWN_FRAME);
				o->align(FL_ALIGN_TOP_LEFT|FL_ALIGN_INSIDE);
				{ txt_203_finance_chief = new Fl_Input2(230, 148, 300, 24, _("Chief"));
				txt_203_finance_chief->tooltip(_("Incident name"));
				txt_203_finance_chief->box(FL_DOWN_BOX);
				txt_203_finance_chief->color((Fl_Color)FL_BACKGROUND2_COLOR);
				txt_203_finance_chief->selection_color((Fl_Color)FL_SELECTION_COLOR);
				txt_203_finance_chief->labeltype(FL_NORMAL_LABEL);
				txt_203_finance_chief->labelfont(0);
				txt_203_finance_chief->labelsize(14);
				txt_203_finance_chief->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
				txt_203_finance_chief->align(FL_ALIGN_LEFT);
				txt_203_finance_chief->when(FL_WHEN_RELEASE);
				} // Fl_Input2* txt_203_finance_chief
				{ txt_203_finance_deputy = new Fl_Input2(230, 180, 300, 24, _("Deputy"));
				txt_203_finance_deputy->tooltip(_("Incident name"));
				txt_203_finance_deputy->box(FL_DOWN_BOX);
				txt_203_finance_deputy->color((Fl_Color)FL_BACKGROUND2_COLOR);
				txt_203_finance_deputy->selection_color((Fl_Color)FL_SELECTION_COLOR);
				txt_203_finance_deputy->labeltype(FL_NORMAL_LABEL);
				txt_203_finance_deputy->labelfont(0);
				txt_203_finance_deputy->labelsize(14);
				txt_203_finance_deputy->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
				txt_203_finance_deputy->align(FL_ALIGN_LEFT);
				txt_203_finance_deputy->when(FL_WHEN_RELEASE);
				} // Fl_Input2* txt_203_finance_deputy
				{ txt_203_time_unit = new Fl_Input2(230, 212, 300, 24, _("Time Unit"));
				txt_203_time_unit->tooltip(_("Incident name"));
				txt_203_time_unit->box(FL_DOWN_BOX);
				txt_203_time_unit->color((Fl_Color)FL_BACKGROUND2_COLOR);
				txt_203_time_unit->selection_color((Fl_Color)FL_SELECTION_COLOR);
				txt_203_time_unit->labeltype(FL_NORMAL_LABEL);
				txt_203_time_unit->labelfont(0);
				txt_203_time_unit->labelsize(14);
				txt_203_time_unit->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
				txt_203_time_unit->align(FL_ALIGN_LEFT);
				txt_203_time_unit->when(FL_WHEN_RELEASE);
				} // Fl_Input2* txt_203_time_unit
				{ txt_203_procurement_unit = new Fl_Input2(230, 244, 300, 24, _("Procurement Unit"));
				txt_203_procurement_unit->tooltip(_("Incident name"));
				txt_203_procurement_unit->box(FL_DOWN_BOX);
				txt_203_procurement_unit->color((Fl_Color)FL_BACKGROUND2_COLOR);
				txt_203_procurement_unit->selection_color((Fl_Color)FL_SELECTION_COLOR);
				txt_203_procurement_unit->labeltype(FL_NORMAL_LABEL);
				txt_203_procurement_unit->labelfont(0);
				txt_203_procurement_unit->labelsize(14);
				txt_203_procurement_unit->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
				txt_203_procurement_unit->align(FL_ALIGN_LEFT);
				txt_203_procurement_unit->when(FL_WHEN_RELEASE);
				} // Fl_Input2* txt_203_procurement_unit
				{ txt_203_claims_unit = new Fl_Input2(230, 276, 300, 24, _("Compensation / Claims Unit"));
				txt_203_claims_unit->tooltip(_("Incident name"));
				txt_203_claims_unit->box(FL_DOWN_BOX);
				txt_203_claims_unit->color((Fl_Color)FL_BACKGROUND2_COLOR);
				txt_203_claims_unit->selection_color((Fl_Color)FL_SELECTION_COLOR);
				txt_203_claims_unit->labeltype(FL_NORMAL_LABEL);
				txt_203_claims_unit->labelfont(0);
				txt_203_claims_unit->labelsize(14);
				txt_203_claims_unit->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
				txt_203_claims_unit->align(FL_ALIGN_LEFT);
				txt_203_claims_unit->when(FL_WHEN_RELEASE);
				} // Fl_Input2* txt_203_claims_unit
				{ txt_203_cost_unit = new Fl_Input2(230, 308, 300, 24, _("Cost Unit"));
				txt_203_cost_unit->tooltip(_("Incident name"));
				txt_203_cost_unit->box(FL_DOWN_BOX);
				txt_203_cost_unit->color((Fl_Color)FL_BACKGROUND2_COLOR);
				txt_203_cost_unit->selection_color((Fl_Color)FL_SELECTION_COLOR);
				txt_203_cost_unit->labeltype(FL_NORMAL_LABEL);
				txt_203_cost_unit->labelfont(0);
				txt_203_cost_unit->labelsize(14);
				txt_203_cost_unit->labelcolor((Fl_Color)FL_FOREGROUND_COLOR);
				txt_203_cost_unit->align(FL_ALIGN_LEFT);
				txt_203_cost_unit->when(FL_WHEN_RELEASE);
				} // Fl_Input2* txt_203_cost_unit
				o->end();
				} // Fl_Group* o
				o->end();
				} // Fl_Group* o
				tab_203_admin->end();
			  } // Fl_Group* tab_203_admin
			tab_ics203_type->end();
			Fl_Group::current()->resizable(tab_ics203_type);
			tab_ics203->end();
			} // Fl_Group* tab_ics203
