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

#include "wx_strings.h"

const std::string counties = "\
--,County,\
--,\
AB,\
MD of Acadia No. 34 (001),\
Athabasca County (002),\
County of Barrhead No. 11 (003),\
Beaver County (004),\
Big Lakes County (005),\
MD of Bighorn No. 8 (006),\
Birch Hills County (007),\
MD of Bonnyville No. 87 (008),\
Brazeau County (009),\
Camrose County (010),\
Cardston County (011),\
Clear Hills County (012),\
Clearwater County (013),\
Cypress County (014),\
MD of Fairview No. 136 (015),\
Flagstaff County (016),\
Foothills County (017),\
County of Forty Mile No. 8 (018),\
County of Grande Prairie No. 1 (019),\
MD of Greenview No. 16 (020),\
Kneehill County (021),\
Lac Ste. Anne County (022),\
Lacombe County (023),\
Lamont County (024),\
Leduc County (025),\
MD of Lesser Slave River No. 124 (026),\
Lethbridge County (027),\
County of Minburn No. 27 (028),\
Mountain View County (029),\
County of Newell (030),\
County of Northern Lights (031),\
Northern Sunrise County (032),\
MD of Opportunity No. 17 (033),\
County of Paintearth No. 18 (034),\
Parkland County (035),\
MD of Peace No. 135 (036),\
MD of Pincher Creek No. 9 (037),\
Ponoka County (038),\
MD of Provost No. 52 (039),\
MD of Ranchland No. 66 (040),\
Red Deer County (041),\
Rocky View County (042),\
Saddle Hills County (043),\
Smoky Lake County (044),\
MD of Smoky River No. 130 (045),\
MD of Spirit River No. 133 (046),\
County of St. Paul No. 19 (047),\
Starland County (048),\
County of Stettler No. 6 (049),\
Sturgeon County (050),\
MD of Taber (051),\
Thorhild County (052),\
County of Two Hills No. 21 (053),\
County of Vermilion River (054),\
Vulcan County (055),\
MD of Wainwright No. 61 (056),\
County of Warner No. 5 (057),\
Westlock County (058),\
County of Wetaskiwin No. 10 (059),\
Wheatland County (060),\
MD of Willow Creek No. 26 (061),\
Woodlands County (062),\
Yellowhead County (063),\
AB,\
AL,\
Autauga (001),\
Baldwin (003),\
Barbour (005),\
Bibb (007),\
Blount (009),\
Bullock (011),\
Butler (013),\
Calhoun (015),\
Chambers (017),\
Cherokee (019),\
Chilton (021),\
Choctaw (023),\
Clarke (025),\
Clay (027),\
Cleburne (029),\
Coffee (031),\
Colbert (033),\
Conecuh (035),\
Coosa (037),\
Covington (039),\
Crenshaw (041),\
Cullman (043),\
Dale (045),\
Dallas (047),\
DeKalb (049),\
Elmore (051),\
Escambia (053),\
Etowah (055),\
Fayette (057),\
Franklin (059),\
Geneva (061),\
Greene (063),\
Hale (065),\
Henry (067),\
Houston (069),\
Jackson (071),\
Jefferson (073),\
Lamar (075),\
Lauderdale (077),\
Lawrence (079),\
Lee (081),\
Limestone (083),\
Lowndes (085),\
Macon (087),\
Madison (089),\
Marengo (091),\
Marion (093),\
Marshall (095),\
Mobile (097),\
Monroe (099),\
Montgomery (101),\
Morgan (103),\
Perry (105),\
Pickens (107),\
Pike (109),\
Randolph (111),\
Russell (113),\
St. Clair (115),\
Shelby (117),\
Sumter (119),\
Talladega (121),\
Tallapoosa (123),\
Tuscaloosa (125),\
Walker (127),\
Washington (129),\
Wilcox (131),\
Winston (133),\
AL,\
AK,\
Aleutians East (013),\
Aleutians West  (016),\
Anchorage (020),\
Bethel (050),\
Bristol Bay (060),\
Denali (068),\
Dillingham (070),\
Fairbanks North Star (090),\
Haines (100),\
Juneau (110),\
Kenai Peninsula (122),\
Ketchikan Gateway (130),\
Kodiak Island (150),\
Lake and Peninsula (164),\
Matanuska-Susitna (170),\
Nome  (180),\
North Slope (185),\
Northwest Arctic (188),\
Prince of Wales-OuterKetchikan (201),\
Sitka (220),\
Skagway-Yakutat-Angoon (231),\
Southeast Fairbanks (240),\
Valdez-Gordova (261),\
Wade Hampton (270),\
Wrangell-Petersburg (280),\
Yukon-Koyukuk (290),\
AK,\
AZ,\
Apache (001),\
Cochise (003),\
Coconino (005),\
Gila (007),\
Graham (009),\
Greenlee (011),\
La Paz (012),\
Maricopa (013),\
Mohave (015),\
Navajo (017),\
Pima (019),\
Pinal (021),\
Santa Cruz (023),\
Yavapai (025),\
Yuma (027),\
AZ,\
AR,\
Arkansas  (001),\
Ashley  (003),\
Baxter  (005),\
Benton  (007),\
Boone  (009),\
Bradley  (011),\
Calhoun  (013),\
Carroll  (015),\
Chicot  (017),\
Clark  (019),\
Clay  (021),\
Cleburne  (023),\
Cleveland  (025),\
Columbia  (027),\
Conway  (029),\
Craighead  (031),\
Crawford  (033),\
Crittenden  (035),\
Cross  (037),\
Dallas  (039),\
Desha  (041),\
Drew  (043),\
Faulkner  (045),\
Franklin  (047),\
Fulton  (049),\
Garland  (051),\
Grant  (053),\
Hempstead  (057),\
Hot Spring  (059),\
Howard  (061),\
Independence  (063),\
Izard  (065),\
Jackson  (067),\
Jefferson  (069),\
Johnson  (071),\
Lafayette  (073),\
Lawrence  (075),\
Lee  (077),\
Lincoln  (079),\
Little River  (081),\
Logan  (083),\
Lonoke  (085),\
Madison  (087),\
Marion  (089),\
Miller  (091),\
Mississippi  (093),\
Monroe  (095),\
Montgomery  (097),\
Nevada  (099),\
Newton  (101),\
Ouachita  (103),\
Phillips  (107),\
Pike  (109),\
Poinsett  (111),\
Polk  (113),\
Pope  (115),\
Prairie  (117),\
Pulaski  (119),\
Randolph  (121),\
St. Francis  (123),\
Saline  (125),\
Scott  (127),\
Searcy  (129),\
Sebastian  (131),\
Sevier  (133),\
Sharp  (135),\
Stone  (137),\
Union  (139),\
Van Buren  (141),\
Washington  (143),\
White  (145),\
Woodruff  (147),\
Yell  (149),\
AR,\
BC,\
Abbotsford (001),\
Burnaby North-Seymour (002),\
Burnaby South (003),\
Cariboo-Prince George (004),\
Central Okanagan-Similkameen-Nicola (005),\
Chilliwack-Hope (006),\
Cloverdale-Langley City (007),\
Coquitlam-Port Coquitlam (008),\
Courtenay-Alberni (009),\
Cowichan-Malahat-Langford (010),\
Delta (011),\
Esquimalt-Saanich-Sooke (012),\
Fleetwood-Port Kells (013),\
Kamloops-Thompson-Cariboo (014),\
Kelowna-Lake Country (015),\
Kootenay-Columbia (016),\
Langley-Aldergrove (017),\
Mission-Matsqui-Fraser Canyon (018),\
Nanaimo-Ladysmith (019),\
New Westminster-Burnaby (020),\
North Island-Powell River (021),\
North Okanagan-Shuswap (022),\
North Vancouver (023),\
Pitt Meadows-Maple Ridge (024),\
Port Moody-Coquitlam (025),\
Prince George-Peace River-Northern Rockies (026),\
Richmond Center (027),\
Saanich-Gulf Islands (028),\
Skeena-Bulkley Valley (029),\
South Okanagan-West Kootenay (030),\
South Surrey-White Rock (031),\
Steveston-Richmond East (032),\
Surrey Centre (033),\
Surrey-Newton (034),\
Vancouver Centre (035),\
Vancouver East (036),\
Vancouver Kingsway (037),\
Vancouver Quadra (038),\
Vancouver South (039),\
Vancouver-Granville (040),\
Victoria (041),\
West Vanc (042),\
BC\
CA,\
Alameda  (001),\
Alpine  (003),\
Amador  (005),\
Butte  (007),\
Calaveras  (009),\
Colusa  (011),\
Contra Costa  (013),\
Del Norte  (015),\
El Dorado  (017),\
Fresno  (019),\
Glenn  (021),\
Humboldt  (023),\
Imperial  (025),\
Inyo  (027),\
Kern  (029),\
Kings  (031),\
Lake  (033),\
Lassen  (035),\
Los Angeles  (037),\
Madera  (039),\
Marin  (041),\
Mariposa  (043),\
Mendocino  (045),\
Merced  (047),\
Modoc  (049),\
Mono  (051),\
Monterey  (053),\
Napa  (055),\
Nevada  (057),\
Orange  (059),\
Placer  (061),\
Plumas  (063),\
Riverside  (065),\
Sacramento  (067),\
San Benito  (069),\
San Bernardino  (071),\
San Diego  (073),\
San Francisco  (075),\
San Joaquin  (077),\
San Luis Obispo  (079),\
San Mateo  (081),\
Santa Barbara  (083),\
Santa Clara  (085),\
Santa Cruz  (087),\
Shasta  (089),\
Sierra  (091),\
Siskiyou  (093),\
Solano  (095),\
Sonoma  (097),\
Stanislaus  (099),\
Sutter  (101),\
Tehama  (103),\
Trinity  (105),\
Tulare  (107),\
Tuolumne  (109),\
Ventura  (111),\
Yolo  (113),\
Yuba  (115),\
CA,\
CO,\
Adams  (001),\
Alamosa  (003),\
Arapahoe  (005),\
Archuleta  (007),\
Baca  (009),\
Bent  (011),\
Boulder  (013),\
Chaffee  (015),\
Cheyenne  (017),\
Clear Creek  (019),\
Conejos  (021),\
Costilla  (023),\
Crowley  (025),\
Custer  (027),\
Delta  (029),\
Denver  (031),\
Dolores  (033),\
Douglas  (035),\
Eagle  (037),\
Elbert  (039),\
El Paso  (041),\
Fremont  (043),\
Garfield  (045),\
Gilpin  (047),\
Grand  (049),\
Gunnison  (051),\
Hinsdale  (053),\
Huerfano  (055),\
Jackson  (057),\
Jefferson  (059),\
Kiowa  (061),\
Kit Carson  (063),\
Lake  (065),\
La Plata  (067),\
Larimer  (069),\
Las Animas  (071),\
Lincoln  (073),\
Logan  (075),\
Mesa  (077),\
Mineral  (079),\
Moffat  (081),\
Montezuma  (083),\
Montrose  (085),\
Morgan  (087),\
Otero  (089),\
Ouray  (091),\
Park  (093),\
Phillips  (095),\
Pitkin  (097),\
Prowers  (099),\
Pueblo  (101),\
Rio Blanco  (103),\
Rio Grande  (105),\
Routt  (107),\
Saguache  (109),\
San Juan  (111),\
San Miguel  (113),\
Sedgwick  (115),\
Summit  (117),\
Teller  (119),\
Washington  (121),\
Weld  (123),\
Yuma  (125),\
CO,\
CT,\
Fairfield  (001),\
Hartford  (003),\
Litchfield  (005),\
Middlesex  (007),\
New Haven  (009),\
New London  (011),\
Tolland  (013),\
Windham  (015),\
CT,\
DE,\
Kent  (001),\
New Castle  (003),\
Sussex  (005),\
DE,\
DC,\
District of Columbia  (001),\
DC,\
FL,\
Alachua  (001),\
Baker  (003),\
Bay  (005),\
Bradford  (007),\
Brevard  (009),\
Broward  (011),\
Calhoun  (013),\
Charlotte  (015),\
Citrus  (017),\
Clay  (019),\
Collier  (021),\
Columbia  (023),\
Dade  (025),\
DeSoto  (027),\
Dixie  (029),\
Duval  (031),\
Escambia  (033),\
Flagler  (035),\
Franklin  (037),\
Gadsden  (039),\
Gilchrist  (041),\
Glades  (043),\
Gulf  (045),\
Hamilton  (047),\
Hardee  (049),\
Hendry  (051),\
Hernando  (053),\
Highlands  (055),\
Hillsborough  (057),\
Holmes  (059),\
Indian River  (061),\
Jackson  (063),\
Jefferson  (065),\
Lafayette  (067),\
Lake  (069),\
Lee  (071),\
Leon  (073),\
Levy  (075),\
Liberty  (077),\
Madison  (079),\
Manatee  (081),\
Marion  (083),\
Martin  (085),\
Monroe  (087),\
Nassau  (089),\
Okaloosa  (091),\
Okeechobee  (093),\
Orange  (095),\
Osceola  (097),\
Palm Beach  (099),\
Pasco  (101),\
Pinellas  (103),\
Polk  (105),\
Putnam  (107),\
St. Johns  (109),\
St. Lucie  (111),\
Santa Rosa  (113),\
Sarasota  (115),\
Seminole  (117),\
Sumter  (119),\
Suwannee  (121),\
Taylor  (123),\
Union  (125),\
Volusia  (127),\
Wakulla  (129),\
Walton  (131),\
Washington  (133),\
FL,\
GA,\
Appling  (001),\
Atkinson  (003),\
Bacon  (005),\
Baker  (007),\
Baldwin  (009),\
Banks  (011),\
Barrow  (013),\
Bartow  (015),\
Ben Hill  (017),\
Berrien  (019),\
Bibb  (021),\
Bleckley  (023),\
Brantley  (025),\
Brooks  (027),\
Bryan  (029),\
Bulloch  (031),\
Burke  (033),\
Butts  (035),\
Calhoun  (037),\
Camden  (039),\
Candler  (043),\
Carroll  (045),\
Catoosa  (047),\
Charlton  (049),\
Chatham  (051),\
Chattahoochee  (053),\
Chattooga  (055),\
Cherokee  (057),\
Clarke  (059),\
Clay  (061),\
Clayton  (063),\
Clinch  (065),\
Cobb  (067),\
Coffee  (069),\
Colquitt  (071),\
Columbia  (073),\
Cook  (075),\
Coweta  (077),\
Crawford  (079),\
Crisp  (081),\
Dade  (083),\
Dawson  (085),\
Decatur  (087),\
DeKalb  (089),\
Dodge  (091),\
Dooly  (093),\
Dougherty  (095),\
Douglas  (097),\
Early  (099),\
Echols  (101),\
Effingham  (103),\
Elbert  (105),\
Emanuel  (107),\
Evans  (109),\
Fannin  (111),\
Fayette  (113),\
Floyd  (115),\
Forsyth  (117),\
Franklin  (119),\
Fulton  (121),\
Gilmer  (123),\
Glascock  (125),\
Glynn  (127),\
Gordon  (129),\
Grady  (131),\
Greene  (133),\
Gwinnett  (135),\
Habersham  (137),\
Hall  (139),\
Hancock  (141),\
Haralson  (143),\
Harris  (145),\
Hart  (147),\
Heard  (149),\
Henry  (151),\
Houston  (153),\
Irwin  (155),\
Jackson  (157),\
Jasper  (159),\
Jeff Davis  (161),\
Jefferson  (163),\
Jenkins  (165),\
Johnson  (167),\
Jones  (169),\
Lamar  (171),\
Lanier  (173),\
Laurens  (175),\
Lee  (177),\
Liberty  (179),\
Lincoln  (181),\
Long  (183),\
Lowndes  (185),\
Lumpkin  (187),\
Macon  (193),\
Madison  (195),\
Marion  (197),\
McDuffie  (189),\
Mclntosh  (191),\
Meriwether  (199),\
Miller  (201),\
Mitchell  (205),\
Monroe  (207),\
Montgomery  (209),\
Morgan  (211),\
Murray  (213),\
Muscogee  (215),\
Newton  (217),\
Oconee  (219),\
Oglethorpe  (221),\
Paulding  (223),\
Peach  (225),\
Pickens  (227),\
Pierce  (229),\
Pike  (231),\
Polk  (233),\
Pulaski  (235),\
Putnam  (237),\
Quitman  (239),\
Rabun  (241),\
Randolph  (243),\
Richmond  (245),\
Rockdale  (247),\
Schley  (249),\
Screven  (251),\
Seminole  (253),\
Spalding  (255),\
Stephens  (257),\
Stewart  (259),\
Sumter  (261),\
Talbot  (263),\
Taliaferro  (265),\
Tattnall  (267),\
Taylor  (269),\
Telfair  (271),\
Terrell  (273),\
Thomas  (275),\
Tift  (277),\
Toombs  (279),\
Towns  (281),\
Treutlen  (283),\
Troup  (285),\
Turner  (287),\
Twiggs  (289),\
Union  (291),\
Upson  (293),\
Walker  (295),\
Walton  (297),\
Ware  (299),\
Warren  (301),\
Washington  (303),\
Wayne  (305),\
Webster  (307),\
Wheeler  (309),\
White  (311),\
Whitfield  (313),\
Wilcox  (315),\
Wilkes  (317),\
Wilkinson  (319),\
Worth  (321),\
GA,\
HI,\
Hawaii  (001),\
Honolulu  (003),\
Kalawao  (005),\
Kauai  (007),\
Maui  (009),\
HI,\
ID,\
Ada  (001),\
Adams  (003),\
Bannock  (005),\
Bear Lake  (007),\
Benewah  (009),\
Bingham  (011),\
Blaine  (013),\
Boise  (015),\
Bonner  (017),\
Bonneville  (019),\
Boundary  (021),\
Butte  (023),\
Camas  (025),\
Canyon  (027),\
Caribou  (029),\
Cassia  (031),\
Clark  (033),\
Clearwater  (035),\
Custer  (037),\
Elmore  (039),\
Franklin  (041),\
Fremont  (043),\
Gem  (045),\
Gooding  (047),\
Idaho  (049),\
Jefferson  (051),\
Jerome  (053),\
Kootenai  (055),\
Latah  (057),\
Lemhi  (059),\
Lewis  (061),\
Lincoln  (063),\
Madison  (065),\
Minidoka  (067),\
Nez Perce  (069),\
Oneida  (071),\
Owyhee  (073),\
Payette  (075),\
Power  (077),\
Shoshone  (079),\
Teton  (081),\
Twin Falls  (083),\
Valley  (085),\
Washington  (087),\
ID,\
IL,\
Adams  (001),\
Alexander  (003),\
Bond  (005),\
Boone  (007),\
Brown  (009),\
Bureau  (011),\
Calhoun  (013),\
Carroll  (015),\
Cass  (017),\
Champaign  (019),\
Christian  (021),\
Clark  (023),\
Clay  (025),\
Clinton  (027),\
Coles  (029),\
Cook  (031),\
Crawford  (033),\
Cumberland  (035),\
DeKalb*  (037),\
De Witt  (039),\
Douglas  (041),\
DuPage*  (043),\
Edgar  (045),\
Edwards  (047),\
Effingham  (049),\
Fayette  (051),\
Ford  (053),\
Franklin  (055),\
Fulton  (057),\
Gallatin  (059),\
Greene  (061),\
Grundy  (063),\
Hamilton  (065),\
Hancock  (067),\
Hardin  (069),\
Henderson  (071),\
Henry  (073),\
Iroquois  (075),\
Jackson  (077),\
Jasper  (079),\
Jefferson  (081),\
Jersey  (083),\
Jo Daviess  (085),\
Johnson  (087),\
Kane  (089),\
Kankakee  (091),\
Kendall  (093),\
Knox  (095),\
Lake  (097),\
La Salle  (099),\
Lawrence  (101),\
Lee  (103),\
Livingston  (105),\
Logan  (107),\
McDonough  (109),\
McHenry  (111),\
McLean  (113),\
Macon  (115),\
Macoupin  (117),\
Madison  (119),\
Marion  (121),\
Marshall  (123),\
Mason  (125),\
Massac  (127),\
Menard  (129),\
Mercer  (131),\
Monroe  (133),\
Montgomery  (135),\
Morgan  (137),\
Moultrie  (139),\
Ogle  (141),\
Peoria  (143),\
Perry  (145),\
Piatt  (147),\
Pike  (149),\
Pope  (151),\
Pulaski  (153),\
Putnam  (155),\
Randolph  (157),\
Richland  (159),\
Rock Island  (161),\
St. Clair  (163),\
Saline  (165),\
Sangamon  (167),\
Schuyler  (169),\
Scott  (171),\
Shelby  (173),\
Stark  (175),\
Stephenson  (177),\
Tazewell  (179),\
Union  (181),\
Vermilion  (183),\
Wabash  (185),\
Warren  (187),\
Washington  (189),\
Wayne  (191),\
White  (193),\
Whiteside  (195),\
Will  (197),\
Williamson  (199),\
Winnebago  (201),\
Woodford  (203),\
IL,\
IN,\
Adams  (001),\
Allen  (003),\
Bartholomew  (005),\
Benton  (007),\
Blackford  (009),\
Boone  (011),\
Brown  (013),\
Carroll  (015),\
Cass  (017),\
Clark  (019),\
Clay  (021),\
Clinton  (023),\
Crawford  (025),\
Daviess  (027),\
Dearborn  (029),\
Decatur  (031),\
De Kalb  (033),\
Delaware  (035),\
Dubois  (037),\
Elkhart  (039),\
Fayette  (041),\
Floyd  (043),\
Fountain  (045),\
Franklin  (047),\
Fulton  (049),\
Gibson  (051),\
Grant  (053),\
Greene  (055),\
Hamilton  (057),\
Hancock  (059),\
Harrison  (061),\
Hendricks  (063),\
Henry  (065),\
Howard  (067),\
Huntington  (069),\
Jackson  (071),\
Jasper  (073),\
Jay  (075),\
Jefferson  (077),\
Jennings  (079),\
Johnson  (081),\
Knox  (083),\
Kosciusko  (085),\
Lagrange  (087),\
Lake  (089),\
La Porte  (091),\
Lawrence  (093),\
Madison  (095),\
Marion  (097),\
Marshall  (099),\
Martin  (101),\
Miami  (103),\
Monroe  (105),\
Montgomery  (107),\
Morgan  (109),\
Newton  (111),\
Noble  (113),\
Ohio  (115),\
Orange  (117),\
Owen  (119),\
Parke  (121),\
Perry  (123),\
Pike  (125),\
Porter  (127),\
Posey  (129),\
Pulaski  (131),\
Putnam  (133),\
Randolph  (135),\
Ripley  (137),\
Rush  (139),\
St. Joseph  (141),\
Scott  (143),\
Shelby  (145),\
Spencer  (147),\
Starke  (149),\
Steuben  (151),\
Sullivan  (153),\
Switzerland  (155),\
Tippecanoe  (157),\
Tipton  (159),\
Union  (161),\
Vanderburgh  (163),\
Vermillion  (165),\
Vigo  (167),\
Wabash  (169),\
Warren  (171),\
Warrick  (173),\
Washington  (175),\
Wayne  (177),\
Wells  (179),\
White  (181),\
Whitley  (183),\
IN,\
IA,\
Adair  (001),\
Adams  (003),\
Allamakee  (005),\
Appanoose  (007),\
Audubon  (009),\
Benton  (011),\
Black Hawk  (013),\
Boone  (015),\
Bremer  (017),\
Buchanan  (019),\
Buena Vista  (021),\
Butler  (023),\
Calhoun  (025),\
Carroll  (027),\
Cass  (029),\
Cedar  (031),\
Cerro Gordo  (033),\
Cherokee  (035),\
Chickasaw  (037),\
Clarke  (039),\
Clay  (041),\
Clayton  (043),\
Clinton  (045),\
Crawford  (047),\
Dallas  (049),\
Davis  (051),\
Decatur  (053),\
Delaware  (055),\
Des Moines  (057),\
Dickinson  (059),\
Dubuque  (061),\
Emmet  (063),\
Fayette  (065),\
Floyd  (067),\
Franklin  (069),\
Fremont  (071),\
Greene  (073),\
Grundy  (075),\
Guthrie  (077),\
Hamilton  (079),\
Hancock  (081),\
Hardin  (083),\
Harrison  (085),\
Henry  (087),\
Howard  (089),\
Humboldt  (091),\
Ida  (093),\
Iowa  (095),\
Jackson  (097),\
Jasper  (099),\
Jefferson  (101),\
Johnson  (103),\
Jones  (105),\
Keokuk  (107),\
Kossuth  (109),\
Lee  (111),\
Linn  (113),\
Louisa  (115),\
Lucas  (117),\
Lyon  (119),\
Madison  (121),\
Mahaska  (123),\
Marion  (125),\
Marshall  (127),\
Mills  (129),\
Mitchell  (131),\
Monona  (133),\
Monroe  (135),\
Montgomery  (137),\
Muscatine  (139),\
O'Brien  (141),\
Osceola  (143),\
Page  (145),\
Palo Alto  (147),\
Plymouth  (149),\
Pocahontas  (151),\
Polk  (153),\
Pottawattamie  (155),\
Poweshiek  (157),\
Ringgold  (159),\
Sac  (161),\
Scott  (163),\
Shelby  (165),\
Sioux  (167),\
Story  (169),\
Tama  (171),\
Taylor  (173),\
Union  (175),\
Van Buren  (177),\
Wapello  (179),\
Warren  (181),\
Washington  (183),\
Wayne  (185),\
Webster  (187),\
Winnebago  (189),\
Winneshiek  (191),\
Woodbury  (193),\
Worth  (195),\
Wright  (197),\
IA,\
KS,\
Allen  (001),\
Anderson  (003),\
Atchison  (005),\
Barber  (007),\
Barton  (009),\
Bourbon  (011),\
Brown  (013),\
Butler  (015),\
Chase  (017),\
Chautauqua  (019),\
Cherokee  (021),\
Cheyenne  (023),\
Clark  (025),\
Clay  (027),\
Cloud  (029),\
Coffey  (031),\
Comanche  (033),\
Cowley  (035),\
Crawford  (037),\
Decatur  (039),\
Dickinson  (041),\
Doniphan  (043),\
Douglas  (045),\
Edwards  (047),\
Elk  (049),\
Ellis  (051),\
Ellsworth  (053),\
Finney  (055),\
Ford  (057),\
Franklin  (059),\
Geary  (061),\
Gove  (063),\
Graham  (065),\
Grant  (067),\
Gray  (069),\
Greeley  (071),\
Greenwood  (073),\
Hamilton  (075),\
Harper  (077),\
Harvey  (079),\
Haskell  (081),\
Hodgeman  (083),\
Jackson  (085),\
Jefferson  (087),\
Jewell  (089),\
Johnson  (091),\
Kearny  (093),\
Kingman  (095),\
Kiowa  (097),\
Labette  (099),\
Lane  (101),\
Leavenworth  (103),\
Lincoln  (105),\
Linn  (107),\
Logan  (109),\
Lyon  (111),\
McPherson  (113),\
Marion  (115),\
Marshall  (117),\
Meade  (119),\
Miami  (121),\
Mitchell  (123),\
Montgomery  (125),\
Morris  (127),\
Morton  (129),\
Nemaha  (131),\
Neosho  (133),\
Ness  (135),\
Norton  (137),\
Osage  (139),\
Osborne  (141),\
Ottawa  (143),\
Pawnee  (145),\
Phillips  (147),\
Pottawatomie  (149),\
Pratt  (151),\
Rawlins  (153),\
Reno  (155),\
Republic  (157),\
Rice  (159),\
Riley  (161),\
Rooks  (163),\
Rush  (165),\
Russell  (167),\
Saline  (169),\
Scott  (171),\
Sedgwick  (173),\
Seward  (175),\
Shawnee  (177),\
Sheridan  (179),\
Sherman  (181),\
Smith  (183),\
Stafford  (185),\
Stanton  (187),\
Stevens  (189),\
Sumner  (191),\
Thomas  (193),\
Trego  (195),\
Wabaunsee  (197),\
Wallace  (199),\
Washington  (201),\
Wichita  (203),\
Wilson  (205),\
Woodson  (207),\
Wyandotte  (209),\
KS,\
KY,\
Adair  (001),\
Allen  (003),\
Anderson  (005),\
Ballard  (007),\
Barren  (009),\
Bath  (011),\
Bell  (013),\
Boone  (015),\
Bourbon  (017),\
Boyd  (019),\
Boyle  (021),\
Bracken  (023),\
Breathitt  (025),\
Breckinridge  (027),\
Bullitt  (029),\
Butler  (031),\
Caldwell  (033),\
Calloway  (035),\
Campbell  (037),\
Carlisle  (039),\
Carroll  (041),\
Carter  (043),\
Casey  (045),\
Christian  (047),\
Clark  (049),\
Clay  (051),\
Clinton  (053),\
Crittenden  (055),\
Cumberland  (057),\
Daviess  (059),\
Edmonson  (061),\
Elliott  (063),\
Estill  (065),\
Fayette  (067),\
Fleming  (069),\
Floyd  (071),\
Franklin  (073),\
Fulton  (075),\
Gallatin  (077),\
Garrard  (079),\
Grant  (081),\
Graves  (083),\
Grayson  (085),\
Green  (087),\
Greenup  (089),\
Hancock  (091),\
Hardin  (093),\
Harlan  (095),\
Harrison  (097),\
Hart  (099),\
Henderson  (101),\
Henry  (103),\
Hickman  (105),\
Hopkins  (107),\
Jackson  (109),\
Jefferson  (111),\
Jessamine  (113),\
Johnson  (115),\
Kenton  (117),\
Knott  (119),\
Knox  (121),\
Larue  (123),\
Laurel  (125),\
Lawrence  (127),\
Lee  (129),\
Leslie  (131),\
Letcher  (133),\
Lewis  (135),\
Lincoln  (137),\
Livingston  (139),\
Logan  (141),\
Lyon  (143),\
McCracken  (145),\
McCreary  (147),\
McLean  (149),\
Madison  (151),\
Magoffin  (153),\
Marion  (155),\
Marshall  (157),\
Martin  (159),\
Mason  (161),\
Meade  (163),\
Menifee  (165),\
Mercer  (167),\
Metcalfe  (169),\
Monroe  (171),\
Montgomery  (173),\
Morgan  (175),\
Muhlenberg  (177),\
Nelson  (179),\
Nicholas  (181),\
Ohio  (183),\
Oldham  (185),\
Owen  (187),\
Owsley  (189),\
Pendleton  (191),\
Perry  (193),\
Pike  (195),\
Powell  (197),\
Pulaski  (199),\
Robertson  (201),\
Rockcastle  (203),\
Rowan  (205),\
Russell  (207),\
Scott  (209),\
Shelby  (211),\
Simpson  (213),\
Spencer  (215),\
Taylor  (217),\
Todd  (219),\
Trigg  (221),\
Trimble  (223),\
Union  (225),\
Warren  (227),\
Washington  (229),\
Wayne  (231),\
Webster  (233),\
Whitley  (235),\
Wolfe  (237),\
Woodford  (239),\
KY,\
LA,\
Acadia  (001),\
Allen  (003),\
Ascension  (005),\
Assumption  (007),\
Avoyelles  (009),\
Beauregard  (011),\
Bienville  (013),\
Bossier  (015),\
Caddo  (017),\
Calcasieu  (019),\
Caldwell  (021),\
Cameron  (023),\
Catahoula  (025),\
Claiborne  (027),\
Concordia  (029),\
De Soto  (031),\
E. Baton Rouge  (033),\
E. Carroll  (035),\
E. Feliciana  (037),\
Evangeline  (039),\
Franklin  (041),\
Grant  (043),\
Iberia  (045),\
Iberville  (047),\
Jackson  (049),\
Jefferson  (051),\
Jefferson Davis  (053),\
Lafayette  (055),\
Lafourche  (057),\
La Salle  (059),\
Lincoln  (061),\
Livingston  (063),\
Madison  (065),\
Morehouse  (067),\
Natchitoches  (069),\
Orleans  (071),\
Ouachita  (073),\
Plaquemines  (075),\
Pointe Coupee  (077),\
Rapides  (079),\
Red River  (081),\
Richland  (083),\
Sabine  (085),\
St. Bernard  (087),\
St. Charles  (089),\
St. Helena  (091),\
St. James  (093),\
St. John the Baptist  (095),\
St. Landry  (097),\
St. Martin  (099),\
St. Mary  (101),\
St. Tammany  (103),\
Tangipahoa  (105),\
Tensas  (107),\
Terrebonne  (109),\
Union  (111),\
Vermilion  (113),\
Vernon  (115),\
Washington  (117),\
Webster  (119),\
W. Baton Rouge  (121),\
W. Carroll  (123),\
W. Feliciana  (125),\
Winn  (127),\
LA,\
ME,\
Androscoggin  (001),\
Aroostook  (003),\
Cumberland  (005),\
Franklin  (007),\
Hancock  (009),\
Kennebec  (011),\
Knox  (013),\
Lincoln  (015),\
Oxford  (017),\
Penobscot  (019),\
Piscataquis  (021),\
Sagadahoc  (023),\
Somerset  (025),\
Waldo  (027),\
Washington  (029),\
York  (031),\
ME,\
MD,\
Allegany  (001),\
Anne Arundel  (003),\
Baltimore  (005),\
Calvert  (009),\
Caroline  (011),\
Carroll  (013),\
Cecil  (015),\
Charles  (017),\
Dorchester  (019),\
Frederick  (021),\
Garrett  (023),\
Harford  (025),\
Howard  (027),\
Kent  (029),\
Montgomery  (031),\
Prince George's  (033),\
Queen Anne's  (035),\
St. Mary's  (037),\
Somerset  (039),\
Talbot  (041),\
Washington  (043),\
Wicomico  (045),\
Worcester  (047),\
Baltimore; city  (510),\
MD,\
MA,\
Barnstable  (001),\
Berkshire  (003),\
Bristol  (005),\
Dukes  (007),\
Essex  (009),\
Franklin  (011),\
Hampden  (013),\
Hampshire  (015),\
Middlesex  (017),\
Nantucket  (019),\
Norfolk  (021),\
Plymouth  (023),\
Suffolk  (025),\
Worcester  (027),\
MA,\
MB,\
Division (001),\
Division (002),\
Division (003),\
Division (004),\
Division (005),\
Division (006),\
Division (007),\
Division (008),\
Division (009),\
Division (000),\
Division (011),\
Division (012),\
Division (013),\
Division (014),\
Division (015),\
Division (016),\
Division (017),\
Division (018),\
Division (019),\
Division (020),\
Division (021),\
Division (022),\
Division (023),\
MB,\
MI,\
Alcona  (001),\
Alger  (003),\
Allegan  (005),\
Alpena  (007),\
Antrim  (009),\
Arenac  (011),\
Baraga  (013),\
Barry  (015),\
Bay  (017),\
Benzie  (019),\
Berrien  (021),\
Branch  (023),\
Calhoun  (025),\
Cass  (027),\
Charlevoix  (029),\
Cheboygan  (031),\
Chippewa  (033),\
Clare  (035),\
Clinton  (037),\
Crawford  (039),\
Delta  (041),\
Dickinson  (043),\
Eaton  (045),\
Emmet  (047),\
Genesee  (049),\
Gladwin  (051),\
Gogebic  (053),\
Grand Traverse  (055),\
Gratiot  (057),\
Hillsdale  (059),\
Houghton  (061),\
Huron  (063),\
Ingham  (065),\
Ionia  (067),\
Iosco  (069),\
Iron  (071),\
IsabelIa  (073),\
Jackson  (075),\
Kalamazoo  (077),\
Kalkaska  (079),\
Kent  (081),\
Keweenaw  (083),\
Lake  (085),\
Lapeer  (087),\
Leelanau  (089),\
Lenawee  (091),\
Livingston  (093),\
Luce  (095),\
Mackinac  (097),\
Macomb  (099),\
Manistee  (101),\
Marquette  (103),\
Mason  (105),\
Mecosta  (107),\
Menominee  (109),\
Midland  (111),\
Missaukee  (113),\
Monroe  (115),\
Montcalm  (117),\
Montmorency  (119),\
Muskegon  (121),\
Newaygo  (123),\
Oakland  (125),\
Oceana  (127),\
Ogemaw  (129),\
Ontonagon  (131),\
Osceola  (133),\
Oscoda  (135),\
Otsego  (137),\
Ottawa  (139),\
Presque Isle  (141),\
Roscommon  (143),\
Saginaw  (145),\
St. Clair  (147),\
St. Joseph  (149),\
Sanilac  (151),\
Schoolcraft  (153),\
Shiawassee  (155),\
Tuscola  (157),\
Van Buren  (159),\
Washtenaw  (161),\
Wayne  (163),\
Wexford  (165),\
MI,\
MN,\
Aitkin  (001),\
Anoka  (003),\
Becker  (005),\
Beltrami  (007),\
Benton  (009),\
Big Stone  (011),\
Blue Earth  (013),\
Brown  (015),\
Carlton  (017),\
Carver  (019),\
Cass  (021),\
Chippewa  (023),\
Chisago  (025),\
Clay  (027),\
Clearwater  (029),\
Cook  (031),\
Cottonwood  (033),\
Crow Wing  (035),\
Dakota  (037),\
Dodge  (039),\
Douglas  (041),\
Faribault  (043),\
Fillmore  (045),\
Freeborn  (047),\
Goodhue  (049),\
Grant  (051),\
Hennepin  (053),\
Houston  (055),\
Hubbard  (057),\
Isanti  (059),\
Itasca  (061),\
Jackson  (063),\
Kanabec  (065),\
Kandiyohi  (067),\
Kittson  (069),\
Koochiching  (071),\
Lac qui Parle  (073),\
Lake  (075),\
Lake of the Woods  (077),\
Le Sueur  (079),\
Lincoln  (081),\
Lyon  (083),\
McLeod  (085),\
Mahnomen  (087),\
Marshall  (089),\
Martin  (091),\
Meeker  (093),\
Mille Lacs  (095),\
Morrison  (097),\
Mower  (099),\
Murray  (101),\
Nicollet  (103),\
Nobles  (105),\
Norman  (107),\
Olmsted  (109),\
Otter Tail  (111),\
Pennington  (113),\
Pine  (115),\
Pipestone  (117),\
Polk  (119),\
Pope  (121),\
Ramsey  (123),\
Red Lake  (125),\
Redwood  (127),\
Renville  (129),\
Rice  (131),\
Rock  (133),\
Roseau  (135),\
St. Louis  (137),\
Scott  (139),\
Sherburne  (141),\
Sibley  (143),\
Stearns  (145),\
Steele  (147),\
Stevens  (149),\
Swift  (151),\
Todd  (153),\
Traverse  (155),\
Wabasha  (157),\
Wadena  (159),\
Waseca  (161),\
Washington  (163),\
Watonwan  (165),\
Wilkin  (167),\
Winona  (169),\
Wright  (171),\
Yellow Medicine  (173),\
MN,\
MS,\
Adams  (001),\
Alcorn  (003),\
Amite  (005),\
Attala  (007),\
Benton  (009),\
Bolivar  (011),\
Calhoun  (013),\
Carroll  (015),\
Chickasaw  (017),\
Choctaw  (019),\
Claiborne  (021),\
Clarke  (023),\
Clay  (025),\
Coahoma  (027),\
Copiah  (029),\
Covington  (031),\
DeSoto  (033),\
Forrest  (035),\
Franklin  (037),\
George  (039),\
Greene  (041),\
Grenada  (043),\
Hancock  (045),\
Harrison  (047),\
Hinds  (049),\
Holmes  (051),\
Humphreys  (053),\
Issaquena  (055),\
Itawamba  (057),\
Jackson  (059),\
Jasper  (061),\
Jefferson  (063),\
Jefferson Davis  (065),\
Jones  (067),\
Kemper  (069),\
Lafayette  (071),\
Lamar  (073),\
Lauderdale  (075),\
Lawrence  (077),\
Leake  (079),\
Lee  (081),\
Leflore  (083),\
Lincoln  (085),\
Lowndes  (087),\
Madison  (089),\
Marion  (091),\
Marshall  (093),\
Monroe  (095),\
Montgomery  (097),\
Neshoba  (099),\
Newton  (101),\
Noxubee  (103),\
Oktibbeha  (105),\
Panola  (107),\
Pearl River  (109),\
Perry  (111),\
Pike  (113),\
Pontotoc  (115),\
Prentiss  (117),\
Quitman  (119),\
Rankin  (121),\
Scott  (123),\
Sharkey  (125),\
Simpson  (127),\
Smith  (129),\
Stone  (131),\
Sunflower  (133),\
Tallahatchie  (135),\
Tate  (137),\
Tippah  (139),\
Tishomingo  (141),\
Tunica  (143),\
Union  (145),\
Walthall  (147),\
Warren  (149),\
Washington  (151),\
Wayne  (153),\
Webster  (155),\
Wilkinson  (157),\
Winston  (159),\
Yalobusha  (161),\
Yazoo  (163),\
MS,\
MO,\
Adair  (001),\
Andrew  (003),\
Atchison  (005),\
Audrain  (007),\
Barry  (009),\
Barton  (011),\
Bates  (013),\
Benton  (015),\
Bollinger  (017),\
Boone  (019),\
Buchanan  (021),\
Butler  (023),\
Caldwell  (025),\
Callaway  (027),\
Camden  (029),\
Cape Girardeau  (031),\
Carroll  (033),\
Carter  (035),\
Cass  (037),\
Cedar  (039),\
Chariton  (041),\
Christian  (043),\
Clark  (045),\
Clay  (047),\
Clinton  (049),\
Cole  (051),\
Cooper  (053),\
Crawford  (055),\
Dade  (057),\
Dallas  (059),\
Daviess  (061),\
DeKalb  (063),\
Dent  (065),\
Douglas  (067),\
Dunklin  (069),\
Franklin  (071),\
Gasconade  (073),\
Gentry  (075),\
Greene  (077),\
Grundy  (079),\
Harrison  (081),\
Henry  (083),\
Hickory  (085),\
Holt  (087),\
Howard  (089),\
Howell  (091),\
Iron  (093),\
Jackson  (095),\
Jasper  (097),\
Jefferson  (099),\
Johnson  (101),\
Knox  (103),\
Laclede  (105),\
Lafayette  (107),\
Lawrence  (109),\
Lewis  (111),\
Lincoln  (113),\
Linn  (115),\
Livingston  (117),\
McDonald  (119),\
Macon  (121),\
Madison  (123),\
Maries  (125),\
Marion  (127),\
Mercer  (129),\
Miller  (131),\
Mississippi  (133),\
Moniteau  (135),\
Monroe  (137),\
Montgomery  (139),\
Morgan  (141),\
New Madrid  (143),\
Newton  (145),\
Nodaway  (147),\
Oregon  (149),\
Osage  (151),\
Ozark  (153),\
Pemiscot  (155),\
Perry  (157),\
Pettis  (159),\
Phelps  (161),\
Pike  (163),\
Platte  (165),\
Polk  (167),\
Pulaski  (169),\
Putnam  (171),\
Ralls  (173),\
Randolph  (175),\
Ray  (177),\
Reynolds  (179),\
Ripley  (181),\
St. Charles  (183),\
St. Clair  (185),\
Ste. Genevieve  (186),\
St. Francois  (187),\
St. Louis  (189),\
St. Louis - city  (510),\
Saline  (195),\
Schuyler  (197),\
Scotland  (199),\
Scott  (201),\
Shannon  (203),\
Shelby  (205),\
Stoddard  (207),\
Stone  (209),\
Sullivan  (211),\
Taney  (213),\
Texas  (215),\
Vernon  (217),\
Warren  (219),\
Washington  (221),\
Wayne  (223),\
Webster  (225),\
Worth  (227),\
Wright  (229),\
MO,\
MT,\
Beaverhead,(001),\
Big Horn,(003),\
Blaine,(005),\
Broadwater,(007),\
Carbon,(009),\
Carter,(011),\
Cascade,(013),\
Chouteau,(015),\
Custer,(017),\
Daniels,(019),\
Dawson,(021),\
Deer Lodge,(023),\
Fallon,(025),\
Fergus,(027),\
Flathead,(029),\
Gallatin,(031),\
Garfield*,(033),\
Glacier,(035),\
Golden Valley,(037),\
Granite,(039),\
Hill,(041),\
Jefferson,(043),\
Judith Basin,(045),\
Lake,(047),\
Lewis & Clark,(049),\
Liberty,(051),\
Lincoln,(053),\
McCone,(055),\
Madison,(057),\
Meagher,(059),\
Mineral,(061),\
Missoula,(063),\
Musselshell,(065),\
Park,(067),\
Petroleum,(069),\
Phillips,(071),\
Pondera,(073),\
Powder River,(075),\
Powell,(077),\
Prairie,(079),\
Ravalli,(081),\
Richland,(083),\
Roosevelt,(085),\
Rosebud,(087),\
Sanders,(089),\
Sheridan,(091),\
Silver Bow,(093),\
Stillwater,(095),\
Sweet Grass,(097),\
Teton,(099),\
Toole,(101),\
Treasure,(103),\
Valley,(105),\
Wheatland,(107),\
Wibaux,(109),\
Yellowstone,(111),\
MT,\
NB,\
Albert (001),\
Carleton (002),\
Charlotte (003),\
Gloucester (004),\
Kent (005),\
Kings (006),\
Madawaska (007),\
Northumberland (008),\
Queens (009),\
Restigouche (010),\
Saint John (011),\
Sunbury (012),\
Victoria (013),\
Westmorland (014),\
York (015),\
NB,\
NE,\
Adams  (001),\
Antelope  (003),\
Arthur  (005),\
Banner  (007),\
Blaine  (009),\
Boone  (011),\
Box Butte  (013),\
Boyd  (015),\
Brown  (017),\
Buffalo  (019),\
Burt  (021),\
Butler  (023),\
Cass  (025),\
Cedar  (027),\
Chase  (029),\
Cherry  (031),\
Cheyenne  (033),\
Clay  (035),\
Colfax  (037),\
Cuming  (039),\
Custer  (041),\
Dakota  (043),\
Dawes  (045),\
Dawson  (047),\
Deuel  (049),\
Dixon  (051),\
Dodge  (053),\
Douglas  (055),\
Dundy  (057),\
Fillmore  (059),\
Franklin  (061),\
Frontier  (063),\
Furnas  (065),\
Gage  (067),\
Garden  (069),\
Garfield  (071),\
Gosper  (073),\
Grant  (075),\
Greeley  (077),\
Hall  (079),\
Hamilton  (081),\
Harlan  (083),\
Hayes  (085),\
Hitchcock  (087),\
Holt  (089),\
Hooker  (091),\
Howard  (093),\
Jefferson  (095),\
Johnson  (097),\
Kearney  (099),\
Keith  (101),\
Keya Paha  (103),\
Kimball  (105),\
Knox  (107),\
Lancaster  (109),\
Lincoln  (111),\
Logan  (113),\
Loup  (115),\
McPherson  (117),\
Madison  (119),\
Merrick  (121),\
Morrill  (123),\
Nance  (125),\
Nemaha  (127),\
Nuckolls  (129),\
Otoe  (131),\
Pawnee  (133),\
Perkins  (135),\
Phelps  (137),\
Pierce  (139),\
Platte  (141),\
Polk  (143),\
Red Willow  (145),\
Richardson  (147),\
Rock  (149),\
Saline  (151),\
Sarpy  (153),\
Saunders  (155),\
Scotts Bluff  (157),\
Seward  (159),\
Sheridan  (161),\
Sherman  (163),\
Sioux  (165),\
Stanton  (167),\
Thayer  (169),\
Thomas  (171),\
Thurston  (173),\
Valley  (175),\
Washington  (177),\
Wayne  (179),\
Webster  (181),\
Wheeler  (183),\
York  (185),\
NE,\
NV,\
Carson City  (510),\
Churchill  (001),\
Clark  (003),\
Douglas  (005),\
Elko  (007),\
Esmeralda  (009),\
Eureka  (011),\
Humboldt  (013),\
Lander  (015),\
Lincoln  (017),\
Lyon  (019),\
Mineral  (021),\
Nye  (023),\
Pershing  (027),\
Storey  (029),\
Washoe  (031),\
White Pine  (033),\
NV,\
NH,\
Belknap  (001),\
Carroll  (003),\
Cheshire  (005),\
Coos  (007),\
Grafton  (009),\
Hillsborough  (011),\
Merrimack  (013),\
Rockingham  (015),\
Strafford  (017),\
Sullivan  (019),\
NH,\
NJ,\
Atlantic  (001),\
Bergen  (003),\
Burlington  (005),\
Camden  (007),\
Cape May  (009),\
Cumberland  (011),\
Essex  (013),\
Gloucester  (015),\
Hudson  (017),\
Hunterdon  (019),\
Mercer  (021),\
Middlesex  (023),\
Monmouth  (025),\
Morris  (027),\
Ocean  (029),\
Passaic  (031),\
Salem  (033),\
Somerset  (035),\
Sussex  (037),\
Union  (039),\
Warren  (041),\
NJ,\
NM,\
Bernalillo  (001),\
Catron  (003),\
Chaves  (005),\
Cibola  (006),\
Colfax  (007),\
Curry  (009),\
De Baca  (011),\
Dona Ana  (013),\
Eddy  (015),\
Grant  (017),\
Guadalupe  (019),\
Harding  (021),\
Hidalgo  (023),\
Lea  (025),\
Lincoln  (027),\
Los Alamos  (028),\
Luna  (029),\
McKinley  (031),\
Mora  (033),\
Otero  (035),\
Quay  (037),\
Rio Arriba  (039),\
Roosevelt  (041),\
Sandoval  (043),\
San Juan  (045),\
San Miguel  (047),\
Santa Fe  (049),\
Sierra  (051),\
Socorro  (053),\
Taos  (055),\
Torrance  (057),\
Union  (059),\
Valencia  (061),\
NM,\
NY,\
Albany  (001),\
Allegany  (003),\
Bronx  (005),\
Broome  (007),\
Cattaraugus  (009),\
Cayuga  (011),\
Chautauqua  (013),\
Chemung  (015),\
Chenango  (017),\
Clinton  (019),\
Columbia  (021),\
Cortland  (023),\
Delaware  (025),\
Dutchess  (027),\
Erie  (029),\
Essex  (031),\
Franklin  (033),\
Fulton  (035),\
Genesee  (037),\
Greene  (039),\
Hamilton  (041),\
Herkimer  (043),\
Jefferson  (045),\
Kings  (047),\
Lewis  (049),\
Livingston  (051),\
Madison  (053),\
Monroe  (055),\
Montgomery  (057),\
Nassau  (059),\
New York  (061),\
Niagara  (063),\
Oneida  (065),\
Onondaga  (067),\
Ontario  (069),\
Orange  (071),\
Orleans  (073),\
Oswego  (075),\
Otsego  (077),\
Putnam  (079),\
Queens  (081),\
Rensselaer  (083),\
Richmond  (085),\
Rockland  (087),\
St. Lawrence  (089),\
Saratoga  (091),\
Schenectady  (093),\
Schoharie  (095),\
Schuyler  (097),\
Seneca  (099),\
Steuben  (101),\
Suffolk  (103),\
Sullivan  (105),\
Tioga  (107),\
Tompkins  (109),\
Ulster  (111),\
Warren  (113),\
Washington  (115),\
Wayne  (117),\
Westchester  (119),\
Wyoming  (121),\
Yates  (123),\
NY,\
NC,\
Alamance  (001),\
Alexander  (003),\
Alleghany  (005),\
Anson  (007),\
Ashe  (009),\
Avery  (011),\
Beaufort  (013),\
Bertie  (015),\
Bladen  (017),\
Brunswick  (019),\
Buncombe  (021),\
Burke  (023),\
Cabarrus  (025),\
Caldwell  (027),\
Camden  (029),\
Carteret  (031),\
Caswell  (033),\
Catawba  (035),\
Chatham  (037),\
Cherokee  (039),\
Chowan  (041),\
Clay  (043),\
Cleveland  (045),\
Columbus  (047),\
Craven  (049),\
Cumberland  (051),\
Currituck  (053),\
Dare  (055),\
Davidson  (057),\
Davie  (059),\
Duplin  (061),\
Durham  (063),\
Edgecombe  (065),\
Forsyth  (067),\
Franklin  (069),\
Gaston  (071),\
Gates  (073),\
Graham  (075),\
Granville  (077),\
Greene  (079),\
Guilford  (081),\
Halifax  (083),\
Harnett  (085),\
Haywood  (087),\
Henderson  (089),\
Hertford  (091),\
Hoke  (093),\
Hyde  (095),\
Iredell  (097),\
Jackson  (099),\
Johnston  (101),\
Jones  (103),\
Lee  (105),\
Lenoir  (107),\
Lincoln  (109),\
McDowell  (111),\
Macon  (113),\
Madison  (115),\
Martin  (117),\
Mecklenburg  (119),\
Mitchell  (121),\
Montgomery  (123),\
Moore  (125),\
Nash  (127),\
New Hanover  (129),\
Northampton  (131),\
Onslow  (133),\
Orange  (135),\
Pamlico  (137),\
Pasquotank  (139),\
Pender  (141),\
Perquimans  (143),\
Person  (145),\
Pitt  (147),\
Polk  (149),\
Randolph  (151),\
Richmond  (153),\
Robeson  (155),\
Rockingham  (157),\
Rowan  (159),\
Rutherford  (161),\
Sampson  (163),\
Scotland  (165),\
Stanly  (167),\
Stokes  (169),\
Surry  (171),\
Swain  (173),\
Transylvania  (175),\
Tyrrell  (177),\
Union  (179),\
Vance  (181),\
Wake  (183),\
Warren  (185),\
Washington  (187),\
Watauga  (189),\
Wayne  (191),\
Wilkes  (193),\
Wilson  (195),\
Yadkin  (197),\
Yancey  (199),\
NC,\
ND,\
Adams  (001),\
Barnes  (003),\
Benson  (005),\
Billings  (007),\
Bottineau  (009),\
Bowman  (011),\
Burke  (013),\
Burleigh  (015),\
Cass  (017),\
Cavalier  (019),\
Dickey  (021),\
Divide  (023),\
Dunn  (025),\
Eddy  (027),\
Emmons  (029),\
Foster  (031),\
Golden Valley  (033),\
Grand Forks  (035),\
Grant  (037),\
Griggs  (039),\
Hettinger  (041),\
Kidder  (043),\
LaMoure  (045),\
Logan  (047),\
McHenry  (049),\
McIntosh  (051),\
McKenzie  (053),\
McLean  (055),\
Mercer  (057),\
Morton  (059),\
Mountrail  (061),\
Nelson  (063),\
Oliver  (065),\
Pembina  (067),\
Pierce  (069),\
Ramsey  (071),\
Ransom  (073),\
Renville  (075),\
Richland  (077),\
Rolette  (079),\
Sargent  (081),\
Sheridan  (083),\
Sioux  (085),\
Slope  (087),\
Stark  (089),\
Steele  (091),\
Stutsman  (093),\
Towner  (095),\
Traill  (097),\
Walsh  (099),\
Ward  (101),\
Wells  (103),\
Williams  (105),\
ND,\
NF,\
Division (001),\
Division (002),\
Division (003),\
Division (004),\
Division (005),\
Division (006),\
Division (007),\
Division (008),\
Division (009),\
Division (000),\
Division (011),\
NF,\
NS,\
Annapolis (001),\
Antigonish (002),\
Cape Breton (003),\
Colchester (004),\
Cumberland (005),\
Digby (006),\
Guysborough (007),\
Halifax (008),\
Hants (009),\
Inverness (010),\
Kings (011),\
Lunenburg (012),\
Pictou (013),\
Queens (014),\
Richmond (015),\
Shelburne (016),\
Victoria (017),\
Yarmouth (018),\
NS,\
NU,\
Baffin (001),\
Keewatin (002),\
Kitikmeot (003),\
NU,\
NW,\
Fort Smith (001),\
Inuvik (002),\
NW,\
OH,\
Adams  (001),\
Allen  (003),\
Ashland  (005),\
Ashtabula  (007),\
Athens  (009),\
Auglaize  (011),\
Belmont  (013),\
Brown  (015),\
Butler  (017),\
Carroll  (019),\
Champaign  (021),\
Clark  (023),\
Clermont  (025),\
Clinton  (027),\
Columbiana  (029),\
Coshocton  (031),\
Crawford  (033),\
Cuyahoga  (035),\
Darke  (037),\
Defiance  (039),\
Delaware  (041),\
Erie  (043),\
Fairfield  (045),\
Fayette  (O47),\
Franklin  (049),\
Fulton  (051),\
Gallia  (053),\
Geauga  (055),\
Greene  (057),\
Guernsey  (059),\
Hamilton  (061),\
Hancock  (063),\
Hardin  (065),\
Harrison  (067),\
Henry  (069),\
Highland  (071),\
Hocking  (073),\
Holmes  (075),\
Huron  (077),\
Jackson  (079),\
Jefferson  (081),\
Knox  (083),\
Lake  (085),\
Lawrence  (087),\
Licking  (089),\
Logan  (091),\
Lorain  (093),\
Lucas  (095),\
Madison  (097),\
Mahoning  (099),\
Marion  (101),\
Medina  (103),\
Meigs  (105),\
Mercer  (107),\
Miami  (109),\
Monroe  (111),\
Montgomery  (113),\
Morgan  (115),\
Morrow  (117),\
Muskingum  (119),\
Noble  (121),\
Ottawa  (123),\
Paulding  (125),\
Perry  (127),\
Pickaway  (129),\
Pike  (131),\
Portage  (133),\
Preble  (135),\
Putnam  (137),\
Richland  (139),\
Ross  (141),\
Sandusky  (143),\
Scioto  (145),\
Seneca  (147),\
Shelby  (149),\
Stark  (151),\
Summit  (153),\
Trumbull  (155),\
Tuscarawas  (157),\
Union  (159),\
Van Wert  (161),\
Vinton  (163),\
Warren  (165),\
Washington  (167),\
Wayne  (169),\
Williams  (171),\
Wood  (173),\
Wyandot  (175),\
OH,\
OK,\
Adair  (001),\
Alfalfa  (003),\
Atoka  (005),\
Beaver  (007),\
Beckham  (009),\
Blaine  (011),\
Bryan  (013),\
Caddo  (015),\
Canadian  (017),\
Carter  (019),\
Cherokee  (021),\
Choctaw  (023),\
Cimarron  (025),\
Cleveland  (027),\
Coal  (029),\
Comanche  (031),\
Cotton  (033),\
Craig  (035),\
Creek  (037),\
Custer  (039),\
Delaware  (041),\
Dewey  (043),\
Ellis  (045),\
Garfield  (047),\
Garvin  (049),\
Grady  (051),\
Grant  (053),\
Greer  (055),\
Harmon  (057),\
Harper  (059),\
Haskell  (061),\
Hughes  (063),\
Jackson  (065),\
Jefferson  (067),\
Johnston  (069),\
Kay  (071),\
Kingfisher  (073),\
Kiowa  (075),\
Latimer  (077),\
Le Flore  (079),\
Lincoln  (081),\
Logan  (083),\
Love  (085),\
McClain  (087),\
McCurtain  (089),\
McIntosh  (091),\
Major  (093),\
Marshall  (095),\
Mayes  (097),\
Murray  (099),\
Muskogee  (101),\
Noble  (103),\
Nowata  (105),\
Okfuskee  (107),\
Oklahoma  (109),\
Okmulgee  (111),\
Osage  (113),\
Ottawa  (115),\
Pawnee  (117),\
Payne  (119),\
Pittsburg  (121),\
Pontotoc  (123),\
Pottawatomie  (125),\
Pushmataha  (127),\
Roger Mills  (129),\
Rogers  (131),\
Seminole  (133),\
Sequoyah  (135),\
Stephens  (137),\
Texas  (139),\
Tillman  (141),\
Tulsa  (143),\
Wagoner  (145),\
Washington  (147),\
Washita  (149),\
Woods  (151),\
Woodward  (153),\
OK,\
ON,\
Algoma (001),\
Brant (002),\
Bruce (003),\
Cochrane (004),\
Dufferin (005),\
Durham (006),\
Elgin (007),\
Essex (008),\
Frontenac (009),\
Grey (010),\
Haldimand (011),\
Haliburton (011),\
Halton (012),\
Hamilton-Wentworth (013),\
Hastings (014),\
Huron (015),\
Kenora (016),\
Kent (017),\
Lambton (018),\
Lanark (019),\
Leeds and Grenville (020),\
Lennox and Addington (021),\
Manitoulin (022),\
Middlesex (023),\
Muskoka (024),\
Niagara (025),\
Nipissing (026),\
Norfolk (027),\
Northumberland (028),\
Ottawa-Carleton (029),\
Oxford (030),\
Parry Sound (031),\
Peel (032),\
Perth (033),\
Peterborough (034),\
Prescott and Russell (035),\
Prince Edward (036),\
Rainy River (037),\
Renfrew (038),\
Simcoe (039),\
Stormont, Dundas and Glengarry (040),\
Sudbury CA.ON.SB (041),\
Sudbury CA.ON.SU (042),\
Thunder Bay (043),\
Timiskaming (044),\
Toronto (045),\
Victoria (046),\
Waterloo (047),\
Wellington (048),\
York (049),\
ON,\
OR,\
Baker  (001),\
Benton  (003),\
Clackamas  (005),\
Clatsop  (007),\
Columbia  (009),\
Coos  (011),\
Crook  (013),\
Curry  (015),\
Deschutes  (017),\
Douglas  (019),\
Gilliam  (021),\
Grant  (023),\
Harney  (025),\
Hood River  (027),\
Jackson  (029),\
Jefferson  (031),\
Josephine  (033),\
Klamath  (035),\
Lake  (037),\
Lane  (039),\
Lincoln  (041),\
Linn  (043),\
Malheur  (045),\
Marion  (047),\
Morrow  (049),\
Multnomah  (051),\
Polk  (053),\
Sherman  (055),\
Tillamook  (057),\
Umatilla  (059),\
Union  (061),\
Wallowa  (063),\
Wasco  (065),\
Washington  (067),\
Wheeler  (069),\
Yamhill  (071),\
OR,\
PA,\
Adams  (001),\
Allegheny  (003),\
Armstrong  (005),\
Beaver  (007),\
Bedford  (009),\
Berks  (011),\
Blair  (013),\
Bradford  (015),\
Bucks  (017),\
Butler  (019),\
Cambria  (021),\
Cameron  (023),\
Carbon  (025),\
Centre  (027),\
Chester  (029),\
Clarion  (031),\
Clearfield  (033),\
Clinton  (035),\
Columbia  (037),\
Crawford  (039),\
Cumberland  (041),\
Dauphin  (043),\
Delaware  (045),\
Elk  (047),\
Erie  (049),\
Fayette  (051),\
Forest  (053),\
Franklin  (055),\
Fulton  (057),\
Greene  (059),\
Huntingdon  (061),\
Indiana  (063),\
Jefferson  (065),\
Juniata  (067),\
Lackawanna  (069),\
Lancaster  (071),\
Lawrence  (073),\
Lebanon  (075),\
Lehigh  (077),\
Luzerne  (079),\
Lycoming  (081),\
McKean  (083),\
Mercer  (085),\
Mifflin  (087),\
Monroe  (089),\
Montgomery  (091),\
Montour  (093),\
Northampton  (095),\
Northumberland  (097),\
Perry  (099),\
Philadelphia  (101),\
Pike  (103),\
Potter  (105),\
Schuylkill  (107),\
Snyder  (109),\
Somerset  (111),\
Sullivan  (113),\
Susquehanna  (115),\
Tioga  (117),\
Union  (119),\
Venango  (121),\
Warren  (123),\
Washington  (125),\
Wayne  (127),\
Westmoreland  (129),\
Wyoming  (131),\
York  (133),\
PA,\
PE,\
Kings (001),\
Prince (002),\
Queens (003),\
PE,\
RI,\
Bristol  (001),\
Kent  (003 ),\
Newport  (005),\
Providence  (007),\
Washington (009),\
RI,\
QU,\
Abitibi (001),\
Abitibi-Ouest (002),\
Acton (003),\
Antoine-Labelle (004),\
Argenteuil (005),\
Arthabaska (006),\
Asbestos (007),\
Avignon (008),\
Beauce-Sartigan (009),\
Beauharnois-Salaberry (010),\
Bécancour (011),\
Bellechasse (012),\
Bonaventure (013),\
Brome-Missisquoi (014),\
Champlain (015),\
Charlevoix (016),\
Charlevoix-Est (017),\
Coaticook (017),\
Communauté-Urbaine-de-l'Outaouais (018),\
Communauté-Urbaine-de-Montréal (019),\
Communauté-Urbaine-de-Québec (020),\
D'Autray (021),\
Denis-Riverin (022),\
Desjardins (023),\
Deux-Montagnes (024),\
Drummond (025),\
Francheville (026),\
Joliette (027),\
Kamouraska (028),\
La Côte-de-Beaupré (029),\
La Côte-de-Gaspé (030),\
Lac-Saint-Jean-Est (031),\
La Haute-Côte-Nord (032),\
La Haute-Yamaska (033),\
La Jacques-Cartier (034),\
Lajemmerais	CA.QC.LJ (035),\
La Matapédia (036),\
L'Amiante (037),\
La Mitis (038),\
La Nouvelle-Beauce (039),\
La Rivière-du-Nord (040),\
L'Assomption (041),\
Laval (042),\
La Vallée-de-la-Gatineau (043),\
La Vallée-du-Richelieu (044),\
Le Bas-Richelieu (045),\
Le Centre-de-la-Mauricie (046),\
Le Domaine-du-Roy (047),\
Le Fjord-du-Saguenay (048),\
Le Granit (049),\
Le Haut-Richelieu (050),\
Le Haut-Saint-François (051),\
Le Haut-Saint-Laurent (052),\
Le Haut-Saint-Maurice (053),\
L'Érable (054),\
Les Basques (055),\
Les Chutes-de-la-Chaudière (056),\
Les Collines-de-l'Outaouais (057),\
Les Etchemins (058),\
Les Îles-de-la-Madeleine (059),\
Les Jardins-de-Napierville (060),\
Les Laurentides (061),\
Les Maskoutains (062),\
Les Moulins (063),\
Les Pays-d'en-Haut (064),\
Le Val-Saint-François (065),\
L'Île-d'Orléans (066),\
L'Islet (067),\
Lotbinière (068),\
Manicouagan (069),\
Maria-Chapdelaine (070),\
Maskinongé (071),\
Matane (072),\
Matawinie (073),\
Mékinac (074),\
Memphrémagog (075),\
Minganie - Basse-Côte-Nord (076),\
Mirabel (077),\
Montcalm (078),\
Montmagny (079),\
Nicolet-Yamaska (080),\
Nord-du-Québec (081),\
Pabok (082),\
Papineau (082),\
Pontiac (083),\
Portneuf (084),\
Rimouski-Neigette (085),\
Rivière-du-Loup (086),\
Robert-Cliche (087),\
Roussillon (088),\
Rouville (089),\
Rouyn-Noranda (090),\
Sept-Rivières - Caniapiscau (091),\
Sherbrooke (092),\
Témiscamingue (092),\
Témiscouata (093),\
Thérèse-De Blainville (094),\
Vallée-de-l'Or (095),\
Vaudreuil-Soulanges (096),\
QU,\
SA,\
Division (001),\
Division (002),\
Division (003),\
Division (004),\
Division (005),\
Division (006),\
Division (007),\
Division (008),\
Division (009),\
Division (010),\
Division (011),\
Division (012),\
Division (013),\
Division (014),\
Division (015),\
Division (016),\
Division (017),\
Division (018),\
SA,\
SC,\
Abbeville  (001),\
Aiken  (003),\
Allendale  (005),\
Anderson  (007),\
Bamberg  (009),\
Barnwell  (011),\
Beaufort  (013),\
Berkeley  (015),\
Calhoun  (017),\
Charleston  (019),\
Cherokee  (021),\
Chester  (023),\
Chesterfield  (025),\
Clarendon  (027),\
Colleton  (029),\
Darlington  (031),\
Dillon  (033),\
Dorchester  (035),\
Edgefield  (037),\
Fairfield  (039),\
Florence  (041),\
Georgetown  (043),\
Greenville  (045),\
Greenwood  (047),\
Hampton  (049),\
Horry  (051),\
Jasper  (053),\
Kershaw  (055),\
Lancaster  (057),\
Laurens  (059),\
Lee  (061),\
Lexington  (063),\
McCormick  (065),\
Marion  (067),\
Marlboro  (069),\
Newberry  (071),\
Oconee  (073),\
Orangeburg  (075),\
Pickens  (077),\
Richland  (079),\
Saluda  (081),\
Spartanburg  (083),\
Sumter  (085),\
Union  (087),\
Williamsburg  (089),\
York  (091),\
SC,\
SD,\
Aurora  (003),\
Beadle  (005),\
Bennett  (007),\
Bon Homme  (009),\
Brookings  (011),\
Brown  (013),\
Brule  (015),\
Buffalo  (017),\
Butte  (019),\
Campbell  (021),\
Charles Mix  (023),\
Clark  (025),\
Clay  (027),\
Codington  (029),\
Corson  (031),\
Custer  (033),\
Davison  (035),\
Day  (037),\
Deuel  (039),\
Dewey  (041),\
Douglas  (043),\
Edmunds  (045),\
Fall River  (047),\
Faulk  (049),\
Grant  (051),\
Gregory  (053),\
Haakon  (055),\
Hamlin  (057),\
Hand  (059),\
Hanson  (061),\
Harding  (063),\
Hughes  (065),\
Hutchinson  (067),\
Hyde  (069),\
Jackson  (071),\
Jerauld  (073),\
Jones  (075),\
Kingsbury  (077),\
Lake  (079),\
Lawrence  (081),\
Lincoln  (083),\
Lyman  (085),\
McCook  (087),\
McPherson  (089),\
Marshall  (091),\
Meade  (093),\
Mellette  (095),\
Miner  (097),\
Minnehaha  (099),\
Moody  (101),\
Pennington  (103),\
Perkins  (105),\
Potter  (107),\
Roberts  (109),\
Sanborn  (111),\
Shannon  (113),\
Spink  (115),\
Stanley  (117),\
Sully  (119),\
Todd  (121),\
Tripp  (123),\
Turner  (125),\
Union  (127),\
Walworth  (129),\
Yankton  (135),\
Ziebach  (137),\
SD,\
TN,\
Anderson  (001),\
Bedford  (003),\
Benton  (005),\
Bledsoe  (007),\
Blount  (009),\
Bradley  (011),\
Campbell  (013),\
Cannon  (015),\
Carroll  (017),\
Carter  (019),\
Cheatham  (021),\
Chester  (023),\
Claiborne  (025),\
Clay  (027),\
Cocke  (029),\
Coffee  (031),\
Crockett  (033),\
Cumberland  (035),\
Davidson  (037),\
Decatur  (039),\
DeKalb  (041),\
Dickson  (043),\
Dyer  (045),\
Fayette  (047),\
Fentress  (049),\
Franklin  (051),\
Gibson  (053),\
Giles  (055),\
Grainger  (057),\
Greene  (059),\
Grundy  (061),\
Hamblen  (063),\
Hamilton  (065),\
Hancock  (067),\
Hardeman  (069),\
Hardin  (071),\
Hawkins  (073),\
Haywood  (075),\
Henderson  (077),\
Henry  (079),\
Hickman  (081),\
Houston  (083),\
Humphreys  (085),\
Jackson  (087),\
Jefferson  (089),\
Johnson  (091),\
Knox  (093),\
Lake  (095),\
Lauderdale  (097),\
Lawrence  (099),\
Lewis  (101),\
Lincoln  (103),\
Loudon  (105),\
McMinn  (107),\
McNairy  (109),\
Macon  (111),\
Madison  (113),\
Marion  (115),\
Marshall  (117),\
Maury  (119),\
Meigs  (121),\
Monroe  (123),\
Montgomery  (125),\
Moore  (127),\
Morgan  (129),\
Obion  (131),\
Overton  (133),\
Perry  (135),\
Pickett  (137),\
Polk  (139),\
Putnam  (141),\
Rhea  (143),\
Roane  (145),\
Robertson  (147),\
Rutherford  (149),\
Scott  (151),\
Sequatchie  (153),\
Sevier  (155),\
Shelby  (157),\
Smith  (159),\
Stewart  (161),\
Sullivan  (163),\
Sumner  (165),\
Tipton  (167),\
Trousdale  (169),\
Unicoi  (171),\
Union  (173),\
Van Buren  (175),\
Warren  (177),\
Washington  (179),\
Wayne  (181),\
Weakley  (183),\
White  (185),\
Williamson  (187),\
Wilson  (189),\
TN,\
TX,\
Anderson  (001),\
Andrews  (003),\
Angelina  (005),\
Aransas  (007),\
Archer  (009),\
Armstrong  (011),\
Atascosa  (013),\
Austin  (015),\
Bailey  (017),\
Bandera  (019),\
Bastrop  (021),\
Baylor  (023),\
Bee  (025),\
Bell  (027),\
Bexar  (029),\
Blanco  (031),\
Borden  (033),\
Bosque  (035),\
Bowie  (037),\
Brazoria  (039),\
Brazos  (041),\
Brewster  (043),\
Briscoe  (045),\
Brooks  (047),\
Brown  (049),\
Burleson  (051),\
Burnet  (053),\
Caldwell  (055),\
Calhoun  (057),\
Callahan  (059),\
Cameron  (061),\
Camp  (063),\
Carson  (065),\
Cass  (067),\
Castro  (069),\
Chambers  (071),\
Cherokee  (073),\
Childress  (075),\
Clay  (077),\
Cochran  (079),\
Coke  (081),\
Coleman  (083),\
Collin  (085),\
Collingsworth  (087),\
Colorado  (089),\
Comal  (091),\
Comanche  (093),\
Concho  (095),\
Cooke  (097),\
Coryell  (099),\
Cottle  (101),\
Crane  (103),\
Crockett  (105),\
Crosby  (107),\
Culberson  (109),\
Dallam  (111),\
Dallas  (113),\
Dawson  (115),\
Deaf Smith  (117),\
Delta  (119),\
Denton  (121),\
DeWitt  (123),\
Dickens  (125),\
Dimmit  (127),\
Donley  (129),\
Duval  (131),\
Eastland  (133),\
Ector  (135),\
Edwards  (137),\
Ellis  (139),\
El Paso  (141),\
Erath  (143),\
Falls  (145),\
Fannin  (147),\
Fayette  (149),\
Fisher  (151),\
Floyd  (153),\
Foard  (155),\
Fort Bend  (157),\
Franklin  (159),\
Freestone  (161),\
Frio  (163),\
Gaines  (165),\
Galveston  (167),\
Garza  (169),\
Gillespie  (171),\
Glasscock  (173),\
Goliad  (175),\
Gonzales  (177),\
Gray  (179),\
Grayson  (181),\
Gregg  (183),\
Grimes  (185),\
Guadalupe  (187),\
Hale  (189),\
Hall  (191),\
Hamilton  (193),\
Hansford  (195),\
Hardeman  (197),\
Hardin  (199),\
Harris  (201),\
Harrison  (203),\
Hartley  (205),\
Haskell  (207),\
Hays  (209),\
Hemphill  (211),\
Henderson  (213),\
Hidalgo  (215),\
Hill  (217),\
Hockley  (219),\
Hood  (221),\
Hopkins  (223),\
Houston  (225),\
Howard  (227),\
Hudspeth  (229),\
Hunt  (231),\
Hutchinson  (233),\
Irion  (235),\
Jack  (237),\
Jackson  (239),\
Jasper  (241),\
Jeff Davis  (243),\
Jefferson  (245),\
Jim Hogg  (247),\
Jim Wells  (249),\
Johnson  (251),\
Jones  (253),\
Karnes  (255),\
Kaufman  (257),\
Kendall  (259),\
Kenedy  (261),\
Kent  (263),\
Kerr  (265),\
Kimble  (267),\
King  (269),\
Kinney  (271),\
Kleberg  (273),\
Knox  (275),\
Lamar  (277),\
Lamb  (279),\
Lampasas  (281),\
La Salle  (283),\
Lavaca  (285),\
Lee  (287),\
Leon  (289),\
Liberty  (291),\
Limestone  (293),\
Lipscomb  (295),\
Live Oak  (297),\
Llano  (299),\
Loving  (301),\
Lubbock  (303),\
Lynn  (305),\
McCulloch  (307),\
McLennan  (309),\
McMullen  (311),\
Madison  (313),\
Marion  (315),\
Martin  (317),\
Mason  (319),\
Matagorda  (321),\
Maverick  (323),\
Medina  (325),\
Menard  (327),\
Midland  (329),\
Milam  (331),\
Mills  (333),\
Mitchell  (335),\
Montague  (337),\
Montgomery  (339),\
Moore  (341),\
Morris  (343),\
Motley  (345),\
Nacogdoches  (347),\
Navarro  (349),\
Newton  (351),\
Nolan  (353),\
Nueces  (355),\
Ochiltree  (357),\
Oldham  (359),\
Orange  (361),\
Palo Pinto  (363),\
Panola  (365),\
Parker  (367),\
Parmer  (369),\
Pecos  (371),\
Polk  (373),\
Potter  (375),\
Presidio  (377),\
Rains  (379),\
Randall  (381),\
Reagan  (383),\
Real  (385),\
Red River  (387),\
Reeves  (389),\
Refugio  (391),\
Roberts  (393),\
Robertson  (395),\
Rockwall  (397),\
Runnels  (399),\
Rusk  (401),\
Sabine  (403),\
San Augustine  (405),\
San Jacinto  (407),\
San Patricio  (409),\
San Saba  (411),\
Schleicher  (413),\
Scurry  (415),\
Shackelford  (417),\
Shelby  (419),\
Sherman  (421),\
Smith  (423),\
Somervell  (425),\
Starr  (427),\
Stephens  (429),\
Sterling  (431),\
Stonewall  (433),\
Sutton  (435),\
Swisher  (437),\
Tarrant  (439),\
Taylor  (441),\
Terrell  (443),\
Terry  (445),\
Throckmorton  (447),\
Titus  (449),\
Tom Green  (451),\
Travis  (453),\
Trinity  (455),\
Tyler  (457),\
Upshur  (459),\
Upton  (461),\
Uvalde  (463),\
Val Verde  (465),\
Van Zandt  (467),\
Victoria  (469),\
Walker  (471),\
Waller  (473),\
Ward  (475),\
Washington  (477),\
Webb  (479),\
Wharton  (481),\
Wheeler  (483),\
Wichita  (485),\
Wilbarger  (487),\
Willacy  (489),\
Williamson  (491),\
Wilson  (493),\
Winkler  (495),\
Wise  (497),\
Wood  (499),\
Yoakum  (501),\
Young  (503),\
Zapata  (505),\
Zavala  (507),\
TX,\
UT,\
Beaver  (001),\
Box Elder  (003),\
Cache  (005),\
Carbon  (007),\
Daggett  (009),\
Davis  (011),\
Duchesne  (013),\
Emery  (015),\
Garfield  (017),\
Grand  (019),\
Iron  (021),\
Juab  (023),\
Kane  (025),\
Millard  (027),\
Morgan  (029),\
Piute  (031),\
Rich  (033),\
Salt Lake  (035),\
San Juan  (037),\
Sanpete  (039),\
Sevier  (041),\
Summit  (043),\
Tooele  (045),\
Uintah  (047),\
Utah  (049),\
Wasatch  (051),\
Washington  (053),\
Wayne  (055),\
Weber  (057),\
UT,\
VT,\
Addison  (001),\
Bennington  (003),\
Caledonia  (005),\
Chittenden  (007),\
Essex  (009),\
Franklin  (011),\
Grand Isle  (013),\
Lamoille  (015),\
Orange  (017),\
Orleans  (019),\
Rutland  (021),\
Washington  (023),\
Windham  (025),\
Windsor  (027),\
VT,\
VA,\
Accomack  (001),\
Albemarle  (003),\
Alleghany  (005),\
Amelia  (007),\
Amherst  (009),\
Appomattox  (011),\
Arlington  (013),\
Augusta  (015),\
Bath  (017),\
Bedford  (019),\
Bland  (021),\
Botetourt  (023),\
Brunswick  (025),\
Buchanan  (027),\
Buckingham  (029),\
Campbell  (031),\
Caroline  (033),\
Carroll  (035),\
Charles City  (036),\
Charlotte  (037),\
Chesterfield  (041),\
Clarke  (043),\
Craig  (045),\
Culpeper  (047),\
Cumberland  (049),\
Dickenson  (051),\
Dinwiddie  (053),\
Essex  (057),\
Fairfax  (059),\
Fauquier  (061),\
Floyd  (063),\
Fluvanna  (065),\
Franklin  (067),\
Frederick  (069),\
Giles  (071),\
Gloucester  (073),\
Goochland  (075),\
Grayson  (077),\
Greene  (079),\
Greensville  (081),\
Halifax  (083),\
Hanover  (085),\
Henrico  (087),\
Henry  (089),\
Highland  (091),\
Isle of Wight  (093),\
James City  (095),\
King and Queen  (097),\
King George  (099),\
King William  (101),\
Lancaster  (103),\
Lee  (105),\
Loudoun  (107),\
Louisa  (109),\
Lunenburg  (111),\
Madison  (113),\
Mathews  (115),\
Mecklenburg  (117),\
Middlesex  (119),\
Montgomery  (121),\
Nelson  (125),\
New Kent  (127),\
Northampton  (131),\
Northumberland  (133),\
Nottoway  (135),\
Orange  (137),\
Page  (139),\
Patrick  (141),\
Pittsylvania  (143),\
Powhatan  (145),\
Prince Edward  (147),\
Prince George  (149),\
Prince William  (153),\
Pulaski  (155),\
Rappahannock  (157),\
Richmond  (159),\
Roanoke  (161),\
Rockbridge  (163),\
Rockingham  (165),\
Russell  (167),\
Scott  (169),\
Shenandoah  (171),\
Smyth  (173),\
Southampton  (175),\
Spotsylvania  (177),\
Stafford  (179),\
Surry  (181),\
Sussex  (183),\
Tazewell  (185),\
Warren  (187),\
Washington  (191),\
Westmoreland  (193),\
Wise  (195),\
Wythe  (197),\
York  (199),\
Alexandria - city  (510),\
Bedford - city  (515),\
Bristol - city  (520),\
Buena Vista - city  (530),\
Charlottesville - city  (540),\
Chesapeake - city  (550),\
Clifton Forge - city  (560),\
Colonial Heights - city  (570),\
Covington - city  (580),\
Danville - city  (590),\
Emporia - city  (595),\
Fairfax - city  (600),\
Falls Church - city  (610),\
Franklin - city  (620),\
Fredericksburg - city  (630),\
Galax - city  (640),\
Hampton - city  (650),\
Harrisonburg - city  (660),\
Hopewell - city  (670),\
Lexington - city  (678),\
Lynchburg - city  (680),\
Manassas - city  (683),\
Manassas Park - city  (685),\
Martinsville - city  (690),\
Newport News - city  (700),\
Norfolk - city  (710),\
Norton - city  (720),\
Petersburg - city  (730),\
Poquoson - city  (735),\
Portsmouth - city  (740),\
Radford - city  (750),\
Richmond - city  (760),\
Roanoke - city  (770),\
Salem - city  (775),\
South Boston - city  (780),\
Staunton - city  (790),\
Suffolk - city  (800),\
Virginia Beach - city  (810),\
Waynesboro - city  (820),\
Williamsburg - city  (830),\
Winchester - city  (840),\
VA,\
WA,\
Adams  (001),\
Asotin  (003),\
Benton  (005),\
Chelan  (007),\
Clallam  (009),\
Clark  (011),\
Columbia  (013),\
Cowlitz  (015),\
Douglas  (017),\
Ferry  (019),\
Franklin  (021),\
Garfield  (023),\
Grant  (025),\
Grays Harbor  (027),\
Island  (029),\
Jefferson  (031),\
King  (033),\
Kitsap  (035),\
Kittitas  (037),\
Klickitat  (039),\
Lewis  (041),\
Lincoln  (043),\
Mason  (045),\
Okanogan  (047),\
Pacific  (049),\
Pend Oreille  (051),\
Pierce  (053),\
San Juan  (055),\
Skagit  (057),\
Skamania  (059),\
Snohomish  (061),\
Spokane  (063),\
Stevens  (065),\
Thurston  (067),\
Wahkiakum  (069),\
Walla Walla  (071),\
Whatcom  (073),\
Whitman  (075),\
Yakima  (077),\
WA,\
WV,\
Barbour  (001),\
Berkeley  (003),\
Boone  (005),\
Braxton  (007),\
Brooke  (009),\
Cabell  (011),\
Calhoun  (013),\
Clay  (015),\
Doddridge  (017),\
Fayette  (019),\
Gilmer  (021),\
Grant  (023),\
Greenbrier  (025),\
Hampshire  (027),\
Hancock  (029),\
Hardy  (031),\
Harrison  (033),\
Jackson  (035),\
Jefferson  (037),\
Kanawha  (039),\
Lewis  (041),\
Lincoln  (043),\
Logan  (045),\
McDowell  (047),\
Marion  (049),\
Marshall  (051),\
Mason  (053),\
Mercer  (055),\
Mineral  (057),\
Mingo  (059),\
Monongalia  (061),\
Monroe  (063),\
Morgan  (065),\
Nicholas  (067),\
Ohio  (069),\
Pendleton  (071),\
Pleasants  (073),\
Pocahontas  (075),\
Preston  (077),\
Putnam  (079),\
Raleigh  (081),\
Randolph  (083),\
Ritchie  (085),\
Roane  (087),\
Summers  (089),\
Taylor  (091),\
Tucker  (093),\
Tyler  (095),\
Upshur  (097),\
Wayne  (099),\
Webster  (101),\
Wetzel  (103),\
Wirt  (105),\
Wood  (107),\
Wyoming  (109),\
WV,\
WI,\
Adams  (001),\
Ashland  (003),\
Barron  (005),\
Bayfield  (007),\
Brown  (009),\
Buffalo  (011),\
Burnett  (013),\
Calumet  (015),\
Chippewa  (017),\
Clark  (019),\
Columbia  (021),\
Crawford  (023),\
Dane  (025),\
Dodge  (027),\
Door  (029),\
Douglas  (031),\
Dunn  (033),\
Eau Claire  (035),\
Florence  (037),\
Fond du Lac  (039),\
Forest  (041),\
Grant  (043),\
Green  (045),\
Green Lake  (047),\
Iowa  (049),\
Iron  (051),\
Jackson  (053),\
Jefferson  (055),\
Juneau  (057),\
Kenosha  (059),\
Kewaunee  (061),\
La Crosse  (063),\
Lafayette  (065),\
Langlade  (067),\
Lincoln  (069),\
Manitowoc  (071),\
Marathon  (073),\
Marinette  (075),\
Marquette  (077),\
Menominee  (078),\
Milwaukee  (079),\
Monroe  (081),\
Oconto  (083),\
Oneida  (085),\
Outagamie  (087),\
Ozaukee  (089),\
Pepin  (091),\
Pierce  (093),\
Polk  (095),\
Portage  (097),\
Price  (099),\
Racine  (101),\
Richland  (103),\
Rock  (105),\
Rusk  (107),\
St. Croix  (109),\
Sauk  (111),\
Sawyer  (113),\
Shawano  (115),\
Sheboygan  (117),\
Taylor  (119),\
Trempealeau  (121),\
Vernon  (123),\
Vilas  (125),\
Walworth  (127),\
Washburn  (129),\
Washington  (131),\
Waukesha  (133),\
Waupaca  (135),\
Waushara  (137),\
Winnebago  (139),\
Wood  (141),\
WI,\
WY,\
Albany  (001),\
Big Horn  (003),\
Campbell  (005),\
Carbon  (007),\
Converse  (009),\
Crook  (011),\
Fremont  (013),\
Goshen  (015),\
Hot Springs  (017),\
Johnson  (019),\
Laramie  (021),\
Lincoln  (023),\
Natrona  (025),\
Niobrara  (027),\
Park  (029),\
Platte  (031),\
Sheridan  (033),\
Sublette  (035),\
Sweetwater  (037),\
Teton  (039),\
Uinta  (041),\
Washakie  (043),\
Weston  (045),\
WY,\
YU,\
Region (001),\
YU,\
AS,\
Eastern District  (010),\
Swains Island  (040),\
Manu'a District  (020),\
Western District  (050),\
Rose Island  (030),\
AS,\
GU,\
Guam (010),\
GU,\
MP,\
085 Northern Islands  (085),\
100 Rota  (100),\
110 Saipan  (110),\
120 Tinian  (120),\
MP,\
PR,\
Adjuntas  (001),\
Aguada  (003),\
Aguadilla  (005),\
Aguas Buenas  (007),\
Aibonito  (009),\
Anasco  (011),\
Arecibo  (013),\
Arroyo  (015),\
Barceloneta  (017),\
Barranquitas  (019),\
Bayamo'n  (021),\
Cabo Rojo  (023),\
Caguas  (025),\
Camuy  (027),\
Canovanas  (029),\
Carolina  (031),\
Catano  (033),\
Cayey  (035),\
Ceiba  (037),\
Ciales  (039),\
Cidra  (041),\
Coamo  (043),\
Comerio  (045),\
Corozal  (047),\
Culebra  (049),\
Dorado  (051),\
Fajardo  (053),\
Florida  (054),\
Guanica  (055),\
Guayama  (057),\
Guayanilla  (059),\
Guaynabo  (061),\
Gurabo  (063),\
Hatillo  (065),\
Hormigueros  (067),\
Humacao  (069),\
lsabela  (071),\
Jayuya  (073),\
Juana Diaz  (075),\
Juncos  (077),\
Lajas  (079),\
Lares  (081),\
Las Marias  (083),\
Las Piedras  (085),\
Loiza  (087),\
Luquillo  (089),\
Manati  (091),\
Maricao  (093),\
Maunabo  (095),\
Mayaguez  (097),\
Moca  (099),\
Morovis  (101),\
Naguabo  (103),\
Naranjito  (105),\
Orocovis  (107),\
Patillas  (109),\
Penuelas  (111),\
Ponce  (113),\
Quebradillas  (115),\
Rincon  (117),\
Rio Grande  (119),\
Sabana Grande  (121),\
Salinas  (123),\
San German  (125),\
San Juan  (127),\
San Lorenzo  (129),\
San Sebastian  (131),\
Santa Isabel  (133),\
Toa Alta  (135),\
Toa Baja  (137),\
Trujillo Alto  (139),\
Utuado  (141),\
Vega Alta  (143),\
Vega Baja  (145),\
Vieques  (147),\
Villalba  (149),\
Yabucoa  (151),\
Yauco  (153),\
PR,\
PW,\
Aimeliik  (002),\
Airai  (004),\
Melekeok  (212),\
Ngaraard  (214),\
Ngernmlengui  (227),\
Ngiwal  (228),\
PW,\
UM,\
Baker Island  (050),\
Howland Island  (100),\
Jarvis Island  (150),\
Johnston Island  (200),\
Kingman Reef  (250),\
Midway Islands  (300),\
Navassa Island  (350),\
Palmyra Atoll  (400),\
Wake Island  (450),\
UM,\
VI,\
St. Croix  (010),\
St. John  (020),\
St. Thomas  (030),\
Angaur  (010),\
Hatoboheit  (050),\
Kayangel  (100),\
Koror  (150),\
Ngarchelong  (218),\
Ngardmau  (222),\
Ngatpang  (224),\
Ngchesar  (226),\
Peleliu  (350),\
Sonsorol  (370),\
VI,\
FM,\
Chuuk  (002),\
Kosrae  (005),\
Pohnpeit  (040),\
Yap  (060),\
FM,\
MH,\
Ailinginae  (007),\
Ailinglaplap  (010),\
Ailuk  (030),\
Arno  (040),\
Aur  (050),\
Bikar  (060),\
Bikini  (070),\
Bokak  (073),\
Ebon  (080),\
Enewetak  (090),\
Erikub  (100),\
Jabat  (110),\
Jaluit  (120),\
Jemo  (130),\
Kili  (140),\
Kwajalein  (150),\
Lae  (160),\
Lib  (170),\
Likiep  (180),\
Majuro  (190),\
Maloelap  (300),\
Mejit  (310),\
Mili  (320),\
Namorik  (330),\
Namu  (340),\
Rongelap  (350),\
Rongrik  (360),\
Toke  (385),\
Ujae  (390),\
Ujelang  (400),\
Utrik  (410),\
Wotho  (420),\
Wotle  (430),\
MH,";

