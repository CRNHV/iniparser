# Iniparser

Credits to: [nowl/iniparser](https://github.com/nowl/iniparser)

This seemed like a good ini parser to me but it had one or two things I needed to adjust for my own use
* It leaked memory in the `destroy_ini` because it didn't properly free some pointers.
* Making it so that the parser accepts ini string, now you have more ways of using this tool

Example usage:

```
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
```




# Original readme:

I always seem to need a good ini parser for various projects and
usually hack one together each time. To remedy this I built this
simple one that will process a standard INI file of the following
form:

----------------------- BEGIN SNIP -----------------------------------

[section1]

key1 = hello
key2= 2.56
key3:12

;; this is a comment
test1 : somethine else here

; this is also a comment
[section 2]

key1 = something in section 2
test1: true

----------------------- END SNIP -------------------------------------

The reader is very simple to use, see main.c for how.
