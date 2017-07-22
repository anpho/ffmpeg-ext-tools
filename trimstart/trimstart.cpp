#include <iostream>
#include <string>
#include <stdlib.h>
#include <vector>

using namespace std;
static int PARAM_NOT_SPECIFIED = 1;
static int INVALID_INPUT = 2;
static int UNKNOWN_ERROR = 9;

string _current_dir="", _exe_name="";

int install() {
	cout << "Install to System Context Menu. Please specify the .reg file." << endl;
	return 0;
}

int uninstall() {
	return 0;
}
void show_readme() {
	cout << "Trimstart Tool for ffmpeg." << endl;
	cout << "Merrick Zhang ( anphorea@gmail.com )" << endl;
	cout << "====================================" << endl;
	cout << "Usage:" << endl;
	cout << "Create a shortcut in your shell:sendto folder, select file(s) to trim, use SendTo to invoke this tool." << endl;
	cout << "OR" << endl;
	cout << _exe_name<<" [media-file]\tTrim the specified media file." << endl;
	//cout << _exe_name<<" /i \t \tInstall to system context menu." << endl;
	//cout << _exe_name<<" /u \t \tUninstall." << endl;
}

bool setup_path_var(const string& argv1) {
	if ( argv1.empty()) return false;

	int slash_pos = argv1.find_last_of("\\");
	if (slash_pos >> 0) {
		_current_dir = argv1.substr(0, slash_pos + 1);
		_exe_name = argv1.substr(slash_pos + 1);
	}
	else {
		cerr << "Strange Parameter: " + argv1 << endl;
		return false;
	}
	return true;
}
char full[_MAX_PATH];
/*
 * Get the full path of this program.
 */
char* getFullPath(char * partialPath)
{
	if (_fullpath(full, partialPath, _MAX_PATH) != NULL){
		return full;
	}
	else
		return "";
}


void trim_file(const string& mediafile, const string trim_start_seconds) {
	cout << "Processing:\t" << mediafile << endl;
	string new_file_name(mediafile);
	int pos = new_file_name.find_last_of('.');
	new_file_name.insert(pos, "-trim");
	cout << "New Filename: " << new_file_name << endl;

	string cmd = "ffmpeg -ss ";
	cmd.append(trim_start_seconds);
	cmd.append(" -i ");
	cmd.append(mediafile);
	cmd.append(" -codec copy ");
	cmd.append(new_file_name);

	cout << "Final cmd line: " << cmd << endl;

	system(cmd.c_str());
}

/*
 * This program is used to generate the command line for ffmpeg tool suite,
 * In order to remove the begining AD from the mp4 file I downloaded.
 * Merrick Zhang (anphorea@gmail.com)
 */
int main(int argc, char *argv[])
{
	// setup path variables
	string app_path(getFullPath(argv[0]));
	if (!setup_path_var(app_path)) {
		return UNKNOWN_ERROR;
	}

	vector<string> mediafiles;

	if (argc > 1) {
		if (strcmp(argv[1], "/i") == 0) {
			return install();
		}
		else if (strcmp(argv[1], "/u") == 0) {
			return uninstall();
		}
		else {
			// To trim
			mediafiles.clear();
			for (int i = 1; i < argc; i++) {
				mediafiles.push_back(argv[i]);
			}
		}
	}
	else {
		return PARAM_NOT_SPECIFIED;
	}

	cout << "Trimstart tool for ffmpeg" << endl << endl;

    string start_seconds;
    cout<< "Trim (seconds) from the beginning (Enter decimal number or hh:mm:ss): ";
    cin>> start_seconds;

	vector<string>::iterator it;
	for (it = mediafiles.begin(); it != mediafiles.end(); it++) {
		trim_file(*it, start_seconds);
	}

	
    return 0;
}

