#TrimStart
==========

#Requirement

1. ffmpeg.exe in PATH
2. some regedit experience

#How to setup

1. Save trimstart.exe to somewhere you like, e.g. `d:\apps\ffmpeg\bin
2. Now you have the absolute path to this tool : `d:\apps\ffmpeg\bin\trimstart.exe`
3. Open `regedit`
4. Expand `HKEY_CLASSES_ROOT` and find the ext item, e.g. `.mp4`
5. if the default value in `.mp4` is not empty, e.g. `mpc-be64.mp4`, then navigate to `mpc-be64.mp4` item accordingly.
6. Expand / Create an Item named `Shell`
7. Create an Item named `trimstart` in `Shell`
8. Create an Item named `command` in `trimstart`
9. Edit the default value of `trimstart`, in this example, make it look like this : `d:\apps\ffmpeg\bin\trimstart.exe "%1"`
10. Make sure ffmpeg.exe is in your PATH.

#How to use

1. Right click the mp4 file, choose TrimStart
2. Give it some value about how long to trim from the start in seconds
3. wait for it to invoke ffmpeg and complete the rest progress.
4. remove your original mp4 file if the new one is OK.

#Disclaim

This is just a tool for myself to remove the AD in the beginning of every mp4 file I downloaded, be careful when you decide to use it. read my code first.

#Author

Merrick Zhang ( anphorea@gmail.com )
