--CET Application
--This file is for creating and populating data into tables

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
drop table Inventory;
drop table Region;
drop table Shipment;
drop table ShipmentDetail;
drop table SupplyType;
drop table User;



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

--inserting data into the table recipe
--insert into CaseReport values ();



--DiseaseType
--creating the Table called DiseaseType
create table DiseaseType(
	id integer NOT NULL primary key,
	name varchar(50) NOT NULL,
	colorIndex integer NOT NULL,
	enabled integer NOT NULL
	);

--inserting data into the table DiseaseType
--insert into DiseaseType values ();



--Inventory
--creating the Table called Inventory
create table Inventory(
	id integer NOT NULL primary key,
	regionId integer NOT NULL references Region(id),
	supplyType integer NOT NULL references SupplyType(id),
	quantity integer NOT NULL
	);

--inserting data into the table Inventory
--insert into Inventory values ();


--Province
--creating the Table called Province
create table Province(
	id integer NOT NULL primary key,
	name varchar(50) NOT NULL
	);

--inserting data into the table Province
insert into Province values(1, "British Columbia");
insert into Province values(2, "Alberta");
insert into Province values(3, "Saskatchewan");
insert into Province values(4, "Manitoba");
insert into Province values(5, "Ontario");
insert into Province values(6, "Quebec");
insert into Province values(7, "Newfoundland and Labrador");
insert into Province values(8, "New Brunswick");
insert into Province values(9, "Nova Scotia");
insert into Province values(10, "Prince Edward Island");
insert into Province values(11, "Yukon");
insert into Province values(12, "Northwest Territories");
insert into Province values(13, "Nunavut");



--Region
--creating the Table called Region
create table Region(
	id integer NOT NULL primary key,
	provinceId integer NOT NULL references Province(id),
	name varchar(50) NOT NULL,
	centerX integer,
	centerY integer,
	polygonPoints varchar(50)
	);

--inserting data into the table Region


