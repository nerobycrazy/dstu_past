struct node{
	Abitur ab;
	node *next;
};

struct Abitur{
	char key[7];
	char fname[30];
	char name[30];
	char oname[30];
	char sex[5];
	char date[30];
	char balls[7];
	char cExam[10];
}; 

struct list{
	int count;
	node li;
};