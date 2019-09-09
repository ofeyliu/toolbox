
/*
useful snippet of c++

author : liuweiwei
date   : 2018-11-03

*/


///////////////////////////////////// folder operation //////////////////////////////////////
#include <direct.h>
//  Return the image filenames inside the image folder
vector<String> filenames;
String folder(image_folder);
glob(folder, filenames);
// create folder
_mkdir(foldername)

/*
* FUNCTION : judge if the file exist
*/
#include <io.h>
bool dirExists(const std::string& dirName_in)
{
	int ftyp = _access(dirName_in.c_str(), 0);

	if (0 == ftyp)
		return true;   // this is a directory!
	else
		return false;    // this is not a directory!
}



/////////////////////////////////////// format string output ////////////////////////////////////

/*
* FUNCTION : snippet to convert an integer value to a string using a clean function
instead of creating a stringstream each time inside the main code
*/ 

// %01
string int2string(int num)
{
	stringstream temp_stream;
	temp_stream << num;
	return temp_stream.str();
}
// %02
sprintf(imageName, "%04d.png", frameNum);

// %03
#include<sstream>
std::ostringstream buffer;
buffer << savename << "\\" << std::setfill('0') << setw(6) << frameNum << ".jpg";
string save_image_name = buffer.str();
buffer.str("");



//////////////////////////////////////////// 计时 (ms) ///////////////////////////////////////
#include <ctime>
using namespace std;

clock_t start = clock();
// do something...
clock_t end   = clock();
cout << "花费了" << (double)(end - start) / CLOCKS_PER_SEC << "秒" << endl;

//////////////////////////////////////////// 计时 (us) ////////////////////////////////////////
#include <chrono>   
#include <ratio>
#include <thread>

using namespace std;
using namespace chrono;

void f()
{
	std::this_thread::sleep_for(std::chrono::seconds(1));
}


int main()
{
	clock_t start = clock();
	auto start2 = std::chrono::high_resolution_clock::now();

	for (int i = 0; i < 30; i++)
	{
		f();
	}
	clock_t end = clock();
	cout << "花费了" << (double)(end - start) / CLOCKS_PER_SEC << "秒" << endl;

	auto end2 = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<microseconds>(end2 - start2);
	cout << "花费了"
		<< double(duration.count()) * microseconds::period::num / microseconds::period::den
		<< "秒" << endl;
}