--Newfoundland and Labrador
insert into Region values (1011, 7, "Eastern Regional Integrated Health Authority", 0, 0, "(0,0)");
insert into Region values (1012, 7, "Central Regional Integrated Health Authority", 0, 0, "(0,0)");
insert into Region values (1013, 7, "Western Regional Integrated Health Authority", 0, 0, "(0,0)");
insert into Region values (1014, 7, "Labrador-Grenfell Regional Integrated Health Authority", 0, 0, "(0,0)");
--Prince Edward Island
insert into Region values (1111, 10, "Prince Edward Island Health Region", 0, 0, "(0,0)");
insert into Region values (1101, 10, "Kings County", 0, 0, "(0,0)");
insert into Region values (1102, 10, "Queens County", 0, 0, "(0,0)");
insert into Region values (1103, 10, "Prince County", 0, 0, "(0,0)");
--Nova Scotia
insert into Region values (1201, 9, "Zone 1", 0, 0, "(0,0)");
insert into Region values (1202, 9, "Zone 2", 0, 0, "(0,0)");
insert into Region values (1203, 9, "Zone 3", 0, 0, "(0,0)");
insert into Region values (1204, 9, "Zone 4", 0, 0, "(0,0)");
insert into Region values (1205, 9, "Zone 5", 0, 0, "(0,0)");
insert into Region values (1206, 9, "Zone 6", 0, 0, "(0,0)");
--New Brunswick
insert into Region values (1301, 8, "Region 1", 0, 0, "(0,0)");
insert into Region values (1302, 8, "Region 2", 0, 0, "(0,0)");
insert into Region values (1303, 8, "Region 3", 0, 0, "(0,0)");
insert into Region values (1304, 8, "Region 4", 0, 0, "(0,0)");
insert into Region values (1305, 8, "Region 5", 0, 0, "(0,0)");
insert into Region values (1306, 8, "Region 6", 0, 0, "(0,0)");
insert into Region values (1307, 8, "Region 7", 0, 0, "(0,0)");
--Quebec
insert into Region values (2401, 6, "Région du Bas-Saint-Laurent", 0, 0, "(0,0)");
insert into Region values (2402, 6, "Région du Saguenay-Lac-Saint-Jean", 0, 0, "(0,0)");
insert into Region values (2403, 6, "Région de la Capitale Nationale", 0, 0, "(0,0)");
insert into Region values (2404, 6, "Région de la Mauricie et du Centre-du-Québec", 0, 0, "(0,0)");
insert into Region values (2405, 6, "Région de l'Estrie", 0, 0, "(0,0)");
insert into Region values (2406, 6, "Région de Montréal", 0, 0, "(0,0)");
insert into Region values (2407, 6, "Région de l'Outaouais", 0, 0, "(0,0)");
insert into Region values (2408, 6, "Région de l'Abitibi-Témiscamingue", 0, 0, "(0,0)");
insert into Region values (2409, 6, "Région de la Côte-Nord", 0, 0, "(0,0)");
insert into Region values (2410, 6, "Région du Nord-du-Québec", 0, 0, "(0,0)");
insert into Region values (2411, 6, "Région de la Gaspésie-Îles-de-la-Madeleine", 0, 0, "(0,0)");
insert into Region values (2412, 6, "Région de la Chaudière-Appalaches", 0, 0, "(0,0)");
insert into Region values (2413, 6, "Région de Laval", 0, 0, "(0,0)");
insert into Region values (2414, 6, "Région de Lanaudière", 0, 0, "(0,0)");
insert into Region values (2415, 6, "Région des Laurentides", 0, 0, "(0,0)");
insert into Region values (2416, 6, "Région de la Montérégie", 0, 0, "(0,0)");
insert into Region values (2417, 6, "Région du Nunavik", 0, 0, "(0,0)");
insert into Region values (2418, 6, "Région des Terres-Cries-de-la-Baie-James", 0, 0, "(0,0)");
--Ontario
insert into Region values (3526, 5, "The District of Algoma Health Unit", 0, 0, "(0,0)");
insert into Region values (3527, 5, "Brant County Health Unit", 0, 0, "(0,0)");
insert into Region values (3530, 5, "Durham Regional Health Unit", 0, 0, "(0,0)"); 
insert into Region values (3531, 5, "Elgin-St. Thomas Health Unit", 0, 0, "(0,0)");
insert into Region values (3533, 5, "Grey Bruce Health Unit", 0, 0, "(0,0)"); 
insert into Region values (3534, 5, "Haldimand-Norfolk Health Unit", 0, 0, "(0,0)");
insert into Region values (3535, 5, "Haliburton, Kawartha, Pine Ridge District Health Unit", 0, 0, "(0,0)");
insert into Region values (3536, 5, "Halton Regional Health Unit", 0, 0, "(0,0)");
insert into Region values (3537, 5, "City of Hamilton Health Unit", 0, 0, "(0,0)");
insert into Region values (3538, 5, "Hastings and Prince Edward Counties Health Unit", 0, 0, "(0,0)");
insert into Region values (3539, 5, "Huron County Health Unit", 0, 0, "(0,0)");
insert into Region values (3540, 5, "Chatham-Kent Health Unit", 0, 0, "(0,0)");
insert into Region values (3541, 5, "Kingston, Frontenac, and Lennox and Addington Health Unit", 0, 0, "(0,0)");
insert into Region values (3542, 5, "Lambton Health Unit", 0, 0, "(0,0)");
insert into Region values (3543, 5, "Leeds, Grenville and Lanark District Health Unit", 0, 0, "(0,0)");
insert into Region values (3544, 5, "Middlesex-London Health Unit", 0, 0, "(0,0)");
insert into Region values (3546, 5, "Niagara Regional Area Health Unit", 0, 0, "(0,0)");
insert into Region values (3547, 5, "North Bay Parry Sound District Health Unit", 0, 0, "(0,0)");
insert into Region values (3549, 5, "Northwestern Health Unit", 0, 0, "(0,0)");
insert into Region values (3551, 5, "City of Ottawa Health Unit", 0, 0, "(0,0)");
insert into Region values (3552, 5, "Oxford County Health Unit", 0, 0, "(0,0)");
insert into Region values (3553, 5, "Peel Regional Health Unit", 0, 0, "(0,0)");
insert into Region values (3554, 5, "Perth District Health Unit", 0, 0, "(0,0)");
insert into Region values (3555, 5, "Peterborough County-City Health Unit", 0, 0, "(0,0)");
insert into Region values (3556, 5, "Porcupine Health Unit", 0, 0, "(0,0)"); 
insert into Region values (3557, 5, "Renfrew County and District Health Unit", 0, 0, "(0,0)");
insert into Region values (3558, 5, "The Eastern Ontario Health Unit", 0, 0, "(0,0)");
insert into Region values (3560, 5, "Simcoe Muskoka District Health Unit", 0, 0, "(0,0)");
insert into Region values (3561, 5, "Sudbury and District Health Unit", 0, 0, "(0,0)");
insert into Region values (3562, 5, "Thunder Bay District Health Unit", 0, 0, "(0,0)");
insert into Region values (3563, 5, "Timiskaming Health Unit", 0, 0, "(0,0)");
insert into Region values (3565, 5, "Waterloo Health Unit", 0, 0, "(0,0)");
insert into Region values (3566, 5, "Wellington-Dufferin-Guelph Health Unit", 0, 0, "(0,0)");
insert into Region values (3568, 5, "Windsor-Essex County Health Unit", 0, 0, "(0,0)");
insert into Region values (3570, 5, "York Regional Health Unit", 0, 0, "(0,0)");
insert into Region values (3595, 5, "City of Toronto Health Unit", 0, 0, "(0,0)");
--Manitoba
insert into Region values (4610, 4, "Winnipeg Regional Health Authority", 0, 0, "(0,0)");
insert into Region values (4615, 4, "Brandon Regional Health Authority", 0, 0, "(0,0)"); 
insert into Region values (4620, 4, "North Eastman Regional Health Authority", 0, 0, "(0,0)"); 
insert into Region values (4625, 4, "South Eastman Regional Health Authority", 0, 0, "(0,0)");
insert into Region values (4630, 4, "Interlake Regional Health Authority", 0, 0, "(0,0)");
insert into Region values (4640, 4, "Central Regional Health Authority", 0, 0, "(0,0)"); 
insert into Region values (4645, 4, "Assiniboine Regional Health Authority", 0, 0, "(0,0)"); 
insert into Region values (4660, 4, "Parkland Regional Health Authority", 0, 0, "(0,0)"); 
insert into Region values (4670, 4, "Norman Regional Health Authority", 0, 0, "(0,0)"); 
insert into Region values (4680, 4, "Burntwood Regional Health Authority", 0, 0, "(0,0)"); 
insert into Region values (4690, 4, "Churchill Regional Health Authority", 0, 0, "(0,0)");
--Saskatchewan
insert into Region values (4701, 3, "Sun Country Regional Health Authority", 0, 0, "(0,0)");
insert into Region values (4702, 3, "Five Hills Regional Health Authority", 0, 0, "(0,0)");
insert into Region values (4703, 3, "Cypress Regional Health Authority", 0, 0, "(0,0)"); 
insert into Region values (4704, 3, "Regina Qu'Appelle Regional Health Authority", 0, 0, "(0,0)"); 
insert into Region values (4705, 3, "Sunrise Regional Health Authority", 0, 0, "(0,0)");
insert into Region values (4706, 3, "Saskatoon Regional Health Authority", 0, 0, "(0,0)"); 
insert into Region values (4707, 3, "Heartland Regional Health Authority", 0, 0, "(0,0)"); 
insert into Region values (4708, 3, "Kelsey Trail Regional Health Authority", 0, 0, "(0,0)"); 
insert into Region values (4709, 3, "Prince Albert Parkland Regional Health Authority", 0, 0, "(0,0)"); 
insert into Region values (4710, 3, "Prairie North Regional Health Authority", 0, 0, "(0,0)");
insert into Region values (4711, 3, "Mamawetan Churchill River Regional Health Authority", 0, 0, "(0,0)"); 
insert into Region values (4712, 3, "Keewatin Yatthé Regional Health Authority", 0, 0, "(0,0)"); 
insert into Region values (4713, 3, "Athabasca Health Authority", 0, 0, "(0,0)");
--Alberta
insert into Region values (4821, 2, "Chinook Regional Health Authority", 0, 0, "(0,0)");
insert into Region values (4822, 2, "Palliser Health Region", 0, 0, "(0,0)"); 
insert into Region values (4823, 2, "Calgary Health Region", 0, 0, "(0,0)"); 
insert into Region values (4824, 2, "David Thompson Regional Health Authority", 0, 0, "(0,0)"); 
insert into Region values (4825, 2, "East Central Health", 0, 0, "(0,0)");
insert into Region values (4826, 2, "Capital Health", 0, 0, "(0,0)"); 
insert into Region values (4827, 2, "Aspen Regional Health Authority", 0, 0, "(0,0)"); 
insert into Region values (4828, 2, "Peace Country Health", 0, 0, "(0,0)"); 
insert into Region values (4829, 2, "Northern Lights Health Region", 0, 0, "(0,0)");
--British Columbia
insert into Region values (5911, 1, "East Kootenay", 0, 0, "(0,0)");
insert into Region values (5912, 1, "Kootenay-Boundary", 0, 0, "(0,0)"); 
insert into Region values (5913, 1, "Okanagan", 0, 0, "(0,0)"); 
insert into Region values (5914, 1, "Thompson/Cariboo", 0, 0, "(0,0)"); 
insert into Region values (5921, 1, "Fraser East", 0, 0, "(0,0)"); 
insert into Region values (5922, 1, "Fraser North", 0, 0, "(0,0)"); 
insert into Region values (5923, 1, "Fraser South", 0, 0, "(0,0)");
insert into Region values (5931, 1, "Richmond", 0, 0, "(0,0)"); 
insert into Region values (5932, 1, "Vancouver", 0, 0, "(0,0)"); 
insert into Region values (5933, 1, "North Shore/Coast Garibaldi", 0, 0, "(0,0)"); 
insert into Region values (5941, 1, "South Vancouver Island", 0, 0, "(0,0)"); 
insert into Region values (5942, 1, "Central Vancouver Island", 0, 0, "(0,0)"); 
insert into Region values (5943, 1, "North Vancouver Island", 0, 0, "(0,0)");
insert into Region values (5951, 1, "Northwest", 0, 0, "(0,0)"); 
insert into Region values (5952, 1, "Northern Interior", 0, 0, "(0,0)"); 
insert into Region values (5953, 1, "Northeast", 0, 0, "(0,0)");
--Yukon
insert into Region values (6001, 11, "Yukon Territory", 0, 0, "(0,0)");

--Northwest Territories
insert into Region values (6101, 12, "Northwest Territories", 0, 0, "(0,0)");

--Nunavut 
insert into Region values (6201, 13, "Nunavut", 0, 0, "(0,0)");



--Shipment
--creating the Table called Shipment
create table Shipment(
	id integer NOT NULL primary key,
	srcRegion integer NOT NULL references Region(id),
	destRegion integer NOT NULL references Region(id),
	shipmentState varchar(15) NOT NULL,
	createdDate varchar(15) NOT NULL,
	shippedDate varchar(15),
	receivedDate varchar(15),
	cancelledDate varchar(15)
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


--SupplyType
--creating the Table called SupplyType
create table SupplyType(
	id integer NOT NULL primary key,
	name varchar(50) NOT NULL,
	colorIndex integer NOT NULL,
	enabled integer NOT NULL
	);

--inserting data into the table SupplyType
--insert into SupplyType values ();


--User
--creating the Table called User
create table User(
	id integer NOT NULL primary key,
	name varchar(50) NOT NULL,
	passwordHash varchar(50) NOT NULL,
	defaultRegionId integer NOT NULL references Region(id),
	locked int NOT NULL,
	role varchar(15) NOT NULL
	);

--inserting data into the table User
--insert into User values ();