const std::string states[] = {
"--,State/Province",
"AL,Alabama",
"AB,Alberta",
"AK,Alaska",
"AZ,Arizona",
"AR,Arkansas",
"BC,British Columbia",
"CA,California",
"CO,Colorado",
"CT,Connecticut",
"DE,Delaware",
"DC,District of Columbia",
"FL,Florida",
"GA,Georgia",
"HI,Hawaii",
"ID,Idaho",
"IL,Illinois",
"IN,Indiana",
"IA,Iowa",
"KS,Kansas",
"KY,Kentucky",
"LA,Louisiana",
"ME,Maine",
"MB,Manitoba",
"MD,Maryland",
"MA,Massachusetts",
"MI,Michigan",
"MN,Minnesota",
"MS,Mississippi",
"MO,Missouri",
"MT,Montana",
"NB,New Brunswick",
"NE,Nebraska",
"NV,Nevada",
"NH,New Hampshire",
"NJ,New Jersey",
"NM,New Mexico",
"NY,New York",
"NC,North Carolina",
"ND,North Dakota",
"NS,Nova Scotia",
"NU,Nunavit",
"NW,Northwest Territories",
"OH,Ohio",
"OK,Oklahoma",
"ON,Ontario",
"OR,Oregon",
"PA,Pennsylvania",
"PE,Prince Edward Island",
"QU,Quebec",
"RI,Rhode Island",
"SA,Saskatchewan",
"SC,South Carolina",
"SD,South Dakota",
"TN,Tennessee",
"TX,Texas",
"UT,Utah",
"VT,Vermont",
"VA,Virginia",
"WA,Washington",
"WV,West Virginia",
"WI,Wisconsin",
"WY,Wyoming",
"YU,Yukon",
"AS,America Somoa",
"GU,Guam",
"MP,Northern Mariana Islands",
"PR,Puerto Rico",
"PW,Palua",
"UM,U.S. Minor outlying islands",
"VI,U.S. Virgin Islands",
"FM,Federated States of Micronesia",
"MH,Marshall Islands"
};

