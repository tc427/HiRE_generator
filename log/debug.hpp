#pragma once

class Debug
{
	public:
		Debug();
		virtual ~Debug();
		static void setDebug(bool d);
		static bool getDebug();

		static bool debug;


	private:
};
