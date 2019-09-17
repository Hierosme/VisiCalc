#ifndef DATA
#define DATA

struct table_s {
	int rows;
	int cols;
	struct cell_s **cells[256][256];
};

struct cell_s {
	int row;
	int col;
	//do I really need this for the simplest version?
	int contents; //based on the number, contains a number, string, or function
	union data_s *data;
};

union data_s {
	double value;
	char *label;
	void (*func)(struct cell_s, struct cell_s, struct table_s);
};

#endif
