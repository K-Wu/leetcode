#include<vector>
#include<string>
using namespace std;

string simplifyPath(string path) {
	int length = path.length();
	vector<int> slashPosition;
	vector<string> directory;
	for (int i = 0; i < length; i++) {
		if (i == length - 1 &&path.at(i)!='/')
			slashPosition.push_back(i+1);
		else if( path.at(i) == '/')
			slashPosition.push_back(i);
			
	}
	int slashNumber = slashPosition.size();
	for (int i = 1; i < slashNumber; i++) {
		string curr_dir = path.substr(slashPosition.at(i - 1) + 1, slashPosition.at(i)- slashPosition.at(i - 1)-1);
		if (curr_dir == "."||curr_dir=="")//±ß½ç²âÀý"/home//foo/"
			continue;
		if (curr_dir == "..")
		{
			if (directory.size() != 0)
				directory.pop_back();
		}

		else
			directory.push_back(curr_dir);
	}
	string result = "";
	for (int i = 0; i < directory.size(); i++) {
		result += "/";
		result+=directory.at(i);
		
	}
	if (result == "")
		result = "/";//²âÀýÊ§°Ü£º"/"
	return result;
}
int main() {

// 	vector<string> vect;
// 	string abccc = "abcde";
// 	bool test = abccc == "abcde";
// 	vect.emplace_back("abc");
// 	vect.pop_back();
// 	vect.pop_back();

	string result1=simplifyPath("/home/");
	string result2 = simplifyPath("/a/./b/../../c/");
	string result3 = simplifyPath("/home//foo/");
	string result4 = simplifyPath("///");
	return 0;
}