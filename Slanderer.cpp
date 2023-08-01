#include <iostream>
#include <algorithm>
#include <cctype>

using namespace std;

void aprint(string text) {
	cout << text << " ";
}

int main(int argc, char* argv[]){

	if (argc == 1) {
		cout << "Usage: " << argv[0] << " Amount [Target to slander]" << endl;
		return 0;
	}

	srand((int)time(NULL));

	string subjects[] = {"You", "I", "They", "We"};
	string adverbs[] = {"like", "love", "strive", "want", "need", "desire"};
	string es_adverbs[] = {"wish"};
	string verbs[] = {"eat", "lick", "sniff", "snort", "squish", "crush", "piss on", "fart on", "poo n kak on", "pop a fart on", "contemplate", "examine", "research", "imprison", "retrieve","perform unlicenced experiments on", "sell", "cook", "hunt down", "return", "obliterate"};
	string first_adjective[] = {"copious amounts of", "unreasonably", "horribly", "terribly", "repellingly", "reasonably", "slightly", "very", "extremely", "all of the", "stupidly"};
	string secondary_adjective[] = {"greasy", "disgusting", "smelly", "sweaty", "good-smelling", "tasty", "nice", "shitty", "nerdy", "rancid", "yucky", "decent", "good"};
	string objects[] = {"shit", "feet", "teeth", "eyeballs", "piss", "toilets", "gas station toilets", "discord servers", "reddit moderators", "Cyblu Bots", "nerds", "people", "lines of cocaine", "crystal meth", "create aeronautics release date predictions", "people that say that create aeronautics wont be released", "people that say that create aeronautics developers are on summer break", "people who simply speak the truth", "ketxhup that he stole"};

	int amount = stoi(argv[1]);
	string target = "";
	string adverb_postfix = " to";
	if (argc==3) {
		target = argv[2];
		transform(target.begin(), target.end(), target.begin(),
			[](unsigned char c){ return tolower(c); });
		target[0] = toupper(target[0]);
		adverb_postfix = find( begin(subjects), end(subjects), target) != end(subjects) ? " to" : "s to";
	}	

	for(int i = 0; i < amount; i++) {
		aprint((argc==3) ? target : subjects[rand()%(sizeof(subjects)/sizeof(string))]);
		aprint(adverbs[rand()%(sizeof(adverbs)/sizeof(string))]+adverb_postfix);
		aprint(verbs[rand()%(sizeof(verbs)/sizeof(string))]);
		aprint(first_adjective[rand()%(sizeof(first_adjective)/sizeof(string))]);
		aprint(secondary_adjective[rand()%(sizeof(secondary_adjective)/sizeof(string))]);
		aprint(objects[rand()%(sizeof(objects)/sizeof(string))]);
		cout << endl;
	}

	return 0;
}