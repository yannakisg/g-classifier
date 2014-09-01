#ifndef _INCLUDE_H
#define _INCLUDE_H

struct LinkedList_;

static unsigned int hJob[9] = {
	27942372,
	110709881,
	126929141,
	137595046,
	145254598,
	159346486,
	240836963,
	243398163,
	266278771
};

static unsigned int hEdu[16] = {
	16552,
	214952,
	215208,
	215464,
	59419843,
	80642508,
	90698509,
	145165208,
	166493923,
	173409779,
	179749877,
	211403740,
	212536728,
	224651316,
	235213797,
	246091672
};


static unsigned int hMarital[7] = {
	8435092,
	14060804,
	109630324,
	121981636,
	181302293,
	188870789,
	234581476
};


static unsigned int hOcc[14] = {
	2366322,
	3255203,
	5866179,
	46550185,
	66124100,
	90157747,
	105507575,
	112458460,
	128065463,
	167206342,
	183460358,
	213447644,
	258411141,
	258805204
};

static unsigned int hRel[6] = {
	384965,
	20560580,
	46465317,
	59364324,
	111247449,
	264865796
};

static unsigned int hRace[5] = {
	4794267,
	5680834,
	6156453,
	13299938,
	218180895
};

static unsigned int hSex[2] = {
	342053,
	80492581
};

static unsigned int hCountry[41] = {
	306049,
	325191,
	329854,
	338019,
	355477,
	2102515,
	4845633,
	5144745,
	5262065,
	5277310,
	5285945,
	5926056,
	8617921,
	9185300,
	77088673,
	81298581,
	82361237,
	87879583,
	91629636,
	94899582,
	104610897,
	105630835,
	110868492,
	111445777,
	123330611,
	124012313,
	137977441,
	142051826,
	145521297,
	159918657,
	174793684,
	190133007,
	195787554,
	200440623,
	206448644,
	217887789,
	231290905,
	243278820,
	251273603,
	260089363,
	264558809
};

static unsigned int hIncome[2] = {
	4293821,
	67142845
};

typedef enum {
	Never_worked,
	Without_pay,
	Private,
	Federal_gov,
	State_gov,
	Local_gov,
	Self_emp_not_inc,
	Self_emp_inc
} Job_Category;

typedef enum {
	_9th,
	_10th,
	_11th,
	_12th,
	Masters,
	Prof_school,
	Assoc_acdm,
	_1st_4th,
	Bachelors,
	Assoc_voc,
	Doctorate,
	Preschool,
	_5th_6th,
	HS_grad,
	Some_college,
	_7th_8th
} Education;

typedef enum {
	 Married_spouse_absent,
	 Divorced,
	 Separated,
	 Never_married,
	 Married_civ_spouse,
	 Married_AF_spouse,
	 Widowed
}Marital_Status;

typedef enum {
	Craft_repair,
	Handlers_cleaners,
	Sales,
	Prof_specialty,
	Machine_op_inspct,
	Armed_Forces,
	Farming_fishing,
	Adm_clerical,
	Transport_moving,
	Priv_house_serv,
	Protective_serv,
	Exec_managerial,
	Other_service,
	Tech_support
} Occupation;


typedef enum {
	Male,
	Female
} Gender;

typedef enum {
	Black,
	Other,
	White,
	Asian_Pac_Islander,
	Amer_Indian_Eskimo
} Race;
typedef enum {
	Wife,
	Own_child,
	Other_relative,
	Unmarried,
	Not_in_family,
	Husband
}Relationship;

typedef enum {
	Cuba,
	Hong,
	Iran,
	Laos,
	Peru,
	Philippines,
	China,
	Haiti,
	India,
	Japan,
	Italy,
	South,
	Jamaica,
	Ireland,
	Canada,
	France,
	Greece,
	Mexico,
	Poland,
	Taiwan,
	Columbia,
	Honduras,
	Portugal,
	Yugoslavia,
	Dominican_Republic,
	Outlying_US,
	Cambodia,
	El_Salvador,
	Guatemala,
	Nicaragua,
	Scotland,
	Puerto_Rico,
	Ecuador,
	Trinadad_Tobago,
	England,
	Vietnam,
	Germany,
	Thailand,
	United_States,
	Holand_Netherlands,
	Hungary
}Country;



typedef enum {
	Greater,
	Less
}Income;

typedef struct {
	unsigned short pos;
	unsigned int sampleW;
	unsigned short age;
	Job_Category jobC;
	Education edu;
	unsigned char yearsOfEdu;
	Marital_Status marStatus;
	Occupation occ;
	Gender gender;
	Race race;
	Relationship rship;
	Country country;
	Income income;
	unsigned short capitalG;
	unsigned short capitalL;
	unsigned char hpw;
}Demographic;

#endif
