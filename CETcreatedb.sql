--CET Application 
--This file is for creating and populating data into tables

--Type: sqlite3 nameofdatabase.extension
--      .read CETcreatedb.sql
--in console

--NOTES
--QSQLITE SQLite version 3 data type | SQL type description 						  | Recommended input (C++ or Qt data type)
--NULL								 | NULL value.	    	 					      | NULL
--									 |												  |
--INTEGER							 | Signed integer, stored in 8, 16, 24, 32, 48,   |	typedef qint8/16/32/64
--									 | or 64-bits depending on the magnitude of the   |
--									 | value.										  |							   
--									 |												  |
--REAL								 | 64-bit floating point value.					  | By default mapping to QString	  
--									 | 												  |
--TEXT								 | Character string (UTF-8, UTF-16BE or  		  | Mapped to QString
--									 | UTF-16-LE).									  |	
--									 |												  |
--CLOB								 | Character large string object				  | Mapped to QString
--									 |												  |
--BLOB								 | The value is a BLOB of data, stored exactly    | Mapped to QByteArray
--									 | as it was input.								  |


--The is delete table if there are table with the same name in the current database
--Will display error if table with the same namwe does not exist, can be ignored

drop table CaseReport;
drop table DiseaseType;
drop table Region;
drop table Shipment;
drop table ShipmentDetail;
drop table Inventory;
drop table SupplyType;
drop table User;
drop table IdNumbers;
drop table Province;


--CaseReport
--creating the Table called CaseReport
create table CaseReport(
	id integer NOT NULL primary key,
	regionId integer NOT NULL references Region(id),
	dateOfReport varchar(15) NOT NULL,
	diseaseType integer NOT NULL references DiseaseType(id),
	correction integer NOT NULL,
	quantity integer NOT NULL
	);

--inserting data into the table CaseReport
insert into CaseReport values (14, 5931, "2010-11-09", 6202, 0, 15);
insert into CaseReport values (15, 5932, "2010-10-12", 6202, 0, 45);
insert into CaseReport values (16, 5932, "2010-10-30", 6203, 0, 16);


--DiseaseType
--creating the Table called DiseaseType
create table DiseaseType(
	id integer NOT NULL primary key,
	name varchar(50) NOT NULL,
	colorIndex integer NOT NULL,
	enabled integer NOT NULL
	);

--inserting data into the table DiseaseType
insert into DiseaseType values (6202, "Smallpox", 0, 1);
insert into DiseaseType values (6203, "Measles", 1, 1);
insert into DiseaseType values (6204, "Yellow Fever", 2, 1);
insert into DiseaseType values (6205, "Influenza", 3, 1);
insert into DiseaseType values (6206, "Cholera", 4, 1);
insert into DiseaseType values (6207, "Typhus", 5, 1);
insert into DiseaseType values (6208, "HIV/AIDS", 7, 1);
insert into DiseaseType values (6209, "H1N1", 8, 1);
insert into DiseaseType values (6210, "Dengue Fever", 9, 1);



--Province
--creating the Table called Province
create table Province(
	id integer NOT NULL primary key,
	name varchar(50) NOT NULL
	);

--inserting data into the table Province
insert into Province values(1, "Alberta");
insert into Province values(2, "British Columbia");
insert into Province values(3, "Manitoba");
insert into Province values(4, "New Brunswick");
insert into Province values(5, "Newfoundland and Labrador");
insert into Province values(6, "Northwest Territories");
insert into Province values(7, "Nova Scotia");
insert into Province values(8, "Nunavut");
insert into Province values(9, "Ontario");
insert into Province values(10, "Prince Edward Island");
insert into Province values(11, "Quebec");
insert into Province values(12, "Saskatchewan");
insert into Province values(13, "Yukon");



--Region
--creating the Table called Region
create table Region(
	id integer NOT NULL primary key,
	provinceId integer NOT NULL references Province(id),
	name varchar(50) NOT NULL,
	centerX integer,
	centerY integer
	);

