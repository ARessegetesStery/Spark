#include "Spark.h"

namespace Spark {

	class SPARK_API Sparkle : public Application
	{
		
	};

}

Spark::Application* createApp()
{
	return new Spark::Sparkle();
}