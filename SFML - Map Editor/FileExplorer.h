#ifndef FILEEXPLORER
#define FILEEXPLORER

#include <string>

using namespace std;

#endif // !FILEEXPLORER

class FileExplorer
{
public:
	static FileExplorer& GetInstance()
	{
		static FileExplorer instance;
		return instance;
	}
	
	string GetPath();

private:

	FileExplorer(); 

	FileExplorer(FileExplorer& const) = delete;
	void operator=(FileExplorer& const) = delete;
};

