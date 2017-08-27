; �ű��� Inno Setup �ű��� ���ɣ�
; �йش��� Inno Setup �ű��ļ�����ϸ��������İ����ĵ���

#define MyAppName "TrimStart"
#define MyAppVersion "1.0.1"
#define MyAppPublisher "anpho"
#define MyAppURL "http://anpho.github.io"
#define MyAppExeName "trimstart.exe"

[Setup]
; ע: AppId��ֵΪ������ʶ��Ӧ�ó���
; ��ҪΪ������װ����ʹ����ͬ��AppIdֵ��
; (�����µ�GUID����� ����|��IDE������GUID��)
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
; ע��: ��Ҫ���κι���ϵͳ�ļ���ʹ�á�Flags: ignoreversion��

[Icons]
Name: "{commonprograms}\{#MyAppName}"; Filename: "{app}\{#MyAppExeName}"
Name: "{commondesktop}\{#MyAppName}"; Filename: "{app}\{#MyAppExeName}"; Tasks: desktopicon
Name: "{sendto}\TrimStart";Filename: "{app}\{#MyAppExeName}"; WorkingDir: "{app}"

[Run]
Filename: "{app}\{#MyAppExeName}"; Description: "{cm:LaunchProgram,{#StringChange(MyAppName, '&', '&&')}}"; Flags: nowait postinstall skipifsilent

