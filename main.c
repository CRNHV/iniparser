#include "iniparser.h"

int main(int argc, char* argv[])
{	
	for (size_t i = 0; i < 50000; i++)
	{
		const char* iniStr =
			"[section1]\r\n\r\n"
			"key1 = hello\r\n"
			"key2= 2.56\r\n"
			"key3:12\r\n\r\n"
			";; this is a comment\r\n"
			"test1 : somethine else here\r\n\r\n"
			"[section2]\r\n\r\n"
			"key4 = hello\r\n"
			"key5= 2.56\r\n"
			"key6:12\r\n\r\n";
		size_t iniStrLen = 156;

		struct read_ini* ini_r = NULL;
		char* value;
		/* "test.ini" will be parsed into "ini" */
		struct ini* ini = read_ini(&ini_r, iniStr, iniStrLen);

		/* free memory */
		destroy_ini(ini);
		cleanup_readini(ini_r);
	}

	return 0;
}
