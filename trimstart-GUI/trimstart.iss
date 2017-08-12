; 脚本用 Inno Setup 脚本向导 生成。
; 查阅文档获取创建 INNO SETUP 脚本文件的详细资料！

#define MyAppName "TrimStart"
#define MyAppVersion "1.0"
#define MyAppPublisher "anpho"
#define MyAppURL "http://anpho.github.io"
#define MyAppExeName "ffmpeg-frontend-gui.exe"

[Setup]
; 注意: AppId 的值是唯一识别这个程序的标志。
; 不要在其他程序中使用相同的 AppId 值。
; (在编译器中点击菜单“工具 -> 产生 GUID”可以产生一个新的 GUID)
AppId={{E50286C3-7030-4969-8DB0-535A306F2826}
AppName={#MyAppName}
AppVersion={#MyAppVersion}
;AppVerName={#MyAppName} {#MyAppVersion}
AppPublisher={#MyAppPublisher}
AppPublisherURL={#MyAppURL}
AppSupportURL={#MyAppURL}
AppUpdatesURL={#MyAppURL}
DefaultDirName={localappdata}\{#MyAppName}
DefaultGroupName={#MyAppName}
AllowNoIcons=yes
OutputDir=C:\Users\anpho\Desktop\build
OutputBaseFilename=setup
SetupIconFile=C:\Users\anpho\Desktop\icon.ico
Compression=lzma
SolidCompression=yes
PrivilegesRequired=none

[Languages]
Name: "chinesesimp"; MessagesFile: "compiler:Languages\ChineseSimp.isl"
Name: "english"; MessagesFile: "compiler:Languages\English.isl"

[Tasks]
Name: "desktopicon"; Description: "{cm:CreateDesktopIcon}"; GroupDescription: "{cm:AdditionalIcons}"; Flags: unchecked

[Files]
Source: "D:\app\ffmpeg-ext\ffmpeg-frontend-gui.exe"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\app\ffmpeg-ext\iconengines\*"; DestDir: "{app}\iconengines\"; Flags: ignoreversion recursesubdirs createallsubdirs
Source: "D:\app\ffmpeg-ext\imageformats\*"; DestDir: "{app}\imageformats\"; Flags: ignoreversion recursesubdirs createallsubdirs
Source: "D:\app\ffmpeg-ext\platforms\*"; DestDir: "{app}\platforms\"; Flags: ignoreversion recursesubdirs createallsubdirs
Source: "D:\app\ffmpeg-ext\translations\*"; DestDir: "{app}\translations\"; Flags: ignoreversion recursesubdirs createallsubdirs
Source: "D:\app\ffmpeg-ext\libgcc_s_dw2-1.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\app\ffmpeg-ext\libstdc++-6.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\app\ffmpeg-ext\libwinpthread-1.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\app\ffmpeg-ext\Qt5Core.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\app\ffmpeg-ext\Qt5Gui.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\app\ffmpeg-ext\Qt5Svg.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\app\ffmpeg-ext\Qt5Widgets.dll"; DestDir: "{app}"; Flags: ignoreversion
; 注意: 不要在任何共享的系统文件使用 "Flags: ignoreversion"

[Icons]
Name: "{group}\{#MyAppName}"; Filename: "{app}\{#MyAppExeName}"
Name: "{group}\{cm:UninstallProgram,{#MyAppName}}"; Filename: "{uninstallexe}"
Name: "{commondesktop}\{#MyAppName}"; Filename: "{app}\{#MyAppExeName}"; Tasks: desktopicon
Name: "{sendto}\TrimStart"; Filename: "{app}\{#MyAppExeName}"

[Run]
Filename: "{app}\{#MyAppExeName}"; Description: "{cm:LaunchProgram,{#StringChange(MyAppName, '&', '&&')}}"; Flags: nowait postinstall skipifsilent

