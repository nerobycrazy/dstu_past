#include "stdafx.h"
#include "new_fig.h"

int main(){

	Rectangle temp1(5);
	cout << "Size   = " << sizeof(&temp1) << endl;
	cout << "Adrs   = " << int(&temp1) << endl;
	cout << "Adrs a = " << int(&temp1.get_a()) << endl;
	cout << "Adrs b = " << int(&temp1.get_b()) << endl;

	cout << "\n\n";

	Circle temp2(3);
	cout << "Size   = " << sizeof(&temp2) << endl;
	cout << "Adrs   = " << int(&temp2) << endl;
	cout << "Adrs r = " << int(&temp2.get_r()) << endl;

	cout << "\n\n";

	Figure *figure[4];
	figure[0] = new Circle(3);
	figure[1] = new Rectangle(5,5);
	figure[2] = new Rectangle(5, 10);
	figure[3] = new Triangle(5.4, 4.4, 3.4);

	for (int i = 0; i < 4; ++i){
		figure[i]->show();
		cout << "\n";
	}

	return 0;
}