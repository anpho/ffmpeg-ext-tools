#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;
static int PARAM_NOT_SPECIFIED = 1;
static int INVALID_INPUT = 2;

/*
 * This program is used to generate the command line for ffmpeg tool suite,
 * In order to remove the begining AD from the mp4 file I downloaded.
 * Merrick Zhang (anphorea@gmail.com)
 */
int main(int argc, char *argv[])
{
	//set system variables;
	string pathv = getenv("PATH");
	cout<<"PATH:"<<pathv<<endl;
	// not done.

    if (argc ==1){
        cout<<"Usage:"<<endl;
        cout<<"    ffmpeg-ext.exe [media-file-path]"<<endl;
        cout<<"    [media-file-path] must be specified."<<endl;
		cout<<"Return Code:"<<endl;
		cout<<"\t1\tParam_Not_Specified"<<endl;
		cout<<"\t2\tInvalid_Input"<<endl;
        return PARAM_NOT_SPECIFIED;
    }

    string filepath = argv[1];
    cout<<"Param[media-file-path] is : "<<filepath<<endl;

    string start_seconds;
    cout<< "Trim start (seconds):";
    cin>> start_seconds;

    string new_file_name;
    int pos=filepath.find_last_of('.');
    filepath.insert(pos,"-trim");
    new_file_name = filepath;
    cout<<"Use filename: "<<filepath<<endl;

    string cmd="ffmpeg -ss ";
    cmd.append(start_seconds);
    cmd.append(" -i ");
    cmd.append(argv[1]);
    cmd.append(" -codec copy ");
    cmd.append(new_file_name);

    cout<<"Final cmd line: "<<cmd<<endl;

    system(cmd.c_str());
	
    return 0;
}
