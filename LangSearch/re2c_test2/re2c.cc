/* Generated by re2c 0.13.5 on Fri Sep  9 16:08:55 2016 */
#line 1 "re2c_02.re"
#include <stdio.h>
#include <string.h>

#define YYMAXFILL 1

struct input_t
{
	size_t len;
	char  *str;

	input_t(const char *s)
		: len(strlen(s))
		, str(new char[len + YYMAXFILL])
	{
		memcpy(str, s, len);
		memset(str+len, 'a', YYMAXFILL);
	}

	~input_t()
	{
		delete []str;
	}
};


static bool lex(const input_t &input)
{
	const char *YYCURSOR = input.str;
	const char *const YYLIMIT = input.str + input.len + YYMAXFILL;
	//const char *const YYMARKER = 0;
	
#line 35 "re2c.cc"
{
	char yych;

	if (YYLIMIT <= YYCURSOR) return false;
	yych = *YYCURSOR;
	switch (yych) {
	case '"':	goto yy7;
	case '\'':	goto yy5;
	case '*':	goto yy3;
	default:	goto yy2;
	}
yy2:
	YYCURSOR = YYMARKER;
	goto yy10;
yy3:
	++YYCURSOR;
#line 39 "re2c_02.re"
	{ return false; }
#line 54 "re2c.cc"
yy5:
	++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) return false;
	yych = *YYCURSOR;
	switch (yych) {
	case '"':	goto yy5;
	case '\'':	goto yy11;
	default:	goto yy2;
	}
yy7:
	++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) return false;
	yych = *YYCURSOR;
	switch (yych) {
	case '"':	goto yy9;
	default:	goto yy7;
	}
yy9:
	++YYCURSOR;
yy10:
#line 40 "re2c_02.re"
	{ return YYLIMIT-YYCURSOR == (size_t)YYLIMIT; }
#line 77 "re2c.cc"
yy11:
	YYMARKER = ++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) return false;
	yych = *YYCURSOR;
	switch (yych) {
	case '"':	goto yy5;
	case '\'':	goto yy11;
	default:	goto yy10;
	}
}
#line 41 "re2c_02.re"

}

int main(int argc, char **argv)
{
	for(int i=1; i<argc; ++i){
		input_t arg(argv[i]);
		printf("%s:%s\n", lex(arg) ? "str" : "err", argv[i]);
	}
	return 0;
}