#include"Header.h"

int main()
{
	Flights myFlight;
	string link;
	cin >> link;
	myFlight.assemble(link);
	myFlight.printCities();
	bool ret= true;
	while (ret)
	{
		cout << "Enter the number city you want to fly from - ";
		int cityWhence;
		cin >> cityWhence;
		cout << "enter the city you want to fly to - ";
		int cityWhere;
		cin >> cityWhere;
		cout << "value - " << myFlight.yourFlight(cityWhence, cityWhere) << endl;
		cout << "try again? 1 - yes | 0 - no  ";
		cin >>ret;
	}

	return 0;
}