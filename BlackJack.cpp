#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;


int main()
{
	srand((unsigned) time(0));
	int card1, card2, total, card3, deal1, deal2, dtotal;
	char retry = 'y';
	char hit = 'y';
	char cont = 'c';

	while(retry != 'n')
	{
		deal1 = (rand() % 10) + 1;
		dtotal = deal1;
		cout << "The dealer starts with a: " << dtotal << endl;

		card1 = (rand() % 10) + 1;
		card2 = (rand() % 10) + 1;
		cout << "First cards: " << card1 << ", " << card2 << endl;

		total = card1 + card2;
		cout << "Total: " << total << endl;

		while(hit != 'n')
		{
			cout << "Hit? (y/n): ";
			cin >> hit;

			if(hit == 'n')
				break;
		
			card3 = (rand() % 10) + 1;
			cout << "Card: " << card3 << endl;
			total = total + card3;
			cout << "Total: " << total << endl;

			if(total > 21)
			{
				cout << "Bust." << endl;
				hit = 'n';
				break;
			}
		}

		if ((total <= 21))
			cout << "Dealer has a " << deal1 << endl;

		while((total <= 21) && (dtotal < 17))
		{
			if(retry == 'n')
				break;
			cout << "(c to continue) ";
			cin >> cont;

			deal2 = (rand() % 10) + 1;
			cout << "Dealer has gets a " << deal2 << endl;
			dtotal = dtotal + deal2;
			cout << "Total: " << dtotal << endl;

			if (dtotal > 17)
				break;
			else if (dtotal > 21)
			{
				cout << "Bust." << endl;
			}
			else if (dtotal == 21)
			{
				cout << "Dealer Wins!";
				break;
			}
		}
		if ((total <= 21) && (total > dtotal))
		{
			cout << "Player Wins!" << endl;
		}
		else if ((dtotal <= 21) && (dtotal > total))
		{
			cout << "Dealer Wins!" << endl;
		}
		else if (dtotal == total)
		{
			cout << "Push!" << endl;
		}

		cout << "Would you like to try again? (y/n): ";
		cin >> retry;
		hit = 'y';
	}
	return 0;
}
