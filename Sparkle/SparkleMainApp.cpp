#include "Spark.h"

namespace Spark {

	class Sparkle : public Application
	{
	public:
		Sparkle()
		{

		}

		~Sparkle()
		{

		}
		
	};

}

Spark::Application* createApp()
{
	return new Spark::Sparkle();
}