#include "../includes/game.hpp"
#include "../includes/InitObjects.hpp"
#include <thread>


int main() {
	InitObjects io;
	Game* pGame = io.init_game();
	std::thread gameTheard(
		[&]()
		{
			pGame->run();
		}
	);
	io.init_level("level_test", pGame);
	gameTheard.join();
	return 0;
}