--inserting data into the table Region


--Newfoundland and Labrador
insert into Region values (1011, 5, "Eastern Regional Integrated Health Authority", 0, 0);
insert into Region values (1012, 5, "Central Regional Integrated Health Authority", 0, 0);
insert into Region values (1013, 5, "Western Regional Integrated Health Authority", 0, 0);
insert into Region values (1014, 5, "Labrador-Grenfell Regional Integrated Health Authority", 0, 0);
--Prince Edward Island
insert into Region values (1111, 10, "Prince Edward Island Health Region", 0, 0);
insert into Region values (1101, 10, "Kings County", 0, 0);
insert into Region values (1102, 10, "Queens County", 0, 0);
insert into Region values (1103, 10, "Prince County", 0, 0);
--Nova Scotia
--insert into Region values (1201, 7, "Zone 1", 0, 0);
--insert into Region values (1202, 7, "Zone 2", 0, 0);
--insert into Region values (1203, 7, "Zone 3", 0, 0);
--insert into Region values (1204, 7, "Zone 4", 0, 0);
--insert into Region values (1205, 7, "Zone 5", 0, 0);
--insert into Region values (1206, 7, "Zone 6", 0, 0);
insert into Region values (1211, 7, "DHA1", 0, 0);
insert into Region values (1212, 7, "DHA2", 0, 0);
insert into Region values (1213, 7, "DHA3", 0, 0);
insert into Region values (1214, 7, "DHA4", 0, 0);
insert into Region values (1215, 7, "DHA5", 0, 0);
insert into Region values (1216, 7, "DHA6", 0, 0);
insert into Region values (1217, 7, "DHA7", 0, 0);
insert into Region values (1218, 7, "DHA8", 0, 0);
insert into Region values (1219, 7, "DHA9", 0, 0);
--New Brunswick
insert into Region values (1301, 4, "Region 1", 0, 0);
insert into Region values (1302, 4, "Region 2", 0, 0);
insert into Region values (1303, 4, "Region 3", 0, 0);
insert into Region values (1304, 4, "Region 4", 0, 0);
insert into Region values (1305, 4, "Region 5", 0, 0);
insert into Region values (1306, 4, "Region 6", 0, 0);
insert into Region values (1307, 4, "Region 7", 0, 0);
--Quebec
insert into Region values (2401, 11, "Région du Bas-Saint-Laurent", 0, 0);
insert into Region values (2402, 11, "Région du Saguenay-Lac-Saint-Jean", 0, 0);
insert into Region values (2403, 11, "Région de la Capitale Nationale", 0, 0);
insert into Region values (2404, 11, "Région de la Mauricie et du Centre-du-Québec", 0, 0);
insert into Region values (2405, 11, "Région de l'Estrie", 0, 0);
insert into Region values (2406, 11, "Région de Montréal", 0, 0);
insert into Region values (2407, 11, "Région de l'Outaouais", 0, 0);
insert into Region values (2408, 11, "Région de l'Abitibi-Témiscamingue", 0, 0);
insert into Region values (2409, 11, "Région de la Côte-Nord", 0, 0);
insert into Region values (2410, 11, "Région du Nord-du-Québec", 0, 0);
insert into Region values (2411, 11, "Région de la Gaspésie-Îles-de-la-Madeleine", 0, 0);
insert into Region values (2412, 11, "Région de la Chaudière-Appalaches", 0, 0);
insert into Region values (2413, 11, "Région de Laval", 0, 0);
insert into Region values (2414, 11, "Région de Lanaudière", 0, 0);
insert into Region values (2415, 11, "Région des Laurentides", 0, 0);
insert into Region values (2416, 11, "Région de la Montérégie", 0, 0);
insert into Region values (2417, 11, "Région du Nunavik", 0, 0);
insert into Region values (2418, 11, "Région des Terres-Cries-de-la-Baie-James", 0, 0);
--Ontario
--insert into Region values (3526, 9, "The District of Algoma Health Unit", 0, 0);
--insert into Region values (3527, 9, "Brant County Health Unit", 0, 0);
--insert into Region values (3530, 9, "Durham Regional Health Unit", 0, 0); 
--insert into Region values (3531, 9, "Elgin-St. Thomas Health Unit", 0, 0);
--insert into Region values (3533, 9, "Grey Bruce Health Unit", 0, 0; 
--insert into Region values (3534, 9, "Haldimand-Norfolk Health Unit", 0, 0);
--insert into Region values (3535, 9, "Haliburton, Kawartha, Pine Ridge District Health Unit", 0, 0);
--insert into Region values (3536, 9, "Halton Regional Health Unit", 0, 0);
--insert into Region values (3537, 9, "City of Hamilton Health Unit", 0, 0;
--insert into Region values (3538, 9, "Hastings and Prince Edward Counties Health Unit", 0, 0);
--insert into Region values (3539, 9, "Huron County Health Unit", 0, 0);
--insert into Region values (3540, 9, "Chatham-Kent Health Unit", 0, 0);
--insert into Region values (3541, 9, "Kingston, Frontenac, and Lennox and Addington Health Unit", 0, 0);
--insert into Region values (3542, 9, "Lambton Health Unit", 0, 0);
--insert into Region values (3543, 9, "Leeds, Grenville and Lanark District Health Unit", 0, 0);
--insert into Region values (3544, 9, "Middlesex-London Health Unit", 0, 0);
--insert into Region values (3546, 9, "Niagara Regional Area Health Unit", 0, 0);
--insert into Region values (3547, 9, "North Bay Parry Sound District Health Unit", 0, 0);
--insert into Region values (3549, 9, "Northwestern Health Unit", 0, 0);
--insert into Region values (3551, 9, "City of Ottawa Health Unit", 0, 0);
--insert into Region values (3552, 9, "Oxford County Health Unit", 0, 0);
--insert into Region values (3553, 9, "Peel Regional Health Unit", 0, 0);
--insert into Region values (3554, 9, "Perth District Health Unit", 0, 0);
--insert into Region values (3555, 9, "Peterborough County-City Health Unit", 0, 0);
--insert into Region values (3556, 9, "Porcupine Health Unit", 0, 0); 
--insert into Region values (3557, 9, "Renfrew County and District Health Unit", 0, 0);
--insert into Region values (3558, 9, "The Eastern Ontario Health Unit", 0, 0);
--insert into Region values (3560, 9, "Simcoe Muskoka District Health Unit", 0, 0);
--insert into Region values (3561, 9, "Sudbury and District Health Unit", 0, 0);
--insert into Region values (3562, 9, "Thunder Bay District Health Unit", 0, 0);
--insert into Region values (3563, 9, "Timiskaming Health Unit", 0, 0);
--insert into Region values (3565, 9, "Waterloo Health Unit", 0, 0);
--insert into Region values (3566, 9, "Wellington-Dufferin-Guelph Health Unit", 0, 0);
--insert into Region values (3568, 9, "Windsor-Essex County Health Unit", 0, 0);
--insert into Region values (3570, 9, "York Regional Health Unit", 0, 0);
--insert into Region values (3595, 9, "City of Toronto Health Unit", 0, 0);
insert into Region values (3501, 9, "Erie St. Clair", 0, 0);
insert into Region values (3502, 9, "South West", 0, 0);
insert into Region values (3503, 9, "Waterloo Wellington", 0, 0);
insert into Region values (3504, 9, "Hamilton Niagara Haldimand Brant", 0, 0);
insert into Region values (3505, 9, "Central West", 0, 0);
insert into Region values (3506, 9, "Mississauga Halton", 0, 0);
insert into Region values (3507, 9, "Toronto Central", 0, 0);
insert into Region values (3508, 9, "Central", 0, 0);
insert into Region values (3509, 9, "Central East", 0, 0);
insert into Region values (3510, 9, "South East", 0, 0);
insert into Region values (3511, 9, "Champlain", 0, 0);
insert into Region values (3512, 9, "North Simcoe Muskoka", 0, 0);
insert into Region values (3513, 9, "North East", 0, 0);
insert into Region values (3514, 9, "North West", 0, 0);
--Manitoba
insert into Region values (4610, 3, "Winnipeg Regional Health Authority", 0, 0);
insert into Region values (4615, 3, "Brandon Regional Health Authority", 0, 0); 
insert into Region values (4620, 3, "North Eastman Regional Health Authority", 0, 0); 
insert into Region values (4625, 3, "South Eastman Regional Health Authority", 0, 0);
insert into Region values (4630, 3, "Interlake Regional Health Authority", 0, 0);
insert into Region values (4640, 3, "Central Regional Health Authority", 0, 0); 
insert into Region values (4645, 3, "Assiniboine Regional Health Authority", 0, 0); 
insert into Region values (4660, 3, "Parkland Regional Health Authority", 0, 0); 
insert into Region values (4670, 3, "Norman Regional Health Authority", 0, 0); 
insert into Region values (4680, 3, "Burntwood Regional Health Authority", 0, 0); 
insert into Region values (4690, 3, "Churchill Regional Health Authority", 0, 0);
--Saskatchewan
insert into Region values (4701, 12, "Sun Country Regional Health Authority", 0, 0);
insert into Region values (4702, 12, "Five Hills Regional Health Authority", 0, 0);
insert into Region values (4703, 12, "Cypress Regional Health Authority", 0, 0); 
insert into Region values (4704, 12, "Regina Qu'Appelle Regional Health Authority", 0, 0); 
insert into Region values (4705, 12, "Sunrise Regional Health Authority", 0, 0);
insert into Region values (4706, 12, "Saskatoon Regional Health Authority", 0, 0); 
insert into Region values (4707, 12, "Heartland Regional Health Authority", 0, 0); 
insert into Region values (4708, 12, "Kelsey Trail Regional Health Authority", 0, 0); 
insert into Region values (4709, 12, "Prince Albert Parkland Regional Health Authority", 0, 0); 
insert into Region values (4710, 12, "Prairie North Regional Health Authority", 0, 0);
insert into Region values (4711, 12, "Mamawetan Churchill River Regional Health Authority", 0, 0); 
insert into Region values (4712, 12, "Keewatin Yatthé Regional Health Authority", 0, 0); 
insert into Region values (4713, 12, "Athabasca Health Authority", 0, 0);
--Alberta
insert into Region values (4821, 1, "Chinook Regional Health Authority", 0, 0);
insert into Region values (4822, 1, "Palliser Health Region", 0, 0); 
insert into Region values (4823, 1, "Calgary Health Region", 0, 0); 
insert into Region values (4824, 1, "David Thompson Regional Health Authority", 0, 0); 
insert into Region values (4825, 1, "East Central Health", 0, 0);
insert into Region values (4826, 1, "Capital Health", 0, 0); 
insert into Region values (4827, 1, "Aspen Regional Health Authority", 0, 0); 
insert into Region values (4828, 1, "Peace Country Health", 0, 0); 
insert into Region values (4829, 1, "Northern Lights Health Region", 0, 0);
--British Columbia
insert into Region values (5911, 2, "East Kootenay", 0, 0);
insert into Region values (5912, 2, "Kootenay-Boundary", 0, 0); 
insert into Region values (5913, 2, "Okanagan", 0, 0); 
insert into Region values (5914, 2, "Thompson/Cariboo", 0, 0); 
insert into Region values (5921, 2, "Fraser East", 0, 0); 
insert into Region values (5922, 2, "Fraser North", 0, 0); 
insert into Region values (5923, 2, "Fraser South", 0, 0);
insert into Region values (5931, 2, "Richmond", 0, 0); 
insert into Region values (5932, 2, "Vancouver", 0, 0); 
insert into Region values (5933, 2, "North Shore/Coast Garibaldi", 0, 0); 
insert into Region values (5941, 2, "South Vancouver Island", 0, 0); 
insert into Region values (5942, 2, "Central Vancouver Island", 0, 0); 
insert into Region values (5943, 2, "North Vancouver Island", 0, 0);
insert into Region values (5951, 2, "Northwest", 0, 0); 
insert into Region values (5952, 2, "Northern Interior", 0, 0); 
insert into Region values (5953, 2, "Northeast", 0, 0);
--Yukon
insert into Region values (6001, 13, "Yukon Territory", 0, 0);

--Northwest Territories
insert into Region values (6101, 6, "Northwest Territories", 0, 0);

--Nunavut 
insert into Region values (6201, 8, "Nunavut", 0, 0);



--Shipment
--creating the Table called Shipment
create table Shipment(
	id integer NOT NULL primary key,
	srcRegion integer NOT NULL references Region(id),
	destRegion integer NOT NULL references Region(id),
	shipmentState int NOT NULL,
	createdDate varchar(15) NOT NULL,
	shippedDate varchar(15),
	receivedDate varchar(15),
	cancelledDate varchar(15),
	notes text
	);

--inserting data into the table Shipment
--insert into Shipment values ();



--ShipmentDetail
--creating the Table called ShipmentDetail
create table ShipmentDetail(
	id integer NOT NULL primary key,
	shipmentId integer NOT NULL references Shipment(id),
	supplyType integer NOT NULL references SupplyType(id),
	quantityRequested int NOT NULL,
	quantityShipped int NOT NULL
	);

--inserting data into the table ShipmentDetail
--insert into ShipmentDetail values ();


--Inventory
--creating the Table called Inventory
create table Inventory(
	id integer NOT NULL primary key,
	regionId integer NOT NULL references Region(id),
	supplyType integer NOT NULL references SupplyType(id),
	quantity integer, 
	required integer
	);

--inserting data into the table Inventory
insert into Inventory values (17, 6001, 6211, 15, 40);
insert into Inventory values (18, 5931, 6212, 9, 10);
insert into Inventory values (19, 5932, 6213, null, 49);


--SupplyType
--creating the Table called SupplyType
create table SupplyType(
	id integer NOT NULL primary key,
	name varchar(50) NOT NULL,
	colorIndex integer NOT NULL,
	enabled integer NOT NULL
	);

--inserting data into the table SupplyType
insert into SupplyType values (6211, "Tamiflu", 0, 1);
insert into SupplyType values (6212, "ECMO", 1, 1);
insert into SupplyType values (6213, "Dialysis Machine", 2, 1);
insert into SupplyType values (6214, "Medical Ventilator", 3, 1);
insert into SupplyType values (6215, "Ibuprofen", 4, 1);
insert into SupplyType values (6216, "YF-Vax", 5, 1);
insert into SupplyType values (6217, "Vibramycin", 6, 1);
insert into SupplyType values (6218, "Abacavir", 7, 1);
insert into SupplyType values (6219, "Symmetrel", 8, 1);
insert into SupplyType values (6220, "Panadol", 9, 1);

--User
--creating the Table called User
create table User(
	id integer NOT NULL primary key,
	name varchar(50) NOT NULL,
	passwordHash varchar(50) NOT NULL,
	defaultRegionId integer NOT NULL references Region(id),
	locked int NOT NULL,
	role int NOT NULL
	);

--inserting data into the table User
insert into User values (6221, "Paulina", "abc", 5, 0, 1);
insert into User values (6222, "Mike", "abc", 5, 0, 0);
insert into User values (6223, "Spencer", "abc", 5, 0, 1);
insert into User values (6224, "Gavin", "abc", 5, 0, 2);


--IdNumbers
--creating the Table called IdNumbers
--Numbers will appear here when new entities are created
create table IdNumbers(
	id integer NOT NULL primary key
);

--inserting data into the table recipe
insert into IdNumbers values (6224);