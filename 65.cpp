//valid number
/*
"0" => true
" 0.1 " = > true
"abc" = > false
"1 a" = > false
"2e10" = > true
"33e2" = > true
"3 . 3" = > false
"3." = > true
".4" = > true
*/
#include<string>

using namespace std;
bool isNumber(string s) {
	int len = s.length();
	int dot = 0;
	bool started_flag = false;
	bool ended_flag = false;
	bool exp_flag = false;
	bool exp_started_flag = true;
	bool neg_flag = false;
	bool pos_flag = false;
	for (int i = 0; i < len; i++) {
		char curr_char = s.at(i);
		if (curr_char == ' ') {
			if ((pos_flag||neg_flag)&&(!started_flag||!exp_started_flag))
				return false;
			if (!started_flag)
			{
				if (dot > 0) // ²âÀýÊ§°Ü£º". 1"
					return false;
				continue;
			}
			else
				ended_flag = true;
		}
		else if (curr_char == '-') {
			if ((dot>0&&!started_flag)||pos_flag||neg_flag||(started_flag&&exp_started_flag)) {//±ß½Ç²âÀýÊ§°Ü:"3-2" //".-4"
				return false;
			}
			else
				neg_flag = true;
		}
		else if (curr_char == '+') {//"¿½±´³É-²âÊÔÀý×Ó+.8"
			if ((dot > 0 && !started_flag)||pos_flag || neg_flag || (started_flag&&exp_started_flag)) {//±ß½Ç²âÀýÊ§°Ü:"3-2"
				return false;
			}
			else
				pos_flag = true;
		}
		else if (curr_char >= 48 && curr_char <= 57)   //digit
		{
			if (~exp_started_flag)
				exp_started_flag = true;
			if (!ended_flag)
			{
				started_flag = true;
				continue;
			}
			else {
				return false;
			}
		}
		else if (curr_char == 'e')//±ß½Ç²âÀýÊ§°Ü"0e"
		{
			if (ended_flag)
				return false;//±ß½Ç²âÀýÊ§°Ü"1 ."
			if (exp_flag||!started_flag)//±ß½Ç²âÀýÊ§°Ü:"e"
				return false;
			else
			{
				neg_flag = false;
				pos_flag = false;
				exp_flag = true;
				exp_started_flag = false;
			}
		}

		else if (curr_char == '.')
		{
			if (ended_flag)
				return false;//±ß½Ç²âÀýÊ§°Ü"1 ."
			if (exp_flag || dot)
				return false;
			dot += 1;
			if (dot >= 2)
				return false;
		}
		else
			return false;
		
	}
	if (!started_flag || !exp_started_flag)
		return false;
	else
		return true;
}
int main() {
	bool p_d = isNumber("+.8");
	bool kkk = isNumber("-+K");
	bool ddd = isNumber("1  .");
	bool eee = isNumber("0e");
	bool a = isNumber("0"); //= > true
	bool b = isNumber(" 0.1 ");// = > true
	bool c = isNumber("abc");// = > false
	bool d = isNumber("1 a");// = > false
	bool e = isNumber("2e10");// = > true
	bool f = isNumber("33e2");// = > true
	bool g = isNumber("3 . 3");// = > false

	return 0;
}