int numstates = (int)(sizeof(states) / sizeof(std::string));

const std::string tzones[] = {
"--Time Zone--",
"ACDT, Australian Central Daylight Time, UTC+10:30",
"ACST, Australian Central Standard Time, UTC+09:30",
"ACT, ASEAN Common Time, UTC+08",
"ADT, Atlantic Daylight Time, UTC-03",
"AEDT, Australian Eastern Daylight Time, UTC+11",
"AEST, Australian Eastern Standard Time, UTC+10",
"AFT, Afghanistan Time, UTC+04:30",
"AKDT, Alaska Daylight Time, UTC-08",
"AKST, Alaska Standard Time, UTC-09",
"AMST, Amazon Summer Time (Brazil)[1], UTC-03",
"AMST, Armenia Summer Time, UTC+05",
"AMT, Amazon Time (Brazil)[2], UTC-04",
"AMT, Armenia Time, UTC+04",
"ART, Argentina Time, UTC-03",
"AST, Arabia Standard Time, UTC+03",
"AST, Atlantic Standard Time, UTC-04",
"AWDT, Australian Western Daylight Time, UTC+09",
"AWST, Australian Western Standard Time, UTC+08",
"AZOST, Azores Standard Time, UTC-01",
"AZT, Azerbaijan Time, UTC+04",
"BDT, Brunei Time, UTC+08",
"BIOT, British Indian Ocean Time, UTC+06",
"BIT, Baker Island Time, UTC-12",
"BOT, Bolivia Time, UTC-04",
"BRT, Brasilia Time, UTC-03",
"BST, Bangladesh Standard Time, UTC+06",
"BST, British Summer Time, UTC+01",
"BTT, Bhutan Time, UTC+06",
"CAT, Central Africa Time, UTC+02",
"CCT, Cocos Islands Time, UTC+06:30",
"CDT, Central Daylight Time (North America), UTC-05",
"CDT, Cuba Daylight Time[3], UTC-04",
"CEDT, Central European Daylight Time, UTC+02",
"CEST, Central European Summer Time (Cf. HAEC), UTC+02",
"CET, Central European Time, UTC+01",
"CHADT, Chatham Daylight Time, UTC+13:45",
"CHAST, Chatham Standard Time, UTC+12:45",
"CHOT, Choibalsan, UTC+08",
"ChST, Chamorro Standard Time, UTC+10",
"CHUT, Chuuk Time, UTC+10",
"CIST, Clipperton Island Standard Time, UTC-08",
"CIT, Central Indonesia Time, UTC+08",
"CKT, Cook Island Time, UTC-10",
"CLST, Chile Summer Time, UTC-03",
"CLT, Chile Standard Time, UTC-04",
"COST, Colombia Summer Time, UTC-04",
"COT, Colombia Time, UTC-05",
"CST, Central Standard Time (North America), UTC-06",
"CST, China Standard Time, UTC+08",
"CST, Central Standard Time (Australia), UTC+09:30",
"CST, Central Summer Time (Australia), UTC+10:30",
"CST, Cuba Standard Time, UTC-05",
"CT, China time, UTC+08",
"CVT, Cape Verde Time, UTC-01",
"CWST, Central Western Standard Time (Australia) unofficial, UTC+08:45",
"CXT, Christmas Island Time, UTC+07",
"DAVT, Davis Time, UTC+07",
"DDUT, Dumont d'Urville Time, UTC+10",
"DFT, AIX specific equivalent of Central European Time[4], UTC+01",
"EASST, Easter Island Standard Summer Time, UTC-05",
"EAST, Easter Island Standard Time, UTC-06",
"EAT, East Africa Time, UTC+03",
"ECT, Eastern Caribbean Time (does not recognise DST), UTC-04",
"ECT, Ecuador Time, UTC-05",
"EDT, Eastern Daylight Time (North America), UTC-04",
"EEDT, Eastern European Daylight Time, UTC+03",
"EEST, Eastern European Summer Time, UTC+03",
"EET, Eastern European Time, UTC+02",
"EGST, Eastern Greenland Summer Time, UTC+00",
"EGT, Eastern Greenland Time, UTC-01",
"EIT, Eastern Indonesian Time, UTC+09",
"EST, Eastern Standard Time (North America), UTC-05",
"EST, Eastern Standard Time (Australia), UTC+10",
"FET, Further-eastern European Time, UTC+03",
"FJT, Fiji Time, UTC+12",
"FKST, Falkland Islands Standard Time, UTC-03",
"FKST, Falkland Islands Summer Time, UTC-03",
"FKT, Falkland Islands Time, UTC-04",
"FNT, Fernando de Noronha Time, UTC-02",
"GALT, Galapagos Time, UTC-06",
"GAMT, Gambier Islands, UTC-09",
"GET, Georgia Standard Time, UTC+04",
"GFT, French Guiana Time, UTC-03",
"GILT, Gilbert Island Time, UTC+12",
"GIT, Gambier Island Time, UTC-09",
"GMT, Greenwich Mean Time, UTC",
"GST, South Georgia and the South Sandwich Islands, UTC-02",
"GST, Gulf Standard Time, UTC+04",
"GYT, Guyana Time, UTC-04",
"HADT, Hawaii-Aleutian Daylight Time, UTC-09",
"HAEC, Heure Avancée d'Europe Centrale francised name for CEST, UTC+02",
"HAST, Hawaii-Aleutian Standard Time, UTC-10",
"HKT, Hong Kong Time, UTC+08",
"HMT, Heard and McDonald Islands Time, UTC+05",
"HOVT, Khovd Time, UTC+07",
"HST, Hawaii Standard Time, UTC-10",
"ICT, Indochina Time, UTC+07",
"IDT, Israel Daylight Time, UTC+03",
"IOT, Indian Ocean Time, UTC+03",
"IRDT, Iran Daylight Time, UTC+08",
"IRKT, Irkutsk Time, UTC+09",
"IRST, Iran Standard Time, UTC+03:30",
"IST, Indian Standard Time, UTC+05:30",
"IST, Irish Standard Time[5], UTC+01",
"IST, Israel Standard Time, UTC+02",
"JST, Japan Standard Time, UTC+09",
"KGT, Kyrgyzstan time, UTC+06",
"KOST, Kosrae Time, UTC+11",
"KRAT, Krasnoyarsk Time, UTC+07",
"KST, Korea Standard Time, UTC+09",
"LHST, Lord Howe Standard Time, UTC+10:30",
"LHST, Lord Howe Summer Time, UTC+11",
"LINT, Line Islands Time, UTC+14",
"MAGT, Magadan Time, UTC+12",
"MART, Marquesas Islands Time, UTC-09:30",
"MAWT, Mawson Station Time, UTC+05",
"MDT, Mountain Daylight Time (North America), UTC-06",
"MET, Middle European Time Same zone as CET, UTC+01",
"MEST, Middle European Saving Time Same zone as CEST, UTC+02",
"MHT, Marshall Islands, UTC+12",
"MIST, Macquarie Island Station Time, UTC+11",
"MIT, Marquesas Islands Time, UTC-09:30",
"MMT, Myanmar Time, UTC+06:30",
"MSK, Moscow Time, UTC+04",
"MST, Malaysia Standard Time, UTC+08",
"MST, Mountain Standard Time (North America), UTC-07",
"MST, Myanmar Standard Time, UTC+06:30",
"MUT, Mauritius Time, UTC+04",
"MVT, Maldives Time, UTC+05",
"MYT, Malaysia Time, UTC+08",
"NCT, New Caledonia Time, UTC+11",
"NDT, Newfoundland Daylight Time, UTC-02:30",
"NFT, Norfolk Time, UTC+11:30",
"NPT, Nepal Time, UTC+05:45",
"NST, Newfoundland Standard Time, UTC-03:30",
"NT, Newfoundland Time, UTC-03:30",
"NUT, Niue Time, UTC-11",
"NZDT, New Zealand Daylight Time, UTC+13",
"NZST, New Zealand Standard Time, UTC+12",
"OMST, Omsk Time, UTC+07",
"ORAT, Oral Time, UTC+05",
"PDT, Pacific Daylight Time (North America), UTC-07",
"PET, Peru Time, UTC-05",
"PETT, Kamchatka Time, UTC+12",
"PGT, Papua New Guinea Time, UTC+10",
"PHOT, Phoenix Island Time, UTC+13",
"PHT, Philippine Time, UTC+08",
"PKT, Pakistan Standard Time, UTC+05",
"PMDT, Saint Pierre and Miquelon Daylight time, UTC-02",
"PMST, Saint Pierre and Miquelon Standard Time, UTC-03",
"PONT, Pohnpei Standard Time, UTC+11",
"PST, Pacific Standard Time (North America), UTC-08",
"PYST, Paraguay Summer Time (South America)[6], UTC-03",
"PYT, Paraguay Time (South America)[7], UTC-04",
"RET, Réunion Time, UTC+04",
"ROTT, Rothera Research Station Time, UTC-03",
"SAKT, Sakhalin Island time, UTC+11",
"SAMT, Samara Time, UTC+04",
"SAST, South African Standard Time, UTC+02",
"SBT, Solomon Islands Time, UTC+11",
"SCT, Seychelles Time, UTC+04",
"SGT, Singapore Time, UTC+08",
"SLST, Sri Lanka Time, UTC+05:30",
"SRT, Suriname Time, UTC-03",
"SST, Samoa Standard Time, UTC-11",
"SST, Singapore Standard Time, UTC+08",
"SYOT, Showa Station Time, UTC+03",
"TAHT, Tahiti Time, UTC-10",
"THA, Thailand Standard Time, UTC+07",
"TFT, Indian/Kerguelen, UTC+05",
"TJT, Tajikistan Time, UTC+05",
"TKT, Tokelau Time, UTC+13",
"TLT, Timor Leste Time, UTC+09",
"TMT, Turkmenistan Time, UTC+05",
"TOT, Tonga Time, UTC+13",
"TVT, Tuvalu Time, UTC+12",
"UCT, Coordinated Universal Time, UTC",
"ULAT, Ulaanbaatar Time, UTC+08",
"UTC, Coordinated Universal Time, UTC",
"UYST, Uruguay Summer Time, UTC-02",
"UYT, Uruguay Standard Time, UTC-03",
"UZT, Uzbekistan Time, UTC+05",
"VET, Venezuelan Standard Time, UTC-04:30",
"VLAT, Vladivostok Time, UTC+10",
"VOLT, Volgograd Time, UTC+04",
"VOST, Vostok Station Time, UTC+06",
"VUT, Vanuatu Time, UTC+11",
"WAKT, Wake Island Time, UTC+12",
"WAST, West Africa Summer Time, UTC+02",
"WAT, West Africa Time, UTC+01",
"WEDT, Western European Daylight Time, UTC+01",
"WEST, Western European Summer Time, UTC+01",
"WET, Western European Time, UTC",
"WST, Western Standard Time, UTC+08",
"YAKT, Yakutsk Time, UTC+10",
"YEKT, Yekaterinburg Time, UTC+06",
"Z, Zulu Time (Coordinated Universal Time), UTC"
};

