#include "World01.h"
#include "World02.h"
#include "World03.h"
#include "World04.h"
#include "World05.h"
#include "Core/Core.h"
#include "Framework/Framework.h"
#include "Renderer/Renderer.h"

using namespace std;

int main(int argc, char* argv[])
{
	INFO_LOG("Initialize Engine...")

	//nc::MemoryTracker::Initialize();
	nc::seedRandom((unsigned int)time(nullptr));
	nc::setFilePath("assets");

	ENGINE.Initialize();

	auto world = make_unique<nc::World05>();
	world->Initialize();

	auto su = make_unique<nc::StringUtils>();

	std::string s1 = "Hello there!";

	cout << (s1) << "\n";

	s1 = su->ToUpper(s1);

	cout << (s1) << "\n";

	s1 = su->ToLower(s1);

	cout << (s1) << "\n";

	std::string s2 = s1;

	bool isEqual = su->IsEqualIgnoreCase(s1, s1);

	cout << "Is Equal: " << isEqual << "\n";

	s1 = su->CreateUnique(s1);

	cout << (s1) << "\n";

	s2 = su->CreateUnique(s2);

	cout << (s2) << "\n";

	// main loop
	bool quit = false;
	while (!quit)
	{
		// update
		ENGINE.Update();
		quit = ENGINE.IsQuit();

		world->Update(ENGINE.GetTime().GetDeltaTime());

		// draw
		world->Draw(*ENGINE.GetSystem<nc::Renderer>());
	}

	world->Shutdown();
	ENGINE.Shutdown();

	return 0;
}
