#ifndef Debug_h
#define Debug_h

#include "Arduino.h"

class Debug {
	public:
		static const int DEBUG = 1;
		static const int INFO = 2;
		static const int WARN = 3;
		static const int ERROR = 4;

		static void setup(bool isDebug);
		static void setup(bool isDebug, int minLevel);

		static void print(String out);
		static void print(String out, int level);
		static void println(String out);
		static void println(String out, int level);

		static void print(int out);
		static void print(int out, int level);
		static void println(int out);
		static void println(int out, int level);

		static void print(uint32_t out);
		static void print(uint32_t out, int level);
		static void println(uint32_t out);
		static void println(uint32_t out, int level);

		static void print(char out);
		static void print(char out, int level);
		static void println(char out);
		static void println(char out, int level);

		static bool IS_DEBUG;
		static int MIN_LEVEL;
};

#endif