int num_tzones = (int)(sizeof(tzones) / sizeof(std::string));

const std::string us_tzones[] = {
"--Zone--",
"ADT",
"AKDT",
"AKST",
"AST",
"CDT",
"CST",
"EDT",
"EST",
"GMT",
"HADT",
"HAST",
"HST",
"MDT",
"MST",
"PDT",
"PST",
"Z"
"UTC-11",
"UTC-10",
"UTC-09",
"UTC-08",
"UTC-07",
"UTC-06",
"UTC-05",
"UTC-04",
"UTC-03",
"UTC-02",
"UTC-01",
"UTC",
"UTC+01",
"UTC+02",
"UTC+03",
"UTC+04",
"UTC+05",
"UTC+06",
"UTC+07",
"UTC+08",
"UTC+09",
"UTC+10",
"UTC+11"
};

int num_us_tzones = (int)(sizeof(us_tzones) / sizeof(std::string));

const std::string flood_categories[] = {
"--Select flooding category--",
"Minor Street Flooding",
"Low Water Crossings Flooded",
"Widespread Flooding",
"Home/Business Flooded",
"Creek/Stream out of Banks",
"River out of Banks",
"Other (please elaborate below)" };

int num_flood_categories = (int)(sizeof(flood_categories)/sizeof(std::string));

