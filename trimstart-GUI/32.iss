; 脚本由 Inno Setup 脚本向导 生成！
; 有关创建 Inno Setup 脚本文件的详细资料请查阅帮助文档！

#define MyAppName "TrimStart"
#define MyAppVersion "1.0.1"
#define MyAppPublisher "anpho"
#define MyAppURL "http://anpho.github.io"
#define MyAppExeName "trimstart.exe"

[Setup]
; 注: AppId的值为单独标识该应用程序。
; 不要为其他安装程序使用相同的AppId值。
; (生成新的GUID，点击 工具|在IDE中生成GUID。)
AppId={{377FBA9E-1DE0-426D-B7F5-6A209B276981}
AppName={#MyAppName}
AppVersion={#MyAppVersion}
;AppVerName={#MyAppName} {#MyAppVersion}
AppPublisher={#MyAppPublisher}
AppPublisherURL={#MyAppURL}
AppSupportURL={#MyAppURL}
AppUpdatesURL={#MyAppURL}
DefaultDirName={userpf}\{#MyAppName}
DisableProgramGroupPage=yes
OutputDir=C:\Users\Merrick\Desktop\trimstart
OutputBaseFilename=setup32
Compression=lzma
SolidCompression=yes
PrivilegesRequired=lowest 

[Languages]
Name: "chinesesimp"; MessagesFile: "compiler:Default.isl"

[Tasks]
Name: "desktopicon"; Description: "{cm:CreateDesktopIcon}"; GroupDescription: "{cm:AdditionalIcons}"; Flags: unchecked; OnlyBelowVersion: 0,6.1

[Files]
Source: "C:\Users\Merrick\Desktop\trimstart\32\trimstart.exe"; DestDir: "{app}"; Flags: ignoreversion
Source: "C:\Users\Merrick\Desktop\trimstart\32\D3Dcompiler_47.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "C:\Users\Merrick\Desktop\trimstart\32\libEGL.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "C:\Users\Merrick\Desktop\trimstart\32\libgcc_s_dw2-1.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "C:\Users\Merrick\Desktop\trimstart\32\libGLESV2.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "C:\Users\Merrick\Desktop\trimstart\32\libstdc++-6.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "C:\Users\Merrick\Desktop\trimstart\32\libwinpthread-1.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "C:\Users\Merrick\Desktop\trimstart\32\opengl32sw.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "C:\Users\Merrick\Desktop\trimstart\32\Qt5Core.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "C:\Users\Merrick\Desktop\trimstart\32\Qt5Gui.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "C:\Users\Merrick\Desktop\trimstart\32\Qt5Svg.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "C:\Users\Merrick\Desktop\trimstart\32\Qt5Widgets.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "C:\Users\Merrick\Desktop\trimstart\32\iconengines\*"; DestDir: "{app}\iconengines"; Flags: ignoreversion recursesubdirs createallsubdirs
Source: "C:\Users\Merrick\Desktop\trimstart\32\imageformats\*"; DestDir: "{app}\imageformats"; Flags: ignoreversion recursesubdirs createallsubdirs
Source: "C:\Users\Merrick\Desktop\trimstart\32\platforms\*"; DestDir: "{app}\platforms"; Flags: ignoreversion recursesubdirs createallsubdirs
Source: "C:\Users\Merrick\Desktop\trimstart\32\translations\*"; DestDir: "{app}\translations"; Flags: ignoreversion recursesubdirs createallsubdirs
; 注意: 不要在任何共享系统文件上使用“Flags: ignoreversion”

[Icons]
Name: "{commonprograms}\{#MyAppName}"; Filename: "{app}\{#MyAppExeName}"
Name: "{commondesktop}\{#MyAppName}"; Filename: "{app}\{#MyAppExeName}"; Tasks: desktopicon
Name: "{sendto}\TrimStart";Filename: "{app}\{#MyAppExeName}"; WorkingDir: "{app}"

[Run]
Filename: "{app}\{#MyAppExeName}"; Description: "{cm:LaunchProgram,{#StringChange(MyAppName, '&', '&&')}}"; Flags: nowait postinstall skipifsilent

