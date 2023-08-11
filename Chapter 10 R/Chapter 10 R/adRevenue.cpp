#include <iostream>

struct AdData
{
	int numAds{ 0 };
	double percentClicked{ 0.0 };
	double revenuePer{ 0.0 };
};

void printAdInfo(AdData& data)
{
	std::cout << data.numAds << " ads were shown.\n";
	std::cout << data.percentClicked << "% of the ads were clicked on.\n";
	std::cout << "Each ad clicked on yielded $" << data.revenuePer << " of revenue on average.\n";
	std::cout << "Therefore, the ads yielded approximately $" << data.numAds * data.percentClicked/100 * data.revenuePer << ".\n";
}

AdData enterInfo()
{
	AdData temp;
	std::cout << "How many ads were shown? ";
	std::cin >> temp.numAds;

	std::cout << "What percentage of ads were clicked? ";
	std::cin >> temp.percentClicked;

	std::cout << "What was the average revenue per ad? ";
	std::cin >> temp.revenuePer;

	return temp;
}

#if 0
int main()
{
	AdData ad{ enterInfo() };
	printAdInfo(ad);
	return 0;
}
#endif