const std::string hail_size[] = {
"--Select Hail size--",
"0.25 (Pea)",
"0.50 (0.5\")",
"0.75 (Penny)",
"0.88 (Nickel)",
"1.00 (Quarter)",
"1.25 (Half Dollar)",
"1.50 (Walnut)",
"1.75 (Golf Ball)",
"2.00 (Hen Egg)",
"2.50 (Tennis Ball)",
"2.75 (Baseball)",
"3.00 (Tea Cup)",
"4.00 (Grapefruit)",
"4.50 (Softball)",
"larger, describe"
};

int num_hail_size = (int)(sizeof(hail_size) / sizeof(std::string));

const std::string wind_speeds[] = {
"--Select Wind speed--",
"50 mph",
"55 mph",
"60 mph",
"65 mph",
"70 mph",
"75 mph",
"80 mph",
"Stronger than 80 mph" };

int num_wind_speeds = (int)(sizeof(wind_speeds)/sizeof(std::string));

const std::string damage[] = {
"--Select Wind Damage Description--",
"Small Tree Limbs Down (<2\")",
"Large Tree Limbs/Branches Down (>=2\")",
"Trees snapped or uprooted",
"Power Lines Down",
"Roof or Structural Damage",
"Other (please elaborate below)" };

int num_damage = (int)(sizeof(damage)/sizeof(std::string));

