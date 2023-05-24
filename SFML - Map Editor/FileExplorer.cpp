#include "FileExplorer.h"
#include <Windows.h>
#include <Commdlg.h>
#include <iostream>


string FileExplorer::GetPath()
{
	OPENFILENAME ofn; 
	char szFileName[MAX_PATH] = ""; 

	ZeroMemory(&ofn, sizeof(ofn));
	ofn.lStructSize = sizeof(ofn);
	ofn.hwndOwner = NULL;
	ofn.lpstrFilter = "Images (*.png)\0*.png\0Fichier Textes (*.txt)\0*.txt\0Tous les fichiers (*.*)\0*.*\0";
	ofn.lpstrFile = szFileName;
	ofn.nMaxFile = MAX_PATH;
	ofn.Flags = OFN_EXPLORER | OFN_FILEMUSTEXIST | OFN_HIDEREADONLY;
	ofn.lpstrDefExt = "png";

	if (GetOpenFileName(&ofn))
	{
		return ofn.lpstrFile;
	}
	else
	{
		MessageBox(NULL, "No file found.", "Erreur",
			MB_OK | MB_ICONERROR);

		return "";
	}
}

FileExplorer::FileExplorer()
{

}