const std::string snow_tot[] = {
"--Select snow tot--",
"Less than 1\"",
"1\"", "2\"", "3\"", "4\"", "5\"",
"6\"", "7\"", "8\"", "9\"", "10\"",
"11\"", "12\"", "More than 12\"" };

int num_snow_tot = (int)(sizeof(snow_tot)/sizeof(std::string));

const std::string snow_dur[] = {
"--Select duration--",
"15 minutes",
"30 minutes",
"45 minutes",
"1 hour ",
"1 hour 15 minutes",
"1 hour 30 minutes",
"1 hour 45 minutes",
"2 hours ",
"2 hours 15 minutes",
"2 hours 30 minutes",
"3 hours ",
"4 hours ",
"5 hours ",
"6 hours ",
"7 hours ",
"8 hours ",
"9 hours ",
"10 hours ",
"11 hours ",
"12 hours ",
"> 12 hours " };

int num_snow_dur = (int)(sizeof(snow_dur)/sizeof(std::string));

const std::string ice_tot[] = {
"--Select ice total--",
"0.10\"",
"0.20\"",
"0.25\"",
"0.30\"",
"0.40\"",
"0.50\"",
"0.60\"",
"0.70\"",
"0.75\"",
"0.80\"",
"0.90\"",
"1.00\"",
"More than 1\"" };

int num_ice_tot = (int)(sizeof(ice_tot)/sizeof(std::string));

const std::string ice_dur[] = {
"--Select duration--",
"5 minutes",
"10 minutes",
"15 minutes",
"20 minutes",
"30 minutes",
"40 minutes",
"45 minutes",
"50 minutes",
"1 hour ",
"1 hour 15 minutes",
"1 hour 30 minutes",
"1 hour 45 minutes",
"2 hours ",
"2 hours 15 minutes",
"2 hours 30 minutes",
"2 hours 45 minutes",
"3 hours ",
"4 hours ",
"5 hours ",
"6 hours ",
"> 6 hours " };

int num_ice_dur = (int)(sizeof(ice_dur)/sizeof(std::string));

const std::string rainfall[] = {
"--Select rainfall total--",
"0.01-0.09\"",
"0.10-0.24\"",
"0.25-0.49\"",
"0.50-0.74\"",
"0.75-0.99\"",
"1.00-1.24\"",
"1.25-1.49\"",
"1.50-1.74\"",
"1.75-1.99\"",
"2.00-2.24\"",
"2.25-2.49\"",
"2.50-2.74\"",
"2.75-2.99\"",
"3.00-3.24\"",
"3.25-3.49\"",
"3.50-3.74\"",
"3.75-3.99\"",
"4.00\" or more" };

int num_rainfall = (int)(sizeof(rainfall)/sizeof(std::string));

const std::string rainfall_dur[] = {
"--Select duration--",
"5 minutes",
"10 minutes",
"15 minutes",
"20 minutes",
"30 minutes",
"40 minutes",
"45 minutes",
"50 minutes",
"1 hour ",
"1 hour 15 minutes",
"1 hour 30 minutes",
"1 hour 45 minutes",
"2 hours ",
"2 hours 15 minutes",
"2 hours 30 minutes",
"2 hours 45 minutes",
"3 hours ",
"4 hours ",
"5 hours ",
"6 hours ",
"> 6 hours " };

int num_rainfall_dur = (int)(sizeof(rainfall_dur) / sizeof(std::string));

const std::string profiles[] = {
"--Select Profile--",
"COOP Observer",
"Emergency Manager",
"Fire and Rescue",
"General Public",
"HAM Operator",
"Law Enforcement",
"Media",
"NWS Employee",
"NWS Storm Spotter",
"Storm Chaser" };

int num_profiles = (int)(sizeof(profiles) / sizeof(std::string));

const std::string tornado_categories[] = {
"--Select report--",
"Funnel cloud",
"Tornado" };

int num_tornado_categories = (int)(sizeof(tornado_categories) / sizeof(std::string));
